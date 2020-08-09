//
//  CPCXmppMultiUserChatTypes.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef unsigned int CPCXmppMultiUserChatHandle;
typedef unsigned int CPCXmppMultiUserChatMessageHandle;

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMultiUserChatRoomState : NSObject
{
   BOOL _isCreatedBySelf;
   BOOL _isReady;
   NSString *_subject;
   NSString *_name;
   NSString *_description;
   NSString *_creation;
   BOOL _isPublic;
   BOOL _isPasswordProteced;
   BOOL _isOpen;
   BOOL _isModerated;
   BOOL _isPersistent;
   BOOL _isRecorded;
   NSInteger _anonymousMode;
   NSInteger _maxParticipants;
}

@property (nonatomic)BOOL isCreatedBySelf;
@property (nonatomic)BOOL isReady;
@property (nonatomic, copy)NSString *subject;
@property (nonatomic, copy)NSString *name;
@property (nonatomic, copy)NSString *description;
@property (nonatomic, copy)NSString *creation;
@property (nonatomic)BOOL isPublic;
@property (nonatomic)BOOL isPasswordProteced;
@property (nonatomic)BOOL isOpen;
@property (nonatomic)BOOL isModerated;
@property (nonatomic)BOOL isPersistent;
@property (nonatomic)BOOL isRecorded;
@property (nonatomic)NSInteger anonymousMode;
@property (nonatomic)NSInteger maxParticipants;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMultiUserChatHistoryItem : NSObject
{
   NSString *_from; // jid
   NSString *_plain;
   NSString *_html;
   NSInteger _timestamp;
}

@property (nonatomic, copy)NSString *from; // jid
@property (nonatomic, copy)NSString *plain;
@property (nonatomic, copy)NSString *html;
@property (nonatomic)NSInteger timestamp;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMultiUserChatAffiliation : CPCEnumType

+ (instancetype)none;
+ (instancetype)outcast;
+ (instancetype)member;
+ (instancetype)owner;
+ (instancetype)admin;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMultiUserChatRole : CPCEnumType

+ (instancetype)none;
+ (instancetype)visitor;
+ (instancetype)participant;
+ (instancetype)moderator;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCRoomListItem : NSObject
{
   NSString *_jid;
   NSString *_name;
   NSString *_node;
   
}

@property(nonatomic, copy) NSString *jid;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *node;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCParticipantState : NSObject
{
   NSString *_nickname;
   NSString *_jid;
   CPCXmppPresenceType *_presence;
   NSString *_message; // for presence
   CPCXmppMultiUserChatAffiliation *_affiliation;
   CPCXmppMultiUserChatRole *_role;
   BOOL _isBanned;
   BOOL _isKicked;
}

@property(nonatomic, copy) NSString *nickname;
@property(nonatomic, copy) NSString *jid;
@property(nonatomic, retain) CPCXmppPresenceType *presence;
@property(nonatomic, copy) NSString *message;
@property(nonatomic, retain) CPCXmppMultiUserChatAffiliation *affiliation;
@property(nonatomic, retain) CPCXmppMultiUserChatRole *role;
@property(nonatomic) BOOL isBanned;
@property(nonatomic) BOOL isKicked;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppMUCErrorType : CPCEnumType
+ (instancetype) noError;
+ (instancetype) passwordRequired;
+ (instancetype) userBanned;
+ (instancetype) roomNotFound;
+ (instancetype) creationRestricted;
+ (instancetype) reservedNicknameRequired;
+ (instancetype) notAMember;
+ (instancetype) nicknameConflict;
+ (instancetype) maximumUsersReached;
+ (instancetype) otherError;
@end

