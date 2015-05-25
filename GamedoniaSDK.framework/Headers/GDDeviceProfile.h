//
//  GDDeviceProfile.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 01/02/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface GDDeviceProfile : NSObject

@property NSString* deviceId;
@property NSString* deviceToken;
@property NSString* deviceType;
@property NSString* uid;
@property NSString* language;
@property NSString* country;
@property NSNumber* timeZoneGMTOffset;

- (NSDictionary *) toDictionary;
- (void) fromJSON:(id)JSON;

@end


/*
 * Protocol definitions
 */

@protocol GDDeviceDelegate <NSObject>

@optional
-(void)buildGDDeviceProfile:(GDDeviceProfile *)device;

@end
