//
//  CPCXmppCannedPresence.h
//  CPCObjAPI2
//

#import "../CPCTypes.h"
#import "CPCXmppRosterTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppCannedStatus : CPCEnumType
+ (NSInteger) XmppCannedStatus_Available;
+ (NSInteger) XmppCannedStatus_Chat;
+ (NSInteger) XmppCannedStatus_Away;
+ (NSInteger) XmppCannedStatus_AppearAway;
+ (NSInteger) XmppCannedStatus_Busy;
+ (NSInteger) XmppCannedStatus_HavingLunch;
+ (NSInteger) XmppCannedStatus_OnVacation;
+ (NSInteger) XmppCannedStatus_ScheduledHoliday;
+ (NSInteger) XmppCannedStatus_InactiveOther;
+ (NSInteger) XmppCannedStatus_OnThePhone;
+ (NSInteger) XmppCannedStatus_DoNotDisturb;
+ (NSInteger) XmppCannedStatus_NotAvailableForCalls;
+ (NSInteger) XmppCannedStatus_AppearOffline;
+ (NSInteger) XmppCannedStatus_Offline;
+ (NSInteger) XmppCannedStatus_Other;
+ (NSInteger) XmppCannedStatus_Invalid;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppCannedPresence : NSObject
{
   NSString *_resource;
   CPCXmppCannedStatus *_status;
   NSString *_note;
   NSInteger _priority;
}

@property (nonatomic, copy) NSString *resource;
@property (nonatomic, retain) CPCXmppCannedStatus *status;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, assign) NSInteger priority;

@end
