//
//  CPCXmppAccount.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppRosterTypes.h"
#import "CPCXmppAccountHandler.h"
#import "CPCXmppCannedPresence.h"
#import "../phone/CPCNetworkChangeHandler.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountSettings : NSObject
{
   NSString *_username;
   NSString *_domain;
   NSString *_password;
   NSString *_proxy;
   NSUInteger _port;
   NSString *_resource;
   NSUInteger _priority;
   NSString *_softwareName;
   NSString *_softwareVersion;
   NSString *_softwareOS;
   NSString *_identityCategory;
   NSString *_identityType;
   NSUInteger _connectTimeOut;
   NSUInteger _keepAliveTime;
   NSArray *_fileTransfileProxies;
   BOOL _usePingKeepAlive;
   BOOL _enableLocalSocks5Proxy;
   BOOL _enableRemoteStreamHostDiscovery;
   BOOL _ignoreCertVerification;
   BOOL _logXmppStanzas;
}
/**
* The user portion of the XMPP identity (JID) for this account,
* for example, the "kperera" portion of "kperera@zippy-phone.com"
*/
@property (nonatomic, copy)NSString *username;
/**
* The host portion of the XMPP identity (JID) for this account,
* for example, the "zippy-phone.com" portion of "kperera@zippy-phone.com"
*/
@property (nonatomic, copy)NSString *domain;
/**
* The password for this account.
*/
@property (nonatomic, copy)NSString *password;
/**
* The fully qualified host name or IP address of the outbound proxy.
*/
@property (nonatomic, copy)NSString *proxy;
/**
* The listening port of the server or proxy.
* Specifying a non-zero port would turn off DNS SRV lookup.
*/
@property(nonatomic, readwrite)NSUInteger port;
/**
* The resource portion of the full XMPP identity for this account,
* leave empty to have server generate one for the account.
*/
@property (nonatomic, copy)NSString *resource;
/**
* The priority for this account's XMPP resource.
*/
@property(nonatomic, readwrite)NSUInteger priority;
/**
 * Part of entity capability discovery
*/
@property (nonatomic, copy)NSString *softwareName;
@property (nonatomic, copy)NSString *softwareVersion;
@property (nonatomic, copy)NSString *softwareOS;
@property (nonatomic, copy)NSString *identityCategory;
@property (nonatomic, copy)NSString *identityType;
/**
* Time to wait for TCP to connect to a host before giving up.
*/
@property(nonatomic, readwrite)NSUInteger connectTimeOut;
/**
* Periodic connection keep alive paramters.
* Specifying zero keepAliveTime will disable keep alive.
* Specifying true for usePingKeepAlive will use XEP instead of
* sending white space keep alive.
*/
@property(nonatomic, readwrite)NSUInteger keepAliveTime;
@property(nonatomic, readwrite)BOOL  usePingKeepAlive;
/**
* List of external file transfer proxies.
* Format: [<username>[:<password>]@]<server>[:<port>];jid=<jid>
* E.g.: username:password@jabber.org:7777;jid=proxy.jabber.org
*/
@property(nonatomic, retain)NSArray *fileTransfileProxies;


/**
 * Specifying whether to host local Socks5 proxy or not.
 */
@property(nonatomic, assign)BOOL enableLocalSocks5Proxy;

/**
 * Specifying whether to discovery remote stream host or not.
 */
@property(nonatomic, assign)BOOL enableRemoteStreamHostDiscovery;

/**
 * Ignore certificate verification.
 */
@property(nonatomic, assign)BOOL ignoreCertVerification;

/**
 * Output all sent and received XMPP stanzas to debug log.
 */
@property(nonatomic, assign)BOOL logXmppStanzas;

@end


@class CPCPhone;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppAccountManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the XmppAccountManager interface.
 */
+ (CPCXmppAccountManager*)managerForPhone:(CPCPhone*)phone;
/**
 * Create an account.
 * @param XmppAccountSettings The XmppAccountSettings that holds
 * configuration information for this account.
 */
- (CPCXmppAccountHandle)create:(CPCXmppAccountSettings*)accountSettings;

- (NSInteger)destroy:(CPCXmppAccountHandle)account;

/**
* Set the handler for events on the specified account. Set the handler
* immediately after creating the account.
*/
- (NSInteger)addHandler:(id<CPCXmppAccountHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (NSInteger)addHandler:(id<CPCXmppAccountHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCXmppAccountHandler>)handler forAccount:(CPCXmppAccountHandle)account;
/**
* Send out presence status
*/
- (NSInteger)publishPresence:(CPCXmppPresenceType*)presence forAccount:(CPCXmppAccountHandle)account withMessage:(NSString*)msg;
- (NSInteger)publishPresence:(CPCXmppPresenceType*)presence
                  forAccount:(CPCXmppAccountHandle)account
                 withMessage:(NSString*)msg
     userActivityGeneralType:(CPCXmppUserActivityGeneralType*)userActivityGeneralType
    userActivitySpecificType:(CPCXmppUserActivitySpecificType*)userActivitySpecificType
            userActivityText:(NSString*)userActivityText;

- (NSInteger)publishCannedPresence:(CPCXmppCannedStatus*)status forAccount:(CPCXmppAccountHandle)account withMessage:(NSString*)msg;

/**
* Enable the specified account so that it can be used to communicate with the XMPP server.
*
* You should use CPCAPI2::XmppAccount::XmppAccountHandler::onAccountStatusChanged()
* to be notified of progress after invoking %enable().
*/

- (NSInteger)enable:(CPCXmppAccountHandle)account;

/**
* Disable the specified account: if account will be discconnected if it connected .
* You should use CPCAPI2::XmppAccount::XmppAccountHandler::onAccountStatusChanged()
* to be notified of progress after invoking %disable().
*/
- (NSInteger)disable:(CPCXmppAccountHandle)account;

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

/**
 * Configure the default account settings.
 * Call configureDefaultAccountSettings(), and then applySettings().
 *
 * @param account the account handle.
 * @param accountSettings the XmppAccountSettings that holds configuration information for this account.
 */
-(NSInteger)configureDefaultAccountSettings:(CPCXmppAccountHandle) account settings:(CPCXmppAccountSettings**) accountSettings;

/**
 * Apply the account settings configured with configureDefaultAccountSettings()
 *
 * @param account the account handle
 */
-(NSInteger)applySettings:(CPCXmppAccountHandle) account;

/**
 *The following (synchronous) methods are used in conjunction with the RemoteSync Module
 *
 *@param account the account handle
 */
-(NSString *)getRemoteSyncAccountID:(CPCXmppAccountHandle)account;


/**
 * Set or clear a restriction on use of the specified network type.
 *
 * @param account the account handle.
 * @param networkTransport the network transport.
 * @param restricted restriction value
 */
- (NSInteger) setNetworkRestriction:(BOOL)restricted network:(CPCNetworkTransport*)networkTransport account:(CPCXmppAccountHandle)account;

/**
 * Block incoming presence
 */
- (NSInteger) blockIncomingPresence:(BOOL)block account:(CPCXmppAccountHandle)account;

@end
