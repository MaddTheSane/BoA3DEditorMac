//
//  Graphics.cpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#include "Graphics.h"

//determines if the given field type exists at the given coordinates
Boolean is_field_type(short i,short j,short field_type)
{
	short k;
	
	for (k = 0; k < NUM_TOWN_PLACED_FIELDS; k++){
		if ((town.preset_fields[k].field_type == field_type) &&
			(town.preset_fields[k].field_loc.x == i) &&
			(town.preset_fields[k].field_loc.y == j))
			return TRUE;
	}
	return FALSE;
}

//places the given field type at the given coordinates
void make_field_type(short i,short j,short field_type){
	short k;
	
	if (is_field_type(i,j,field_type) == TRUE)
		return;
	for (k = 0; k < NUM_TOWN_PLACED_FIELDS; k++){
		if (town.preset_fields[k].field_type == -1) {
			town.preset_fields[k].field_loc.x = i;
			town.preset_fields[k].field_loc.y = j;
			town.preset_fields[k].field_type = field_type;
			return;
		}
	}
	//sprintf(str,"Field error  %d %d %d",i,j,field_type);
	//give_error(str,"",0);
	//give_error("Each town can have at most 60 fields and special effects (webs, barrels, blood stains, etc.). To place more, use the eraser first.","",0);
}

//removes the given field type at the given coordinates if it is there
void take_field_type(short i,short j,short field_type){
	short k;
	for (k = 0; k < NUM_TOWN_PLACED_FIELDS; k++){
		if ((town.preset_fields[k].field_type == field_type) &&
			(town.preset_fields[k].field_loc.x == i) &&
			(town.preset_fields[k].field_loc.y == j)) {
			town.preset_fields[k].clear_preset_field_type();
			return;
		}
	}
}

Boolean is_oblique_mirror(short i,short j){
	return is_field_type(i,j,2);
}
void make_oblique_mirror(short i,short j){
	make_field_type(i,j,2);
}
void take_oblique_mirror(short i,short j){
	take_field_type(i,j,2);
}
Boolean is_facing_mirror(short i,short j){
	return is_field_type(i,j,8);
}
void make_facing_mirror(short i,short j){
	make_field_type(i,j,8);
}
void take_facing_mirror(short i,short j){
	take_field_type(i,j,8);
}
Boolean is_web(short i,short j){
	return is_field_type(i,j,5);
}
void make_web(short i,short j){
	make_field_type(i,j,5);
}
void take_web(short i,short j){
	take_field_type(i,j,5);
}
Boolean is_crate(short i,short j){
	return is_field_type(i,j,6);
}
void make_crate(short i,short j){
	make_field_type(i,j,6);
}
void take_crate(short i,short j){
	take_field_type(i,j,6);
}
Boolean is_barrel(short i,short j){
	return is_field_type(i,j,7);
}
void make_barrel(short i,short j){
	make_field_type(i,j,7);
}
void take_barrel(short i,short j){
	take_field_type(i,j,7);
}
Boolean is_fire_barrier(short i,short j){
	return is_field_type(i,j,4);
}
void make_fire_barrier(short i,short j){
	make_field_type(i,j,4);
}
void take_fire_barrier(short i,short j){
	take_field_type(i,j,4);
}
Boolean is_force_barrier(short i,short j){
	return is_field_type(i,j,3);
}
void make_force_barrier(short i,short j){
	make_field_type(i,j,3);
}
void take_force_barrier(short i,short j){
	take_field_type(i,j,3);
}
Boolean is_blocked(short i,short j){
	return is_field_type(i,j,1);
}
void make_blocked(short i,short j){
	make_field_type(i,j,1);
}
void take_blocked(short i,short j){
	take_field_type(i,j,1);
}
Boolean is_sfx(short i,short j,short type){
	return is_field_type(i,j,type + 14);
}
void make_sfx(short i,short j,short type){
	make_field_type(i,j,type + 14);
}
void take_sfx(short i,short j,short type){
	take_field_type(i,j,type + 14);
}
