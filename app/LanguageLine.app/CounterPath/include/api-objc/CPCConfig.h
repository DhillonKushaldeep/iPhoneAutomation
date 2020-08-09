//
//  CPCConfig.h
//  
//
//  Copyright (c) 2013 CounterPath. All rights reserved.
//
//

#ifndef _CPCConfig_h
#define _CPCConfig_h

#if defined(CPCAPI2_BUILD_FOR_SHARED_LIBRARY)
  #define CPCAPI2_SHAREDLIBRARY_OBJC_API __attribute__((visibility("default")))
#else
  #define CPCAPI2_SHAREDLIBRARY_OBJC_API
#endif

#endif
