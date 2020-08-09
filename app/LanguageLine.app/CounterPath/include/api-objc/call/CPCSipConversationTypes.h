//
//  CPCSipConversationTypes.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCSipConversationMediaTypes.h"

typedef NSInteger CPCSipConvMediaType;
typedef NSInteger CPCSipConvMediaDirection;
typedef NSInteger CPCSipConvMediaEncryption;
typedef NSInteger CPCSipConvDtmfMode;
typedef NSInteger CPCSipConvNatTraversalMode;
typedef NSInteger CPCSipConvHoldMode;
typedef NSInteger CPCSipConvPrackMode;
typedef NSInteger CPCNatTraversalServerSourceType;


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvMediaEncryptionOptions : NSObject

+ (CPCSipConvMediaEncryption)mode_unencrypted;
+ (CPCSipConvMediaEncryption)mode_SRTP_SDES_encrypted;
+ (CPCSipConvMediaEncryption)mode_SRTP_DTLS_encrypted;

@property (nonatomic, assign) CPCSipConvMediaEncryption encryptionMode;
@property (nonatomic, assign) BOOL secureMediaRequired;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvMediaInfo : NSObject

+ (CPCSipConvMediaType)type_audio;
+ (CPCSipConvMediaType)type_video;

+ (CPCSipConvMediaDirection)direction_None;
+ (CPCSipConvMediaDirection)direction_SendReceive;
+ (CPCSipConvMediaDirection)direction_SendOnly;
+ (CPCSipConvMediaDirection)direction_ReceiveOnly;
+ (CPCSipConvMediaDirection)direction_Inactive;

@property (nonatomic, assign) CPCSipConvMediaType mediaType;
@property (nonatomic, assign) CPCSipConvMediaDirection mediaDirection;
@property (nonatomic, retain) CPCSipConvMediaEncryptionOptions* mediaEncryptionOptions;
@property (nonatomic, readonly) CPCAudioCodec *audioCodec;
@property (nonatomic, readonly) CPCVideoCodec *videoCodec;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipConvSettings : NSObject

+ (CPCSipConvDtmfMode)dtmfMode_RFC2833;
+ (CPCSipConvDtmfMode)dtmfMode_InBand;
+ (CPCSipConvDtmfMode)dtmfMode_SIP_INFO;
+ (CPCSipConvDtmfMode)dtmfMode_RFC2833_InBand;
+ (CPCSipConvDtmfMode)dtmfMode_RFC2833_SIP_INFO;
+ (CPCSipConvDtmfMode)dtmfMode_InBand_SIP_INFO;
+ (CPCSipConvDtmfMode)dtmfMode_Everything;

+ (CPCSipConvNatTraversalMode)natMode_None;
+ (CPCSipConvNatTraversalMode)natMode_Auto;
+ (CPCSipConvNatTraversalMode)natMode_STUN;
+ (CPCSipConvNatTraversalMode)natMode_TURN;
+ (CPCSipConvNatTraversalMode)natMode_ICE;

+ (CPCSipConvHoldMode)holdMode_RFC3264;
+ (CPCSipConvHoldMode)holdMode_RFC2543;

+ (CPCSipConvPrackMode)prackMode_Disabled;
+ (CPCSipConvPrackMode)prackMode_Supported;
+ (CPCSipConvPrackMode)prackMode_Required;
+ (CPCSipConvPrackMode)prackMode_SupportUasAndUac;

+ (CPCNatTraversalServerSourceType)natSource_None;
+ (CPCNatTraversalServerSourceType)natSource_SRV;
+ (CPCNatTraversalServerSourceType)natSource_Custom;

/**
 * Sets the session name that appears in SDP bodies sent by the SDK.
 */
@property (nonatomic, retain) NSString* sessionName;

/**
 * Sets the NAT traversal mode used for media.
 */
@property (nonatomic, assign) CPCSipConvNatTraversalMode natTraversalMode;

/**
 * The source of the NAT traversal server to use.
 */
@property (nonatomic, assign) CPCNatTraversalServerSourceType natTraversalServerSource;

/**
 * Sets the address of the NAT traversal server (STUN or TURN).
 * By default the SDK will obtain this address from DNS SRV records, however the application can override
 * the value from DNS by specifying a value here, or "server.none.phone.config" to prevent client side media NAT traversal.
 */
@property (nonatomic, retain) NSString* natTraversalServer;

/**
 * Used to specify the TURN username and password
 */
@property (nonatomic, retain) NSString *turnUsername;
@property (nonatomic, retain) NSString *turnPassword;

/**
 * Used to specify the RFC support level for call 'hold' functionality.
 */
@property (nonatomic, assign) CPCSipConvHoldMode holdMode;

/**
 * Used to specify the PRACK support.
 */
@property (nonatomic, assign) CPCSipConvPrackMode prackMode;

/**
 * Used to specify the RTP port range
 */
@property (nonatomic, assign) NSUInteger minRtpPort;
@property (nonatomic, assign) NSUInteger maxRtpPort;

/**
 * Used to specify the audio RTP port range
 */
@property (nonatomic, assign) NSUInteger minRtpPortAudio;
@property (nonatomic, assign) NSUInteger maxRtpPortAudio;

/**
 * Used to specify the video RTP port range
 */
@property (nonatomic, assign) NSUInteger minRtpPortVideo;
@property (nonatomic, assign) NSUInteger maxRtpPortVideo;

/**
 * If true, the P-Asserted-Identity header will be included in 200 OK responses
 */
@property (nonatomic, readwrite) BOOL pAssertedIdentity;

/**
 * If true, the P-Preferred-Identity header will be included in outgoing INVITE requests
 */
@property (nonatomic, readwrite) BOOL pPreferredIdentity;

/**
 * If true, these attribute lines will be included in the SDP:
 *
 * a=rtpmap:9 G722/8000
	* a=rtpmap:8 PCMA/8000
	* a=rtpmap:0 PCMU/8000
 */
@property (nonatomic, readwrite) BOOL includeAttribsForStaticPLs;

@end



/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCConversationStatistics : NSObject

@property(nonatomic, readonly) NSArray *audioChannels;	//CPCAudioStatistics*
@property(nonatomic, readonly) NSArray *remoteAudioChannels;	//CPCRemoteAudioStatistics*
@property(nonatomic, readonly) NSArray *videoChannels;	//CPCVideoStatistics*
@property(nonatomic, readonly) NSArray *remoteVideoChannels;	//CPCRemoteVideoStatistics*

@end


/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCJitterBufferStatistics : NSObject

@property(nonatomic, readonly) NSArray *audioChannels;
@property(nonatomic, readonly) NSArray *videoChannels;

@end
