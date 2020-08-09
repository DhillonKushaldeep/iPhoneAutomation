//
//  CPCXmppAccountHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

typedef NSUInteger CPCXmppAccountHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountError : CPCEnumType
+ (NSInteger)Error_None;
+ (NSInteger)Error_NoHandlerSet;
+ (NSInteger)Error_IoError;
+ (NSInteger)Error_DnsError;
+ (NSInteger)Error_HostNotFound;
+ (NSInteger)Error_ConnectionRefused;
+ (NSInteger)Error_AlreadyEnabled;
+ (NSInteger)Error_NotEnabled;
+ (NSInteger)Error_AlreadyConnected;
+ (NSInteger)Error_NotConnected;
+ (NSInteger)Error_ParseError;
+ (NSInteger)Error_StreamError;
+ (NSInteger)Error_TlsFailed;
+ (NSInteger)Error_CompressionFailed;
+ (NSInteger)Error_UnsupportedAuthMech;
+ (NSInteger)Error_AuthenticationFailed;
@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountEvent : NSObject

@property (nonatomic, readonly) CPCXmppAccountHandle account;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountStatus : CPCEnumType
+ (NSInteger)Status_Connected;
+ (NSInteger)Status_Failure;
+ (NSInteger)Status_Disconnected;
+ (NSInteger)Status_Connecting;
+ (NSInteger)Status_Disconnecting;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountStatusChangedEvent : CPCXmppAccountEvent
@property (nonatomic, readonly)CPCXmppAccountStatus *status;
@property (nonatomic, readonly)CPCXmppAccountError *error;
@property (nonatomic, readonly)NSString *errorText;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountErrorEvent : CPCXmppAccountEvent
@property (nonatomic, readonly)NSString *errorText;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppLicensingErrorEvent : CPCXmppAccountEvent
@property (nonatomic, readonly)NSString *errorText;
@end

@protocol CPCXmppAccountHandler <NSObject>
@optional
/**
* Notifies the application when the %XmppAccount has changed to a specific state.
*/
- (void)onXmppAccountStatusChanged:(CPCXmppAccountStatusChangedEvent*)event;

/**
 * Notifies the application when an account error has occurred
 */
- (void)onXmppAccountError:(CPCXmppAccountErrorEvent*)event;

/**
 *
 */
- (void) onXmppLicensingError:(CPCXmppLicensingErrorEvent*)event;

@end

