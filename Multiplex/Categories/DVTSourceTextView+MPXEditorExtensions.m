//
//  IDESourceCodeEditor+CATViewReplacement.m
//  Multiplex
//
//  Created by Kolin Krewinkel on 9/25/14.
//  Copyright (c) 2014 Kolin Krewinkel. All rights reserved.
//

@import MPXFoundation;
@import MPXSelectionCore;
@import ReactiveCocoa;

#import <DVTFoundation/DVTTextPreferences.h>

#import <DVTKit/DVTLayoutManager.h>
#import <DVTKit/DVTTextCompletionController.h>
#import <DVTKit/DVTTextStorage.h>
#import <DVTKit/DVTTextCompletionSession.h>
#import <DVTKit/DVTTextCompletionInlinePreviewController.h>

#import <libextobjc/EXTSynthesize.h>

#import "DVTSourceTextView+MPXEditorExtensions.h"
#import "DVTSourceTextView+MPXEditorSelectionVisualization.h"

@implementation DVTSourceTextView (MPXEditorExtensions)
@synthesizeAssociation(DVTSourceTextView, mpx_selectionManager);
@synthesizeAssociation(DVTSourceTextView, mpx_inUndoGroup);
@synthesizeAssociation(DVTSourceTextView, mpx_shouldCloseGroupOnNextChange);
@synthesizeAssociation(DVTSourceTextView, mpx_textViewSelectionBridge);
@synthesizeAssociation(DVTSourceTextView, mpx_trimTrailingWhitespace);

#pragma mark - Initializer

- (void)mpx_commonInitDVTSourceTextView
{
    [self mpx_commonInitDVTSourceTextView];

    self.mpx_textViewSelectionDecorator = [[MPXTextViewSelectionDecorator alloc] initWithTextView:self];

    self.mpx_selectionManager = [[MPXSelectionManager alloc] initWithTextView:self];
    self.mpx_selectionManager.visualizationDelegate = self.mpx_textViewSelectionDecorator;

    self.selectedTextAttributes = @{};

    self.mpx_trimTrailingWhitespace = self.shouldTrimTrailingWhitespace;
}

- (void)undo:(id)sender
{
    if (self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = NO;
        [self.undoManager endUndoGrouping];
    }

    [self.undoManager undoNestedGroup];
}

#pragma mark - Keyboard Events

- (void)insertText:(id)insertObject
{
    // Prevents random stuff being thrown in.
    if (![insertObject isKindOfClass:[NSString class]]) {
        return;
    }

    NSString *insertString = (NSString *)insertObject;

    if (self.mpx_shouldCloseGroupOnNextChange && self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = NO;
        [self.undoManager endUndoGrouping];
        self.mpx_shouldCloseGroupOnNextChange = NO;
    }

    if (!self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = YES;
        self.mpx_shouldCloseGroupOnNextChange = NO;

        [self.undoManager beginUndoGrouping];

        NSArray *currState = self.mpx_selectionManager.finalizedSelections;
        [self.undoManager registerUndoWithTarget:self handler:^(id  _Nonnull target) {
            self.mpx_selectionManager.finalizedSelections = currState;
            [self.mpx_textViewSelectionDecorator startBlinking];
        }];
    }

    [self.completionController textViewShouldInsertText:self];

    // Sequential (negative) offset of characters added.
    __block NSInteger totalDelta = 0;
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSRange range = selection.range;
        NSUInteger insertStringLength = [insertString length];

        // Offset by the previous mutations made (+/- doesn't matter, as long as the different maths at each point
        // correspond to the relative offset made by inserting a # of chars.)
        NSRange offsetRange = NSMakeRange(range.location + totalDelta, range.length);

        [self.textStorage replaceCharactersInRange:offsetRange withString:insertString withUndoManager:self.undoManager];

        // Offset the following ones by noting the original length and updating for the replacement's length, moving
        // cursors following forward/backward.
        NSInteger delta = range.length - insertStringLength;
        totalDelta -= delta;

        NSRange lineRange;
        (void)[self.layoutManager lineFragmentRectForGlyphAtIndex:NSMaxRange(offsetRange) effectiveRange:&lineRange];

        NSUInteger relativeLinePosition = selection.indexWantedWithinLine;

        if (relativeLinePosition == NSNotFound) {
            relativeLinePosition = NSMaxRange(offsetRange) - lineRange.location;
        }

        // Move cursor (or range-selection) to the end of what was just added with 0-length.
        NSRange newInsertionPointRange = NSMakeRange(offsetRange.location + insertStringLength, 0);
        return [[MPXSelection alloc] initWithSelectionRange:newInsertionPointRange
                                      indexWantedWithinLine:relativeLinePosition
                                                     origin:newInsertionPointRange.location];
    } sequentialModification:YES];


    [self.mpx_textViewSelectionDecorator startBlinking];

    [self.completionController textViewDidInsertText];
    [self.completionController _textViewTextDidChange:self];
}

- (void)deleteBackward:(id)sender
{
    // Sequential (negative) offset of characters added.
    __block NSUInteger totalDelta = 0;

    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        // Update the base range with the delta'd amount of change from previous mutations.
        NSRange range = [selection range];
        NSRange offsetRange = NSMakeRange(range.location - totalDelta, range.length);

        NSRange deletingRange = NSMakeRange(0, 0);
        if (offsetRange.location > 0 && offsetRange.length == 0) {
            deletingRange = NSMakeRange(offsetRange.location - 1, 1);
        } else {
            deletingRange = NSMakeRange(offsetRange.location, offsetRange.length);
        }

        // Delete the characters
        [self insertText:@"" replacementRange:deletingRange];

        // New range for the beam (to the beginning of the range we replaced)
        NSRange newInsertionPointRange = NSMakeRange(deletingRange.location, 0);
        MPXSelection *newSelection = [MPXSelection selectionWithRange:newInsertionPointRange];

        // Increment/decrement the delta by how much we trimmed.
        totalDelta += deletingRange.length;

        return newSelection;
    }];
}

#pragma mark - Indentations/Other insertions

- (void)insertNewline:(id)sender
{
    BOOL shouldTrimTrailingWhitespace = [self mpx_shouldTrimTrailingWhitespace];

    NSString *newlineString = @"\n";
    [self insertText:newlineString];

    self.mpx_trimTrailingWhitespace = NO;

    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSRange range = selection.range;

        // Don't attempt to indent if at the end of the file.
        if (NSMaxRange(range) == self.textStorage.length) {
            return selection;
        }

        NSRange shiftedRange = NSMakeRange(NSMaxRange(range), [newlineString length]);

        NSRange indentedRange = [self _indentInsertedTextIfNecessaryAtRange:shiftedRange];
        return [MPXSelection selectionWithRange:NSMakeRange(indentedRange.location, 0)];
    } sequentialModification:YES];

    self.mpx_trimTrailingWhitespace = shouldTrimTrailingWhitespace;
}

- (BOOL)handleInsertTab
{
    BOOL shouldTrimTrailingWhitespace = [self mpx_shouldTrimTrailingWhitespace];
    self.mpx_trimTrailingWhitespace = NO;

    NSString *tabString = [self mpx_tabString];
    [self insertText:tabString];

    self.mpx_trimTrailingWhitespace = shouldTrimTrailingWhitespace;

    return YES;
}

- (NSString *)mpx_tabString
{
    DVTTextPreferences *preferences = [DVTTextPreferences preferences];
    if (preferences.useTabsToIndent) {
        return @"\t";
    }

    NSMutableString *spaceTabString = [NSMutableString string];

    NSUInteger spaceCount = preferences.tabWidth;
    for (NSUInteger spacesAdded = 0; spacesAdded < spaceCount; spacesAdded++) {
        [spaceTabString appendString:@" "];
    }

    return spaceTabString;
}

- (BOOL)mpx_shouldTrimTrailingWhitespace
{
    return self.mpx_trimTrailingWhitespace;
}

#pragma mark - Range Manipulation

- (BOOL)mpx_validateMenuItem:(NSMenuItem *)item
{
    SEL theAction = item.action;
    if (theAction == @selector(copy:) || theAction == @selector(cut:)) {
        return [self.mpx_selectionManager.visualSelections count] > 0;
    }

    return [self mpx_validateMenuItem:item];
}

- (void)selectAll:(id)sender
{
    self.mpx_selectionManager.finalizedSelections = @[[MPXSelection selectionWithRange:NSMakeRange(0, [self.textStorage.string length])]];
}

- (void)mpx_mapAndFinalizeSelectedRanges:(MPXSelection * (^)(MPXSelection *selection))mapBlock
{
    [self mpx_mapAndFinalizeSelectedRanges:mapBlock sequentialModification:NO];
}

- (void)mpx_mapAndFinalizeSelectedRanges:(MPXSelection * (^)(MPXSelection *selection))mapBlock
                  sequentialModification:(BOOL)sequentialModification
{
    NSArray *mappedValues = [[[self.mpx_selectionManager.visualSelections rac_sequence] map:mapBlock] array];
    self.mpx_selectionManager.finalizedSelections = mappedValues;

    [self.mpx_textViewSelectionDecorator startBlinking];
}

@end
