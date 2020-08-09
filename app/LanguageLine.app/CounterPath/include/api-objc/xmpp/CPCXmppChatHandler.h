//
//  CPCXmppChatHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import "CPCXmppAccountHandler.h"
#import "CPCXmppChatTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatType : CPCEnumType

+ (instancetype)incoming;
+ (instancetype)outgoing;

@end

/**
 * Possible reasons for a terminated chat session.
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatEndReason : CPCEnumType

+ (instancetype)unknown;
+ (instancetype)userTerminatedLocally;
+ (instancetype)userTerminatedRemotely;
+ (instancetype)rejected;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatBaseEvent : NSObject

@property (nonatomic, readonly) CPCXmppAccountHandle account;
@property (nonatomic, readonly) CPCXmppChatHandle chatHandle;

@end

/**
 * Event fired by the SDK to signal a new chat session.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppNewChatEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatType *chatType;

@end

/**
 * Event fired by the SDK when the other participant of the
 * chat session is composing a new message.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatIsComposingMessageEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppIsComposingMessageState *state; // The state of the 'isComposing' indicator
@end

/*
 * Event fired by the SDK to signal a new message within a chat session.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface  CPCXmppChatNewMessageEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message; // The message
@property (nonatomic, readonly) NSString *messageId;							// The message ID
@property (nonatomic, readonly) NSString *threadId;								// The thread ID
@property (nonatomic, readonly)NSString *from;                    // The originator of the message
@property (nonatomic, readonly)NSString *to;                      // The destination of the message
@property (nonatomic, readonly)NSString *messageContent;          // The content of the message, represented as a byte array
@property (nonatomic, readonly)NSString *htmlText;                // The content of the message in html text, represented as a byte array
@property (nonatomic, readonly)NSString *subject;                 // The subject of the message
@property (nonatomic, readonly)NSDate *date;                 // The timestamp of the message
@property (nonatomic, readonly)BOOL isDelayedDelivery;            // Is date taken from delay delivery extension

@end

/**
 * Event fired by the SDK when a message was successfully
 * delivered to the other participant's device(s).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatMessageDeliveredEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message;                   // The delivered message
@property (nonatomic, readonly)CPCXmppMessageDeliveryStatus *messageDeliveryStatus; // The status of the message delivery
@property (nonatomic, readonly)NSString *from;                             // The originator of the message

@end

/**
 * Event fired by the SDK when message delivery
 * failed to the other participant's device(s).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatMessageDeliveryErrorEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message;                   // The failed message
@property (nonatomic, readonly)CPCXmppMessageDeliveryStatus *messageDeliveryStatus; // The status of the message delivery
@property (nonatomic, readonly)NSString *from;                             // The originator of the message

@end

/**
 * Event fired by the SDK when a message was successfully
 * displayed on the other participant's device(s).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatMessageDisplayedEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message;              // The displayed message
@property (nonatomic, readonly)CPCXmppMessageDisplayStatus *messageDisplayStatus; // The status of the message display
@property (nonatomic, readonly)NSString *from;                             // The originator of the message

@end

/**
 * Event fired by the SDK when a new message was successfully
 * sent.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatSendMessageSuccessEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message; // The new message
@property (nonatomic, readonly) NSString *messageId;         // The message ID
@property (nonatomic, readonly) NSString *threadId;          // The thread ID
@end

/**
 * Event fired by the SDK when a new message failed to send.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatSendMessageFailureEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle message; // The new message

@end

/**
 * Event fired by the SDK when a message delivered notification
 * was successfully sent.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatNotifyMessageDeliveredSuccessEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly) CPCXmppChatMessageHandle notification; // The notification
@property (nonatomic, readonly) CPCXmppChatMessageHandle message;      // The delivered message

@end

/**
 * Event fired by the SDK when a message displayed notification
 * was successfully sent.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatNotifyMessageDisplayedSuccessEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)CPCXmppChatMessageHandle notification; // The notification
@property (nonatomic, readonly)CPCXmppChatMessageHandle message;      // The displayed message

@end

/**
 * Event fired by the SDK to signal the termination of a chat session.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatEndedEvent : CPCXmppChatBaseEvent

@property (nonatomic, assign)CPCXmppChatEndReason *endReason; // Reason for the termination of a chat session

@end
/**
 * Used to report general SDK error conditions, such as invalid handles, or cases
 * where the transfer is not in a valid state for the requested operation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppChatErrorEvent : CPCXmppChatBaseEvent

@property (nonatomic, readonly)NSString *errorText;

@end

@protocol CPCXmppChatHandler <NSObject>


   /**
    * Callback invoked by the SDK when a new chat session is established.
    *
    * @param chat the chat session that was established.
    * @param args information about the new chat session.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
-(void)onNewXmppChat:(CPCXmppNewChatEvent*)event;
   /**
    * Callback invoked by the SDK when the other participant is composing a new message.
    *
    * @param chat the chat session associated with the message being composed.
    * @param args information about the message being composed.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onIsComposingXmppMessage:(CPCXmppChatIsComposingMessageEvent*)event;
   
   /**
    * Callback invoked by the SDK when a new message is received within a chat session.
    *
    * @param chat the chat session with which the message is associated.
    * @param args information about the new message.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onNewXmppMessage:(CPCXmppChatNewMessageEvent*)event;
   
   /**
    * Callback invoked by the SDK when the sending of a message was successful.
    *
    * @param chat the chat session with which the message is associated.
    * @param args information about the success.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onSendXmppMessageSuccess:(CPCXmppChatSendMessageSuccessEvent*)event;

   /**
    * Callback invoked by the SDK when the sending of a message failed.
    *
    * @param chat the chat session with which the message is associated.
    * @param args information about the failure.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onSendXmppMessageFailure:(CPCXmppChatSendMessageFailureEvent*)event;
   
   /**
    * Callback invoked by the SDK when the message was successfully delivered
    * to the other participant's device(s).
    *
    * @param chat the chat session that the new message was sent against.
    * @param args information about the message delivered.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onXmppMessageDelivered:(CPCXmppChatMessageDeliveredEvent*)event;

   /**
    * Callback invoked by the SDK when the message delivery failed
    * to the other participant's device(s).
    *
    * @param chat the chat session that the new message was sent against.
    * @param args information about the message delivered.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onXmppMessageDeliveryError:(CPCXmppChatMessageDeliveryErrorEvent*)event;

   /**
    * Callback invoked by the SDK when the message was successfully displayed
    * on the other pariticpant's device(s).
    *
    * @param chat the chat session that the new message was sent against.
    * @param args information about the message displayed.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onXmppMessageDisplayed:(CPCXmppChatMessageDisplayedEvent*)event;

   /**
    * Callback invoked by the SDK when a chat session was terminated.
    *
    * @param chat the chat session that was terminated.
    * @param args information about the terminated chat session.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onXmppChatEnded:(CPCXmppChatEndedEvent*)event;
   
   /**
    * Invoked by the SDK for errors which do not fall into the categories outlined above.
    *
    * @param chat the chat session the error occured against.
    * @param args information about the error.
    *
    * return kSuccess if the operation was successful, kError otherwise.
    */
- (void)onXmppChatError:(CPCXmppChatErrorEvent*)event;

@end


