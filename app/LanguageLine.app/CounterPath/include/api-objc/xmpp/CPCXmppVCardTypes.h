//
//  CPCXmppVCardTypes.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardAddressType : CPCEnumType

+ (NSUInteger)AddrTypeHome;
+ (NSUInteger)AddrTypeWork;
+ (NSUInteger)AddrTypePref;
+ (NSUInteger)AddrTypeX400;
+ (NSUInteger)AddrTypeInet;
+ (NSUInteger)AddrTypeParcel;
+ (NSUInteger)AddrTypePostal;
+ (NSUInteger)AddrTypeDom;
+ (NSUInteger)AddrTypeIntl;
+ (NSUInteger)AddrTypeVoice;
+ (NSUInteger)AddrTypeFax;
+ (NSUInteger)AddrTypePager;
+ (NSUInteger)AddrTypeMsg;
+ (NSUInteger)AddrTypeCell;
+ (NSUInteger)AddrTypeVideo;
+ (NSUInteger)AddrTypeBbs;
+ (NSUInteger)AddrTypeModem;
+ (NSUInteger)AddrTypeIsdn;
+ (NSUInteger)AddrTypePcs;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardName : NSObject
{
   NSString *_family;
   NSString *_given;
   NSString *_middle;
   NSString *_prefix;
   NSString *_suffix;
}

@property (nonatomic, copy)NSString *family;         /**< Family name. */
@property (nonatomic, copy)NSString *given;          /**< Given name. */
@property (nonatomic, copy)NSString *middle;         /**< Middle name. */
@property (nonatomic, copy)NSString *prefix;         /**< Name prefix. */
@property (nonatomic, copy)NSString *suffix;         /**< Name suffix. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardClassification : CPCEnumType

+ (NSUInteger)ClassNone;
+ (NSUInteger)ClassPublic;
+ (NSUInteger)ClassPrivate;
+ (NSUInteger)ClassConfidential;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardEmail : NSObject
{
    NSString *_userid;
    BOOL _home;
    BOOL _work;
    BOOL _internet;
    BOOL _pref;
    BOOL _x400;
}

@property (nonatomic, copy)NSString *userid;         /**< Email address. */
@property (nonatomic) BOOL home;                  /**< Whether this is a personal address. */
@property (nonatomic) BOOL work;                  /**< Whether this is a work address. */
@property (nonatomic) BOOL internet;              /**< Whether this is an internet address(?). */
@property (nonatomic) BOOL pref;                  /**< Whether this is the preferred address. */
@property (nonatomic) BOOL x400;                  /**< Whether this is an X.400 address. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardTelephone: NSObject
{
   NSString *_number;
   BOOL _home;
   BOOL _work;
   BOOL _voice;
   BOOL _fax;
   BOOL _pager;
   BOOL _msg;
   BOOL _cell;
   BOOL _video;
   BOOL _bbs;
   BOOL _modem;
   BOOL _isdn;
   BOOL _pcs;
   BOOL _pref;
}

@property (nonatomic, copy)NSString *number;         /**< The phone number. */
@property (nonatomic) BOOL home;                  /**< Whether this is a personal number. */
@property (nonatomic) BOOL work;                  /**< Whether this is a work number. */
@property (nonatomic) BOOL voice;                 /**< Whether this is a voice number. */
@property (nonatomic) BOOL fax;                   /**< Whether this is a fax number. */
@property (nonatomic) BOOL pager;                 /**< Whether this is a pager. */
@property (nonatomic) BOOL msg;                   /**< MSG(?) */
@property (nonatomic) BOOL cell;                  /**< Whether this is a cell phone. */
@property (nonatomic) BOOL video;                 /**< Whether this is a video chat(?). */
@property (nonatomic) BOOL bbs;                   /**< Whether this is a BBS. */
@property (nonatomic) BOOL modem;                 /**< Whether this is a modem. */
@property (nonatomic) BOOL isdn;                  /**< Whether this is a ISDN line(?) */
@property (nonatomic) BOOL pcs;                   /**< PCS(?) */
@property (nonatomic) BOOL pref;                  /**< Whether this is the preferred number. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardAddress : NSObject
{
    NSString *_pobox;
    NSString *_extadd;
    NSString *_street;
    NSString *_locality;
    NSString *_region;
    NSString *_pcode;
    NSString *_ctry;
    BOOL _home;
    BOOL _work;
    BOOL _postal;
    BOOL _parcel;
    BOOL _pref;
    BOOL _dom;
    BOOL _intl;
}

@property (nonatomic, copy)NSString *pobox;          /**< Pobox. */
@property (nonatomic, copy)NSString *extadd;         /**< Extended address. */
@property (nonatomic, copy)NSString *street;         /**< Street. */
@property (nonatomic, copy)NSString *locality;       /**< Locality. */
@property (nonatomic, copy)NSString *region;         /**< Region. */
@property (nonatomic, copy)NSString *pcode;          /**< Postal code. */
@property (nonatomic, copy)NSString *ctry;           /**< Country. */
@property (nonatomic) BOOL home;                  /**< Whether this is a personal address. */
@property (nonatomic) BOOL work;                  /**< Whether this is a work address. */
@property (nonatomic) BOOL postal;                /**< Whether this is a postal address(?). */
@property (nonatomic) BOOL parcel;                /**< Whether this is a arcel address(?). */
@property (nonatomic) BOOL pref;                  /**< Whether this is the preferred address. */
@property (nonatomic) BOOL dom;                   /**< Whether this is a domestic(?) address. */
@property (nonatomic) BOOL intl;                  /**< Whether this is an international(?) address. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardLabel : NSObject
{
   NSMutableArray *_lines;
   BOOL _home;
   BOOL _work;
   BOOL _postal;
   BOOL _parcel;
   BOOL _pref;
   BOOL _dom;
   BOOL _intl;
}

@property (nonatomic, retain) NSMutableArray *lines;           /**< A list of lines. NSString */
@property (nonatomic) BOOL home;                  /**< Whether this is a personal address. */
@property (nonatomic) BOOL work;                  /**< Whether this is a work address. */
@property (nonatomic) BOOL postal;                /**< Whether this is a postal address(?). */
@property (nonatomic) BOOL parcel;                /**< Whether this is a arcel address(?). */
@property (nonatomic) BOOL pref;                  /**< Whether this is the preferred address. */
@property (nonatomic) BOOL dom;                   /**< Whether this is a domestic(?) address. */
@property (nonatomic) BOOL intl;                  /**< Whether this is an international(?) address. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardGeo : NSObject
{
   NSString *_latitude;
   NSString *_longitude;
}

@property (nonatomic, copy)NSString *latitude;       /**< Longitude. */
@property (nonatomic, copy)NSString *longitude;      /**< Latitude. */

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardOrganization : NSObject
{
   NSString *_name;
   NSMutableArray *_units;
}

@property (nonatomic, copy)NSString *name;                 /**< The organizations name. */
@property (nonatomic, retain) NSMutableArray *units;   /**< A list of units in the organization
                                   * (the VCard's owner belongs to?).  NSString*/
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardPhoto : NSObject
{
   NSString *_extval;
   NSData *_binval;
   NSString *_type;
}

@property (nonatomic, copy)NSString *extval;         /**< The photo is not stored inside the VCard. This is a hint (URL?)
                                * where to look for it. */
@property (nonatomic, retain)NSData *binval;         /**< This is the photo (binary). */
@property (nonatomic, copy)NSString *type;           /**< This is a hint at the mime-type. May be forged! */

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppVCardDetail : NSObject
{
   NSArray *_emailList;
   NSArray *_telephoneList;
   NSArray *_addressList;
   NSArray *_labelList;
   
   CPCXmppVCardName *_name;
   CPCXmppVCardGeo *_geo;
   CPCXmppVCardOrganization *_organization;
   CPCXmppVCardPhoto *_photo;
   CPCXmppVCardPhoto *_logo;
   
   CPCXmppVCardClassification *_classification;
   
   NSString *_formattedname;
   NSString *_nickname;
   NSString *_url;
   NSString *_birthday;
   NSString *_jid;
   NSString *_title;
   NSString *_role;
   NSString *_note;
   NSString *_desc;
   NSString *_mailer;
   NSString *_timezone;
   NSString *_product;
   NSString *_revision;
   NSString *_sortstring;
   NSString *_uid;
}

@property (nonatomic, retain) NSArray *emailList;
@property (nonatomic, retain) NSArray *telephoneList;
@property (nonatomic, retain) NSArray *addressList;
@property (nonatomic, retain) NSArray *labelList;

@property (nonatomic, retain) CPCXmppVCardName *name;
@property (nonatomic, retain) CPCXmppVCardGeo *geo; // geo location
@property (nonatomic, retain) CPCXmppVCardOrganization *organization;
@property (nonatomic, retain) CPCXmppVCardPhoto *photo;
@property (nonatomic, retain) CPCXmppVCardPhoto *logo;

@property (nonatomic, retain) CPCXmppVCardClassification *classification;

@property (nonatomic, copy) NSString *formattedname;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *birthday;
@property (nonatomic, copy) NSString *jid;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *role;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, copy) NSString *desc; // description
@property (nonatomic, copy) NSString *mailer;
@property (nonatomic, copy) NSString *timezone;
@property (nonatomic, copy) NSString *product; // the production identifier
@property (nonatomic, copy) NSString *revision; // the date of the last revision
@property (nonatomic, copy) NSString *sortstring;
@property (nonatomic, copy) NSString *uid; // the unique identifier

@end
