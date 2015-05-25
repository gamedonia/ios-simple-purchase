//
//  GDPaymentTransaction.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 10/05/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GDPaymentTransaction : NSObject

@property BOOL* success;
@property NSString* status;
@property NSString* identifier;
@property NSString* transactionId;
@property NSString* receipt;


//@"{'success':true, 'status':'success', 'identifier':'%@', 'message':'', 'transactionId':'%@', 'receipt':'%@'}", transaction.payment.productIdentifier, transaction.transactionIdentifier, receipt];
@end
