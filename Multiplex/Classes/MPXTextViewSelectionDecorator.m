//
//  MPXTextViewSelectionDecorator.m
//  Multiplex
//
//  Created by Kolin Krewinkel on 8/23/15.
//  Copyright © 2015 Kolin Krewinkel. All rights reserved.
//

#import <DVTKit/DVTLayoutManager.h>
#import <DVTKit/DVTSourceTextView.h>
#import <DVTKit/DVTTextStorage.h>
#import <DVTKit/DVTFontAndColorTheme.h>

@import ReactiveCocoa;

#import "MPXSelection.h"
#import "MPXSelectionManager.h"
#import "MPXSelectionMutation.h"
#import "MPXGeometry.h"

#import "MPXTextViewSelectionDecorator.h"

@interface MPXTextViewSelectionDecorator ()

@property (nonatomic) DVTSourceTextView *textView;

@property (nonatomic) NSTimer *blinkTimer;
@property (nonatomic) BOOL blinkState;

@property (nonatomic) NSArray *caretViews;

@end

@implementation MPXTextViewSelectionDecorator

#pragma mark - Initialization

- (instancetype)initWithTextView:(DVTSourceTextView *)textView
{
    if (self = [super init]) {
        self.textView = textView;

        NSScrollView *scrollView = (NSScrollView *)self.textView.superview;
        [scrollView.contentView setPostsBoundsChangedNotifications:YES];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(scrollViewDidScroll:)
                                                     name:NSViewBoundsDidChangeNotification
                                                   object:scrollView.contentView];
    }

    return self;
}

#pragma mark - MPXSelectionManagerVisualizationDelegate

- (void)selectionManager:(MPXSelectionManager *)selectionManager didChangeVisualSelections:(NSArray *)visualSelections
{
    [self stopBlinking];

    DVTTextStorage *textStorage = self.textView.textStorage;

    // Reset the background color of all the source text.
    [self.textView.layoutManager setTemporaryAttributes:@{} forCharacterRange:NSMakeRange(0, textStorage.length)];

    // Remove any onscreen cursors
    for (RACTuple *tuple in self.caretViews) {
        NSView *caretView = tuple[1];
        [caretView removeFromSuperview];
    }

    RACSequence *selectionSequence = [visualSelections rac_sequence];

    self.caretViews = [[selectionSequence map:^RACTuple *(MPXSelection *selection) {
        NSUInteger caretIndex = selection.insertionIndex;

        NSUInteger glyphIndex = [self.textView.layoutManager glyphIndexForCharacterAtIndex:caretIndex];
        NSRect glyphRect = [self.textView.layoutManager boundingRectForGlyphRange:NSMakeRange(glyphIndex, 0)
                                                                  inTextContainer:self.textView.textContainer];

        CGRect unroundedCaretRect = CGRectOffset(CGRectMake(glyphRect.origin.x, glyphRect.origin.y, 1.f/self.textView.window.screen.backingScaleFactor, CGRectGetHeight(glyphRect)),
                                                 self.textView.textContainerOrigin.x,
                                                 self.textView.textContainerOrigin.y);

        CGRect caretRect = MPXRoundedValueRectForView(unroundedCaretRect, self.textView);

        NSView *caretView = [[NSView alloc] initWithFrame:caretRect];
        caretView.wantsLayer = YES;
        caretView.layer.backgroundColor = [textStorage.fontAndColorTheme.sourceTextInsertionPointColor CGColor];

        [self.textView addSubview:caretView];

        return RACTuplePack(selection, caretView);
    }] array];

    // Paint the background of the selection range for selections taht are not just insertion points.
    NSArray *rangedSelections = [[selectionSequence filter:^BOOL(MPXSelection *selection) {
        return selection.range.length > 0;
    }] array];

    NSColor *selectedBackgroundColor = textStorage.fontAndColorTheme.sourceTextSelectionColor;
    for (MPXSelection *selection in rangedSelections) {
        [self.textView.layoutManager setTemporaryAttributes:@{NSBackgroundColorAttributeName: selectedBackgroundColor}
                                          forCharacterRange:selection.range];
    }

    [self updateTextViewSelectedRange];
    
    [self startBlinking];   
}

- (void)setCursorsVisible:(BOOL)visible
{
    for (RACTuple *tuple in self.caretViews) {
        NSView *caretView = tuple[1];
        caretView.alphaValue = !visible;
    }

    self.blinkState = visible;
}

- (void)blinkCursors:(NSTimer *)sender
{
    if ([self.caretViews count] == 0) {
        return;
    }

    [self setCursorsVisible:!self.blinkState];
}

- (void)startBlinking
{
    [self.blinkTimer invalidate];
    self.blinkTimer = nil;

    // This used to check if the blink timer was already there, however:
    // we should restart it because the old one will mess up a new cursor's showing
    // for too short a time if the timer was already in motion.
    self.blinkTimer = [NSTimer timerWithTimeInterval:0.5
                                              target:self
                                            selector:@selector(blinkCursors:)
                                            userInfo:nil
                                             repeats:YES];
    self.blinkTimer.tolerance = self.blinkTimer.timeInterval * 0.05;

    [[NSRunLoop mainRunLoop] addTimer:self.blinkTimer forMode:NSRunLoopCommonModes];
}

- (void)stopBlinking
{
    [self.blinkTimer invalidate];
    self.blinkTimer = nil;

    [self setCursorsVisible:NO];
}

- (void)scrollViewDidScroll:(NSNotification *)notification
{
    [self updateTextViewSelectedRange];
}

- (void)updateTextViewSelectedRange
{
    // Don't modify the selected range if the text view string was reset to nil.
    if ([self.textView.string length] == 0) {
        return;
    }

    // If there's only one selection, always show it in the breadcrumb bar and have it be the basis for autocompletion.
    if ([self.caretViews count] == 1) {
        MPXSelection *selection = [self.caretViews firstObject][0];
        [self setTextViewSelectedRangeSafely:selection.range];
        return;
    }
    
    MPXSelection *visibleSelection = [self firstVisibleSelectionInTextView];
    if (visibleSelection && [self.textView.string length] > 0) {
        if (!NSEqualRanges(self.textView.selectedRange, visibleSelection.range)) {
            [self setTextViewSelectedRangeSafely:visibleSelection.range];
        }
    } else {
        [self setTextViewSelectedRangeSafely:NSMakeRange(0, 0)];
    }
}

- (void)setTextViewSelectedRangeSafely:(NSRange)range
{
    // When the textStorage is modified, sometimes a scroll can be triggered. Because this modification occurs just
    // before the selections are updated, we check that the ranges aren't out of bounds (because the selections we're
    // referencing are now incongruent with the text).
    if ([self.textView.textStorage.string length] > NSMaxRange(range)) {
        self.textView.selectedRange = range;
    }
}

- (MPXSelection *)firstVisibleSelectionInTextView
{
    NSClipView *clipView = (NSClipView *)self.textView.superview;

    __block MPXSelection *visibleSelection = nil;
    for (RACTuple *tuple in self.caretViews) {
        RACTupleUnpack(MPXSelection *selection, NSView *caretView) = tuple;

        if (CGRectIntersectsRect(caretView.frame, clipView.documentVisibleRect)) {
            visibleSelection = selection;
            break;
        }
    }
    
    if (visibleSelection) {
        return visibleSelection;
    }

    return nil;
}

@end
