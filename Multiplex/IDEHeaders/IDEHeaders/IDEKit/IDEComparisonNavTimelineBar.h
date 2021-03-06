//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEViewController.h>

@class IDEComparisonEditor, IDEComparisonEditorChangesStepperView, IDEComparisonEditorTimelineNavBar, IDEComparisonNavTimelineView, IDEPathControl, NSWindow;

@interface IDEComparisonNavTimelineBar : IDEViewController
{
    IDEComparisonEditorTimelineNavBar *_navTimelineBarContainerView;
    NSWindow *_attachedWindow;
    id _notificationToken;
    IDEComparisonNavTimelineView *_timelineView;
    IDEComparisonEditor *_comparisonEditor;
}

@property(retain) IDEComparisonEditor *comparisonEditor; // @synthesize comparisonEditor=_comparisonEditor;
@property(retain) IDEComparisonNavTimelineView *timelineView; // @synthesize timelineView=_timelineView;
@property(retain) id notificationToken; // @synthesize notificationToken=_notificationToken;
@property(retain) IDEComparisonEditorTimelineNavBar *navTimelineBarContainerView; // @synthesize navTimelineBarContainerView=_navTimelineBarContainerView;
- (void)animationDidStop:(id)arg1 finished:(BOOL)arg2;
- (void)layoutContainerView;
@property(readonly) IDEComparisonEditorChangesStepperView *changesStepperControl;
@property(readonly) IDEPathControl *secondaryPathControl;
@property(readonly) IDEPathControl *primaryPathControl;
@property BOOL hideChangesStepperControl;
@property BOOL hideTimelineButton;
@property BOOL hideSecondaryPathControl;
@property BOOL showAsInset;
@property(retain) NSWindow *attachedWindow;
- (void)layoutAttachedWindow;
- (void)toggleTimelineVisibility:(id)arg1;
- (void)hideTimeline;
- (void)showTimeline;
- (void)primitiveInvalidate;
- (void)viewWillUninstall;
- (void)loadView;
- (id)initWithComparisonEditor:(id)arg1;

@end

