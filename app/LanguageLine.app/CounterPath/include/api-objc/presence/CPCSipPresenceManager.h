//
//  CPCSipPresenceManager.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"


@class CPCSipPresenceDocument, CPCSipPresenceStatus;



/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSubscriptionSettings : NSObject

@property (nonatomic, assign) NSInteger expiresSeconds;  // defaults to 3600
@property (nonatomic, copy) NSArray *retryWithTheseResponseCodesOnly;
@property (nonatomic, assign) NSInteger minTimeBeforeResubscribeInSeconds;
@property (nonatomic, assign) NSInteger maxTimeBeforeResubscribeInSeconds;

+ (CPCSipPresSubscriptionSettings*)defaultSettings;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPublicationSettings : NSObject
{
	NSUInteger _expiresSeconds;
}

@property (nonatomic, assign) NSUInteger expiresSeconds;

@end


/** Manager class to create and manage presence subscriptions and to publish 
* the local user's presence via SIP SIMPLE; get an instance of the class 
* using the class method getManager:
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresenceManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %CPCSipPresenceManager interface.
 */
+ (id)getManager:(CPCPhone*)phone;


/**
 * add and remove event handlers (observers) for call events on the specified account.
 * Set the handler at least one observer immediately after creating the account.
 * to remove one handler object for all accounts specify 0 as account handle
 */
- (NSInteger)addHandler:(id<CPCSipPresSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addHandler:(id<CPCSipPresSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCSipPresSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Set the handler for presence publication events on the specified account.
 * Set the handler immediately after creating the account.
 */
- (NSInteger)addPublicationHandler:(id<CPCSipPresencePublicationHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addPublicationHandler:(id<CPCSipPresencePublicationHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removePublicationHandler:(id<CPCSipPresencePublicationHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Allocates a new publication within the SDK.  This function is used in concert with publish(..)
 * to send presence PUBLISH requests to a Presence UA server
 */
- (CPCSipPresencePublicationHandle) createPublication:(CPCSipAccountHandle)account settings:(CPCSipPresPublicationSettings*)settings;

/**
 * Used to send Presence state on to a subscription agent server
 * Sends a PUBLISH request with content as specified by the presenceState parameter.
 */
- (NSInteger) publish:(CPCSipPresencePublicationHandle)publication document:(CPCSipPresenceDocument*)document;

/**
 * Allocates a new subscription within the SDK.  This function is used in concert with addParticipant(..) and start(..)
 * to begin a new outgoing (client) subscription session.
 */
- (CPCSipPresenceHandle)createSubscription:(CPCSipAccountHandle)account;

/**
 * Sets parameters for an outgoing subscription session.  Invoked immediately after #createSubscription(..)
 * Use this function if the default values in SipPresenceSubscriptionSettings are not suitable for your application.
 */
- (NSInteger)applySubscriptionSettings:(CPCSipPresenceHandle)subscription settings:(CPCSipPresSubscriptionSettings*)settings;

/**
 * Adds a participant to the subscription session.  Call this function after createSubscription(..) and before start(..).
 * Note: To add multiple participants to a subscription session, use this function in concert with the setEventServer(..) function.
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger)addParticipant:(CPCSipPresenceHandle)subscription targetAddress:(NSString *)targetAddress;

/**
 * Sets the address of the event server responsible for sending event notifications.  For example, this may be
 * the address of a resource list server.  If an event server is set on a subscription, the outgoing SUBSCRIBE
 * is sent to the targetAddress for the event server specified in the targetAddress parameter and the URIs in
 * the resource list are taken from the list of URIs passed with the addParticipant(..) function.
 * Call this function after createSubscription(..) and before start(..).
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger)setEventServer:(CPCSipPresenceHandle)subscription targetAddress:(NSString*)targetAddress;

/**
 * Initiates an outgoing (client) subscription session by sending a SUBSCRIBE to the remote participant
 * (see addParticipant(..)) or to the event/resource-list server.
 */
- (NSInteger)start:(CPCSipPresenceHandle)subscription;

/**
 * Ends a subscription session.  Sends an outgoing SUBSCRIBE with Expires == 0.
 */
- (NSInteger)end:(CPCSipPresenceHandle)subscription;

/**
 * Refreshes a subscription session. Sends an outgoing SUBSCRIBE.
 */
- (NSInteger) refresh:(CPCSipPresenceHandle)subscription;

/**
 * Used after receiving an incoming subscription session to reject the SUBSCRIBE offered by the remote party.
 * @param subscription The incoming subscription session to reject.
 * @param rejectReason The SIP response code sent to the originating party.
 */
- (NSInteger)reject:(CPCSipPresenceHandle)subscription rejectReason:(NSInteger)reason;   // generally use 486 busy here

/**
 * Used to accept an incoming (server) subscription session (200 OK).
 */
- (NSInteger)accept:(CPCSipPresenceHandle)subscription presenceState:(CPCSipPresenceDocument*)state;

/**
 * Used to send outgoing event state on an incoming (server) subscription session.
 * Sends a NOTIFY request with content as specified by the presenceState parameter.
 */
- (NSInteger)notify:(CPCSipPresenceHandle)subscription presenceState:(CPCSipPresenceDocument*)state;


/**
 * Prepares a pre-populated Presence document, customized for the specified subscription,
 * and including status information corresponding to the specified presenceStatus.
 * This is a convenience function, which enables applications to quickly generate a Presence document
 * prior to submitting it to the remote party via the #notify(..) function.
 * The prepared Presence document is returned via the #SipPresenceSubscriptionHandler::onPresenceReadyToSend(..)
 * callback function.
 */
- (NSInteger)preparePresence:(CPCSipPresenceHandle)subscription  status:(CPCSipPresenceStatus*)status;

@end
