//
//  CPCSipConversationState.h
//  BriaVoip
//
//  Copyright (c) 2013 CounterPath Corporation Inc. All rights reserved.
//

#ifndef BriaVoip_CPCSipConversationState_h
#define BriaVoip_CPCSipConversationState_h

#import <Foundation/Foundation.h>

#import "../CPCConfig.h"
#import "CPCSipConversationTypes.h"
#import "CPCSipConversationHandler.h"

@class CPCSipConversationManager;

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationState : NSObject

@property (nonatomic, readonly) CPCSipAccountHandle account;
@property (nonatomic, readonly) CPCSipConvState conversationState;
@property (nonatomic, readonly) CPCSipConvType conversationType;
@property (nonatomic, readonly) NSString* remoteAddress;
@property (nonatomic, readonly) NSString* remoteDisplayName;
@property (nonatomic, readonly) NSArray* remoteMediaInfo;
@property (nonatomic, readonly) NSArray* localMediaInfo;
@property (nonatomic, readonly) BOOL localHold;
@property (nonatomic, readonly) BOOL remoteHold;
@property (nonatomic, readonly) CPCSipConvEndReason endReason;
@property (nonatomic, readonly) CPCConversationStatistics *statistics;
@property (nonatomic, readonly) CPCJitterBufferStatistics *jitterBufferStatistics;

@end
/**
* Manager class that provides a mechanism for obtaining the 
* SipConversationState class that provides information about a 
* specific conversation; get an instance of the class using the 
* class method getInterface: then call getState: to obtain the state.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationStateManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %SipConversationStateManager interface.
 */
+ (CPCSipConversationStateManager*)getInterface:(CPCSipConversationManager*)manager;

- (NSInteger)getState:(CPCSipConvConversationHandle)conversationHandle outParam:(CPCSipConversationState**)conversationState;


@end


#endif
