//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface DVTMergedSortedArray : NSArray
{
    NSArray *_array1;
    NSArray *_array2;
    struct _mergedIndexes {
        unsigned int :1;
        unsigned int :31;
    } *_combinedInfo;
    unsigned long long _count;
}

- (void)getObjects:(id *)arg1 range:(struct _NSRange)arg2;
- (id)objectAtIndex:(unsigned long long)arg1;
- (unsigned long long)count;
- (void)dealloc;
- (id)initWithArray:(id)arg1 array:(id)arg2 context:(void *)arg3 mergeDuplicates:(BOOL)arg4 comparator:(dispatch_block_t)arg5;
- (id)initWithArray:(id)arg1 array:(id)arg2 context:(void *)arg3 comparator:(dispatch_block_t)arg4;
- (id)_initWithArray:(id)arg1 array:(id)arg2 context:(void *)arg3 mergeDuplicates:(BOOL)arg4 comparator:(dispatch_block_t)arg5;

@end

