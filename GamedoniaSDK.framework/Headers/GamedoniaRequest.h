//
//  GamedoniaRequest.h
//  gamedoniasdk
//
//  Created by Alberto Xaubet Matesanz on 07/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

#define GD_APIKEY           @"X-Gamedonia-ApiKey"
#define GD_SIGNATURE        @"X-Gamedonia-Signature"
#define GD_SESSION_TOKEN    @"X-Gamedonia-SessionToken"
#define GD_AUTH             @"Authorization"
#define GD_DATE             @"Date"
#define GD_GAMEID           @"gameid"
#define GD_CONTENT_TYPE     @"application/json"

@interface GamedoniaRequest : NSObject

+ (void) initialize: (NSString *) apiKey secret:(NSString *)secret apiServerUrl:(NSString *)apiServerUrl apiVersion:(NSString *)apiVersion;

+ (void) post: (NSString *)url content:(NSString *)content success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

+ (void) post: (NSString *)url content:(NSString *)content auth:(NSString *)auth sessionToken:(NSString *)sessionToken gameid:(NSString *)gameid success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success
      failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

+ (void) get: (NSString *)url sessionToken:(NSString *)sessionToken success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success
      failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

+ (void) put: (NSString *)url content:(NSString *)content auth:(NSString *)auth sessionToken:(NSString *)sessionToken gameid:(NSString *)gameid success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success
      failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

+ (void) del: (NSString *)url success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

//+ (void) get: (NSString *) url;

+ (NSString *) md5: (NSString *)input;

+ (NSString *) hmacsha1: (NSString *)data secret:(NSString *)secret;

+ (NSString *) getCurrentDate;

+ (NSString *) sign: (NSString *)apiKey secret:(NSString *)secret data:(NSString *)data contentType:(NSString *)contentType date:(NSString *)date requestMethod:(NSString *)requestMethod path:(NSString *)path;

+ (NSString *) sign: (NSString *)apiKey secret:(NSString *)secret date:(NSString *)date requestMethod:(NSString *)requestMethod path:(NSString *)path;


@end
