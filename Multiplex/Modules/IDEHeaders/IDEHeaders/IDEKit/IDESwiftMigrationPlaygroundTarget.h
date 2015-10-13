//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDESwiftMigrationTarget.h>

@class IDEPlayground;

@interface IDESwiftMigrationPlaygroundTarget : IDESwiftMigrationTarget
{
    IDEPlayground *_playground;
}

@property(readonly, copy) IDEPlayground *playground; // @synthesize playground=_playground;
- (BOOL)migratorHasBeenRun;
- (void)updateBuildSettings;
- (id)iconImage;
- (id)blueprint;
- (id)subTitle;
- (id)title;
- (id)initWithPlayground:(id)arg1 assistantContext:(id)arg2;

@end
