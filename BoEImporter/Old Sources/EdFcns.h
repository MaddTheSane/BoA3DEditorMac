//
//  EdFcns.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#ifndef EdFcns_h
#define EdFcns_h

#include <Carbon/Carbon.h>

#include "ImporterGlobal.h"

bool create_new_item(short item_to_create, location create_loc, Boolean property, item_type *i_to_make);
bool create_new_ter_script(const char* ter_script_name,location create_loc,in_town_on_ter_script_type* script_to_make);
void set_up_lights();
void set_all_items_containment();

short get_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_se_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_se_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);


#endif /* EdFcns_h */
