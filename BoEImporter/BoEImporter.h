//
//  BoEImporter.h
//  BoEImporter
//
//  Created by C.W. Betts on 11/25/15.
//
//

#import <Foundation/Foundation.h>
#import "BoEImporterProtocol.h"

// This object implements the protocol which we have defined. It provides the actual behavior for the service. It is 'exported' by the service to make it available to the process hosting the service over an NSXPCConnection.
@interface BoEImporter : NSObject <BoEImporterProtocol>
@end
