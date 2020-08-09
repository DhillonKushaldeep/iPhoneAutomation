//
//  CPCRecordingHandler.h
//  CPCAPI2
//
//  Copyright (c) 2014 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCRecordingStopReason : CPCEnumType

+ (instancetype) unknown;
+ (instancetype) noSpace;
+ (instancetype) badFile;

@end



typedef NSInteger CPCRecorderHandle;


/**
 * Contains information about stop reason
 *
 * @param recorder The handle for this particular recorder
 * @param reason The stop reason
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCRecordingStoppedEvent: NSObject

@property(nonatomic, readonly) CPCRecorderHandle recorder;
@property(nonatomic, readonly) CPCRecordingStopReason *reason;

@end



//-------------------- CPCRecordingHandler protocol --------------------------------------------------------------------------


/**
 * Handler for events relating to recording;
 * set in setHandler:
 */
@protocol CPCRecordingHandler <NSObject>
@optional

/**
 * Called when recorder was stopped during recording.
 */
- (void)onRecordingStopped:(CPCRecordingStoppedEvent*)event;

@end


