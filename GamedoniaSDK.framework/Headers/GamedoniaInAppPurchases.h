//
//  GamedoniaInAppPurchases.h
//  bet2race
//
//  Created by Alberto Xaubet Matesanz on 03/10/12.
//  Copyright (c) 2012 Alberto Xaubet Matesanz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StoreKit/StoreKit.h"
#import "GDPaymentTransaction.h"

#define kProductsLoadedNotification         @"ProductsLoaded"
#define kProductPurchasedNotification       @"ProductPurchased"
#define kProductPurchaseFailedNotification  @"ProductPurchaseFailed"

@protocol GamedoniaInAppPurchasesDelegate <NSObject>

@required
- (void) productsRequested:(NSMutableArray *)productsList;
- (void) productPurchased: (GDPaymentTransaction *) transaction;
- (void) transactionsRestored:(BOOL)status transactions:(NSArray *)transactions;

@end

@interface GamedoniaInAppPurchases : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver> {

    NSSet * _productIdentifiers;
    NSArray * _products;
    NSMutableSet * _purchasedProducts;
    SKProductsRequest * _request;
    
}

@property (retain) NSSet *productIdentifiers;
@property (retain) NSArray * products;
@property (retain) NSMutableSet *purchasedProducts;
@property (retain) SKProductsRequest *request;
@property (weak) id <GamedoniaInAppPurchasesDelegate> delegate;

- (void)requestProducts:(NSSet *)productIdentifiers;
- (id)initWithProductIdentifiers:(NSSet *)productIdentifiers;
- (void)buyProductIdentifier:(NSString *)productIdentifier;
- (BOOL)canMakePayments;
- (void)restorePreviousTransactions;

@end


