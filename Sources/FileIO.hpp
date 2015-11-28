//
//  FileIO.hpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef FileIO_h
#define FileIO_h

#include <Carbon/Carbon.h>
#include "global.h"

void open_Appl_resource( const char * rsrc_file );
bool init_directories( void );
void save_campaign();
void save_change_to_outdoor_size(short plus_north,short plus_west,short plus_south,short plus_east,short on_surface);
void save_change_to_town_size(int old_town_size);
void save_remove_town();
void load_campaign(FSSpec* file_to_load);
void augment_terrain(location to_create);
void load_outdoors(location which_out,short mode);
void load_town(short which_town);
void load_all_town_names(FSSpec* to_open);
void start_data_dump();
short str_to_num(Str255 str) ;
Boolean create_basic_scenario(char *scen_name_short,char *scen_name_with_ext,char *scen_full_name,short out_width,short out_height,short on_surface,Boolean use_warriors_grove);
Boolean import_boa_town();
Boolean import_boa_outdoors();
void EdSysBeep(short duration);
void get_name_of_current_scenario(char *name);
void extract_old_scen_text();
void init_warriors_grove();
void import_blades_of_exile_scenario();
void get_bl_str(char *str,short str_type,short str_num);
void add_short_string_to_file(FSIORefNum file_id,const char *str1,short num,const char *str2);
void add_big_string_to_file(FSIORefNum file_id,const char *str1,short num1,const char *str2,short num2,const char *str3,short num3,const char *str4);
void add_string_to_file(FSIORefNum file_id,const char *str);
void add_cr(FSIORefNum file_id);
void add_string(FSIORefNum file_id,const char *str);
void handle_messages(FSIORefNum file_id,short node_type,short message_1,short message_2);
void trunc_str(char *str);
void clean_str(char *str);
void open_current_scenario_resources();
void close_current_scenario_resources();
Boolean SelectSaveFileToOpen(FSSpecPtr defaultLocationfssPtr,FSSpec *file_picked, bool BoAScen);
void kludge_correct_old_bad_data();
bool get_user_pref_bool_value(int which, bool write_default_if_missing);
void write_user_pref_bool_value(int which, bool value);
bool get_should_play_sounds();
void write_should_play_sounds(bool play);
bool get_should_use_strict_adjusts();
void write_should_use_strict_adjusts(bool use);
bool get_always_show_heights();
void write_always_show_heights(bool show);
bool get_allow_arrow_key_navigation();
void write_allow_arrow_key_navigation(bool allow);
bool get_saved_window_bounds(unsigned int which, Rect& windRect);
void write_window_bounds(unsigned int which, const Rect& windRect);
short get_saved_tile_zoom_level();
void write_tile_zoom_level(short tile_zoom_level);
bool select_script_editor();
bool open_script_with_editor(const char* script_name);
bool get_editor_application();
char* get_scenario_filename();

#endif /* FileIO_h */
