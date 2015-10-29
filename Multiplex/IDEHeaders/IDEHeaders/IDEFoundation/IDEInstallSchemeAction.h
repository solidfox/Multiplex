//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDESchemeAction.h>

#import "DVTXMLUnarchiving-Protocol.h"

@class NSArray, NSString;

@interface IDEInstallSchemeAction : IDESchemeAction <DVTXMLUnarchiving>
{
    NSString *_buildConfiguration;
    NSString *_customInstallName;
    NSArray *_killProcessList;
}

+ (id)keyPathsForValuesAffectingKillProcessListString;
+ (id)keyPathsForValuesAffectingDefaultInstallName;
+ (id)keyPathsForValuesAffectingSubtitle;
+ (BOOL)allowInstallSchemeAction;
@property(copy) NSArray *killProcessList; // @synthesize killProcessList=_killProcessList;
@property(copy) NSString *customInstallName; // @synthesize customInstallName=_customInstallName;
- (void)setBuildConfiguration:(id)arg1;
- (id)buildConfiguration;
- (void)setKillProcessesFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
- (void)setCustomInstallNameFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
- (void)setBuildConfigurationFromUTF8String:(char *)arg1 fromXMLUnarchiver:(id)arg2;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)arg1 version:(id)arg2;
- (void)dvt_awakeFromXMLUnarchiver:(id)arg1;
- (BOOL)hasDefaultValues;
- (id)overridingMacrosForInstallBuildForWorkspaceArena:(id)arg1 destination:(id)arg2;
- (id)installOperationWithExecutionEnvironment:(id)arg1 withBuildOperation:(id)arg2 buildParameters:(id)arg3 schemeActionRecord:(id)arg4 outError:(id *)arg5 actionCallbackBlock:(dispatch_block_t)arg6;
@property(copy) NSString *killProcessListString;
@property(readonly) NSString *defaultInstallName;
- (BOOL)doesNonActionWork;
- (id)subtitle;
- (id)name;
- (void)_commonInit;
- (id)initFromXMLUnarchiver:(id)arg1 archiveVersion:(float)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
