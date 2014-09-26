//
//  CMDTextEditor.h
//  CommandEdit
//
//  Created by Kolin Krewinkel on 9/25/14.
//  Copyright (c) 2014 Kolin Krewinkel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "DVTInterfaces.h"

@interface CMDTextEditor : DVTSourceTextView

- (instancetype)initWithTextStorage:(DVTTextStorage *)textStorage;

@end
