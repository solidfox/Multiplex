//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDELocalizationWorkContext.h>

@class NSData, NSURL;

@interface IDELocalizationWorkWriteData : IDELocalizationWorkContext
{
    NSData *_data;
    NSURL *_url;
}

@property(retain) NSURL *url; // @synthesize url=_url;
@property(retain) NSData *data; // @synthesize data=_data;

@end

