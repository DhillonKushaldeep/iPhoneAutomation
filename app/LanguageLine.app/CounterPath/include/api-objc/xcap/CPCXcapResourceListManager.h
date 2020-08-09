//
//  CPCXcapResourceListManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#ifndef CPCObjAPI2_CPCXcapResourceListManager_h
#define CPCObjAPI2_CPCXcapResourceListManager_h

//#import "CPCXcapResourceListHandler.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXcapResourceListManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the CPCXcapResourceListManager interface.
 */
+ (CPCXcapResourceListManager*)managerForPhone:(CPCPhone*)phone;


@end

#endif
