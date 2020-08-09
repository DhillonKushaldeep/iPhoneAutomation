//
//  CPCSipPresenceModel.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"



/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresCannedStatus : CPCEnumType

+ (instancetype)Available;
+ (instancetype)Busy;
+ (instancetype)Away;
+ (instancetype)OnThePhone;
+ (instancetype)NotAvailable;
+ (instancetype)DND;
+ (instancetype)AppearOffline;
+ (instancetype)Other;
+ (instancetype)Lunch;
+ (instancetype)Vacation;

@end


#define OPTIONAL        // a property marked as optional means the value can be nil indicating it was not part of the presence stanza



typedef NSString CPCSipPresID;
typedef NSString CPCSipPresURI;
typedef NSDate CPCSipPresDateTime;

/** Timestamp type  / EXAMPLE: <pdm:timestamp>2010-07-01T09:37:47Z</pdm:timestamp> */
typedef CPCSipPresDateTime CPCSipPresTimeStamp;

/** Device ID, a URN / EXAMPLE: <dm:deviceID>urn:x-mac:0003ba4811e3</dm:deviceID> */
typedef CPCSipPresURI CPCSipPresDeviceId;


/**
* A class that contains only properties.
*/

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresFromUntil : NSObject
{
	CPCSipPresDateTime* _from;
	CPCSipPresDateTime* _until;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresDateTime* from;
@property (nonatomic, retain) OPTIONAL CPCSipPresDateTime* until;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresNote : NSObject
{
	NSString* _text;
	NSString* _lang;
}
@property (nonatomic, retain) NSString* text;
@property (nonatomic, retain) OPTIONAL NSString* lang;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresActivityType : CPCEnumType

+ (instancetype)Appointment;
+ (instancetype)Away;
+ (instancetype)Breakfast;
+ (instancetype)Busy;
+ (instancetype)Dinner;
+ (instancetype)Holiday;
+ (instancetype)InTransit;
+ (instancetype)LookingForWork;
+ (instancetype)Meal;
+ (instancetype)Meeting;
+ (instancetype)OnThePhone;
+ (instancetype)Performance;
+ (instancetype)PermanentAbsence;
+ (instancetype)Playing;
+ (instancetype)Presentation;
+ (instancetype)Shopping;
+ (instancetype)Sleeping;
+ (instancetype)Spectator;
+ (instancetype)Steering;
+ (instancetype)Travel;
+ (instancetype)Tv;
+ (instancetype)Vacation;
+ (instancetype)Working;
+ (instancetype)Worship;
+ (instancetype)Unknown;
+ (instancetype)Other;
+ (instancetype)Lunch;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresActivity : NSObject
{
	CPCSipPresActivityType* _activity;
	CPCSipPresNote* _otherValue;
}
@property (nonatomic, retain) CPCSipPresActivityType* activity;
@property (nonatomic, retain) CPCSipPresNote* otherValue;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresActivities : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	NSArray* _notes;
	NSArray* _activities;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) NSArray* activities;  // array of CPCSipPresActivity

@end


/** Class, Describes the class of the service, device or person. EXAMPLE: <rpid:class>calendar</rpid:class> */
typedef NSString CPCSipPresClass;


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresMoodValue : CPCEnumType

+ (instancetype)Afraid;
+ (instancetype)Amazed;
+ (instancetype)Angry;
+ (instancetype)Annoyed;
+ (instancetype)Anxious;
+ (instancetype)Ashamed;
+ (instancetype)Bored;
+ (instancetype)Brave;
+ (instancetype)Calm;
+ (instancetype)Cold;
+ (instancetype)Confused;
+ (instancetype)Contented;
+ (instancetype)Cranky;
+ (instancetype)Curious;
+ (instancetype)Depressed;
+ (instancetype)Disappointed;
+ (instancetype)Disgusted;
+ (instancetype)Distracted;
+ (instancetype)Embarrassed;
+ (instancetype)Excited;
+ (instancetype)Flirtatious;
+ (instancetype)Frustrated;
+ (instancetype)Grumpy;
+ (instancetype)Guilty;
+ (instancetype)Happy;
+ (instancetype)Hot;
+ (instancetype)Humbled;
+ (instancetype)Humiliated;
+ (instancetype)Hungry;
+ (instancetype)Hurt;
+ (instancetype)Impressed;
+ (instancetype)InAwe;
+ (instancetype)InLove;
+ (instancetype)Indignant;
+ (instancetype)Interested;
+ (instancetype)Invinvible;
+ (instancetype)Jealous;
+ (instancetype)Lonely;
+ (instancetype)Mean;
+ (instancetype)Moody;
+ (instancetype)Nervous;
+ (instancetype)Neutral;
+ (instancetype)Offended;
+ (instancetype)Playful;
+ (instancetype)Proud;
+ (instancetype)Relieved;
+ (instancetype)Remorseful;
+ (instancetype)Restless;
+ (instancetype)Sad;
+ (instancetype)Sarcastic;
+ (instancetype)Serious;
+ (instancetype)Shocked;
+ (instancetype)Shy;
+ (instancetype)Sick;
+ (instancetype)Sleepy;
+ (instancetype)Stressed;
+ (instancetype)Surprised;
+ (instancetype)Thirsty;
+ (instancetype)Worried;
+ (instancetype)Unknown;
+ (instancetype)Other;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresMood : NSObject
{
	CPCSipPresMoodValue* _mood;
	CPCSipPresNote* _otherValue;
}

@property (nonatomic, retain) CPCSipPresMoodValue* mood;
@property (nonatomic, retain) CPCSipPresNote* otherValue;

@end


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresMoods : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	NSArray *_notes;
	NSArray *_moods;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) NSArray* moods; // array of CPCSipPresMood objects

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresAudioIsType : CPCEnumType

+ (instancetype)Noisy;
+ (instancetype)Ok;
+ (instancetype)Quiet;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresVideoIsType : CPCEnumType

+ (instancetype)TooBright;
+ (instancetype)Ok;
+ (instancetype)Dark;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresTextIsType : CPCEnumType

+ (instancetype)Uncomfortable;
+ (instancetype)Inappropriate;
+ (instancetype)Ok;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPlacesIs : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	CPCSipPresAudioIsType* _audio;
	CPCSipPresVideoIsType* _video;
	CPCSipPresTextIsType* _text;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) OPTIONAL CPCSipPresAudioIsType* audio;
@property (nonatomic, retain) OPTIONAL CPCSipPresVideoIsType* video;
@property (nonatomic, retain) OPTIONAL CPCSipPresTextIsType* text;

@end



/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPlaceTypeValue : NSObject
{
	CPCSipPresNote* _otherValue;
}

@property (nonatomic, retain) CPCSipPresNote* otherValue;

@end

/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPlaceType : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	NSArray* _notes;
	CPCSipPresPlaceTypeValue* _placeType;
}
@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) CPCSipPresPlaceTypeValue* placeType;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPrivacyType : CPCEnumType

+ (instancetype)Audio;
+ (instancetype)Text;
+ (instancetype)Video;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPrivacy : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	NSArray* _notes;
	NSArray* _privacy;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) NSArray* privacy; // array of CPCSipPresPrivacyType objects

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresRelationshipType : CPCEnumType

+ (instancetype)Assistant;
+ (instancetype)Associate;
+ (instancetype)Family;
+ (instancetype)Friend;
+ (instancetype)Self;
+ (instancetype)Supervisor;
+ (instancetype)Unknown;
+ (instancetype)Other;

@end


/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresRelationshipValue : NSObject
{
	CPCSipPresRelationshipType* _relationship;
	CPCSipPresNote* _otherValue;
}
@property (nonatomic, retain) CPCSipPresRelationshipType* relationship;
@property (nonatomic, retain) CPCSipPresNote* otherValue;

@end

/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresRelationship : NSObject
{
	NSArray* _notes;
	CPCSipPresRelationshipValue* _relationship;
}
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) CPCSipPresRelationshipValue* relationship;

@end



/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresServiceClassType : CPCEnumType

+ (instancetype)Courier;
+ (instancetype)Electronic;
+ (instancetype)Freight;
+ (instancetype)InPerson;
+ (instancetype)Postal;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresServiceClass : NSObject
{
	NSArray* _notes;
	CPCSipPresServiceClassType* _serviceClass;
}

@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) CPCSipPresServiceClassType* serviceClass;

@end


/** 
* A class that contains only constants.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSphereType : CPCEnumType

+ (instancetype)Home;
+ (instancetype)Work;
+ (instancetype)Unknown;

@end


/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresSphere : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	CPCSipPresSphereType* _sphere;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) OPTIONAL CPCSipPresSphereType* sphere;

@end


/** 
* A class that contains only properties. A URI pointing to an image (icon) 
* representing the current status of the person or service.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresStatusIcon : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	CPCSipPresURI* _uri;
}

@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) CPCSipPresURI* uri;


@end


/**
 * A class that contains only properties. Describes the number of minutes of offset from UTC at the user's current location.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresTimeOffset : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresFromUntil* _fromUntil;
	NSString* _description;
	NSInteger _offset;
}
@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresFromUntil* fromUntil;
@property (nonatomic, retain) OPTIONAL NSString* description;
@property (nonatomic, assign) NSInteger offset;

@end


/**
 * A class that contains only constants.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresActiveIdle : CPCEnumType

+ (instancetype)Active;
+ (instancetype)Idle;

@end


/**
 * A class that contains only properties. Records the user-input or usage state of the service or device.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresUserInput : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresActiveIdle* _activeIdle;
	NSNumber* _idleThreshold;
	CPCSipPresDateTime* _lastInput;
}
@property (nonatomic, retain) OPTIONAL CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresActiveIdle* activeIdle;
@property (nonatomic, retain) OPTIONAL NSNumber* idleThreshold;
@property (nonatomic, retain) OPTIONAL CPCSipPresDateTime* lastInput;

@end


/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresDevice : NSObject
{
	CPCSipPresID* _identifier;
	CPCSipPresDeviceId *_deviceID;
	NSArray *_notes;
	CPCSipPresTimeStamp *_timestamp;
	CPCSipPresUserInput *_userInput;
}
@property (nonatomic, retain) CPCSipPresID* identifier;
@property (nonatomic, retain) CPCSipPresDeviceId *deviceID;
@property (nonatomic, retain) NSArray *notes;
@property (nonatomic, retain) OPTIONAL CPCSipPresTimeStamp *timestamp;
@property (nonatomic, retain) OPTIONAL CPCSipPresUserInput *userInput;

@end


/**
 * A class that contains only properties. Contains information about the human user
 */

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPerson : NSObject
{
	CPCSipPresID* _identifier;
	NSArray* _notes;
	CPCSipPresTimeStamp *_timestamp;
	CPCSipPresActivities *_activities;
	CPCSipPresClass *_classEnt;
	CPCSipPresMoods *_mood;
	CPCSipPresPlacesIs *_placeIs;
	CPCSipPresPlaceType *_placeType;
	CPCSipPresPrivacy *_privacy;
	CPCSipPresSphere *_sphere;
	CPCSipPresStatusIcon *_statusIcon;
	CPCSipPresTimeOffset *_timeOffset;
	CPCSipPresUserInput *_userInput;
}
@property (nonatomic, retain) CPCSipPresID* identifier;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) OPTIONAL CPCSipPresTimeStamp *timestamp;
@property (nonatomic, retain) OPTIONAL CPCSipPresActivities *activities;
@property (nonatomic, retain) OPTIONAL CPCSipPresClass *classEnt;
@property (nonatomic, retain) OPTIONAL CPCSipPresMoods *mood;
@property (nonatomic, retain) OPTIONAL CPCSipPresPlacesIs *placeIs;
@property (nonatomic, retain) OPTIONAL CPCSipPresPlaceType *placeType;
@property (nonatomic, retain) OPTIONAL CPCSipPresPrivacy *privacy;
@property (nonatomic, retain) OPTIONAL CPCSipPresSphere *sphere;
@property (nonatomic, retain) OPTIONAL CPCSipPresStatusIcon *statusIcon;
@property (nonatomic, retain) OPTIONAL CPCSipPresTimeOffset *timeOffset;
@property (nonatomic, retain) OPTIONAL CPCSipPresUserInput *userInput;

@end


/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresContact : NSObject
{
	NSNumber *_priority;
	CPCSipPresURI *_contact;
}
@property(nonatomic, retain) OPTIONAL NSNumber *priority;	//CGFloat
@property(nonatomic, retain) CPCSipPresURI *contact;

@end


/**
 * A class that contains only constants.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresBasicStatus : CPCEnumType

+ (instancetype)Open;
+ (instancetype)Closed;

@end



/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresStatus : NSObject
{
	CPCSipPresBasicStatus* _basic;
}
@property (nonatomic, retain) OPTIONAL CPCSipPresBasicStatus* basic;

@end


/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresTuple : NSObject
{
	CPCSipPresID* _identifier;
	NSArray* _notes;
	CPCSipPresTimeStamp *_timestamp;
	CPCSipPresStatus *_status;
	CPCSipPresContact *_contact;
	CPCSipPresDeviceId *_deviceID;
	CPCSipPresRelationship *_relationship;
	CPCSipPresServiceClass *_serviceClass;
	CPCSipPresUserInput *_userInput;
}
@property (nonatomic, retain) CPCSipPresID* identifier;
@property (nonatomic, retain) NSArray* notes;
@property (nonatomic, retain) OPTIONAL CPCSipPresTimeStamp *timestamp;
@property (nonatomic, retain) CPCSipPresStatus *status;
@property (nonatomic, retain) OPTIONAL CPCSipPresContact *contact;
@property (nonatomic, retain) OPTIONAL CPCSipPresDeviceId *deviceID;
@property (nonatomic, retain) OPTIONAL CPCSipPresRelationship *relationship;
@property (nonatomic, retain) OPTIONAL CPCSipPresServiceClass *serviceClass;
@property (nonatomic, retain) OPTIONAL CPCSipPresUserInput *userInput;

@end



/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCSipPresPresence : NSObject
{
	NSString *_entity;
	NSArray *_notes;
	NSArray *_tuples;
	NSArray *_devices;
	NSArray *_persons;
}
@property (nonatomic, retain) NSString *entity;
@property (nonatomic, retain) NSArray *notes;
@property (nonatomic, retain) NSArray *tuples;
@property (nonatomic, retain) NSArray *devices;
@property (nonatomic, retain) NSArray *persons;

@end



