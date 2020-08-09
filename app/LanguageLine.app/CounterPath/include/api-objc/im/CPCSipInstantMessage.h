//
//  CPCSipInstantMessage.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCSipInstantMessageHandler.h"
#import "../account/CPCSipAccountHandler.h"
#import "CPCSipImDocument.h"


@class CPCPhone;


/** Manager class to control incoming and outgoing SIP SIMPLE instant 
* messages; get an instance of the class using the class method 
* getInterface:(CPCPhone*)phone
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipInstantMessage: NSObject

@property (nonatomic, assign) void* object;

/*
 * Get a reference to the %CPCSipInstantMessage interface.
 */
+(id) getInterface: (CPCPhone*)phone;

/**
 * Set the handler for incoming and outgoing instant messages.
 */

- (NSInteger)addHandler:(id<CPCSipInstantMessageHandler>)handler forAccount:(CPCSipAccountHandle)account;
- (NSInteger)addHandler:(id<CPCSipInstantMessageHandler>)handler forAccount:(CPCSipAccountHandle)account queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCSipInstantMessageHandler>)handler forAccount:(CPCSipAccountHandle)account;

/**
 * Accept the incoming message identified by the %CPCSipInstantMessageHandle.
 *
 * @param im The handle that was passed in
 * SipInstantMessageHandler::onIncomingInstantMessage()
 * @param statusCode The applicable  code, typically 200
 */
- (NSInteger)acceptIncoming:(CPCSipInstantMessageHandle)im statusCode:(NSUInteger)statusCode;

/**
 * Reject the incoming message identified by the %CPCSipInstantMessageHandle.
 *
 * @param im The handle that was passed in
 * SipInstantMessageHandler::onIncomingInstantMessage()
 * @param statusCode The applicable  code, for example, azj - all the reject codes look like they would apply to the proxy, not to the client. can you think of any example to put in here
 * @param reasonText The text description of the  code, for example, clb
 */
- (NSInteger)rejectIncoming:(CPCSipInstantMessageHandle)im statusCode:(NSUInteger)statusCode reason:(NSString*)reason;

/**
 * Send an instant message to the specified URI, using the specified account.
 * @param account The %Account to use for delivery
 * @param targetaddress The fully formatted address of the recipient,
 * for example ewilding@zippy-phone.com or 6045551212@zippy-phone.com
 * @param content The body of the IM; UTF-8 encoded.
 * @param contentLength The length of the content of the MESSAGE, in bytes; will
 * be placed in the Content-Length header
 * @param mimeType A value from this enum
 * @param messageType the type of message to send e.g "IM", "SMS", defaults to none.
 */
- (CPCSipInstantMessageHandle)sendMessage:(CPCSipAccountHandle)account targetAddress:(NSString*)targetAddress content:(NSData*)content mimeType:(CPCSipIMMimeType*)mimeType messageType:(NSString*)messageType;

/**
 * Send an instant message to the specified URI, using the specified account.
 * @param account The %Account to use for delivery
 * @param targetAddress The fully formatted address of the recipient,
 * for example ewilding@zippy-phone.com or 6045551212@zippy-phone.com
 * @param content The body of the IM; UTF-8 encoded.
 * @param contentLength The length of the content of the MESSAGE, in bytes; will
 * be placed in the Content-Length header
 * @param customMimeType A custom mime-type value to be used
 * @param messageType the type of message to send e.g "IM", "SMS", defaults to none.
 */
- (CPCSipInstantMessageHandle)sendMessage:(CPCSipAccountHandle)account targetAddress:(NSString*)targetAddress content:(NSData*)content customMimeType:(NSString*)customMimeType messageType:(NSString*)messageType;

/**
 * Indicates only a specific set of mime types that are accepted and adds an accepted mime type
 * @param mimeType the mime type(xml/html) which is acceptable
 */
- (NSInteger) acceptMimeType: (CPCSipAccountHandle)account mimeType:(CPCSipIMMimeType*)mimeType;

- (NSInteger) acceptMimeType: (CPCSipAccountHandle)account customMimeType:(NSString*)mimeType;

- (NSInteger) rejectIncomingMimeType:(CPCSipInstantMessageHandle)im acceptMimeTypes:(NSArray*)acceptMimeTypes;

/**
 * Indicates that a new message is being typed/composed.
 *
 * Notes:
 *
 * 1) It does not necessarily mean that a notification will be sent to the other
 *    participant of the IM session. It depends on the internal state and timers.
 *
 * 2) However, this method must be called often while the participant is actively
 *    typing/composing the message in order to maintain an accurate internal state.
 *
 * @param account The %Account to use.
 * @param targetAddress The fully formatted address of the recipient.
 * @param mimeType the MIME type of the message being composed.
 * @param datetime the date/time at which the message is being composed, defaults to the current date/time if not specified.
 * @param refreshInterval the refresh interval to use (in seconds), defaults to 90 seconds.
 * @param idleInterval the idle interval to use (in seconds), defaults to 15 seconds.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */

- (NSInteger) setIsComposingMessage:(NSString*)targetAddress mimeType:(CPCSipIMMimeType*)mimeType account:(CPCSipAccountHandle)account date:(NSDate*)date refreshInterval:(NSInteger)refreshInterval idleInterval:(NSInteger)idleInterval;

/**
 * Indicates that a new message is being typed/composed.
 *
 * Notes:
 *
 * 1) It does not necessarily mean that a notification will be sent to the other
 *    participant of the IM session. It depends on the internal state and timers.
 *
 * 2) However, this method must be called often while the participant is actively
 *    typing/composing the message in order to maintain an accurate internal state.
 *
 * @param account The %Account to use.
 * @param targetAddress The fully formatted address of the recipient.
 * @param customMimeType the custom MIME type of the message being composed.
 * @param datetime the date/time at which the message is being composed, defaults to the current date/time if not specified.
 * @param refreshInterval the refresh interval to use (in seconds), defaults to 90 seconds.
 * @param idleInterval the idle interval to use (in seconds), defaults to 15 seconds.
 *
 * @return kSuccess if the operation was successful, kError otherwise.
 */
- (NSInteger) setIsComposingMessage:(NSString*)targetAddress customMimeType:(NSString*)customMimeType account:(CPCSipAccountHandle)account date:(NSDate*)date refreshInterval:(NSInteger)refreshInterval idleInterval:(NSInteger)idleInterval;

@end

