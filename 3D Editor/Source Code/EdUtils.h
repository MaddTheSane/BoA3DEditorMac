//
//  EdUtils.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef EdUtils_h
#define EdUtils_h

#include <Carbon/Carbon.h>
#include "global.h"

void RedAlert_c (char *theStr);
void RedAlert (char *theStr);
void RedAlert_big_color (char *str1,char *str2,char *str3,char *str4,short num,char *str5,short color);
void RedAlert_big (char *str1,char *str2,char *str3,char *str4,short num,char *str5);
void display_error_dialog(StringPtr theStr,Boolean shut_down);
void ZeroRectCorner (Rect *theRect);
short rect_width (const Rect *theRect);
short rect_height (const Rect *theRect);
Boolean rects_touch(const Rect *r1,const Rect *r2);
short rect_dist(Rect *r1,Rect *r2);
Boolean rect_empty(Rect *r);
Rect rect_union(Rect *r1,Rect *r2);
Rect rect_sect(Rect *r1,Rect *r2);
Boolean r1_in_r2(Rect r1,Rect r2);
Rect rect_centered_around_point(Rect r, location l);
Boolean loc_in_active_area(location loc);
Boolean loc_in_rect(location loc,Rect r);
Boolean loc_touches_rect(location loc,Rect r);
terrain_type_type get_ter(short which_ter);
void ASB (const char *theStr);
void ASB_big (const char *str1,const char *str2,const char *str3,const char *str4,short num,const char *str5);
void ASB_big_color (const char *str1,const char *str2,const char *str3,const char *str4,short num,const char *str5,short dummy);
void CenterRectInRect (Rect *rectA, Rect *rectB);
int coord2Index(int coord, int base, int step);
Rect largestNonOverlapping(Rect bounds, const Rect* obstaclesBegin, const Rect* obstaclesEnd);


#endif /* EdUtils_h */
