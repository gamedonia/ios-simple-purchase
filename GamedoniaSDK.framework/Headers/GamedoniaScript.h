//
//  GamedoniaScript.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 18/03/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GamedoniaScript : NSObject

- (void) run: (NSString *)script parameters:(NSDictionary *)parameters callback:(void (^)(BOOL success, NSDictionary *data))callback;

@end
