//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTEncodableIndexDelegate-Protocol.h"
#import "DVTInvalidation-Protocol.h"

@class DVTEncodableIndex, DVTLibraryFragmentFilter, DVTStackBacktrace, IDEWorkspace, NSArray, NSMutableSet, NSObject<OS_dispatch_queue>, NSString;

@interface IDETextIndex : NSObject <DVTEncodableIndexDelegate, DVTInvalidation>
{
    NSObject *_indexQueue;
    unsigned long long _maxConcurrentOperationCount;
    DVTLibraryFragmentFilter *_filterIndex;
    DVTEncodableIndex *_findIndex;
    IDEWorkspace *_workspace;
    NSArray *_dataProviders;
    int _readyFlag;
    NSMutableSet *_scheduledJobs;
    unsigned long long _nRunningJobs;
    double _startTime;
    long long _nCompleted;
    NSObject *_updateQueue;
    double _timeOfLastUpdateRequest;
    BOOL _updatePending;
    NSObject *_saveQueue;
    double _timeOfLastSaveRequest;
    unsigned long long _indexTypesForPendingSave;
}

+ (void)_logMissingProviderForFileDataType:(id)arg1;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (long long)defaultMaxConcurrentOperationCount;
+ (id)logAspect;
+ (void)initialize;
- (id)_dataProviderForFilePath:(id)arg1 lastKnownFileDataType:(id)arg2 outFileDataType:(id *)arg3;
- (id)_dataProviderForFileDataType:(id)arg1;
- (void)_initDataProviders;
- (id)_computeFindableForFilePath:(id)arg1 withDataProvider:(id)arg2;
- (BOOL)_computeFilterForFilePath:(id)arg1 withDataProvider:(id)arg2 queryString:(id)arg3;
- (id)findableForFilePath:(id)arg1;
- (id)filePathsPossiblyContainingString:(id)arg1 indexedFilePaths:(id *)arg2;
- (void)_finishIndexing;
- (void)_reportProgress:(double)arg1;
- (void)_startIndexing;
- (void)_postNotificationName:(id)arg1 userInfo:(id)arg2;
- (void)_scheduleJobs;
- (void)setMaxConcurrentOperationCount:(unsigned long long)arg1;
- (void)scheduleJob:(id)arg1;
- (void)scheduleJobs:(id)arg1;
- (void)encodableIndex:(id)arg1 didRemoveItemForIdentifier:(id)arg2;
- (void)encodableIndex:(id)arg1 didAddItemForIdentifier:(id)arg2;
- (void)_removeIndexEntriesForPathStrings:(id)arg1 indexTypes:(unsigned long long)arg2;
- (void)_indexFileInPath:(id)arg1;
- (id)_collectFilePathsForTextIndex;
- (void)_scheduleUpdate;
- (void)updateTextIndex;
- (void)_updateIfReady;
- (BOOL)_hasBegunTextIndexing;
- (void)_beginTextIndexingIfNeeded;
- (void)beginTextIndexing;
- (id)_indexFolderPath;
- (void)_scheduleSaveForTypes:(unsigned long long)arg1;
- (void)_saveTextIndexForTypes:(unsigned long long)arg1;
- (void)_loadTextIndex;
- (dispatch_block_t)_validationBlock;
- (void)primitiveInvalidate;
- (void)dealloc;
- (id)initWithWorkspace:(id)arg1;
- (id)init;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end
