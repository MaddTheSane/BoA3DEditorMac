//
//  BoEImporter.m
//  BoEImporter
//
//  Created by C.W. Betts on 11/25/15.
//
//

#import "BoEImporter.h"
#include "ExileCppImporter.h"

@implementation BoEImporter

// This implements the example protocol. Replace the body of this class with the implementation of this service's protocol.
- (void)importBladesOfExileScenarioAtURL:(nonnull NSURL *)boeURL toDestinationURL:(nonnull NSURL*)dest avernumDataURL:(nonnull NSURL*)averURL withReply:(void (^__nonnull)(NSString *__nonnull statusString,NSError *__nullable error))reply;
{
	CFErrorRef theErr = NULL;
	OSStatus iErr = setBladesDirectory((CFURLRef)averURL);
	if (iErr != noErr) {
		reply(@"Unable to change directory", [NSError errorWithDomain:NSOSStatusErrorDomain code:iErr userInfo:nil]);
		return;
	}
	
	bool imported = importBladesOfExileScenario((CFURLRef)boeURL, (CFURLRef)dest, &theErr);
	
	NSString *response = (NSString*)copyStatusString();
	
	clearStatusString();
	
	if (imported) {
		reply(response, nil);
	} else {
		NSAssert(theErr != NULL, @"Error should have been populated.");
		reply(response, (NSError*)theErr);
	}
	[response release];
	if (theErr) {
		CFRelease(theErr);
	}
}

@end
