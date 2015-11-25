//
//  ResourceBridging.m
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#import "ResourceBridging.h"
#include <Carbon/Carbon.h>
#import <Cocoa/Cocoa.h>

@implementation ResourceBridging
{
	ResFileRefNum resourceRef;
}

- (nullable instancetype)initWithFileURL:(NSURL*)fileURL error:(NSError**)error
{
	if (self = [super init]) {
		FSRef aRef;
		HFSUniStr255 rsrcForkName;
		FSGetResourceForkName(&rsrcForkName);
		if (CFURLGetFSRef((CFURLRef)fileURL, &aRef) == false) {
			if (error) {
				*error = [NSError
						  errorWithDomain:NSCocoaErrorDomain code:NSFileReadInvalidFileNameError userInfo:
						  @{NSLocalizedFailureReasonErrorKey: @"Could not resolve URL to FSRef",
							NSURLErrorKey: fileURL,
							}];
			}
			return nil;
		}
		OSErr iErr = FSOpenResourceFile(&aRef, rsrcForkName.length, rsrcForkName.unicode, fsRdPerm, &resourceRef);
		if (iErr != noErr) {
			if (error) {
				*error = [NSError errorWithDomain:NSOSStatusErrorDomain code:iErr userInfo:nil];
			}
			return nil;
		}
	}
	return self;
}

+ (nullable NSData*)resourceDataFromType:(OSType)type resID:(SInt16)resID;
{
	return nil;
}

+ (nullable NSImage*)PICTImageAtResID:(SInt16)resID
{
	NSData *pictData = [self resourceDataFromType:'PICT' resID:resID];
	if (pictData == nil) {
		return nil;
	}
	if (![NSPICTImageRep canInitWithData:pictData]) {
		return nil;
	}
	NSPICTImageRep *aPict = [[NSPICTImageRep alloc] initWithData:pictData];
	if (aPict == nil) {
		return nil;
	}
	NSImage *anImg = [[NSImage alloc] initWithSize:NSMakeSize(aPict.pixelsWide, aPict.pixelsHigh)];
	[anImg addRepresentation:aPict];
	
	return anImg;
}

- (void)dealloc
{
	if (resourceRef != -1)
	FSCloseFork(resourceRef);
}
@end
