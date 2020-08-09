//
//  CPCSipConversationMediaTypes.h
//  CPCObjAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"

/** 
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioCodec : NSObject
@property(nonatomic, readonly) NSInteger plType;
@property(nonatomic, readonly) NSString  *plName;
@property(nonatomic, readonly) NSInteger plFreq;
@property(nonatomic, readonly) NSInteger pacSize;
@property(nonatomic, readonly) NSInteger channels;
@property(nonatomic, readonly) NSInteger rate;
@end

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoCodec : NSObject
@property(nonatomic, readonly) NSString  *plName;
@property(nonatomic, readonly) NSInteger plType;
@property(nonatomic, readonly) NSUInteger width;
@property(nonatomic, readonly) NSUInteger height;
@property(nonatomic, readonly) NSUInteger startBitrate;
@property(nonatomic, readonly) NSUInteger maxBitrate;
@property(nonatomic, readonly) NSUInteger minBitrate;
@property(nonatomic, readonly) NSUInteger maxFramerate;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCIPEndpoint : NSObject
@property(nonatomic, readonly) NSString *ipAddress;
@property(nonatomic, readonly) NSUInteger port;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCStreamStatistics : NSObject
@property(nonatomic, readonly) NSUInteger fractionLost;
@property(nonatomic, readonly) NSUInteger cumulativeLost;
@property(nonatomic, readonly) NSUInteger extendedMax;
@property(nonatomic, readonly) NSUInteger jitterSamples;
@property(nonatomic, readonly) NSInteger rttMs;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCStreamDataCounters : NSObject
@property(nonatomic, readonly) NSUInteger bytesSent;
@property(nonatomic, readonly) NSUInteger packetsSent;
@property(nonatomic, readonly) NSUInteger bytesReceived;
@property(nonatomic, readonly) NSUInteger packetsReceived;
@end

/*
 * Voice Quality Monitoring enabled SDKs only
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXRVoipMetrics : NSObject
@property(nonatomic, readonly) NSUInteger lossRate;
@property(nonatomic, readonly) NSUInteger discardRate;
@property(nonatomic, readonly) NSUInteger burstDensity;
@property(nonatomic, readonly) NSUInteger gapDensity;
@property(nonatomic, readonly) NSUInteger burstDuration;
@property(nonatomic, readonly) NSUInteger gapDuration;
@property(nonatomic, readonly) NSUInteger roundTripDelay;
@property(nonatomic, readonly) NSUInteger endSystemDelay;
@property(nonatomic, readonly) NSUInteger signalLevel;
@property(nonatomic, readonly) NSUInteger noiseLevel;
@property(nonatomic, readonly) NSUInteger RERL;
@property(nonatomic, readonly) NSUInteger Gmin;
@property(nonatomic, readonly) NSUInteger Rfactor;
@property(nonatomic, readonly) NSUInteger extRfactor;
@property(nonatomic, readonly) NSUInteger MOSLQ;
@property(nonatomic, readonly) NSUInteger MOSCQ;
@property(nonatomic, readonly) NSUInteger RXconfig;
@property(nonatomic, readonly) NSUInteger JBnominal;
@property(nonatomic, readonly) NSUInteger JBmax;
@property(nonatomic, readonly) NSUInteger JBabsMax;
@end

 /*
  * Voice Quality Monitoring enabled SDKs only
  */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCXRStatisticsSummary : NSObject
@property(nonatomic, readonly) NSUInteger beginSeq;
@property(nonatomic, readonly) NSUInteger endSeq;
@property(nonatomic, readonly) NSUInteger lostPackets;
@property(nonatomic, readonly) NSUInteger dupPackets;
@property(nonatomic, readonly) NSUInteger minJitter;
@property(nonatomic, readonly) NSUInteger maxJitter;
@property(nonatomic, readonly) NSUInteger meanJitter;
@property(nonatomic, readonly) NSUInteger devJitter;
@property(nonatomic, readonly) NSUInteger minTtlOrHl;
@property(nonatomic, readonly) NSUInteger maxTtlOrHl;
@property(nonatomic, readonly) NSUInteger meanTtlOrHl;
@property(nonatomic, readonly) NSUInteger devTtlOrHl;
@end

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioStatistics : NSObject
@property(nonatomic, readonly) CPCAudioCodec *encoder;
@property(nonatomic, readonly) CPCAudioCodec *decoder;
@property(nonatomic, readonly) CPCStreamStatistics *streamStatistics;
@property(nonatomic, readonly) CPCStreamDataCounters *streamDataCounters;
@property(nonatomic, readonly) NSUInteger maxJitterMs;
@property(nonatomic, readonly) NSUInteger averageJitterMs;
@property(nonatomic, readonly) NSUInteger discardedPackets;
 // Voice Quality Monitoring enabled SDKs only
@property(nonatomic, readonly) CPCXRVoipMetrics *xrVoipMetrics;
 // Voice Quality Monitoring enabled SDKs only
@property(nonatomic, readonly) CPCXRStatisticsSummary *xrStatisticsSummary;
@property(nonatomic, readonly) NSDate *callStartTime;
@property(nonatomic, readonly) CPCIPEndpoint *endpoint;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCRemoteAudioStatistics : NSObject
@property(nonatomic, readonly) NSUInteger sender_SSRC;
@property(nonatomic, readonly) NSUInteger source_SSRC;
@property(nonatomic, readonly) CPCStreamStatistics *streamStatistics;
 // Voice Quality Monitoring enabled SDKs only
@property(nonatomic, readonly) CPCXRVoipMetrics *xrVoipMetrics;
 // Voice Quality Monitoring enabled SDKs only
@property(nonatomic, readonly) CPCXRStatisticsSummary *xrStatisticsSummary;
@property(nonatomic, readonly) CPCIPEndpoint *endpoint;
@end

/**
* A class that contains only properties.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoStatistics : NSObject
@property(nonatomic, readonly) CPCVideoCodec *encoder;
@property(nonatomic, readonly) CPCVideoCodec *decoder;
@property(nonatomic, readonly) CPCStreamStatistics *streamStatistics;
@property(nonatomic, readonly) CPCStreamDataCounters *streamDataCounters;
@property(nonatomic, readonly) NSUInteger totalBitrateSent;
@property(nonatomic, readonly) NSUInteger videoBitrateSent;
@property(nonatomic, readonly) NSUInteger fecBitrateSent;
@property(nonatomic, readonly) NSUInteger nackBitrateSent;
@property(nonatomic, readonly) NSUInteger discardedPackets;
@property(nonatomic, readonly) CPCIPEndpoint *endpoint;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCRemoteVideoStatistics : NSObject
@property(nonatomic, readonly) CPCStreamStatistics *streamStatistics;
@property(nonatomic, readonly) CPCIPEndpoint *endpoint;
@end

/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCAudioJitterBufferStatistics : NSObject
// current jitter buffer size in milliseconds
@property(nonatomic, readonly) NSUInteger currentBufferSizeMs;
// optimal jitter buffer size in milliseconds
@property(nonatomic, readonly) NSUInteger preferredBufferSizeMs;
// true if the jitter buffer has expanded due to bursts of jitter
@property(nonatomic, readonly) BOOL jitterBurstsFound;
// packet loss rate, taking into account packets lost in the
// network and packets discarded by the jitter buffer because they
// are too late (in percent) (in Q14)
@property(nonatomic, readonly) NSUInteger currentEffectivePacketLossRate;
// packet loss rate, taking into account late packets only (in percent) (in Q14)
@property(nonatomic, readonly) NSUInteger currentDiscardRate;
// amount of synthesized audio inserted, expressed as a fraction of the original stream (in Q14)
@property(nonatomic, readonly) NSUInteger currentSynthesizedAudioInsertRate;
// amount of synthesized audio inserted pre-emptively, expressed as a fraction of the original stream (in Q14)
@property(nonatomic, readonly) NSUInteger currentSynthesizedAudioPreemptiveInsertRate;
// amount of audio removed by compressing it in time, expressed as a fraction of the original stream (in Q14)
@property(nonatomic, readonly) NSUInteger currentAccelerateRate;
// clock-drift in parts-per-million (may be negative or positive)
@property(nonatomic, readonly) NSInteger clockDriftPPM;
// average packet waiting time in the jitter buffer in milliseconds
@property(nonatomic, readonly) NSInteger meanWaitingTimeMs;
// median packet waiting time in the jitter buffer in milliseconds
@property(nonatomic, readonly) NSInteger medianWaitingTimeMs;
// minimum packet waiting time in the jitter buffer in milliseconds
@property(nonatomic, readonly) NSInteger minWaitingTimeMs;
// maximum packet waiting time in the jitter buffer in milliseconds
@property(nonatomic, readonly) NSInteger maxWaitingTimeMs;
// number of zeroe'd-out samples added as a result of the jitter buffer's built-in packet loss concealment
@property(nonatomic, readonly) NSInteger addedSamples;
@end


/**
 * A class that contains only properties.
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoJitterBufferStatistics : NSObject
// number of decoded key frames
@property(nonatomic, readonly) NSUInteger numDecodedKeyFrames;
// number of decoded delta frames
@property(nonatomic, readonly) NSUInteger numDecodedDeltaFrames;
// minimum buffer time required for smooth playback in milliseconds
@property(nonatomic, readonly) NSInteger currentBufferSizeMs;
// packet loss rate, taking into account late packets only (in percent) (in Q14)
@property(nonatomic, readonly) NSUInteger currentDiscardRate;
@end
