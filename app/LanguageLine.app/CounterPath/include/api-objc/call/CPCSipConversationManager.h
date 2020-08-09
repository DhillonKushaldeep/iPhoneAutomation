//
//  CPCSipConversationManager.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CPCSipConversationHandler.h"
#import "../account/CPCSipAccountHandler.h"
#import "CPCSipConversationTypes.h"


@class CPCPhone;


/**
* Manager class to control incoming, outgoing and established phone calls; 
* get an instance of the class using the class method getManager:.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConversationManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %SipConversationManager interface.
 */
+ (id)getManager:(CPCPhone*)phone;


/**
 * add and remove event handlers (observers) for call events on the specified account. 
 * Set the handler at least one observer immediately after creating the account.
 * to remove one handler object for all accounts specify 0 as account handle
 */
- (NSInteger)addHandler:(id<CPCSipConvConversationHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addHandler:(id<CPCSipConvConversationHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCSipConvConversationHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Set default settings which apply to all incoming and outgoing calls on the specified account.
 * Invoked immediately after creating the account.
 */
- (NSInteger)setDefaultSettings:(CPCSipConvSettings*)settings forAccount:(CPCSipAccountHandle)account;



/**
 *
 */
- (NSInteger)setDefaultSettings:(CPCSipConvSettings *)settings forAccount:(CPCSipAccountHandle)account forTransport:(CPCNetworkTransport*)transport;

/**
 * Allocates a new call within the SDK.  This function is used in concert with addParticipant(..) and start(..)
 * to begin a new outgoing call.
 */
- (CPCSipConvConversationHandle)createConversation:(CPCSipAccountHandle)account;


/**
 * Adds a participant to the call.  Call this function after createConversation(..) and before start(..).
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger)addParticipant:(CPCSipConvConversationHandle)conversation targetAddress:(NSString*)targetAddress;


/**
 * Changes the set of media offered by the SDK.  May be called prior to an initial outgoing INVITE (i.e. prior to calling start(..))
 * or may be called on an already established call.
 * Used prior to calling #sendMediaChangeRequest(..) to send a re-INVITE request with a new SDP offer reflecting the
 * enabled/disabled states of the media streams on the call.
 */
- (NSInteger)configureMedia:(CPCSipConvConversationHandle)conversation media:(CPCSipConvMediaInfo*)mediaInfo;


/**
 * Enables or disables a particular media type for the conversation.
 * Note: This is a simple convenience function and has the same effect as manually specifying media
 * information using #configureMedia(..)
 * May be invoked prior to starting the conversation, or after start(..) has already been invoked.
 * Used prior to calling #sendMediaChangeRequest(..) to send a re-INVITE request with a new SDP offer reflecting the
 * enabled/disabled states of the media streams on the call.
 */
- (NSInteger)setMediaEnabled:(CPCSipConvConversationHandle)conversation mediaType:(CPCSipConvMediaType)type enable:(BOOL)enable;


/**
 * Use this function to enable RFC 3323 privacy mechanisms for an outgoing call prior to calling start(..).
 */
- (NSInteger)setAnonymousMode:(CPCSipConvConversationHandle)conversation anonymous:(NSUInteger)mode;

/**
 * When this feature is enabled, it tries to setup a call using RTP/SAVP, if it fails it then tries
 * to setup a call using RTP/AVP. Note that there is no need to configure the media encryption related settings
 * for the call in this case as it is handled automatically.
 */
- (NSInteger) setBestEffortMediaEncryption:(CPCSipConvConversationHandle)conversation enabled:(BOOL)enabled;

/**
 * Initiates an outgoing call by sending an INVITE to the remote participant (see addParticipant(..)).
 */
- (NSInteger)start:(CPCSipConvConversationHandle)conversation;


/**
 * Places the call on hold.  Results in an outgoing re-INVITE request with media attributes
 * set such that remote media is no longer received.  Regardless of the success/failure of the re-INVITE
 * transaction, the SDK will cease sending media from the mic/camera to the remote party.
 */
- (NSInteger)hold:(CPCSipConvConversationHandle)conversation;


/**
 * Takes the call off hold.  See #hold(..).
 */
- (NSInteger)unhold:(CPCSipConvConversationHandle)conversation;


/**
 * Sends a re-INVITE requesting a change in the set of negotiated media streams.
 * For example, can be used to upgrade an audio-only call to audio-video.
 * Call this function after calling #setMedia(..).
 */
- (NSInteger)sendMediaChangeRequest:(CPCSipConvConversationHandle)conversation;


/**
 * Ends a call.  Sends an outgoing BYE or CANCEL request depending on the current conversation state.
 */
- (NSInteger)end:(CPCSipConvConversationHandle)conversation;


/**
 * Redirects an incoming call to a new target address.  Sends a SIP 302 response.
 */
- (NSInteger)redirect:(CPCSipConvConversationHandle)conversation target:(NSString*)target reason:(NSString*)reason;


/**
 * Used after receiving an incoming call to indicate to the remote end that the local user agent is 'ringing'.
 */
- (NSInteger)sendRingingResponse:(CPCSipConvConversationHandle)conversation;


/**
 * Used after receiving an incoming call to reject the INVITE session offered by the remote party.
 * @param conversation The incoming call to reject.
 * @param rejectReason The SIP response code sent to the caller.
 */
- (NSInteger)reject:(CPCSipConvConversationHandle)conversation reasonCode:(NSUInteger)rejectReason;


/**
 * Used to answer an incoming call (200 OK with SDP answer).
 */
- (NSInteger)accept:(CPCSipConvConversationHandle)conversation;


/**
 * Accept an incoming transfer request.  Results in a new outgoing call to the transfer target.
 * See #TransferRequestEvent.
 */
- (NSInteger)acceptIncomingTransferRequest:(CPCSipConvConversationHandle)targetConversation;


/**
 * Reject an incoming transfer request.
 */
- (NSInteger)rejectIncomingTransferRequest:(CPCSipConvConversationHandle)targetConversation;


/**
 * Transfers the call specified as the transfereeConversation to the remote party of the transferTargetConversation.
 * This is a SIP attended transfer.
 * Typically the transferee would be "on hold", and the transferTargetConversation would be "established"
 * prior to calling this function.
 */
- (NSInteger)transfer:(CPCSipConvConversationHandle)transferee targetConversation:(CPCSipConvConversationHandle)targetConversation;


/**
 * Transfers the call specified as the transfereeConversation to the address specified by targetAddress.
 * This is a SIP basic transfer.
 * The format of the targetAddress parameter is sip:username@domain.com
 */
- (NSInteger)transfer:(CPCSipConvConversationHandle)transferee targetAddress:(NSString*)targetAddress;


/**
 * Assigns a preference to the specified DtmfMode, where ordinal 0 is the DtmfMode that will
 * be used first (whenever possible).  Other modes (ordinal 1, 2, ...) will be attempted under
 * the following conditions:
 * RFC 2833:  failure to negotiate the telephone-event codec in SDP
 * In Band:  negotiation of a voice codec such as G.729 which distorts inband DTMF
 * SIP INFO:  reception of an error response after sending a DTMF INFO to the remote target
 *
 * Specify ordinal 0xFFFFFFFF to completely clear the preferred order.
 *
 * @param account SipAccount to apply the DTMF mode preference to.
 * @param ordinal Priority ordering of the DTMF mode relative to other DTMF modes.
 * @param dtmfMode One of the values from the #DtmfMode enumeration.
 */
- (NSInteger)setDtmfMode:(CPCSipAccountHandle)account ordinal:(NSUInteger)ordinal mode:(CPCSipConvDtmfMode)mode;


/**
 * Starts playing a DTMF tone, according to the DTMF mode selected for the SipAccount via #setDtmfMode(..).
 * @param conversation Conversation to play the tone for.  May be 0 if only local playback is desired.
 * @param toneId See http://tools.ietf.org/html/rfc4733#section-3.2 for toneId semantics.
 * @param playLocally YES to play the DTMF tone to the local Audio playout device.
 */
- (NSInteger)startDtmfTone:(CPCSipConvConversationHandle)conversation toneID:(NSUInteger)toneID playLocally:(BOOL)local;


/**
 * Stops playing all DTMF tones.
 */
- (NSInteger)stopDtmfTones;

/**
 * Requests the latest statistics for the conversation. Use while the call is established,
 * or once the call has been terminated.  See SipConversationHandler::onConversationStatisticsUpdated(..)
 * DEPRECATED: Use the version of refreshConversationStatistics that takes the 'includeJitterStatistics' parameter.
 * NOTE: Detailed jitter buffer statistics will NOT be included when using this deprecated version of the function.
 */
- (NSInteger)refreshConversationStatistics:(CPCSipConvConversationHandle)conversation;

/**
 * Requests the latest statistics for the conversation. Use while the call is established,
 * or once the call has been terminated.  See SipConversationHandler::onConversationStatisticsUpdated(..)
 * @param conversation Conversation to get statistics for.
 * @param includeNetworkStatistics True to include network-related statistics (packets received, lost, etc.)
 * @param includeJitterStatistics True to include jitter buffer statistics.
 * @param includeRemoteStatistics True to include the RemoteAudioStatistics and RemoteVideoStatistics data.
 *
 * WARNING: Retrieving conversation statistics is a relatively expensive operation.  It is recommended
 *          that applications only call this function when absolutely necessary.  Also, if the
 *          application is not concerned with detailed jitter buffer statistics, it is recommended
 *          to set the includeJitterStatistics to 'false'.
 */
- (NSInteger)refreshConversationStatistics:(CPCSipConvConversationHandle)conversation includeNetworkStatistics:(BOOL)includeNetworkStatistics includeJitterStatistics:(BOOL)includeJitterStatistics includeRemoteStatistics:(BOOL)includeRemoteStatistics;

/**
 * Set the handler for call events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addAdornmentHandler:(id<CPCSipConversationAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addAdornmentHandler:(id<CPCSipConversationAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeAdornmentHandler:(id<CPCSipConversationAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account;

- (NSInteger)adornMessageHeader:(NSArray*)headers  forEvent:(NSUInteger)adornmentMessageId forConversation:(CPCSipConvConversationHandle)conversation;

/**
 * Plays the specified sound remotely.
 * @param resourceUri specifies the location of the audio data to be played.
	* @param repeat specifies necessary to play sound in loop
 */
- (NSInteger) playSound:(NSString*)resourceUri conversation:(CPCSipConvConversationHandle)conversation repeat:(BOOL)repeat;

/**
 * Stop playing the specified sound.  Note that it is only necessary to call this if you wish to prematurely stop
 * the playing sound, or if you wish to stop playback when playSound was called with 'repeat' set to 'true'.
 */
- (NSInteger) stopPlaySound:(CPCSipConvConversationHandle)conversation;

@end
