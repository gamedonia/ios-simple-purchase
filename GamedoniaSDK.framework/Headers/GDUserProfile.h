//
//  GDUserProfile.h
//  gamedoniasdk
//
//  Created by Alberto Xaubet Matesanz on 05/11/12.
//  Copyright (c) 2012 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GDUserProfile : NSObject

@property NSString* _id;
@property NSMutableDictionary* profile;

- (NSDictionary *) toDictionary;
- (void) fromJSON:(id)JSON;

@end
