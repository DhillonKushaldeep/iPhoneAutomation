//
//  CPCXmppFileTransferState.h
//  
//
//
//

#ifndef _CPCXmppFileTransferState_h
#define _CPCXmppFileTransferState_h

#import <Foundation/Foundation.h>

#import "../CPCConfig.h"
#import "CPCXmppAccountHandler.h"
#import "CPCXmppFileTransferHandler.h"
#import "CPCXmppFileTransferManager.h"

@class CPCXmppFileTransferStateManager;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferState : NSObject

@property (nonatomic, readonly) CPCXmppAccountHandle account;
@property (nonatomic, readonly) CPCXmppFileTransferStateEnum *fileTransferState;
@property (nonatomic, readonly) CPCXmppFileTransferType *fileTransferType;
@property (nonatomic, readonly) NSString *remoteAddress;
@property (nonatomic, readonly) NSString *remoteDisplayName;
@property (nonatomic, readonly) CPCXmppFileTransferEndReason *endReason;
@property (nonatomic, readonly) NSArray *fileItems;

@end;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferStateManager : NSObject

@property (nonatomic, readonly) void *object;

+ (CPCXmppFileTransferStateManager*)getInterface:(CPCXmppFileTransferManager*)manager;

- (NSInteger)getState:(CPCXmppFileTransferHandle)fileTransferHandle outParam:(CPCXmppFileTransferState**)conversationState;

@end;


#endif
