//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEExplorationContext.h>

@class NSString;

@interface IDEActionExplorationContext : IDEExplorationContext
{
    NSString *_actionIdentifier;
}

@property(readonly) NSString *actionIdentifier; // @synthesize actionIdentifier=_actionIdentifier;
- (int)explorationType;
- (id)initWithAction:(id)arg1;

@end

