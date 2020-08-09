//
//  CPCXmppFileTransferHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CPCXmppAccountHandler.h"
#import "../CPCTypes.h"
#import "../CPCConfig.h"

typedef unsigned int CPCXmppFileTransferItemHandle;
typedef unsigned int CPCXmppFileTransferHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferEndReason : CPCEnumType

+ (CPCXmppFileTransferEndReason*)Reason_Unknown;
+ (CPCXmppFileTransferEndReason*)Reason_UserTerminatedLocally;
+ (CPCXmppFileTransferEndReason*)Reason_UserTerminatedRemotely;
+ (CPCXmppFileTransferEndReason*)Reason_ServerError;
+ (CPCXmppFileTransferEndReason*)Reason_ServerRejected;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferStateEnum : CPCEnumType

+ (CPCXmppFileTransferStateEnum*)State_None;
+ (CPCXmppFileTransferStateEnum*)State_LocalOriginated;
+ (CPCXmppFileTransferStateEnum*)State_RemoteOriginated;
+ (CPCXmppFileTransferStateEnum*)State_Connected;
+ (CPCXmppFileTransferStateEnum*)State_Early;
+ (CPCXmppFileTransferStateEnum*)State_Ended;

@end

/**
 * Represents whether we are sending or receiving the file transfer.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferType : CPCEnumType

+ (CPCXmppFileTransferType*)Type_Incoming;
+ (CPCXmppFileTransferType*)Type_Outgoing;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferItemEndReason : CPCEnumType

+ (CPCXmppFileTransferItemEndReason*)Reason_Complete;
+ (CPCXmppFileTransferItemEndReason*)Reason_Interrupted;
+ (CPCXmppFileTransferItemEndReason*)Reason_Failed;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferStreamType : CPCEnumType

+ (CPCXmppFileTransferStreamType*)Type_All;
+ (CPCXmppFileTransferStreamType*)Type_Socks5;
+ (CPCXmppFileTransferStreamType*)Type_InBand;
+ (CPCXmppFileTransferStreamType*)Type_OutOfBand;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppNewFileTransferEvent : NSObject
{
@private
   CPCXmppFileTransferStateEnum* fileTransferState;
   CPCXmppFileTransferType* fileTransferType;
   CPCXmppFileTransferHandle fileTransferHandle;
   NSString* remoteAddress;
   NSString* remoteDisplayName;
   CPCXmppAccountHandle account;
   NSArray* fileItems;
}


@property (nonatomic, retain) CPCXmppFileTransferStateEnum* fileTransferState;
@property (nonatomic, retain) CPCXmppFileTransferType* fileTransferType;
@property (nonatomic) CPCXmppFileTransferHandle fileTransferHandle;
@property (nonatomic, copy) NSString* remoteAddress;
@property (nonatomic, copy) NSString* remoteDisplayName;
@property (nonatomic)       CPCXmppAccountHandle account;
@property (nonatomic, copy) NSArray* fileItems; // The items present in the transfer, each of type CPCXmppFileTransferItemDetail

@end

/**
 * Fired by the SDK to signal the completion of the entire file transfer
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferEndedEvent : NSObject
{
@private
   CPCXmppFileTransferStateEnum* fileTransferState;
   CPCXmppFileTransferEndReason* endReason;
   CPCXmppFileTransferHandle fileTransferHandle;
   NSInteger xmppResponseCode;
   NSString* signallingEndEvent;
   NSString* signallingEndReason;
}

@property (nonatomic, retain) CPCXmppFileTransferStateEnum* fileTransferState;
@property (nonatomic, retain) CPCXmppFileTransferEndReason* endReason;
@property (nonatomic) CPCXmppFileTransferHandle fileTransferHandle;
@property (nonatomic)       NSInteger xmppResponseCode;
@property (nonatomic, copy) NSString* signallingEndEvent;
@property (nonatomic, copy) NSString* signallingEndReason;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferItemEndedEvent : NSObject
{
@private
   CPCXmppFileTransferItemHandle fileTransferItem;
   CPCXmppFileTransferItemEndReason* endReason;
   CPCXmppFileTransferStreamType* streamType;
}

@property (nonatomic)       CPCXmppFileTransferItemHandle fileTransferItem;
@property (nonatomic, retain) CPCXmppFileTransferItemEndReason* endReason;
@property (nonatomic, retain) CPCXmppFileTransferStreamType* streamType;
@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferItemProgressEvent : NSObject
{
@private
   CPCXmppFileTransferItemHandle fileTransferItem;
   unsigned short percent;
}

@property (nonatomic) CPCXmppFileTransferItemHandle fileTransferItem;
@property (nonatomic) unsigned short percent; // percentage [ 0% .. 100% ]

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppFileTransferErrorEvent : NSObject
{
@private
   NSString* errorText;
}

@property (nonatomic, copy) NSString* errorText;

@end


@protocol CPCXmppFileTransferHandler <NSObject>

/**
 * Callback invoked by the SDK when a new file transfer is created,
 * either by sending or receiving.
 */
- (NSInteger) onNewFileTransfer:(CPCXmppNewFileTransferEvent*)args;


/**
 * Callback invoked by the SDK when a file transfer has completed
 * (including all of its file transfer items)
 */
- (NSInteger) onFileTransferEnded:(CPCXmppFileTransferEndedEvent*)args;


/**
 * Progress indication (in percent) of an ongoing file transfer item
 */
- (NSInteger) onFileTransferItemProgress:(CPCXmppFileTransferItemProgressEvent*)args;


/**
 * Invoked by the SDK when a file (item) has finished transfering.
 * i.e. when percentage completion reaches 100%, or the item is
 * cancelled either locally or remotely.
 */
- (NSInteger) onFileTransferItemEnded:(CPCXmppFileTransferItemEndedEvent*)args;


/**
 * Invoked by the SDK for errors which do not fall into the categories
 * outlined above.
 */
- (NSInteger) onError:(CPCXmppFileTransferErrorEvent*)args;


@end
