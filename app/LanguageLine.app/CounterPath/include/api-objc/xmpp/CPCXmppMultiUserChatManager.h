//
//  CPCXmppMultiUserChatManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppMultiUserChatHandler.h"

#import "../CPCTypes.h"

@class CPCPhone;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMultiUserChatManager : NSObject

/**
 * Get a reference to the %CPCXmppMultiUserChatManager interface.
 */
+ (CPCXmppMultiUserChatManager*) managerForPhone:(CPCPhone*)phone;

/**
 * Set the handler for call events on the specified account. Set the handler
 * immediately after creating the account.
 */

- (NSInteger)addHandler:(id<CPCXmppMultiUserChatHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (NSInteger)addHandler:(id<CPCXmppMultiUserChatHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCXmppMultiUserChatHandler>)handler forAccount:(CPCXmppAccountHandle)account;

#if 0 // bliu: TODO
-(NSInteger) createRoom:(CPCXmppAccountHandle) account room:(NSString*) room password:(NSString*)password  reason:(NSString*)reason;
-(NSInteger) destroyRoom:(CPCXmppAccountHandle) account room:(NSString*)room password:(NSString*)password reason:(NSString*)reason;
#endif

/**
 * Get a list of all multi user chat rooms accessible to this account.
 */
-(NSInteger) getRoomList:(CPCXmppAccountHandle) account;

/**
 * Allocates a new multi user chat within the SDK.  This function is used in concert with other operations e.g. join(...).
 */
-(CPCXmppMultiUserChatHandle) create:(CPCXmppAccountHandle) account;

/**
 * Accept an invitation to a multi user chat.
 * @param historyRequester Four possibilities:
 * 1. since:<number>, number of seconds since 1900-01-01 00:00:00, in UTC only
 * 2. message:<number>, e.g. "message:100" the most recent 100 messages
 * 3. char:<number>, e.g. "char:1000" the max characters of *complete* Xmpp messages
 * 4. seconds<number>, e.g. "seconds:3600" all message within the past 3600 seconds
 */
-(NSInteger) accept:(CPCXmppMultiUserChatHandle) handle
              nickname:(NSString*)nickname
      historyRequester:(NSString*)historyRequester
          historyToAdd:(NSArray*)historyToAdd; //array of CPCXmppMultiUserChatHistoryItem
/**
 * Reject an invitation to a multi user chat.
 */
-(NSInteger) decline:(CPCXmppMultiUserChatHandle) handle reason:(NSString*)reason;

/**
 * Join the multi user chat.
 * @param room A unique name will be created if left as blank.
 * @param historyRequester Four possibilities:
 * 1. since:<number>, number of seconds since 1900-01-01 00:00:00, in UTC only
 * 2. message:<number>, e.g. "message:100" the most recent 100 messages
 * 3. char:<number>, e.g. "char:1000" the max characters of *complete* Xmpp messages
 * 4. seconds<number>, e.g. "seconds:3600" all message within the past 3600 seconds
 */
-(NSInteger) join:(CPCXmppMultiUserChatHandle)handle
            room:(NSString*)room
        nickname:(NSString*)nickname
        password:(NSString*)password
historyRequester:(NSString*)historyRequester
    historyToAdd:(NSArray*)historyToAdd; //array of CPCXmppMultiUserChatHistoryItem

/**
 * Leave the multi user chat; the local user will no longer be a participant.
 */
-(NSInteger) leave:(CPCXmppMultiUserChatHandle) handle reason:(NSString*)reason;

/**
 * Send a plain-text or html message to everyone currently in the multi user chat.
 */
-(CPCXmppMultiUserChatMessageHandle) sendMessage:(CPCXmppMultiUserChatHandle) handle plain:(NSString*)plain html:(NSString*)html;

/**
 * Indicates that a new message is being typed/composed.
 *
 * Notes:
 *
 * 1) It does not necessarily mean that a notification will be sent to the other
 *    participant of the chat session. It depends on the internal state and timers.
 *
 * 2) However, this method must be called often while the participant is actively
 *    typing/composing the message in order to maintain an accurate internal state.
 *
 * @param handle the multi user chat session associated with the message being composed.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
-(NSInteger) setIsComposingMessage:(CPCXmppMultiUserChatHandle) handle;

-(NSInteger) publishPresence:(CPCXmppMultiUserChatHandle) handle presence:(CPCXmppPresenceType*)presence note:(NSString*)note;

/**
 * Change the nickname.
 */
-(NSInteger) changeNickname:(CPCXmppMultiUserChatHandle) handle nickname:(NSString*)nickname;

/**
 * Change the subject of the multi user chat.
 */
-(NSInteger) changeSubject:(CPCXmppMultiUserChatHandle) handle subject:(NSString*)subject;

/**
 * Send an invitation to another person, passing the person's JID and an optional reason.
 */
-(NSInteger) invite:(CPCXmppMultiUserChatHandle) handle jid:(NSString*)jid reason:(NSString*)reason;

/**
 * Kick a participant, passing the person's nickname and an optional reason.
 */
-(NSInteger) kick:(CPCXmppMultiUserChatHandle) handle nickname:(NSString*)nickname reason:(NSString*)reason;

/**
 * Ban a participant, passing the person's nickname and an optional reason.
 */
-(NSInteger) ban:(CPCXmppMultiUserChatHandle) handle  nickname:(NSString*)nickname reason:(NSString*)reason;

/**
 * Change the affiliation of a participant, passing the person's nickname and an optional reason.
 */
-(NSInteger) changeAffiliation:(CPCXmppMultiUserChatHandle)handle
                nickname:(NSString*)nickname
             affiliation:(CPCXmppMultiUserChatAffiliation*)affiliation
                  reason:(NSString*)reason;

/**
 * Change the role of a participant, passing the person's nickname and an optional reason.
 */
-(NSInteger) changeRole:(CPCXmppMultiUserChatHandle)handle
         nickname:(NSString*)nickname
             role:(CPCXmppMultiUserChatRole*)role
           reason:(NSString*)reason;
@end
