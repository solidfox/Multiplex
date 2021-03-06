//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDEPlaygroundCommonSharedContext.h>

@class DVTFilePath, IDEPlaygroundSharedContext, NSArray;

@interface IDEPlaygroundPageSharedContext : IDEPlaygroundCommonSharedContext
{
    IDEPlaygroundSharedContext *_playgroundContext;
}

+ (id)keyPathsForValuesAffectingResourceDirectoryFilePaths;
+ (id)keyPathsForValuesAffectingImplicit;
@property(readonly, nonatomic) __weak IDEPlaygroundSharedContext *playgroundContext; // @synthesize playgroundContext=_playgroundContext;
@property(readonly, nonatomic) NSArray *resourceDirectoryFilePaths;
- (id)_targetTripleForAuxiliarySource;
- (id)_sdkForAuxiliarySource;
- (id)auxiliarySourceFrameworkDependencies;
- (id)sourcesDirectoryPath;
- (id)resourcesDirectoryPath;
- (id)name;
@property(readonly, nonatomic) BOOL implicit; // @dynamic implicit;
- (id)description;
- (id)_initWithFilePath:(id)arg1 andPlaygroundContext:(id)arg2;

// Remaining properties
@property(readonly, nonatomic) DVTFilePath *swiftContentsFilePath; // @dynamic swiftContentsFilePath;
@property(readonly, nonatomic) DVTFilePath *timelineFilePath; // @dynamic timelineFilePath;

@end

