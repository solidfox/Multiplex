//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSPointerArray;

@interface _DVTLogObjectsRequest : NSObject
{
    NSPointerArray *_remainingObjects;
    double _initialRequestTimeInterval;
    double _lastRequestTimeInterval;
}

@property double lastRequestTimeInterval; // @synthesize lastRequestTimeInterval=_lastRequestTimeInterval;
@property double initialRequestTimeInterval; // @synthesize initialRequestTimeInterval=_initialRequestTimeInterval;
@property(retain) NSPointerArray *remainingObjects; // @synthesize remainingObjects=_remainingObjects;

@end

