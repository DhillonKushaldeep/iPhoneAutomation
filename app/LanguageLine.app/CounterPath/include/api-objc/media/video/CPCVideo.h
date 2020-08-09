//
//  CPCVideo.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../CPCConfig.h"
#import "CPCVideoHandler.h"
#import "CPCVideoView.h"

typedef NSInteger CPCVideoCaptureResolution;

@interface CPCVideoImageOrientation : CPCEnumType
+ (instancetype) defaultOrientation;
+ (instancetype) portrait;
+ (instancetype) landscape;
@end


@class CPCMediaManager;

/** Manager class for controlling video and video devices; get an instance of 
* the class using the class method getInterface:
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideo : NSObject


@property (nonatomic, readonly) void* object;

@property (nonatomic, readonly) BOOL isCapturing;

+ (CPCVideoCaptureResolution) resolution_Low;
+ (CPCVideoCaptureResolution) resolution_Standard;
+ (CPCVideoCaptureResolution) resolution_High;
+ (CPCVideoCaptureResolution) resolution_MaxSupported;

/**
 * Get a reference to the %Video interface.
 */
+ (CPCVideo*)getInterface:(CPCMediaManager*)manager;


/**
 * Sets the callback handler for audio related events.
 */
- (void)addHandler:(id<CPCVideoHandler>)handler;
- (void)addHandler:(id<CPCVideoHandler>)handler queue:(dispatch_queue_t)queue;
- (void)removeHandler:(id<CPCVideoHandler>)handler;


/**
 * Queries the list of audio capture and playout devices available on the system.
 * The set of devices reported is dependant on OS support.
 * See #AudioHandler::onAudioDeviceListUpdated(..) for the results of the query.
 */
- (void)queryDeviceList;


/**
 * Selects the video capture device used during a video call and for local video preview.
 * The deviceId corresponds to the VideoDeviceInfo::id returned by calling queryDeviceList().
 */
- (NSInteger)setCaptureDevice:(NSUInteger)deviceId;

/**
 * Sets the orientation of the capture device to allow video to be displayed in the correct orientation
 * This is primarily useful on mobile devices
 */
- (NSInteger) setCaptureDeviceOrientation:(CPCVideoOrientation)orientation;

/**
 * Sets the orientation of the image to allow video to be displayed in the correct orientation on remote device
 * This is primarily useful on mobile devices
 */
- (NSInteger) setCaptureImageOrientation:(CPCVideoImageOrientation*)orientation;

/**
 * Specifies the target GUI surface used for rendering the far-end video during a call.
 */
- (NSInteger) setIncomingVideoRenderTarget:(CPCVideoView*)view;

/**
 * Specifies the target GUI surface used for rendering the local capture video during a call.
 */
- (NSInteger) setLocalVideoRenderTarget:(CPCVideoView*)view;

/**
 * Starts capturing from the video capture device specified in #setCaptureDevice(..)
 */
- (NSInteger) startCapture;
- (NSInteger) stopCapture;

/**
 * Specifies the preferred video resolution.  Selecting a higher resolution
 * impacts both CPU usage and bandwidth usage.
 */
- (NSInteger) setPreferredResolution:(CPCVideoCaptureResolution)resolution codec:(NSUInteger)codecId;

/**
 * Queries the list of video codecs available in this version of the SDK.
 * The set of codecs reported is dependant on OS support.
 * See #VideoHandler::onVideoCodecListUpdated(..) for the results of the query.
 */
- (NSInteger)queryCodecList;

/**
 * Enables or disables a codec. Changes take effect for subsequent new incoming/outgoing
 * calls.
 * @param codecId The id of the codec returned by #VideoHandler::onVideoCodecListUpdated(..)
 * @param enabled True to enable the codec, false to disable
 */
- (NSInteger) setCodecEnabled:(NSUInteger)codecId enable:(BOOL)enable;

/**
 * Sets the priority of a codec. Higher value indicates a higher priority codec which should be used if possible
 * @param codecId The id of the codec returned by #VideoHandler::onVideoCodecListUpdated(..)
 * @param priority The priority of the codec. Higher value = greater priority to be used
 */
- (NSInteger) setCodecPriority:(NSUInteger)codecId priority:(NSUInteger)priority;


/**
 * Mutes or unmutes the active video capture device.
 * When video is muted, local preview will still be presented, but
 * the captured video will not be sent to remote participants.
 */
- (NSUInteger) setVideoMute:(BOOL)enabled;

/**
 * Enables or disables a video engine.
 * @param enabled True to enable video engine, false to disable
 */
- (NSUInteger) setVideoApiEnabled:(BOOL)enabled;


- (NSInteger)setVideoDscp:(unsigned int)mediaDscp;

@end
