//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import "DVTInvalidation-Protocol.h"

@class DVTCustomDataSpecifier, DVTPreferenceSetManager, NSData, NSImage, NSString, NSURL;

@protocol DVTPreferenceSet <DVTInvalidation>
+ (NSString *)titleForNewPreferenceSetFromTemplate;
+ (NSString *)preferenceSetsListHeader;
+ (NSString *)preferenceSetsFileExtension;
+ (NSString *)defaultKeyForExcludedBuiltInPreferenceSets;
+ (NSString *)defaultKeyForCurrentPreferenceSet;
+ (NSURL *)builtInPreferenceSetsDirectoryURL;
+ (id <DVTPreferenceSet>)systemPreferenceSet;
+ (NSString *)preferenceSetGroupingName;
+ (DVTPreferenceSetManager *)preferenceSetsManager;
@property BOOL contentNeedsSaving;
@property(readonly, getter=isBuiltIn) BOOL builtIn;
@property(retain) DVTCustomDataSpecifier *customDataSpecifier;
@property(retain) NSImage *image;
@property(readonly, copy) NSString *localizedName;
@property(readonly, copy) NSString *name;
- (NSData *)dataRepresentationWithError:(id *)arg1;
- (id)initWithCustomDataSpecifier:(DVTCustomDataSpecifier *)arg1 basePreferenceSet:(id <DVTPreferenceSet>)arg2;
- (id)initWithName:(NSString *)arg1 dataURL:(NSURL *)arg2;

@optional
+ (NSString *)titleForManagePreferenceSets;
@end
