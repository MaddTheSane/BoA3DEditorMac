//
//  Graphics.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#ifndef Graphics_h
#define Graphics_h

#include <Carbon/Carbon.h>
#include "ImporterGlobal.h"

Boolean is_field_type(short i,short j,short field_type);
void make_field_type(short i,short j,short field_type);
void take_field_type(short i,short j,short field_type);
Boolean is_oblique_mirror(short i,short j);
void make_oblique_mirror(short i,short j);
void take_oblique_mirror(short i,short j);
Boolean is_facing_mirror(short i,short j);
void make_facing_mirror(short i,short j);
void take_facing_mirror(short i,short j);
Boolean is_web(short i,short j);
void make_web(short i,short j);
void take_web(short i,short j);
Boolean is_crate(short i,short j);
void make_crate(short i,short j);
void take_crate(short i,short j);
Boolean is_barrel(short i,short j);
void make_barrel(short i,short j);
void take_barrel(short i,short j);
Boolean is_fire_barrier(short i,short j);
void make_fire_barrier(short i,short j);
void take_fire_barrier(short i,short j);
Boolean is_force_barrier(short i,short j);
void make_force_barrier(short i,short j);
void take_force_barrier(short i,short j);
Boolean is_blocked(short i,short j);
void make_blocked(short i,short j);
void take_blocked(short i,short j);
Boolean is_sfx(short i,short j,short type);
void make_sfx(short i,short j,short type);
void take_sfx(short i,short j,short type);

#endif /* Graphics_h */
