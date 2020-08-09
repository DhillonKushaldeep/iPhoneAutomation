//
//  CPCNetworkChangeManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCNetworkChangeHandler.h"

/**
 * Do not use this interface; it covers alpha-grade
 * functionality that is not officially supported and is subject to change.
 *
 * Interface for network change related functionality in the SDK.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCNetworkChangeManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %CPCNetworkChangeManager interface.
 *
 * @param cpcPhone the phone object to be associated with this manager.
 */
+ (id) getInterface: (CPCPhone*)phone;

/**
 * Create a new handle needed to install and remove a %CPCNetworkChangeManager.
 */
- (CPCNetworkChangeManagerHandle) create;

/**
 * Set the handler for chat related events on the specified account.
 * Set the handler immediately after getting a reference to this manager.
 *
 * @param account the user account to be associated with the handler.
 * @param handler the handler to register.
 *
 * return kSuccess if the operation was successful, kError otherwise.
 */

- (NSInteger)addHandler:(id<CPCNetworkChangeHandler>)handler forHandle:(CPCNetworkChangeManagerHandle)handle;
- (NSInteger)addHandler:(id<CPCNetworkChangeHandler>)handler forHandle:(CPCNetworkChangeManagerHandle)handle queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCNetworkChangeHandler>)handler forHandle:(CPCNetworkChangeManagerHandle)handle;

/**
 * Returns current network transport
 * @return CPCNetworkTransport.
 */
- (CPCNetworkTransport*)networkTransport;

@end
