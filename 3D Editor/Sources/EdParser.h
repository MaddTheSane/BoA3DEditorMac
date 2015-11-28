//
//  EdParser.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef EdParser_h
#define EdParser_h

#include "Library.hpp"


// general script records

// Script stuff
#define MAX_DESCRIBER_LEN	30
#define	NUM_SCRIPT_STRINGS	750
#define	SCRIPT_VAR_NAME_LEN	20
#define	NUM_SCRIPT_INTS	20
#define	NUM_SCRIPT_LOCATIONS	10
#define	NUM_SCRIPT_STRING_VARS	20
#define	NUM_PROCEDURE_PASS_VARS	5

// a block of text, loaded in from a file.
class text_block_type
{
public:
	text_block_type();
	~text_block_type();
	Boolean load_text_file_into_buffer(char *file_name_to_load,short file_location);
	void preprocess_text();
	short estimate_num_of_tokens();
	
	char *text_block;
	long block_length;
};

// A token, a basic unit of meaning in a script (like a procedure name, or a number).
// The list of 20-odd different token types can be found in tokntype.h.
class token_type
{
public:
	token_type();
	
	unsigned char type;
	short line;
	short what_sort;
};

// A token, a basic unit of meaning in a script.
typedef struct
{
	char token_text[MAX_DESCRIBER_LEN];
} token_describer_type;

// Stores a loaded script, in tokenized form.
class script_type
{
public:
	script_type();
	~script_type();
	void flush_data();
	Boolean load_script(short type_of_script_to_load,const char *script_to_load,short file_location);
	Boolean IsWhiteSpace(char c);
	Boolean IsIdentifier(char c);
	Boolean IsNumber(char c);
	Boolean IsOperatorCharacter (char c);
	short IsVariable (char * string, int length, token_type *token);
	short IsBlockDefiner (char * string, int length, short *value);
	short IsVarDefiner (char * string, int length, short *value);
	short IsVarArrayDefiner (char * string, int length, short *value);
	short IsVarStringDefiner (char * string, int length, short *value);
	short IsNewVariableDefiner (char * string, int length, short *value);
	short IsFlowController (char * string, int length, short *value);
	short IsConstant (char * string, int length, short *value);
	short IsOperator (char * string, int length, short *value);
	short IsFunction (char * string, int length, short *value);
	short IsProcedure (char * string, int length, short *value);
	short IsBinaryFunction (char * string, int length, short *value);
	short IsTrinaryFunction (char * string, int length, short *value);
	short IsLocationFunction (char * string, int length, short *value);
	Boolean process_scenario_data();
	Boolean process_creature_data();
	Boolean token_type_match(short which_token,short type);
	Boolean token_sort_match(short which_token,short what_sort);
	Boolean token_match(short which_token,short type,short what_sort);
	short find_first_matching_token(short type_of_token,short what_sort = -1);
	short find_next_matching_token(short start_token,short type_of_token,short what_sort = -1);
	Boolean semicolon_check(short check_token);
	short find_start_of_state(short which_state);
	Boolean run_script(short next_token);
	Boolean evaluate_int_expression(short next_token,short *result,short *new_position);
	Boolean higher_precedence (token_type op1, token_type op2);
	short evaluate_unary_function(short fcn_type,short op1,short which_line);
	short evaluate_binary_function(short fcn_type,short op1,short op2,short which_line);
	Boolean run_procedure(short which_procedure,short which_line);
	short find_previous_matching_token(short start_token,short type_of_token,short what_sort);
	short find_matching_bracket(short start_token);
	short end_of_current_line(short start_token);
	short find_conditional_matching_bracket(short start_token);
	location location_function_value(short what_function,short what_passed,short what_line);
	Boolean run_creature_script();
	short evaluate_trinary_function(short fcn_type,short op1,short op2,short op3,short which_line);
	short IsNoParameterFunction (char * string, int length, short *value);
	short evaluate_no_param_function(short fcn_type,short which_line);
	Boolean run_zone_script();
	Boolean process_dialogue_data();
	
	// basic script information
	char script_name[20];
	short type_of_script;
	// -1 - undefined
	// 0 - Scenario data
	// 1 - Scenario script
	// 2 - Town - specials
	// 3 - Town - dialogue
	// 4 - Outdoor - specials
	// 5 - Outdoor - dialogue
	// 6 - Creature
	// 7 - Terrain Spot
	token_type *token_list;
	short num_tokens;
	Boolean script_killed; // If the script hits a run-time error,
	// this makes sure it's never called again.
	short which_object; // The number of the creature/object this is for.
	// only relevant if type_of_script is 2,3.
	
	// script variables
	char int_var_names[NUM_SCRIPT_INTS][SCRIPT_VAR_NAME_LEN];
	short int_var_values[NUM_SCRIPT_INTS];
	char location_var_names[NUM_SCRIPT_LOCATIONS][SCRIPT_VAR_NAME_LEN];
	location location_var_values[NUM_SCRIPT_LOCATIONS];
	char string_var_names[NUM_SCRIPT_STRING_VARS][SCRIPT_VAR_NAME_LEN];
	char *string_var_values[NUM_SCRIPT_STRING_VARS];
	
	// temporary holder for the script text
	char *string_data[NUM_SCRIPT_STRINGS];
	
	// stacks for running procedures
	short procedure_passed_variable_types[NUM_PROCEDURE_PASS_VARS];
	//	0 - int 1 - loc 2 - string constant 3 - string variable
	short procedure_passed_values[NUM_PROCEDURE_PASS_VARS];
	location procedure_passed_locations[NUM_PROCEDURE_PASS_VARS];
};

// begin Blades of Exile records
// This junk only used for routines to port BoE scenarios.

typedef struct {
	short type,sd1,sd2,pic,m1,m2,ex1a,ex1b,ex2a,ex2b,jumpto;
} old_blades_special_node_type;

typedef struct {
	short personality,type;
	char link1[4],link2[4];
	short extras[4];
} old_blades_talking_node_type;

typedef struct {
	unsigned char strlens[200];
	old_blades_talking_node_type talk_nodes[60];
} old_blades_talking_record_type;

typedef struct {
	short picture;
	unsigned char blockage,flag1,flag2,special,trans_to_what,fly_over,boat_over;
	unsigned char block_horse,light_radius,step_sound,shortcut_key,res1,res2,res3;
} old_blades_terrain_type_type;

typedef	struct {
	unsigned char monst[4];
} old_blades_wandering_type;

typedef struct {
	unsigned char monst[7];
	unsigned char friendly[3];
	short spec_on_meet,spec_on_win,spec_on_flee,cant_flee;
	short end_spec1,end_spec2;
} old_blades_out_wandering_type;

typedef struct {
	unsigned char	terrain[48][48];
	location	special_locs[18];
	unsigned char		special_id[18];
	location	exit_locs[8];
	char		exit_dests[8];
	location	sign_locs[8];
	old_blades_out_wandering_type	wandering[4],special_enc[4];
	location	wandering_locs[4];
	Rect info_rect[8];
	unsigned char strlens[180];
	old_blades_special_node_type specials[60];
} old_blades_outdoor_record_type;

typedef struct {
	unsigned char number;
	unsigned char start_attitude;
	location start_loc;
	unsigned char  mobile;
	unsigned char  time_flag;
	unsigned char  extra1,extra2;
	short spec1, spec2;
	char spec_enc_code,time_code;
	short monster_time,personality;
	short special_on_kill,facial_pic;
} old_blades_creature_start_type;

typedef struct {
	short variety, item_level;
	char awkward, bonus, protection, charges, type;
	unsigned char graphic_num,ability, type_flag, is_special;
	short value;
	Boolean identified, magic;
	unsigned char weight, description_flag;
	char full_name[25], name[15];
	unsigned char reserved1,reserved2;
	unsigned char magic_use_type, ability_strength, treas_class, real_abil;
} old_blades_short_item_record_type;


typedef struct {
	short variety, item_level;
	char awkward, bonus, protection, charges, type, magic_use_type;
	unsigned char graphic_num,ability, ability_strength,type_flag, is_special;
	short value;
	unsigned char weight, special_class;
	location item_loc;
	char full_name[25], name[15];
	unsigned char treas_class,item_properties,reserved1,reserved2;
} old_blades_item_record_type;

typedef struct {
	location item_loc;
	short item_code,ability;
	unsigned char charges,always_there,property,contained;
} old_blades_preset_item_type;

typedef struct {
	location field_loc;
	short field_type;
} old_blades_preset_field_type;

typedef struct {
	short town_chop_time,town_chop_key;
	old_blades_wandering_type	wandering[4];
	location	wandering_locs[4];
	location	special_locs[50];
	unsigned char		spec_id[50];
	location	sign_locs[15];
	short		lighting;
	location start_locs[4];
	location exit_locs[4];
	short exit_specs[4];
	Rect in_town_rect;
	old_blades_preset_item_type preset_items[64];
	short max_num_monst;
	old_blades_preset_field_type preset_fields[50];
	short spec_on_entry,spec_on_entry_if_dead;
	short timer_spec_times[8];
	short timer_specs[8];
	unsigned char strlens[180];
	old_blades_special_node_type specials[100];
	unsigned char specials1,specials2,res1,res2;
	short difficulty;
} old_blades_town_record_type;

typedef struct {
	unsigned char terrain[64][64];
	Rect room_rect[16];
	old_blades_creature_start_type creatures[60];
	unsigned char lighting[8][64];
} old_blades_big_tr_type;

typedef struct {
	unsigned char terrain[48][48];
	Rect room_rect[16];
	old_blades_creature_start_type creatures[40];
	unsigned char lighting[6][48];
} old_blades_ave_tr_type;

typedef struct {
	unsigned char terrain[32][32];
	Rect room_rect[16];
	old_blades_creature_start_type creatures[30];
	unsigned char lighting[4][32];
} old_blades_tiny_tr_type;

typedef struct {
	old_blades_item_record_type scen_items[400];
	char monst_names[256][20];
	char ter_names[256][30];
} old_blades_scen_item_data_type;

typedef struct {
	short ter_type,item_num[10],item_odds[10],property;
} old_blades_item_storage_shortcut_type;

typedef struct {
	unsigned char m_num,level,m_name[26];
	short health,m_health,mp,max_mp;
	unsigned char armor,skill;
	short a[3];
	unsigned char a1_type,a23_type,m_type,speed,ap,mu,cl,breath,breath_type,treasure,spec_skill,poison;
	short morale,m_morale;
	short corpse_item,corpse_item_chance;
	short status[15];
	unsigned char direction,immunities,x_width,y_width,radiate_1,radiate_2;
	unsigned char default_attitude,summon_type,default_facial_pic,res1,res2,res3;
	short picture_num;
	
} old_blades_monster_record_type;

typedef struct {
	short active,attitude;
	unsigned char number;
	location m_loc;
	old_blades_monster_record_type m_d;
	Boolean mobile;
	short summoned;
	old_blades_creature_start_type monst_start;
} old_blades_creature_data_type;

typedef struct {
	location horse_loc,horse_loc_in_sec,horse_sector;
	short which_town;
	Boolean exists,property;
} old_blades_horse_record_type;

typedef struct {
	location boat_loc,boat_loc_in_sec,boat_sector;
	short which_town;
	Boolean exists,property;
} old_blades_boat_record_type;

typedef struct {
	unsigned char flag1, flag2, flag3, flag4;
	unsigned char ver[3],min_run_ver,prog_make_ver[3],num_towns;
	unsigned char out_width,out_height,difficulty,intro_pic,default_ground;
} scen_header_type;

typedef struct {
	unsigned char flag1, flag2, flag3, flag4;
	unsigned char ver[3],min_run_ver,prog_make_ver[3],num_towns;
	unsigned char out_width,out_height,difficulty,intro_pic,default_ground;
	unsigned char town_size[200];
	unsigned char town_hidden[200];
	short flag_a;
	short intro_mess_pic,intro_mess_len;
	location where_start,out_sec_start,out_start;
	short which_town_start;
	short flag_b;
	short town_data_size[200][5];
	short town_to_add_to[10];
	short flag_to_add_to_town[10][2];
	short flag_c;
	short out_data_size[100][2];
	Rect store_item_rects[3];
	short store_item_towns[3];
	short flag_e;
	short special_items[50];
	short special_item_special[50];
	short rating,uses_custom_graphics;
	short flag_f;
	old_blades_monster_record_type scen_monsters[256];
	//old_blades_boat_record_type scen_boats[30];
	//old_blades_horse_record_type scen_horses[30];
	boat_record_type scen_boats[30];
	horse_record_type scen_horses[30];
	short flag_g;
	old_blades_terrain_type_type ter_types[256];
	short scenario_timer_times[20];
	short scenario_timer_specs[20];
	short flag_h;
	old_blades_special_node_type scen_specials[256];
	old_blades_item_storage_shortcut_type storage_shortcuts[10];
	short flag_d;
	unsigned char scen_str_len[300];
	short flag_i;
	location last_out_edited;
	short last_town_edited;
	
} old_blades_scenario_data_type;

typedef struct {
	char town_strs[180][256];
	char out_strs[120][256];
	char scen_strs[270][256];
	char talk_strs[170][256];
} old_blades_piles_of_stuff_dumping_type;

// end BoE records

typedef struct {
	/*char strings_ls[NLS][40];
	 char strings_rs[NRS][50];
	 char town_strs[180][256];
	 char out_strs[120][256];
	 char short_talk_strs[NUM_TALK_NODES][120];
	 char talk_strs[NUM_TALK_NODES * 2][256];*/
	scen_item_data_type scen_item_list;
} piles_of_stuff_dumping_type;

void init_scripts();
void load_town_script();
void load_tokens_for_initialized_script(script_type *script_data);
Boolean load_scenario_data(char *scenario_name);
Boolean set_char_variable(short which_char_type,short which_value,short new_value);
Boolean set_char_array_variable(short which_char_type,short which_member,short which_value,short new_value);
Boolean set_char_string(short which_char_type,short which_value,char *new_str);
Boolean set_floor_variable(short which_floor_type,short which_value,short new_value);
Boolean set_floor_string(short which_floor_type,short which_value,char *new_str);
Boolean set_terrain_variable(short which_ter_type,short which_value,short new_value);
Boolean set_terrain_string(short which_ter_type,short which_value,char *new_str);
Boolean set_item_variable(short which_item_type,short which_value,short new_value);
Boolean set_item_array_variable(short which_item_type,short which_member,short which_value,short new_value);
Boolean set_item_string(short which_item_type,short which_value,char *new_str);
short evaluate_operator(short operator_type,short op1,short op2);
short value_limit(short start_value,short min,short max,Boolean *error);
Boolean load_individual_scenario_data(char *scenario_name,Boolean force_reload = FALSE);
Boolean load_core_scenario_data();
Boolean check_script_exists(char *check_file_name,short file_location);


#endif /* EdParser_h */
