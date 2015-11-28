//
//  townout.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/28/15.
//
//

#ifndef townout_h
#define townout_h

#include "global.h"

// townout
void edit_placed_monst_event_filter (short item_hit);
void edit_placed_monst(short which_m);
void put_placed_item_in_dlog();
Boolean get_placed_item_in_dlog();
void edit_placed_item_event_filter (short item_hit);
void edit_placed_item(short which_i);
void edit_sign_event_filter (short item_hit);
void edit_sign(short which_sign, bool handleUndo);
void get_a_number_event_filter (short item_hit);
short get_a_number(short which_dlog,short default_value,short min,short max);
void change_ter_event_filter (short item_hit);
void change_ter(short *change_from,short *change_to,short *chance);
void outdoor_details_event_filter (short item_hit);
void outdoor_details();
void edit_out_wand_event_filter (short item_hit);
void edit_out_wand(short mode);
void edit_town_details_event_filter (short item_hit);
void edit_town_details();
void put_town_wand_in_dlog();
void edit_town_wand_event_filter (short item_hit);
void edit_town_wand();
void pick_out_event_filter (short item_hit);
short pick_out(location default_loc,short max_x,short max_y);
void change_outdoor_size_event_filter (short item_hit);
Boolean change_outdoor_size();
void new_town_event_filter (short item_hit);
Boolean new_town();
void delete_town();
Boolean change_town_size();
void change_town_size_event_filter(short item_hit);
void pick_import_town_event_filter (short item_hit);
short pick_import_town(short which_dlog,short def);
Boolean terrains_match(short terrain_drawn,short terrain_there);
Boolean floors_match(short floor_drawn,short floor_there);
void edit_area_rect_event_filter (short item_hit);
Boolean edit_area_rect_str(short which_str,short mode);
void edit_out_strs_event_filter (short item_hit);
void edit_out_strs();
void edit_town_strs_event_filter (short item_hit);
void edit_town_strs();
void edit_item_placement();
void edit_item_placement_event_filter (short item_hit);
void edit_add_town();
void edit_add_town_event_filter (short item_hit);
void edit_make_scen_1_event_filter (short item_hit);
void edit_make_scen_2_event_filter (short item_hit);
void build_scenario();
void edit_scen_details_event_filter (short item_hit);
void edit_scen_details();
void edit_scen_intro_event_filter (short item_hit);
void edit_scen_intro(short which_part);
void edit_scen_intro_pic_event_filter (short item_hit);
void edit_scen_intro_pic();
void pick_town_event_filter (short item_hit, int which_dlg);
void edit_item_properties_event_filter (short item_hit);
void edit_item_properties(short which_i);

#endif /* townout_h */
