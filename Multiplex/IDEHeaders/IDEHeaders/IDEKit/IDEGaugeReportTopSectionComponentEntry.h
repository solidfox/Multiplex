//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString, NSView;

@interface IDEGaugeReportTopSectionComponentEntry : NSObject
{
    NSString *_label;
    NSView *_accessoryView;
    NSView *_componentView;
}

@property(readonly) NSView *componentView; // @synthesize componentView=_componentView;
@property(readonly) NSView *accessoryView; // @synthesize accessoryView=_accessoryView;
@property(readonly) NSString *label; // @synthesize label=_label;
- (id)initWithLabel:(id)arg1 accessoryView:(id)arg2 componentView:(id)arg3;

@end

