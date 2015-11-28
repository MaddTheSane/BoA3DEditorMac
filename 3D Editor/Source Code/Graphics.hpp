//
//  Graphics.hpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef Graphics_h
#define Graphics_h

#include <Carbon/Carbon.h>
#include "global.h"

void Get_right_sbar_rect( Rect * rect );
int get_right_sbar_max();
void Set_up_win ();
void load_main_screen();
void recalculate_2D_view_details();
void recalculate_draw_distances();
void resize_recalculate_num_tiles();
void zoom_tiles_recalculate();
void set_up_terrain_rects();
void make_tile_gworlds(bool first_time=false);
bool set_view_mode(int mode);
void redraw_screen();
void draw_main_screen();
void set_up_terrain_buttons();
void reset_mode_number();
void set_up_view_buttons();
Rect terrainViewRect();
Rect get_template_from_rect(short x,short y);
void draw_creature(short creature_num,location loc_drawn,short in_square_x,short in_square_y,bool selected=false);
void draw_item(short item_num,location loc_drawn,short in_square_x,short in_square_y,bool selected=false);
Boolean place_terrain_icon_into_ter_small(graphic_id_type icon,short in_square_x,short in_square_y);
void draw_ter_small();
void draw_terrain();
void update_terrain_window_title();
void place_left_text();
void rect_draw_some_item (GWorldPtr src_gworld,Rect src_rect,GWorldPtr targ_gworld,Rect targ_rect,
						  char masked,short main_win);
void place_right_buttons(short mode);
Boolean container_there(location l);
void char_win_draw_string(GrafPtr dest_window,Rect dest_rect,const char *str,short mode,short line_height);
void c2p(Str255 str) ;
void p2c(Str255 str);
void get_str(Str255 str,short i, short j);
short string_length(char *str);
Boolean clear_graphics_library();
Boolean refresh_graphics_library();
void load_builtin_images();
//void win_draw_string(CGrafPtr dest_window,Rect dest_rect,char *str,short mode,short line_height,short r, short g, short b);
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
void reset_small_drawn();
void win_draw_string_outline(CGrafPtr dest_window,Rect dest_rect,char *str,short mode,short line_height);
void place_ter_icon_on_tile(short tile_x,short tile_y,short position,short which_icon,bool selected=false);
void place_dlog_borders_around_rect(GWorldPtr to_gworld,WindowPtr win,
									Rect border_to_rect);
void place_dlog_border_on_win(GWorldPtr to_gworld,WindowPtr win,
							  Rect border_to_rect,short horiz_or_vert,short bottom_or_top);
void paint_pattern(GWorldPtr dest,short which_mode,Rect dest_rect,short which_pattern);
void draw_ter_script(short script_num,location loc_drawn,short in_square_x,short in_square_y,bool selected);
void cant_draw_graphics_error(graphic_id_type a,const char *bonus_string,short bonus_num);
void refresh_graphics_on_screen();
void drawToolPalette();
void drawToolCategories();
void drawToolDetails();
OSStatus mainWindowTooltipContentCallback(WindowRef inWindow,Point inGlobalMouse,HMContentRequest inRequest,HMContentProvidedType *outContentProvided,HMHelpContentPtr ioHelpContent);
OSStatus paletteWindowTooltipContentCallback(WindowRef inWindow,Point inGlobalMouse,HMContentRequest inRequest,HMContentProvidedType *outContentProvided,HMHelpContentPtr ioHelpContent);
OSStatus tileWindowTooltipContentCallback(WindowRef inWindow,Point inGlobalMouse,HMContentRequest inRequest,HMContentProvidedType *outContentProvided,HMHelpContentPtr ioHelpContent);

#endif /* Graphics_h */
