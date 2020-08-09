//
//  CPCSipAccount.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CPCSipAccountHandler.h"
#import "../phone/CPCNetworkChangeHandler.h"


#pragma GCC visibility push(default)

@class CPCPhone, CPCSipAccountSettings;


/**
* Manager class to control SIP accounts and therefore the main entry point for 
* SIP-related functionality; get an instance of the class using the class 
* method managerForPhone: ; each SipAccountManager represents one instance 
* of a SIP user agent, so create as many accounts as you need.
*/

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipAccountManager : NSObject


/**
 * Get a reference to the SipAccount interface.
 */
+ (CPCSipAccountManager*)managerForPhone:(CPCPhone*)phone;



/**
 * Create an account.
 * @param SipAccountSettings The SipAccountSettings that holds
 * configuration information for this account.
 */
- (CPCSipAccountHandle)createAccount:(CPCSipAccountSettings*)settings;

/**
 * Configure the default account settings.  These settings are used unless overridden by network-transport-specific settings.
 * Call configureDefaultAccountSettings(), configureTransportAccountSettings() (optional), and then applySettings().
 *
 * @param account the account handle.
 * @param sipAccountSettings the SipAccountSettings that holds
 *                           configuration information for this account.
 */
- (NSInteger)configureDefaultAccountSettings:(CPCSipAccountSettings*)settings forAccount:(CPCSipAccountHandle)account;

/**
 * Configure transport-specific account settings.  These settings override the default account settings, and take effect when the NetworkChangeManager detects that
 * network connectivity has changed to the specified transport type.
 * Call configureDefaultAccountSettings(), configureTransportAccountSettings() (optional), and then applySettings().
 *
 * @param account the account handle.
 * @param sipAccountSettings the SipAccountSettings that holds
 *                           configuration information for this account.
 * @param transport the network transport to associate configuration with.
 */
- (NSInteger)configureTransportAccountSettings:(CPCSipAccountSettings*)settings forAccount:(CPCSipAccountHandle)account forTransport:(CPCNetworkTransport*)transport;

/**
 * Apply the account settings configured with configureDefaultAccountSettings(), configureTransportAccountSettings()
 *
 * @param account the account handle
 */
- (NSInteger)applySettings:(CPCSipAccountHandle)account;

/**
 * Add / remove handler for events on the specified account. Set at least one observer
 * immediately after creating the account. Observer messages are always called on the Main thread
 * to stop getting events set the handler to nil
 */
- (void)addHandler:(id<CPCSipAccountHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (void)addHandler:(id<CPCSipAccountHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (void)removeHandler:(id<CPCSipAccountHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Enable the specified account so that it can be used to send/receive SIP messages.
 * If the SipAccountSettings.useRegistrar is true, then this function also sends
 * the inital SIP REGISTER message to the proxy/registrar configured in SipAccountSettings.
 *
 * You should use CPCAPI2::SipAccount::SipAccountHandler::onAccountStatusChanged()
 * to be notified of progress after invoking %enable().
 */
- (NSInteger)enableAccount:(CPCSipAccountHandle)account;


/**
 * Disable the specified account: if SipAccountSettings.useRegistrar is true, unregister it with the SIP registrar.
 * You should use CPCAPI2::SipAccount::SipAccountHandler::onAccountStatusChanged()
 * to be notified of progress after invoking %disable().
 */
- (NSInteger)disableAccount:(CPCSipAccountHandle)account;

/**
 * Deletes an account, uses the handle obtained from create.
 */
- (NSInteger)destroy:(CPCSipAccountHandle)account;

/**
 * Request a refresh of the current registration (sends a re-REGISTER request).
 *
 * @param deadlineSecondsFromNow Set to 0 to request an unconditional refresh. Otherwise specify a value
 *                               to be compared against the number of seconds remaining before the next
 *                               scheduled refresh by the SDK, wherein a refresh will only be performed now
 *                               if (timeUntilNextRefresh < deadlineSecondsFromNow).
 */
- (NSInteger) requestRegistrationRefresh:(CPCSipAccountHandle) account deadlineSecondsFromNow:(NSUInteger) deadlineSecondsFromNow;

- (void)addAdornmentHandler:(id<CPCSipAccountAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (void)addAdornmentHandler:(id<CPCSipAccountAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (void)removeAdornmentHandler:(id<CPCSipAccountAdornmentHandler>)handler forAccount:(CPCSipAccountHandle)account;

- (int)adornMessageHeader:(NSArray*)headers forEvent:(NSUInteger)adornmentMessageId forAccount:(CPCSipAccountHandle)account;

/**
 * Sets restriction on specified network.
 *
 * @param account the account handle.
 * @param networkTransport the network transport.
 * @param restricted restriction value
 */
- (NSInteger) setNetworkRestriction:(BOOL)restricted network:(CPCNetworkTransport*)networkTransport account:(CPCSipAccountHandle) account;


/**
 * The following setters will set custom values for certain SIP timers (see RFC 3261 for a full table of SIP timers)
 * It is not necessary to set these timers; if they are not set then the default values will be used.
 * These setters must be called before any SIP account is enabled. The values set here will apply for all SIP 
 * accounts.
 */

/**
 * Sets the SIP T1 timer value (see RFC 3261)
 *
 * @param t1ValueMs the value (in milliseconds) for the T1 timer
 */
-(void) setT1TimerValueMs:(NSUInteger) t1ValueMs;

/**
 * Sets the SIP T2 timer value (see RFC 3261)
 *
 * @param t2ValueMs the value (in milliseconds) for the T2 timer
 */
-(void) setT2TimerValueMs:(NSUInteger) t2ValueMs;

/**
 * Sets the SIP T4 timer value (see RFC 3261)
 *
 * @param t4ValueMs the value (in milliseconds) for the T4 timer
 */
-(void) setT4TimerValueMs:(NSUInteger) t4ValueMs;

/**
 * Sets the SIP TD timer value (see RFC 3261)
 *
 * @param tDValueMs the value (in milliseconds) for the TD timer
 */
-(void) setTDTimerValueMs:(NSUInteger) tDValueMs;

/**
 * Gets the SIP T1 timer value (see RFC 3261)
 */
-(NSUInteger) getT1TimerValueMs;

/**
 * Gets the SIP T2 timer value (see RFC 3261)
 */
-(NSUInteger) getT2TimerValueMs;

/**
 * Gets the SIP T4 timer value (see RFC 3261)
 */
-(NSUInteger) getT4TimerValueMs;

/**
 * Gets the SIP TD timer value (see RFC 3261)
 */
-(NSUInteger) getTDTimerValueMs;

/**
 * As soon as the account manager is created you should start processing to recieve events.
 * you cna create accounts before start but enable them only once processing is started
 */
- (void)startProcessing DEPRECATED_MSG_ATTRIBUTE("No longer necessary to call.");


/**
 * before application teardown you should stop processing to properly free resopurces.
 * call stop processing only after all acounts are in disabled state.
 */
- (void)stopProcessing DEPRECATED_MSG_ATTRIBUTE("No longer necessary to call.");

@end


#pragma GCC visibility pop
