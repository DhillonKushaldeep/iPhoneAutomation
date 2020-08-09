//
//  CPCAudio.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../CPCConfig.h"
#import "CPCAudioHandler.h"

@class CPCMediaManager;

/** Manager class to control audio and audio devices;
* get an instance of the class using the class method getInterface:
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudio : NSObject


@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the %Audio interface.
 */
+ (CPCAudio*)getInterface:(CPCMediaManager*)manager;


/**
 * Sets the callback handler for audio related events.
 */
- (void)addHandler:(id<CPCAudioHandler>)handler;
- (void)addHandler:(id<CPCAudioHandler>)handler queue:(dispatch_queue_t)queue;
- (void)removeHandler:(id<CPCAudioHandler>)handler;


/**
 * Queries the list of audio capture and playout devices available on the system.
 * The set of devices reported is dependant on OS support.
 * See #AudioHandler::onAudioDeviceListUpdated(..) for the results of the query.
 */
- (void)queryDeviceList;


/**
 * Selects the audio capture/render device used for the voice path during an audio call.
 * The deviceId corresponds to the AudioDeviceInfo::id returned by calling queryDeviceList().
 */
- (NSInteger)setCaptureDevice:(NSUInteger)deviceId forRole:(CPCAudioDeviceRole)role;

- (NSInteger)setRenderDevice:(NSUInteger)deviceId forRole:(CPCAudioDeviceRole)role;


/**
 * Plays the specified sound on the specified audio render device.
 * The resourceUri specifies the location of the audio data to be played.
 *
 * Supported URI formats:
 *
 * DTMF tones, e.g. tone:n;duration=ms where n is 0..15 and ms is the duration in milliseconds
 * Resource URIs, e.g. ms-appx:///Assets/ALERT_asterik.wav
 *
 * Windows 8 'Windows Store' Apps - Resource URIs must be in the format ms-appx:///Assets/ALERT_asterik.wav
 */
- (CPCPlaySoundHandle)playSound:(NSString*)resourceUri role:(CPCAudioDeviceRole)role repeat:(BOOL)repeat;


/**
 * Stop playing the specified sound.  Note that it is only necessary to call this if you wish to prematurely stop
 * the playing sound, or if you wish to stop playback when playSound was called with 'repeat' set to 'true'.
 */
- (NSInteger)stopPlaySound:(CPCPlaySoundHandle)soundHandle;


/**
 * Queries the list of audio codecs available in this version of the SDK.
 * The set of codecs reported is dependant on OS support.
 * See #AudioHandler::onAudioCodecListUpdated(..) for the results of the query.
 */
- (NSInteger)queryCodecList;


/**
 * Enables or disables a codec.  Changes take effect for subsequent new incoming/outgoing
 * calls.
 * @param codecId The id of the codec returned by #AudioHandler::onAudioCodecListUpdated(..)
 * @param enabled True to enable the codec, false to disable
 */
- (NSInteger)setCodecEnabled:(NSUInteger)codecID enable:(BOOL)enable;


/**
 * Sets the priority of a codec. Higher value indicates a higher priority codec which should be used if possible
 * @param codecId The id of the codec returned by #AudioHandler::onAudioCodecListUpdated(..)
 * @param priority The priority of the codec. Higher value = greater priority to be used
 */
- (NSInteger)setCodecPriority:(NSUInteger)codecId priority:(NSUInteger)priority;


/**
 * Mutes or unmutes the active microphone device.
 */
- (NSInteger)setMicMute:(BOOL)mute;


/**
 * Mutes or unmutes the active speaker device.
 */
- (NSInteger)setSpeakerMute:(BOOL)mute;


/**
 * Sets the active microphone device volume.
 * @param level The desired level in the range 0 ... 100
 */
- (NSInteger)setMicVolume:(NSUInteger)level;


/**
 * Sets the active speaker device volume.
 * @param level The desired level in the range 0 ... 100
 */
- (NSInteger)setSpeakerVolume:(NSUInteger)level;


/**
 * Queries the current status of microphone and speaker mute and volume levels.
 * See #AudioHandler::onAudioDeviceVolume(..) for the results of the query.
 */
- (NSInteger)queryDeviceVolume;

- (NSInteger)setEchoCancellationMode:(CPCEchoCancellationMode*)mode role:(CPCAudioDeviceRole)role;

- (NSInteger)setNoiseSuppressionMode:(CPCNoiseSuppressionMode*)mode role:(CPCAudioDeviceRole)role;

- (NSInteger)setVadMode:(CPCVadMode*)mode role:(CPCAudioDeviceRole)role;

- (NSInteger)setAudioDscp:(unsigned int)mediaDscp;

/**
 * Starts sending input device lelvels to the application layer.
 */
- (NSInteger)startMonitoringCaptureDeviceLevels:(NSUInteger)deviceId;

/**
 * Stops sending input device lelvels to the application layer.
 */
- (NSInteger)stopMonitoringCaptureDeviceLevels;

/**
 * Starts sending output device lelvels to the application layer.
 */
- (NSInteger)startMonitoringRenderDeviceLevels:(NSUInteger)deviceId resourceUri:(NSString*)resourceUri;

/**
 * Stops sending output device lelvels to the application layer.
 */
- (NSInteger)stopMonitoringRenderDeviceLevels;

@end
