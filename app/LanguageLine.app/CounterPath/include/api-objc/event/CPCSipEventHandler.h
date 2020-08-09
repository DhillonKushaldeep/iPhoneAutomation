//
//  CPCSipEventHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"
#import "CPCSipEventState.h"

typedef NSInteger CPCSipEventSubscriptionHandle;

/**
* Do not use this class; it covers unreleased, unsupported 
* functionality that is subject to change. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionEndReason : CPCEnumType

+ (NSInteger)Unknown;
+ (NSInteger)ServerError;
+ (NSInteger)ServerEnded;

@end


/**
* Do not use this class; it covers unreleased, unsupported 
* functionality that is subject to change. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionType : CPCEnumType

+ (NSInteger)Incoming;
+ (NSInteger)Outgoing;

@end


/**
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipSubscriptionState : CPCEnumType

+ (NSInteger)NotStarted;
+ (NSInteger)Pending;
+ (NSInteger)Active;
+ (NSInteger)Terminated;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventBaseEvent : NSObject

@property (nonatomic, readonly) CPCSipEventSubscriptionHandle handler;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventNewSubscriptionEvent : CPCSipEventBaseEvent

@property (nonatomic, readonly)CPCSipEventSubscriptionType *subscriptionType;
@property (nonatomic, readonly)NSString *remoteAddress;
@property (nonatomic, readonly)NSString *remoteDisplayName;
@property (nonatomic, readonly)NSString *eventPackage;
@property (nonatomic, readonly)NSArray *eventPackageParams; //CPCParameter
@property (nonatomic, readonly)NSArray *supportedMimeTypes; //CPCMimeType
@property (nonatomic, readonly)CPCSipAccountHandle account;

@end

//--------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionEndedEvent : CPCSipEventBaseEvent

@property (nonatomic, readonly)CPCSipEventSubscriptionEndReason *endReason;
@property (nonatomic, readonly)CPCSipEventSubscriptionType *subscriptionType;
@property (nonatomic, readonly)NSInteger statusCode; // Error code
@property (nonatomic, readonly)NSInteger retryAfter; // value of Retry-Header if present
@property (nonatomic, readonly)BOOL initialSubscribe; // Initial Subscribe failed
@property (nonatomic, readonly)BOOL isNotifyTerminated; // Terminated because of NOTIFY
@property (nonatomic, readonly)NSString *remoteAddress; // Buddy address
@property (nonatomic, readonly)NSString *reason; // subscription end reason

@end
//---------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventIncomingEventStateEvent : CPCSipEventBaseEvent

@property (nonatomic, readonly)CPCSipEventState *eventState;
@property (nonatomic, readonly)NSArray *eventPackageParams; //CPCParameter

@end
//---------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventIncomingResourceListEvent : CPCSipEventBaseEvent

@property (nonatomic, readonly)NSString *uri;
@property (nonatomic, readonly)NSInteger version;
@property (nonatomic, readonly)BOOL fullState;
@property (nonatomic, readonly)NSArray *resources; //CPCSipEventResource

@end
//---------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionStateChangedEvent : CPCSipEventBaseEvent
@property (nonatomic, readonly)CPCSipSubscriptionState *subscriptionState;
@end
//----------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionNotifySuccessEvent : CPCSipEventBaseEvent
@end
//----------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionNotifyFailureEvent : CPCSipEventBaseEvent
@property (nonatomic, readonly)   NSInteger sipResponseCode;
@end
//-----------------

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionErrorEvent : CPCSipEventBaseEvent
@property (nonatomic, readonly)NSString *errorText;
@end
//-----------------

@protocol SipEventSubscriptionHandler <NSObject>
@optional
- (void)onSipNewSubscription:(CPCSipEventNewSubscriptionEvent*) event;
- (void)onSipSubscriptionEnded:(CPCSipEventSubscriptionEndedEvent*) event;
- (void)onSipSubscriptionIncomingEventState:(CPCSipEventIncomingEventStateEvent*) event;
- (void)onSipSubscriptionIncomingResourceList:(CPCSipEventIncomingResourceListEvent*) event;
- (void)onSipSubscriptionStateChanged:(CPCSipEventSubscriptionStateChangedEvent*) event;
- (void)onSipSubscriptionNotifySuccess:(CPCSipEventSubscriptionNotifySuccessEvent*) event;
- (void)onSipSubscriptionNotifyFailure:(CPCSipEventSubscriptionNotifyFailureEvent*) event;
- (void)onSipSubscriptionError:(CPCSipEventSubscriptionErrorEvent*) event;
@end
