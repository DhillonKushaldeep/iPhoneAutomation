//
//  CPCSipEventManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCSipEventHandler.h"

@class CPCPhone;
typedef NSUInteger CPCSipAccountHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventSubscriptionSettings : NSObject
{
	NSString *_eventPackage;
	NSArray  *_eventPackageParams;
	NSInteger  _expiresSeconds;
	NSArray *_supportedMimeTypes;
}

@property (nonatomic, copy)NSString *eventPackage;
@property (nonatomic, copy)NSArray *eventPackageParams; //CPCParameter
@property (nonatomic, readwrite)NSInteger  expiresSeconds;
@property (nonatomic, copy)NSArray *supportedMimeTypes; //CPCMimeType

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipSubscriptionTerminateReason : CPCEnumType

+ (instancetype) noResource;
+ (instancetype) deactivated;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipEventManager : NSObject
@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %SipEventManager interface.
 */
/**
 * Get a reference to the CPCSipPublicationManager interface.
 */
+ (CPCSipEventManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addHandler:(id<SipEventSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType;
- (NSInteger)addHandler:(id<SipEventSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<SipEventSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account DEPRECATED_MSG_ATTRIBUTE("Use removeHandler:forAccount:forEventType instead.");
- (NSInteger)removeHandler:(id<SipEventSubscriptionHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType;

/**
 * Allocates a new subscription within the SDK.  This function is used in concert with addParticipant(..) and start(..)
 * to begin a new outgoing (client) subscription session.
 */
- (CPCSipEventSubscriptionHandle) createSubscription:(CPCSipAccountHandle) account;

/**
 * Sets parameters for an outgoing subscription session.  Invoked immediately after createSubscription(..)
 * Must be invoked prior to calling start(..) so that the event package and other subscription parameters are configured.
 */
- (NSInteger) applySubscriptionSettings:(CPCSipEventSubscriptionHandle) subscription settings:(CPCSipEventSubscriptionSettings*) settings;

/**
 * Adds a participant to the subscription session.  Call this function after createSubscription(..) and before start(..).
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger) addParticipant:(CPCSipEventSubscriptionHandle) subscription targetAddress:(NSString*)targetAddress;

/**
 * Sets the address of the event server responsible for sending event notifications.  For example, this may be
 * the address of a resource list server.  If an event server is set on a subscription, the outgoing SUBSCRIBE
 * is sent to the targetAddress for the event server specified in the targetAddress parameter..
 * Call this function after createSubscription(..) and before start(..).
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger) setEventServer:(CPCSipEventSubscriptionHandle) subscription targetAddress:(NSString*)targetAddress;

/**
 * Initiates an outgoing (client) subscription session by sending a SUBSCRIBE to the remote participant
 * (see addParticipant(..)) or to the event/resource-list server.
 */
- (NSInteger) start:(CPCSipEventSubscriptionHandle) subscription;

/**
 * Ends a subscription session.  Sends an outgoing SUBSCRIBE with Expires == 0.
 * reason can be nil. By default it means noResource
 */
- (NSInteger) end:(CPCSipEventSubscriptionHandle) subscription reason:(CPCSipSubscriptionTerminateReason*) reason;

/**
 * Used after receiving an incoming subscription session to reject the SUBSCRIBE offered by the remote party.
 * @param subscription The incoming subscription session to reject.
 * @param rejectReason The SIP response code sent to the originating party.
 */
- (NSInteger) reject:(CPCSipEventSubscriptionHandle) subscription rejectReason:(NSUInteger) rejectReason;

/**
 * Used to accept an incoming (server) subscription session (200 OK).
 */
- (NSInteger) accept:(CPCSipEventSubscriptionHandle) subscription eventState:(CPCSipEventState*)eventState;

/**
 * Used to put an incoming (server) subscription session to PENDING state (200 OK).
 */
- (NSInteger) provisionalAccept:(CPCSipEventSubscriptionHandle) subscription eventState:(CPCSipEventState*)eventState;

/**
 * Used to send outgoing event state on an incoming (server) subscription session.
 * Sends a NOTIFY request with content as specified by the eventState parameter.
 */
- (NSInteger) notify:(CPCSipEventSubscriptionHandle) subscription  eventState:(CPCSipEventState*)eventState;

@end
