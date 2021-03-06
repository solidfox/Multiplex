//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSPredicate, NSString;

@interface IDEBatchFindFileLocator : NSObject
{
    NSString *_path;
    NSPredicate *_predicate;
}

@property(readonly) NSPredicate *predicate; // @synthesize predicate=_predicate;
@property(readonly) NSString *path; // @synthesize path=_path;
- (id)locationOperationForWorkspace:(id)arg1 withResultsBlock:(dispatch_block_t)arg2;
@property(readonly) BOOL requiresMainThread;
- (id)initWithPath:(id)arg1 andPredicate:(id)arg2;

@end

