//
//  CPCSipPresenceDocument.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"
#import "CPCSipPresenceModel.h"


/**
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresenceStatus : CPCEnumType

+ (instancetype)Available;
+ (instancetype)Busy;
+ (instancetype)Away;
+ (instancetype)OnThePhone;
+ (instancetype)NotAvailable;
+ (instancetype)DND;
+ (instancetype)AppearOffline;
+ (instancetype)Other;

@end




/**
* A class that contains only properties.
* Presence document as obtained by preparePresence:status: on the SipPresenceManager
* you can not instantiate it directly, always use the method above and then modify the object before
* using it in a notify or accept message
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresenceDocument : NSObject

@property (nonatomic, retain) CPCSipPresenceStatus* status;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, retain) CPCSipPresPresence *presence;

- (id)initWithStatus:(CPCSipPresenceStatus*)status note:(NSString*)note;

@end
