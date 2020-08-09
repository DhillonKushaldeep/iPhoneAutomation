//
//  CPCSipPublicationManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCSipEventPublicationHandler.h"

@interface CPCSipEventPublicationSettings : NSObject
{
	NSString *_eventPackage;
	NSArray  *_eventPackageParams;
	NSInteger  _expiresSeconds;
	NSArray *_supportedMimeTypes;
}

@property (nonatomic, copy)NSString *eventPackage;
@property (nonatomic, copy)NSArray *eventPackageParams; //CPCParameter
@property (nonatomic, readwrite)NSInteger  expiresSeconds;
@property (nonatomic, copy)NSArray *supportedMimeTypes; //CPCMimeType

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPublicationManager : NSObject
@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the CPCSipPublicationManager interface.
 */
+ (CPCSipPublicationManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (NSInteger)addHandler:(id<CPCSipEventPublicationHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType;
- (NSInteger)addHandler:(id<CPCSipEventPublicationHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType queue:(dispatch_queue_t)queue;
- (NSInteger)removeHandler:(id<CPCSipEventPublicationHandler>)handler forAccount:(CPCSipAccountHandle)account DEPRECATED_MSG_ATTRIBUTE("Use removeHandler:forAccount:forEventType instead");
- (NSInteger)removeHandler:(id<CPCSipEventPublicationHandler>)handler forAccount:(CPCSipAccountHandle)account forEventType:(NSString*)eventType;

/**
 * Allocates a new publication context within the SDK.  This function is used in concert with setTarget(..)
 * to set up a publication prior to calling publish(..).
 */
-(CPCSipEventPublicationHandle) createPublication:(CPCSipAccountHandle) account withSettings:(CPCSipEventPublicationSettings*) settings;

/**
 * Sets the address identifying the party for which event state will be published.
 * The format of the targetAddress parameter is sip:username@domain.com
 */

- (NSInteger) setTarget:(CPCSipEventPublicationHandle) publication address:(NSString*)targetAddress;

/**
 * Sends an outgoing PUBLISH request to publish initial event state or to refresh event state
 * for the publication.
 */

- (NSInteger) publish:(CPCSipEventPublicationHandle) publication eventState:(CPCSipEventState*) eventState;

/**
 * Removes event state for the publication per section 4.5 of RFC 3903.
 */
- (NSInteger) end:(CPCSipEventPublicationHandle) publication;

@end
