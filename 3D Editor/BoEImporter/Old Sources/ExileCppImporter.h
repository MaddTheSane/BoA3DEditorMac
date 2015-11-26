//
//  ExileCppImporter.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#ifndef ExileCppImporter_h
#define ExileCppImporter_h

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

bool importBladesOfExileScenario(CFURLRef oldBoE, CFURLRef newBoA, CFErrorRef *error);



#ifdef __cplusplus
}
#endif

#endif /* ExileCppImporter_h */
