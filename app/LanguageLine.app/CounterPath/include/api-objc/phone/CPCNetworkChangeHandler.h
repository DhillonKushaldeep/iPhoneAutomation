//
//  CPCNetworkChangeHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"

typedef NSInteger CPCNetworkChangeManagerHandle;

/**
 * Type of network transport
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCNetworkTransport : CPCEnumType

+ (CPCNetworkTransport*) transportNone;
+ (CPCNetworkTransport*) transportWiFi;
+ (CPCNetworkTransport*) transportWWAN;

@end

/**
 * Do not use this interface; it covers alpha-grade
 * functionality that is not officially supported and is subject to change.
 
 *
 * Event fired by the SDK to signal a network change.
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCNetworkChangeEvent : NSObject

@property (nonatomic, readonly) CPCNetworkTransport *networkTransport;

@end


@protocol CPCNetworkChangeHandler <NSObject>
@optional
- (void) onNetworkChange:(CPCNetworkChangeEvent*)event;

@end
