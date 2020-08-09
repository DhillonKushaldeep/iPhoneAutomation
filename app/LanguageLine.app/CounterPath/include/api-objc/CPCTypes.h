//
//  CPCTypes.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCConfig.h"

enum {
   kCPCSuccess = 0,
   kCPCError = 0x80000001,
};

/**   Abstract base class
 *    object wrapper for C++ enum types so that they can be elements of an NSArray;
 *    the concrete subclasses will provide class methods for the enumeration.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCEnumType : NSObject
{
   NSInteger _value;
}
@property (nonatomic, assign, readonly) NSInteger value;

+ (instancetype)enumWithValue:(NSInteger)value;
- (instancetype)initWithValue:(NSInteger)value;

@end


// SIP event types

typedef NSUInteger CPCSipEventHandle;
typedef NSUInteger CPCSipPresenceHandle;
typedef NSUInteger CPCSipPresencePublicationHandle;


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCNameAddress : NSObject
{
	NSString *_displayName;
	NSString *_address;
}

@property(nonatomic, copy) NSString* displayName;
@property(nonatomic, copy) NSString* address;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCMimeType : NSObject
{
	NSString* _mimeType;
	NSString* _mimeSubType;
}

@property(nonatomic, copy) NSString* mimeType;
@property(nonatomic, copy) NSString* mimeSubType;

@end


/**
 * Possible states for the 'IsComposing' indicator.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCIsComposingMessageState : CPCEnumType

+ (NSInteger) unknown;
+ (NSInteger) idle;
+ (NSInteger) active;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipHeader : NSObject
{
	NSString *_header;
	NSString *_value;
}

@property (nonatomic, copy)NSString *header;
@property (nonatomic, copy)NSString *value;

- (id)initWithHeader:(NSString*)header andValue:(NSString*)value;

@end


@interface CPCDialogId : NSObject
{
	NSString *_callId;
	NSString *_localTag;
	NSString *_remoteTag;
}

@property (nonatomic, copy) NSString *callId;
@property (nonatomic, copy) NSString *localTag;
@property (nonatomic, copy) NSString *remoteTag;

@end

@interface CPCParameter : NSObject
{
	NSString *_name;
	NSString *_value;
}

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *value;

@end


@interface CPCSipResponseType : NSObject
{
	NSString *_method;
	NSUInteger _responseCode;
}

- (instancetype) initWithMethod:(NSString*)method code:(NSUInteger)code;

@property (nonatomic, copy) NSString *method;
@property (nonatomic, assign) NSUInteger responseCode;

@end

@interface CPCSipParameterType : NSObject
{
	NSString *_name;
	NSString *_value;
}

- (instancetype)initWithValue:(NSString*)value name:(NSString*)name;

@property (nonatomic, copy)NSString *name;
@property (nonatomic, copy)NSString *value;

@end
