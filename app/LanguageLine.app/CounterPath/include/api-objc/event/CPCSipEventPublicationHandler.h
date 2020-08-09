//
//  CPCSipEventPublicationHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"

typedef NSInteger CPCSipEventPublicationHandle;
/**
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventPublicationFailureReason : CPCEnumType

+ (NSInteger)Unknown;
+ (NSInteger)ServerError;
+ (NSInteger)ConditionalRequestFailed;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationBaseEvent : NSObject

@property (nonatomic, readonly) CPCSipEventPublicationHandle handle;

@end

/**
 * Event passed in SipEventPublicationHandler::onPublicationSuccess().
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationSuccessEvent : CPCSipPublicationBaseEvent
@end

/**
 * Event passed in SipEventPublicationHandler::onPublicationFailure().
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationFailureEvent : CPCSipPublicationBaseEvent

@property (nonatomic, readonly)CPCSipEventPublicationFailureReason *reason;

@end
/**
 * Event passed in SipEventPublicationHandler::onPublicationRemove().
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationRemoveEvent : CPCSipPublicationBaseEvent
@end

/**
 * Event passed in SipEventPublicationHandler::onError();
 * used to report general SDK error conditions, such as invalid handles, or cases
 * where the call is not in a valid state for the requested operation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationErrorEvent : CPCSipPublicationBaseEvent

@property (nonatomic, readonly)NSString *errorText;

@end


/**
 * Handler for events relating to PUBLISH-related functionality (RFC 3903);
 * set in SipEventPublicationManager::setHandler();
 * if you are implementing SipPresencePublicationHandler,
 * you should not use this SipEventPublicationHandler to handle "presence" events.
 */
@protocol CPCSipEventPublicationHandler <NSObject>
@optional

-(void) onPublicationSuccess:(CPCSipPublicationSuccessEvent*) event;
-(void)	onPublicationFailure:(CPCSipPublicationFailureEvent*) event;
-(void)	onPublicationRemove:(CPCSipPublicationRemoveEvent*) event;
-(void)	onPublicationError:(CPCSipPublicationErrorEvent*) event;

@end

