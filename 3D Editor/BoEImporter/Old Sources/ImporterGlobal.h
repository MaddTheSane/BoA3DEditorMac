// global.h

#ifndef GLOBAL_H
#define GLOBAL_H

#include <Carbon/Carbon.h>
#include <string>

// The comments are partial, intermittent, and may be wrong.

//tridash - larger window stuff

#define DEFAULT_WINDOW_WIDTH 516//675//standard value is 750
#define DEFAULT_WINDOW_HEIGHT 455//585//standard value is 550
#define TILES_DRAW_RECT_HEIGHT 520//height of rect drawn to in the tiles window, previously 382
#define TILES_DRAW_RECT_WIDTH 310//width of rect drawn to in the tiles window, previously 210
#define TILES_WINDOW_WIDTH 325//previously 225
#define TILES_DRAW_RECT {20, 0, 20 + TILES_DRAW_RECT_HEIGHT, TILES_DRAW_RECT_WIDTH}//size of rectangle terrain buttons drawn to, standard value is {0, 0, 382, 210}
#define DEFAULT_TERRAIN_RECT_GR_SIZE {0, 0, 512, 512}//size of GWorld for terrain to be drawn to in main window

#define DEFAULT_RECT3DEDIT_HEIGHT 415
#define DEFAULT_RECT3DEDIT_WIDTH 496

extern const Rect default_terrain_viewport_3d;

#define DEFAULT_INDOOR_DRAW_DISTANCE 10//realistic draw distance in towns, used to be 10
#define DEFAULT_OUTDOOR_DRAW_DISTANCE 14//realistic draw distance outdoors, used to be 14

#define TERRAIN_NUM_ROWS 43
#define ITEM_NUM_ROWS 42
#define CREATURE_NUM_ROWS 22
#define FLOOR_NUM_ROWS 22

#define MAIN_WINDOW_NUM 0
#define PALETTE_WINDOW_NUM 1
#define TILES_WINDOW_NUM 2

#define EXILE_BIG_GUNS 1

//lengths of time to wait between events
#define DENSE_TICKS 10
#define SPARSE_TICKS 60
#define VERY_SPARSE_TICKS 300
#define	SLEEP_TICKS 0L

#define	MOUSE_REGION	0L
#define DRAG_EDGE		15
#define IN_FRONT	(WindowPtr)-1L
#define	NIL				0L


#define	NUM_BUTTONS		13
#define	NUM_P_PER_TOWN		20

#define	NUM_DLOG_B		53

#define	MAX_TOWN_SIZE	64
#define OUTDOOR_SIZE	48

#define	TER_RECT_UL_X	20
#define	TER_RECT_UL_Y	20
#define	TERRAIN_BORDER_WIDTH	15
//tridash - larger window stuff
#define	LEFT_TEXT_LINE_ULX	5//default 15
#define	LEFT_TEXT_LINE_ULY	5//default 485
#define	LEFT_TEXT_LINE_WIDTH	240
#define	TEXT_LINE_HEIGHT	12
#define	RIGHT_TEXT_LINE_ULX	25 //default 5
#define	RIGHT_TEXT_LINE_ULY	65 //default 105
#define	RIGHT_BUTTONS_X_SHIFT 500//680//default 540
#define RIGHT_PALETTE_X_SHIFT 500
#define RIGHT_TILES_X_SHIFT 0
#define RIGHT_BUTTONS_Y_SHIFT 0//520//default 382
#define RIGHT_SCROLLBAR_WIDTH 16

#define	PALETTE_BUT_UL_X	0
//#define	PALETTE_BUT_UL_Y	520//default 382

#define NUM_TALK_NODES	100
#define NUM_SCEN_ITEMS	500

#define	SMALL_SPACE_SIZE	8
#define	BIG_SPACE_SIZE	48
#define SPACE_X_DISPLACEMENT_3D  24
#define SPACE_Y_DISPLACEMENT_3D  16
#define ELEVATION_Y_DISPLACEMENT_3D  23
#define PICT_BOX_WIDTH_3D	46
#define PICT_BOX_HEIGHT_3D   55
#define ITEM_BOX_SIZE_3D   28
#define OUTDOOR_CREATURE_WIDTH_3D   11
#define OUTDOOR_CREATURE_HEIGHT_3D	16

#define	TER_BUTTON_HEIGHT_3D	terrain_button_height//default is 19
#define	TER_BUTTON_HEIGHT_3D_OLD	19
#define TER_BUTTON_HEIGHT_3D_STD	27
#define TER_BUTTON_HEIGHT_3D_MID	41
#define TER_BUTTON_HEIGHT_3D_BIG	55

#define TILES_N_COLS tiles_n_columns
#define TILES_N_COLS_STD 12

// new blades consts
#define	SCRIPT_NAME_LEN	14

#define	CDGT	cd_retrieve_text_edit_str
#define	CDGN	cd_retrieve_text_edit_num
#define	CDST	cd_set_text_edit_str
#define	CDSN	cd_set_text_edit_num

#define NUM_WAYPOINTS	10

#define	TER_BUTTON_SIZE	terrain_button_width//default is 16
#define TER_BUTTON_SIZE_BIG 46
#define TER_BUTTON_SIZE_MID 34
#define	TER_BUTTON_SIZE_STD	23//24
#define TER_BUTTON_SIZE_OLD 16

#define	PALETTE_BUT_HEIGHT		17
#define	PALETTE_BUT_WIDTH		25

#define NUM_TER_SCRIPTS	100

#define MAX_NUM_SHEETS_IN_LIBRARY	200

#define NUM_TOWN_PLACED_ITEMS	144
#define NUM_TOWN_PLACED_FIELDS	60
#define NUM_TOWN_PLACED_CREATURES	80
#define NUM_TOWN_PLACED_SPECIALS	60
#define NUM_OUT_PLACED_SPECIALS	30
#define NUM_OUT_TOWN_ENTRANCES	8
#define NUM_TOWN_DESCRIPTION_AREAS 16
#define NUM_OUT_DESCRIPTION_AREAS 8

#define kNO_TOWN_SPECIALS	0xFF	// No Special encounter on town map
#define kNO_OUT_SPECIALS	-1		// No special encounter on outdoor map
#define kNO_OUT_TOWN_ENTRANCE	-1	// No town entrance on outdoor map
#define kNO_SIGN	-1				// No sign in town or outdoors

#define kINVAL_TOWN_LOC_X	-1		// invalid town location
#define kINVAL_TOWN_LOC_Y	-1

#define SDF_RANGE_X	300
#define SDF_RANGE_Y	30

#define TOOL_PALETTE_GUTTER_WIDTH 10
#define TOOL_TITLE_HEIGHT 12
#define TOOL_PALETTE_TEXT_LINE_WIDTH 240
#define TOOL_PALETTE_TEXT_LINE_HEIGHT 12
#define TOOL_PALETTE_TEXT_LINE_SPACING 2
#define TOOL_PALETTE_HEIGHT (4*TOOL_PALETTE_GUTTER_WIDTH + TOOL_TITLE_HEIGHT + TOOL_PALETTE_TEXT_LINE_SPACING + PALETTE_BUT_HEIGHT+1 + 10*(TOOL_PALETTE_TEXT_LINE_HEIGHT+TOOL_PALETTE_TEXT_LINE_SPACING))
#define TOOL_PALETTE_WIDTH (7*TOOL_PALETTE_GUTTER_WIDTH + PALETTE_BUT_WIDTH+1 + TOOL_PALETTE_TEXT_LINE_WIDTH)

const static struct endianness_t{
	bool isLittle;
	endianness_t(){
		uint16_t test=0xFF00;
		isLittle=((uint8_t*)(&test))[0]==0;
	}
} endianness;

// patch to change the mouse click behavior on the dialog button/radio button
// mode selector for cd_press_button()
enum EDLGBtnRes {
	eDLGBtnResCompatible,	// change graphics of the button - sound and delay - recover graphics
	eDLGBtnResChange,		// change graphics of the button - sound (no delay)
	eDLGBtnResRecover,		// recover graphics of the button
};

// bit definition of scroll direction
enum {
	eSCRL_NoScrl	= 0,
	eSCRL_Top		= 0x08,
	eSCRL_Left		= 0x04,
	eSCRL_Bottom	= 0x02,
	eSCRL_Right		= 0x01,
};

//use a wrapping namespace to simulate C++0x strongly typed enum
//when possible this should be switched to an actual strongly type enum
//by removing the namespace and changing 'enum SelectionType_e' to
//'enum class SelectionType'
namespace SelectionType{
	enum SelectionType_e {
		None,
		//Town only:
		Creature,
		Item,
		TerrainScript,
		Waypoint,
		//Town or outdoor:
		SpecialEncounter, 
		AreaDescription,
		Sign,
		//Outdoor only:
		TownEntrance
	};
} //namespace SelectionType

#define	inUpButton	kControlUpButtonPart
#define	inDownButton	kControlDownButtonPart
#define	inPageUp	kControlPageUpPart
#define	inPageDown	kControlPageDownPart
#define	inThumb	kControlIndicatorPart
#define	DisposDialog	DisposeDialog
#define	GetMHandle	GetMenuHandle

typedef struct {
	char x,y;
} location;

//typedef struct {
//	short type,sd1,sd2,pic,m1,m2,ex1a,ex1b,ex2a,ex2b,jumpto;
//	} special_node_type;

typedef struct {
	short which_state,which_personality;
	short condition1[4],condition2[4];
	short action_when_selected,default_jump_state;
	short action_mods[4];
} talking_node_type;

typedef struct {
	unsigned char short_strlens[NUM_TALK_NODES];
	unsigned char strlens[NUM_TALK_NODES * 2];
	char char_names[NUM_P_PER_TOWN][20];
	short p_start_node[NUM_P_PER_TOWN];
	short p_start_state[NUM_P_PER_TOWN];
	talking_node_type talk_nodes[NUM_TALK_NODES];
} talking_record_type;

// The data for the location for an icon in memory.
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
class text_block_type;

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
class script_type;

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

/*struct app_refs{
	FSRef textEditorRef;
	FSRef alintRef;
	FSRef dialogueEditorRef;
	FSRef graphicAdjusterRef;
	UInt8 textEditorPath[512];
	UInt8 alintPath[512];
	UInt8 dialogueEditorPath[512];
	UInt8 graphicAdjusterPath[512];
};*/

extern town_record_type town;
extern scen_item_data_type scen_data;


void trunc_str(char *str);
void clean_str(char *str);
void add_string_to_file(short file_id,const char *str);
void add_string(short file_id,const char *str);
void add_cr(short file_id);
void add_short_string_to_file(short file_id,const char *str1,short num,const char *str2);
void add_big_string_to_file(short file_id,const char *str1,short num1,const char *str2,short num2,const char *str3,short num3,const char *str4);

void c2p(Str255 str);
void p2c(Str255 str);

Boolean load_core_scenario_data();

short get_ran (short times,short  min,short  max);


static inline void flip_short(short *s)
{
	*(unsigned short*)s = ((*(unsigned short*)s >> 8) & 0xFF) | ((*(unsigned short*)s & 0xFF) << 8);
}

static inline void alter_rect(Rect *r)
{
	short a;
	
	a = r->top;
	r->top = r->left;
	r->left = a;
	a = r->bottom;
	r->bottom = r->right;
	r->right = a;
}

static inline void flip_rect(Rect *s)
{
	flip_short(&(s->top));
	flip_short(&(s->bottom));
	flip_short(&(s->left));
	flip_short(&(s->right));
	//alter_rect(s); //It's unclear why this line was ever here, and it was causing horrible errors
}

static inline bool same_point(location l1,location l2)
{
	return((l1.x == l2.x) && (l1.y == l2.y));
}

__unused static short s_pow(short x,short y)
{
	return (short) pow((double) x, (double) y);
}

__unused static short dist(location p1,location p2)
{
	return (short) sqrt((double)((p1.x - p2.x) * (p1.x - p2.x) +
								 (p1.y - p2.y) * (p1.y - p2.y)));
}

static inline short minmax(short min,short max,short k)
{
	if (k < min)
		return min;
	if (k > max)
		return max;
	return k;
}

bool loc_touches_rect(location loc, Rect r);
bool loc_in_active_area(location loc);
terrain_type_type get_ter(short which_ter);

extern FSVolumeRefNum start_volume;
extern SInt32 start_dir;
extern FSSpec current_scenario_file_info;

extern std::string statStr;

#endif
