//
//  PurchaseTableViewController.m
//  simple purchase sample
//
//  Created by Javier Albillos on 9/3/15.
//  Copyright (c) 2015 Gamedonia. All rights reserved.
//

#import "PurchaseTableViewController.h"
#import <GamedoniaSDK/Gamedonia.h>
#import <GamedoniaSDK/OpenUDID.h>

const float GAS_DRIVE_CONSUMPTION_REFILL = 0.25;

@interface PurchaseTableViewController ()

@end

@implementation PurchaseTableViewController

- (void) viewDidLoad {
    
    [super viewDidLoad];
    
    _currentGas = 0.5f;
    [self.progressView setProgress:0.5f animated:NO];
    
    UIColor *greenColor = [UIColor alloc];
    greenColor = [UIColor colorWithRed:(110.0/255.f)
                                 green:(172.0/255.f)
                                  blue:(43.0/255.f)
                                 alpha:1.0f];
    [self.progressView setProgressTintColor:greenColor];
    
    
    // Background
    float grey = (float) 238/255.0f;
    self.view.backgroundColor = [UIColor colorWithRed:(grey)
                                                green:(grey)
                                                 blue:(grey)
                                                alpha:1.0f];
    
    UIImageView *CurrentImage = [UIImageView alloc];
    CurrentImage = [CurrentImage initWithImage:[UIImage imageNamed:@"background"]];
    CurrentImage.frame = self.view.bounds;
    
    [self.tableView setBackgroundView:CurrentImage];
    
    
    // Register as delegate
    [Gamedonia purchase].delegate = self;
    
    
    // Authentication
    
    NSString *ses_token = [NSString alloc];
    ses_token = [[Gamedonia users] getSessionToken];
    
    if (ses_token != nil) {
        
        [[Gamedonia users] loginUserWithSessionToken:ses_token callback:^(BOOL success) {
            
            if (success) {
                
                [self processLogin];
            }
            else {
                
                NSLog(@"No active session token detected.");
            }
        }];
        
        
    }
    else {
        
        NSString* openUDID = [OpenUDID value];
        
        GDUser * user = [GDUser alloc];
        Credentials *credentials = [[Credentials alloc] init];
        [credentials setOpen_udid:openUDID];
        user.credentials = credentials;
        
        [[Gamedonia users] createUser:user callback:^(BOOL success) {
            
            [self printText:@"Starting session with Gamedonia..."];
            
            [[Gamedonia users] loginUserWithOpenUDID:^(BOOL log_success) {
                
                if (log_success) {
                    
                    [self processLogin];
                    
                } else {
                    
                    NSLog(@"Login failed");
                }
            }];
        }];
        
        
    }
}


- (void) didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) processLogin {
    
    [[Gamedonia users] getMe:^(BOOL getme_success, GDUserProfile *userProfile) {
        if(getme_success){
            
            NSString *uid = [NSString alloc];
            uid = [[Gamedonia users].me _id];
            [self printText:[self concatenate:@"Session started successfully:\nuid: " with:uid]];
            
            NSSet *productsList = [NSSet setWithObject:@"gas"];
            
            [[Gamedonia purchase] requestProducts:productsList];
            
        }
        else{
            
            NSLog(@"Get me call failed.");
        }
    }];
    
}

-(void) updateGas:(float)value {
    
    float result = _currentGas + value;
    
    if(result <= 0.0f) {
        
        _currentGas = 0.0f;
        
    } else if(result >= 1.0f) {
        
        _currentGas = 1.0f;
        
    } else {
        
        _currentGas = result;
    }
    
    [self.progressView setProgress:_currentGas animated:YES];
}

- (IBAction) clickDrive:(id)sender {
    
    if(_currentGas <= 0.0f) {
        
        [self printText:@"Out of GAS! Purchase more please!"];
    }
    else {
        
        [self updateGas:-GAS_DRIVE_CONSUMPTION_REFILL];
    }
}

- (IBAction) clickBuyGas:(id)sender {
    
    if(_currentGas < 1.0f){
        
        [[Gamedonia purchase] buyProductIdentifier:@"gas"];
    }
    else {
        
        [self printText:@"Already full of gas! Drive to spend some"];
    }
}

- (void) productsRequested:(NSMutableArray *)productsList {
    
    NSLog(@"Products have been requested.");
}

- (void) productPurchased: (GDPaymentTransaction *) transaction {
    
    if (transaction.success) {
        
        [self updateGas:GAS_DRIVE_CONSUMPTION_REFILL];
    
        [self printText:@"GAS refilled!"];
    }
}

- (void) transactionsRestored:(BOOL)status transactions:(NSArray *)transactions {
    
    NSLog(@"Transactions restored.");
}




-(NSString*) concatenate:(NSString*)string1 with:(NSString*)string2 {
    
    NSMutableString* result = [NSMutableString stringWithString: string1];
    [result appendString: string2];
    NSString *res_string = result;
    
    return res_string;
}

-(void) printText:(NSString *)text {
    
    NSString *result = [NSString alloc];
    result = [self concatenate: _textView.text with:text];
    result = [self concatenate:result with:@"\n\n"];
    _textView.text = result;
    
    NSRange range = NSMakeRange(_textView.text.length - 1, 1);
    [_textView scrollRangeToVisible:range];
    
}

- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [super tableView:tableView cellForRowAtIndexPath:indexPath];
    cell.backgroundColor = [UIColor clearColor];
    
    return cell;
}



@end
