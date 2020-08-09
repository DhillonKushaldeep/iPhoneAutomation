//
//  CPCXmppRosterManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppRosterTypes.h"
#import "CPCXmppRosterHandler.h"
#import "CPCXmppAccountHandler.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the CPCXmppRosterManager interface.
 */
+ (CPCXmppRosterManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Create a roster for the specified account and start querying the roster as soon as possible
 */

- (CPCXmppRosterHandle)createRoster:(CPCXmppAccountHandle) account;

/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addHandler:(id<CPCXmppRosterHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (NSInteger)addHandler:(id<CPCXmppRosterHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCXmppRosterHandler>)handler forAccount:(CPCXmppAccountHandle)account;

/**
 * Accept a subscription received through onRosterSubscriptionRequest
 */
- (NSInteger)acceptSubscriptionRequest:(CPCXmppRosterHandle)roster address:(NSString*)address;

/**
 * Reject a subscription received through onRosterSubscriptionRequest
 */
- (NSInteger)rejectSubscriptionRequest:(CPCXmppRosterHandle)roster address:(NSString*)address;

/**
 * Remove contact's subscription for user's presence
 */
- (NSInteger)cancelAcceptedSubscription:(CPCXmppRosterHandle)roster address:(NSString*)address message:(NSString*)message;

/**
 * Add an entry to roster
 */
- (NSInteger)addRosterItem:(CPCXmppRosterHandle)roster address:(NSString*)address displayName:(NSString*)displayName groups:(NSArray*)groups;

/**
 * Update an entry in roster
 */
- (NSInteger)updateRosterItem:(CPCXmppRosterHandle)roster address:(NSString*)address displayName:(NSString*)displayName groups:(NSArray*)groups;

/**
 * Remote an entry from roster
 */
- (NSInteger)removeRosterItem:(CPCXmppRosterHandle)roster address:(NSString*)address;

/**
 * Send request for contact's presence. Compliant servers will auto add contact to roster
 * if contact is not already in roster
 */
- (NSInteger)subscribePresence:(CPCXmppRosterHandle)roster address:(NSString*)address displayName:(NSString*)displayName groups:(NSArray*)groups message:(NSString*)message;

/**
 * Removes presence subscription
 */
- (NSInteger) unsubscribePresence:(CPCXmppRosterHandle)roster address:(NSString*)address;

@end

