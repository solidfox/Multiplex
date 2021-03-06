//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTLineGraphLayerDataSource-Protocol.h"

@class NSArray, NSString;

@interface DVTDefaultLineGraphLayerDataSource : NSObject <DVTLineGraphLayerDataSource>
{
    NSArray *_linePointValues;
}

- (id)lineDataForBounds:(struct _DVTGraphBounds)arg1;
- (id)initWithEquidistantYNumbers:(id)arg1 startingAtX:(double)arg2 deltaX:(double)arg3;
- (id)initWithLinePointValues:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

