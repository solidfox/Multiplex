//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSTableColumn;

@interface DVTTextCompletionWindowResizeAnimation : NSViewAnimation
{
    double _typeColStartWidth;
    double _typeColEndWidth;
    NSTableColumn *_typeColumn;
}

@property(retain) NSTableColumn *typeColumn; // @synthesize typeColumn=_typeColumn;
@property double typeColEndWidth; // @synthesize typeColEndWidth=_typeColEndWidth;
@property double typeColStartWidth; // @synthesize typeColStartWidth=_typeColStartWidth;
- (void)setCurrentProgress:(float)arg1;

@end

