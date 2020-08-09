//
//  CPCSipConversationHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../account/CPCSipAccount.h"

typedef NSUInteger CPCSipConvConversationHandle;

typedef NSInteger CPCSipConvState;
typedef NSInteger CPCSipConvEndReason;
typedef NSInteger CPCSipConvType;
typedef NSInteger CPCSipConvTransferProgressEventType;



/**
 * Static class to get access to the constants used for the SIP conversation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversation : NSObject

+ (CPCSipConvState)state_None;
+ (CPCSipConvState)state_LocalOriginated;
+ (CPCSipConvState)state_RemoteOriginated;
+ (CPCSipConvState)state_RemoteRinging;
+ (CPCSipConvState)state_LocalRinging;
+ (CPCSipConvState)state_Connected;
+ (CPCSipConvState)state_Early;
+ (CPCSipConvState)state_Ended;


+ (CPCSipConvEndReason)endReason_Unknown;
+ (CPCSipConvEndReason)endReason_UserTerminatedLocally;
+ (CPCSipConvEndReason)endReason_UserTerminatedRemotely;
+ (CPCSipConvEndReason)endReason_ServerError;
+ (CPCSipConvEndReason)endReason_ServerRejected;
+ (CPCSipConvEndReason)endReason_Redirected;


+ (CPCSipConvType)type_Incoming;
+ (CPCSipConvType)type_Outgoing;
+ (CPCSipConvType)type_IncomingJoinRequest;
+ (CPCSipConvType)type_IncomingTransferRequest;


@end


/**
* Abstract parent class; do not instantiate this class directly 
* (doing so will throw an exception)
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvMediaCorrelator : NSObject

@property (nonatomic, assign) CPCSipConvMediaType mediaType;
@property (nonatomic, assign) CPCSipConvMediaDirection mediaDirection;

@end

/**
* Abstract parent class; do not instantiate this class directly 
* (doing so will throw an exception)
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationEvent : NSObject

@property (nonatomic, readonly) CPCSipConvConversationHandle conversation;
@property (nonatomic, readonly) CPCSipAccountHandle account;

@end

/**
 * Event passed in onNewConversation: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * An outgoing INVITE has been submitted to the SIP stack for transmission, OR
 * an outgoing INVITE has forked, OR
 * an incoming INVITE has been received.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvNewConversationEvent : CPCSipConversationEvent

@property (nonatomic, readonly) CPCSipConvState conversationState;
@property (nonatomic, readonly) CPCSipConvType conversationType;
@property (nonatomic, readonly) NSString* localAddress;
@property (nonatomic, readonly) NSString* localDisplayName;
@property (nonatomic, readonly) NSString* remoteAddress;
@property (nonatomic, readonly) NSString* remoteDisplayName;
@property (nonatomic, readonly) NSArray* localMediaInfo;  // array with CPCSipConvMediaInfo objects
@property (nonatomic, readonly) NSArray* remoteMediaInfo;  // array with CPCSipConvMediaInfo objects
@property (nonatomic, readonly) CPCSipConvConversationHandle relatedConversation; // forked conversation original handle
@property (nonatomic, readonly) CPCSipConvConversationHandle conversationToReplace;
@property (nonatomic, readonly) CPCSipConvConversationHandle conversationToJoin;
@property (nonatomic, readonly) BOOL autoAnswer;
@property (nonatomic, readonly) BOOL isCodecsMismatched;
@property (nonatomic, readonly) NSString* alterInfoHeader;

@end



/**
 * Event passed in onConversationEnded: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * The INVITE session is terminated (for any reason).
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvConversationEndedEvent : CPCSipConversationEvent

@property (nonatomic, readonly) CPCSipConvState conversationState;
@property (nonatomic, readonly) CPCSipConvEndReason endReason;
@property (nonatomic, readonly) NSUInteger sipResponseCode;
@property (nonatomic, readonly) NSString* signallingEndEvent; // e.g. BYE, INVITE/487
@property (nonatomic, readonly) NSString* signallingEndReason; // fromSIP Reason header
@property (nonatomic, readonly) NSString* callQualityReport; // an RFC6035 SIP Voice Quality Session Report. Only availabe if Voice Quality Monitoring is enabled in your SDK

@end



/**
 * Event passed in onIncomingTransferRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * Incoming REFER (RFC 3515). See RFC 5589 for descriptions of the call flows
 * relating to this event.  Currently the SDK supports transfer with dialog reuse (section 6.2),
 * with attended and basic transfer variants.
 *
 * Use the SipConversationManager::acceptIncomingTransferRequest() and
 * SipConversationManager::rejectIncomingTransferRequest() functions to handle this event.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvTransferRequestEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSString* transferTargetAddress;
@property (nonatomic, readonly) NSString* transferTargetDisplayName;
@property (nonatomic, readonly) CPCSipConvConversationHandle transferTargetConversation;

@end


/**
 * Provides status updates once an attended transfer is initiated.
 * Taken from the NOTIFY w/Event: refer requests issued by the transferee.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvTransferProgressEvent : CPCSipConversationEvent

+ (CPCSipConvTransferProgressEventType)type_Trying;
+ (CPCSipConvTransferProgressEventType)type_Ringing;
+ (CPCSipConvTransferProgressEventType)type_Connected;
+ (CPCSipConvTransferProgressEventType)type_Redirected;
+ (CPCSipConvTransferProgressEventType)type_Failed;

@property (nonatomic, readonly) CPCSipConvTransferProgressEventType type;
@property (nonatomic, readonly) NSUInteger sipResponseCode;

@end


/**
 * Event passed in onIncomingRedirectRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * Incoming SIP 302 response received as a result of an outgoing INVITE.
 * Provides the SIP address of the party that the call is being redirected to. The SIP
 * address is in the format <protocol>:<AOR>, for example, sip:kpereira@domainA.com.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvRedirectRequestEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSString* targetAddress;

@end


/**
 * Event passed in onIncomingTargetChangeRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * Incoming Re-INVITE with new Contact.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvTargetChangeRequestEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSString* targetAddress;

@end


/**
 * Event passed in onIncomingHangupRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * Incoming REFER (Refer-To: BYE).  Used in 3PCC call flows when
 * the controlling endpoint requests the controlled endpoint to hang up.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvHangupRequestEvent : CPCSipConversationEvent

@end


/**
 * Do not use this class; it covers unreleased, 
 * unsupported functionality that is subject to change. 
 * Incoming Broadsoft 'talk' event
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvBroadsoftTalkEvent : CPCSipConversationEvent

@end


/**
 * Do not use this class; it covers unreleased, 
 * unsupported functionality that is subject to change. 
 * Incoming Broadsoft 'hold' event
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvBroadsoftHoldEvent : CPCSipConversationEvent

@end


/**
 * Event passed in onConversationStateChangeRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol; this event 
 * indicates the remote end sent a request or response that involves 
 * SIP functionality that the SDK does not support.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvStateChangeRequestEvent : CPCSipConversationEvent

@end


/**
 * Event passed in onConversationStateChanged: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * The conversation state changed as a result of a local or remote action.
 * See #ConversationState for a list of possible states.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvStateChangedEvent : CPCSipConversationEvent

@property (nonatomic, readonly) CPCSipConvState conversationState;
@property (nonatomic, readonly) CPCDialogId *dialogId;
@property (nonatomic, readonly) NSString *contactHeaderField;
@property (nonatomic, readonly) NSString *remoteAddress;
@property (nonatomic, readonly) NSString *remoteDisplayName;
@property (nonatomic, readonly) NSString *alertInfoHeader;

@end


/**
 * Event passed in onConversationMediaChangeRequest: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * The remote UA wishes to change the set of media and/or directions of media,
 * or requires the local UA to send a media offer.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvMediaChangeRequestEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSArray* remoteMediaInfo; // an array of CPCSipConvMediaCorrelators

@end


/**
 * Event passed in onConversationMediaChanged: in the 
 * <CPCSipConvConversationHandler> formal protocol. 
 * Gives the updated local media state after a successful or unsuccessful offer/answer exchange.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvMediaChangedEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSArray* localMediaInfo; // array of CPCSipConvMediaCorrelators
@property (nonatomic, readonly) NSArray* remoteMediaInfo; // array of CPCSipConvMediaCorrelators
@property (nonatomic, readonly) BOOL localHold;
@property (nonatomic, readonly) BOOL remotelHold;

@end


/**
 * Event passed in onError: in the <CPCSipConvConversationHandler>, 
 * used to report general SDK error conditions, such as invalid handles, 
 * or to report cases where the call is not in a valid state for the requested operation.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvErrorEvent : CPCSipConversationEvent

@property (nonatomic, readonly) NSString* errorText;

@end


/**
 * Event passed in onConversationStatisticsUpdated: 
 * in the <CPCSipConvConversationHandler> formal protocol.
 * Holds updated conversation statistics after refreshConversationStatistics() is called.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationStatisticsUpdatedEvent : CPCSipConversationEvent

@property (nonatomic, readonly) CPCConversationStatistics *conversationStatistics;
@property (nonatomic, readonly) CPCJitterBufferStatistics *jitterBufferStatistics;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationAdornmentEvent : CPCSipConversationEvent

@property (nonatomic,readonly) NSUInteger adornmentMessageId;
@property (nonatomic,readonly) NSString *target;
@property (nonatomic,readonly) NSString *method;
@property (nonatomic,readonly) NSUInteger responseCode;
@property (nonatomic,readonly) NSString *message;

@end


@protocol CPCSipConversationAdornmentHandler <NSObject>
@optional

- (void)onConversationAdornment:(CPCSipConversationAdornmentEvent*) event;

@end

/**
 * Handler for events relating to incoming, outgoing, and established phone 
 * calls; set in setHandler:forAccount: in the SipConversationManager class.
 */
@protocol CPCSipConvConversationHandler <NSObject>
@optional

- (void)onNewConversation:(CPCSipConvNewConversationEvent*)event;
- (void)onConversationEnded:(CPCSipConvConversationEndedEvent*)event;

- (void)onIncomingTransferRequest:(CPCSipConvTransferRequestEvent*)event;
- (void)onIncomingRedirectRequest:(CPCSipConvRedirectRequestEvent*)event;
- (void)onIncomingTargetChangeRequest:(CPCSipConvTargetChangeRequestEvent*)event;
- (void)onIncomingHangupRequest:(CPCSipConvHangupRequestEvent*)event;
- (void)onIncomingBroadsoftTalkRequest:(CPCSipConvBroadsoftTalkEvent*)event;
- (void)onIncomingBroadsoftHoldRequest:(CPCSipConvBroadsoftHoldEvent*)event;

- (void)onTransferProgress:(CPCSipConvTransferProgressEvent*)event;

- (void)onConversationStateChangeRequest:(CPCSipConvStateChangeRequestEvent*)event;
- (void)onConversationStateChanged:(CPCSipConvStateChangedEvent*)event;

- (void)onConversationMediaChangeRequest:(CPCSipConvMediaChangeRequestEvent*)event;
- (void)onConversationMediaChanged:(CPCSipConvMediaChangedEvent*)event;

- (void)onConversationStatisticsUpdated:(CPCSipConversationStatisticsUpdatedEvent*)event;

- (void)onError:(CPCSipConvErrorEvent*)event;


@end









