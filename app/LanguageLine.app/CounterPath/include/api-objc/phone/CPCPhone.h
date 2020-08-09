//
//  CPCPhone.h
//  CPCAPI2
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "../CPCConfig.h"
#import "CPCPhoneErrorHandler.h"

enum CPCLogLevel
{
	ECPCLogLevel_None = 0,
	ECPCLogLevel_Error,
	ECPCLogLevel_Warning,
	ECPCLogLevel_Info,
	ECPCLogLevel_Debug,
	ECPCLogLevel_Max
};
/**
* Protocol which defines a method that will be called for each SDK diagnostic log message the SDK outputs.
* Note: The instance of %CPCPhoneLogger should be prepared to receive calls on a thread the SDK
* creates and dedicates to logging, i.e. not a main or UI thread.
*/
@protocol CPCPhoneLogger <NSObject>
- (BOOL) log:(enum CPCLogLevel)level subsystem:(NSString *)subsystem appName:(NSString *)appName file:(NSString *)file line:(NSInteger)line message:(NSString *)message messageWithHeaders:(NSString *)messageWithHeaders;
@end


/**
 * SDK licensing data passed in CPCPhone's initialize(..) method
 */
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCPhoneLicenseInfo : NSObject

@property (nonatomic, copy) NSString* licenseKey; // The license key
@property (nonatomic, copy) NSString* licenseDocumentLocation; // Location for the license file (mandatory if license key is provided).
@property (nonatomic, copy) NSString* licenseAor; // Licensing identifier (optional).

@end


/**
* Manager class that is the main entry point to the SDK; get an instance of 
* the class using the class method create: Create only one instance.
*/
CPCAPI2_SHAREDLIBRARY_OBJC_API @interface CPCPhone : NSObject

@property (nonatomic, assign) void* object;  // CPCAPI2::Phone c++ class


/**
 * Create the %Phone object.
 */
+ (CPCPhone*)create;


/**
 * Initialize SDK-wide functionality, such as logging.
 * This method should be called immediately after creating an instance of %Phone.
 * @param licenseInfo contains data used to validate licensing of the SDK
 * @param errorHandler a global error handler used anywhere that an error occurs in the phone without having a known context
 * or to report license validation errors.
 */
- (NSInteger)initialize:(CPCPhoneLicenseInfo*)licenseInfo errorHandler:(id<CPCPhoneErrorHandler>)errorHandler;


/**
 * Initialize SDK-wide functionality, such as logging.
 * This method should be called immediately after
 * creating an instance of %Phone.
 */
- (NSInteger)initialize:(NSString*)licenseKey licenseDocumentLocation:(NSString*)licenseDocumentLocation DEPRECATED_MSG_ATTRIBUTE("Use the version of initialize that takes the LicenseInfo parameter.");
- (NSInteger)initialize:(NSString*)licenseKey licenseDocumentLocation:(NSString*)licenseDocumentLocation licenseAor:(NSString*)licenseAor DEPRECATED_MSG_ATTRIBUTE("Use the version of initialize that takes the LicenseInfo parameter.");


/**
 * Enables or disables the diagnostic logging for all SDK modules.
 * @param enabled YES to enable logging
 * @param id A meaningful identifier that will become part of the log file name
 */
- (NSInteger) setLoggingEnabled:(BOOL)enabled identifier:(NSString*)identifier;

/**
 * Enables or disables the the diagnostic logging to a callback, for all SDK modules.
 * @param enabled YES to enable logging
 * @param logger An instance of %CPCPhoneLogger, that will consume SDK diagnostic log callbacks.
 */   
- (NSInteger) setLoggingEnabled:(BOOL)enabled logger:(id<CPCPhoneLogger>)logger;

/**
 * NOTE: setting string conversion function is not supported in Obj-C
 */

/*
 * Provides instanceID as per https://tools.ietf.org/html/rfc5626#section-4.1
 */
- (NSString*) getInstanceId;

@end
