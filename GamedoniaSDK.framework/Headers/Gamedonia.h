//
//  Gamedonia.h
//  gamedoniasdk
//
//  Created by Alberto Xaubet Matesanz on 07/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GamedoniaRequest.h"
#import "GamedoniaUsers.h"
#import "GamedoniaData.h"
#import "GamedoniaDevice.h"
#import "GamedoniaPush.h"
#import "GamedoniaScript.h"
#import "GamedoniaInAppPurchases.h"
#import "GamedoniaFiles.h"
#import "GDOptions.h"

@interface Gamedonia : NSObject


+ (void)initialize: (NSString *) apiKey secret:(NSString *)secret apiServerUrl:(NSString *)apiServerUrl apiVersion:(NSString *)apiVersion;
+ (void)initializeWithOptions: (NSString *) apiKey secret:(NSString *)secret apiServerUrl:(NSString *)apiServerUrl apiVersion:(NSString *)apiVersion options:(GDOptions *)options;

/// ---------------------------------
/// @name Accessing Clients
/// ---------------------------------

/**
 Returns a globally shared instance of GamedoniaUsers.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaUsers *)users;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaUsers *)newUsers;

/**
 Returns a globally shared instance of GamedoniaData.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaData *)data;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaData *)newData;

/**
 Returns a globally shared instance of GamedoniaData.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaDevice *)device;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaDevice *)newDevice;

/**
 Returns a globally shared instance of GamedoniaData.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaPush *)push;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaPush *)newPush;

/**
 Returns a globally shared instance of GamedoniaData.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaScript *)script;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaScript *)newScript;

/**
Returns a globally shared instance of GamedoniaData.

For most simple cases, this is all you will need; if you need your own unique instance,
you should use newUsers instead.
*/
+ (GamedoniaInAppPurchases *)purchase;

/**
 Returns a new instance of GamedoniaUsers.
 */
+ (GamedoniaInAppPurchases *)newPurchase;

/**
 Returns a globally shared instance of GamedoniaFiles.
 
 For most simple cases, this is all you will need; if you need your own unique instance,
 you should use newUsers instead.
 */
+ (GamedoniaFiles *)file;

/**
 Returns a new instance of GamedoniaFiles.
 */
+ (GamedoniaFiles *)newFile;

+ (BOOL)isDebug;

+ (NSOperationQueue *)operationsQueue;

@end
