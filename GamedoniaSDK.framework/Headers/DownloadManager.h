#import <Foundation/Foundation.h>
#import "Download.h"

@class DownloadManager;
@class Download;

/** This delegate protocol informs the `delegate` regarding the success or failure of the downloads.
 *
 * @see DownloadManager
 * @see Download
 * @see delegate
 */

@protocol DownloadManagerDelegate <NSObject>

@optional

/** Informs the delegate that all downloads have finished (whether successfully or unsuccessfully).
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @see DownloadManager
 */

- (void)didFinishLoadingAllForManager:(DownloadManager *)downloadManager;


/** Informs the delegate that all downloads have started (whether successfully or unsuccessfully).
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @see DownloadManager
 */
- (void)didStartLoadingAllFormManager:(DownloadManager *)downloadManager;

/** Informs the delegate that a particular download has finished successfully.
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @param download
 *
 * The individual `Download`.
 *
 * @see DownloadManager
 * @see Download
 */

- (void)downloadManager:(DownloadManager *)downloadManager downloadDidFinishLoading:(Download *)download;

/** Informs the delegate that a particular download has failed.
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @param download
 *
 * The individual `Download`.
 *
 * @see DownloadManager
 * @see Download
 */

- (void)downloadManager:(DownloadManager *)downloadManager downloadDidFail:(Download *)download;

/** Informs the delegate of the status of a particular download that is in progress.
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @param download
 *
 * The individual `Download`.
 *
 * @see DownloadManager
 * @see Download
 */

- (void)downloadManager:(DownloadManager *)downloadManager downloadDidReceiveData:(Download *)download;


/** Informs the delegate that a download has started
 *
 * @param downloadManager
 *
 * The `DownloadManager` that is performing the downloads.
 *
 * @param download
 *
 * The individual `Download`.
 *
 * @see DownloadManager
 * @see Download
 */
- (void)downloadManager:(DownloadManager *)downloadManager downloadDidStart:(Download *)download;

@end

/** While the `Download` class downloads individual files, `DownloadManager` allows 
 * you to coordinate multiple downloads. If you use this `DownloadManager` class, 
 * you do not have to interact directly with the `Download` class (other than 
 * optionally inquiring about the progress of the downloads in the `DownloadManagerDelegate` 
 * methods).
 *
 * @see DownloadManagerDelegate
 * @see Download
 */

@interface DownloadManager : NSObject

/// @name Initialization

/** Returns pointer to initialized `DownloadManager` object.
 *
 * @param delegate
 *
 * The delegate that conforms to `DownloadManagerDelegate` which will receive 
 * information regarding the progress of the downloads.
 *
 * @return
 *
 * Returns pointer to `DownloadManager` object. If error, this is `nil`.
 *
 * @see DownloadManagerDelegate
 */

- (id)initWithDelegate:(id<DownloadManagerDelegate>)delegate;

/// @name Control Download Manager

/** Add a download to the manager.
 *
 * @param filename
 *
 * The name of the local filename to where the file should be copied.
 *
 * @param url
 *
 * The remote URL of the source from where the file should be copied.
 *
 * @see filename
 * @see url
 */

- (Download *)addDownloadWithFilename:(NSString *)filename URL:(NSURL *)url fileId:(NSString *)fileId;

/// Starts the queued downloads.

- (void)start;

/// Cancel all downloads in progress or pending.

- (void)cancelAll;

- (Download *) findDownloadByFileId:(NSString *)fileId;

/// @name Properties

/** The maximum number of permissible number of concurrent downloads.
 * Many servers limit the number of concurrent downloads (4 or 6 are common)
 * and failure to observe this threshold will result in failures. Good
 * common practice is to set this to be 4.
 */

@property NSInteger maxConcurrentDownloads;

/** The array of `Download` objects representing the list of the ongoing or pending downloads.
 *
 * @see Download
 */

@property (nonatomic, strong) NSMutableArray *downloads;

/** The delegate object that this class notifies regarding the progress of the individual downloads.
 *
 * @see DownloadManagerDelegate
 */

@property (nonatomic, weak) id<DownloadManagerDelegate> delegate;

@end
