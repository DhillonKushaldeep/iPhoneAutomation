//
//  CPCXmppRosterHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import "CPCXmppRosterTypes.h"
#import "CPCXmppAccountHandler.h"
#import "CPCXmppCannedPresence.h"

typedef NSInteger CPCXmppRosterHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppBaseRosterEvent : NSObject

@property (nonatomic, readonly) CPCXmppAccountHandle account;
@property (nonatomic, readonly) CPCXmppRosterHandle roster;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterUpdateEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)BOOL fullUpdate;
@property (nonatomic, readonly)NSArray *added;   //list of CPCXmppRosterItem
@property (nonatomic, readonly)NSArray *updated; //list of CPCXmppRosterItem
@property (nonatomic, readonly)NSArray *removed; //list of NSString

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterUpdateFailedEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)NSUInteger errorCode;
@property (nonatomic, readonly)NSString *errorText;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterPresenceEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)CPCXmppRosterItem *rosterItem;
@property (nonatomic, readonly)NSString *resource;
@property (nonatomic, readonly)CPCXmppCannedPresence *compositeCannedPresence;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterSubscriptionRequestEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)NSString *address;
@property (nonatomic, readonly)NSString *msg;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterUnsubscriptionRequestEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)NSString *address;
@property (nonatomic, readonly)NSString *msg;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterErrorEvent : CPCXmppBaseRosterEvent

@property (nonatomic, readonly)NSString *errorText;

@end

@protocol CPCXmppRosterHandler <NSObject>

/**
 * Notifies the application when the %XmppRoster has been updated on the server.
 * May result from a local operation, or a change initiated by a remote client logged in with the same credentials.
 */
- (void)onRosterUpdate:(CPCXmppRosterUpdateEvent*)event;

/**
 * Notifies the application when a subscription request was received
 */
- (void)onSubscriptionRequest:(CPCXmppRosterSubscriptionRequestEvent*)event;

/**
 * Notifies the application when an unsubscription request was received
 */
- (void)onUnsubscriptionRequest:(CPCXmppRosterUnsubscriptionRequestEvent*)event;

/**
 * Notifies the application when one or more items in the XmppRoster have updated presence status information available.
 */
- (void)onRosterPresence:(CPCXmppRosterPresenceEvent*)event;

/**
 * Notifies the application when an account error has occurred
 */
- (void)onRosterError:(CPCXmppRosterErrorEvent*)event;

@end

