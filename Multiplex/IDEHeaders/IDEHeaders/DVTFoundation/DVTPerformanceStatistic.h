//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTPerformanceStatistic : NSObject
{
    NSString *_name;
    dispatch_block_t _checkpointBlock;
    dispatch_block_t _logBlock;
}

+ (void)freezePerformanceStatisticRegistration;
+ (id)allStatistics;
+ (id)registerStatisticWithName:(id)arg1 checkpointBlock:(dispatch_block_t)arg2 logBlock:(dispatch_block_t)arg3;
+ (void)initialize;
@property(readonly, copy) dispatch_block_t logBlock; // @synthesize logBlock=_logBlock;
@property(readonly, copy) dispatch_block_t checkpointBlock; // @synthesize checkpointBlock=_checkpointBlock;
@property(readonly, copy) NSString *name; // @synthesize name=_name;
- (id)initWithName:(id)arg1 checkpointBlock:(dispatch_block_t)arg2 logBlock:(dispatch_block_t)arg3;

@end

