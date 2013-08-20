//
//  CJAMacros.h
//  CJAMacros
//
//  Created by Carl Jahn
//  Copyright (c) 2013 Carl Jahn. All rights reserved.
//

#import <Foundation/Foundation.h>

///---------------------------
/// @name Logs
///---------------------------

/**
 Shortcuts for NSLogs(...). Also includes the current __FUNCTION__
 */
#define kNSLogFunctionWithObject(_object) NSLog(@"%s %@", __FUNCTION__, [_object description]);
#define kNSLogFunction kNSLogFunctionWithObject(@"")

/**
 Special ErrorLog. 
 You can use this function to Log in Release Mode
 @param format - The same format as you should use in NSLog(...)
 */
void ErrorLog(NSString *format, ...); //The Error-Log also Outputs in the relase Vesion

/**
 DEBUG and RELEASE settings for the Log Macros
 Note: The ErrorLog Function is always available. Normal NSLog stripped out in RELEASE mode
 */
#ifdef DEBUG
  #define ELog 1
#else
  #define ELog 1
  #define NSLog(format, ...)
#endif

///---------------------------
/// @name Localization
///---------------------------

/**
 Simple Shortcut for your NSLocalizedString(@"..", @"..")
 */
#define _(_key) NSLocalizedString( _key , nil);


///---------------------------
/// @name NSNotificationCenter
///---------------------------

/**
  Shortcut for [[NSNotificationCenter ...] postNotificationName: ...]
  @param notificationName - The notification name you want to post
  @param obj - The object for the notification
  @param userInfoDictionary - The NSDictionary for the userInfo
 */
#define notify(_notificationName, _obj, _userInfoDictionary) [[NSNotificationCenter defaultCenter] postNotificationName: _notificationName object: _obj userInfo: _userInfoDictionary];

/**
 Shortcut for [[NSNotificationCenter ...] addObserver: ...]
 @param notificationName - The notification name you want to post
 @param observer - The observer object
 @param observerSelector - The current selector for the notificaton
 */
#define addObserver(_notificationName, _observer, _observerSelector, _obj) [[NSNotificationCenter defaultCenter] addObserver:_observer selector:@selector(_observerSelector) name:_notificationName object: _obj];

/**
 Shortcut for [[NSNotificationCenter ...] removeObserver: ...]
 @param observer - The observer object that should be remove from the NSNotificationCenter
 */
#define removeObserver(_observer) [[NSNotificationCenter defaultCenter] removeObserver: _observer];


///---------------------------
/// @name Main Thread
///---------------------------

/**
 Shortcut for perform a code snippet on the main thread
 @lambda - your code snippet that shuld execute on the main thread
 */
#define onMainThread(_lambda) \
if([NSThread isMainThread]){ \
_lambda \
} else { \
dispatch_async(dispatch_get_main_queue(), ^{ \
_lambda \
}); \
}

///---------------------------
/// @name Runtime Checks
///---------------------------

 
//If the symbol for iOS 5 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_5_0
#define NSFoundationVersionNumber_iOS_5_0 881.00
#define _iOS_5_0 NSFoundationVersionNumber_iOS_5_0
#endif

//If the symbol for iOS 5.1 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_5_1
#define NSFoundationVersionNumber_iOS_5_1 890.10
#define _iOS_5_1 NSFoundationVersionNumber_iOS_5_1
#endif

//If the symbol for iOS 6.0 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_6_0
#define NSFoundationVersionNumber_iOS_6_0 993.00
#define _iOS_6_0 NSFoundationVersionNumber_iOS_6_0
#endif

//If the symbol for iOS 6.1 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_6_1
#define NSFoundationVersionNumber_iOS_6_1 993.00
#define _iOS_6_1 NSFoundationVersionNumber_iOS_6_1
#endif

//If the symbol for iOS 7 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_7_0
#define NSFoundationVersionNumber_iOS_7_0 1047.00
#define _iOS_7_0 NSFoundationVersionNumber_iOS_7_0
#endif

/**
 Runtime check for the current version Nummer. 
 checks ( CURRENT_VERSION_NUMBR == GIVEN_VERSION_NUMBER)
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on) 
 */
#define SYSTEM_VERSION_EQUAL_TO(_gVersion)                  ( floor(NSFoundationVersionNumber) == _gVersion ? YES : NO )

/**
 Runtime check for the current version Nummer. 
 checks CURRENT_VERSION_NUMBER > GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_GREATER_THAN(_gVersion)              ( floor(NSFoundationVersionNumber) >  _gVersion ? YES : NO )

/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER >= GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(_gVersion)  ( floor(NSFoundationVersionNumber) >= _gVersion ? YES : NO )


/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER < GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_LESS_THAN(_gVersion)                 ( floor(NSFoundationVersionNumber) <  _gVersion ? YES : NO )


/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER <= GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(_gVersion)     ( floor(NSFoundationVersionNumber) <= _gVersion ? YES : NO )