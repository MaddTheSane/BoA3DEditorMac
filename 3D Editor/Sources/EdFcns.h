//
//  EdFcns.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef EdFcns_h
#define EdFcns_h

#include "global.h"

void init_screen_locs();
void handle_action(Point the_point,EventRecord event, short which_window);
void handleToolPaletteClick(Point the_point, EventRecord event);
void handle_ter_spot_press(location spot_hit,Boolean option_hit,Boolean alt_hit,Boolean ctrl_hit);
void play_press_snd();
void swap_terrain();
void set_tool(short tool);
void set_new_terrain(short selected_terrain);
void set_new_floor(short selected_terrain);
void set_new_creature(short selected_creature);
void set_new_item(short selected_item);
void handle_keystroke(char chr,char chr2,EventRecord event);
bool handle_scroll( int map_size, int scrl, bool ctrlKey, bool shftKey );
Boolean is_hill(short i,short j);
Boolean is_rocks(short i,short j);
Boolean is_water(short i,short j);
void shy_change_circle_terrain(location center,short radius,short terrain_type,short probability);
void change_circle_terrain(location center,short radius,short terrain_type,short probability);
void change_circle_height(location center,short radius,short lower_or_raise,short probability);
void change_rect_terrain(Rect r,short terrain_type,short probability,Boolean hollow);
void set_terrain(location l,short terrain_type);
Boolean town_fix_grass_rocks(location l);
Boolean out_fix_grass_rocks(location l);
Boolean town_fix_rocks_water(location l);
Boolean out_fix_rocks_water(location l);
Boolean town_fix_hills(location l);
Boolean out_fix_hills(location l);
short get_corner_height(short x, short y,short out_or_town,short which_corner) ;
short adjust_get_ter(short x, short y,short out_or_town);
void adjust_space(location l);
short coord_to_ter(short x,short y);
void change_height(location l,short lower_or_raise);
void adjust_space_height(location l,short lower_or_raise);
void adjust_space_height_lower(location l);
void adjust_space_height_raise(location l);
void shut_down_menus();
Boolean save_check(short which_dlog);
void update_item_menu();
short locs_to_dir(location l1,location l2);
void delete_selected_instance();
void copy_selected_instance();
void cut_selected_instance();
void paste_selected_instance(location create_loc);
void check_selected_item_number();
location selected_instance_location();
void shift_selected_instance(short dx,short dy);
void rotate_selected_instance(int dir);
void setSelection(SelectionType::SelectionType_e type, unsigned short num, bool jumpTo=false);
void jumpToSelectedInstance();
void create_navpoint(location spot_hit);
void delete_navpoint(location spot_hit);
void frill_terrain();
void unfrill_terrain();
void create_new_creature(short c_to_create,location create_loc,creature_start_type *c_to_make);
Boolean create_new_item(short item_to_create,location create_loc,Boolean property,item_type *i_to_make);
void shift_item_locs(location spot_hit);
void place_items_in_town();
void create_town_entry(Rect rect_hit);
void edit_town_entry(location spot_hit);
void set_rect_height(Rect r);
void add_rect_height(Rect r);
void shy_put_terrain(short i,short j,short ter);
void transform_walls(Rect working_rect);
Boolean is_not_darkness_floor(short i,short j);
void place_bounding_walls(Rect working_rect);
Boolean is_wall(short x, short y);
void clean_walls();
Boolean is_dumb_terrain(short ter);
short get_height(short x, short y,short out_or_town);
void set_all_items_containment();
void set_items_containment(int x, int y, int mode=0);
void set_up_lights();
Boolean old_can_see_in(location p1,location p2,short check_light,short check_travel);
void old_can_see(location p1,location p2,short check_light,short check_travel,Boolean *see_to,Boolean *see_in);
Boolean can_see_to(location p1,location p2,short check_light,short check_travel);
Boolean can_see_in(location p1,location p2,short check_light,short check_travel);
void can_see(location p1,location p2,short check_light,short check_travel,Boolean *see_to,Boolean *see_in);
Boolean can_see_single(location p1,location p2,short check_light,short check_travel,Boolean *see_to);
Boolean no_block(location l, short direction,short check_light,short check_travel);
Boolean look_block(location l, short direction);
Boolean move_block(location l, short direction);
void clear_selected_copied_objects();
void set_drawing_mode(short new_mode);
void reset_drawing_mode();
Boolean create_new_ter_script(const char* ter_script_name,location create_loc,in_town_on_ter_script_type* script_to_make);
void recursive_clean_terrain(location l);
void recursive_adjust_space_height_raise(location l);
void recursive_adjust_space_height_lower(location l);
Boolean get_see_in(short sector_offset_x, short sector_offset_y, short x, short y);
void set_see_in(short sector_offset_x, short sector_offset_y, short x, short y, Boolean value);
Boolean get_see_to(short sector_offset_x, short sector_offset_y, short x, short y);
void set_see_to(short sector_offset_x, short sector_offset_y, short x, short y, Boolean value);
short get_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_se_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_se_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
short get_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y);
void set_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value);
void set_up_corner_and_sight_map();
void find_out_about_corner_walls(outdoor_record_type* drawing_terrain, short x, short y, short current_size, short *nw_corner, short *ne_corner, short *se_corner, short *sw_corner);
void find_out_about_corner_walls_being_hidden(outdoor_record_type *drawing_terrain, short sector_offset_x, short sector_offset_y, short x, short y, short current_size, Boolean see_in_neighbors[3][3],
											  Boolean see_to_neighbors[3][3], /*Boolean see_to, */short *nw_corner, short *ne_corner, short *se_corner, short *sw_corner);
Boolean is_wall_drawn(outdoor_record_type *drawing_terrain, short sector_offset_x, short sector_offset_y, short x, short y);
Boolean clean_up_from_scrolling( int map_size, short dx, short dy );
void paste_terrain(location l,Boolean option_hit,Boolean alt_hit,Boolean ctrl_hit);
void copy_rect_terrain(Rect r);
int flood_fill_floor(short new_floor, short old_floor, int x, int y);
int flood_fill_terrain(short new_terrain, short old_terrain, int x, int y);
namespace Undo{ //forward decl
	class UndoStep;
}
void updateUndoMenu();
void pushUndoStep(Undo::UndoStep* s);
void purgeUndo();
void performUndo();
void purgeRedo();
void performRedo();

#endif /* EdFcns_h */
