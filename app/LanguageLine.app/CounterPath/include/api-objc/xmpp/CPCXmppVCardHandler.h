//
//  CPCXmppVCardHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppVCardTypes.h"

typedef unsigned int CPCXmppVCardHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVCardFetchedEvent : NSObject

@property (nonatomic) CPCXmppAccountHandle account;
@property (nonatomic) CPCXmppVCardHandle handle;
@property (nonatomic, copy) NSString *jid;
@property (nonatomic, retain) CPCXmppVCardDetail *detail;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVCardOperationResultEvent : NSObject

@property (nonatomic) CPCXmppAccountHandle account;
@property (nonatomic) CPCXmppVCardHandle handle;
@property (nonatomic, copy) NSString *jid;
@property (nonatomic) NSInteger type;
@property (nonatomic) NSInteger result;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardErrorEvent : NSObject

@property (nonatomic, copy) NSString* errorText;

@end

@protocol CPCXmppVCardHandler <NSObject>


/**
 * This function is called when a VCard has been successfully fetched.
 */
-(void)onVCardFetched:(CPCVCardFetchedEvent*)evt;

/**
 * This function is called to indicate the result of a VCard operation
 */
-(void)onVCardOperationResult:(CPCVCardOperationResultEvent*) evt;
-(void)onXmppVCardError:(CPCXmppVCardErrorEvent*)evt;

@end
