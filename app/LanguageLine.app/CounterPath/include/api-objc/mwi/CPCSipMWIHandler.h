//
//  CPCSipMWIHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"
#import "../event/CPCSipEventHandler.h"


typedef NSInteger CPCSipMWIItemType;



/**
* 	A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWIItem : NSObject

/**
 *  Get the type of the message that is waiting.
 */
@property(nonatomic, readonly) CPCSipMWIItemType type;

/**
 *  Get the count of "new messages"; the meaning of "new message"
 *  is defined by the MWI server.
 */
@property(nonatomic, readonly) unsigned long newMessageCount;

/**
 *  Get the count of "old messages"; the meaning of "old message"
 *  is defined by the MWI server.
 */
@property(nonatomic, readonly) unsigned long oldMessageCount;

/**
 *  Get the count of "new urgent messages"; the meaning of "urgent message"
 *  is defined by the MWI server.
 */
@property(nonatomic, readonly) unsigned long newUrgentMessageCount;

/**
 *  Get the count of "old urgent messages"; the meaning of "urgent message"
 *  is defined by the MWI server.
 */
@property(nonatomic, readonly) unsigned long oldUrgentMessageCount;

+ (CPCSipMWIItemType) type_Voice;
+ (CPCSipMWIItemType) type_Fax;
+ (CPCSipMWIItemType) type_Pager;
+ (CPCSipMWIItemType) type_Multimedia;
+ (CPCSipMWIItemType) type_Text;
+ (CPCSipMWIItemType) type_None;

@end

/**
* Abstract parent class; do not instantiate this class directly 
* doing so will throw an exception).
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWISubscriptionEvent : NSObject

@property(nonatomic, readonly) CPCSipEventHandle subscription;
@property(nonatomic, readonly) CPCSipAccountHandle account;

@end


/**
 * Event passed in onNewSubscription: in the <CPCSipMWIHandler> formal protocol.
 * An outgoing SUBSCRIBE has been submitted to the SIP stack for transmission.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipNewMWISubscriptionEvent : CPCSipMWISubscriptionEvent
@end


/**
 * Event passed in onSubscriptionEnded: in the <CPCSipMWIHandler> formal protocol.
 * The client subscription session is terminated (for any reason).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWISubscriptionEndedEvent : CPCSipMWISubscriptionEvent

@property(nonatomic, readonly) CPCSipEventSubscriptionEndReason *endReason;

@end

/**
 * Event passed in onIncomingMWIStatus: in the <CPCSipMWIHandler> formal protocol.
 * An incoming NOTIFY was received.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipIncomingMWIStatusEvent : CPCSipMWISubscriptionEvent

@property(nonatomic, readonly) BOOL hasMessages;
@property(nonatomic, readonly) NSArray *items;
@property(nonatomic, readonly) CPCSipAccountHandle account;

@end

/**
 * Event passed in onSubscriptionStateChanged: in the <CPCSipMWIHandler> formal protocol.
 * The state of the outgoing subscription has changed.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWISubscriptionStateChangedEvent : CPCSipMWISubscriptionEvent

@property(nonatomic, readonly) CPCSipSubscriptionState *subscriptionState;

@end

/**
 * Event passed in onMWISubscriptionError: in the <CPCSipMWIHandler> formal protocol;
 * used to report general SDK error conditions, such as invalid handles, or cases
 * where the call is not in a valid state for the requested operation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipMWISubscriptionErrorEvent : CPCSipMWISubscriptionEvent

@property(nonatomic, readonly) NSString *errorText;

@end

/**
* Handler for events relating to MWI (message waiting indicator) 
* activity; set in addHandler: in the SipMWIManager class.
*/
@protocol CPCSipMWIHandler <NSObject>

- (void) onNewSubscription:(CPCSipNewMWISubscriptionEvent*)event;
- (void) onSubscriptionEnded:(CPCSipMWISubscriptionEndedEvent*)event;
- (void) onIncomingMWIStatus:(CPCSipIncomingMWIStatusEvent*)event;
- (void) onSubscriptionStateChanged:(CPCSipMWISubscriptionStateChangedEvent*)event;
- (void) onMWISubscriptionError:(CPCSipMWISubscriptionErrorEvent*)event;

@end
