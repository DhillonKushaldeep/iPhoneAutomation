//
//  CPCXmppVCardManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppVCardHandler.h"
#import "CPCXmppAccountHandler.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardManager : NSObject
@property (nonatomic, readonly) void* object;
+(id) getInterface:(CPCPhone*)phone;


/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addHandler:(id<CPCXmppVCardHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (NSInteger)addHandler:(id<CPCXmppVCardHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCXmppVCardHandler>)handler forAccount:(CPCXmppAccountHandle)account;


/**
 * Allocates a new vcard within the SDK.
 *
 * @return XmppVCardHandle which is unique within the SDK
 */
-(CPCXmppVCardHandle) create:(CPCXmppAccountHandle) account;

/**
 * Retrieve the vcard of a given JID
 */
-(NSInteger) fetchVCard:(CPCXmppVCardHandle)handle withJid:(NSString*)jid;

/**
 * Update own vcard
 */
-(NSInteger) storeVCard:(CPCXmppVCardHandle) handle withDetails:(CPCXmppVCardDetail*)vcard;

/**
 * Cancel all pending operations (fetch or store)
 */
-(NSInteger) cancelVCardOperations:(CPCXmppVCardHandle) handle;

@end
