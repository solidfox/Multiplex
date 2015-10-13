//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDEIssueProvider.h>

@class DVTObservingToken, IDEWorkspace, NSDictionary;

@interface IDESourceControlIssueProvider : IDEIssueProvider
{
    IDEWorkspace *_workspace;
    DVTObservingToken *_scmMonitorObservingToken;
    id _didUpdateServerStatusNotificationToken;
    id _didUpdateLocalStatusNotificationToken;
    NSDictionary *_localizedStrings;
}

+ (id)_issueScanningQueue;
- (id)ideModelObjectTypeIdentifier;
- (id)_issueTypeIdentifierForStatus:(int)arg1;
- (id)_shortMessageForItem:(id)arg1;
- (id)displayNameForIssueTypeIdentifier:(id)arg1;
- (id)_locationsOfTextualConflictsAtPath:(id)arg1;
- (id)_issuesForItemWithStatus:(id)arg1;
- (void)_scanForIssues;
- (void)primitiveInvalidate;
- (void)_setUpSourceControlObserving;
- (id)_localizedStringForKey:(id)arg1;
- (void)_generateLocalizedStrings;
- (id)initWithIssueManager:(id)arg1 extension:(id)arg2;

@end
