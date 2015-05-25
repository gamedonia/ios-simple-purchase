//
//  GamedoniaFiles.h
//  GamedoniaSDKSample
//
//  Created by Alberto Xaubet Matesanz on 17/09/13.
//  Copyright (c) 2013 Edenic Games S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DownloadManager.h"

@interface GamedoniaFiles : NSObject {
    DownloadManager *downloadManager;
    NSString *downloadFolder;
    NSMutableArray *downloads;
    int pendingUrlDownloads;
    //NSMutableArray *resolvedDownloadUrls;
}

@property (nonatomic, weak) id<DownloadManagerDelegate> delegate;

- (id)init;
- (void)addDownloadWithFileId:(NSString *)fileId;
- (void)start;
- (void)resume;
- (void)cancelAll;
- (BOOL) hasPendingDownloads;
- (Download *) findDownloadByFileId:(NSString *)fileId;
- (void) setDelegate:(id<DownloadManagerDelegate>)delegate;
- (NSMutableArray *) getResolvedDownloadUrls;
@end
