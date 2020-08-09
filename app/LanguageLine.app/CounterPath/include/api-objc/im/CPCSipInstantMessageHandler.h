//
//  CPCSipInstantMessageHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"

typedef NSUInteger CPCSipInstantMessageHandle;

/**
* Abstract parent class; do not instantiate this class directly 
* (doing so will throw an exception)
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipIMEvent: NSObject

@property (nonatomic, readonly) CPCSipAccountHandle account;
@property (nonatomic, readonly) CPCSipInstantMessageHandle im;

@end

/**
* Event passed in onIncomingInstantMessage: in the 
* <CPCSipInstantMessageHandler> formal protocol. 
*/ 
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipIncomingIMEvent: CPCSipIMEvent

@property (nonatomic, readonly) CPCNameAddress* to;
@property (nonatomic, readonly) CPCNameAddress* from;
@property (nonatomic, readonly) NSString* mimeType;
@property (nonatomic, readonly) NSData *content;
@property (nonatomic, readonly) NSString* messageType;

@end

/**
* A class that contains only properties.
* Contains information about the success or failure of an outgoing IM.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipOutgoingIMHeaders: NSObject

@property (nonatomic,readonly) NSArray* acceptableMimeTypes;

@end

/**
* Event passed in onOutgoingInstantMessageFailure: in the 
* <CPCSipInstantMessageHandler> formal protocol. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipOutgoingIMEvent: CPCSipIMEvent

@property (nonatomic, readonly) CPCSipInstantMessageHandle im;
@property (nonatomic, readonly) NSUInteger signalingStatusCode;
@property (nonatomic, readonly) NSString* signalingResponseText;
@property (nonatomic, readonly) CPCSipOutgoingIMHeaders* headers;

@end

/**
 * Event fired by the SDK when the other participant of the
 * chat session is composing a new message.
 *
 * @param state The state of the 'isComposing' indicator
 * @param to The recipient of the message
 * @param from The sender of the message
 * @param mimeType MIME type of the message being composed
 * @param lastActive date/time the 'isComposing' indicator was last active
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCIsComposingIMEvent : CPCSipIMEvent

@property (nonatomic, readonly) CPCIsComposingMessageState* state;
@property (nonatomic, readonly) CPCNameAddress* to;
@property (nonatomic, readonly) CPCNameAddress* from;
@property (nonatomic, readonly) NSString* mimeType;
@property (nonatomic, readonly) NSDate *lastActive;

@end

/**
 * Event fired by the SDK when a 'message being composed' notification
 * was successfully sent.
 *
 * @param state The state of the 'isComposing' indicator
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSetIsComposingIMSuccessEvent : CPCSipIMEvent

@property (nonatomic, readonly) CPCIsComposingMessageState* state;

@end

/**
 * Event fired by the SDK when a 'message being composed' notification
 * failed sending.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSetIsComposingIMFailureEvent : CPCSipIMEvent

@end

/**
* Event passed in onError: in the <CPCSipInstantMessageHandler> formal protocol,
* used to report general SDK error conditions, such as invalid handles.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCImErrorEvent: CPCSipIMEvent

@property (nonatomic, readonly) NSString* errorText;

@end

/**
* Handler for events relating to incoming and outgoing 
* SIP instant messages; set in setHandler:setAccount: 
* in the SipInstantMessageManager class.
*/
@protocol CPCSipInstantMessageHandler <NSObject>
@optional

-(void)onIncomingInstantMessage:(CPCSipIncomingIMEvent*)event;
-(void)onOutgoingInstantMessageSuccess:(CPCSipOutgoingIMEvent*)event;
-(void)onOutgoingInstantMessageFailure:(CPCSipOutgoingIMEvent*)event;
-(void)onIsComposingInstantMessage:(CPCIsComposingIMEvent*)event;
-(void)onSetIsComposingInstantMessageSuccess:(CPCSetIsComposingIMSuccessEvent*)event;
-(void)onSetIsComposingInstantMessageFailure:(CPCSetIsComposingIMFailureEvent*)event;
-(void)onInstantMessageError:(CPCImErrorEvent*)event;

@end
