//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface NSGraphicsContext (DVTNSGraphicsContextAdditions)
+ (void)dvt_drawInBitmap:(id)arg1 withBlock:(dispatch_block_t)arg2;
+ (void)dvt_drawInContext:(struct CGContext *)arg1 withBlock:(dispatch_block_t)arg2;
- (void)dvt_temporarilyMakeCurrentAndDoOperationPerservingState:(dispatch_block_t)arg1;
- (void)dvt_drawBlockByPreservingState:(dispatch_block_t)arg1;
@end

