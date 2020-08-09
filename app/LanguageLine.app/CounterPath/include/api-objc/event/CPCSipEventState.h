//
//  CPCSipEventState.h
//  CPCAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import "../CPCTypes.h"

@class CPCSipSubscriptionState;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipSubscriptionEndReason : CPCEnumType

+ (instancetype) unknown;
+ (instancetype) serverError;
+ (instancetype) serverEnded;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSubscriptionType : CPCEnumType

+ (instancetype) incoming;
+ (instancetype) outgoing;

@end


/**
 * A class. Used with CPCSipEventManager and CPCSipPublicationManager.
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface  CPCSipEventState : NSObject
{
	NSString *_mimeType;
	NSString *_mimeSubType;
	NSString *_eventPackage;
    NSString *_contentUTF8;
    NSUInteger _contentLength;
    NSUInteger _expiresTimeMs;
}

@property(nonatomic, copy)NSString *mimeType;
@property(nonatomic, copy)NSString *mimeSubType;
@property(nonatomic, copy)NSString *eventPackage;
@property(nonatomic, copy)NSString *contentUTF8;
@property(nonatomic, readwrite)NSUInteger contentLength;
@property(nonatomic, readwrite)NSUInteger expiresTimeMs;

@end

/**
 * A class. Used with CPCSipEventManager for resource list processing.
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface  CPCSipEventResourceInstance : NSObject
{
	NSString *_id;
	CPCSipSubscriptionState *_subscriptionState;
	NSString *_mimeType;
	NSString *_mimeSubType;
	NSString *_contentUtf8;
}

@property (nonatomic, copy)NSString *resourceID;
@property (nonatomic, retain)CPCSipSubscriptionState *subscriptionState;
@property (nonatomic, copy)NSString *mimeType;
@property (nonatomic, copy)NSString *mimeSubType;
@property (nonatomic, copy)NSString *contentUtf8;

@end

/**
 * A class. Used with CPCSipEventManager for resource list processing.
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventResource : NSObject
{
	NSString *_uri;
	NSArray  *_names; //NSString
	NSArray  *_instances; //CPCSipEventResourceInstance
}

@property (nonatomic, copy)NSString *uri;
@property (nonatomic, copy)NSArray *names;
@property (nonatomic, copy)NSArray *instances;

@end
