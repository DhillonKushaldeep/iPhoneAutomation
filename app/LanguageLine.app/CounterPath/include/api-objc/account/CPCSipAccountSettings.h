//
//  CPCAccountSettings.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCTypes.h"

typedef NSUInteger CPCSipAccountTransportType;
typedef NSUInteger CPCSipAccountSessionTimerMode;
typedef NSUInteger CPCStunServerSourceType;
typedef NSUInteger CPCSipAccountIpVersion;

@interface CPCTunnelType : CPCEnumType
+ (instancetype) TSCF;
+ (instancetype) unknown;
@end

@interface CPCTunnelConfig : NSObject
{
	BOOL _useTunnel;
	CPCTunnelType *_tunnelType;
	NSString *_server;
	CPCSipAccountTransportType _transportType;
	NSUInteger _redundancyFactor;
	BOOL _doLoadBalancing;
}

@property(nonatomic, assign) BOOL useTunnel;
@property(nonatomic, retain) CPCTunnelType *tunnelType;
@property(nonatomic, retain) NSString *server;
@property(nonatomic, assign) CPCSipAccountTransportType transportType;
@property(nonatomic, assign) NSUInteger redundancyFactor;
@property(nonatomic, assign) BOOL doLoadBalancing;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipAccountSettings : NSObject
{
   @private
   NSString* _username;
   NSString* _domain;
   NSString* _password;
   NSString* _displayname;
   NSString* _authname;
   BOOL _register;
   NSString* _outboundProxy;
   NSUInteger _regiserInterval;
   NSUInteger _minRegInterval;
   BOOL _rport;
   CPCSipAccountTransportType _transport;
   BOOL _excludeEncryptedTransports;
   NSString* _userAgent;
   NSUInteger _udpKeepAliveTime;
   NSUInteger _tcpKeepAliveTime;
   BOOL _useOutbound;
   BOOL _useGruu;
   BOOL _useInstanceId;
   NSString* _otherNonEscapedCharsInUri;
   NSArray *_nameServers;
   CPCSipAccountSessionTimerMode _sessionTimerMode;
   NSUInteger _sessionTimeSeconds;
   CPCStunServerSourceType _stunServerSource;
   NSString *_stunServer;
   BOOL _ignoreCertVerification;
   NSString *_authRealm;
   BOOL _alwaysRouteViaOutboundProxy;
   BOOL _useImsAuthHeader;
   NSUInteger _sipQosSettings;
   NSInteger _minSipPort;
   NSInteger _maxSipPort;
   CPCSipAccountIpVersion _ipVersion;
   NSArray *_reRegisterOnResponseTypes;
   BOOL _enableRegeventDeregistration;
   NSString *_xcapRoot;
   BOOL _usePushNotifications;
   NSArray *_capabilities;
   CPCTunnelConfig *_tunnelConfig;
   NSString *_sourceAddress;
   BOOL _autoRetryOnTransportDisconnect;
}

/**
 * The user portion of the SIP identity for this account,
 * for example, the "kperera" portion of "kperera@zippy-phone.com"
 */
@property (nonatomic, copy) NSString* username;

/**
 * The  host portion of the SIP identity for this account,
 * for example, the "zippy-phone.com" portion of "kperera@zippy-phone.com"
 */
@property (nonatomic, copy) NSString* domain;

/**
 * The password for this account at the SIP registrar.
 */
@property (nonatomic, copy) NSString* password;

/**
 * Any display name for this account; used in SIP From headers.
 */
@property (nonatomic, copy) NSString* displayName;

/**
 * The authorization name, if required for this account by the SIP registrar.
 */
@property (nonatomic, copy) NSString* authname;

/**
 * The authorization realm, if required for this account by the SIP registrar.
 * If not specified, domain is used.
 */
@property (nonatomic, copy) NSString* authRealm;

/**
 * YES to send a SIP REGISTER request to the proxy/registrar.
 */
@property (nonatomic, assign) BOOL useRegistrar;

/**
 * The fully qualified host name or IP
 * address of the outbound proxy. These formats are allowed:
 * <ul>
 * <li> abc.com - uses DNS SRV to resolve the _sip services at abc.com
 * <li> sip.abc.com (fully qualified) ñ uses DNS A/AAAA to resolve the
 * address of the proxy/registrar
 * <li> 192.168.0.100:5060 ñ DNS is not used to resolve the address of
 * the proxy/registrar
 * </ul>
 */
@property (nonatomic, copy) NSString* outboundProxy;

/**
 * True to send all outgoing requests/reponses via the outbound proxy
 * specified in outboundProxy.
 * Note that this should only be used for interoperability with broken
 * or incorrectly configured implementations, since it will break
 * compliance with RFC-3261 mid-dialog/target refresh request handling.
 */
@property (nonatomic, assign) BOOL alwaysRouteViaOutboundProxy;

/**
 * The time interval between the applicationís
 * attempts to reregister in order to refresh the account registration. A value
 * of 0 means not to reregister after the initial registration. This value
 * is placed in the ìExpiresî header field of the register message.
 */
@property (nonatomic, assign) NSUInteger registrationIntervalInSeconds;

/**
 * If the reregistration fails, the application will wait this amount of time,
 * then attempt to reregister. If the second attempt fails, the application
 * will wait twice this time and try again, then four times this time, and so on,
 * until reregistration succeeds.
 */
@property (nonatomic, assign) NSUInteger minimumRegistrationIntervalInSeconds;

/**
 * Set to YES if your proxy is able to support rport (RFC 3581). A value of true instructs
 * the application to include the rport parameter in the REGISTER request,
 * with the expectation that your proxy will provide the appropriate rport
 * value in the 200 OK. When rport is true, the local SDK will attempt SIP NAT
 * traversal by leveraging the rport and received parameters; if the
 * rport/received parameters do not match the values in the
 * Contact header, the account will un-REGISTER and re-REGISTER with
 * an updated Contact header, reflecting the discovered values.
 * Set to false if your proxy cannot support rport.
 */
@property (nonatomic, assign) BOOL useRport;

/**
 * The transport to use for signaling; enter one of the values from CPCSipAccountTransportType.
 */
@property (nonatomic, assign) CPCSipAccountTransportType transportType;

/**
 * Exclude encrypted transports when sipTransportType == SipAccountTransport_Auto.
 */
@property (nonatomic, assign) BOOL excludeEncryptedTransports;

/**
 * The name to put in the user agent in the SIP User-Agent header of outgoing traffic.
 */
@property (nonatomic, copy) NSString* userAgent;

/**
 * True to enable SIP Outbound support (RFC 5626)
 */
@property (nonatomic, assign) BOOL useOutbound;

/**
 * True to enable GRUU support
 */
@property (nonatomic, assign) BOOL useGruu;

/**
 * True to use +sip.instance feature tag
 */
@property (nonatomic, assign) BOOL useInstanceId;

/**
 * Time between CR/LF keepalive messages in seconds.  Set to 0 to disable.
 */
@property (nonatomic, assign) NSUInteger udpKeepAliveTime;
@property (nonatomic, assign) NSUInteger tcpKeepAliveTime;

/**
 * Allow to add other non-escaped chars to the existing set. Applicable to Uri only.
 * Current non-escaped char set is:
 *  "abcdefghijklmnopqrstuvwxyz"
 *  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
 *  "0123456789"
 *  "-_.!~*\\()&=+$,;?/"
 */
@property (nonatomic, copy) NSString* otherNonEscapedCharsInUri;

/**
 * List of name servers to be used
 */
@property (nonatomic, copy) NSArray *nameServers;

/**
 * Session timer mode; enter one of the values from SipAccountSessionTimerMode.
 */
@property (nonatomic, assign) CPCSipAccountSessionTimerMode sessionTimerMode;

/**
 * Session timer value in seconds.
 */
@property (nonatomic, assign) NSUInteger sessionTimeSeconds;

/**
 * The source of the STUN server to use.
 */
@property (nonatomic, assign) CPCStunServerSourceType stunServerSource;

/**
 * STUN server host address[:port]. Only used when stunServerSource == StunServerSource_Custom.
 */
@property (nonatomic, copy) NSString *stunServer;

/**
 * Ignore certificate verification.
 */
@property (nonatomic, assign) BOOL ignoreCertVerification;

/**
 * QoS for SIP traffic.
 */
@property (nonatomic, assign) NSUInteger sipQosSettings;

/**
 * True to include an Authorization header in initial outgoing requests.
 */
@property (nonatomic, assign) BOOL useImsAuthHeader;

/**
 * Minimal value for SIP port
 */
@property (nonatomic, assign) NSInteger minSipPort;

/**
 * Maximal value for SIP port
 */
@property (nonatomic, assign) NSInteger maxSipPort;

/**
 * SIP transport IP version (IPv4 or IPv6 or both)
 */
@property (nonatomic, assign) CPCSipAccountIpVersion ipVersion;

/**
 * Re-register when any of the response types specified here are
 * received (CPCSipResponseType).
 */
@property(nonatomic, copy) NSArray *reRegisterOnResponseTypes;

/**
 * True to automatically handle network de-registration requests using
 * the "reg" SUBSCRIBE/NOTIFY event package
 */
@property (nonatomic, assign) BOOL enableRegeventDeregistration;

/**
 * xcap root loacation inside domain. Part of the path that goes between domain and AUID
 */
@property(nonatomic, copy) NSString *xcapRoot;

/**
 * True to use push notifications
 */
@property(nonatomic, assign) BOOL usePushNotifications;

/**
 * Configuration to use for for transporting signaling and media via tunnel.
 */
@property(nonatomic, retain) CPCTunnelConfig *tunnelConfig;

/**
 * Additional parameters to be added to SIP Contact headers.
 */
@property(nonatomic,  copy) NSArray *capabilities;

/**
 * Limit networking usage to this address if specified.  Address
 * can be IPv4 or IPv6 depending on setting of ipVersion.
 */
@property(nonatomic, retain) NSString *sourceAddress;

/**
 * Automatically re-open connections for registration when closed.
 * This setting is for platforms that make preferable solutions
 * difficult or impossible to deploy.  Applies to TCP/TLS only.
 */
@property(nonatomic, assign) BOOL autoRetryOnTransportDisconnect;

/**
 * Possible values for the SipAccountTransportType parameter:
 * <ul>
 * <li>1: the application sets up the transport based on the
 * capabilities of the network and the the application computer;
 * the preferred method will be obtained via DNS (NAPTR/srv) queries.
 * <li>2: This transport provides no signalling security.
 * <li>3: This transport provides no signalling security.
 * <li>4: Choose this option if you want to request signalling encryption.
 * </ul>
 */
+ (CPCSipAccountTransportType)transportType_Auto;
+ (CPCSipAccountTransportType)transportType_UDP;
+ (CPCSipAccountTransportType)transportType_TCP;
+ (CPCSipAccountTransportType)transportType_TLS;

+ (CPCSipAccountSessionTimerMode)sessionTimerMode_Inactive;
+ (CPCSipAccountSessionTimerMode)sessionTimerMode_Optional;
+ (CPCSipAccountSessionTimerMode)sessionTimerMode_Required;
+ (CPCSipAccountSessionTimerMode)sessionTimerMode_Always;

+ (CPCStunServerSourceType)stunServerSource_None;
+ (CPCStunServerSourceType)stunServerSource_SRV;
+ (CPCStunServerSourceType)stunServerSource_Custom;

+ (CPCSipAccountIpVersion) ipVersion_V4;
+ (CPCSipAccountIpVersion) ipVersion_V6;
+ (CPCSipAccountIpVersion) ipVersion_V4V6;

@end
