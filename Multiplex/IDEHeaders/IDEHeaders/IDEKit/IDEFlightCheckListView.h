//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import "DVTLayoutView_ML-Protocol.h"

#import "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, DVTStackView_ML, NSArray, NSButton, NSMapTable, NSSet, NSString, NSTextField;

@interface IDEFlightCheckListView : DVTLayoutView_ML <DVTInvalidation>
{
    int _style;
    NSArray *_flightChecks;
    id  _delegate;
    DVTStackView_ML *_stackView;
    NSMapTable *_flightCheckToViewMap;
    NSButton *_resolveButton;
    NSSet *_flightCheckObservers;
    NSTextField *_stepsLabel;
}

+ (void)initialize;
@property(retain, nonatomic) NSTextField *stepsLabel; // @synthesize stepsLabel=_stepsLabel;
@property(retain, nonatomic) NSSet *flightCheckObservers; // @synthesize flightCheckObservers=_flightCheckObservers;
@property(retain, nonatomic) NSButton *resolveButton; // @synthesize resolveButton=_resolveButton;
@property(retain, nonatomic) NSMapTable *flightCheckToViewMap; // @synthesize flightCheckToViewMap=_flightCheckToViewMap;
@property(retain, nonatomic) DVTStackView_ML *stackView; // @synthesize stackView=_stackView;
@property __weak id  delegate; // @synthesize delegate=_delegate;
@property(nonatomic) int style; // @synthesize style=_style;
@property(copy, nonatomic) NSArray *flightChecks; // @synthesize flightChecks=_flightChecks;
- (void)layoutBottomUp;
- (void)layoutTopDown;
- (BOOL)_shouldShowStepsLabel;
- (BOOL)_shouldShowResolveButton;
- (BOOL)_haveFailedFlightChecks;
- (BOOL)isFlipped;
- (void)resolveIssues:(id)arg1;
- (void)_updateFlightCheckViews;
- (void)primitiveInvalidate;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

