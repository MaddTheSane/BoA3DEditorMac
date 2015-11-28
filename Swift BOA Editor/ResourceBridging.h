//
//  ResourceBridging.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NSImage;

/// Needed because Apple <i>really</i> doesn't want you using old functions...
@interface ResourceBridging : NSObject
- (nullable instancetype)initWithFileURL:(NSURL*)fileURL error:(NSError**)error;

+ (nullable NSData*)resourceDataFromType:(OSType)type resID:(SInt16)resID;
+ (nullable NSImage*)PICTImageAtResID:(SInt16)resID;

- (nullable NSData *)resourceDataFromType:(OSType)type resID:(SInt16)resID;
- (nullable NSImage*)PICTImageAtResID:(SInt16)resID;


@end

NS_ASSUME_NONNULL_END
