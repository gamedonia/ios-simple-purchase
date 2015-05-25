//
//  GamedoniaPush.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 04/02/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "GDDeviceProfile.h"

@protocol GamedoniaPushEventListener

@required
- (void) didReceiveRemotePushDeviceToken:(NSString *)deviceToken;

@end


@interface GamedoniaPush : NSObject <GDDeviceDelegate> {
     NSMutableArray * _listeners;
}

- (void)registerDeviceToken:(NSData  *)deviceToken;

/*
 *  Events Listeners
 */

- (void) addEventListener:(NSObject<GamedoniaPushEventListener> *)listener;
- (void) removeEventListener:(NSObject<GamedoniaPushEventListener> *)listener;

@end
