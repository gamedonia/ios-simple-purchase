//
//  GamedoniaUsers.h
//  gamedoniasdk
//
//  Created by Alberto Xaubet Matesanz on 05/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDUser.h"
#import "GDSessionToken.h"

@protocol GamedoniaUsersDelegate <NSObject>

- (void) receivedResponse: BOOL;

@end

@protocol GamedoniaUsersEventListener

@required
- (void) onLoginSuccess;

@end

@interface GamedoniaUsers : NSObject {
    
    NSMutableArray * _listeners;
}

@property GDUserProfile *me;
@property GDSessionToken* session_token;

- (BOOL)isLoggedIn;
- (NSString*) getSessionToken;
- (void) createUser: (GDUser *)user callback:(void (^)(BOOL success))callback;
- (void) loginUserWithGameCenterId: (NSString *)gamecenterId callback:(void (^)(BOOL success))callback;
- (void) loginUserWithOpenUDID:(void (^)(BOOL success))callback;
- (void) loginUserWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(BOOL success))callback;
- (void) loginUserWithFacebook:(NSString *)fbuid fbAccessToken:(NSString *)fbAccessToken callback:(void (^)(BOOL success))callback;
- (void) loginUserWithTwitter:(NSString *)twuid twTokenSecret:(NSString *)twTokenSecret twToken:(NSString *)twToken callback:(void (^)(BOOL success))callback;
- (void) loginUserWithSessionToken:(NSString *)sessionToken callback:(void (^)(BOOL success))callback;
- (void) logoutUser:(void (^)(BOOL success))callback;
- (void) getUser:(NSString *)userId callback:(void (^)(BOOL success, GDUserProfile *userProfile))callback;
- (void) getMe:(void (^)(BOOL success, GDUserProfile *userProfile))callback;
- (void) updateUser:(NSDictionary *)profile overwrite:(BOOL)overwrite callback:(void (^)(BOOL success, GDUserProfile *userProfile))callback;
- (void) changePassword:(NSString *)email currentPassword:(NSString *)currentPassword newPassword:(NSString *)newPassword callback:(void (^)(BOOL success))callback;
- (void) resetPassword:(NSString *)email callback:(void (^)(BOOL success))callback;
- (void) restorePassword:(NSString *)restoreToken newPassword:(NSString *)newPassword callback:(void (^)(BOOL success))callback;
- (void) search:(NSString *)query limit:(int)limit callback:(void (^)(BOOL success, NSArray *list))callback;
- (void) search:(NSString *)query limit:(int)limit sort:(NSString *)sort callback:(void (^)(BOOL success, NSArray *list))callback;
- (void) search:(NSString *)query limit:(int)limit sort:(NSString *)sort skip:(int)skip callback:(void (^)(BOOL success, NSArray *list))callback;


/*
 *  Events Listeners
 */

- (void) addEventListener:(NSObject<GamedoniaUsersEventListener> *)listener;
- (void) removeEventListener:(NSObject<GamedoniaUsersEventListener> *)listener;

@end
