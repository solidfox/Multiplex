//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTTableCellViewFormatter : NSFormatter
{
    long long _backgroundStyle;
    NSString *_filterMatchString;
    struct _NSRange _filterMatchRange;
}

+ (id)_filterMatchAttributesForDarkBackground;
+ (id)_filterMatchAttributesForLightBackground;
@property struct _NSRange filterMatchRange; // @synthesize filterMatchRange=_filterMatchRange;
@property(retain) NSString *filterMatchString; // @synthesize filterMatchString=_filterMatchString;
@property long long backgroundStyle; // @synthesize backgroundStyle=_backgroundStyle;
- (void)_highlightFilterMatchSubstringsIfNecessary:(id)arg1;
- (BOOL)getObjectValue:(out id *)arg1 forString:(id)arg2 errorDescription:(out id *)arg3;
- (id)attributedStringForObjectValue:(id)arg1 withDefaultAttributes:(id)arg2;
- (id)stringForObjectValue:(id)arg1;
- (id)init;

@end

