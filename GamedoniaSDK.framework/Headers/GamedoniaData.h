//
//  GamedoniaData.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 10/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GamedoniaData : NSObject

- (void) create: (NSString *)collection entity:(NSDictionary *)entity callback:(void (^)(BOOL success, NSDictionary *data))callback;
- (void) remove: (NSString *)collection entityId:(NSString *)entityId callback:(void (^)(BOOL success))callback;
- (void) update: (NSString *)collection entity:(NSDictionary *)entity overwrite:(BOOL)overwrite callback:(void (^)(BOOL success, NSDictionary *data))callback;
- (void) get: (NSString *)collection entityId:(NSString *)entityId callback:(void (^)(BOOL success, NSDictionary *data))callback;
- (void) search:(NSString *)collection query:(NSString *)query callback:(void (^)(BOOL success, NSArray *data))callback;
- (void) search:(NSString *)collection query:(NSString *)query limit:(int)limit callback:(void (^)(BOOL success, NSArray *data))callback;
- (void) search:(NSString *)collection query:(NSString *)query limit:(int)limit sort:(NSString *)sort callback:(void (^)(BOOL success, NSArray *data))callback;
- (void) search:(NSString *)collection query:(NSString *)query limit:(int)limit sort:(NSString *)sort skip:(int)skip callback:(void (^)(BOOL success, NSArray *data))callback;

@end
