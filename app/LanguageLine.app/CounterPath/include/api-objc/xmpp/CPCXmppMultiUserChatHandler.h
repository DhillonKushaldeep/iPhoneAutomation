//
//  CPCXmppMultiUserChatHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppChatTypes.h"
#import "CPCXmppMultiUserChatTypes.h"
#import "CPCXmppAccountHandler.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API  @interface CPCXmppMUCRoomEvent : NSObject
@property(nonatomic, readonly) CPCXmppAccountHandle accountHandle;
@property(nonatomic, readonly) CPCXmppMultiUserChatHandle chatHandle;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCServiceAvailabilityEvent : NSObject
@property(nonatomic, readonly) CPCXmppAccountHandle accountHandle;
@property(nonatomic, readonly) BOOL available;
@property(nonatomic, readonly) NSString *service;
@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCRoomListRetrievedEvent : NSObject
@property(nonatomic, readonly) CPCXmppAccountHandle accountHandle;
@property(nonatomic, readonly) NSArray *rooms; //CPCXmppMUCRoomListItem
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantAddedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *nickname;
@property(nonatomic, readonly) CPCXmppMUCParticipantState *state;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantRemovedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *nickname;
@property(nonatomic, readonly) NSString *jid;
@property(nonatomic, readonly) NSString *reason;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantUpdatedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *nickname;
@property(nonatomic, readonly) NSString *reason;
@property(nonatomic, readonly) CPCXmppMUCParticipantState *state;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantSelfUpdatedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *jid; // maker
@property(nonatomic, readonly) NSString *reason;
@property(nonatomic, readonly) CPCXmppMUCParticipantState *state;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantChatStateEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *jid; // maker
@property(nonatomic, readonly) CPCXmppIsComposingMessageState *state; // The state of the 'isComposing' indicator

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCLocalUserLeftEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *reason;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCReadyEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSInteger features;
@property(nonatomic, readonly) NSString *room;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCConfigurationRequestedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *data;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCSubjectChangedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *nickname; // from
@property(nonatomic, readonly) NSString *subject; // new subject

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCNewMessageEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) CPCXmppMultiUserChatMessageHandle message;
@property(nonatomic, readonly) NSString *nickname; // from
@property(nonatomic, readonly) NSString *messageId;
@property(nonatomic, readonly) NSString *plain;
@property(nonatomic, readonly) NSString *html;
@property(nonatomic, readonly) NSDate *date;
@property(nonatomic, readonly) BOOL isPrivate; // is a private message
@property(nonatomic, readonly) BOOL isDelayedDelivery; // did message contain delayed timestamp

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCSendMessageSuccessEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) CPCXmppMultiUserChatMessageHandle message;
@property(nonatomic, readonly) NSString *messageId; // the message ID

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCSendMessageFailureEvent : CPCXmppMUCRoomEvent
@property(nonatomic, readonly) CPCXmppMultiUserChatMessageHandle message;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCInvitationReceivedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *room;
@property(nonatomic, readonly) NSString *jid; // from
@property(nonatomic, readonly) NSString *reason;
@property(nonatomic, readonly) NSString *password;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCInvitationDeclinedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) NSString *jid; // invitee
@property(nonatomic, readonly) NSString *reason;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCErrorEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) CPCXmppMUCErrorType *type;
@property(nonatomic, readonly) NSString *error;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCRoomStateChangedEvent : CPCXmppMUCRoomEvent

@property(nonatomic, readonly) CPCXmppMultiUserChatRoomState *state;

@end


@protocol CPCXmppMultiUserChatHandler <NSObject>
/**
 * Notifies that the service is available on the server.
 * Query the evt for information.
 * A handler to this event is optional.
 */
- (void) onXmppMUCServiceAvailability:(CPCXmppMUCServiceAvailabilityEvent*)evt;

/**
 * Notifies that a list of rooms has been retrieved from the server.
 */
-(void) onXmppMUCRoomListRetrieved:(CPCXmppMUCRoomListRetrievedEvent*) evt;

/**
 * Notifies that a participant has joined the multi user chat. Doesn't include self joining a room.
 * Expect for onParticipantSelfUpdated as a self event instead.
 * Query the evt for the participant.
 */
-(void) onXmppMUCParticipantAdded:(CPCXmppMUCParticipantAddedEvent*) evt;

/**
 * Notifies that a participant has left the multi user chat or has been kicked out.
 * Query the evt for the participant.
 */
-(void) onXmppMUCParticipantRemoved:(CPCXmppMUCParticipantRemovedEvent*) evt;

/**
 * Notifies that a participant's information has changed. Doesn't include self state changes.
 * Query the evt for the change.
 */
-(void) onXmppMUCParticipantUpdated:(CPCXmppMUCParticipantUpdatedEvent*) evt;

/**
 * Notifies that the local user's information has changed.
 * Query the evt for information.
 */
-(void) onXmppMUCParticipantSelfUpdated:(CPCXmppMUCParticipantSelfUpdatedEvent*) evt;

/**
 * Notifies that the multi user chat is ready to be used; called in response to
 * XmppMultiUserChat::create() (if supportsConfigurationRequest() is false)
 * or in response to XmppMultiUserChat::submitConfigurationDataForm() or
 * MultiUserChatConfigurationRequest::submit() (if %supportsConfigurationRequest()
 * is true).
 */
-(void) onXmppMUCReady:(CPCXmppMUCReadyEvent*) evt;

/**
 * Notifies that the subject of the multi user chat has changed.
 * Query the evt for information.
 */
-(void) onXmppMUCSubjectChanged:(CPCXmppMUCSubjectChangedEvent*) evt;

/**
 * Notifies that a new message has been received.
 * Query the evt for information.
 */
-(void) onXmppMUCNewMessage:(CPCXmppMUCNewMessageEvent*) evt;

/**
 * Callback invoked by the SDK when the sending of a message was successful.
 * Query the evt for information.
 * A handler to this event is optional.
 */

-(void) onXmppMUCSendMessageSuccess:(CPCXmppMUCSendMessageSuccessEvent*) evt;

/**
 * Callback invoked by the SDK when the sending of a message failed.
 * Query the evt for information.
 * A handler to this event is optional.
 */
-(void) onXmppMUCSendMessageFailure:(CPCXmppMUCSendMessageFailureEvent*) evt;

/**
 * Notifies that the local user has received an chat state message ("typing..") as part of the
 * multi user chat; this callback is received only on a multi user chat that is in progress
 * and for which the local user is a participant. Doesn't include self chat state changes.
 * Query the evt for information.
 */
-(void) onXmppMUCParticipantChatStateReceived:(CPCXmppMUCParticipantChatStateEvent*) evt;

/**
 * Notifies that an invitation to the local user has been received.
 * Query the evt for information.
 */
-(void) onXmppMUCInvitationReceived:(CPCXmppMUCInvitationReceivedEvent*) evt;

/**
 * Notifies that an invitation that the local user sent has been declined by the recipient.
 * Query the evt for information.
 */
-(void) onXmppMUCInvitationDeclined:(CPCXmppMUCInvitationDeclinedEvent*) evt;

/**
 * Notifies that an error has occurred for this multi user chat.
 */
-(void) onXmppMUCError:(CPCXmppMUCErrorEvent*) evt;

/**
 * Notifies that the local user has left the multi user chat.
 * (If another participant leaves, onParticipantRemoved() is called.)
 * The evt is informational (contains no content).
 */
-(void) onXmppMUCLocalUserLeft:(CPCXmppMUCLocalUserLeftEvent*) evt;

/**
 * Called on the multi user chat owner when the multi user chat has been created and
 * passes information about the multi user chat; called only if
 * MultiUserChatHandler::supportsConfigurationRequest() is true. Query the evt
 * for the configuration form.
 */
-(void) onXmppMUCConfigurationRequested:(CPCXmppMUCConfigurationRequestedEvent*) evt;

/**
 * Notifies that configuration information about the multi user chat has changed.
 * Query the evt for information.
 */
-(void) onXmppMUCRoomStateChanged:(CPCXmppMUCRoomStateChangedEvent*) evt;
                                        
@end
