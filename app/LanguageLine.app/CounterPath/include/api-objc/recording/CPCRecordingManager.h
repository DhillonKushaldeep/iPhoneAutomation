//
//  CPCRecordingManager.h
//  CPCAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCTypes.h"
#import "CPCRecordingHandler.h"

@class CPCPhone;

/**
 * Manager controlling recording
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCRecordingManager : NSObject

/**
 * Get a reference to the Recording Manager interface.
 */
+ (CPCRecordingManager*)managerForPhone:(CPCPhone*)phone;

/**
 * Set the handler for events on the specified recorder.
 */
- (void) addHandler:(id<CPCRecordingHandler>)handler recorder:(CPCRecorderHandle)recorder;
- (void) addHandler:(id<CPCRecordingHandler>)handler recorder:(CPCRecorderHandle)recorder queue:(dispatch_queue_t)queue;
- (void) removeHandler:(id<CPCRecordingHandler>)handler recorder:(CPCRecorderHandle)recorder;

/**
 * Creates new recorder and returns recorder handle.
 * @param filePath path to destination file
 */
- (CPCRecorderHandle) audioRecorderCreate:(NSString*)filePath;

/**
 * Adds conversation to recorder.
 * @param recorder recorder handle
 * @param conversation conversation handle
 */
- (NSInteger) recorder:(CPCRecorderHandle)recorder addConversation:(CPCSipConvConversationHandle)conversation;

/**
 * Removes conversation from recorder.
 * @param recorder recorder handle
 * @param conversation conversation handle
 */
- (NSInteger) recorder:(CPCRecorderHandle)recorder removeConversation:(CPCSipConvConversationHandle)conversation;

/**
 * Starts recording.
 * @param recorder recorder handle
 */
- (NSInteger) recorderStart:(CPCRecorderHandle)recorder;

/**
 * Pauses recording.
 * @param recorder recorder handle
 */
- (NSInteger) recorderPause:(CPCRecorderHandle)recorder;

/**
 * Stops recording and destroys recorder.
 * @param recorder recorder handle
 */
- (NSInteger) recorderDestroy:(CPCRecorderHandle)recorder;


/**
 * As soon as the recording manager is created you should start processing to recieve events.
 * you can create and set audio and video handlers before starting but notifications
 * will only happen once processing is started
 */
- (void)startProcessing DEPRECATED_MSG_ATTRIBUTE("No longer necessary to call.");

/**
 * before application teardown you should stop processing to properly free resopurces.
 */
- (void)stopProcessing DEPRECATED_MSG_ATTRIBUTE("No longer necessary to call.");


@end
