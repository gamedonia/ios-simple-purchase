//
//  GamedoniaDevice.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 01/02/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GamedoniaUsers.h"
#import "GamedoniaPush.h"
#import "GDDeviceProfile.h"

@interface GamedoniaDevice : NSObject <GamedoniaUsersEventListener, GamedoniaPushEventListener>

@property GDDeviceProfile *_device;

-(id)init;
-(void) registerDevice:(GDDeviceProfile *)device callback:(void (^)(BOOL success))callback;

@end



