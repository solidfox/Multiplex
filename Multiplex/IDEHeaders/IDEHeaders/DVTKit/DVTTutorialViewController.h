//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTPagingDotView, DVTTutorialController, NSButton, NSView;

@interface DVTTutorialViewController : NSViewController
{
    DVTPagingDotView *_pagingDotView;
    NSButton *_nextButton;
    NSButton *_nextButtonArrow;
    NSButton *_previousButton;
    NSButton *_previousButtonArrow;
    NSView *_navigationContainerView;
    DVTTutorialController *_tutorialController;
}

@property __weak DVTTutorialController *tutorialController; // @synthesize tutorialController=_tutorialController;
@property __weak NSView *navigationContainerView; // @synthesize navigationContainerView=_navigationContainerView;
@property __weak NSButton *previousButtonArrow; // @synthesize previousButtonArrow=_previousButtonArrow;
@property __weak NSButton *previousButton; // @synthesize previousButton=_previousButton;
@property __weak NSButton *nextButtonArrow; // @synthesize nextButtonArrow=_nextButtonArrow;
@property __weak NSButton *nextButton; // @synthesize nextButton=_nextButton;
@property __weak DVTPagingDotView *pagingDotView; // @synthesize pagingDotView=_pagingDotView;
- (void)setPreviousButtonHidden:(BOOL)arg1;
- (void)setNextButtonHidden:(BOOL)arg1;
- (void)_linkifyButton:(id)arg1;
- (void)viewDidLoad;
- (void)previousAction:(id)arg1;
- (void)nextAction:(id)arg1;

@end

