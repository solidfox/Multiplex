//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSMutableOrderedSet;

@interface _DVTTimeSlicedMainThreadActiveWorkQueues : NSObject
{
    NSMutableOrderedSet *_workQueues;
    BOOL _nextProcessingBatchScheduled;
}

- (void)_tattleOnOvershotDeadline:(double)arg1 currentQueue:(id)arg2;
- (void)_removeWorkQueue:(id)arg1;
- (void)_addWorkQueue:(id)arg1;
- (void)_scheduleProcessing;
- (id)_nextWorkQueue;
- (void)_processWorkQueuesOnDeadline;
- (id)init;

@end

