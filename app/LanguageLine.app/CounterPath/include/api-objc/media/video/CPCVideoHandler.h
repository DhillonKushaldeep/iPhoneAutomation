//
//  CPCAudioHandler.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../../CPCConfig.h"


//-------------------- Video Device Info -------------------------------------------------------------------------------

typedef NSInteger CPCVideoOrientation;


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoDeviceInfo : NSObject

@property (nonatomic, readonly) NSString* friendlyName;
@property (nonatomic, readonly) NSUInteger deviceID;
@property (nonatomic, readonly) CPCVideoOrientation orientation;
@property (nonatomic, readonly) NSUInteger cameraIndex;

+ (CPCVideoOrientation) videoOrientation_0;
+ (CPCVideoOrientation) videoOrientation_90;
+ (CPCVideoOrientation) videoOrientation_180;
+ (CPCVideoOrientation) videoOrientation_270;

@end

/**
* Event passed in onVideoDeviceListUpdated: in 
* the <CPCVideoHandler> formal protocol. 
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoDeviceListEvent : NSObject

@property (nonatomic, readonly) NSArray* deviceList;

@end



//-------------------- Video Codec Info --------------------------------------------------------------------------------


/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoCodecInfo : NSObject

@property (nonatomic, readonly) NSString* codecName;
@property (nonatomic, readonly) NSUInteger codecID;
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic, readonly) NSUInteger minBandwidth;
@property (nonatomic, readonly) NSUInteger maxBandwidth;
@property (nonatomic, readonly) NSUInteger priority;

@end

/**
* Event passed in onVideoCodecListUpdated: in 
* the <CPCVideoHandler> formal protocol. 
*/ 
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoCodecListEvent : NSObject

@property (nonatomic, readonly) NSArray* codecList;

@end



//-------------------- Video Handler Protocol --------------------------------------------------------------------------

/**
* Handler for events relating to video and video devices; 
* set in addHandler: in the Video class.
*/ 
@protocol CPCVideoHandler <NSObject>
@optional
/**
 * Called when the list of media devices on the system changes, or as a result of
 * calling #CPCVideo: -(void)queryDeviceList;
 */
- (void)onVideoDeviceListUpdated:(CPCVideoDeviceListEvent*)event;

/**
 * Called as a result of calling #CPCVideo: -(void)queryCodecList;
 */
- (void)onVideoCodecListUpdated:(CPCVideoCodecListEvent*)event;

@end


