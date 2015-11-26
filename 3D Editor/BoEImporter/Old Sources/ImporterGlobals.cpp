//
//  ImporterGlobals.cpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#include <stdio.h>
#include "ImporterGlobal.h"

short get_ran (short times,short  min,short  max)
{
	unsigned int store;
	short i, to_ret = 0;
	
	for (i = 1; i < times + 1; i++) {
		store = random() & 0x7fff;
		to_ret = to_ret + min + ((store * (max - min + 1)) / 0x7fff);
	}
	return to_ret;
}

void c2p(Str255 str)
{
	Str255 str2;
	short len;
	
	len = strlen((char *) str);
	strcpy((char *) str2,(char *) str);
	str[0] = (unsigned char) len;
	strncpy((char *) (str + 1), (char *) str2,len);
}

void p2c(Str255 str)
{
	Str255 str2;
	short len = (short) str[0];
	strncpy((char *) str2,(char *) (str + 1), len);
	str2[len] = 0;
	strcpy((char *) str,(char *) str2);
}

// Returns TRUE is this location touches (is not strictly inside of) rectangle
bool loc_touches_rect(location loc,Rect r)
{
	if ((loc.x >= r.left) && (loc.x <= r.right) && (loc.y >= r.top) && (loc.y <= r.bottom))
		return TRUE;
	return FALSE;
}

// Returns TRUE is this location is in the active region of the zone
bool loc_in_active_area(location loc)
{
	return loc_touches_rect(loc,town.in_town_rect);
}

scen_item_data_type scen_data;
zone_names_data_type zone_names;

terrain_type_type get_ter(short which_ter)
{
	terrain_type_type ter;
	ter = scen_data.scen_terrains[which_ter];
	return ter;
}
