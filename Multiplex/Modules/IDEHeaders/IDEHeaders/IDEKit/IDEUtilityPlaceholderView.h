//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import "DVTLayoutView_ML-Protocol.h"

@class NSColor, NSString, NSTextField;

@interface IDEUtilityPlaceholderView : DVTLayoutView_ML
{
    NSTextField *_placeholderTextField;
    NSColor *_backgroundColor;
}

@property(copy, nonatomic) NSColor *backgroundColor; // @synthesize backgroundColor=_backgroundColor;
@property(retain, nonatomic) NSTextField *placeholderTextField; // @synthesize placeholderTextField=_placeholderTextField;
- (void)drawRect:(struct CGRect)arg1;
- (void)layoutBottomUp;
@property(copy, nonatomic) NSString *placeholderString;
- (id)initWithFrame:(struct CGRect)arg1;

@end
