//
//  CPCSipAccountHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCSipAccountSettings.h"

typedef NSUInteger CPCSipAccountHandle;

@interface CPCSipAccountEvent : NSObject

@property (nonatomic,readonly) CPCSipAccountHandle account;

@end

/**
 * Event to notify that the status of the account has changed. It contains:
 * <ul>
 * <li>accountStatus: The current status of the account is one of the values in Status.
 * <li>signalingStatusCode: The SIP code for the failure, for example, 404.
 * <li>signalingResponseText: The text description of the SIP code, for example,
 * "Not Found (User not found)".
 */

/**
* Event passed in onAccountStatusChanged: in the 
* <CPCSipAccountHandler> formal protocol.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipAccountStatusEvent : CPCSipAccountEvent

@property (nonatomic,readonly) NSUInteger status;
@property (nonatomic,readonly) NSUInteger reason;
@property (nonatomic,readonly) NSUInteger signalingStatusCode;
@property (nonatomic,readonly) NSString* signalingResponseText;
@property (nonatomic,readonly) CPCSipAccountTransportType transportType;

+ (NSUInteger)status_registered;
+ (NSUInteger)status_failure DEPRECATED_MSG_ATTRIBUTE("this state will never be reported (Unregistered will be reported instead)");
+ (NSUInteger)status_unregistered;
+ (NSUInteger)status_registering;
+ (NSUInteger)status_unregistering;
+ (NSUInteger)status_waitingToRegister;
+ (NSUInteger)status_refreshing;

+ (NSUInteger)reason_none;
+ (NSUInteger)reason_noNetwork;
+ (NSUInteger)reason_restrictedNetwork;
+ (NSUInteger)reason_newNetwork;
+ (NSUInteger)reason_serverResponse;
+ (NSUInteger)reason_localTimeout;
+ (NSUInteger)reason_networkDeregistered;

@end


@interface CPCSipAccountErrorEvent : CPCSipAccountEvent

@property (nonatomic,readonly) NSString* errorText;

@end


@interface CPCSipAccountLicensingErrorEvent : CPCSipAccountEvent

@property (nonatomic,readonly) NSString* errorText;

@end

@interface CPCSipAccountAdornmentEvent : CPCSipAccountEvent;

@property (nonatomic,readonly) NSUInteger adornmentMessageId;
@property (nonatomic,readonly) NSString *target;
@property (nonatomic,readonly) NSString *method;
@property (nonatomic,readonly) NSUInteger responseCode;
@property (nonatomic,readonly) NSString *message;

@end

@protocol CPCSipAccountAdornmentHandler <NSObject>
@optional
- (void)onAccountAdornment:(CPCSipAccountAdornmentEvent*)event;
@end

/**
* Handler for events relating to SIP accounts; set in 
* addHandler:forAccount: in the SipAccountManager class.
*/

@protocol CPCSipAccountHandler <NSObject>
@optional

/**
 * Notifies the application when the %SipAccount has changed to a specific state.
 */
- (void)onAccountStatusChanged:(CPCSipAccountStatusEvent*)event;
- (void)onAccountError:(CPCSipAccountErrorEvent*)event;
- (void)onAccountLicensingError:(CPCSipAccountLicensingErrorEvent*)event;

@end
