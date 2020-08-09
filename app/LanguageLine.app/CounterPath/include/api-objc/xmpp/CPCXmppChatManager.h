//
//  CPCXmppChatManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import "CPCXmppChatHandler.h"
#import "CPCXmppAccountHandler.h"
#import "CPCXmppChatTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the CPCXmppChatManager interface.
 */
+ (CPCXmppChatManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Allocates a chat session within the SDK. This function is
 * used in concert with addParticipant(..) and start(..) to begin a
 * new chat session. Use end..() to later terminate the chat session.
 *
 * @param account the user account of the creator of the
 *                new chat session.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (CPCXmppChatHandle) createChat:(CPCXmppAccountHandle)account;


/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addHandler:(id<CPCXmppChatHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (NSInteger)addHandler:(id<CPCXmppChatHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCXmppChatHandler>)handler forAccount:(CPCXmppAccountHandle)account;

/**
 * Adds a participant to the chat session. Call this
 * function after createChat(..) and before start(..).
 *
 * NOTE: Only the first participant will be used, as only 1-1 chat is
 * supported at the moment. Additional participants will be
 * ignored.
 *
 * @param chat the chat session to add a participant to.
 * @param participantAddress the JID of the participant. The
 *                              format of the targetAddress parameter is
 *                              username@domain.com.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)addParticipant:(CPCXmppChatHandle)chat participantAddress:(NSString*)participantAddress;

/**
 * Initiates a chat session.
 *
 * @param chat The chat session to initiate.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)start:(CPCXmppChatHandle)chat;

/**
 * Ends a chat session.
 *
 * @param chat The chat session to terminate.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)end:(CPCXmppChatHandle)chat;

/**
 * Sends a message to the other party that is part of the chat session.
 *
 * @param chat The chat session to send the message against.
 * @param messageContent the content of message to send.
 *
 * @return the handle of the message being sent.
 */
- (CPCXmppChatMessageHandle)sendMessage:(CPCXmppChatHandle)chat messageContent:(NSString*)messageContent;

/**
 * Used after receiving an incoming chat session to accept the
 * session offered by the remote party.
 *
 * @param chat The incoming chat session to accept.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)accept:(CPCXmppChatHandle)chat;

/**
 * Used after receiving an incoming chat session to reject the
 * session offered by the remote party.
 *
 * @param chat The incoming chat session to reject.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)reject:(CPCXmppChatHandle)chat;

/**
 * Notifies the other participant that the message has been successfully
 * delivered.
 *
 * @param chat the chat session associated with the message delivered.
 * @param message the delivered message.
 * @param messageDeliveryStatus the status of the message delivery.
 *
 * @return the handle of the notification being sent.
 */
- (CPCXmppChatMessageHandle)notifyMessageDelivered:(CPCXmppChatHandle)chat message:(CPCXmppChatMessageHandle)message messageDeliveryStatus:(CPCXmppMessageDeliveryStatus*)messageDeliveryStatus;

/**
 * Notifies the other participant that the message has been successfully
 * displayed.
 *
 * @param chat the chat session associated with the message being composed.
 * @param message the displayed message.
 * @param messageDisplayStatus the status of the message display
 *
 * @return the handle of the notification being sent.
 */
- (CPCXmppChatMessageHandle)notifyMessageDisplayed:(CPCXmppChatHandle)chat message:(CPCXmppChatMessageHandle)message messageDisplayStatus:(CPCXmppMessageDisplayStatus*)messageDisplayStatus;

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
 * @param chat the chat session associated with the message being composed.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)setIsComposingMessage:(CPCXmppChatHandle)chat;

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
 * @param chat the chat session associated with the message being composed.
 * @param refreshInterval the refresh interval to use (in seconds), defaults to 90 seconds.
 * @param idleInterval the idle interval to use (in seconds), defaults to 15 seconds.
 *        Switch to idle state immediately without switching to active state if idleInterval = 0.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger)setIsComposingMessage:(CPCXmppChatHandle)chat refreshInterval:(NSInteger)refreshInterval idleInterval:(NSInteger)idleInterval;

/**
 *
 * The following (synchronous) method is related to the use of XMPP with
 * the RemoteSync module.
 *
 * @param chat the chat session associated with the message being composed.
 * @param message the displayed message.
 *
 */
- (NSString *)getRemoteSyncFromID:(CPCXmppChatHandle)chat message:(CPCXmppChatMessageHandle)message;

/**
 *
 * The following (synchronous) method is related to the use of XMPP with
 * the RemoteSync module.
 *
 * @param chat the chat session associated with the message being composed.
 * @param message the displayed message.
 *
 */
- (NSString *)getRemoteSyncToID:(CPCXmppChatHandle)chat message:(CPCXmppChatMessageHandle)message;

/**
 *
 * The following (synchronous) method is related to the use of XMPP with
 * the RemoteSync module.
 *
 * @param chat the chat session associated with the message being composed.
 
 *
 */
- (NSString *)getRemoteSyncConversationID:(CPCXmppChatHandle)chat;

/**
 *
 * The following (synchronous) method is related to the use of XMPP with
 * the RemoteSync module.
 *
 * @param chat the chat session associated with the message being composed.
 * @param stanzaID.
 *
 */
- (NSString *)getRemoteSyncUniqueID:(CPCXmppChatHandle)chat stanzaID:(NSString *)stanzaID;

/**
 * Returns a text/xml document with both of the messageContent (plaintext)
 * and htmlText (HTML) encoded into the string. Note that it is required to
 * have *at least* a plaintext string. The Content-Type of the resulting
 * RemoteSync string will be text/xml.
 *
 * @param xmppContent contains the plainText and htmlText of XMPP message
 */
- (NSString *)getRemoteSyncEncodedContent:(CPCXmppMessageContent *)xmppContent;

/**
 * Returns the decoded messageContent (plaintext)
 * and htmlText (HTML) encoded from the string.
 *
 * @param encodedContentString is the encoded document of the plainText and htmlText.
 */
- (CPCXmppMessageContent*)getRemoteSyncDecodedContent:(NSString*)encodedContentString;
 

@end


