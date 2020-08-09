//
//  CPCAudioHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../CPCConfig.h"
#import "../../CPCTypes.h"


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCEchoCancellationMode : CPCEnumType

+ (NSInteger) none;
+ (NSInteger) aggressiveEchoCancellation;
+ (NSInteger) defaultEchoCancellation;
+ (NSInteger) loudSpeakerphoneEchoSuppression;
+ (NSInteger) loudEarpieceEchoSuppression;
+ (NSInteger) earpieceEchoSuppression;

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCNoiseSuppressionMode : CPCEnumType

+ (NSInteger) none;
+ (NSInteger) low;
+ (NSInteger) moderate;
+ (NSInteger) high;
+ (NSInteger) veryHigh;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVadMode : CPCEnumType

+ (NSInteger) none;
+ (NSInteger) conventional;
+ (NSInteger) aggressiveLow;
+ (NSInteger) aggressiveMid;
+ (NSInteger) aggressiveHigh;

@end


//-------------------- Audio Device Info -------------------------------------------------------------------------------

typedef NSInteger CPCAudioDeviceRole;
typedef NSInteger CPCAudioDeviceType;

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioDeviceInfo : NSObject

@property (nonatomic, readonly) NSString* friendlyName;
@property (nonatomic, readonly) NSUInteger deviceID;
@property (nonatomic, readonly) CPCAudioDeviceRole role;
@property (nonatomic, readonly) CPCAudioDeviceType type;

+ (CPCAudioDeviceType) type_capture;
+ (CPCAudioDeviceType) type_render;

+ (CPCAudioDeviceRole) role_none;
+ (CPCAudioDeviceRole) role_headset;
+ (CPCAudioDeviceRole) role_speaker;

@end

/**
* Event passed in onAudioDeviceListUpdated: in the <CPCAudioHandler> formal protocol. 
*/ 
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioDeviceListEvent : NSObject

@property (nonatomic, readonly) NSArray* deviceList;

@end



//-------------------- Audio Codec Info --------------------------------------------------------------------------------


/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioCodecInfo : NSObject

@property (nonatomic, readonly) NSString* codecName;
@property (nonatomic, readonly) NSUInteger codecID;
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic, readonly) NSUInteger samplingRate;
@property (nonatomic, readonly) NSUInteger minBandwidth;
@property (nonatomic, readonly) NSUInteger maxBandwidth;
@property (nonatomic, readonly) NSUInteger priority;

@end

/**
* Event passed in onAudioCodecListUpdated: in the <CPCAudioHandler> formal protocol. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioCodecListEvent : NSObject

@property (nonatomic, readonly) NSArray* codecList;

@end


//-------------------- Audio Volume event ------------------------------------------------------------------------------

/**
* Event passed in onAudioDeviceVolume: in the 
* <CPCAudioHandler> formal protocol. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioDeviceVolumeEvent : NSObject

@property (nonatomic, readonly) BOOL micMuted;
@property (nonatomic, readonly) BOOL speakerMuted;
@property (nonatomic, readonly) NSUInteger micVolumeLevel;
@property (nonatomic, readonly) NSUInteger speakerVolumeLevel;

@end

//-------------------- Audio Device Level event ------------------------------------------------------------------------------

/**
 * Event passed in onAudioDeviceLevelChange: in the
 * <CPCAudioHandler> formal protocol.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioDeviceLevelChangeEvent : NSObject

@property (nonatomic, readonly) NSUInteger inputDeviceLevel;
@property (nonatomic, readonly) NSUInteger outputDeviceLevel;

@end

//-------------------- Audio interruption event ------------------------------------------------------------------------------

/**
 * Event passed in onAudioInterruption: in the
 * <CPCAudioHandler> formal protocol.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioInterruptionEvent : NSObject

@property (nonatomic, readonly) BOOL interrupted;

@end


//-------------------- Audio HAndler Protocol --------------------------------------------------------------------------

typedef NSUInteger CPCPlaySoundHandle;


/**
* Handler for events relating to audio and audio devices; 
* set in addHandler: in the Audio class.
*/
@protocol CPCAudioHandler <NSObject>
@optional
/**
 * Called when the list of media devices on the system changes, or as a result of
 * calling #CPCAudio: -(void)queryDeviceList;
 */
- (void)onAudioDeviceListUpdated:(CPCAudioDeviceListEvent*)event;

/**
 * Called when the audio specified in the call to #CPCAudio: -(void)playSound... has
 * successfully finished playing.
 */
- (void)onPlaySoundComplete:(NSNumber*)handle;

/**
 * Called when the audio specified in the call to #CPCAudio: -(void)playSound.. could
 * not be played.  Possible reasons include:
 *  - resource specified by resourceUri not found
 */
- (void)onPlaySoundFailure:(NSNumber*)handle;

/**
 * Called as a result of calling #CPCAudio: -(void)queryCodecList;
 */
- (void)onAudioCodecListUpdated:(CPCAudioCodecListEvent*)event;


/**
 * Called as a result of calling #Audio::queryDeviceVolume().
 */
- (void)onAudioDeviceVolume:(CPCAudioDeviceVolumeEvent*)event;


/**
 * Called as a result of change in input and/or output device levels.
 */
- (void)onAudioDeviceLevelChange:(CPCAudioDeviceLevelChangeEvent*)event;

/**
 * Called when audio interrution state changes
 */
- (void)onAudioInterruption:(CPCAudioInterruptionEvent*)event;

@end


