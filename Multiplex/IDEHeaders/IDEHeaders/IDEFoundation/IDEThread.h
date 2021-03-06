//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTInvalidation-Protocol.h"
#import "IDEDebugNavigableModel-Protocol.h"

@class DVTStackBacktrace, IDEDebugProcess, IDELaunchSession, NSArray, NSNumber, NSString;

@interface IDEThread : NSObject <IDEDebugNavigableModel, DVTInvalidation>
{
    BOOL _hasLatestStackFrames;
    BOOL _recorded;
    BOOL _recordedForMemoryAddress;
    int _state;
    NSString *_associatedProcessUUID;
    IDEDebugProcess *_parentProcess;
    NSNumber *_uniqueID;
    NSString *_threadName;
    NSString *_threadDisplayName;
    NSArray *_stackFrames;
    IDEThread *_recordedThread;
    NSString *_lastReasonStopped;
}

+ (id)keyPathsForValuesAffectingThreadDisplayName;
+ (id)displayNameForThreadName:(id)arg1 threadID:(id)arg2;
+ (void)initialize;
@property(copy, nonatomic) NSString *lastReasonStopped; // @synthesize lastReasonStopped=_lastReasonStopped;
@property(nonatomic, getter=isRecordedForMemoryAddress) BOOL recordedForMemoryAddress; // @synthesize recordedForMemoryAddress=_recordedForMemoryAddress;
@property(nonatomic, getter=isRecorded) BOOL recorded; // @synthesize recorded=_recorded;
@property(retain, nonatomic) IDEThread *recordedThread; // @synthesize recordedThread=_recordedThread;
@property(copy, nonatomic) NSArray *stackFrames; // @synthesize stackFrames=_stackFrames;
@property(nonatomic) BOOL hasLatestStackFrames; // @synthesize hasLatestStackFrames=_hasLatestStackFrames;
@property(readonly, nonatomic) NSString *threadDisplayName; // @synthesize threadDisplayName=_threadDisplayName;
@property(copy, nonatomic) NSString *threadName; // @synthesize threadName=_threadName;
@property(nonatomic) int state; // @synthesize state=_state;
@property(readonly, nonatomic) NSNumber *uniqueID; // @synthesize uniqueID=_uniqueID;
@property(retain, nonatomic) IDEDebugProcess *parentProcess; // @synthesize parentProcess=_parentProcess;
@property(readonly, copy) NSString *associatedProcessUUID; // @synthesize associatedProcessUUID=_associatedProcessUUID;
- (void)primitiveInvalidate;
- (id)compressedStackFramesIncludingRecorded:(long long)arg1;
- (BOOL)_shouldSkipRecordedFrames;
- (id)compressedStackFrames:(long long)arg1;
@property(readonly) IDELaunchSession *launchSession;
@property(readonly, copy) NSString *description;
- (id)init;
- (id)initWithParentProcess:(id)arg1 uniqueID:(id)arg2;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

