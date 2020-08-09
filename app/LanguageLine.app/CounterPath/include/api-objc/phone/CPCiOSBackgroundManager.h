//
//  CPCiOSBackgroundManager.h
//  CPCObjAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>


/*
	The following keys are required to be set into Info.plist to make Backgrounding work:
 
	UIRequiresPersistentWiFi (boolean) = True
	UIRequiredDeviceCapabilities (array) = microphone
	UIBackgroundModes (array) = voip, audio
 */

@class CPCPhone;

enum CPCKeepBgAliveStrategy
{
	ECPCKeepBgAliveStrategyDefault,
	ECPCKeepBgAliveStrategySoft,
	ECPCKeepBgAliveStrategyHard
};

enum CPCApplicationSleepBehaviour
{
	ECPCApplicationSleepBehaviourDefault,
	ECPCApplicationSleepBehaviourSleep,
	ECPCApplicationSleepBehaviourNotSleep
};



@protocol CPCiOSBackgroundManagerHandler <NSObject>
@optional
/* Fired in background on keep alive timer */
- (void) onBackgroundKeepAlive;

/* Return YES if app plays any audio like ringtone, dialpad keys sounds, etc... */
- (BOOL) isPlayingAudio;

/* Checks whatever application should force to sleep or not to sleep */
- (enum CPCApplicationSleepBehaviour) applicationSleepBehaviour;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCiOSBackgroundManager : NSObject

/**
 * Get a reference to the CPCiOSBackgroundManager interface. Application must query an instance for a first time from application:didFinishLaunchingWithOptions: method
 */
+ (id)instance;

/**
 * Assigns CPCPhone object. Call immediatelly after creating new CPCPhone instance
 */
- (void) setPhone:(CPCPhone*)phone;

- (NSInteger)addHandler:(id<CPCiOSBackgroundManagerHandler>)handler;
- (NSInteger)removeHandler:(id<CPCiOSBackgroundManagerHandler>)handler;

/**
 * Globally enable or disable backgrounding support.
 */
- (void) setBackgroundingEnabled:(BOOL)enabled;

/**
 * Tune WWAN backgrounding support.
 */
- (void) setBackgroundingWWANEnabled:(BOOL)enabled;

/**
 * Retrieves current backgrounding enabled state, it will depend on active transport
 */
- (BOOL) isBackgroundingEnabled;

/**
 * Keep Alive strategy
 */
- (void) setStrategy:(enum CPCKeepBgAliveStrategy)strategy;

/**
 * Background activity
 */
- (void) backgroundActivityDetected;

@end
