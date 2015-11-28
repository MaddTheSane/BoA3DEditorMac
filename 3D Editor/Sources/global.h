// global.h

#ifndef GLOBAL_H
#define GLOBAL_H

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
class graphic_id_type;
class floor_type_type;
class terrain_type_type;
class out_wandering_type;
class outdoor_record_type;
class creature_type;
class item_record_type;
class item_type;
class creature_start_type;
class preset_field_type;

// when a terrain spot has a script, the details for that script are remembered in
// this record. It a terrain spot has a script, it MUST has a corresponding
// record of this sort active
class in_town_on_ter_script_type;
class town_record_type;
class big_tr_type;
class ave_tr_type;
class tiny_tr_type;
class scen_item_data_type;

//town i's name is stored in town_names[i]
//outdoor section i,j's name is stored in
// section_names[i+out_width*j]
class zone_names_data_type;
class boat_record_type;
class horse_record_type;
class scenario_data_type;

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

#endif