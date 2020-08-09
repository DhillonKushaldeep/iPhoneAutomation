//
//  CPCVideoView.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#if TARGET_OS_IPHONE

#import <UIKit/UIKit.h>


@interface CPCVideoView : UIView

@property(nonatomic, readonly) UIView *rendererView;
@property(nonatomic, readonly) NSTimeInterval lastFrameTimeStamp;
@property(nonatomic, readonly) BOOL displaysVideoPreview;
@property(nonatomic, readwrite) CGSize preferredVideoPreviewSize;

@end

#elif TARGET_OS_MAC

#import <AppKit/AppKit.h>
#import "../../CPCConfig.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCVideoView : NSView
{
	CALayer *_rendererView;
}

@property(nonatomic, readonly) CALayer *rendererView;
@property (atomic, assign, getter=isFlipped) BOOL flipped;
@property (nonatomic, assign) BOOL mirrored;
@property (nonatomic, readonly) NSInteger videoWidth;
@property (nonatomic, readonly) NSInteger videoHeight;
@property (nonatomic, readonly) CGFloat frameRate;
@property (nonatomic, readonly) NSTimeInterval timeSinceLastRender;
@end

#endif
