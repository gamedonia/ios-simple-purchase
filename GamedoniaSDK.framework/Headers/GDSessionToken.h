//
//  GDSessionToken.h
//  gamedoniasdk
//
//  Created by Alberto Xaubet Matesanz on 05/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GDSessionToken : NSObject

@property NSString* session_token;
@property NSString* expiration_date;

- (void) fromJSON:(id)json;
@end
