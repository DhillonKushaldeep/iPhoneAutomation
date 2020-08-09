//
//  CPCXmppFileTransferManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCXmppFileTransferHandler.h"
#import "CPCXmppAccountHandler.h"
#import "../CPCTypes.h"

@class CPCPhone;


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferAcceptedState : CPCEnumType

+ (CPCXmppFileTransferAcceptedState*)State_NotProcessed;
+ (CPCXmppFileTransferAcceptedState*)State_Accepted;
+ (CPCXmppFileTransferAcceptedState*)State_Rejected;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferItemDetail : NSObject

@property (nonatomic,       readwrite) CPCXmppFileTransferItemHandle handle;  /* handle for the item */
@property (nonatomic, copy, readwrite) NSString* localFilePath;               /* Local Path to the file (not including name) */
@property (nonatomic, copy, readwrite) NSString* localFileName;               /* Local Name of the file */
@property (nonatomic, copy, readwrite) NSString* remoteFileName;              /* Remote Name of the file */
@property (nonatomic,       readwrite)  long long fileSizeBytes;               /* Size of the file in bytes */
@property (nonatomic,       readonly)  BOOL isIncoming;                       /* True if the item is being transferred from the remote side, false otherwise */
@property (nonatomic, copy, readwrite) CPCXmppFileTransferAcceptedState*
acceptedState;                         /* State of the acceptance (by the user) of the item */
@property (nonatomic,       readwrite) unsigned short percentComplete;        /* Percentage complete of the item transfer */
@property (nonatomic, copy, readwrite) CPCXmppFileTransferStreamType* streamType; /* Stream type of the item transfer */

+ (CPCXmppFileTransferItemDetail*)itemDetailForOutboundTransfer;

@end



CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferManager : NSObject

@property (nonatomic, assign) void* object; 

+ (CPCXmppFileTransferManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Set the handler for events on the specified account. Set the handler
 * immediately after creating the account.
 */
- (void)addHandler:(id<CPCXmppFileTransferHandler>)handler forAccount:(CPCXmppAccountHandle)account;
- (void)addHandler:(id<CPCXmppFileTransferHandler>)handler forAccount:(CPCXmppAccountHandle)account queue:(dispatch_queue_t)queue;
- (void)removeHandler:(id<CPCXmppFileTransferHandler>)handler forAccount:(CPCXmppAccountHandle)account;


/**
 * Creates a new (empty) file transfer item handle, used for outbound
 * transfers. The handle will be unique across the SDK. After items
 * are created, they should be "configured" using the
 * configureFileTransferItems method, before start() is called.
 */
- (CPCXmppFileTransferItemHandle) createFileTransferItem:(CPCXmppAccountHandle)account;


/**
 * Allocates a new file transfer within the SDK, for outbound
 * transfer. After createFileTransfer() is called,
 * configureFileTransferItems should be invoked in order to set the
 * items to be transferred.
 *
 * After this has been done, addParticipant(..) and start(..)
 * @return CPCXmppFileTransferHandle which is unique within the SDK
 */
- (CPCXmppFileTransferHandle)createFileTransfer:(CPCXmppAccountHandle)account;


/**
 * Adds a participant to the file transfer session.  Call this
 * function after createFileTransfer(..) and before start(..).  Note:
 * The format of the targetAddress parameter is
 * username@domain.com/<resource>.
 *
 * NOTE: only the first participant will be used, as file transfer is
 * only to one hop (i.e. not 1:N). Additional participants will be
 * ignored.
 */
- (NSInteger)addParticipant:(CPCXmppFileTransferHandle)fileTransfer targetAddress:(NSString*)targetAddress;


/**
 * Initiates an outgoing (client) session to the remote participant.
 */
- (NSInteger)start:(CPCXmppFileTransferHandle)fileTransfer;


/**
 * Ends an (already connected) session.
 * Does nothing if the file transfer is not connected.
 */
- (NSInteger)end:(CPCXmppFileTransferHandle)fileTransfer;


/**
 * This method should be called before accepting/starting a file
 * transfer, it informs the SDK which file transfer items will be
 * used.
 *
 * In the case of an inbound transfer, the application should set
 * the "isAccepted" flag for each item in the list.  If the user
 * accepted the item, then the local name and/or path may also be
 * modified.  The handles should not be changed.
 *
 * @param fileItems array of CPCXmppFileTransferItemDetail
 */
- (NSInteger)configureFileTransferItems:(CPCXmppFileTransferHandle)fileTransfer fileItems:(NSArray*)fileItems;


/**
 * Accepts the file transfer. Any file transfer
 * items which are marked as "isAccepted" using the
 * configureFileTransferItems method will be accepted
 */
- (NSInteger)accept:(CPCXmppFileTransferHandle)fileTransfer;


/**
 * The entire file transfer (and all of its items) will be rejected
 * with the reason sent to the remote party. This should be done
 * BEFORE accept() is called, otherwise an end() call will be required.
 *
 * @param fileTransfer The incoming session to reject.
 * @param rejectReason The XMPP response code sent to the originating party.
 */
- (NSInteger)reject:(CPCXmppFileTransferHandle)fileTransfer rejectReason:(NSInteger)rejectReason;


/**
 * Cancels an ongoing file transfer (within the overall file transfer).
 */
- (NSInteger)cancelItem:(CPCXmppFileTransferHandle)fileTransfer fileTransferItem:(CPCXmppFileTransferItemHandle)fileTransferItem;


@end
