//
//  CPCSipMWIManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCSipMWIHandler.h"
#import "../account/CPCSipAccountHandler.h"

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWISubscriptionSettings: NSObject
{
	NSUInteger _expiresSeconds;
}
@property(nonatomic) NSUInteger expiresSeconds;

@end


/**
 * Manager interface to subscribe for message waiting indication (MWI)
 * information that is stored on a voicemail server;
 * the interface conforms with RFC 3842; get a reference to the
 * interface using the static method getInterface().
 * Only outgoing message-summary subscriptions are supported.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWIManager : NSObject

@property (nonatomic, assign) void* object;

/**
 * Get a reference to the %CPCSipMWIManager interface.
 */
+ (CPCSipMWIManager*) getInterface:(CPCPhone*)phone;

/**
 * Set the handler for incoming and outgoing instant messages.
 */

- (NSInteger)addHandler:(id<CPCSipMWIHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addHandler:(id<CPCSipMWIHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCSipMWIHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Allocates a new subscription within the SDK.  This function is used in concert with start(..)
 * to begin a new outgoing (client) subscription session.
 * Note that some legacy systems send unsolicited out-of-dialog NOTIFYs for message-summary a short time after initial
 * registration (i.e. after a successful REGISTER/200 OK).  In this case, a call to createSubscription(..) is not
 * required -- event information will nonetheless be reported via the SipMessageWaitingIndicationHandler.
 */
- (CPCSipEventHandle) createSubscription:(CPCSipAccountHandle)account;

/**
 * Sets parameters for an outgoing subscription session.  Invoked immediately after createSubscription(..)
 * Invoked prior to calling start(..) to customize the default subscription parameters @see SIPMWISubscriptionSettings.
 */
- (NSInteger) applySubscriptionSettings:(CPCSipEventHandle)subscription settings:(CPCSipMWISubscriptionSettings*)settings;

/**
 * Initiates an outgoing (client) subscription session by sending a SUBSCRIBE.
 */
- (NSInteger) start:(CPCSipEventHandle)subscription;

/**
 * Ends a subscription session.  Sends an outgoing SUBSCRIBE with Expires == 0.
 */
- (NSInteger) end:(CPCSipEventHandle)subscription;

@end
