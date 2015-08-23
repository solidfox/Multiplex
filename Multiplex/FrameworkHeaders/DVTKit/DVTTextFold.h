//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, NSAttributedString, NSMutableArray, NSString, NSTextAttachmentCell;

@interface DVTTextFold : NSObject <DVTInvalidation>
{
    struct _NSRange _relativeLocation;
    DVTTextFold *_parent;
    NSMutableArray *_children;
    NSString *_label;
    unsigned long long _foldStyle;
    NSTextAttachmentCell *_attachmentCell;
}

+ (id)keyPathsForValuesAffectingReplacementRange;
+ (id)keyPathsForValuesAffectingReplacementString;
+ (id)foldsFromString:(id)arg1;
+ (id)decodeFold:(id)arg1 forParent:(id)arg2;
+ (Class)_webViewAttachmentCellClass;
+ (Class)_inlineTokenAttachmentCellClass;
+ (void)initialize;
@property(readonly) unsigned long long foldStyle; // @synthesize foldStyle=_foldStyle;
- (struct _NSRange)fixedSelectionRangeForRange:(struct _NSRange)arg1 affinity:(unsigned long long)arg2 inTextView:(id)arg3;
- (unsigned long long)foldingTypesetter:(id)arg1 shouldUseControlCharacterAction:(unsigned long long)arg2 remainingNominalParagraphRange:(struct _NSRange *)arg3 andParagraphSeparatorRange:(struct _NSRange *)arg4 charactarIndex:(unsigned long long)arg5 layoutManager:(id)arg6 string:(id)arg7;
- (struct CGRect)foldingTypesetter:(id)arg1 shouldUseBoundingBox:(struct CGRect)arg2 forControlGlyphAtIndex:(unsigned long long)arg3 textContainer:(id)arg4 proposedLineFragment:(struct CGRect)arg5 glyphPosition:(struct CGPoint)arg6 characterIndex:(unsigned long long)arg7;
- (struct CGRect)foldingLayoutManager:(id)arg1 shouldUseBoundingRect:(struct CGRect)arg2 forGlyphRange:(struct _NSRange)arg3 inTextContainer:(id)arg4;
@property(readonly) NSAttributedString *foldedIconString;
@property(readonly) NSTextAttachmentCell *attachmentCell; // @synthesize attachmentCell=_attachmentCell;
@property(readonly) struct _NSRange replacementRange;
@property(readonly) NSString *replacementString;
@property(copy) NSString *label;
@property(readonly) NSMutableArray *children;
@property(readonly) unsigned long long numberOfChildren;
- (id)removeChildren:(id)arg1;
- (void)addChild:(id)arg1;
@property(retain) DVTTextFold *parent;
- (id)findFoldContainingRange:(struct _NSRange)arg1;
- (id)findFoldWithRange:(struct _NSRange)arg1;
- (unsigned long long)subtractOutFolds:(unsigned long long)arg1;
- (unsigned long long)addInFolds:(unsigned long long)arg1;
- (id)adjustFoldsForRange:(struct _NSRange)arg1 changeInLength:(long long)arg2;
- (id)foldsEnclosingRange:(struct _NSRange)arg1;
- (void)_addFoldsEnclosingRange:(struct _NSRange)arg1 toArray:(id)arg2;
- (id)lastFoldTouchingCharacterIndex:(unsigned long long)arg1;
- (id)firstFoldTouchingCharacterIndex:(unsigned long long)arg1;
- (id)allFoldsTouchingRange:(struct _NSRange)arg1;
- (id)inlineFoldsTouchingRange:(struct _NSRange)arg1;
- (id)blockFoldsTouchingRange:(struct _NSRange)arg1;
- (void)enumerateDescendantsWithOptions:(unsigned long long)arg1 usingBlock:(dispatch_block_t)arg2;
- (BOOL)isCharacterFoldedAtIndex:(unsigned long long)arg1;
- (BOOL)rangeIsInsideAFold:(struct _NSRange)arg1;
- (void)offsetBy:(long long)arg1;
@property struct _NSRange range;
- (BOOL)validate;
@property(readonly, copy) NSString *description;
- (id)innerDescription:(id)arg1;
@property(readonly) NSString *stringValue;
- (id)_pList;
- (void)primitiveInvalidate;
- (id)initWithRange:(struct _NSRange)arg1 style:(unsigned long long)arg2;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end
