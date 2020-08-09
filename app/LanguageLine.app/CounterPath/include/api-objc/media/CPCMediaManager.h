//
//  CPCMediaManager.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "../CPCTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCMediaStackSettings : NSObject
{
}

@end


CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCMediaDevicePerformanceProfile : CPCEnumType

+ (instancetype) slowMobile;
+ (instancetype) mobile;
+ (instancetype) desktop;

@end


@class CPCPhone;

/**
* Manager class with generic functionality for controlling
* both audio and video; get an instance of the class using the 
* class method managerForPhone:
*/ 
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCMediaManager : NSObject

@property (nonatomic, readonly) void* object;

/**
 * Get a reference to the MediaManager interface.
 */
+ (CPCMediaManager*)managerForPhone:(CPCPhone*)phone;




/**
 * Ensures that the Media stack has been fully initialized.
 * Must be called from within the main application thread before a SipAccount is enabled.
 * Note that this may trigger a consent prompt requiring
 * the user to allow access to the microphone, speaker, and camera.
 */
- (void)initializeMediaStack;
- (void)initializeMediaStack:(CPCMediaStackSettings*)mediaStackSettings;


/**
 * As soon as the media manager is created you should start processing to recieve events.
 * you can create and set audio and video handlers before starting but notifications
 * will only happen once processing is started
 */
- (void)startProcessing DEPRECATED_MSG_ATTRIBUTE("Use initializeMediaStack instead");

- (void)startProcessing:(CPCMediaStackSettings*)mediaStackSettings DEPRECATED_MSG_ATTRIBUTE("Use initializeMediaStack: instead.");
- (void)updateMediaSettings:(CPCMediaStackSettings*)mediaStackSettings;
/**
 * before application teardown you should stop processing to properly free resopurces.
 */
- (void)stopProcessing DEPRECATED_MSG_ATTRIBUTE("No longer necessary to call");

/**
 * Sets the RTP keep alive interval.  Keep-alives will be send when no media is flowing
 * in order to keep NAT pin holes open.
 */
- (NSInteger) setRtpKeepAliveIntervalSeconds:(NSUInteger)rtpKeepAliveIntervalSeconds;

/**
 * Voice Quality Monitoring enabled SDKs only
 *
 * Enables reporting and processing of statistics summary report blocks,
 * as defined in RFC 3611 section 4.6.
 * @see struct XRStatisticsSummary in SipConversationMediaTypes.h
 */
- (NSInteger) setRtcpXrStatisticsSummaryReportsEnabled:(BOOL)enabled;

/**
 * Voice Quality Monitoring enabled SDKs only
 *
 * Enables reporting and processing of VoIP metrics report blocks,
 * as defined in RFC 3611 section 4.7.
 * @see struct XRVoipMetrics in SipConversationMediaTypes.h
 */
- (NSInteger) setRtcpXrVoIPMetricsReportsEnabled:(BOOL)enabled;

/**
 * Enable or disable Music On Hold feature.
 */
- (NSInteger) setMoHEnabled:(BOOL)enabled;

/**
 * Specifies a device performance profile, used to tune settings such as
 * codec computational complexity and maximum resolution.
 */
- (NSInteger) setDevicePerformanceProfile:(CPCMediaDevicePerformanceProfile*)profile;


@end
