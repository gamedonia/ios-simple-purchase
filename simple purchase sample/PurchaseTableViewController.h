//
//  PurchaseTableViewController.h
//  simple purchase sample
//
//  Created by Javier Albillos on 9/3/15.
//  Copyright (c) 2015 Gamedonia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GamedoniaSDK/Gamedonia.h>

@interface PurchaseTableViewController : UITableViewController<GamedoniaInAppPurchasesDelegate>
@property (weak, nonatomic) IBOutlet UIProgressView *progressView;
@property (weak, nonatomic) IBOutlet UIButton *driveButton;
@property (weak, nonatomic) IBOutlet UIButton *buyGasButton;
@property (weak, nonatomic) IBOutlet UITextView *textView;

@property (nonatomic, assign) float currentGas;

extern const float GAS_DRIVE_CONSUMPTION_REFILL;

@end