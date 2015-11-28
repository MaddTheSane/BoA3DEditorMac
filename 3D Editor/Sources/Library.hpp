//
//  Library.hpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef Library_h
#define Library_h

#include "global.h"

class graphic_id_type {
public:
	graphic_id_type():
	which_sheet(-1),which_icon(0),graphic_adjust(0){}
	
	graphic_id_type(short sheet, short icon, short adjust):
	which_sheet(sheet),which_icon(icon),graphic_adjust(adjust){}
	
	void clear_graphic_id_type();
	Boolean not_legit();
	
	short which_sheet; // the resource number of the graphic
	short which_icon; // the icon in the resource. icons are in resources 
		// 16 icons per row
	short graphic_adjust;
};
	
class floor_type_type {
public:
	floor_type_type();
	void clear_floor_values();
	
	char floor_name[20];
	graphic_id_type pic; // regular picture location for ground
	graphic_id_type ed_pic; // picture location for editor graphic for icon
	short blocked; // 0 no 1 yes
 	char step_sound; // -1 no sound, otherwise sound when stepped on
 	char light_radius; // radius terrain sends its light out to, 0 - no light
 	short floor_height; // in pixels, positive is up, shows how many vertical pixels
 						// to offset graphics when drawn
	short num_anim_steps;
	
	// special properties of floor
	short special; // floor special property
	short effect_adjust; // intensity of special effect
	// described in the editor docs
	
	// special editor and movement toggles
	Boolean is_water; // water?
	Boolean is_floor; // a human built (stone or wood) floor
	Boolean is_ground; // regular grass, cave floor?
	Boolean is_rough; // rought errain? (i.e. desert or rough cave)
	Boolean fly_over; // can this terrain be flied over?
	Boolean shimmers; // does this graphic get drawn with graphical effects?
		// 0 - none
		// 1 - glows light/dark
		// 2 - water effect
	
	short outdoor_combat_town_used; // The town that is loaded when party fights an outdoor
		// combat on this terrain type. If 0-999, loads the town in the current scenario/
		// If 1000 + x, loads town x in file Blades of Avernum Out Fight
		// 0 - 
	unsigned char shortcut_key;
	short extra[6];
};

class terrain_type_type {
public:
	terrain_type_type();
	void clear_terrain_values();

	char ter_name[20];
	graphic_id_type pic; // regular picture location for when above ground
	graphic_id_type cut_away_pic; // picture when the terrain is being drawn cut away
	graphic_id_type ed_pic; // picture location for editor graphic for icon
	
	// the icon can be drawn with a certain pixel offset.
	short icon_offset_x,icon_offset_y;
	
	// a terrain spot can have a second icon drawn, which must be in the same sheet as the first icon.
	// it affects the outdoor and underground terrain versions equally.
	// there can be a different icon for the front and cut away view.
	short second_icon,second_icon_offset_x,second_icon_offset_y;
	short cut_away_second_icon,cut_away_offset_x,cut_away_offset_y;
		// For now, cut_away_offset_x & cut_away_offset_y are UNUSED
		// Use other offsets instead.
	short anim_steps; // number of icons in this terrain's animation. uses icons after
		// first icon in sheet for animation
	unsigned char move_block[4]; // 0 - no block, 1 - block movement, 0 - n, 1 - w, 2 - s, 3 - e
	unsigned char see_block[4]; // 0 - no block, 1 - sight movement, 0 - n, 1 - w, 2 - s, 3 - e
	unsigned char blocks_view[4]; // 0 - draw after pc in spot, 1 - draw before, 0 - n, 1 - w, 2 - s, 3 - e
	short height_adj; // pixels up to draw chars/items in this space
	unsigned char suppress_floor; // 0 - no, if 1, floor type under terrain type is ignored
	unsigned char light_radius; // radius of light coming from this spot
	char step_sound; // -1 - no sound, takes precedence over floor sound

	unsigned char shortcut_key;
	
	// various special properties
	short crumble_type; // 0 - won't crumble, 1-5 - strength of speel needed to make crumble
	short beam_hit_type; // 0 - blocks beam, 1 - allows beam through
		// 3 - crumbles when beam hits
	short terrain_to_crumble_to;
	short hidden_town_terrain; // -1 - unused. otherwise, terrain to place here if this is
		// icon for a hidden town
	short swap_terrain; // ter to swap to if a swap terrain special call is used
	Boolean is_bridge; // allows people to cross this space even if floor is a blocking type
	Boolean is_road;
	Boolean can_look_at; // a terrain which is always selected to be inspected when player looks
	Boolean draw_on_automap;
	char default_script[SCRIPT_NAME_LEN]; // the name of the default script
	Boolean shimmers; // does this graphic get drawn with graphical effects?
		// 0 - none
		// 1 - glows light/dark
		// 2 - water effect

	short outdoor_combat_town_used; // The town that is loaded when party fights an outdoor
		// combat on this terrain type. If 0-999, loads the town in the current scenario/
		// If 1000 + x, loads town x in file Blades of Avernum Out Fight
		// 0 - 
	
	// special properties of terrain
	short special; // terrain special property
	short effect_adjust; // intensity of special effect
	// below may be out of date. full info inj editor docs
	// special		effect			effect_adjust
	// 0			none
	// 1			fire damage		amt. of damage
	// 2			cold damage		amt. of damage
	// 3			magic damage	amt. of damage
	// 4			poison			amt. of damage
	// 5			disease			amt. of damage
	// 6			blocks monsts
	
	// Hill properties
	// 19			hill, up to west
	// 20			hill, up to southwest
	// 21			hill, up to south
	// 22			hill, up to southeast
	// 23			hill, up to east
	// 24			hill, up to northeast
	// 25			hill, up to north
	// 26			hill, up to northwest
	// 27			hill, down to southeast
	// 28			hill, down to northeast
	// 29			hill, down to northwest
	// 30			hill, down to southwest
	
	// Beam abilities
	// 31			beam power source, if charged by beam	
	// 32			fires beam north
	// 33			fires beam west
	// 34			fires beam south
	// 35			fires beam east
	// 36			nw/se mirror
	// 37			ne/sw mirror
	// 38			beam power source

	// 39			sign
	// 40			container
	// 41			acts as table
	// 42			glows
	// 43			waterfall - south
	// 44			waterfall - west
	// 45			destroyed by quickfire	
};

class out_wandering_type {
public:
	out_wandering_type();
	void clear_out_wandering_type();
	void port();
	
	short hostile[4],hostile_amount[4];
	short friendly[3],friendly_amount[3];

	short cant_flee;
		// this encounter can ever be evaded?
	short end_spec1,end_spec2;
		// if this flag is set, this encounter never appears.
	short killed_flag1,killed_flag2;
		// this flag is set to 1 when enc killed.
		// can, and probably should, be same as end_spec
		
	short forced; // if > 0, party encoutners this immediately
	short check_every_turn; // most encoutners checked every 10 turns.
		// if this is 1, check this one every turn
	short move_type;
		// 0 - seek party  1 - no move  2 - random move  3 - follow roads  4 - flee party
		// +10 - always stays within 10 spaces of starting spot
	location start_loc; // location encounter first appears
	short start_state_when_encountered;
	short start_state_when_defeated;
	short start_state_when_fled;
	short random_move_chance; // chance (0-100) that this creature will move randomly at
		// any move instead of doing what it wants
};

class outdoor_record_type {
public:
	outdoor_record_type();
	void clear_outdoor_record_type();
	void port();

	char name[20];
	unsigned char floor[OUTDOOR_SIZE][OUTDOOR_SIZE],height[OUTDOOR_SIZE][OUTDOOR_SIZE];
	short terrain[OUTDOOR_SIZE][OUTDOOR_SIZE];
	Rect special_rects[NUM_OUT_PLACED_SPECIALS];
	short spec_id[NUM_OUT_PLACED_SPECIALS];
	Rect exit_rects[NUM_OUT_TOWN_ENTRANCES];
	short exit_dests[NUM_OUT_TOWN_ENTRANCES];

	// signs
	location sign_locs[8];
	char sign_text[8][256];
	
	// wandering
	out_wandering_type wandering[4],special_enc[4],preset[8];
	location wandering_locs[4];

	Rect info_rect[NUM_OUT_DESCRIPTION_AREAS];
	char info_rect_text[NUM_OUT_DESCRIPTION_AREAS][30];

	// scripts and special flags
	char section_script[SCRIPT_NAME_LEN]; // the name of the default script
	short is_on_surface;
	
	short extra[10];	// extra[0]: region number
};

class creature_type {
public:
	creature_type();
	void clear_creature_type();
	
	char name[20];
	short level; // level of creature
	short which_to_add_to[6]; // which 6 skills to give bonuses to
	short how_much[6]; // how much to add to each skill
	short items[8]; // numbers of items it has
	short item_chances[8]; // chance, from 0 to 100, of the item being present
	short hp_bonus;
	short sp_bonus;
	short spec_abil; 
		// 0 - 
	short default_attitude; // 0 - PC, 1 - PC aid, 2 friendly, 3 - neutral, 4 - hostile A, 5 - hostile B
	short species;
		// 0 - human
		// 1 - humanoid
		// 2 - nephil
		// 3 - slith
		// 4 - giant
		// 5 - reptile
		// 6 - beast
		// 7 - demon
		// 8 - undead
		// 9 - insect
		// 10 - slime
		// 11 - stone/golem
		// 12 - special
		// 13 - vahnatai
		// 14-19 - other/ scenario designed
	unsigned char immunities[6]; 
		// 0 - fire, 1 - cold, 2 - magic, 3 - mental, 4 - poison/acid, 5 - melee
	short natural_armor; // like armor, starts at 0

	// graphic
	graphic_id_type char_graphic;
	short char_upper_graphic_sheet;
	short small_or_large_template;

	short a[3],a1_type,a23_type;
		// attack types
		// 0 - strike
		// 1 - claw
		// 2 - bite
		// 3 - slimes
		// 4 - punches
		// 5 - stings
		// 6 - clubs
		// 7 - burns
		// 8 - harms
		// 9 - stabs
	short ap_bonus;

	char default_script[SCRIPT_NAME_LEN]; 
	short default_strategy;
		// 0 - default, regular attack
		// 1 - archer/caster, so maintain distance
		// 2-9 - reserved
	short default_aggression,default_courage;
	short summon_class; // -1 - never summoned, otherwise, number from 0-6, higher = harder to summon
	short extra[10];
};

class item_record_type {
public:
	item_record_type();
	void clear_item_record_type();

	short variety;
		// 0 - null item
		// 1 - 1 handed weapon
		// 2 - 2 handed Weapon
		// 3 - Gold
		// 4 - Food
		// 5 - Thrown Missile
		// 6 - Bow
		// 7 - Potion
		// 8 - Scroll
		// 9 - Wand
		// 10 - Tool
		// 11 - Pants
		// 12 - Shield
		// 13 - Armor
		// 14 - Helm
		// 15 - Gloves
		// 16 - Boots
		// 17 - Cloak
		// 18 - Ring
		// 19 - Necklace
		// 20 - Bracelet
		// 21 - Object
		// 22 - Crossbow
		// 23 - Arrows
		// 24 - Bolts
	short damage; // weapons do (1 - damage/2) + (1 - damage/2)
	char bonus; // amt. added to weapon damage, and to hit increased by %5 * bonus
	char weap_type; // number of skill used for weapon, such as 4 for melee
	char protection; // prevents (1 - protection/2) + (1 - protection/2) melee damage
	char charges;
	short encumbrance;
	graphic_id_type item_floor_graphic;
	short inven_icon;
	short missile_anim_type;

	// item abilities
	short ability_in_slot[4]; // -1 or 0 - no abil
		// otherwise, number of ability
		// probably out of date. consult editor docs for full list
		// PASSIVE ABILITIES
		// 1 - 49 - Affects statistic x + 1. So if 3, affects statistic 2 (Intelligence)
		// 50 - Melee to hit chance
		// 51 - Melee damage
		// 52 - Missile to hit chance
		// 53 - Missile damage
		// 54 - Resist all hostile effects
		// 55 - Resist fire
		// 56 - Resist cold
		// 57 - Resist magic
		// 58 - Resist mental
		// 59 - Resist poison
		// 60 - Resist acid
		// 61 - Affect action points
		// 62 - Affect melee statistics
		// 63 - Affect magic statistics
		// 64 - Affect all statistics
		// 65 - Affect rune reading
		// 70 - Extra fire damage (only has effect on a weapon)
		// 71 - Extra acid damage (only has effect on a weapon)
		// 72 - Extra poison damage (only has effect on a weapon)
		// 73 - Extra damage to humanoids (only has effect on a weapon)
		// 74 - Extra damage to undead (only has effect on a weapon)
		// 75 - Extra damage to demons (only has effect on a weapon)
		// 76 - Extra damage to giants (only has effect on a weapon)
		// 77 - Drains life, adds to wielder (only has effect on a melee weapon)
		// 78 - Extra damage to reptiles (only has effect on a weapon)
		// 79 - Extra damage to aliens (only has effect on a weapon)
		// 80 - Encumbers
		// 81 - Resist melee damage
		// 82 - Resist all damage
		// 83 - Affects chance to be hit in combat
		// 84 - Protects from petrification
		// ACTIVE ABILITIES
		// 100-119 - Casts mage spell 100 + x.
		// 120-139 - Casts priest spell 120 + x.
		// 150 - 199 - Affects status 150 + x.
		// 200 - heals damage
		// 201 - cures bad effects
		// 202 - Adds experience.
		// 203 - Adds skill points.
		// 204 - Adds spell energy.
		// 205 - Cleanses webs and disease.
		// 207 - Calls a scenario script state. Doesn't lose a charge when used. Items with this ability can't be carried between scenarios
		// 208 - Calls a scenario script state. Loses a charge when used. Items with this ability can't be carried between scenarios
		// 209 - Whole party resists mental effects
		// 210 - Increases light.
		// 211 - is a lockpick.
		// 212 - Is a First Aid Kit.
		// 213 - Gives whole party flight.
		// 214 - Afflicts user with bad effects.
		// 215 - Permanently change 1 statistic.
	short ability_strength[4]; // strength of ability, -50 to 50
		
	short special_class; // 0 - no class
	short value;
	short weight;
	short value_class; // Represents the item's value for random treasures
		// from 0 - 10, if -1, no class.
	
	// property flags
	unsigned char ident; // if 1, always ident
	unsigned char magic; // if 1, magic item
	unsigned char cursed; // if 1, cursed
	unsigned char once_per_day; // if 1, always ident
	unsigned char junk_item; // if 1, can delete this item to make room in town
	unsigned char extra[4];
	char full_name[30],name[20];
	short augment_item;
};

class item_type {
public:
	item_type();
	void clear_item_type();
	Boolean exists();
	void port();
	
	short which_item; 
		// -1 - null item
		// if 0 - 399, item from scenario list
		// if 1000 + x, is item x is party imported_items list
	location item_loc;
	unsigned char charges;
	unsigned char properties; 
		// bit 0 - ident   1 - property   2 - contained   3 - cursed  4 - used today
	location item_shift;
	
	static unsigned char identified_bit;
	static unsigned char property_bit;
	static unsigned char contained_bit;
	static unsigned char cursed_bit;
	static unsigned char usedToday_bit;
};


class creature_start_type {
public:
	creature_start_type();
	void clear_creature_start_type();
	Boolean exists();
	void port();
	
	short number; // numebr of creature in roster, -1 for none here
	short facing;
	short start_attitude;// 0 - PC, 1 - PC aid, 2 friendly, 3 - neutral, 4 - hostile A, 5 - hostile B
	location start_loc;
	short personality;
	short extra_item;
	short extra_item_chance_1;
	short extra_item_2;
	short extra_item_chance_2;
	short hidden_class;
	short character_id;
		// a number from 0-20000, a unique id for this character

	// timing variable
	short time_flag;
		// Indicates when this char appears. Types 0-9 are only there if
		// the town has not been destroyed.
		// 0 - always here (unless town has been destroyed)
		// 1 - appear at time t, unless town destroyed
		// 2 - disappear at time t
		// 3 - appear if event attached_event not done by time t
		// 4 - disappear if event attached_event not done by time t
		// 5 - appear if event attached_event done
		// 6 - disappear if event attached_event done
		// 7 - here on day 0-2 of every 9 days
		// 8 - here on day 3-5 of every 9 days
		// 9 - here on day 6-8 of every 9 days
		// 10 - here if and only if town has been destroyed
	short creature_time;
	short attached_event;
		// the event that this character is tied to (like a troglo to the
		// troglos killed event)
	short unique_char;
	
	// scripting
	char char_script[SCRIPT_NAME_LEN]; // the name of the default script
	short memory_cells[10];
	short act_at_distance;
	
	short extra[4];
};
	
class preset_field_type {
public:
	preset_field_type();
	void clear_preset_field_type();
	void port();
	
	location field_loc;
	short field_type;
};

// when a terrain spot has a script, the details for that script are remembered in
// this record. It a terrain spot has a script, it MUST has a corresponding
// record of this sort active
class in_town_on_ter_script_type {
public:
	in_town_on_ter_script_type();
	void clear_in_town_on_ter_script_type();
	void port();

	short exists;
	location loc; // location of the terrain spot this is for
	char script_name[SCRIPT_NAME_LEN]; 
	short memory_cells[10];
};


class town_record_type {
public:
	town_record_type();
	void clear_town_record_type();
	void set_start_locs(short town_size);
	void port();

	char town_name[20];
	short respawn_monsts[4][6];
	location respawn_locs[6];
	Rect special_rects[NUM_TOWN_PLACED_SPECIALS];
	unsigned char spec_id[NUM_TOWN_PLACED_SPECIALS];
	short lighting;

	// signs
	location sign_locs[15];
	char sign_text[15][256];

	location start_locs[4];
	location exit_locs[4];
	Rect in_town_rect;
	item_type preset_items[NUM_TOWN_PLACED_ITEMS];	
	preset_field_type preset_fields[NUM_TOWN_PLACED_FIELDS];

	short wall_1_sheet,wall_1_height,wall_2_sheet,wall_2_height,cliff_sheet;
		// how high to make walls and what sheets to look in to get wall graphics
	short beam_type;
		// sort of beams which might be present in level
		// 0 - never, 1 - damage, 2 - impass
	short environmental_sound; // sound to play in background
	short is_on_surface;
	short town_kill_day,town_linked_event;
		// town is cleaned out is event town_linked_event is not done by day town_kill_day
	short external_floor_type;
	short monster_respawn_chance;
	
	// scripts and specials
	char town_script[SCRIPT_NAME_LEN]; 
	in_town_on_ter_script_type ter_scripts[NUM_TER_SCRIPTS];
	
	Rect room_rect[NUM_TOWN_DESCRIPTION_AREAS];
	char info_rect_text[NUM_TOWN_DESCRIPTION_AREAS][30];
	creature_start_type creatures[NUM_TOWN_PLACED_CREATURES];
	short extra[20];
	
	location waypoints[NUM_WAYPOINTS];

	short exit_specs[4];
	short spec_on_entry,spec_on_entry_if_dead;
};

class big_tr_type {
public:
	big_tr_type();
	void clear_big_tr_type();
	void port();
	
	short terrain[64][64];
	unsigned char floor[64][64],height[64][64];
	unsigned char lighting[64][64];
};

class ave_tr_type {
public:
	ave_tr_type();
	void clear_ave_tr_type();
	void port();
	
	short terrain[48][48];
	unsigned char floor[48][48],height[48][48];
	unsigned char lighting[48][48];
};
	
class tiny_tr_type {
public:
	tiny_tr_type();
	void clear_tiny_tr_type();
	void port();
	
	short terrain[32][32];
	unsigned char floor[32][32],height[32][32];
	unsigned char lighting[32][32];
};	


typedef struct {
	short ter_type,item_num[10],item_odds[10],property;
} item_storage_shortcut_type;

class scen_item_data_type {
public:
	scen_item_data_type();
	void clear_scen_item_data_type();
	
	item_record_type scen_items[NUM_SCEN_ITEMS];
	floor_type_type scen_floors[256];
	terrain_type_type scen_terrains[512];
	creature_type scen_creatures[256];
};

//town i's name is stored in town_names[i]
//outdoor section i,j's name is stored in
// section_names[i+out_width*j]
class zone_names_data_type {
public:
	char town_names[200][20];
	char section_names[100][20];
	int out_width;
	int out_height;
	//width and height are stored seperately here as these data structures may 
	//be used to store information about scenarios from which zones are being imported
};

class boat_record_type {
public:
	boat_record_type();
	void clear_boat_record_type();
	void port();
	
	location boat_loc,boat_loc_in_sec,boat_sector;
	short which_town;
	Boolean exists,property;
};
class horse_record_type {
public:
	horse_record_type();
	void clear_horse_record_type();
	void port();
	
	location horse_loc,horse_loc_in_sec,horse_sector;
	short which_town;
	Boolean exists,property;
};
	
class scenario_data_type {
public:
	scenario_data_type();
	void clear_scenario_data_type();
	short scenario_platform();
	void port();
	
	unsigned char flag1, flag2, flag3, flag4;
	// for max, flags are 97 215 7 33
	// for win, flags are 199 61 2 53
	unsigned char ver[3],min_run_ver,prog_make_ver[3],num_towns;
	short out_width,out_height;
	short min_level,max_level;
	short rating;
		
	// labels when selecting scen
	char scen_name[50];
	short scen_label_pic;
	char scen_desc[256];
	
	// credits text
	char credits_text[2][256];
	char comments_text[2][256];
	
	// intro stuff, plays when scen started
	short intro_pic_resources[3];
	char intro_text[3][6][256];
	
	// town data
	unsigned char town_size[200]; // 0 - large, 1 - medium, 2 - small
	unsigned char town_starts_hidden[200];
	
	// starting loc
	short start_in_what_town;
	location what_start_loc_in_town;
	location what_outdoor_section_start_in;
	location start_where_in_outdoor_section;

	// changing town entrances
	short town_to_add_to[10];
	short flag_to_add_to_town[10][2];

	boat_record_type scen_boats[30];
	horse_record_type scen_horses[30];
	item_storage_shortcut_type storage_shortcuts[10];

	location last_out_edited;
	short last_town_edited;
};


// Library
void flip_short(short *s);
void alter_rect(Rect *r);
void flip_rect(Rect *s);

#endif /* Library_h */
