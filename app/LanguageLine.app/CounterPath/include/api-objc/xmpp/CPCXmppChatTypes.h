//
//  CPCXmppChatTypes.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import "../CPCTypes.h"

typedef unsigned int CPCXmppChatHandle;
typedef NSString* CPCXmppChatMessageHandle;

/**
 * Possible message delivery statuses.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMessageDeliveryStatus : CPCEnumType

+ (NSInteger)delivered;
+ (NSInteger)error;

@end
/**
 * Possible message display statuses.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMessageDisplayStatus : CPCEnumType

+ (NSInteger)displayed;

@end

/**
 * Possible states for the 'IsComposing' indicator.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppIsComposingMessageState : CPCEnumType

+ (NSInteger)unknown;
+ (NSInteger)idle;
+ (NSInteger)active;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMessageType : CPCEnumType

+ (NSInteger)messageDeliveredNotification;
+ (NSInteger)messageDisplayedNotification;
+ (NSInteger)isComposingNotification;
+ (NSInteger)message;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMessageContent : NSObject

@property (nonatomic, readwrite, copy) NSString *plainText;
@property (nonatomic, readwrite, copy) NSString *htmlText;

@end

