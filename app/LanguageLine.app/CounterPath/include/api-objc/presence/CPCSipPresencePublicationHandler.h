//
//  CPCSipPresencePublicationHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"
#import "../event/CPCSipEventHandler.h"
#import "CPCSipPresenceDocument.h"
#import "../event/CPCSipEventPublicationHandler.h"


/**
* Abstract parent class; do not instantiate this class directly 
* (doing so will throw an exception)
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresencePublicationEvent : NSObject

@property(nonatomic, readonly) CPCSipPresencePublicationHandle handle;
@property(nonatomic, readonly) CPCSipAccountHandle account;

@end


/**
* Event passed in onPublicationSuccess: in the 
* <CPCSipPresencePublicationHandler> formal protocol.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresencePublicationSuccessEvent : CPCSipPresencePublicationEvent
@end

/**
* Event passed in onPublicationFailure: in the 
* <CPCSipPresencePublicationHandler> formal protocol.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresencePublicationFailureEvent : CPCSipPresencePublicationEvent

@property(nonatomic, readonly) CPCSipEventPublicationFailureReason *reason;

@end


/**
* Event passed in onPublicationRemove: in the 
* <CPCSipPresencePublicationHandler> formal protocol.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresencePublicationRemoveEvent : CPCSipPresencePublicationEvent
@end


/**
* Event passed in onPublicationError: in the 
* <CPCSipPresencePublicationHandler> formal protocol.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresencePublicationErrorEvent : CPCSipPresencePublicationEvent

@property(nonatomic, readonly) NSString *errorText;

@end


/**
* Handler for events relating to publishing presence updates; set in addPublicationHandlerr: in the CPCSipPresenceManager class.
*/ 
@protocol CPCSipPresencePublicationHandler <NSObject>
@optional

- (void) onPublicationSuccess:(CPCSipPresencePublicationSuccessEvent*)event;
- (void) onPublicationFailure:(CPCSipPresencePublicationFailureEvent*)event;
- (void) onPublicationRemove:(CPCSipPresencePublicationRemoveEvent*)event;
- (void) onPublicationError:(CPCSipPresencePublicationErrorEvent*)event;

@end
