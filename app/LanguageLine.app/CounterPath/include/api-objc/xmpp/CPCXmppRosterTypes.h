//
//  CPCXmppRosterTypes.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import "../CPCTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppSubscriptionState : CPCEnumType

+ (NSInteger)SubscriptionState_None;              /**< Contact and user are not subscribed to each other, and
                                                   * neither has requested a subscription from the other. */
+ (NSInteger)SubscriptionState_None_OutPending;   /**< Contact and user are not subscribed to each other, and
                                                   * user has sent contact a subscription request but contact
                                                   * has not replied yet. */
+ (NSInteger)SubscriptionState_None_InPending;    /**< Contact and user are not subscribed to each other, and
                                                   * contact has sent user a subscription request but user has
                                                   * not replied yet (note: contact's server SHOULD NOT push or
                                                   * deliver roster items in this state, but instead SHOULD wait
                                                   * until contact has approved subscription request from user). */
+ (NSInteger)SubscriptionState_None_InOutPending; /**< Contact and user are not subscribed to each other, contact
                                                   * has sent user a subscription request but user has not replied
                                                   * yet, and user has sent contact a subscription request but
                                                   * contact has not replied yet. */
+ (NSInteger)SubscriptionState_Out;               /**< User is subscribed to contact (one-way). */
+ (NSInteger)SubscriptionState_Out_InPending;     /**< User is subscribed to contact, and contact has sent user a
                                                   * subscription request but user has not replied yet. */
+ (NSInteger)SubscriptionState_In;                /**< Contact is subscribed to user (one-way). */
+ (NSInteger)SubscriptionState_In_OutPending;     /**< Contact is subscribed to user, and user has sent contact a
                                                   * subscription request but contact has not replied yet. */
+ (NSInteger)SubscriptionState_InOut;             /**< User and contact are subscribed to each other (two-way). */
@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppPresenceType : CPCEnumType

+ (NSInteger)PresenceType_Available;                  /**< The entity is online. */
+ (NSInteger)PresenceType_Chat;                       /**< The entity is 'available for chat'. */
+ (NSInteger)PresenceType_Away;                       /**< The entity is away. */
+ (NSInteger)PresenceType_DND;                        /**< The entity is DND (Do Not Disturb). */
+ (NSInteger)PresenceType_XA;                         /**< The entity is XA (eXtended Away). */
+ (NSInteger)PresenceType_Unavailable;                /**< The entity is offline. */
+ (NSInteger)PresenceType_Probe;                      /**< This is a presence probe. */
+ (NSInteger)PresenceType_Error;                      /**< This is a presence error. */
+ (NSInteger)PresenceType_Invalid;                    /**< The stanza is invalid. */
+ (NSInteger)PresenceType_Unknown;                     /**< Presence has not been set yet. */
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppUserActivityGeneralType : CPCEnumType

+ (NSInteger)ActivityDoingChores;
+ (NSInteger)ActivityDrinking;
+ (NSInteger)ActivityEating;
+ (NSInteger)ActivityExercising;
+ (NSInteger)ActivityGrooming;
+ (NSInteger)ActivityHavingAppointment;
+ (NSInteger)ActivityInactive;
+ (NSInteger)ActivityRelaxing;
+ (NSInteger)ActivityTalking;
+ (NSInteger)ActivityTraveling;
+ (NSInteger)ActivityUndefinedGeneralType;
+ (NSInteger)ActivityWorking;
+ (NSInteger)ActivityInvalidGeneralType;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppUserActivitySpecificType  : CPCEnumType

+ (NSInteger)ActivityAtTheSpa;
+ (NSInteger)ActivityBrushingTeeth;
+ (NSInteger)ActivityBuyingGroceries;
+ (NSInteger)ActivityCleaning;
+ (NSInteger)ActivityCoding;
+ (NSInteger)ActivityCommuting;
+ (NSInteger)ActivityCooking;
+ (NSInteger)ActivityCycling;
+ (NSInteger)ActivityDancing;
+ (NSInteger)ActivityDayOff;
+ (NSInteger)ActivityDoingMaintenance;
+ (NSInteger)ActivityDoingTheDishes;
+ (NSInteger)ActivityDoingTheLaundry;
+ (NSInteger)ActivityDriving;
+ (NSInteger)ActivityFishing;
+ (NSInteger)ActivityGaming;
+ (NSInteger)ActivityGardening;
+ (NSInteger)ActivityGettingAHaircut;
+ (NSInteger)ActivityGoingOut;
+ (NSInteger)ActivityHangingOut;
+ (NSInteger)ActivityHavingABeer;
+ (NSInteger)ActivityHavingASnack;
+ (NSInteger)ActivityHavingBreakfast;
+ (NSInteger)ActivityHavingCoffee;
+ (NSInteger)ActivityHavingDinner;
+ (NSInteger)ActivityHavingLunch;
+ (NSInteger)ActivityHavingTea;
+ (NSInteger)ActivityHiding;
+ (NSInteger)ActivityHiking;
+ (NSInteger)ActivityInACar;
+ (NSInteger)ActivityInAMeeting;
+ (NSInteger)ActivityInRealLife;
+ (NSInteger)ActivityJogging;
+ (NSInteger)ActivityOnABus;
+ (NSInteger)ActivityOnAPlane;
+ (NSInteger)ActivityOnATrain;
+ (NSInteger)ActivityOnATrip;
+ (NSInteger)ActivityOnThePhone;
+ (NSInteger)ActivityOnVacation;
+ (NSInteger)ActivityOnVideoPhone;
+ (NSInteger)ActivityOther;
+ (NSInteger)ActivityPartying;
+ (NSInteger)ActivityPlayingSports;
+ (NSInteger)ActivityPraying;
+ (NSInteger)ActivityReading;
+ (NSInteger)ActivityRehearsing;
+ (NSInteger)ActivityRunning;
+ (NSInteger)ActivityRunningAnErrand;
+ (NSInteger)ActivityScheduledHoliday;
+ (NSInteger)ActivityShaving;
+ (NSInteger)ActivityShopping;
+ (NSInteger)ActivitySkiing;
+ (NSInteger)ActivitySleeping;
+ (NSInteger)ActivitySmoking;
+ (NSInteger)ActivitySocializing;
+ (NSInteger)ActivityStudying;
+ (NSInteger)ActivitySunbathing;
+ (NSInteger)ActivitySwimming;
+ (NSInteger)ActivityTakingABath;
+ (NSInteger)ActivityTakingAShower;
+ (NSInteger)ActivityThinking;
+ (NSInteger)ActivityWalking;
+ (NSInteger)ActivityWalkingTheDog;
+ (NSInteger)ActivityWatchingAMovie;
+ (NSInteger)ActivityWatchingTv;
+ (NSInteger)ActivityWorkingOut;
+ (NSInteger)ActivityWriting;
+ (NSInteger)ActivityInvalidSpecificType;
@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppResourceItem : NSObject
{
   NSString *_resource;
   NSInteger _priority;
   CPCXmppPresenceType *_presenceType;
   NSString *_presenceStatusText;
	// XEP-0108
   CPCXmppUserActivityGeneralType *_userActivityGeneralType;
   CPCXmppUserActivitySpecificType *_userActivitySpecificType;
   NSString *_userActivityText;

}

@property (nonatomic, copy)NSString *resource;
@property (nonatomic, readwrite)NSInteger priority;
@property (nonatomic, retain)CPCXmppPresenceType *presenceType;
@property (nonatomic, copy)NSString *presenceStatusText;
@property (nonatomic, retain)CPCXmppUserActivityGeneralType *userActivityGeneralType;
@property (nonatomic, retain)CPCXmppUserActivitySpecificType *userActivitySpecificType;
@property (nonatomic, copy)NSString *userActivityText;
@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXmppRosterItem : NSObject
{
   NSString *_address;
   NSString *_dispalyName;
   NSArray *_groups; //NSStrings
   CPCXmppSubscriptionState *_subscription;
   NSArray *_resources; //CPCXmppResourceItem
}
@property (nonatomic, copy)NSString *address;
@property (nonatomic, copy)NSString *displayName;
@property (nonatomic, retain)NSArray *groups;
@property (nonatomic, retain)CPCXmppSubscriptionState *subscription;
@property (nonatomic, retain)NSArray *resources;

@end

