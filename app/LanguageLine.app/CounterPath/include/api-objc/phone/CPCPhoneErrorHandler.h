//
//  CPCPhoneErrorHandler.h
//  CPCObjAPI2
//
//  Copyright (c) 2015 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCTypes.h"

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCPhoneErrorEvent : NSObject

@property (nonatomic, readonly) NSString* errorText;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCPhoneLicenseErrorReason : CPCEnumType

+ (CPCPhoneLicenseErrorReason*) reasonInvalid;
+ (CPCPhoneLicenseErrorReason*) reasonExpired;
+ (CPCPhoneLicenseErrorReason*) reasonRejected;
+ (CPCPhoneLicenseErrorReason*) reasonServerError;
+ (CPCPhoneLicenseErrorReason*) reasonUnknown;

@end

CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCPhoneLicenseErrorEvent : NSObject

@property (nonatomic, readonly) NSString* errorText;
@property (nonatomic, readonly) CPCPhoneLicenseErrorReason *licenseErrorReason;

@end


@protocol CPCPhoneErrorHandler

/**
 * Indicates that a general error on the phone has occurred but the error did not trigger a more specific onError event
 */
- (void) onError:(NSString*)sourceModule phoneErrorEvent:(CPCPhoneErrorEvent*)phoneErrorEvent;
	
/**
 * Indicates that an error has occurred while validating the license data. The SDK instance is no longer usable and should be destroyed.
 */
- (void) onLicensingError:(CPCPhoneLicenseErrorEvent*)licensingErrorevent;

@end
