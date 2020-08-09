//
//  CPCSipImDocument.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipIMMimeType : CPCEnumType


+(NSUInteger)mimeType_textPlain;
+(NSUInteger)mimeType_textHtml;
+(NSUInteger)mimeType_custom;

@end
/**
* Static class to get access to the constants used 
* for the SIP instant message.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipImDocument : NSObject

@property (nonatomic, assign) CPCSipIMMimeType* mimeType;

@end
