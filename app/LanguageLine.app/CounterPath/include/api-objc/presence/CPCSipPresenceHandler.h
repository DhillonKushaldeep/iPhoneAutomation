//
//  CPCSipPresenceHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"
#import "../event/CPCSipEventHandler.h"
#import "CPCSipPresenceDocument.h"



/**
* Abstract parent class; do not instantiate this class directly 
* (doing so will throw an exception)
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresenceEvent : NSObject

@property (nonatomic, readonly) CPCSipPresenceHandle subscription;
@property (nonatomic, readonly) CPCSipAccountHandle account;

@end




/**
 * Event passed in onNewSubscription: in the 
 * <CPCSipPresSubscriptionHandler> formal protocol. 
 * An outgoing SUBSCRIBE has been submitted to the SIP stack for transmission, OR
 * an outgoing SUBSCRIBE has forked, OR
 * an incoming SUBSCRIBE has been received.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresNewSubscriptionEvent :CPCSipPresenceEvent

@property (nonatomic, readonly) CPCSipEventSubscriptionType* subscriptionType;
@property (nonatomic, readonly) NSString* remoteAddress;
@property (nonatomic, readonly) NSString* remoteDisplayName;

@end



/**
 * Event passed in onSubscriptionEnded: in the 
 * <CPCSipPresSubscriptionHandler> formal protocol. 
 * The client or server subscription session is terminated (for any reason).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSubscriptionEndedEvent : CPCSipPresenceEvent

@property (nonatomic, readonly) NSUInteger retryTime;
@property (nonatomic, readonly) CPCSipEventSubscriptionEndReason* endReason;

@end



/**
 * Event passed in onIncomingPresenceStatus: in the 
 * <CPCSipPresSubscriptionHandler> formal protocol. 
 * An incoming NOTIFY was received.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresStatusEvent : CPCSipPresenceEvent

@property (nonatomic, readonly) CPCSipPresenceDocument* presence;

@end


/**
 * Event passed in onSubscriptionStateChanged: in the 
 * <CPCSipPresSubscriptionHandler> formal protocol. 
 * The state of the incoming or outgoing subscription has changed.
 * This might happen for any of the following reasons:
 * <ul>
 * <li>The remote party accepted the subscription request
 * <li>The remote party rejected or terminated the subscription
 * <li>The event server is transitioning to an out-of-service state
 * </ul>
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSubStateChangedEvent : CPCSipPresenceEvent

@property (nonatomic, readonly) CPCSipSubscriptionState* state;

@end


/**
 * Event passed in onPresenceDocumentReady: in the 
 * <CPCSipPresSubscriptionHandler> formal protocol.
 * A pre-populated Presence document is ready. Invoked by the SDK
 * after the application calls SipPresenceManager::preparePresence(..)
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresDocumentEvent : CPCSipPresenceEvent

@property (nonatomic, readonly) CPCSipPresenceDocument* document;

@end



/**
 * Event passed in onError: in the <CPCSipPresSubscriptionHandler> formal protocol; 
 * used to report general SDK error conditions, such as invalid handles, or cases 
 * where the subscription is not in a valid state for the requested operation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSubErrorEvent : CPCSipPresenceEvent

@property (nonatomic, readonly) NSString* errorText;

@end



/**
 * Handler for events related to presence subscriptions; 
 * set in addHandler:forAccount: in the SipPresenceManager class.
 */
@protocol CPCSipPresSubscriptionHandler <NSObject>
@optional

- (void)onNewSubscription:(CPCSipPresNewSubscriptionEvent*)event;
- (void)onSubscriptionEnded:(CPCSipPresSubscriptionEndedEvent*)event;
- (void)onIncomingPresenceStatus:(CPCSipPresStatusEvent*)event;
- (void)onSubscriptionStateChanged:(CPCSipPresSubStateChangedEvent*)event;
- (void)onPresenceDocumentReady:(CPCSipPresDocumentEvent*)event;
- (void)onError:(CPCSipPresSubErrorEvent*)event;

@end


