#include <Carbon/Carbon.h>	// included in pre-compiled header
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "ImporterGlobal.h"
#include "EdFcns.h"
#include "Graphics.h"
#include <stdexcept>
#include <algorithm>

using std::min;
using std::max;

#define	MAX_RECURSION_DEPTH	200

// Edit screen coordinate
Rect kRect3DEditScrn = {
	0 + TER_RECT_UL_X,
	0 + TER_RECT_UL_Y,
	DEFAULT_RECT3DEDIT_HEIGHT + TER_RECT_UL_X,
	DEFAULT_RECT3DEDIT_WIDTH + TER_RECT_UL_Y
};

extern Rect terrain_viewport_3d;
extern unsigned int terrain_width_2d;
extern unsigned int terrain_height_2d;
extern int TER_RECT_UL_X_2d_big;
extern int TER_RECT_UL_Y_2d_big;
extern int TER_RECT_UL_X_2d_small;
extern int TER_RECT_UL_Y_2d_small;

extern int terrain_button_height;
extern int terrain_button_width;

extern int tiles_n_columns;

extern int indoor_draw_distance;
extern int outdoor_draw_distance;

extern scenario_data_type scenario;
extern town_record_type town;
extern scen_item_data_type scen_data;
extern outdoor_record_type border_terrains[3][3];
extern short cur_town;
extern location cur_out;
extern short current_drawing_mode;
extern short town_type ;
extern short current_height_mode ;
extern Boolean editing_town;
extern short cur_viewing_mode;
extern short overall_mode;
extern short previous_tool;
bool object_sticky_draw;
extern Boolean small_any_drawn;

extern Boolean file_is_loaded,mouse_button_held;
extern bool delimit_undo_on_mouse_up;
extern short cen_x, cen_y;

extern short mode_count;
extern Boolean change_made_town,change_made_outdoors;
extern WindowPtr	mainPtr;
//tridash - moving stuff to panels
extern WindowPtr palettePtr;
extern WindowPtr tilesPtr;

extern SelectionType::SelectionType_e selected_object_type;
extern unsigned short selected_object_number;
extern item_type copied_item;
extern creature_start_type copied_creature;
extern short max_zone_dim[3];

extern Rect terrain_buttons_rect;
extern Rect tilesRect;
extern ControlHandle right_sbar;
extern short store_control_value ;
extern in_town_on_ter_script_type copied_ter_script;

extern short current_cursor;
extern short ticks_to_wait;
extern bool allow_arrow_key_navigation;
extern Boolean scroll_dialog_lock;
big_tr_type t_d;
big_tr_type clipboard;
Rect clipboardSize;
Boolean dataOnClipboard=false;
outdoor_record_type current_terrain;

Rect terrain_rects[516];//was 264		/*terrain_rect_base = {0,0,16,16}*/						
Rect terrain_rects_3D[516];//was 264		/*terrain_rect_base_3D = {0,0,16,16}*/						
Rect palette_buttons[9][6];
Rect mode_buttons[5];
Rect view_buttons[2];

// Bottom text rectangles
Rect left_text_lines[10];
// right_text_lines rects are for INSIDE the buttons GWORLD, NOT the screen.
Rect right_text_lines[5];

namespace tools{
Rect toolCategoryTownRect;
Rect toolCategoryOutdoorRect;
Rect toolDetailsRect;
	
Rect autohillsButtonRect;
	
	const int nCategories = 6;
	
	int lastUsedTools[nCategories] = {0, //basic drawing, pencil
	                                  20, //advanced drawing, set height
	                                  23, //copy and paste, copy terrain
	                                  16, //'Object' creation, place special encounter
	                                  40, //selection, select object (only tool)
	                                  61}; //(town mode) object/field/stain placement, make space blocked

//TODO: make Change Terrain Randomly into a standard tool
//do the same for set town boundaries
int categoryForTool[83] = {
	0, 0, 0, 0, 0, //the pencil, brushes, and spray cans are basic drawing
	2, //paste terrain is copy and paste
	0, //the eyedropper is, for now, basic drawing //-1, //the eyedropper has no assigned category
	0, //the paint bucket is basic drawing
	-1, -1, //tools 8 and 9 do not exist
	1, 1, //frame and fill rectangle are advanced drawing
	-1, -1, -1, -1, //tools 12-15 do not exist
	3, //place special encounter is 'Object' creation
	-1, //set town boundaries has no category (should be put into 'Object' creation)
	1, 1, 1, //swap walls, add walls, and set height are advanced drawing
	3, 3, //description rectangle and town entrance are 'Object' creation
	2, //copy terrain is copy and paste
	1, //change height is advanced drawing
	-1, -1, -1, //rectangle redrawing tools have no category
	-1, -1, //tools 28 and 29 do not exist
	3, 3, 3, 3, //(town mode) entrance placement is 'Object' creation
	-1, -1, -1, -1, -1, -1, //tools 34-39 do not exist
	4, //object selection is selection
	-1, //object deletion has no category
	-1, -1, -1, //tools 42-44 do not exist
	1, //change terrain randomly is advanced drawing
	0, 0, //placing creatures and items are basic drawing
	-1, -1, -1, //pasting instances and deleting and editing special encounters have no category
	-1, -1, -1, -1, -1, -1, //tools 51-56 do not exist
	3, //plaing a waypoint is 'Object' creation
	-1, -1, //deleting waypoints and editing signs have no category
	3, //placing spawn points is 'Object' creation
	5, 5, 5, 5, 5, 5, 5, 5, //block space, clean space, objects and stains
	-1, //edit town entrance has no category
	3, //place terrain script is 'Object' creation
	-1, -1, //starting point placement has no category
	5, 5, //placing mirrors
	5, 5, 5, 5, 5, 5, 5, 5 //placing stains
};

int toolIcons[83][3] = {
	{0,0,0}, //pencil
	{0,1,0}, //large paintbrush
	{0,2,0}, //small paintbrush
	{0,3,0}, //large spraycan
	{0,4,0}, //small spraycan
	{0,8,1}, //paste terrain
	{0,5,1}, //eyedropper
	{0,6,1}, //paint bucket
	{-1,-1,-1}, //tool 8 (does not exist)
	{-1,-1,-1}, //tool 9 (does not exist)
	{0,7,0}, //frame rectangle
	{0,6,0}, //fill rectangle
	{-1,-1,-1}, //tool 12 (does not exist)
	{-1,-1,-1}, //tool 13 (does not exist)
	{-1,-1,-1}, //tool 14 (does not exist)
	{-1,-1,-1}, //tool 15 (does not exist)
	{0,1,2}, //place special encounter
	{-1,-1,-1}, //set town boundaries
	{0,3,1}, //swap wall types
	{0,8,0}, //bounding walls
	{0,5,0}, //set height rectangle
	{0,3,2}, //place area description
	{1,6,2}, //create town entrance
	{0,7,1}, //copy terrain
	{0,5,0}, //change height rectangle
	{-1,-1,-1}, //redraw special encounter
	{-1,-1,-1}, //redraw town entrance
	{-1,-1,-1}, //redraw area description
	{-1,-1,-1}, //tool 28 (does not exist)
	{-1,-1,-1}, //tool 29 (does not exist)
	{0,5,3}, //place north entrance
	{0,6,3}, //place west entrance
	{0,7,3}, //place south entrance
	{0,8,3}, //place east entrance
	{-1,-1,-1}, //tool 34 (does not exist)
	{-1,-1,-1}, //tool 35 (does not exist)
	{-1,-1,-1}, //tool 36 (does not exist)
	{-1,-1,-1}, //tool 37 (does not exist)
	{-1,-1,-1}, //tool 38 (does not exist)
	{-1,-1,-1}, //tool 39 (does not exist)
	{0,0,2}, //select instance
	{-1,-1,-1}, //delete instance
	{-1,-1,-1}, //tool 42 (does not exist)
	{-1,-1,-1}, //tool 43 (does not exist)
	{-1,-1,-1}, //tool 44 (does not exist)
	{0,4,1}, //change terrain randomly
	{0,0,0}, //place creature
	{0,0,0}, //place item
	{-1,-1,-1}, //paste instance
	{-1,-1,-1}, //delete special encounter
	{-1,-1,-1}, //set special encounter
	{-1,-1,-1}, //tool 51 (does not exist)
	{-1,-1,-1}, //tool 52 (does not exist)
	{-1,-1,-1}, //tool 53 (does not exist)
	{-1,-1,-1}, //tool 54 (does not exist)
	{-1,-1,-1}, //tool 55 (does not exist)
	{-1,-1,-1}, //tool 56 (does not exist)
	{0,6,2}, //place waypoint
	{0,7,2}, //delete waypoint
	{0,2,2}, //edit sign
	{0,8,2}, //place spawn point
	{0,0,4}, //make space blocked
	{0,1,4}, //place web
	{0,2,4}, //place crate
	{0,3,4}, //place barrel
	{0,4,4}, //place fire barrier
	{0,5,4}, //place force barrier
	{0,0,5}, //clear space
	{-1,-1,-1}, //place stains (old)
	{1,7,2}, //edit town entrance
	{0,4,2}, //place terrain script
	{-1,-1,-1}, //place outdoor start point
	{-1,-1,-1}, //place town start point
	{0,6,4}, //place NE/SW mirror
	{0,7,4}, //place NW/SE mirror
	{0,1,5}, //place small blood stain
	{0,2,5}, //place medium blood stain
	{0,3,5}, //place large blood stain
	{0,4,5}, //place small slime pool
	{0,5,5}, //place large slime pool
	{0,6,5}, //place dried blood
	{0,7,5}, //place bones
	{0,8,5} //place rocks
};

const char* tool_names[83] = {
	"Pencil",
	"Paintbrush (Large)",
	"Paintbrush (Small)",
	"Spraycan (Large)",
	"Spraycan (Small)",
	"Paste Terrain",
	"Eyedropper",
	"Paint bucket",
	"Tool 8 (Does not exist)",
	"Tool 9 (Does not exist)",
	"Fill Rectangle",
	"Frame Rectangle",
	"Tool 12 (Does not exist)",
	"Tool 13 (Does not exist)",
	"Tool 14 (Does not exist)",
	"Tool 15 (Does not exist)",
	"Place Special Encounter",
	"Set Town Boundaries",
	"Swap Wall Types",
	"Place Bounding Walls",
	"Set Height (Rectangle)",
	"Place Area Description",
	"Create Town Entrance",
	"Copy Terrain",
	"Change Height (Rectangle)",
	"Redraw Special Encounter",
	"Redraw Town Entrance",
	"Redraw Area Description",
	"Tool 28 (Does not exist)",
	"Tool 29 (Does not exist)",
	"Place North Town Entrance",
	"Place West Town Entrance",
	"Place South Town Entrance",
	"Place East Town Entrance",
	"Tool 34 (Does not exist)",
	"Tool 35 (Does not exist)",
	"Tool 36 (Does not exist)",
	"Tool 37 (Does not exist)",
	"Tool 38 (Does not exist)",
	"Tool 39 (Does not exist)",
	"Select Object",
	"Delete Object",
	"Tool 42 (Does not exist)",
	"Tool 43 (Does not exist)",
	"Tool 44 (Does not exist)",
	"Replace Terrain",
	"Place Creature",
	"Place Item",
	"Paste Object",
	"Delete Special Encounter",
	"Set Special Encounter",
	"Tool 51 (Does not exist)",
	"Tool 52 (Does not exist)",
	"Tool 53 (Does not exist)",
	"Tool 54 (Does not exist)",
	"Tool 55 (Does not exist)",
	"Tool 56 (Does not exist)",
	"Place Waypoint",
	"Delete Waypoint",
	"Edit Sign",
	"Place Spawn Point",
	"Make Space Blocked",
	"Place Web",
	"Place Crate",
	"Place Barrel",
	"Place Fire Barrier",
	"Place Force Barrier",
	"Clear Space",
	"Place Stain", //old
	"Edit Town Entrance",
	"Place Terrain Script",
	"Place Outdoor Start Point",
	"Place Town Start Point",
	"Place NE/SW Mirror",
	"Place NW/SE MIrror",
	"Place Small Blood Stain",
	"Place Medium Blood Stain",
	"Place Large Blood Stain",
	"Place Small Slime Pool",
	"Place Large Slime Pool",
	"Place Dried Blood",
	"Place Bones",
	"Place Rocks"
};

Rect tool_details_text_lines[10];
	
} //namespace tools

#pragma mark -
static bool old_can_see_in(location p1,location p2,short check_light,short check_travel);
static void old_can_see(location p1,location p2,short check_light,short check_travel,bool *see_to,bool *see_in);
static void can_see(location p1,location p2,short check_light,short check_travel,bool *see_to,bool *see_in);

static bool can_see_single(location p1,location p2,short check_light,short check_travel,bool *see_to);

bool look_block(location l, short direction);
bool move_block(location l, short direction);
bool no_block(location l, short direction,short check_light,short check_travel);


static void shift_item_locs(location spot_hit);

#pragma mark -

Boolean hintbook_mode = FALSE;

static short current_terrain_type = 0;
short current_floor_drawn = 0;
short current_terrain_drawn = 0;

typedef struct {
	unsigned nw_corner : 2;
	unsigned sw_corner : 2;
	unsigned se_corner : 2;
	unsigned ne_corner : 2;
	unsigned see_in : 1;
	unsigned see_to : 1;
} temp_space_info, *temp_space_info_ptr;

static temp_space_info corner_and_sight_map[88][88];

// if a terrain type has special property from 19-30, it is a slope. this
// array says what corners for these 12 terrain types are elevated.
// first field is nw corner
// 2nd field is sw corner
// 3rd field is se corner
// 4th field is ne corner
// if 1, is elevated
short hill_c_heights[12][4] = {{1,1,0,0},{0,1,0,0},{0,1,1,0},
	{0,0,1,0},{0,0,1,1},{0,0,0,1},
	{1,0,0,1},{1,0,0,0},{1,1,0,1},
	{1,1,1,0},{0,1,1,1},{1,0,1,1}};

static short recursive_depth = 0; // used for recursive hill/terrain correcting function
static short recursive_hill_up_depth = 0;
static short recursive_hill_down_depth = 0;

#if 0

//exchanges terrain (or floor) b for terrain (or floor) a with probability c/100
void swap_terrain()
{
	short a,b,c,i,j;
	short ter;
	change_ter(&a,&b,&c);
	if(a < 0)
		return;
	
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	int changingContainers=(scen_data.scen_terrains[b].special==40)-(scen_data.scen_terrains[a].special==40);
	
	for(i = 0; i < ((editing_town) ? max_zone_dim[town_type] : 48); i++){
		for(j = 0; j < ((editing_town) ? max_zone_dim[town_type] : 48); j++){
			if(current_drawing_mode > 0){ //replace terrain
				ter = (editing_town) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
				if((ter == a) && (get_ran(1,1,100) <= c)){
					if(editing_town){
						t_d.terrain[i][j] = b;
						if(changingContainers)
							set_items_containment(i,j,changingContainers);
					}
					else 
						current_terrain.terrain[i][j] = b;
					pushUndoStep(new Undo::TerrainChange(i,j,b,a));
				}
			}
			else{ //replace floor
				ter =(editing_town) ? t_d.floor[i][j] : current_terrain.floor[i][j];
				if((ter == a) && (get_ran(1,1,100) <= c)){
					if(editing_town)
						t_d.floor[i][j] = b;
					else 
						current_terrain.floor[i][j] = b;
					pushUndoStep(new Undo::FloorChange(i,j,b,a));
				}
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

//changes the current tool mode
void set_tool(short tool){
	using namespace tools;
	previous_tool=overall_mode;
	overall_mode=tool;
	
	if(categoryForTool[overall_mode]>=0)
		lastUsedTools[categoryForTool[overall_mode]]=overall_mode;
	
	//handle some special cases
	switch(tool){
		case 0: //pencil
			set_cursor(0);
			break;
		case 1: //large paintbrush
		case 2: //small paintbrush
			set_cursor(2);
			break;
		case 3: //large spraycan
		case 4: //small spraycan
			set_cursor(3);
			break;
		case 5: //paste terrain
			set_cursor(5);
			mode_count = 2;
			break;
		case 6: //eyedrpper
			set_cursor(1);
			break;
		case 7: //paint bucket
			set_cursor(10);
			break;
		case 10: //draw filled rectangle
		case 11: //draw hollow rectangle
		case 16: //create special encounter
		case 17: //set town boundaries
		case 18: //swap wall types
		case 19: //place bounding walls
		case 20: //set rectangle height
		case 21: //create description rectangle
		case 22: //create town entrance
		case 23: //copy terrain
		case 24: //change rectangle height
		case 25: //redraw special encounter
		case 26: //redraw town entrance
		case 27: //redraw area dewscription rectangle
			mode_count=2;
			set_cursor(5);
			break;
		case 30: //plcae north town entrance
		case 31: //plcae west town entrance
		case 32: //plcae south town entrance
		case 33: //plcae east town entrance
		case 40: //select object
		case 48: //paste instance
		case 57: //place waypoint
		case 58: //delete waypoint
		case 59: //edit sign
			set_cursor(7);
			break;
		case 60: //place spawn points
			set_cursor(7);
			mode_count = (editing_town ? 6 : 4);
			break;
		case 61: //make space blocked
		case 62: //place web
		case 63: //place crate
		case 64: //place barrel
		case 65: //place fire barrier
		case 66: //place force barrier
			set_cursor(0);
			break;
		case 67: //clear space
			set_cursor(4);
			break;
		case 69: //edit town entrance
		case 70: //place terrain script
		case 71: //set outdoor start point
		case 72: //set town start point
			set_cursor(7);
			break;
		case 73: //place NE/SW mirror
		case 74: //place NW/SE mirror
		case 75: //place small blood stain
		case 76: //place medium blood stain
		case 77: //place large blood stain
		case 78: //place small slime pool
		case 79: //place large slime pool
		case 80: //place dried blood
		case 81: //place bones
		case 82: //place rocks
			set_cursor(0);
			break;
	}
	drawToolPalette();
}

//sets a new terrain for drawing with
void set_new_terrain(short selected_terrain)
{
	if (selected_terrain >= 512)
		return;
	if (scen_data.scen_terrains[selected_terrain].ed_pic.not_legit() == TRUE)
		return;
	current_terrain_drawn = selected_terrain;
	
	//char str1[256],str2[256];
	//sprintf(str1,"Drawing terrain number %d:",current_terrain_drawn);
	//sprintf(str2,"  %s",scen_data.scen_terrains[current_terrain_drawn].ter_name);
	//set_string(str1,str2);
	place_right_buttons(0);
	drawToolPalette();
}

//sets a new floor for drawing with
// check if floor is valid, and, if so, make that floor current floor drawn
void set_new_floor(short selected_terrain)
{
	if (selected_terrain >= 256)
		return;
	if (scen_data.scen_floors[selected_terrain].ed_pic.not_legit() == TRUE)
		return;
	current_floor_drawn = selected_terrain;
	
	//char str1[256],str2[256];
	//sprintf(str1,"Drawing floor number %d:",current_floor_drawn);
	//sprintf(str2,"  %s",scen_data.scen_floors[current_floor_drawn].floor_name);
	//set_string(str1,str2);
	place_right_buttons(0);
	drawToolPalette();
}

//sets a new creature to be placed
void set_new_creature(short selected_creature)
{
	if (selected_creature >= 256)
		return;
	if(!strcmp("Unused",scen_data.scen_creatures[selected_creature].name) || !strcmp("Placeholder",scen_data.scen_creatures[selected_creature].name))
		return;
	set_tool(0);
	current_drawing_mode = 3;
	mode_count = selected_creature;
}

void set_new_item(short selected_item)
{
	if (selected_item >= NUM_SCEN_ITEMS)
		return;
	if (!strcmp("Unused",scen_data.scen_items[selected_item].full_name))
		return;
	set_tool(0);
	current_drawing_mode = 4;
	mode_count = selected_item;
}

// "Outdoor: drawing mode failure after moving section" fix
// As the scroll handler of edit screen is revised,
// key scroll process also needed to rewritten.
bool handle_tenKey( char *chr, char chr2, EventRecord event )
{
	// virtual key code of ten key
	const char ten_key[10] = {82,83,84,85,86,87,88,89,91,92};
	
	// Ten key scroller assignment
	const int scrl_key_2D[10] = {
		eSCRL_NoScrl,			// 0
		eSCRL_Left	|	eSCRL_Bottom,	// 1
		eSCRL_Bottom,	// 2
		eSCRL_Right |	eSCRL_Bottom,	// 3
		eSCRL_Left,						// 4
		eSCRL_NoScrl,			// 5
		eSCRL_Right,					// 6
		eSCRL_Left	|	eSCRL_Top,		// 7
		eSCRL_Top,		// 8
		eSCRL_Right |	eSCRL_Top		// 9
	};
	
	const int scrl_key_3D[10] = {
		eSCRL_NoScrl,			// 0
		eSCRL_Bottom,	// 1
		eSCRL_Right |	eSCRL_Bottom,	// 2
		eSCRL_Right,					// 3
		eSCRL_Left |	eSCRL_Bottom,	// 4
		eSCRL_NoScrl,			// 5
		eSCRL_Right	|	eSCRL_Top,		// 6
		eSCRL_Left,						// 7
		eSCRL_Left |	eSCRL_Top,		// 8
		eSCRL_Top		// 9
	};
	
	Point kCenterPoint = {TER_RECT_UL_Y_2d_big + TERRAIN_BORDER_WIDTH + (terrain_width_2d/2) * BIG_SPACE_SIZE,TER_RECT_UL_X_2d_big + TERRAIN_BORDER_WIDTH + (terrain_height_2d/2) * BIG_SPACE_SIZE};
	
	// Ten key handling
	for ( int i = 0; i < 10; i++) {
		if ( chr2 == ten_key[i] ) {
			if (i == 0) {				// "0" key
				*chr = 'z';
				break;
			}
			else if ( i == 5 ) {		// "5" key
				if (cur_viewing_mode == 0) {
					handle_action( kCenterPoint, event, MAIN_WINDOW_NUM );
					mouse_button_held = FALSE;
					return true;
				}
				else if(cur_viewing_mode >= 10){
					kCenterPoint.h = 253+TER_RECT_UL_X;
					kCenterPoint.v = 212+TER_RECT_UL_Y;
					handle_action( kCenterPoint, event, MAIN_WINDOW_NUM );
					mouse_button_held = FALSE;
					return true;
				}
				break;
			}
			else {						// other ten keys
				bool ctrlKey = ((event.modifiers & controlKey) != 0);
				bool shftKey = ((event.modifiers & shiftKey) != 0);
				int map_size = (editing_town) ? max_zone_dim[town_type] : 48;
				int scrl = eSCRL_NoScrl;
				if (cur_viewing_mode == 0)
					scrl = scrl_key_2D[ i ];
				if (cur_viewing_mode == 10 || cur_viewing_mode == 11)
					scrl = scrl_key_3D[ i ];
				if ( scrl != eSCRL_NoScrl ) {
					handle_scroll( map_size, scrl, ctrlKey, shftKey );
					return true;
				}
				break;
			}
		}
	}
	
	return false;
}

//returns true if loc is not conveniently visible from the current 3D viewport
//TODO: This is wrong when the main window has been resized!
bool out_of_view_3D(location loc){
	if(cen_x-loc.x>10 || loc.x-cen_x>9 || cen_y-loc.y>10 || loc.y-cen_y>9)
		return(true);
	int x = loc.x-cen_x;
	int y = loc.y-cen_y;
	return((y<x-9) || (y<-12-x) || (y>x+9) || (y>11-x));
}

// "Outdoor: drawing mode failure after moving section" fix
// handle ten key on a separate subroutine
void handle_keystroke(char chr,char chr2,EventRecord event){
	short i,j;
	
	if ( handle_tenKey( &chr, chr2, event ) )
		return;
	
	if (cur_viewing_mode == 10 || cur_viewing_mode == 11) {
		//fix problem with pressing some keys in this mode
		if(chr == '1' || chr == '2' || chr == '3' || chr == '4' || chr == '5')
			return;
	}
	
	//handle arrow keys
	if(chr2 >= 123 && chr2 <= 126){
		//navigation among towns and outdoor sections
		if(event.modifiers & cmdKey){
			int targetZone=-1;
			switch(chr2){
				case 126: //up
					if(!editing_town){
						if(cur_out.y>0)
							targetZone=cur_out.x*100 + cur_out.y-1;
						else
							EdSysBeep(20);
					}
					else
						EdSysBeep(20);
					break;
				case 125: //down
					if(!editing_town){
						if(cur_out.y<scenario.out_height-1)
							targetZone=cur_out.x*100 + cur_out.y+1;
						else
							EdSysBeep(20);
					}
					else
						EdSysBeep(20);
					break;
				case 124: //right
					if(editing_town){
						if(cur_town<scenario.num_towns - 1)
							targetZone=cur_town+1;
						else
							EdSysBeep(20);
					}
					else{
						if(cur_out.x<scenario.out_width-1)
							targetZone=(cur_out.x+1)*100 + cur_out.y;
						else
							EdSysBeep(20);
					}	
					break;
				case 123: //left
					if(editing_town){
						if(cur_town>0)
							targetZone=cur_town-1;
						else
							EdSysBeep(20);
					}
					else{
						if(cur_out.x>0)
							targetZone=(cur_out.x-1)*100 + cur_out.y;
						else
							EdSysBeep(20);
					}
					break;
			}
			if(targetZone!=-1){
				if(editing_town){
					//if no changes were made, or the user okays it, go ahead
					if(!change_made_town || save_check(859)){
						load_town(targetZone);
						clear_selected_copied_objects();
						set_up_terrain_buttons();
						change_made_town = FALSE;
						cen_x = max_zone_dim[town_type] / 2; cen_y = max_zone_dim[town_type] / 2;
						reset_drawing_mode();
						reset_small_drawn();
						purgeUndo();
						purgeRedo();
						update_terrain_window_title();
						redraw_screen();
					}
				}
				else{//editing outdoors
					//if no changes were made, or the user okays it, go ahead
					if(!change_made_outdoors || save_check(859)){
						location spot_hit = {targetZone / 100,targetZone % 100};
						clear_selected_copied_objects();
						augment_terrain(spot_hit);
						set_up_terrain_buttons();
						cen_x = 24; cen_y = 24;
						reset_drawing_mode();
						purgeUndo();
						purgeRedo();
						update_terrain_window_title();
						redraw_screen();
						change_made_outdoors = FALSE;
					}
				}
			}
		}
		//this is a little complicated:
		//in the case that new navigation by arrow keys is allowed:
		//without modifiers, the arrow keys move the viewport in the specified directions
		//	with just the shift key the viewport is moved in large steps (7 units)
		//	with just the control key the viewport is moved to the edge of the current zone
		//	with the option key the keystroke applies to the selected object, if any
		//		with the option key only the selected object is shifted in the specified direction
		//		with the option key and shift key the selected object is rotated
		//if the new navigation system is not allowed, the old style is used
		//	without modifiers, the arrow keys move the selected object
		//	with the shift key the selected object is rotated instead
		else if(cur_viewing_mode == 0 || cur_viewing_mode == 10 || cur_viewing_mode == 11) {
			if(allow_arrow_key_navigation){ //use new style controls
				if(!((event.modifiers & optionKey) || (event.modifiers & cmdKey))){ //move the view
					switch(chr2){
						case 126: //up
							handle_scroll( (editing_town ? max_zone_dim[town_type] : 48), eSCRL_Top, (event.modifiers & controlKey), (event.modifiers & shiftKey) );
							break;
						case 124: //right
							handle_scroll( (editing_town ? max_zone_dim[town_type] : 48), eSCRL_Right, (event.modifiers & controlKey), (event.modifiers & shiftKey) );
							break;
						case 123: //left
							handle_scroll( (editing_town ? max_zone_dim[town_type] : 48), eSCRL_Left, (event.modifiers & controlKey), (event.modifiers & shiftKey) );
							break;
						case 125: //down
							handle_scroll( (editing_town ? max_zone_dim[town_type] : 48), eSCRL_Bottom, (event.modifiers & controlKey), (event.modifiers & shiftKey) );
							break;
					}
				}
				else if((event.modifiers & optionKey) && selected_object_type!=SelectionType::None){ 
					if(!(event.modifiers & shiftKey)){ //move the selected instance
						switch(chr2){
							case 126: //up
								shift_selected_instance(0, -1);
								break;
							case 124: //right
								shift_selected_instance(1,0);
								break;
							case 123: //left
								shift_selected_instance(-1,0);
								break;
							case 125: //down
								shift_selected_instance(0, 1);
								break;
						}
						location new_loc = selected_instance_location();
						if(new_loc.x>-1){
							if((cur_viewing_mode == 0 && (abs(new_loc.x-cen_x)>4 || abs(new_loc.y-cen_y)>4)) || ((cur_viewing_mode==10 || cur_viewing_mode==11) && out_of_view_3D(new_loc))){
								cen_x = new_loc.x;
								cen_y = new_loc.y;
								draw_terrain();
							}
						}
					}
					else if((event.modifiers & shiftKey) && selected_object_type==SelectionType::Creature){ //rotate the selected instance
						switch(chr2){
							case 126: //up
							case 125: //down
								rotate_selected_instance(2);
								break;
							case 124: //right
								rotate_selected_instance(-1);
								break;
							case 123: //left
								rotate_selected_instance(1);
								break;
						}
					}
				}
			}
			else{ //fall back on old functionality
				if ((chr2 == 126) && selected_object_type!=SelectionType::None){
					if(event.modifiers & shiftKey)
						rotate_selected_instance(2);
					else
						shift_selected_instance(0, -1);
				}
				if ((chr2 == 124) && selected_object_type!=SelectionType::None){
					if(event.modifiers & shiftKey)
						rotate_selected_instance(-1);
					else
						shift_selected_instance(1,0);
				}
				if ((chr2 == 123) && selected_object_type!=SelectionType::None){
					if(event.modifiers & shiftKey)
						rotate_selected_instance(1);
					else
						shift_selected_instance(-1,0);
				}
				if ((chr2 == 125) && selected_object_type!=SelectionType::None){
					if(event.modifiers & shiftKey)
						rotate_selected_instance(2);
					else
						shift_selected_instance(0, 1);
				}
				location new_loc = selected_instance_location();
				if(new_loc.x>-1){
					if((cur_viewing_mode == 0 && (abs(new_loc.x-cen_x)>4 || abs(new_loc.y-cen_y)>4)) || ((cur_viewing_mode==10 || cur_viewing_mode==11) && out_of_view_3D(new_loc))){
						cen_x = new_loc.x;
						cen_y = new_loc.y;
						draw_terrain();
					}
				}
			}
			draw_terrain();
			return;
		}
	}
	if((chr2 == 51) || (chr2 == 117))
		delete_selected_instance();
	
	switch(chr){
		case 'M':
			hintbook_mode = !hintbook_mode;
			small_any_drawn = FALSE;
			draw_terrain();
			break;
			
		//case '1': case '2': case '3': case '4': case '5': 
			//TODO: Use the number keys for shortcuts
			//Previously used for selecting crates, barrels, etc.
		//	break;
			
		case 'F':
			if (current_drawing_mode == 2) {//Change Height Rect
				if(!(event.modifiers & shiftKey)){
					set_tool(20);//Set Height Rect
				}
				else{
					set_tool(24);//Change Height Rect
				}
			}
			else {//Fill Rect Solid
				set_tool(10);
			}
			break; 
		case 'H':
			if (current_drawing_mode == 2) {//Change Height Rect
				if(!(event.modifiers & shiftKey)){
					set_tool(20);//Set Height Rect
				}
				else{
					set_tool(24);//Change Height Rect
				}
			}
			else {//Fill Rect Hollow
				set_tool(11);
			}
			break;
		case 'P': //switch back to pencil drawing
			set_tool(0);
			break;
		case ' ': //cycle drawing mode
			set_drawing_mode((current_drawing_mode + 1) % (editing_town ? 5 : 3));
			draw_main_screen();
			break; 
		case '\t': //switch 2D to 3D and vice versa
			if ((event.modifiers & optionKey) != 0) {
				toggle_zoomedOut();
			}
			else {
				toggle_3D();
			}
			break;
		case 'S':
			set_tool(40); //select
			place_right_buttons(0);
			break;
		case 'W':
			set_tool(18); //swap walls
			place_right_buttons(0);
			break;
		case 'A': 
			set_tool(19); //place bounding walls
			place_right_buttons(0);
			break;
		case 'Z':
			performUndo();
			break;
		case 'Y':
			performRedo();
			break;
		case 'J': //jump to selected object
			jumpToSelectedInstance();
			break;
		case 'C':
			set_tool(23); //copy terrain
			break;
		case 'V':
			set_tool(5); //paste terrain
			break;
		default:
			if (('a' <= chr) && (chr <= 'z')) {
				if (current_drawing_mode == 0) { // use shortcut keys, if editing floor
					for (i = 0; i < 256; i++) {
						j = current_floor_drawn + i + 1;
						j = j % 256;
						if ((scen_data.scen_floors[j].shortcut_key < 26) && (scen_data.scen_floors[j].shortcut_key == chr - 'a')) {
							set_new_floor(j);
							return;	
						}
					}
					for (i = 0; i < 512; i++) {
						j = current_terrain_type + i + 1;
						j = j % 512;
						if ((scen_data.scen_terrains[j].shortcut_key < 26) && (scen_data.scen_terrains[j].shortcut_key == chr - 'a')) {
							set_new_terrain(j);
							return;	
						}
					}
				}
				if (current_drawing_mode > 0) { // use shortcut keys, if editing terrain
					for (i = 0; i < 512; i++) {
						j = current_terrain_type + i + 1;
						j = j % 512;
						if ((scen_data.scen_terrains[j].shortcut_key < 26) && (scen_data.scen_terrains[j].shortcut_key == chr - 'a')) {
							set_new_terrain(j);
							return;	
						}
					}
					for (i = 0; i < 256; i++) {
						j = current_floor_drawn + i + 1;
						j = j % 256;
						if ((scen_data.scen_floors[j].shortcut_key < 26) && (scen_data.scen_floors[j].shortcut_key == chr - 'a')) {
							set_drawing_mode(0);
							set_new_floor(j);
							return;	
						}
					}
				}
			}
			break;
	}
	draw_terrain();
	drawToolPalette(); //TODO: don't call this unconditionally
	mouse_button_held = FALSE;
}

//tests if terrain at location (i,j) is a hill. Returns TRUE if (i,j) is out of bounds
Boolean is_hill(short i,short j)
{
	
	Boolean answer = FALSE;
	short ter;
	
	ter = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return TRUE;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return TRUE;
	if ((ter >= 74) && (ter <= 121)) 
		answer = TRUE;	
	if (ter == 255)
		answer = TRUE;	
	return answer;		
}

// Returns true if rocky cave floor or desert
Boolean is_rocks(short i,short j)
{
	Boolean answer = FALSE;
	short ter;
	
	ter = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return TRUE;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return TRUE;
	
	if (ter == 255)
		answer = TRUE;	
	
	if (scen_data.scen_floors[ter].is_rough)
		answer = TRUE;	
	
	return answer;		
}

// Returns true if space is any sort of water
Boolean is_water(short i,short j)
{
	Boolean answer = FALSE;
	short ter;
	
	ter = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return TRUE;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return TRUE;
	
	if (ter == 255)
		answer = TRUE;	
	if (scen_data.scen_floors[ter].is_water)
		answer = TRUE;	
	
	return answer;		
}
#endif

/// return true if the indicated space is a container, taking into account barrels and crates
static bool is_container(short x, short y){
	return((scen_data.scen_terrains[t_d.terrain[x][y]].special==40) || is_crate(x,y) || is_barrel(x,y));
}

#if 0
// prob is 0 - 20, 0 no, 20 always
void shy_change_circle_terrain(location center,short radius,short terrain_type,short probability)
{
	location l;
	short i,j;
	short ter;
	//printf("Shy:(%i, %i), %i, %i\n",center.x,center.y,terrain_type,probability);
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			l.x = i;
			l.y = j;
			if (current_drawing_mode == 0) {
				ter = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
				if ((dist(center,l) <= radius) && (get_ran(1,1,20) <= probability) && (ter == 0))
					set_terrain(l,terrain_type);
			}
			else {
				ter = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
				if ((dist(center,l) <= radius) && (get_ran(1,1,20) <= probability) 
					&& (ter == 0))
					set_terrain(l,terrain_type);
			}
		}
	}
}

//changes terrain within the circle of given radius and center with probability that any given space is changed
void change_circle_terrain(location center,short radius,short terrain_type,short probability)
// prob is 0 - 20, 0 no, 20 always
{
	location l;
	short i,j;
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			l.x = i;
			l.y = j;
			if ((dist(center,l) <= radius) && (get_ran(1,1,20) <= probability))
				set_terrain(l,terrain_type);
		}
	}
}

//changes height within the circle of given radius and center with probability that any given space is changed
void change_circle_height(location center,short radius,short lower_or_raise,short probability)
// prob is 0 - 20, 0 no, 20 always
{
	location l;
	short i,j;
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			l.x = i;
			l.y = j;
			if ((dist(center,l) <= radius) && (get_ran(1,1,20) <= probability))
				change_height(l,lower_or_raise);
		}
	}
}

//This is a scan-line flood-fill algorithm to replace all connected spaces of old_floor with new_floor
//squares that touch corners are not considered connected
int flood_fill_floor(short new_floor, short old_floor, int x, int y){
	//flood fill is recursive, so to avoid lots of extra nested groups, handle undo grouping from outside
	int minx=x, maxx=x;
	if(floors_match(new_floor,old_floor))
		return(-1);
	short i,max_size=((editing_town == TRUE) ? max_zone_dim[town_type] : OUTDOOR_SIZE);
	//start at the seed point and move right to find one end of the line
	for (i = x; i < max_size; i++){
		if(editing_town){
			if(!floors_match(t_d.floor[i][y],old_floor)){
				maxx=i-1;
				break;
			}
		}
		else if(!floors_match(current_terrain.floor[i][y],old_floor)){
			maxx=i-1;
			break;
		}
	}
	//if we went all the way to the edge of the zone without finding the end, the end must be the edge
	if((i==max_size) && maxx==x)
		maxx=max_size-1;
	//start at the seed point again and move left to find the other end of the line
	for (i = x; i>=0; i--){
		if(editing_town){
			if(!floors_match(t_d.floor[i][y],old_floor)){
				minx=i+1;
				break;
			}
		}
		else if(!floors_match(current_terrain.floor[i][y],old_floor)){
			minx=i+1;
			break;
		}
	}
	//set the edge of the zone to be the end if we couldn't find the end
	if(i==-1 && minx==x)
		minx=0;
	//fill the line
	location l;
	l.y=y;
	for(i=minx; i<=maxx;i++){
		l.x=i;
		set_terrain(l,new_floor);
	}
	//fill connected spaces in the row above
	if(y>0){
		for(i=minx; i<=maxx;i++){
			if(editing_town && floors_match(t_d.floor[i][y-1],old_floor)){
				if(flood_fill_floor(new_floor,old_floor,i,y-1)>=maxx)
					break;//if the recursive call filled farther out than the
				//end of the current line, we know we don't need to check any farther
			}
			else if(floors_match(current_terrain.floor[i][y-1],old_floor)){
				if(flood_fill_floor(new_floor,old_floor,i,y-1)>=maxx)
					break;
			}
		}
	}
	//fill connected spaces in the row below
	if(y<(max_size-1)){
		for(i=minx; i<=maxx;i++){
			if(editing_town && floors_match(t_d.floor[i][y+1],old_floor)){
				if(flood_fill_floor(new_floor,old_floor,i,y+1)>=maxx)
					break;
			}
			else if(floors_match(current_terrain.floor[i][y+1],old_floor)){
				if(flood_fill_floor(new_floor,old_floor,i,y+1)>=maxx)
					break;
			}
		}
	}
	//return the farthest exent of this scan line; this value is used to
	//optimize the recursion, and can be ignored by any other functions
	//that call this one
	return(maxx);
}

int flood_fill_terrain(short new_terrain, short old_terrain, int x, int y){
	//flood fill is recursive, so to avoid lots of extra nested groups, handle undo grouping from outside
	int minx=x, maxx=x;
	int changingContainers=(scen_data.scen_terrains[new_terrain].special==40)-(scen_data.scen_terrains[old_terrain].special==40);
	if(new_terrain==old_terrain)
		return(-1);
	short i,max_size=((editing_town == TRUE) ? max_zone_dim[town_type] : 48);
	for (i = x; i < max_size; i++){
		if(editing_town){
			if(t_d.terrain[i][y]!=old_terrain){
				maxx=i-1;
				break;
			}
		}
		else if(current_terrain.terrain[i][y]!=old_terrain){
			maxx=i-1;
			break;
		}
	}
	if((i==max_size) && maxx==x)
		maxx=max_size-1;
	for (i = x; i>=0; i--){
		if(editing_town){
			if(t_d.terrain[i][y]!=old_terrain){
				minx=i+1;
				break;
			}
		}
		else if(current_terrain.terrain[i][y]!=old_terrain){
			minx=i+1;
			break;
		}
	}
	if(i==-1 && minx==x)
		minx=0;
	for(i=minx; i<=maxx;i++){
		if(editing_town)
			t_d.terrain[i][y]=new_terrain;
		else
			current_terrain.terrain[i][y]=new_terrain;
		pushUndoStep(new Undo::TerrainChange(i,y,new_terrain,old_terrain));
		if(editing_town && changingContainers)
			set_items_containment(i, y, changingContainers);
	}
	if(y>0){
		for(i=minx; i<=maxx;i++){
			if(editing_town && t_d.terrain[i][y-1]==old_terrain){
				if(flood_fill_terrain(new_terrain,old_terrain,i,y-1)>=maxx)
					break;
			}
			else if(current_terrain.terrain[i][y-1]==old_terrain){
				if(flood_fill_terrain(new_terrain,old_terrain,i,y-1)>=maxx)
					break;
			}
		}
	}
	if(y<(max_size-1)){
		for(i=minx; i<=maxx;i++){
			if(editing_town && t_d.terrain[i][y+1]==old_terrain){
				if(flood_fill_terrain(new_terrain,old_terrain,i,y+1)>=maxx)
					break;
			}
			else if(current_terrain.terrain[i][y+1]==old_terrain){
				if(flood_fill_terrain(new_terrain,old_terrain,i,y+1)>=maxx)
					break;
			}
		}
	}
	return(maxx);
}

//Changes the terrain in rectangle r to terrain_type with probability that a each space is 
//changed. If hollow is true, only the edges of the rectangle are changed
void change_rect_terrain(Rect r,short terrain_type,short probability,Boolean hollow)
// prob is 0 - 20, 0 no, 20 always
{
	location l;
	short i,j;
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			l.x = i;
			l.y = j;
			if ((i >= r.left) && (i <= r.right) && (j >= r.top) && (j <= r.bottom)
				&& ((hollow == FALSE) || (i == r.left) || (i == r.right) || (j == r.top) || (j == r.bottom))
				&& ((hollow == TRUE) || (get_ran(1,1,20) <= probability)))
				set_terrain(l,terrain_type);
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

//this function just copies the indicated rectangular area of the current zone onto the clipboard
void copy_rect_terrain(Rect r)
{
	short i,j;
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			if ((i >= r.left) && (i <= r.right) && (j >= r.top) && (j <= r.bottom)){
				if(editing_town){
					clipboard.terrain[i-r.left][j-r.top]=t_d.terrain[i][j];
					clipboard.floor[i-r.left][j-r.top]=t_d.floor[i][j];
					clipboard.height[i-r.left][j-r.top]=t_d.height[i][j];
				}
				else{
					clipboard.terrain[i-r.left][j-r.top]=current_terrain.terrain[i][j];
					clipboard.floor[i-r.left][j-r.top]=current_terrain.floor[i][j];
					clipboard.height[i-r.left][j-r.top]=current_terrain.height[i][j];
				}
			}
		}
	}
	dataOnClipboard=true;
	clipboardSize.top=0;
	clipboardSize.left=0;
	clipboardSize.bottom=r.bottom-r.top;
	clipboardSize.right=r.right-r.left;
}

void paste_terrain(location l,Boolean option_hit,Boolean alt_hit,Boolean ctrl_hit)
{
	/*command - option_hit
	option - alt_hit
	control - ctrl_hit*/
	if(!dataOnClipboard)
		return;
	short i,j,x,y;
	Boolean pasteF = (!option_hit && !alt_hit && !ctrl_hit) || alt_hit;
	Boolean pasteT = (!option_hit && !alt_hit && !ctrl_hit) || ctrl_hit;
	Boolean pasteH = (!option_hit && !alt_hit && !ctrl_hit) || option_hit;
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = l.x; (i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48)) && (i<=(l.x+clipboardSize.right)); i++){
		for (j = l.y; (j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48)) && (j<=(l.y+clipboardSize.bottom)); j++) {
			x = i-l.x;
			y = j-l.y;
			if(editing_town){
				if(pasteT){
					pushUndoStep(new Undo::TerrainChange(i,j,clipboard.terrain[i-l.x][j-l.y],t_d.terrain[i][j]));
					set_items_containment(i,j);
					t_d.terrain[i][j]=clipboard.terrain[i-l.x][j-l.y];
				}
				if(pasteF){
					pushUndoStep(new Undo::FloorChange(i,j,clipboard.floor[i-l.x][j-l.y],t_d.floor[i][j]));
					t_d.floor[i][j]=clipboard.floor[i-l.x][j-l.y];
				}
				if(pasteH){
					pushUndoStep(new Undo::HeightChange(i,j,clipboard.height[i-l.x][j-l.y],t_d.height[i][j]));
					t_d.height[i][j]=clipboard.height[i-l.x][j-l.y];
				}
			}
			else{
				if(pasteT){
					pushUndoStep(new Undo::TerrainChange(i,j,clipboard.terrain[x][y],current_terrain.terrain[i][j]));
					current_terrain.terrain[i][j]=clipboard.terrain[x][y];
				}
				if(pasteF){
					pushUndoStep(new Undo::FloorChange(i,j,clipboard.floor[x][y],current_terrain.floor[i][j]));
					current_terrain.floor[i][j]=clipboard.floor[x][y];
				}
				if(pasteH){
					pushUndoStep(new Undo::HeightChange(i,j,clipboard.height[x][y],current_terrain.height[i][j]));
					current_terrain.height[i][j]=clipboard.height[x][y];
				}
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

/*
 i = 0; //x coordinate
	while(i < 32){
		j = 0; //y coordinate
		while(j < 32){
			if(get_floor(i,j)==255){
				if((j > 0) && (get_floor(i,j - 1) != 255))//need wall to north
					k = k + 1;
				if(get_floor(i + 1,j) != 255)//need wall to east
					k = k + 2;
				if(get_floor(i,j + 1) != 255)//need wall to south
					k = k + 4;
				if((i>0) && (get_floor(i - 1,j) != 255))//need wall to west
					k = k + 8;
				if(k>0){ //draw the wall
					set_terrain(i,j,420+k);
					k=0;
				}
			}
			j = j + 1;
		}
		i = i + 1;
	}
 */

/*void swap_val(unsigned char *val,short a,short b)
 {
	if (*val == a)
		*val = b;
	else if (*val == b)
		*val = a;
 }
 void change_val_4 (unsigned char *val,short a,short b,short c,short d)
 {
	 if (*val == a)
		 *val = b;
	 else if (*val == b)
		 *val = c;
	 else if (*val == c)
		 *val = d;
	 else if (*val == d)
		 *val = a;
 }
 void change_val (unsigned char *val,short a,short b)
 {
	 if (*val == a)
		 *val = b;
 }*/

//changes the terrain or floor at the given location. Also does neatening like for boundaries 
//between water and grass, etc, handles placing of signs, and adds terrain scripts required by 
//the placed terrain. 
//Note: bug where floors with same number as sign terrains were treated as signs has been fixed
void set_terrain(location l,short terrain_type)
{
	short i,j,which_sign = -1;
	terrain_type_type ter_info,ter_info2;
	location l2;
	
	i = l.x; j = l.y;
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return ;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return ;
	
	short old_terrain;
	
	if (current_drawing_mode == 0) {
		if (editing_town){
			old_terrain = t_d.floor[i][j];
			t_d.floor[i][j] = terrain_type;
		}
		else {
			old_terrain = current_terrain.floor[i][j];
			current_terrain.floor[i][j] = terrain_type;
		}
	}
	else {
		if (editing_town){
			old_terrain = t_d.terrain[i][j];
			t_d.terrain[i][j] = terrain_type;
		}
		else{
			old_terrain = current_terrain.terrain[i][j];
			current_terrain.terrain[i][j] = terrain_type;
		}
	}
	
	l2 = l;
	if(terrain_type!=old_terrain){
		if(current_drawing_mode==0)
			pushUndoStep(new Undo::FloorChange(i,j,terrain_type,old_terrain));
		else
			pushUndoStep(new Undo::TerrainChange(i,j,terrain_type,old_terrain));
	}
	int changingContainers=(scen_data.scen_terrains[terrain_type].special==40)-(scen_data.scen_terrains[old_terrain].special==40);
	if(changingContainers)
		set_items_containment(i,j,changingContainers);
	
	adjust_space(l);
	l.x--;
	adjust_space(l);
	l.y--;
	adjust_space(l);
	l.x++;
	adjust_space(l);
	l.x++;
	adjust_space(l);
	l.y++;
	adjust_space(l);
	l.y++;
	adjust_space(l);
	l.x--;
	adjust_space(l);
	l.x--;
	adjust_space(l);
	l.x++;
	l.y--;
	
	// now handle placing signs
	if(current_drawing_mode>0){//if we just placed a floor, it can't be a sign
		Boolean sign_error_received = FALSE;
		ter_info = scen_data.scen_terrains[terrain_type];
		if(ter_info.special == 39){ // it's a sign
			if(editing_town == TRUE){ // town mode, is a sign
				for(i = 0; i < 15; i++){ // find outwhether this sign has already been assigned
					if((town.sign_locs[i].x == l.x) && (town.sign_locs[i].y == l.y)){
						which_sign = i;
						break;
					}
				}
				if(which_sign>=0){ //found an existing sign
					edit_sign(which_sign,true);
					sign_error_received = FALSE;
				}
				else{ // if not assigned; pick a new sign
					for(i = 0; i < 15; i++){
						if(town.sign_locs[i].x == kNO_SIGN)
							which_sign = i;
					}
					if(which_sign >= 0){
						town.sign_locs[which_sign] = l;
						edit_sign(which_sign,false);
						pushUndoStep(new Undo::CreateSign(which_sign,l,town.sign_text[which_sign],true));
						sign_error_received = FALSE;
					}
					else{
						if(sign_error_received == FALSE){
							give_error("Towns can have at most 15 signs. Outdoor sections can have at most 8. When the party looks at this sign, they will get no message.","",0);
							sign_error_received = TRUE;
						}
					}
					if(delimit_undo_on_mouse_up){
						pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
						delimit_undo_on_mouse_up=false;
					}
				}
			}
			if(editing_town == FALSE){ // outdoor mode, it's a sign
				for(i = 0; i < 8; i++){ // find is this sign has already been assigned
					if((current_terrain.sign_locs[i].x == l.x) && (current_terrain.sign_locs[i].y == l.y)){
						which_sign = i;
						break;
					}
				}
				if(which_sign>=0){ //found an existing sign
					edit_sign(which_sign,true);
					sign_error_received = FALSE;
				}
				else{ // if not assigned; pick a new sign
					for(i = 0; i < 8; i++){
						if(current_terrain.sign_locs[i].x == kNO_SIGN)
							which_sign = i;
					}
					if(which_sign >= 0){
						current_terrain.sign_locs[which_sign] = l;
						edit_sign(which_sign,false);
						pushUndoStep(new Undo::CreateSign(which_sign,l,current_terrain.sign_text[which_sign],true));
						sign_error_received = FALSE;
					}
					else{
						if(sign_error_received == FALSE){
							give_error("Towns can have at most 15 signs. Outdoor sections can have at most 8. When the party looks at this sign, they will get no message.","",0);
							sign_error_received = TRUE;
						}
					}
					if(delimit_undo_on_mouse_up){
						pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
						delimit_undo_on_mouse_up=false;
					}
				}
			}
			mouse_button_held = FALSE;
		}
		else { // not a sign, so delete any signs placed here
			if (editing_town == TRUE) {
				for (i = 0; i < 15; i++){ // find is this spot has a sign attached to it, and erase it
					if ((town.sign_locs[i].x == l.x) && (town.sign_locs[i].y == l.y)) {
						pushUndoStep(new Undo::CreateSign(i,l,town.sign_text[i],false));
						town.sign_locs[i].x = town.sign_locs[i].y = kNO_SIGN;
						town.sign_text[i][0] = 0;
					}
				}
			}
			if (editing_town == FALSE) {
				for (i = 0; i < 8; i++){// find is this spot has a sign attached to it, and erase it
					if ((current_terrain.sign_locs[i].x == l.x) && (current_terrain.sign_locs[i].y == l.y)) {
						pushUndoStep(new Undo::CreateSign(i,l,current_terrain.sign_text[i],false));
						current_terrain.sign_locs[i].x = current_terrain.sign_locs[i].y = kNO_SIGN;
						current_terrain.sign_text[i][0] = 0;
					}
				}
			}
		}
	}
	
	// now do placing scripts if placing terrain in a town
	if ((editing_town) && (current_drawing_mode > 0)) {
		for (i = 0; i < NUM_TER_SCRIPTS; i++){
			if ((town.ter_scripts[i].exists) && (same_point(l,town.ter_scripts[i].loc))) {
				town.ter_scripts[i].exists = FALSE;
				check_selected_item_number();
			}
		}
		if (strlen(scen_data.scen_terrains[t_d.terrain[(int)l.x][(int)l.y]].default_script) > 0) {
			create_new_ter_script(scen_data.scen_terrains[t_d.terrain[(int)l.x][(int)l.y]].default_script,l,NULL);
			mouse_button_held = FALSE;
		}
	}
				
	if(cur_viewing_mode == 11 && editing_town)
		set_up_lights();
	
}

//corrects boundary spaces between grass and rock floors
Boolean town_fix_grass_rocks(location l)
{
	short new_ter_to_place;
	short store_ter;
	short i,j;
	
	i = l.x; j = l.y;	
	if ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1))
		return FALSE;
	
	store_ter = t_d.floor[i][j];
	
	if ((store_ter == 4) || (store_ter == 41) ||
		((store_ter >= 11) && (store_ter <= 22)) || ((store_ter >= 45) && (store_ter <= 56))) {
	  	Boolean translated_to_cave = FALSE;
	  	if (store_ter > 22) {
	  		//if (store_ter == 41)
	  		//	store_ter = 11;
	  		//if (store_ter >= 45)
	  		//	store_ter -= 34;
	  		translated_to_cave = TRUE;	
		}
		
		if (is_rocks(i-1,j) == FALSE) {
			if (is_rocks(i,j-1) == FALSE)
				new_ter_to_place = 18;
			else {
				if (is_rocks(i,j+1) == FALSE)
					new_ter_to_place = 12;
				else 
					new_ter_to_place = 11;
			}		
		}
		else {// rocks(i-1,j) == TRUE
			if (is_rocks(i+1,j) == FALSE) {
				if (is_rocks(i, j-1) == FALSE)
					new_ter_to_place = 16;
				else if (is_rocks(i,j+1) == FALSE)
					new_ter_to_place = 14;
				else 
					new_ter_to_place = 15;
			}
			else { //rocks(i+1,j) == TRUE
				if (!is_rocks(i, j-1))
					new_ter_to_place = 17;
				else if (!is_rocks(i,j+1))
					new_ter_to_place = 13;
				else if (!is_rocks(i-1,j-1))
					new_ter_to_place = 20;
				else if(!is_rocks(i-1,j+1))
					new_ter_to_place = 19;
				else if (!is_rocks(i+1,j-1))
					new_ter_to_place = 21;
				else if (!is_rocks(i+1,j+1))
					new_ter_to_place = 22;
				else 
					new_ter_to_place = 4;//(get_ran(1,0,2) == 1) ? 10 : 8; 
			}
		}
		
		if (translated_to_cave) {
	  		if (new_ter_to_place == 4)
	  			new_ter_to_place = 41;
			else 
				new_ter_to_place += 34;
		}
		
		t_d.floor[i][j] = new_ter_to_place; 				
	}
	
	if(store_ter!=t_d.floor[i][j])
		pushUndoStep(new Undo::FloorChange(i,j,t_d.floor[i][j],store_ter));
	return(!(store_ter == t_d.floor[i][j]));
}

//corrects boundary spaces between grass and rock floors
Boolean out_fix_grass_rocks(location l)
{
	short new_ter_to_place;
	short store_ter;
	short i,j;
	
	i = l.x; j = l.y;
	if ((i < 0) || (i > 47) || (j < 0) || (j > 47))
		return FALSE;
	
	store_ter = current_terrain.floor[i][j];
	
	if ((store_ter == 4) || (store_ter == 41) ||
		((store_ter >= 11) && (store_ter <= 22)) || ((store_ter >= 45) && (store_ter <= 56))) {
	  	Boolean translated_to_cave = FALSE;
	  	if (store_ter > 22) {
	  		//if (store_ter == 41)
	  		//	store_ter = 11;
	  		//if (store_ter >= 45)
	  		//	store_ter -= 34;
	  		translated_to_cave = TRUE;	
		}
		
		if (is_rocks(i-1,j) == FALSE) {
			if (is_rocks(i,j-1) == FALSE) {
				new_ter_to_place = 18;
			}
			else {
				if (is_rocks(i,j+1) == FALSE)
					new_ter_to_place = 12;
				else 
					new_ter_to_place = 11;
			}		
		}
		else {// rocks(i-1,j) == TRUE
			if (is_rocks(i+1,j) == FALSE) {
				if (is_rocks(i, j-1) == FALSE)
					new_ter_to_place = 16;
				else if (is_rocks(i,j+1) == FALSE)
					new_ter_to_place = 14;
				else 
					new_ter_to_place = 15;
			}
			else { //rocks(i+1,j) == TRUE
				if (is_rocks(i, j-1) == FALSE)
					new_ter_to_place = 17;
				else if (is_rocks(i,j+1) == FALSE)
					new_ter_to_place = 13;
				else if (is_rocks(i-1,j-1) == FALSE)
					new_ter_to_place = 20;
				else if(is_rocks(i-1,j+1) == FALSE)
					new_ter_to_place = 19;
				else if (is_rocks(i+1,j-1) == FALSE)
					new_ter_to_place = 21;
				else if (is_rocks(i+1,j+1) == FALSE)
					new_ter_to_place = 22;
				else 
					new_ter_to_place = 4;//(get_ran(1,0,2) == 1) ? 10 : 8; 
			}
			
		}
		
		if (translated_to_cave) {
	  		if (new_ter_to_place == 4)
	  			new_ter_to_place = 41;
			else 
				new_ter_to_place += 34;
		}
		
		current_terrain.floor[i][j] = new_ter_to_place; 				
	}
	if(store_ter!=current_terrain.floor[i][j])
		pushUndoStep(new Undo::FloorChange(i,j,current_terrain.floor[i][j],store_ter));
	return(store_ter != current_terrain.floor[i][j]);
}

//corrects boundary spaces between water and rock floors
Boolean town_fix_rocks_water(location l)
{

	short new_ter_to_place;
	short store_ter;
	short i,j;
	
	i = l.x; j = l.y;
	if ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1))
		return FALSE;
	
	store_ter = t_d.floor[i][j];
	
	if ((store_ter == 23) || (store_ter == 57) ||
		((store_ter >= 25) && (store_ter <= 36)) || ((store_ter >= 59) && (store_ter <= 70))) {
	  	Boolean translated_to_cave = FALSE;
	  	if (store_ter > 36) {
	  		//if (store_ter == 57)
	  		//	store_ter = 23;
	  		//if (store_ter >= 59)
	  		//	store_ter -= 34;
	  		translated_to_cave = TRUE;	
		}
		
		if (is_water(i-1,j) == FALSE) {
			if (is_water(i,j-1) == FALSE) {
				new_ter_to_place = 36;
			}
			else {
				if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 35;
				else
					new_ter_to_place = 29;
			}
		}					
		else {// rocks(i-1,j) == TRUE
			if (is_water(i+1,j) == FALSE) {
				if (is_water(i, j-1) == FALSE)
					new_ter_to_place = 33;
				else if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 34;
				else 
					new_ter_to_place = 25;
			}
			
			else { //rocks(i+1,j) == TRUE
				if (is_water(i, j-1) == FALSE)
					new_ter_to_place = 27;
				else if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 31;
				else if (is_water(i-1,j-1) == FALSE)
					new_ter_to_place = 28;
				else if(is_water(i-1,j+1) == FALSE)
					new_ter_to_place = 30;
				else if (is_water(i+1,j-1) == FALSE)
					new_ter_to_place = 26;
				else if (is_water(i+1,j+1) == FALSE)
					new_ter_to_place = 32;
				else 
					new_ter_to_place = 23;
			}
			
		}
		
		if (translated_to_cave) {
	  		if (new_ter_to_place == 23)
	  			new_ter_to_place = 57;
			else 
				new_ter_to_place += 34;
		}
		t_d.floor[i][j] = new_ter_to_place; 
	}
	if(store_ter!=t_d.floor[i][j])
		pushUndoStep(new Undo::FloorChange(i,j,t_d.floor[i][j],store_ter));
	return(store_ter != t_d.floor[i][j]);
}

//corrects boundary spaces between water and rock floors
Boolean out_fix_rocks_water(location l)
{
	short new_ter_to_place;
	short store_ter;
	short i,j;
	
	i = l.x; j = l.y;
	if ((i < 0) || (i > 47) || (j < 0) || (j > 47))
		return FALSE;
	
	store_ter = current_terrain.floor[i][j];
	
	if ((store_ter == 23) || (store_ter == 57) ||
		((store_ter >= 25) && (store_ter <= 36)) || ((store_ter >= 59) && (store_ter <= 70))) {
	  	Boolean translated_to_cave = FALSE;
	  	if (store_ter > 36) {
	  		//if (store_ter == 57)
	  		//	store_ter = 23;
	  		//if (store_ter >= 59)
	  		//	store_ter -= 34;
	  		translated_to_cave = TRUE;	
		}
		
		if (is_water(i-1,j) == FALSE) {
			if (is_water(i,j-1) == FALSE) {
				new_ter_to_place = 36;
			} else {
				if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 35;
				else new_ter_to_place = 29;
			}
		} else {// rocks(i-1,j) == TRUE
			if (is_water(i+1,j) == FALSE) {
				if (is_water(i, j-1) == FALSE)
					new_ter_to_place = 33;
				else if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 34;
				else new_ter_to_place = 25;
			} else { //rocks(i+1,j) == TRUE
				if (is_water(i, j-1) == FALSE)
					new_ter_to_place = 27;
				else if (is_water(i,j+1) == FALSE)
					new_ter_to_place = 31;
				else if (is_water(i-1,j-1) == FALSE)
					new_ter_to_place = 28;
				else if(is_water(i-1,j+1) == FALSE)
					new_ter_to_place = 30;
				else if (is_water(i+1,j-1) == FALSE)
					new_ter_to_place = 26;
				else if (is_water(i+1,j+1) == FALSE)
					new_ter_to_place = 32;
				else new_ter_to_place = 23;
			}
		}
		
		if (translated_to_cave) {
	  		if (new_ter_to_place == 23)
	  			new_ter_to_place = 57;
			else new_ter_to_place += 34;
		}
		current_terrain.floor[i][j] = new_ter_to_place; 
	}
	if(store_ter!=current_terrain.floor[i][j])
		pushUndoStep(new Undo::FloorChange(i,j,current_terrain.floor[i][j],store_ter));
	return(store_ter != current_terrain.floor[i][j]);
}

//auto-hill generation
Boolean town_fix_hills(location l)
{
	short store_ter;
	short cur_height;
	short i;
	short corner_heights[4] = {0,0,0,0}; // 0 - nw, 1 - sw se ne
	int lx = l.x;
	int ly = l.y;
	
	if ((l.x < 0) || (l.x > max_zone_dim[town_type] - 1) || (l.y < 0) || (l.y > max_zone_dim[town_type] - 1))
		return FALSE;
	if (current_height_mode != 1)
		return FALSE;
	store_ter = t_d.terrain[lx][ly];
	cur_height = t_d.height[lx][ly];
	
	if (t_d.floor[lx][ly] == 255)
		return FALSE;
	
	if (get_height(l.x - 1,l.y,1) > cur_height) {
		corner_heights[0] = 1; corner_heights[1] = 1;
	}
	
	if (get_height(l.x - 1,l.y + 1,1) > cur_height) {
		corner_heights[1] = 1;
	}
	
	if (get_height(l.x,l.y + 1,1) > cur_height) {
		corner_heights[2] = 1; corner_heights[1] = 1;
	}
	
	if (get_height(l.x + 1,l.y + 1,1) > cur_height) {
		corner_heights[2] = 1;
	}
	
	if (get_height(l.x + 1,l.y,1) > cur_height) {
		corner_heights[2] = 1; corner_heights[3] = 1;
	}
	
	if (get_height(l.x + 1,l.y - 1,1) > cur_height) {
		corner_heights[3] = 1;
	}
	
	if (get_height(l.x,l.y - 1,1) > cur_height) {
		corner_heights[0] = 1; corner_heights[3] = 1;
	}
	
	if (get_height(l.x - 1,l.y - 1,1) > cur_height) {
		corner_heights[0] = 1;
	}
	
	if(corner_heights[0] || corner_heights[1] || corner_heights[2] || corner_heights[3]){
		//find out what type of hill this requires:
		for (i = 0; i < 12; i++){
			if ((hill_c_heights[i][0] == corner_heights[0]) && 
				(hill_c_heights[i][1] == corner_heights[1]) &&
				(hill_c_heights[i][2] == corner_heights[2]) &&
				(hill_c_heights[i][3] == corner_heights[3]))
				break;
		}
		//if the require hill type doesn't match the type presently there, replace it
		if(i+19!=scen_data.scen_terrains[t_d.terrain[lx][ly]].special){
			short hill_adjust = 0;
			if (town.is_on_surface == FALSE)
				hill_adjust = 32;
			else if (scen_data.scen_floors[t_d.floor[lx][ly]].is_rough)
				hill_adjust = 16;
			t_d.terrain[lx][ly] = i + 74 + hill_adjust;
		}
	} //handle the case where there is a slope where none is now needed:
	else if ((t_d.terrain[lx][ly] >= 74) && (t_d.terrain[lx][ly] <= 121))
		t_d.terrain[lx][ly] = 0;
	if(store_ter != t_d.terrain[lx][ly]){
		//the fact that doing this can affect containers is yet another reason that auto-hills is evil
		int changingContainers=(scen_data.scen_terrains[t_d.terrain[lx][ly]].special==40)-(scen_data.scen_terrains[store_ter].special==40);
		if(changingContainers)
			set_items_containment(lx,ly,changingContainers);
		pushUndoStep(new Undo::TerrainChange(lx,ly,t_d.terrain[lx][ly],store_ter));
	}
	return(store_ter != t_d.terrain[lx][ly]);
}

//outdoor auto-hill generation
Boolean out_fix_hills(location l)
{
	short store_ter;
	short cur_height;
	short i;
	short corner_heights[4] = {0,0,0,0}; // 0 - nw, 1 - sw se ne
	int lx = l.x;
	int ly = l.y;
	
	if ((l.x < 0) || (l.x > 47) || (l.y < 0) || (l.y > 47))
		return FALSE;
	if (current_height_mode != 1)
		return FALSE;
	
	store_ter = current_terrain.terrain[lx][ly];
	cur_height = current_terrain.height[lx][ly];
	
	if (current_terrain.floor[lx][ly] == 255)
		return FALSE;
	
	if (get_height(l.x - 1,l.y,1) > cur_height) {
		corner_heights[0] = 1; corner_heights[1] = 1;
	}
	
	if (get_height(l.x - 1,l.y + 1,1) > cur_height) {
		corner_heights[1] = 1;
	}
	
	if (get_height(l.x,l.y + 1,1) > cur_height) {
		corner_heights[2] = 1; corner_heights[1] = 1;
	}
	
	if (get_height(l.x + 1,l.y + 1,1) > cur_height) {
		corner_heights[2] = 1;
	}
	
	if (get_height(l.x + 1,l.y,1) > cur_height) {
		corner_heights[2] = 1; corner_heights[3] = 1;
	}
	
	if (get_height(l.x + 1,l.y - 1,1) > cur_height) {
		corner_heights[3] = 1;
	}
	
	if (get_height(l.x,l.y - 1,1) > cur_height) {
		corner_heights[0] = 1; corner_heights[3] = 1;
	}
	
	if (get_height(l.x - 1,l.y - 1,1) > cur_height) {
		corner_heights[0] = 1;
	}
	
	if(corner_heights[0] || corner_heights[1] || corner_heights[2] || corner_heights[3]){
		//find out what type of hill this requires:
		for (i = 0; i < 12; i++){
			if ((hill_c_heights[i][0] == corner_heights[0]) && 
				(hill_c_heights[i][1] == corner_heights[1]) &&
				(hill_c_heights[i][2] == corner_heights[2]) &&
				(hill_c_heights[i][3] == corner_heights[3]))
				break;
		}
		//if the require hill type doesn't match the type presently there, replace it
		if(i+19!=scen_data.scen_terrains[current_terrain.terrain[lx][ly]].special){
			short hill_adjust = 0;
			if (current_terrain.is_on_surface == FALSE)
				hill_adjust = 32;
			else if (scen_data.scen_floors[current_terrain.floor[lx][ly]].is_rough)
				hill_adjust = 16;
			current_terrain.terrain[lx][ly] = i + 74 + hill_adjust;
		}
	} //handle the case where there is a slope where none is now needed:
	else if ((current_terrain.terrain[lx][ly] >= 74) && (current_terrain.terrain[lx][ly] <= 121))
		current_terrain.terrain[lx][ly] = 0;
	//record any change made to the undo list
	if(store_ter != current_terrain.terrain[lx][ly])
		pushUndoStep(new Undo::TerrainChange(lx,ly,current_terrain.terrain[lx][ly],store_ter));
	return(store_ter != current_terrain.terrain[lx][ly]);
}

// given a spot in the world and a corner, returns 1 if that corner is elevated
// 0 - level with floor, 1 - above floor
// which corner 0 - nw, 1 - sw, 2 - se, 3 - ne
short get_corner_height(short x, short y,short out_or_town,short which_corner) 
{
	short new_ter;
	
	new_ter = adjust_get_ter(x,y,out_or_town);
	if ((scen_data.scen_terrains[new_ter].special < 19) || (scen_data.scen_terrains[new_ter].special > 30))
		return 0;
	return hill_c_heights[scen_data.scen_terrains[new_ter].special - 19][which_corner];
}

//returns the height at location (x,y) in the outdoor section or town
short get_height(short x, short y,short out_or_town)
{
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	
	if (editing_town == FALSE) {
		if (x > 47) x = 47;
		if (y > 47) y = 47;
		
		return current_terrain.height[x][y];
	}
	if (x > max_zone_dim[town_type] - 1) x = max_zone_dim[town_type] - 1;
	if (y > max_zone_dim[town_type] - 1) y = max_zone_dim[town_type] - 1;
	
	return t_d.height[x][y];
}

// does boundary check and returns 0 if off world
short adjust_get_ter(short x, short y,short out_or_town)
{
	if (x < 0) return 0;
	if (y < 0) return 0;
	
	if (x > MAX_TOWN_SIZE - 1)  return 0;
	if (y > MAX_TOWN_SIZE - 1)  return 0;
	
	return (editing_town) ? t_d.terrain[x][y] : current_terrain.terrain[x][y];
}

//starting function for recursive cleaning
void adjust_space(location l)
{
	recursive_depth = 0;
	recursive_clean_terrain(l);
}

//recursively does auto-hill corections and floor boundary corrections
void recursive_clean_terrain(location l)
{
	Boolean needed_change = FALSE;
	location l2;
	short i,j;
	
	if (recursive_depth >= MAX_RECURSION_DEPTH)
		return;
	
	i = l.x; j = l.y;
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return ;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return ;
	if (editing_town == TRUE) {
		if (town_fix_hills(l) == TRUE)
			needed_change = TRUE;
		if (town_fix_grass_rocks(l) == TRUE)
			needed_change = TRUE;
		if (town_fix_rocks_water(l) == TRUE)
			needed_change = TRUE;
	}
	if (editing_town == FALSE) {
		if (out_fix_hills(l) == TRUE)
			needed_change = TRUE;
		if (out_fix_grass_rocks(l) == TRUE)
			needed_change = TRUE;
		if (out_fix_rocks_water(l) == TRUE)
			needed_change = TRUE;
	}
	if (needed_change == TRUE) {
		recursive_depth++;
		l2 = l;
		l2.x--;
		recursive_clean_terrain(l2);
		l2.x += 2;
		recursive_clean_terrain(l2);
		l2.x--;
		l2.y--;
		recursive_clean_terrain(l2);
		l2.y += 2;
		recursive_clean_terrain(l2); 
		recursive_depth--;
	}
}

//returns the terrain at location (x,y)
short coord_to_ter(short x,short y)
{
	short what_terrain;
	if (x < 0) return 0;
	if (y < 0) return 0;
	if (x > (editing_town) ? max_zone_dim[town_type] - 1 : 47)  return 0;
	if (y > (editing_town) ? max_zone_dim[town_type] - 1 : 47)  return 0;
	
	if (editing_town == TRUE)
		what_terrain = t_d.terrain[x][y];
	else what_terrain = current_terrain.terrain[x][y];
	
	return what_terrain;
}

//lowers or raises the space at location l
void change_height(location l,short lower_or_raise)
{
	Boolean needed_change = TRUE;
	short i,j;
	
	i = l.x; j = l.y;
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return ;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return ;
	
	if (editing_town) {
		pushUndoStep(new Undo::HeightChange(i,j,minmax(1,100,(lower_or_raise == 0) ? (t_d.height[i][j] - 1) : (t_d.height[i][j] + 1)),t_d.height[i][j]));
		t_d.height[i][j] = minmax(1,100,(lower_or_raise == 0) ? (t_d.height[i][j] - 1) : (t_d.height[i][j] + 1));
	}
	else{
		pushUndoStep(new Undo::HeightChange(i,j,minmax(1,100,(lower_or_raise == 0) ? (current_terrain.height[i][j] - 1) : (current_terrain.height[i][j] + 1)),current_terrain.height[i][j]));
		current_terrain.height[i][j] = minmax(1,100,(lower_or_raise == 0) ? (current_terrain.height[i][j] - 1) : (current_terrain.height[i][j] + 1));
	}
	
	if (needed_change == TRUE) {
		adjust_space_height(l,lower_or_raise);
		l.x--;
		adjust_space_height(l,lower_or_raise);
		l.y--;
		adjust_space_height(l,lower_or_raise);
		l.x++;
		adjust_space_height(l,lower_or_raise);
		l.x++;
		adjust_space_height(l,lower_or_raise);
		l.y++;
		adjust_space_height(l,lower_or_raise);
		l.y++;
		adjust_space_height(l,lower_or_raise);
		l.x--;
		adjust_space_height(l,lower_or_raise);
		l.x--;
		adjust_space_height(l,lower_or_raise);
		l.x++;
		l.y--;	
		adjust_space(l);
		l.x--;
		adjust_space(l);
		l.y--;
		l.x++;
		adjust_space(l);
		l.y++;
		l.x++;
		adjust_space(l);
		l.y++;
		l.x--;
		adjust_space(l);
	}
}

void adjust_space_height(location l,short lower_or_raise)
{
	if (current_height_mode != 1)
		return;
	if (lower_or_raise == 0)
		adjust_space_height_lower(l);
	else 
		adjust_space_height_raise(l);
}

void adjust_space_height_lower(location l)
{
	recursive_hill_down_depth = 0;
	recursive_adjust_space_height_lower(l);
	adjust_space(l);
}

void recursive_adjust_space_height_lower(location l)
{
	short i,j,height,old_height;
	
	if (recursive_hill_down_depth >= MAX_RECURSION_DEPTH)
		return;
	
	i = l.x; j = l.y;
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return ;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return ;
	
	old_height = height = get_height(i,j,editing_town);
	
	if (height - 1 > get_height(i + 1,j,editing_town))
		height = get_height(i + 1,j,editing_town) + 1;
	if (height - 1 > get_height(i - 1,j,editing_town))
		height = get_height(i - 1,j,editing_town) + 1;
	if (height - 1 > get_height(i,j + 1,editing_town))
		height = get_height(i,j + 1,editing_town) + 1;
	if (height - 1 > get_height(i,j - 1,editing_town))
		height = get_height(i,j - 1,editing_town) + 1;
	if (height - 1 > get_height(i + 1,j + 1,editing_town))
		height = get_height(i + 1,j + 1,editing_town) + 1;
	if (height - 1 > get_height(i - 1,j + 1,editing_town))
		height = get_height(i - 1,j + 1,editing_town) + 1;
	if (height - 1 > get_height(i + 1,j - 1,editing_town))
		height = get_height(i + 1,j - 1,editing_town) + 1;
	if (height - 1 > get_height(i - 1,j - 1,editing_town))
		height = get_height(i - 1,j - 1,editing_town) + 1;
	
	if (old_height != height) {
		if (editing_town == TRUE)
			t_d.height[i][j] = height;
		else 
			current_terrain.height[i][j] = height;
		pushUndoStep(new Undo::HeightChange(i,j,height,old_height));
		//if (editing_town == TRUE)
		//	else out_fix_hills(l);
		recursive_hill_down_depth++;
		l.x--;
		recursive_adjust_space_height_lower(l);
		l.y--;
		l.x++;
		recursive_adjust_space_height_lower(l);
		l.x++;
		l.y++;
		recursive_adjust_space_height_lower(l);
		l.y++;
		l.x--;
		recursive_adjust_space_height_lower(l);
		
		recursive_hill_down_depth--;
	}
	adjust_space(l);	
}

void adjust_space_height_raise(location l)
{
	recursive_hill_up_depth = 0;
	recursive_adjust_space_height_raise(l);
	adjust_space(l);
}

void recursive_adjust_space_height_raise(location l)
{
	short i,j,height,old_height;
	
	if (recursive_hill_up_depth >= MAX_RECURSION_DEPTH)
		return;
	
	i = l.x; j = l.y;
	if ((editing_town == TRUE) && ((i < 0) || (i > max_zone_dim[town_type] - 1) || (j < 0) || (j > max_zone_dim[town_type] - 1)))
		return ;
	if ((editing_town == FALSE) && ((i < 0) || (i > 47) || (j < 0) || (j > 47)))
		return ;
	
	old_height = height = get_height(i,j,editing_town);
	
	if (height + 1 < get_height(i + 1,j,editing_town))
		height = get_height(i + 1,j,editing_town) - 1;
	if (height + 1 < get_height(i - 1,j,editing_town))
		height = get_height(i - 1,j,editing_town) - 1;
	if (height + 1 < get_height(i,j + 1,editing_town))
		height = get_height(i,j + 1,editing_town) - 1;
	if (height + 1 < get_height(i,j - 1,editing_town))
		height = get_height(i,j - 1,editing_town) - 1;
	if (height + 1 < get_height(i + 1,j + 1,editing_town))
		height = get_height(i + 1,j + 1,editing_town) - 1;
	if (height + 1 < get_height(i - 1,j + 1,editing_town))
		height = get_height(i - 1,j + 1,editing_town) - 1;
	if (height + 1 < get_height(i + 1,j - 1,editing_town))
		height = get_height(i + 1,j - 1,editing_town) - 1;
	if (height + 1 < get_height(i - 1,j - 1,editing_town))
		height = get_height(i - 1,j - 1,editing_town) - 1;
	
	if (old_height != height) {
		if (editing_town == TRUE)
			t_d.height[i][j] = height;
		else 
			current_terrain.height[i][j] = height;
		pushUndoStep(new Undo::HeightChange(i,j,height,old_height));
		//if (editing_town == TRUE)
		//	else out_fix_hills(l);
		recursive_hill_up_depth++;
		l.x--;
		recursive_adjust_space_height_raise(l);
		l.y--;
		l.x++;
		recursive_adjust_space_height_raise(l);
		l.x++;
		l.y++;
		recursive_adjust_space_height_raise(l);
		l.y++;
		l.x--;
		recursive_adjust_space_height_raise(l);
		
		recursive_hill_up_depth--;
	}
	adjust_space(l);
}

//disables menu items which aren't applicable at the moment
void shut_down_menus()
{
	MenuHandle cur_menu;	
	if (file_is_loaded == FALSE) {
		cur_menu = GetMHandle(550); DisableMenuItem(cur_menu,2 );
		
		cur_menu = GetMenuHandle(570); DisableMenuItem(cur_menu,1 );
		DisableMenuItem(cur_menu,2 );  DisableMenuItem(cur_menu,4 );
		DisableMenuItem(cur_menu,5 );  DisableMenuItem(cur_menu,6 );  
		DisableMenuItem(cur_menu,7 );  DisableMenuItem(cur_menu,9 );
		DisableMenuItem(cur_menu,10);  DisableMenuItem(cur_menu,11);
		DisableMenuItem(cur_menu,12);  DisableMenuItem(cur_menu,13);
		DisableMenuItem(cur_menu,15);  DisableMenuItem(cur_menu,16);
		cur_menu = GetMenuHandle(600); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(650); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(651); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(700); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(701); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(702); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(703); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(704); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(750); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(751); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(752); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(753); DisableMenuItem(cur_menu,0 );
		return;
	}
	else {
		cur_menu = GetMHandle(550); EnableMenuItem(cur_menu,2 );
		
		cur_menu = GetMenuHandle(570); EnableMenuItem(cur_menu,0 );
		EnableMenuItem(cur_menu,9 );   EnableMenuItem(cur_menu,10);
		EnableMenuItem(cur_menu,11);   EnableMenuItem(cur_menu,15);
		EnableMenuItem(cur_menu,16);
		cur_menu = GetMenuHandle(600); EnableMenuItem(cur_menu,0 );
		EnableMenuItem(cur_menu,10);   EnableMenuItem(cur_menu,11);
		cur_menu = GetMenuHandle(650); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(651); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(700); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(701); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(702); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(703); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(704); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(750); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(751); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(752); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(753); EnableMenuItem(cur_menu,0 );
	}
	if (editing_town == FALSE) {
		cur_menu = GetMenuHandle(570); EnableMenuItem(cur_menu,1 );
		EnableMenuItem(cur_menu,2 );   DisableMenuItem(cur_menu,4 );  
		DisableMenuItem(cur_menu,5 );  DisableMenuItem(cur_menu,6 );
		DisableMenuItem(cur_menu,7 );  DisableMenuItem(cur_menu,12);
		DisableMenuItem(cur_menu,13);
		cur_menu = GetMenuHandle(650); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(700); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(701); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(702); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(703); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(704); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(750); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(751); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(752); DisableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(753); DisableMenuItem(cur_menu,0 );
		
		cur_menu = GetMenuHandle(651); EnableMenuItem(cur_menu,0 );
	}
	else {
		cur_menu = GetMenuHandle(570); EnableMenuItem(cur_menu,1 );
		EnableMenuItem(cur_menu,2 );   EnableMenuItem(cur_menu,4 );
		EnableMenuItem(cur_menu,5 );   EnableMenuItem(cur_menu,6 );
		EnableMenuItem(cur_menu,7 );   EnableMenuItem(cur_menu,12);
		EnableMenuItem(cur_menu,13);
		cur_menu = GetMenuHandle(650); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(700); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(701); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(702); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(703); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(704); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(750); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(751); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(752); EnableMenuItem(cur_menu,0 );
		cur_menu = GetMenuHandle(753); EnableMenuItem(cur_menu,0 );
		
		cur_menu = GetMenuHandle(651); DisableMenuItem(cur_menu,0 );		
	}
}

//Called when the data in memory is going to be overwritten or dumped. 
//Returns TRUE if the user hasn't made any changes to the data, to it can be safely thrown away.
//If the user has made changes, dialog which_dlog is displayed to ask the user whether to save 
//the changes, and does so if so instructed. Returns whether the user chose to save the changes or not.
Boolean save_check(short which_dlog)
{
	short choice;
	
	if (change_made_town == FALSE && change_made_outdoors == FALSE)
		return TRUE;
	choice = fancy_choice_dialog(which_dlog,0);
	if (choice == 3)
		return TRUE;
	if (choice == 2) {
		return FALSE;
	}
	save_campaign();
	return TRUE;
}

//refreshs the menu items in the item menus to reflect the current item definitions
void update_item_menu()
{	
	short i,j;
	MenuHandle item_menu[5],mon_menu[4];
	Str255 item_name;
	
	for (i = 0; i < 5; i++)
		item_menu[i] = GetMHandle(700 + i);
	for (j = 0; j < 5; j++) {
		for (i = 0; i < 100; i++) {
			DeleteMenuItem(item_menu[j],1); 
		}
		for (i = 0; i < 100; i++) {
			if (strlen(scen_data.scen_items[i + j * 100].full_name) == 0)
				sprintf(scen_data.scen_items[i + j * 100].full_name,"Unused");
			sprintf((char *) item_name, "%d - %s",
					i + j * 100,scen_data.scen_items[i + j * 100].full_name);
			c2p(item_name);
			AppendMenu(item_menu[j],item_name);
		} 
	}
	for (i = 0; i < 4; i++)
		mon_menu[i] = GetMHandle(750 + i);
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 64; i++) {
			DeleteMenuItem(mon_menu[j],1); 
		}
		for (i = 0; i < 64; i++) {
			if (strcmp(scen_data.scen_creatures[i + j * 64].name,"Unused")!=0)
				sprintf((char *) item_name, "%d - %s, L%d",
						i + j * 64,scen_data.scen_creatures[i + j * 64].name,
						scen_data.scen_creatures[i + j * 64].level);
			else sprintf((char *) item_name, "%d - %s",
						 i + j * 64,scen_data.scen_creatures[i + j * 64].name);
			
			c2p( item_name);
			AppendMenu(mon_menu[j],item_name);
		} 
	}
}
#endif

// given 2 locations, finds the direction (0 - 7)
// from l1 to l2
short locs_to_dir(location l1,location l2)
{
	if (l1.x < l2.x) {
		if (l2.y < l1.y)
			return 7;
		if (l2.y == l1.y)
			return 6;
		return 5;
	}
	if (l1.x > l2.x) {
		if (l2.y < l1.y)
			return 1;
		if (l2.y == l1.y)
			return 2;
		return 3;
	}
	if (l2.y < l1.y)
		return 0;
	return 4;
}

#if 0

//destroys whatever creature, terrain script, or item the user has selected
void delete_selected_instance(){
	short real_drawing_mode;
	if(editing_town){
		switch(selected_object_type){
			case SelectionType::None:
				beep();
				break;
			case SelectionType::Creature:
				if(selected_object_number<NUM_TOWN_PLACED_CREATURES){
					pushUndoStep(new Undo::CreateCreature(selected_object_number,
														  town.creatures[selected_object_number],false));
					town.creatures[selected_object_number].number = -1;
				}
				break;
			case SelectionType::Item:
				if(selected_object_number<NUM_TOWN_PLACED_ITEMS){
					pushUndoStep(new Undo::CreateItem(selected_object_number,
													  town.preset_items[selected_object_number],false));
					town.preset_items[selected_object_number].which_item = -1;
				}
				break;
			case SelectionType::TerrainScript:
				if(selected_object_number<NUM_TER_SCRIPTS){
					pushUndoStep(new Undo::CreateTerrainScript(selected_object_number,
															   town.ter_scripts[selected_object_number],false));
					town.ter_scripts[selected_object_number].exists = FALSE;
				}
				break;
			case SelectionType::Waypoint:
				if(selected_object_number<NUM_WAYPOINTS){
					pushUndoStep(new Undo::CreateWaypoint(selected_object_number,town.waypoints[selected_object_number],false));
					town.waypoints[selected_object_number].x = -1;
				}
				break;
			case SelectionType::SpecialEncounter:
				if(selected_object_number<NUM_TOWN_PLACED_SPECIALS){
					pushUndoStep(new Undo::CreateSpecialEncounter(selected_object_number,
																  town.special_rects[selected_object_number],
																  town.spec_id[selected_object_number],false));
					town.spec_id[selected_object_number] = kNO_TOWN_SPECIALS;
					SetRect(&town.special_rects[selected_object_number],-1,-1,-1,-1);
				}
				break;
			case SelectionType::AreaDescription:
				if(selected_object_number<NUM_TOWN_DESCRIPTION_AREAS){
					pushUndoStep(new Undo::CreateDescriptionArea(selected_object_number,
																 town.room_rect[selected_object_number],
																 town.info_rect_text[selected_object_number],false));
					town.room_rect[selected_object_number].right = 0;
				}
				break;
			case SelectionType::Sign:
				if(selected_object_number<15){
					real_drawing_mode = current_drawing_mode;
					current_drawing_mode = 1;
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					set_terrain(town.sign_locs[selected_object_number],0);
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					current_drawing_mode = real_drawing_mode;
				}
				break;
			default: //other cases should never happen; do nothing
				break;
		}
	}
	else{
		switch(selected_object_type){
			case SelectionType::None:
				beep();
				break;
			case SelectionType::SpecialEncounter:
				if(selected_object_number<NUM_OUT_PLACED_SPECIALS){
					pushUndoStep(new Undo::CreateSpecialEncounter(selected_object_number,
																  current_terrain.special_rects[selected_object_number],
																  current_terrain.spec_id[selected_object_number],false));
					current_terrain.spec_id[selected_object_number] = kNO_OUT_SPECIALS;
					SetRect(&current_terrain.special_rects[selected_object_number],-1,-1,-1,-1);
				}
				break;
			case SelectionType::AreaDescription:
				if(selected_object_number<NUM_OUT_DESCRIPTION_AREAS){
					pushUndoStep(new Undo::CreateDescriptionArea(selected_object_number,
																 current_terrain.info_rect[selected_object_number],
																 current_terrain.info_rect_text[selected_object_number],false));
					current_terrain.info_rect[selected_object_number].right = 0;
				}
				break;
			case SelectionType::TownEntrance:
				if(selected_object_number<NUM_OUT_TOWN_ENTRANCES){
					pushUndoStep(new Undo::CreateTownEntrance(selected_object_number,current_terrain.exit_rects[selected_object_number],current_terrain.exit_dests[selected_object_number],false));
					current_terrain.exit_dests[selected_object_number] = kNO_OUT_TOWN_ENTRANCE;
					current_terrain.exit_rects[selected_object_number].right = 0;
				}
				break;
			case SelectionType::Sign:
				if(selected_object_number<8){
					real_drawing_mode = current_drawing_mode;
					current_drawing_mode = 1;
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					set_terrain(current_terrain.sign_locs[selected_object_number],0);
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					current_drawing_mode = real_drawing_mode;
				}
				break;
			default: //other cases should never happen; do nothing
				break;
		}
	}
	selected_object_type=SelectionType::None;
	selected_object_number=0;
}

//copies the selected creature, terrain script, or item for later pasting
//NOTE: this actually only makes a reference to the copied item
void copy_selected_instance()
{		
	//must have something selected which isn't a rectangle
	if(selected_object_type==SelectionType::None || selected_object_type==SelectionType::SpecialEncounter
	   || selected_object_type==SelectionType::AreaDescription || selected_object_type==SelectionType::TownEntrance){
		beep();
		return;
	}
	//TODO: Make this work with signs and waypoints
	if (selected_object_type==SelectionType::Sign || selected_object_type==SelectionType::Waypoint){
		beep();
		return;
	}
	copied_creature.number = -1;
	copied_item.which_item = -1;
	copied_ter_script.exists = FALSE;
	switch(selected_object_type){
		case SelectionType::Creature:
			copied_creature = town.creatures[selected_object_number];
			break;
		case SelectionType::Item:
			copied_item = town.preset_items[selected_object_number];
			break;
		case SelectionType::TerrainScript:
			copied_ter_script = town.ter_scripts[selected_object_number];
			break;
		default: //other cases have already been ruled out
			break;
	}
}

//copies and then deletes the selected creature, terrain script or item.
void cut_selected_instance(){
	//must have something selected which isn't a rectangle
	if(selected_object_type==SelectionType::None || selected_object_type==SelectionType::SpecialEncounter
	   || selected_object_type==SelectionType::AreaDescription || selected_object_type==SelectionType::TownEntrance){
		beep();
		return;
	}
	//TODO: Make this work with signs and waypoints
	if (selected_object_type==SelectionType::Sign || selected_object_type==SelectionType::Waypoint){
		beep();
		return;
	}
	copy_selected_instance();
	delete_selected_instance();
}

void paste_selected_instance(location create_loc){	
	// select creature
	if (copied_creature.number >= 0)
		create_new_creature(copied_creature.number,create_loc,&copied_creature);
	
	// select ter script
	if (copied_ter_script.exists) 
		create_new_ter_script("dummyname",create_loc,&copied_ter_script);
	
	// select item
	if (copied_item.which_item >= 0)
		create_new_item(copied_item.which_item,create_loc,FALSE,&copied_item);
}

// looks to make sure that the selected item is still legal. If not, undoes it.
void check_selected_item_number(){
	switch(selected_object_type){
		case SelectionType::None:
			break;
		case SelectionType::Creature:
			if(selected_object_number>=NUM_TOWN_PLACED_CREATURES || !town.creatures[selected_object_number].exists()){
				selected_object_type=SelectionType::None;
				selected_object_number=0;
			}
			break;
		case SelectionType::Item:
			if(selected_object_number>=NUM_TOWN_PLACED_ITEMS || !town.preset_items[selected_object_number].exists()){
				selected_object_type=SelectionType::None;
				selected_object_number=0;
			}
			break;
		case SelectionType::TerrainScript:
			if(selected_object_number>=NUM_TER_SCRIPTS || !town.ter_scripts[selected_object_number].exists){
				selected_object_type=SelectionType::None;
				selected_object_number=0;
			}
			break;
		case SelectionType::Waypoint:
			if(selected_object_number>=NUM_WAYPOINTS || town.waypoints[selected_object_number].x<0){
				selected_object_type=SelectionType::None;
				selected_object_number=0;
			}
			break;
		case SelectionType::SpecialEncounter:
			if(editing_town){
				if(selected_object_number>=NUM_TOWN_PLACED_SPECIALS || town.spec_id[selected_object_number] == kNO_TOWN_SPECIALS){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			else{ //editing outdoors
				if(selected_object_number>=NUM_OUT_PLACED_SPECIALS || current_terrain.spec_id[selected_object_number] == kNO_OUT_SPECIALS){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			break;
		case SelectionType::AreaDescription:
			if(editing_town){
				if(selected_object_number>=NUM_TOWN_DESCRIPTION_AREAS || town.room_rect[selected_object_number].right<=0){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			else{ //editing outdoors
				if(selected_object_number>=NUM_OUT_DESCRIPTION_AREAS || current_terrain.info_rect[selected_object_number].right<=0){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			break;
		case SelectionType::TownEntrance:
			if(selected_object_number>=NUM_OUT_TOWN_ENTRANCES || current_terrain.exit_dests[selected_object_number]==kNO_OUT_TOWN_ENTRANCE){
				selected_object_type=SelectionType::None;
				selected_object_number=0;
			}
			break;
		case SelectionType::Sign:
			if(editing_town){
				if(selected_object_number>=15 || town.sign_locs[selected_object_number].x==kNO_SIGN){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			else{ //editing outdoors
				if(selected_object_number>=8 || current_terrain.sign_locs[selected_object_number].x==kNO_SIGN){
					selected_object_type=SelectionType::None;
					selected_object_number=0;
				}
			}
			break;			
	}
}

void clear_selected_copied_objects(){
	selected_object_type=SelectionType::None;
	selected_object_number=0;
	copied_creature.number = -1;
	copied_item.which_item = -1;
	copied_ter_script.exists = FALSE;
}

location selected_instance_location(){
	location loc={-1,-1};
	switch(selected_object_type){
		case SelectionType::None:
			beep();
			break;
		case SelectionType::Creature:
			if(selected_object_number<NUM_TOWN_PLACED_CREATURES)
				loc = town.creatures[selected_object_number].start_loc;
			break;
		case SelectionType::Item:
			if(selected_object_number<NUM_TOWN_PLACED_ITEMS)
				loc = town.preset_items[selected_object_number].item_loc;
			break;
		case SelectionType::TerrainScript:
			if(selected_object_number<NUM_TER_SCRIPTS)
				loc = town.ter_scripts[selected_object_number].loc;
			break;
		case SelectionType::Waypoint:
			if(selected_object_number<NUM_WAYPOINTS)
				loc = town.waypoints[selected_object_number];
			break;
		case SelectionType::SpecialEncounter:
			if(editing_town){
				if(selected_object_number<NUM_TOWN_PLACED_SPECIALS){
					loc.x = (town.special_rects[selected_object_number].left+town.special_rects[selected_object_number].right)/2;
					loc.y = (town.special_rects[selected_object_number].top+town.special_rects[selected_object_number].bottom)/2;
				}
			}
			else{
				if(selected_object_number<NUM_OUT_PLACED_SPECIALS){
					loc.x = (current_terrain.special_rects[selected_object_number].left+current_terrain.special_rects[selected_object_number].right)/2;
					loc.y = (current_terrain.special_rects[selected_object_number].top+current_terrain.special_rects[selected_object_number].bottom)/2;
				}
			}
			break;
		case SelectionType::AreaDescription:
			if(editing_town){
				if(selected_object_number<NUM_TOWN_DESCRIPTION_AREAS){
					loc.x = (town.room_rect[selected_object_number].left+town.room_rect[selected_object_number].right)/2;
					loc.y = (town.room_rect[selected_object_number].top+town.room_rect[selected_object_number].bottom)/2;
				}
			}
			else{
				if(selected_object_number<NUM_OUT_DESCRIPTION_AREAS){
					loc.x = (current_terrain.info_rect[selected_object_number].left+current_terrain.info_rect[selected_object_number].right)/2;
					loc.y = (current_terrain.info_rect[selected_object_number].top+current_terrain.info_rect[selected_object_number].bottom)/2;
				}
			}
			break;
		case SelectionType::TownEntrance:
			if(selected_object_number<NUM_OUT_TOWN_ENTRANCES){
				loc.x = (current_terrain.exit_rects[selected_object_number].left+current_terrain.exit_rects[selected_object_number].right)/2;
				loc.y = (current_terrain.exit_rects[selected_object_number].top+current_terrain.exit_rects[selected_object_number].bottom)/2;
			}
			break;
		case SelectionType::Sign:
			if(editing_town){
				if(selected_object_number<15){
					loc = town.sign_locs[selected_object_number];
				}
			}
			else{
				if(selected_object_number<8){
					loc = current_terrain.sign_locs[selected_object_number];
				}
			}
			break;
	}
	return(loc);
}

void shift_selected_instance(short dx,short dy){
	static Rect outdoor_bounds={0,0,OUTDOOR_SIZE-1,OUTDOOR_SIZE-1};
	location loc;
	switch(selected_object_type){
		case SelectionType::None:
			beep();
			break;
		case SelectionType::Creature:
			if(selected_object_number<NUM_TOWN_PLACED_CREATURES){
				loc = town.creatures[selected_object_number].start_loc;
				loc.x += dx;
				loc.y += dy;
				if(!loc_in_active_area(loc))
					return;
				pushUndoStep(new Undo::CreatureLocationChangeStep(loc, town.creatures[selected_object_number].start_loc, selected_object_number));
				town.creatures[selected_object_number].start_loc = loc;
			}
			break;
		case SelectionType::Item:
			if(selected_object_number<NUM_TOWN_PLACED_ITEMS){
				loc = town.preset_items[selected_object_number].item_loc;
				bool wasContainer=is_container(loc.x,loc.y);
				loc.x += dx;
				loc.y += dy;
				if(!loc_in_active_area(loc))
					return;
				//because there may also be container shenanigans let's just make an undo group unconditionally
				pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
				pushUndoStep(new Undo::ItemLocationChangeStep(loc, town.preset_items[selected_object_number].item_loc, selected_object_number));
				town.preset_items[selected_object_number].item_loc =loc;
				shift_item_locs(loc);
				
				if(wasContainer!=is_container(loc.x,loc.y)){
					if(wasContainer){ //the item was in a container and moved out
						//although the item was on the same space as a container, it might have been manually marked uncontained
						unsigned char new_properties=town.preset_items[selected_object_number].properties&~item_type::contained_bit;
						if(new_properties!=town.preset_items[selected_object_number].properties){
							pushUndoStep(new Undo::MiscItemPropertyChange(new_properties, town.preset_items[selected_object_number].properties, Undo::MiscItemPropertyChange::PROPERTY_MASK, selected_object_number));
							town.preset_items[selected_object_number].properties=new_properties;
							drawToolPalette(); //need to update display of the item's properties
						}
					}
					else{ //the item was not in a container, and moved into one
						//there really shouldn't be any items marked contained but not on spaces with containers, 
						//but we don't currently seem to enforce that, so treat this case like the previous one
						unsigned char new_properties=town.preset_items[selected_object_number].properties|item_type::contained_bit;
						if(new_properties!=town.preset_items[selected_object_number].properties){
							pushUndoStep(new Undo::MiscItemPropertyChange(new_properties, town.preset_items[selected_object_number].properties, Undo::MiscItemPropertyChange::PROPERTY_MASK, selected_object_number));
							town.preset_items[selected_object_number].properties=new_properties;
							drawToolPalette(); //need to update display of the item's properties
						}
					}
				}
				pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
			}
			break;
		case SelectionType::TerrainScript:
			if(selected_object_number<NUM_TER_SCRIPTS){
				loc = town.ter_scripts[selected_object_number].loc;
				loc.x += dx;
				loc.y += dy;
				if(!loc_in_active_area(loc))
					return;
				pushUndoStep(new Undo::TerrainScriptLocationChangeStep(loc, town.ter_scripts[selected_object_number].loc, selected_object_number));
				town.ter_scripts[selected_object_number].loc = loc;
			}
			break;
		case SelectionType::Waypoint:
			if(selected_object_number<NUM_WAYPOINTS){
				loc = town.waypoints[selected_object_number];
				loc.x += dx;
				loc.y += dy;
				if(!loc_in_active_area(loc))
					return;
				pushUndoStep(new Undo::WaypointLocationChangeStep(loc, town.waypoints[selected_object_number], selected_object_number));
				town.waypoints[selected_object_number] = loc;
			}
			break;
		case SelectionType::SpecialEncounter:
			if(editing_town){
				if(selected_object_number<NUM_TOWN_PLACED_SPECIALS){
					Rect current_rect=town.special_rects[selected_object_number];
					OffsetRect(&current_rect,dx,dy);
					if(!r1_in_r2(current_rect, town.in_town_rect))
						return;
					
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					if(current_rect.top!=town.special_rects[selected_object_number].top)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.top, town.special_rects[selected_object_number].top, Undo::RectChangeStep::TOP, selected_object_number));
					if(current_rect.bottom!=town.special_rects[selected_object_number].bottom)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.bottom, town.special_rects[selected_object_number].bottom, Undo::RectChangeStep::BOTTOM, selected_object_number));
					if(current_rect.left!=town.special_rects[selected_object_number].left)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.left, town.special_rects[selected_object_number].left, Undo::RectChangeStep::LEFT, selected_object_number));
					if(current_rect.right!=town.special_rects[selected_object_number].right)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.right, town.special_rects[selected_object_number].right, Undo::RectChangeStep::RIGHT, selected_object_number));
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					
					town.special_rects[selected_object_number]=current_rect;
				}
			}
			else{
				if(selected_object_number<NUM_OUT_PLACED_SPECIALS){
					Rect current_rect=current_terrain.special_rects[selected_object_number];
					OffsetRect(&current_rect,dx,dy);
					if(!r1_in_r2(current_rect, outdoor_bounds))
						return;
					
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					if(current_rect.top!=current_terrain.special_rects[selected_object_number].top)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.top, current_terrain.special_rects[selected_object_number].top, Undo::RectChangeStep::TOP, selected_object_number));
					if(current_rect.bottom!=current_terrain.special_rects[selected_object_number].bottom)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.bottom, current_terrain.special_rects[selected_object_number].bottom, Undo::RectChangeStep::BOTTOM, selected_object_number));
					if(current_rect.left!=current_terrain.special_rects[selected_object_number].left)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.left, current_terrain.special_rects[selected_object_number].left, Undo::RectChangeStep::LEFT, selected_object_number));
					if(current_rect.right!=current_terrain.special_rects[selected_object_number].right)
						pushUndoStep(new Undo::SpecialEncounterRectChange(current_rect.right, current_terrain.special_rects[selected_object_number].right, Undo::RectChangeStep::RIGHT, selected_object_number));
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					
					current_terrain.special_rects[selected_object_number]=current_rect;
				}
			}
			break;
		case SelectionType::AreaDescription:
			if(editing_town){
				if(selected_object_number<NUM_TOWN_DESCRIPTION_AREAS){
					Rect current_rect=town.room_rect[selected_object_number];
					OffsetRect(&current_rect,dx,dy);
					if(!r1_in_r2(current_rect, town.in_town_rect))
						return;
					
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					if(current_rect.top!=town.room_rect[selected_object_number].top)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.top, town.room_rect[selected_object_number].top, Undo::RectChangeStep::TOP, selected_object_number));
					if(current_rect.bottom!=town.room_rect[selected_object_number].bottom)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.bottom, town.room_rect[selected_object_number].bottom, Undo::RectChangeStep::BOTTOM, selected_object_number));
					if(current_rect.left!=town.room_rect[selected_object_number].left)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.left, town.room_rect[selected_object_number].left, Undo::RectChangeStep::LEFT, selected_object_number));
					if(current_rect.right!=town.room_rect[selected_object_number].right)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.right, town.room_rect[selected_object_number].right, Undo::RectChangeStep::RIGHT, selected_object_number));
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					
					town.room_rect[selected_object_number]=current_rect;
				}
			}
			else{
				if(selected_object_number<NUM_OUT_DESCRIPTION_AREAS){
					Rect current_rect=current_terrain.info_rect[selected_object_number];
					OffsetRect(&current_rect,dx,dy);
					if(!r1_in_r2(current_rect, outdoor_bounds))
						return;
					
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
					if(current_rect.top!=current_terrain.info_rect[selected_object_number].top)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.top, current_terrain.info_rect[selected_object_number].top, Undo::RectChangeStep::TOP, selected_object_number));
					if(current_rect.bottom!=current_terrain.info_rect[selected_object_number].bottom)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.bottom, current_terrain.info_rect[selected_object_number].bottom, Undo::RectChangeStep::BOTTOM, selected_object_number));
					if(current_rect.left!=current_terrain.info_rect[selected_object_number].left)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.left, current_terrain.info_rect[selected_object_number].left, Undo::RectChangeStep::LEFT, selected_object_number));
					if(current_rect.right!=current_terrain.info_rect[selected_object_number].right)
						pushUndoStep(new Undo::DescriptionAreaRectChange(current_rect.right, current_terrain.info_rect[selected_object_number].right, Undo::RectChangeStep::RIGHT, selected_object_number));
					pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
					
					current_terrain.info_rect[selected_object_number]=current_rect;
				}
			}
			break;
		case SelectionType::TownEntrance:
			if(selected_object_number<NUM_OUT_TOWN_ENTRANCES){
				Rect current_rect=current_terrain.exit_rects[selected_object_number];
				OffsetRect(&current_rect,dx,dy);
				if(!r1_in_r2(current_rect, outdoor_bounds))
					return;
				
				pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
				if(current_rect.top!=current_terrain.exit_rects[selected_object_number].top)
					pushUndoStep(new Undo::TownEntranceRectChange(current_rect.top, current_terrain.exit_rects[selected_object_number].top, Undo::RectChangeStep::TOP, selected_object_number));
				if(current_rect.bottom!=current_terrain.exit_rects[selected_object_number].bottom)
					pushUndoStep(new Undo::TownEntranceRectChange(current_rect.bottom, current_terrain.exit_rects[selected_object_number].bottom, Undo::RectChangeStep::BOTTOM, selected_object_number));
				if(current_rect.left!=current_terrain.exit_rects[selected_object_number].left)
					pushUndoStep(new Undo::TownEntranceRectChange(current_rect.left, current_terrain.exit_rects[selected_object_number].left, Undo::RectChangeStep::LEFT, selected_object_number));
				if(current_rect.right!=current_terrain.exit_rects[selected_object_number].right)
					pushUndoStep(new Undo::TownEntranceRectChange(current_rect.right, current_terrain.exit_rects[selected_object_number].right, Undo::RectChangeStep::RIGHT, selected_object_number));
				pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
				
				current_terrain.exit_rects[selected_object_number]=current_rect;
			}
			break;
		case SelectionType::Sign:
			beep();
			break;
	}
}

void rotate_selected_instance(int dir)
{
	//only work on creatures
	if(selected_object_type==SelectionType::Creature && selected_object_number<NUM_TOWN_PLACED_CREATURES && town.creatures[selected_object_number].exists()){
		short facing = town.creatures[selected_object_number].facing + dir;
		if(facing<0)
			facing+=4;
		else if(facing>3)
			facing-=4;
		pushUndoStep(new Undo::MiscCreaturePropertyChange(facing, town.creatures[selected_object_number].facing, Undo::MiscCreaturePropertyChange::FACING, selected_object_number));
		town.creatures[selected_object_number].facing = facing;
		drawToolDetails();
	}
}

void setSelection(SelectionType::SelectionType_e type, unsigned short num, bool jumpTo){
	selected_object_type=type;
	selected_object_number=num;
	if(jumpTo)
		jumpToSelectedInstance();
}

void jumpToSelectedInstance(){
	if(selected_object_type==SelectionType::None)
		return;
	location loc=selected_instance_location();
	//TODO: the 2D in-bounds logic here is out of date, it needs to take into acount the curent window dimensions
	if((cur_viewing_mode == 0 && (abs(loc.x-cen_x)>4 || abs(loc.y-cen_y)>4)) || ((cur_viewing_mode==10 || cur_viewing_mode==11) && out_of_view_3D(loc))){
		cen_x = loc.x;
		cen_y = loc.y;
		draw_terrain();
	}
}

void create_navpoint(location spot_hit)
{
	short i;
	
	for (i = 0; i < NUM_WAYPOINTS; i++) {
		if (town.waypoints[i].x < 0) {
			town.waypoints[i] = spot_hit;
			setSelection(SelectionType::Waypoint, i, false);
			pushUndoStep(new Undo::CreateWaypoint(i,spot_hit,true));
			return;
		}
	}
}

void delete_navpoint(location spot_hit)
{
	short i;
	
	for (i = 0; i < NUM_WAYPOINTS; i++) {
		if (same_point(town.waypoints[i],spot_hit)) {
			town.waypoints[i].x = kINVAL_TOWN_LOC_X;
			town.waypoints[i].y = kINVAL_TOWN_LOC_Y;
			pushUndoStep(new Undo::CreateWaypoint(i,spot_hit,false));
			return;
		}
	}
}

void frill_terrain()
{
	short i,j;
	short terrain_type, old_terrain_type;
	unsigned char floor_type, old_floor_type;
	int edge_correct = 0;
	//if the edge floor repeats to infinity, don't add frills to edge spaces, to avoid weird looking rows
	if(town.external_floor_type == -1)
		edge_correct = 1;
	
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = edge_correct; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48)-edge_correct; i++){
		for (j = edge_correct; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48)-edge_correct; j++) {
			old_terrain_type = terrain_type = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
			old_floor_type = floor_type = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
			
			// cave type floors
			if ((floor_type == 0) && (get_ran(1,1,20) < 4))
				floor_type = 3;
			if ((floor_type == 0) && (get_ran(1,1,20) < 3))
				floor_type = 1;
			if ((floor_type == 0) && (get_ran(1,1,20) < 2))
				floor_type = 2;
			if ((floor_type == 4) && (get_ran(1,1,20) < 4))
				floor_type = 7;
			if ((floor_type == 4) && (get_ran(1,1,20) < 3))
				floor_type = 5;
			if ((floor_type == 4) && (get_ran(1,1,20) < 2))
				floor_type = 6;
			if ((floor_type == 8) && (get_ran(1,1,20) < 6))
				floor_type = 10;
			if ((floor_type == 72) && (get_ran(1,1,100) < 5))
				floor_type = 73;
			if ((floor_type == 72) && (get_ran(1,1,100) < 5))
				floor_type = 74;
			
			// terrain type floors
			if ((floor_type == 37) && (get_ran(1,1,20) < 4))
				floor_type = 40;
			if ((floor_type == 37) && (get_ran(1,1,20) < 3))
				floor_type = 38;
			if ((floor_type == 37) && (get_ran(1,1,20) < 2))
				floor_type = 39;
			if ((floor_type == 41) && (get_ran(1,1,20) < 4))
				floor_type = 44;
			if ((floor_type == 41) && (get_ran(1,1,40) == 1))
				floor_type = 42;
			if ((floor_type == 41) && (get_ran(1,1,20) < 2))
				floor_type = 43;
			
			if(terrain_type!=old_terrain_type){
				pushUndoStep(new Undo::TerrainChange(i,j,terrain_type,old_terrain_type));
				if (editing_town == TRUE)
					t_d.terrain[i][j] = terrain_type;
				else
					current_terrain.terrain[i][j] = terrain_type;
			}
			if(floor_type!=old_floor_type){
				pushUndoStep(new Undo::FloorChange(i,j,floor_type,old_floor_type));
				if (editing_town == TRUE)
					t_d.floor[i][j] = floor_type;
				else
					current_terrain.floor[i][j] = floor_type;
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
	draw_terrain();
}

void unfrill_terrain()
{
	short i,j;
	short terrain_type, old_terrain_type;
	unsigned char floor_type, old_floor_type;
	
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = 0; i < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); i++){
		for (j = 0; j < ((editing_town == TRUE) ? max_zone_dim[town_type] : 48); j++) {
			old_terrain_type = terrain_type = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
			old_floor_type = floor_type = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
			
			if (floor_type == 3)
				floor_type = 0;
			if (floor_type == 2)
				floor_type = 0;
			if (floor_type == 1)
				floor_type = 0;
			if (floor_type == 5)
				floor_type = 4;
			if (floor_type == 6)
				floor_type = 4;
			if (floor_type == 10)
				floor_type = 8;
			if (floor_type == 73)
				floor_type = 72;
			if (floor_type == 74)
				floor_type = 72;
			
			if (floor_type == 38)
				floor_type = 37;
			if (floor_type == 39)
				floor_type = 37;
			if (floor_type == 40)
				floor_type = 37;
			if (floor_type == 42)
				floor_type = 41;
			if (floor_type == 43)
				floor_type = 41;
			if (floor_type == 44)
				floor_type = 41;
			
			if(terrain_type!=old_terrain_type){
				pushUndoStep(new Undo::TerrainChange(i,j,terrain_type,old_terrain_type));
				if (editing_town == TRUE)
					t_d.terrain[i][j] = terrain_type;
				else
					current_terrain.terrain[i][j] = terrain_type;
			}
			if(floor_type!=old_floor_type){
				pushUndoStep(new Undo::FloorChange(i,j,floor_type,old_floor_type));
				if (editing_town == TRUE)
					t_d.floor[i][j] = floor_type;
				else
					current_terrain.floor[i][j] = floor_type;
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
	draw_terrain();
}

void create_new_creature(short c_to_create,location create_loc,creature_start_type *c_to_make)
{
	short i;
	
	//if (!strcmp(scen_data.scen_creatures[c_to_create].name,"Unused"))
	//	return;
	if (c_to_create < 0)	
		return;
	if (loc_in_active_area(create_loc) == FALSE) {
		give_error("You can't place a creature here. This space is outside of the active town area.","",0);
		return;
	}
	
	for (i = 0; i < NUM_TOWN_PLACED_CREATURES; i++){
		if ((town.creatures[i].exists()) && (same_point(town.creatures[i].start_loc,create_loc)))  {
		  	beep();
		  	return;
		}
	}
	
	for (i = 0; i < NUM_TOWN_PLACED_CREATURES; i++){
		if (town.creatures[i].exists() == FALSE) {
			town.creatures[i].clear_creature_start_type();
			selected_object_number=i;
			selected_object_type=SelectionType::Creature;
			if (c_to_make != NULL) {
				town.creatures[i] = *c_to_make;
				town.creatures[i].start_loc = create_loc;
				town.creatures[i].character_id = cur_town * 100 + i;
				return;
			}
			
			town.creatures[i].number = c_to_create;
			town.creatures[i].start_loc = create_loc;
			
			town.creatures[i].start_attitude = 
				scen_data.scen_creatures[c_to_create].default_attitude;
			if (town.creatures[i].start_attitude < 2)
				town.creatures[i].start_attitude = 2;
			town.creatures[i].character_id = cur_town * 100 + i;
			pushUndoStep(new Undo::CreateCreature(i,town.creatures[i],true));
			
			return;
		}	
	}
}
#endif

// if i_to_make is not null, copies all of the info from this structure
// returns TRUE is tried to place in an impossible spot, or item was placed
// returns false is item not palced because too many
Boolean create_new_item(short item_to_create,location create_loc,Boolean property,item_type *i_to_make)
{
	short i;
	
	//if (!strcmp(scen_data.scen_items[item_to_create].name,"Unused"))
	//	return TRUE;
	if (item_to_create < 0)	
		return TRUE;
	if (loc_in_active_area(create_loc) == FALSE) {
		//give_error("You can't place an item here. This space is outside of the active town area.","",0);
		return TRUE;
	}
	
	for (i = 0; i < NUM_TOWN_PLACED_ITEMS; i++){
		if (town.preset_items[i].exists() == FALSE) {
			selected_object_number=i;
			selected_object_type=SelectionType::Item;
			if (i_to_make != NULL) {
				town.preset_items[i] = *i_to_make;
				town.preset_items[i].item_loc = create_loc;
				shift_item_locs(create_loc);
				return TRUE;
			}
			town.preset_items[i].which_item = item_to_create;
			town.preset_items[i].item_loc = create_loc;
			town.preset_items[i].charges = scen_data.scen_items[item_to_create].charges;
			
			town.preset_items[i].properties = 0;
			if (property)
				town.preset_items[i].properties += 2;
			
			if(is_container(create_loc.x, create_loc.y))
			   town.preset_items[i].properties |= item_type::contained_bit;
			shift_item_locs(create_loc);
			
			return TRUE;
		}
	}
	return FALSE;
}

#if 0
Boolean create_new_ter_script(const char *ter_script_name,location create_loc,in_town_on_ter_script_type *script_to_make)
{
	short i;
	
	if (strlen(ter_script_name) <= 0)	
		return TRUE;
	if (strlen(ter_script_name) >= SCRIPT_NAME_LEN)	
		return TRUE;
	if (loc_in_active_area(create_loc) == FALSE) {
		//give_error("You can't place a terrain script here. This space is outside of the active town area.","",0);
		return TRUE;
	}
	
	for (i = 0; i < NUM_TER_SCRIPTS; i++){
		if ((town.ter_scripts[i].exists) && (same_point(town.ter_scripts[i].loc,create_loc)))  {
			//give_error("You can't make or paste a terrain script on a spot which already has a terrain script.","If you want to edit this terrain script, use the Select/Edit Placed Object button",0);
		  	return TRUE;
		}	
	}
	for (i = 0; i < NUM_TER_SCRIPTS; i++){
		if (town.ter_scripts[i].exists == FALSE) {
			town.ter_scripts[i].clear_in_town_on_ter_script_type();
			
			selected_object_number=i;
			selected_object_type=SelectionType::TerrainScript;
			if (script_to_make != NULL) {
				town.ter_scripts[i] = *script_to_make;
				town.ter_scripts[i].loc = create_loc;
				return TRUE;
			}
			town.ter_scripts[i].exists = TRUE;
			strcpy(town.ter_scripts[i].script_name,ter_script_name);
			town.ter_scripts[i].loc = create_loc;
			
			return TRUE;
		}	
	}
	//give_error("You can only have 100 active terrain scripts in a zone. No terrain script has been created.","",0);
	return FALSE;
}
#endif

void shift_item_locs(location spot_hit)
{
	short i;
	short num_items_there = 0,cur_item_pos = 0;
	location offsets[4][4] = {{{0,0},{0,0},{0,0},{0,0}},
	{{-4,-2},{4,2},{0,0},{0,0}},
	{{-4,-2},{4,-2},{-4,2},{0,0}},
	{{-4,-2},{4,-2},{-4,2},{4,2}}};
	
	for (i = 0; i < NUM_TOWN_PLACED_ITEMS; i++){
		if ((town.preset_items[i].exists()) && (same_point(town.preset_items[i].item_loc,spot_hit))) 
			num_items_there++;
	}
	for (i = 0; i < NUM_TOWN_PLACED_ITEMS; i++){
		if ((town.preset_items[i].exists()) && (same_point(town.preset_items[i].item_loc,spot_hit))) {
			town.preset_items[i].item_shift = offsets[min(num_items_there - 1,3)][cur_item_pos % 4];
			cur_item_pos++;
		}
	}
}

#if 0
void place_items_in_town()
{
	location l;
	short i,j,k,x;
	Boolean place_failed = FALSE;
	
	for (i=town.in_town_rect.left; i < town.in_town_rect.right;i++){
		for (j = town.in_town_rect.top; j < town.in_town_rect.bottom;j++) {
			l.x = i; l.y = j;
			
			for (k = 0; k < 10; k++){
				if (t_d.terrain[i][j] == scenario.storage_shortcuts[k].ter_type) {
					for (x = 0; x < 10; x++){
						if(get_ran(1,1,100)<=scenario.storage_shortcuts[k].item_odds[x]){
						if (create_new_item(scenario.storage_shortcuts[k].item_num[x],l,scenario.storage_shortcuts[k].property,NULL) == FALSE)
							place_failed = TRUE;
						}
					}
				}
			}
		}
	}
	if (place_failed == TRUE)
		give_error("Not all of the random items could be placed. The preset item per town limit of 144 was reached.","",0);
	draw_terrain();
}

void create_town_entry(Rect rect_hit){
	short x,y;
	
	for (x = 0; x < 8; x++){
		if(current_terrain.exit_dests[x] == kNO_OUT_TOWN_ENTRANCE) {
			y = get_a_number(856,0,0,scenario.num_towns - 1);
			if(y==-1)
				return;//the user cancelled the action
			if (cre(y,0,scenario.num_towns - 1,"The town number you gave was out of range. It must be from 0 to the number of towns in the scenario - 1.","",0) == TRUE) return;
			if (y >= 0) {
				current_terrain.exit_dests[x] = y;
				current_terrain.exit_rects[x] = rect_hit;
				selected_object_type=SelectionType::TownEntrance;
				selected_object_number=x;
				pushUndoStep(new Undo::CreateTownEntrance(selected_object_number,current_terrain.exit_rects[x],current_terrain.exit_dests[x],true));
			}
			return;
		}
	}
	give_error("You can't set more than 8 town entrances in any outdoor section.","",0);
}

void edit_town_entry(location spot_hit){
	short x,y;
	
	for (x = 0; x < NUM_OUT_TOWN_ENTRANCES; x++){
		if(current_terrain.exit_dests[x]!=kNO_OUT_TOWN_ENTRANCE && (loc_touches_rect(spot_hit,current_terrain.exit_rects[x]))) {
			y = get_a_number(856,current_terrain.exit_dests[x],0,scenario.num_towns - 1);
			if(y==-1)
				return;//the user cancelled the action
			if (cre(y,-1,scenario.num_towns - 1,"The town number you gave was out of range. It must be from 0 to the number of towns in the scenario - 1. ","",0) == TRUE) return;
			if(current_terrain.exit_dests[x]!=y)
				pushUndoStep(new Undo::TownEntranceTownChange(y,current_terrain.exit_dests[x],x));
			current_terrain.exit_dests[x] = y;
			return;
		}
	}
}

void set_rect_height(Rect r){
	short i,j,h;
	
	h = get_a_number(872,0,0,99);
	if ((h < 1) || (h > 100))
		return;
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = r.left; i < r.right + 1; i++){
		for (j = r.top; j < r.bottom + 1; j++) {
			if (editing_town && (t_d.height[i][j] != h)){
				pushUndoStep(new Undo::HeightChange(i,j,h,t_d.height[i][j]));
				t_d.height[i][j] = h;
			}
			else if(!editing_town && current_terrain.height[i][j] != h){
				pushUndoStep(new Undo::HeightChange(i,j,h,current_terrain.height[i][j]));
				current_terrain.height[i][j] = h;
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

void add_rect_height(Rect r)
{
	short i,j,h, newh;
	
	h = get_a_number(880,0,-99,99);
	if ((h < -100) || (h > 100))
		return;
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = r.left; i < r.right + 1; i++){
		for (j = r.top; j < r.bottom + 1; j++) {
			if (editing_town){
				newh = t_d.height[i][j] + h;
				if(newh<0)
					newh=0;
				else if(newh>99)
					newh=99;
				pushUndoStep(new Undo::HeightChange(i,j,newh,t_d.height[i][j]));
				t_d.height[i][j] = newh;
			}
			else if(!editing_town){
				newh = current_terrain.height[i][j] + h;
				if(newh<0)
					newh=0;
				else if(newh>99)
					newh=99;
				pushUndoStep(new Undo::HeightChange(i,j,newh,current_terrain.height[i][j]));
				current_terrain.height[i][j] = newh;
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

// put a bit of terrain down without doing redrawing or anything odd and without drawing anything
void shy_put_terrain(short i,short j,short ter)
{
	if (editing_town == TRUE) {
		if (t_d.terrain[i][j] == 0)
			t_d.terrain[i][j] = ter;
		return;
	}
	if (current_terrain.terrain[i][j] == 0)
		current_terrain.terrain[i][j] = ter;
}

// swaps walls of type 1 to type 2 and vise versa
void transform_walls(Rect theWorking_rect)
{
	short i,j;
	short ter,new_ter;
	
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = theWorking_rect.left; i <= theWorking_rect.right; i++){
		for (j = theWorking_rect.top;j <= theWorking_rect.bottom; j++) {
			new_ter = ter = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
			if ((ter >= 2) && (ter <= 37))
				new_ter = ter + 36;
			else if ((ter >= 38) && (ter <= 73))
				new_ter = ter - 36;
			if(new_ter!=ter)
				pushUndoStep(new Undo::TerrainChange(i,j,new_ter,ter));
			if (editing_town == TRUE)
				t_d.terrain[i][j] = new_ter;
			else 
				current_terrain.terrain[i][j] = new_ter;
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

Boolean is_not_darkness_floor(short i,short j) 
{
	unsigned char floor = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
	return(floor!=255);
}

// places walls of wall type 1 surrounding blackness floor (floor 255)
void place_bounding_walls(Rect theWorking_rect)
{
	short i,j;
	Boolean ft[4]; // means: wallable floor there
	short ter,new_ter;
	unsigned char floor;
	
	if (theWorking_rect.left == 0)
		theWorking_rect.left = 1;
	if (theWorking_rect.top == 0)
		theWorking_rect.top = 1;
	if (theWorking_rect.right == ((editing_town == TRUE) ? max_zone_dim[town_type] : 48) - 1)
		theWorking_rect.right = ((editing_town == TRUE) ? max_zone_dim[town_type] : 48) - 2;
	if (theWorking_rect.bottom == ((editing_town == TRUE) ? max_zone_dim[town_type] : 48) - 1)
		theWorking_rect.bottom = ((editing_town == TRUE) ? max_zone_dim[town_type] : 48) - 2;
	
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::BEGIN_GROUP));
	for (i = theWorking_rect.left; i <= theWorking_rect.right; i++){
		for (j = theWorking_rect.top;j <= theWorking_rect.bottom; j++) {
			ter = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
			floor = (editing_town == TRUE) ? t_d.floor[i][j] : current_terrain.floor[i][j];
			if ((floor == 255) && (ter == 0)) {
				ft[0] = ft[1] = ft[2] = ft[3] = FALSE;
				
				if (is_not_darkness_floor(i,j-1))
					ft[0] = TRUE;
				if (is_not_darkness_floor(i - 1,j))
					ft[1] = TRUE;
				if (is_not_darkness_floor(i,j+1))
					ft[2] = TRUE;
				if (is_not_darkness_floor(i + 1,j))
					ft[3] = TRUE;
				
				new_ter = (editing_town == TRUE) ? t_d.terrain[i][j] : current_terrain.terrain[i][j];
				if ((ft[0] == TRUE) && (ft[1] == TRUE)) {
					new_ter = 6;
					if (ft[2] == TRUE) 
						shy_put_terrain(i,j + 1,2);
					if (ft[3] == TRUE) 
						shy_put_terrain(i + 1,j,3);
				}
				else if ((ft[2] == TRUE) && (ft[1] == TRUE)) {
					new_ter = 7;
					if (ft[3] == TRUE) 
						shy_put_terrain(i + 1,j,3);					
				}
				else if ((ft[2] == TRUE) && (ft[3] == TRUE))
					new_ter = 8;
				else if ((ft[0] == TRUE) && (ft[3] == TRUE))
					new_ter = 9;
				else if (ft[0] == TRUE) {
					new_ter = 2;
					if (ft[2] == TRUE) 
						shy_put_terrain(i,j + 1,2);					
				}
				else if (ft[1] == TRUE) {
					new_ter = 3;
					if (ft[3] == TRUE) 
						shy_put_terrain(i + 1,j,3);					
				}
				else if (ft[2] == TRUE) {
					new_ter = 4;
				}
				else if (ft[3] == TRUE) {
					new_ter = 5;
				}
				if(new_ter!=ter)
					pushUndoStep(new Undo::TerrainChange(i,j,new_ter,ter));
				if (editing_town)
					t_d.terrain[i][j] = new_ter;
				else
					current_terrain.terrain[i][j] = new_ter;
			}
		}
	}
	pushUndoStep(new Undo::UndoGroupDelimiter(Undo::UndoStep::END_GROUP));
}

Boolean is_wall(short x, short y)
{
	if (editing_town == TRUE) {
		if ((t_d.terrain[x][y] >= 2) && (t_d.terrain[x][y] <= 73))
			return TRUE;
	}
	if (editing_town == FALSE) {
		if ((current_terrain.terrain[x][y] >= 2) && (current_terrain.terrain[x][y] <= 73))
			return TRUE;
	}
	return FALSE;
}

void clean_walls()
{
	short i,j;
	
	if (editing_town == TRUE) {
		for (i = 1; i < max_zone_dim[town_type] - 1; i++){
			for (j = 1; j < max_zone_dim[town_type] - 1; j++) {
				if ((t_d.terrain[i][j] == 6) && (is_dumb_terrain(t_d.terrain[i][j - 1])) && (is_wall(i + 1,j) == FALSE)) {
					t_d.terrain[i][j] = 3; t_d.terrain[i][j - 1] = 4;
				}
				if ((t_d.terrain[i][j] == 6) && (is_dumb_terrain(t_d.terrain[i - 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					t_d.terrain[i][j] = 2; t_d.terrain[i - 1][j] = 5;
				}
				if ((t_d.terrain[i][j] == 7) && (is_dumb_terrain(t_d.terrain[i][j + 1])) && (is_wall(i + 1,j) == FALSE)) {
					t_d.terrain[i][j] = 3; t_d.terrain[i][j + 1] = 2;
				}
				if ((t_d.terrain[i][j] == 7) && (is_dumb_terrain(t_d.terrain[i - 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					t_d.terrain[i][j] = 4; t_d.terrain[i - 1][j] = 5;
				}
				if ((t_d.terrain[i][j] == 8) && (is_dumb_terrain(t_d.terrain[i][j + 1])) && (is_wall(i - 1,j ) == FALSE)) {
					t_d.terrain[i][j] = 5; t_d.terrain[i][j + 1] = 2;
				}
				if ((t_d.terrain[i][j] == 8) && (is_dumb_terrain(t_d.terrain[i + 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					t_d.terrain[i][j] = 4; t_d.terrain[i + 1][j] = 3;
				}
				if ((t_d.terrain[i][j] == 9) && (is_dumb_terrain(t_d.terrain[i][j - 1])) && (is_wall(i - 1,j) == FALSE)) {
					t_d.terrain[i][j] = 5; t_d.terrain[i][j - 1] = 4;
				}
				if ((t_d.terrain[i][j] == 9) && (is_dumb_terrain(t_d.terrain[i + 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					t_d.terrain[i][j] = 2; t_d.terrain[i + 1][j] = 3;
				}				
				if ((t_d.terrain[i][j] == 42) && (is_dumb_terrain(t_d.terrain[i][j - 1])) && (is_wall(i + 1,j) == FALSE)) {
					t_d.terrain[i][j] = 3 + 36; t_d.terrain[i][j - 1] = 4 + 36;
				}
				if ((t_d.terrain[i][j] == 42) && (is_dumb_terrain(t_d.terrain[i - 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					t_d.terrain[i][j] = 2 + 36; t_d.terrain[i - 1][j] = 5 + 36;
				}
				if ((t_d.terrain[i][j] == 43) && (is_dumb_terrain(t_d.terrain[i][j + 1])) && (is_wall(i + 1,j) == FALSE)) {
					t_d.terrain[i][j] = 3 + 36; t_d.terrain[i][j + 1] = 2 + 36;
				}
				if ((t_d.terrain[i][j] == 43) && (is_dumb_terrain(t_d.terrain[i - 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					t_d.terrain[i][j] = 4 + 36; t_d.terrain[i - 1][j] = 5 + 36;
				}
				if ((t_d.terrain[i][j] == 44) && (is_dumb_terrain(t_d.terrain[i][j + 1])) && (is_wall(i - 1,j) == FALSE)) {
					t_d.terrain[i][j] = 41; t_d.terrain[i][j + 1] = 38;
				}
				if ((t_d.terrain[i][j] == 44) && (is_dumb_terrain(t_d.terrain[i + 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					t_d.terrain[i][j] = 40; t_d.terrain[i + 1][j] = 39;
				}
				if ((t_d.terrain[i][j] == 45) && (is_dumb_terrain(t_d.terrain[i][j - 1])) && (is_wall(i - 1,j) == FALSE)) {
					t_d.terrain[i][j] = 5 + 36; t_d.terrain[i][j - 1] = 4 + 36;
				}
				if ((t_d.terrain[i][j] == 45) && (is_dumb_terrain(t_d.terrain[i + 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					t_d.terrain[i][j] = 2 + 36; t_d.terrain[i + 1][j] = 3 + 36;
				}		
			}
		}
	}
	if (editing_town == FALSE) {
		for (i = 1; i < 47; i++){
			for (j = 1; j < 47; j++) {
				if ((current_terrain.terrain[i][j] == 6) && (is_dumb_terrain(current_terrain.terrain[i][j - 1])) && (is_wall(i + 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 3; current_terrain.terrain[i][j - 1] = 4;
				}
				if ((current_terrain.terrain[i][j] == 6) && (is_dumb_terrain(current_terrain.terrain[i - 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					current_terrain.terrain[i][j] = 2; current_terrain.terrain[i - 1][j] = 5;
				}
				if ((current_terrain.terrain[i][j] == 7) && (is_dumb_terrain(current_terrain.terrain[i][j + 1])) && (is_wall(i + 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 3; current_terrain.terrain[i][j + 1] = 2;
				}
				if ((current_terrain.terrain[i][j] == 7) && (is_dumb_terrain(current_terrain.terrain[i - 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					current_terrain.terrain[i][j] = 4; current_terrain.terrain[i - 1][j] = 5;
				}
				if ((current_terrain.terrain[i][j] == 8) && (is_dumb_terrain(current_terrain.terrain[i][j + 1])) && (is_wall(i - 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 5; current_terrain.terrain[i][j + 1] = 2;
				}
				if ((current_terrain.terrain[i][j] == 8) && (is_dumb_terrain(current_terrain.terrain[i + 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					current_terrain.terrain[i][j] = 4; current_terrain.terrain[i + 1][j] = 3;
				}
				if ((current_terrain.terrain[i][j] == 9) && (is_dumb_terrain(current_terrain.terrain[i][j - 1])) && (is_wall(i - 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 5; current_terrain.terrain[i][j - 1] = 4;
				}
				if ((current_terrain.terrain[i][j] == 9) && (is_dumb_terrain(current_terrain.terrain[i + 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					current_terrain.terrain[i][j] = 2; current_terrain.terrain[i + 1][j] = 3;
				}
				if ((current_terrain.terrain[i][j] == 42) && (is_dumb_terrain(current_terrain.terrain[i][j - 1])) && (is_wall(i + 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 3 + 36; current_terrain.terrain[i][j - 1] = 4 + 36;
				}
				if ((current_terrain.terrain[i][j] == 42) && (is_dumb_terrain(current_terrain.terrain[i - 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					current_terrain.terrain[i][j] = 2 + 36; current_terrain.terrain[i - 1][j] = 5 + 36;
				}
				if ((current_terrain.terrain[i][j] == 43) && (is_dumb_terrain(current_terrain.terrain[i][j + 1])) && (is_wall(i + 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 3 + 36; current_terrain.terrain[i][j + 1] = 2 + 36;
				}
				if ((current_terrain.terrain[i][j] == 43) && (is_dumb_terrain(current_terrain.terrain[i - 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					current_terrain.terrain[i][j] = 4 + 36; current_terrain.terrain[i - 1][j] = 5 + 36;
				}
				if ((current_terrain.terrain[i][j] == 44) && (is_dumb_terrain(current_terrain.terrain[i][j + 1])) && (is_wall(i - 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 41; current_terrain.terrain[i][j + 1] = 38;
				}
				if ((current_terrain.terrain[i][j] == 44) && (is_dumb_terrain(current_terrain.terrain[i + 1][j])) && (is_wall(i,j - 1) == FALSE)) {
					current_terrain.terrain[i][j] = 40; current_terrain.terrain[i + 1][j] = 39;
				}
				if ((current_terrain.terrain[i][j] == 45) && (is_dumb_terrain(current_terrain.terrain[i][j - 1])) && (is_wall(i - 1,j) == FALSE)) {
					current_terrain.terrain[i][j] = 5 + 36; current_terrain.terrain[i][j - 1] = 4 + 36;
				}
				if ((current_terrain.terrain[i][j] == 45) && (is_dumb_terrain(current_terrain.terrain[i + 1][j])) && (is_wall(i,j + 1) == FALSE)) {
					current_terrain.terrain[i][j] = 2 + 36; current_terrain.terrain[i + 1][j] = 3 + 36;
				}
			}
		}
	}
}

// returns true if it's a ter which can be easily rubbed out
Boolean is_dumb_terrain(short ter){
	return(!ter);
}
#endif

// Goes to all items and sets whether they are currently contained in an object or not
void set_all_items_containment(){
	for(short i = 0; i < NUM_TOWN_PLACED_ITEMS; i++){
		if(town.preset_items[i].which_item >= 0){
			short ter = t_d.terrain[ (short)town.preset_items[i].item_loc.x][ (short)town.preset_items[i].item_loc.y];
			
			if(( is_crate(town.preset_items[i].item_loc.x,town.preset_items[i].item_loc.y)) 
				|| (is_barrel(town.preset_items[i].item_loc.x,town.preset_items[i].item_loc.y))
				|| (scen_data.scen_terrains[ter].special == 40))
							town.preset_items[i].properties = town.preset_items[i].properties | 4;
            else 
                town.preset_items[i].properties = town.preset_items[i].properties & 251;
		}
	}
}

#if 0
//mode is used to describe whether a container was added, removed, or whether the function should figure everything out by itself
//mode = -1: a container terrain was removed
//mode = 0: auto detect whether there is a container or not
//mode = 1: a container terrain was added
void set_items_containment(int x, int y, int mode){
	bool container=false;
	if(mode){ //know that a container terrain changed
		if(is_crate(x,y) || is_barrel(x,y))
			return; //if there is a crate or barrel already present, containment hasn't changed
		container = (mode==1);
	}
	else //need to find out about presence of containers
		container = is_container(x, y);
	
	for(short i = 0; i < NUM_TOWN_PLACED_ITEMS; i++){
		if(town.preset_items[i].which_item>=0 && town.preset_items[i].item_loc.x==x && town.preset_items[i].item_loc.y==y){
			if(container) //mark the item contained
				town.preset_items[i].properties|=item_type::contained_bit;
			else //mark the item uncontained
				town.preset_items[i].properties&=~item_type::contained_bit;
		}
	}
}
#endif

void set_up_lights(){
	short i,j,rad;
	location where,l;
	Boolean where_lit[64][64],store_edit;
	terrain_type_type ter;
	short wherex, wherey;
	
	store_edit =  editing_town;
	editing_town = TRUE;
	
	// Find light sources
	for (i = 0; i < 64; i++)
		for (j = 0; j < 64; j++)
			where_lit[i][j] = 0;
	
	for (i = 0; i < max_zone_dim[town_type]; i++){
		for (j = 0; j < max_zone_dim[town_type]; j++) {
			l.x = i; l.y = j;
			ter = get_ter(t_d.terrain[i][j]);
			rad = max((short)ter.light_radius, (short)scen_data.scen_floors[t_d.floor[i][j]].light_radius);
			if (rad > 0) {
				for (wherex = max(0,i - rad); wherex < min((short)max_zone_dim[town_type],(short)(i + rad + 1)); wherex++) {
					for (wherey = max(0,j - rad); wherey < min((short)max_zone_dim[town_type],(short)(j + rad + 1)); wherey++) {
						where.x = wherex;	where.y = wherey;
						if (/*(where_lit[where.x][where.y] == 0) && */(dist(where,l) <= rad) && (old_can_see_in(l,where,0,0) == TRUE)) {
							where_lit[wherex][wherey] = where_lit[wherex][wherey] + rad - dist(where,l) + 1;
							where_lit[wherex][wherey] = min((short)8,(short)where_lit[wherex][wherey]);
						}
					}
				}
			}
		}
	}
	for (i = 0; i < 64; i++){
		for (j = 0; j < 64; j++) {
			t_d.lighting[i][j] = where_lit[i][j];
		}
	}
	editing_town = store_edit;
}

bool old_can_see_in(location p1,location p2,short check_light,short check_travel)
{
	bool a,b;
	
	old_can_see(p1,p2,check_light,check_travel,&a,&b);
	return b;
}

// returns TRUE if you can see p2 from p1
// check_light - returns FALSE if p2 is in darkness
// check travel - returns FALSE if path is obstructed by, say, water or a wall w. window
void old_can_see(location p1,location p2,short check_light,short check_travel,bool *see_to,bool *see_in)
{
	short t;
	short dx,dy;
	short x_dir = 2,y_dir = 0,x_back_dir = 6,y_back_dir = 4,num_shifts = 0;
	// dirs 0 - n 1 - nw 2 - w and so on to 7 - ne
	location shift_dir = {0,0},empty_loc = {0,0};
	location cur_loc,next_loc;
	Boolean store_to = FALSE,store_in = FALSE;
	
	*see_to = TRUE;
	*see_in = TRUE;
	if (same_point(p1,p2))
		return;
	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	shift_dir.x = (p2.x > p1.x) ? 1 : -1;
	shift_dir.y = (p2.y > p1.y) ? 1 : -1;
	if (p2.x > p1.x) {
		x_dir = 6; x_back_dir = 2;
	}
	if (p2.y > p1.y) {
		y_dir = 4; y_back_dir = 0;
	}
	cur_loc = p1;
	
	if (dx >= dy) {
		y_dir = locs_to_dir(empty_loc,shift_dir);
		y_back_dir = (y_dir + 4) % 8;
		//if ((p1.x - p2.x == 1) && (p1.y - p2.y == 1))
		//	print_nums(99,y_dir,y_back_dir);
		for (t = 0; t < dx; t++) {
			if (((t + 1) * dy) / dx > num_shifts) {
				num_shifts++;// = (t * dy) / dx;
				next_loc = cur_loc;
				//next_loc.x += shift_dir.x;
				next_loc.y += shift_dir.y;
				if (look_block(cur_loc,y_dir) == TRUE) 
					*see_to = FALSE;
				if (look_block(next_loc,y_back_dir) == TRUE)
					*see_in = FALSE;
				//if ((p1.x - p2.x == 1) && (p1.y - p2.y == 1)) {
				//	print_nums(999,look_block(cur_loc,y_dir),look_block(next_loc,y_back_dir));
				//	print_nums(next_loc.x,next_loc.y,y_back_dir);	
				//	}
				if ((check_travel == TRUE) &&
					(move_block(cur_loc,y_dir) == TRUE))
					*see_to = FALSE;
				if ((check_travel == TRUE) &&
					(move_block(next_loc,y_back_dir) == TRUE))
					*see_in = FALSE;
				cur_loc = next_loc;
			}
			//else {
			next_loc = cur_loc;
			next_loc.x += shift_dir.x;
			if (look_block(cur_loc,x_dir) == TRUE) 
				*see_to = FALSE;
			if (look_block(next_loc,x_back_dir) == TRUE)
				*see_in = FALSE;
			if ((check_travel == TRUE) &&
				(move_block(cur_loc,x_dir) == TRUE))
				*see_to = FALSE;
			if ((check_travel == TRUE) &&
				(move_block(next_loc,x_back_dir) == TRUE))
				*see_in = FALSE;
			cur_loc = next_loc;
			//	}
			if (same_point(cur_loc,p2)) {
				if (*see_to == FALSE)
					*see_in = FALSE;
				t = 10000;
				return;
			}
			else if ((*see_in == FALSE) || (*see_to == FALSE)) {
				*see_in = *see_to = FALSE;
				t = 10000;
				return;
			}
		}
		store_to = *see_to;
		store_in = *see_in;
	}
	num_shifts = 0;
	if (dy > dx) {
		x_dir = locs_to_dir(empty_loc,shift_dir);
		x_back_dir = (x_dir + 4) % 8;
		for (t = 0; t < dy; t++) {
			if (((t + 1) * dx) / dy > num_shifts) {
				num_shifts++;// = (t * dx) / dy;
				next_loc = cur_loc;
				next_loc.x += shift_dir.x;
				//next_loc.y += shift_dir.y;
				if (look_block(cur_loc,x_dir) == TRUE) 
					*see_to = FALSE;
				if (look_block(next_loc,x_back_dir) == TRUE)
					*see_in = FALSE;
				if ((check_travel == TRUE) &&
					(move_block(cur_loc,x_dir) == TRUE))
					*see_to = FALSE;
				if ((check_travel == TRUE) &&
					(move_block(next_loc,x_back_dir) == TRUE))
					*see_in = FALSE;
				cur_loc = next_loc;
			}
			//else {
			next_loc = cur_loc;
			next_loc.y += shift_dir.y;
			if (look_block(cur_loc,y_dir) == TRUE) 
				*see_to = FALSE;
			if (look_block(next_loc,y_back_dir) == TRUE)
				*see_in = FALSE;
			if ((check_travel == TRUE) &&
				(move_block(cur_loc,y_dir) == TRUE))
				*see_to = FALSE;
			if ((check_travel == TRUE) &&
				(move_block(next_loc,y_back_dir) == TRUE))
				*see_in = FALSE;
			cur_loc = next_loc;
			//	}
			
			if (same_point(cur_loc,p2)) {
				if (*see_to == FALSE)
					*see_in = FALSE;
				t = 10000;
			}
			else if ((*see_in == FALSE) || (*see_to == FALSE)) {
				*see_in = *see_to = FALSE;
				t = 10000;
			}
		}
	}
}

Boolean can_see_to(location p1,location p2,short check_light,short check_travel)
{
	bool a,b;
	
	can_see(p1,p2,check_light,check_travel,&a,&b);
	return a;
}

Boolean can_see_in(location p1,location p2,short check_light,short check_travel)
{
	bool a,b;
	
	can_see(p1,p2,check_light,check_travel,&a,&b);
	return b;
}

// returns TRUE if you can see p2 from p1
// check_light - returns FALSE if p2 is in darkness
// check travel - returns FALSE if path is obstructed by, say, water or a wall w. window
void can_see(location p1,location p2,short check_light,short check_travel,bool *see_to,bool *see_in)
{
	short t;
	short dx,dy;
	short x_dir = 2,y_dir = 0,x_back_dir = 6,y_back_dir = 4,num_shifts = 0;
	// dirs 0 - n 1 - nw 2 - w and so on to 7 - ne
	location shift_dir = {0,0},empty_loc = {0,0};
	location cur_loc,next_loc;
	
	*see_to = TRUE;
	*see_in = TRUE;
	if (same_point(p1,p2))
		return;
	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	shift_dir.x = (p2.x > p1.x) ? 1 : -1;
	shift_dir.y = (p2.y > p1.y) ? 1 : -1;
	if (p2.x > p1.x) {
		x_dir = 6; x_back_dir = 2;
	}
	if (p2.y > p1.y) {
		y_dir = 4; y_back_dir = 0;
	}
	cur_loc = p1;
	
	if (dx >= dy) {
		y_dir = locs_to_dir(empty_loc,shift_dir);
		y_back_dir = (y_dir + 4) % 8;
		//if ((p1.x - p2.x == 1) && (p1.y - p2.y == 1))
		//	print_nums(99,y_dir,y_back_dir);
		for (t = 0; t < dx; t++) {
			next_loc = cur_loc;
			if (((t + 1) * dy) / dx > num_shifts) {
				num_shifts++;// = (t * dy) / dx;
							 //next_loc.x += shift_dir.x;
				next_loc.y += shift_dir.y;
			}
			//else {
			next_loc.x += shift_dir.x;
			//	}
			
			if(can_see_single(cur_loc,next_loc,check_light,check_travel,see_to) == FALSE) {
				*see_in = FALSE;
				*see_to &= (t + 1 >= dx);
				return;
			}
			cur_loc = next_loc;
		}
		return;
	}
	num_shifts = 0;
	if (dy > dx) {
		x_dir = locs_to_dir(empty_loc,shift_dir);
		x_back_dir = (x_dir + 4) % 8;
		for (t = 0; t < dy; t++) {
			next_loc = cur_loc;
			if (((t + 1) * dx) / dy > num_shifts) {
				num_shifts++;// = (t * dx) / dy;
				next_loc.x += shift_dir.x;
				//next_loc.y += shift_dir.y;
			}
			//else {
			next_loc.y += shift_dir.y;
			//	}
			if(can_see_single(cur_loc,next_loc,check_light,check_travel,see_to) == FALSE) {
				*see_in = FALSE;
				*see_to &= (t + 1 >= dy);
				return;
			}
			cur_loc = next_loc;
		}
		return;
	}
}

bool can_see_single(location p1,location p2,short check_light,short check_travel,bool *see_to)
{
	
	location shift_dir = {0,0},shift_dir_x = {0,0},shift_dir_y = {0,0},empty_loc = {0,0};
	location test_loc_x_y_forwards, test_loc_y_x_forwards;
	short x_dir, y_dir, x_back_dir, y_back_dir;
	if(p1.x != p2.x) {
		shift_dir_x.x = shift_dir.x = (p2.x > p1.x) ? 1 : -1;
	}
	if(p1.y != p2.y) {
		shift_dir_y.y = shift_dir.y = (p2.y > p1.y) ? 1 : -1;
	}
	
	x_dir = locs_to_dir(empty_loc,shift_dir_x);
	y_dir = locs_to_dir(empty_loc,shift_dir_y);
	x_back_dir = (x_dir + 4) % 8;
	y_back_dir = (y_dir + 4) % 8;
	
	if(p1.x != p2.x && p1.y != p2.y) {
		Boolean x_no_block00 = FALSE;
		Boolean x_no_block01 = FALSE;
		Boolean x_no_block10 = FALSE;
		Boolean x_no_block11 = FALSE;
		Boolean y_no_block00 = FALSE;
		Boolean y_no_block01 = FALSE;
		Boolean y_no_block10 = FALSE;
		Boolean y_no_block11 = FALSE;
		
		test_loc_x_y_forwards = test_loc_y_x_forwards = p1;
		test_loc_x_y_forwards.x += shift_dir.x;
		test_loc_y_x_forwards.y += shift_dir.y;
		
		// [          0,0:p1         ] [1,0:test_loc_x_y_forwards]
		// [0,1:test_loc_y_x_forwards] [          1,1:p2         ]
		//
		// of course, this is just an example.  it can be in any orientation
		
		Boolean corner2 = FALSE;
		
		if(shift_dir.x == 1 && shift_dir.y == 1) {
			if(get_se_corner(0,0,p1.x,p1.y)) {
				*see_to = FALSE;
				return FALSE;
			}
			else if(get_nw_corner(0,0,p2.x,p2.y)) {
				corner2 = TRUE;
			}
		}
		else if(shift_dir.x == -1 && shift_dir.y == 1) {
			if(get_sw_corner(0,0,p1.x,p1.y)) {
				*see_to = FALSE;
				return FALSE;
			}
			else if(get_ne_corner(0,0,p2.x,p2.y)) {
				corner2 = TRUE;
			}
		}
		else if(shift_dir.x == -1 && shift_dir.y == -1) {
			if(get_nw_corner(0,0,p1.x,p1.y)) {
				*see_to = FALSE;
				return FALSE;
			}
			else if(get_se_corner(0,0,p2.x,p2.y)) {
				corner2 = TRUE;
			}
		}
		else if(shift_dir.x == 1 && shift_dir.y == -1) {
			if(get_ne_corner(0,0,p1.x,p1.y)) {
				*see_to = FALSE;
				return FALSE;
			}
			else if(get_sw_corner(0,0,p2.x,p2.y)) {
				corner2 = TRUE;
			}
		}
		if(corner2 == FALSE) {
			x_no_block00 = no_block(p1,x_dir,check_light,check_travel);
			x_no_block10 = no_block(test_loc_x_y_forwards,x_back_dir,check_light,check_travel);
			y_no_block10 = no_block(test_loc_x_y_forwards,y_dir,check_light,check_travel);
			y_no_block11 = no_block(p2,y_back_dir,check_light,check_travel);
			
			if (x_no_block00 && x_no_block10 && y_no_block10 && y_no_block11) 
				return TRUE;
			
			y_no_block00 = no_block(p1,y_dir,check_light,check_travel);
			y_no_block01 = no_block(test_loc_y_x_forwards,y_back_dir,check_light,check_travel);
			x_no_block01 = no_block(test_loc_y_x_forwards,x_dir,check_light,check_travel);
			x_no_block11 = no_block(p2,x_back_dir,check_light,check_travel);
			
			if (y_no_block00 && y_no_block01 && x_no_block01 && x_no_block11) 
				return TRUE;
			
			//deal with BoA's strangeness
			if ((x_no_block00 && y_no_block00 && x_no_block11 && y_no_block11)
				&& (x_no_block10 || y_no_block01) && (x_no_block01 || y_no_block10))
				return TRUE;
			
			//deal with more of BoA's strangeness - sort of symmetric to the previous 'if'
			if ((x_no_block10 && y_no_block10 && x_no_block01 && y_no_block01) && (x_no_block11 || y_no_block11)
				&& (x_no_block00 || y_no_block00))
				return TRUE;
		}
		
		//ok, at this point, we know we can't see in
		
		//!_ around goal has already been checked for
		
		//I don't understand what's wrong with this, but without it, everything works,
		//and with it, sometimes little corner walls aren't displayed in strange (but not unusual) circumstances
		/*
			//L on start
		 if(!x_no_block00 && !y_no_block00)
		 *see_to = FALSE;
		 
		 //|_ on start and neighbor
		 if((!x_no_block00 && !y_no_block01) || (!y_no_block00 && !x_no_block10))
		 *see_to = FALSE;*/
		
		//__ on start and neighbor
		if((!x_no_block00 && !x_no_block01) || (!y_no_block00 && !y_no_block10))
			*see_to = FALSE;
		
		/*
			*see_to = FALSE;
		 
		 if (
			 x_no_block00 && x_no_block10 &&
			 y_no_block10
			 ) *see_to = TRUE;
		 
		 if (
			 y_no_block00 && y_no_block01 &&
			 x_no_block01
			 ) *see_to = TRUE;
		 
		 //deal with BoA's strangeness
		 if (
			 (
			  x_no_block00 && y_no_block00
			  )
			 &&
			 (
			  x_no_block10 || y_no_block01
			  )
			 &&
			 (
			  x_no_block01 || y_no_block10
			  )
			 ) *see_to = TRUE;
		 
		 //deal with more of BoA's strangeness - sort of symmetric to the previous 'if'
		 if (
			 (
			  x_no_block10 && y_no_block10 &&
			  x_no_block01 && y_no_block01
			  )
			 &&
			 (
			  x_no_block00 || y_no_block00
			  )
			 ) *see_to = TRUE;*/
		
		return FALSE;
	}
	else if(p1.x != p2.x) {
		if(no_block(p1,x_dir,check_light,check_travel) && no_block(p2,x_back_dir,check_light,check_travel)) {
			return TRUE;
		}
		else {
			*see_to = no_block(p1,x_dir,check_light,check_travel);
			return FALSE;
		}
	}
	else if(p1.y != p2.y) {
		if(no_block(p1,y_dir,check_light,check_travel) && no_block(p2,y_back_dir,check_light,check_travel)) {
			return TRUE;
		}
		else {
			*see_to = no_block(p1,y_dir,check_light,check_travel);
			return FALSE;
		}
	}
	else {
		return TRUE;
	}
}

bool no_block(location l, short direction,short check_light,short check_travel)
{
	if(check_light)
		if(look_block(l,direction))
			return FALSE;
	if(check_travel)
		if(move_block(l,direction))
			return FALSE;
	return TRUE;
}

// direction 0 - n, 1 - nw, 2 - w, 3 - sw, ..., 7 - ne
/// hey, this should never get a diagonal, so ignore diag. values
bool look_block(location l, short direction)
{
	int lx = l.x;
	int ly = l.y;
	
	//short ter;
	//terrain_type_type t;
	
	//ter = (editing_town == FALSE) ? border_terrains[(l.x + 48) / 48][(l.y + 48) / 48].terrain[l.x - (((l.x + 48) / 48) * 48 - 48)][l.y - (((l.y + 48) / 48) * 48 - 48)] : t_d.terrain[l.x][l.y];
	//t = get_ter(ter);
	
	switch (direction) {
		case 0: return scen_data.scen_terrains[(editing_town == FALSE) ? ( ((unsigned char)l.x > 47) ? border_terrains[(lx + 48) / 48][(ly + 48) / 48].terrain[lx - (((lx + 48) / 48) * 48 - 48)][ly - (((ly + 48) / 48) * 48 - 48)] : current_terrain.terrain[lx][ly]) : t_d.terrain[lx][ly]].see_block[0] ; break;
		case 1: return ((look_block(l,0)) || (look_block(l,2))); break;
		case 2: return scen_data.scen_terrains[(editing_town == FALSE) ? ( ((unsigned char)l.x > 47) ? border_terrains[(lx + 48) / 48][(ly + 48) / 48].terrain[lx - (((lx + 48) / 48) * 48 - 48)][ly - (((ly + 48) / 48) * 48 - 48)] : current_terrain.terrain[lx][ly]) : t_d.terrain[lx][ly]].see_block[1] ; break;
		case 3: return ((look_block(l,2)) || (look_block(l,4))); break;
		case 4: return scen_data.scen_terrains[(editing_town == FALSE) ? ( ((unsigned char)l.x > 47) ? border_terrains[(lx + 48) / 48][(ly + 48) / 48].terrain[lx - (((lx + 48) / 48) * 48 - 48)][ly - (((ly + 48) / 48) * 48 - 48)] : current_terrain.terrain[lx][ly]) : t_d.terrain[lx][ly]].see_block[2] ; break;
		case 5: return ((look_block(l,4)) || (look_block(l,6))); break;
		case 6: return scen_data.scen_terrains[(editing_town == FALSE) ? ( ((unsigned char)l.x > 47) ? border_terrains[(lx + 48) / 48][(ly + 48) / 48].terrain[lx - (((lx + 48) / 48) * 48 - 48)][ly - (((ly + 48) / 48) * 48 - 48)] : current_terrain.terrain[lx][ly]) : t_d.terrain[lx][ly]].see_block[3] ; break;
		case 7: return ((look_block(l,6)) || (look_block(l,0))); break;
	}
	return TRUE;
}
// direction 0 - n, 1 - nw, 2 - w, 3 - sw, ..., 7 - ne
/// hey, this should never get a diagonal, so ignore diag. values
bool move_block(location l, short direction)
{
	short ter;
	terrain_type_type t;
	int lx = l.x;
	int ly = l.y;
	
	ter = (editing_town == FALSE) ? current_terrain.terrain[lx][ly] : t_d.terrain[lx][ly];
	t = get_ter(ter);
	
	switch (direction) {
		case 0: return t.move_block[0]; break;
		case 1: return ((move_block(l,0)) || (move_block(l,2))); break;
		case 2: return t.move_block[1]; break;
		case 3: return ((move_block(l,2)) || (move_block(l,4))); break;
		case 4: return t.move_block[2]; break;
		case 5: return ((move_block(l,4)) || (move_block(l,6))); break;
		case 6: return t.move_block[3]; break;
		case 7: return ((move_block(l,6)) || (move_block(l,0))); break;
	}
	return TRUE;
}

static temp_space_info_ptr corner_and_sight_map_at_loc(short sector_offset_x, short sector_offset_y, short x, short y);
//this must be fast
temp_space_info_ptr corner_and_sight_map_at_loc(short sector_offset_x, short sector_offset_y, short x, short y)
{
	if(editing_town) {
		x += ((sector_offset_x == 1) ? max_zone_dim[town_type] : ((sector_offset_x) ? -max_zone_dim[town_type] : 0)) + 12;
		y += ((sector_offset_y == 1) ? max_zone_dim[town_type] : ((sector_offset_y) ? -max_zone_dim[town_type] : 0)) + 12;
	}
	else {
		x += ((sector_offset_x == 1) ? 48 : ((sector_offset_x) ? -48 : 0)) + 20;
		y += ((sector_offset_y == 1) ? 48 : ((sector_offset_y) ? -48 : 0)) + 20;
	}
	if(x < 0 || x > 87 || y < 0 || y > 87)
		return NULL;
	return &corner_and_sight_map[x][y];
}

#if 0
Boolean get_see_in(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p;
	
	if(cur_viewing_mode != 11)
		return TRUE;
	
	p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	
	if(p == NULL)
		return FALSE;
	return p->see_in;
}

void set_see_in(short sector_offset_x, short sector_offset_y, short x, short y, Boolean value)
{
	temp_space_info_ptr p;
	
	if(cur_viewing_mode != 11)
		return;
	
	p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	
	if(p == NULL)
		return;
	p->see_in = value;
}

Boolean get_see_to(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p;
	
	if(cur_viewing_mode != 11)
		return TRUE;
	
	p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	
	if(p == NULL)
		return FALSE;
	return p->see_to;
}

void set_see_to(short sector_offset_x, short sector_offset_y, short x, short y, Boolean value)
{
	temp_space_info_ptr p;
	
	if(cur_viewing_mode != 11)
		return;
	
	p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	
	if(p == NULL)
		return;
	p->see_to = value;
}
#endif

short get_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return 0;
	
	return p->nw_corner;
}

void set_nw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return;
	p->nw_corner = value;
}

short get_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return 0;
	return p->sw_corner;
}

void set_sw_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return;
	p->sw_corner = value;
}

short get_se_corner(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return 0;
	return p->se_corner;
}

void set_se_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return;
	p->se_corner = value;
}

short get_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return 0;
	return p->ne_corner;
}

void set_ne_corner(short sector_offset_x, short sector_offset_y, short x, short y, short value)
{
	temp_space_info_ptr p = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
	if(p == NULL)
		return;
	p->ne_corner = value;
}

#if 0
void set_up_corner_and_sight_map()
{
	short nw_corner, ne_corner, se_corner, sw_corner;
	Boolean see_to, see_in;
	
	short sector_offset_x, sector_offset_y, x, y, temp_x, temp_y;
	location view_to, view_from;
	short view_tox, view_toy;
	
	outdoor_record_type *drawing_terrain = &current_terrain;
	
	view_from.x = cen_x;
	view_from.y = cen_y;
	
	Boolean see_in_neighbors[3][3] = {{TRUE,TRUE,TRUE},{TRUE,TRUE,TRUE},{TRUE,TRUE,TRUE}};
	Boolean see_to_neighbors[3][3] = {{TRUE,TRUE,TRUE},{TRUE,TRUE,TRUE},{TRUE,TRUE,TRUE}};
	
	short current_size = ((editing_town) ? max_zone_dim[town_type] : 48);
	
	temp_space_info_ptr temp_ptr;
	
	for(sector_offset_x = -1;sector_offset_x <= 1/*!editing_town*/;sector_offset_x++){
		for(sector_offset_y = -1;sector_offset_y <= 1/*!editing_town*/;sector_offset_y++){
			
			if(!editing_town) {
				//don't draw nonexistant sectors
				if(cur_out.x + sector_offset_x < 0 || cur_out.y + sector_offset_y < 0 || 
				   cur_out.x + sector_offset_x >= scenario.out_width || cur_out.y + sector_offset_y >= scenario.out_height)
					continue;
				if(sector_offset_x == 0 && sector_offset_y == 0)
					drawing_terrain = &current_terrain;
				else
					drawing_terrain = &border_terrains[sector_offset_x + 1][sector_offset_y + 1];
				//region number
				if(current_terrain.extra[0] != drawing_terrain->extra[0])
					continue;
			}
			
			for(x = 0; x < current_size; x++) {
				for(y = 0; y < current_size; y++) {
					temp_ptr = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
					if(temp_ptr == NULL)
						continue;
					if(cur_viewing_mode == 11) {
						temp_x = x;
						temp_y = y;
						if(editing_town) {
							if(sector_offset_x == -1) {
								temp_x = 0;
							}
							if(sector_offset_x == 1) {
								temp_x = current_size - 1;
							}
							if(sector_offset_y == -1) {
								temp_y = 0;
							}
							if(sector_offset_y == 1) {
								temp_y = current_size - 1;
							}
						}
						else {
							temp_x += sector_offset_x * current_size;
							temp_y += sector_offset_y * current_size;
						}
						
						//in the game, things a certain distance away aren't drawn.  Also, 
						//that helps here by reducing the number of line-of-sight calculations needed
						if(editing_town && (abs(temp_x - cen_x) > 10 || abs(temp_y - cen_y) > 10))
							continue;
						if(!editing_town && (abs(temp_x - cen_x) + abs(temp_y - cen_y) > 14))
							continue;
					}
					
					find_out_about_corner_walls(drawing_terrain,x,y,current_size,&nw_corner,&ne_corner,&se_corner,&sw_corner);
					
					temp_ptr->nw_corner = nw_corner;
					temp_ptr->sw_corner = sw_corner;
					temp_ptr->se_corner = se_corner;
					temp_ptr->ne_corner = ne_corner;
					//set_nw_corner(sector_offset_x,sector_offset_y,x,y,nw_corner);
					//set_sw_corner(sector_offset_x,sector_offset_y,x,y,sw_corner);
					//set_se_corner(sector_offset_x,sector_offset_y,x,y,se_corner);
					//set_ne_corner(sector_offset_x,sector_offset_y,x,y,ne_corner);
				}
			}
		}
	}
	
	if(cur_viewing_mode == 11) {		
		for(sector_offset_x = -1;sector_offset_x <= 1/*!editing_town*/;sector_offset_x++){
			for(sector_offset_y = -1;sector_offset_y <= 1/*!editing_town*/;sector_offset_y++){				
				if(!editing_town) {
					//don't draw nonexistant sectors
					if(cur_out.x + sector_offset_x < 0 || cur_out.y + sector_offset_y < 0 || 
					   cur_out.x + sector_offset_x >= scenario.out_width || cur_out.y + sector_offset_y >= scenario.out_height)
						continue;					
					if(sector_offset_x == 0 && sector_offset_y == 0)
						drawing_terrain = &current_terrain;
					else
						drawing_terrain = &border_terrains[sector_offset_x + 1][sector_offset_y + 1];
					//region number
					if(current_terrain.extra[0] != drawing_terrain->extra[0])
						continue;
				}
				for(x = 0; x < current_size; x++) {
					for(y = 0; y < current_size; y++) {
						temp_x = x;
						temp_y = y;
						if(editing_town) {
							if(sector_offset_x == -1) {
								temp_x = 0;
							}
							if(sector_offset_x == 1) {
								temp_x = current_size - 1;
							}
							if(sector_offset_y == -1) {
								temp_y = 0;
							}
							if(sector_offset_y == 1) {
								temp_y = current_size - 1;
							}
						}
						else {
							temp_x += sector_offset_x * current_size;
							temp_y += sector_offset_y * current_size;
						}
						//in the game, things a certain distance away aren't drawn.  Also, 
						//that helps here by reducing the number of line-of-sight calculations needed
						if(editing_town && (abs(temp_x - cen_x) > indoor_draw_distance || abs(temp_y - cen_y) > indoor_draw_distance))
							continue;
						if(!editing_town && (abs(temp_x - cen_x) + abs(temp_y - cen_y) > outdoor_draw_distance))
							continue;
						
						view_to.x = temp_x;
						view_to.y = temp_y;
						can_see(view_from, view_to, TRUE, FALSE,&see_to,&see_in);
						
						set_see_in(sector_offset_x,sector_offset_y,x,y,see_in);
						set_see_to(sector_offset_x,sector_offset_y,x,y,see_to);
					}
				}
			}
		}
	}
	
	for(sector_offset_x = -1;sector_offset_x <= 1;sector_offset_x++){
		for(sector_offset_y = -1;sector_offset_y <= 1;sector_offset_y++){
			
			if(!editing_town) {
				//don't draw nonexistant sectors
				if(cur_out.x + sector_offset_x < 0 || cur_out.y + sector_offset_y < 0 || 
				   cur_out.x + sector_offset_x >= scenario.out_width || cur_out.y + sector_offset_y >= scenario.out_height)
					continue;
				
				if(sector_offset_x == 0 && sector_offset_y == 0)
					drawing_terrain = &current_terrain;
				else
					drawing_terrain = &border_terrains[sector_offset_x + 1][sector_offset_y + 1];
				
				//region number
				if(current_terrain.extra[0] != drawing_terrain->extra[0])
					continue;
			}
			
			for(x = 0; x < current_size; x++) {
				for(y = 0; y < current_size; y++) {
					
					temp_ptr = corner_and_sight_map_at_loc(sector_offset_x,sector_offset_y,x,y);
					
					if(temp_ptr == NULL)
						continue;
					
					if(cur_viewing_mode == 11) {
						
						temp_x = x;
						temp_y = y;
						if(editing_town) {
							if(sector_offset_x == -1) {
								temp_x = 0;
							}
							if(sector_offset_x == 1) {
								temp_x = current_size - 1;
							}
							if(sector_offset_y == -1) {
								temp_y = 0;
							}
							if(sector_offset_y == 1) {
								temp_y = current_size - 1;
							}
						}
						else {
							temp_x += sector_offset_x * current_size;
							temp_y += sector_offset_y * current_size;
						}
						
						//in the game, things a certain distance away aren't drawn.  Also, 
						//that helps here by reducing the number of line-of-sight calculations needed
						if(editing_town && (abs(temp_x - cen_x) > indoor_draw_distance || abs(temp_y - cen_y) > indoor_draw_distance))
							continue;
						if(!editing_town && (abs(temp_x - cen_x) + abs(temp_y - cen_y) > outdoor_draw_distance))
							continue;
						
						for(view_tox = 0; view_tox < 3; view_tox++) {
							for(view_toy = 0; view_toy < 3; view_toy++) {
								see_in_neighbors[view_tox][view_toy] = get_see_in(sector_offset_x,sector_offset_y,x + view_tox - 1,y + view_toy - 1);
								see_to_neighbors[view_tox][view_toy] = get_see_to(sector_offset_x,sector_offset_y,x + view_tox - 1,y + view_toy - 1);
							}
						}
					}
					
					//nw_corner = get_nw_corner(sector_offset_x,sector_offset_y,x,y);
					//sw_corner = get_sw_corner(sector_offset_x,sector_offset_y,x,y);
					//se_corner = get_se_corner(sector_offset_x,sector_offset_y,x,y);
					//ne_corner = get_ne_corner(sector_offset_x,sector_offset_y,x,y);
					nw_corner = temp_ptr->nw_corner;
					sw_corner = temp_ptr->sw_corner;
					se_corner = temp_ptr->se_corner;
					ne_corner = temp_ptr->ne_corner;
					
					find_out_about_corner_walls_being_hidden(drawing_terrain,sector_offset_x,sector_offset_y,x,y,current_size,see_in_neighbors,see_to_neighbors,/*get_see_to(sector_offset_x,sector_offset_y,x,y),*/&nw_corner,&ne_corner,&se_corner,&sw_corner);
					
					temp_ptr->nw_corner = nw_corner;
					temp_ptr->sw_corner = sw_corner;
					temp_ptr->se_corner = se_corner;
					temp_ptr->ne_corner = ne_corner;
					//set_nw_corner(sector_offset_x,sector_offset_y,x,y,nw_corner);
					//set_sw_corner(sector_offset_x,sector_offset_y,x,y,sw_corner);
					//set_se_corner(sector_offset_x,sector_offset_y,x,y,se_corner);
					//set_ne_corner(sector_offset_x,sector_offset_y,x,y,ne_corner);
				}
			}
		}
	}
}

void find_out_about_corner_walls(outdoor_record_type *drawing_terrain, short x, short y, short current_size, short *nw_corner, short *ne_corner, short *se_corner, short *sw_corner)
{	
	short n_terrain = 0, w_terrain = 0, s_terrain = 0, e_terrain = 0;
	short n_terrain_position = 0, w_terrain_position = 0, s_terrain_position = 0, e_terrain_position = 0;//0 - non-relevantwall 1 - towards counterclockwise  2 - clockwise
		short /*n_terrain_wall_type = 0,*/ w_terrain_wall_type = 0, /*s_terrain_wall_type = 0,*/ e_terrain_wall_type = 0;//0 if non-relevantwall, 1 if wall type 1, 2 if wall type 2
			
			//initialize the variables to 0
			*nw_corner = *ne_corner = *sw_corner = *se_corner = 0;
			
			//get the terrains
			if(x > 0)
				w_terrain = (editing_town) ? t_d.terrain[x - 1][y] : drawing_terrain->terrain[x - 1][y];
			if(y > 0)
				n_terrain = (editing_town) ? t_d.terrain[x][y - 1] : drawing_terrain->terrain[x][y - 1];
			if(x + 1 < current_size)
				e_terrain = (editing_town) ? t_d.terrain[x + 1][y] : drawing_terrain->terrain[x + 1][y];
			if(y + 1 < current_size)
				s_terrain = (editing_town) ? t_d.terrain[x][y + 1] : drawing_terrain->terrain[x][y + 1];
			
			//only walls are relevant
			if( !(w_terrain >= 2 && w_terrain <= 73))
				w_terrain = 0;
			if( !(n_terrain >= 2 && n_terrain <= 73))
				n_terrain = 0;
			if( !(e_terrain >= 2 && e_terrain <= 73))
				e_terrain = 0;
			if( !(s_terrain >= 2 && s_terrain <= 73))
				s_terrain = 0;
			
			//find out what kind of relevance the wall has, if any
			if(n_terrain != 0)
				n_terrain_position = (n_terrain % 4 == 3 || n_terrain == 6 || n_terrain == 42) ? 1 : ((n_terrain % 4 == 1 || n_terrain == 8 || n_terrain == 44) ? 2 : 0);
			if(w_terrain != 0)
				w_terrain_position = (w_terrain % 4 == 0 || w_terrain == 7 || w_terrain == 43) ? 1 : ((w_terrain % 4 == 2 || w_terrain == 9 || w_terrain == 45) ? 2 : 0);
			if(s_terrain != 0)
				s_terrain_position = (s_terrain % 4 == 1 || s_terrain == 8 || s_terrain == 44) ? 1 : ((s_terrain % 4 == 3 || s_terrain == 6 || s_terrain == 42) ? 2 : 0);
			if(e_terrain != 0)
				e_terrain_position = (e_terrain % 4 == 2 || e_terrain == 9 || e_terrain == 45) ? 1 : ((e_terrain % 4 == 0 || e_terrain == 7 || e_terrain == 43) ? 2 : 0);
			
			//preliminary to finding out the wall types of the possible corner walls.
			//two of them have no effect, so don't bother with them.
			//if(n_terrain_position != 0)
			//  n_terrain_wall_type = (n_terrain < 38) ? 1 : 2;
			if(w_terrain_position != 0)
				w_terrain_wall_type = (w_terrain < 38) ? 1 : 2;
			//if(s_terrain_position != 0)
			//  s_terrain_wall_type = (s_terrain < 38) ? 1 : 2;
			if(e_terrain_position != 0)
				e_terrain_wall_type = (e_terrain < 38) ? 1 : 2;
			
			//actually find out which ones exist (and with which wall type).
			//check if the walls are in the right place that there should be a corner wall
			if(n_terrain_position == 1 && w_terrain_position == 2)
				*nw_corner = w_terrain_wall_type;
			if(w_terrain_position == 1 && s_terrain_position == 2)
				*sw_corner = w_terrain_wall_type;
			if(s_terrain_position == 1 && e_terrain_position == 2)
				*se_corner = e_terrain_wall_type;
			if(e_terrain_position == 1 && n_terrain_position == 2)
				*ne_corner = e_terrain_wall_type;
}

void find_out_about_corner_walls_being_hidden(outdoor_record_type *drawing_terrain, short sector_offset_x, short sector_offset_y, short x, short y, short current_size, Boolean see_in_neighbors[3][3], Boolean see_to_neighbors[3][3], /*Boolean see_to, */short *nw_corner, short *ne_corner, short *se_corner, short *sw_corner)
{
	Boolean nw_disrupted = FALSE, sw_disrupted = FALSE, se_disrupted = FALSE, ne_disrupted = FALSE;
	Boolean see_a_nw_wall = FALSE, see_a_sw_wall = FALSE, see_a_se_wall = FALSE, see_a_ne_wall = FALSE;
	short center_terrain = 0;
	
	//get the terrain
	center_terrain = (editing_town) ? t_d.terrain[x][y] : drawing_terrain->terrain[x][y];
	
	//only walls are relevant
	if( !(center_terrain >= 2 && center_terrain <= 73))
		center_terrain = 0;
	
	//if there's a wall in the same place a corner wall would be, there shouldn't be a corner wall.
	//this only applies when the interfering wall is visible, though.
	if(*nw_corner && center_terrain != 0)
		nw_disrupted = (
						(center_terrain % 4 == 3 || center_terrain == 6 || center_terrain == 42)
						&&
						(see_in_neighbors[0][1] || see_in_neighbors[1][1])
						)
			||
			(
			 (center_terrain % 4 == 2 || center_terrain == 9 || center_terrain == 45)
			 &&
			 (see_in_neighbors[1][0] || see_in_neighbors[1][1])
			 );
	if(*ne_corner && center_terrain != 0)
		ne_disrupted = (
						(center_terrain % 4 == 2 || center_terrain == 9 || center_terrain == 45)
						&&
						(see_in_neighbors[1][0] || see_in_neighbors[1][1])
						)
			||
			(
			 (center_terrain % 4 == 1 || center_terrain == 8 || center_terrain == 44)
			 &&
			 (see_in_neighbors[2][1] || see_in_neighbors[1][1])
			 );
	if(*se_corner && center_terrain != 0)
		se_disrupted = (
						(center_terrain % 4 == 1 || center_terrain == 8 || center_terrain == 44)
						&&
						(see_in_neighbors[2][1] || see_in_neighbors[1][1])
						)
			||
			(
			 (center_terrain % 4 == 0 || center_terrain == 7 || center_terrain == 43)
			 &&
			 (see_in_neighbors[1][2] || see_in_neighbors[1][1])
			 );
	if(*sw_corner && center_terrain != 0)
		sw_disrupted = (
						(center_terrain % 4 == 0 || center_terrain == 7 || center_terrain == 43)
						&&
						(see_in_neighbors[1][2] || see_in_neighbors[1][1])
						)
			||
			(
			 (center_terrain % 4 == 3 || center_terrain == 6 || center_terrain == 42)
			 &&
			 (see_in_neighbors[0][1] || see_in_neighbors[1][1])
			 );
	
	if(*nw_corner)
		see_a_nw_wall = ((cen_x < x && cen_y < y) ? (
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x - 1,y) &&
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y - 1)
													 ) : (
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x - 1,y) ||
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y - 1)
														  ));
	if(*sw_corner)
		see_a_sw_wall = ((cen_x < x && cen_y > y) ? (
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x - 1,y) &&
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y + 1)
													 ) : (
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x - 1,y) ||
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y + 1)
														  ));
	if(*se_corner)
		see_a_se_wall = ((cen_x > x && cen_y > y) ? (
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x + 1,y) &&
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y + 1)
													 ) : (
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x + 1,y) ||
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y + 1)
														  ));
	if(*ne_corner)
		see_a_ne_wall = ((cen_x > x && cen_y < y) ? (
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x + 1,y) &&
													 is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y - 1)
													 ) : (
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x + 1,y) ||
														  is_wall_drawn(drawing_terrain,sector_offset_x,sector_offset_y,x,y - 1)
														  ));
	
	
	//actually find out which ones should be drawn.
	//check that there isn't already a wall that would be displayed where the corner wall would be,
	//and that you can actually see the corner
	if(*nw_corner && (nw_disrupted || !see_a_nw_wall))
		*nw_corner = 3;
	if(*sw_corner && (sw_disrupted || !see_a_sw_wall))
		*sw_corner = 3;
	if(*se_corner && (se_disrupted || !see_a_se_wall))
		*se_corner = 3;
	if(*ne_corner && (ne_disrupted || !see_a_ne_wall))
		*ne_corner = 3;
	/*if(*nw_corner && (nw_disrupted || !((see_in_neighbors[0][0] && see_to && cen_x < x && cen_y < y) || see_in_neighbors[1][1])))
		*nw_corner = 3;
	if(*sw_corner && (sw_disrupted || !((see_in_neighbors[0][2] && see_to && cen_x < x && cen_y > y) || see_in_neighbors[1][1])))
		*sw_corner = 3;
	if(*se_corner && (se_disrupted || !((see_in_neighbors[2][2] && see_to && cen_x > x && cen_y > y) || see_in_neighbors[1][1])))
		*se_corner = 3;
	if(*ne_corner && (ne_disrupted || !((see_in_neighbors[2][0] && see_to && cen_x > x && cen_y < y) || see_in_neighbors[1][1])))
		*ne_corner = 3;*/
}

Boolean is_wall_drawn(outdoor_record_type *drawing_terrain, short sector_offset_x, short sector_offset_y, short x, short y)
{
	//get the terrain
	short wall_terrain = (editing_town) ? t_d.terrain[x][y] : drawing_terrain->terrain[x][y];
	
	//only walls are relevant
	if( !(wall_terrain >= 2 && wall_terrain <= 73))
		return FALSE;
	
	if(get_see_in(sector_offset_x,sector_offset_y,x,y))
		return TRUE;
	if(!get_see_to(sector_offset_x,sector_offset_y,x,y))
		return FALSE;
	
	return (
			(scen_data.scen_terrains[wall_terrain].see_block[0] == 1 && get_see_in(sector_offset_x,sector_offset_y,x,y - 1) == TRUE) ||
			(scen_data.scen_terrains[wall_terrain].see_block[1] == 1 && get_see_in(sector_offset_x,sector_offset_y,x - 1,y) == TRUE) ||
			(scen_data.scen_terrains[wall_terrain].see_block[2] == 1 && get_see_in(sector_offset_x,sector_offset_y,x,y + 1) == TRUE) ||
			(scen_data.scen_terrains[wall_terrain].see_block[3] == 1 && get_see_in(sector_offset_x,sector_offset_y,x + 1,y) == TRUE)
			);
}

// "Outdoor: drawing mode failure after moving section" fix
// returns TRUE if outdoor section change is cancelled by user
Boolean clean_up_from_scrolling( int map_size, short dx, short dy )
{
	int sector_x_overflow = 0;
	int sector_y_overflow = 0;
	char sector_offset_x = 0;
	char sector_offset_y = 0;
	
	short cen_x_save = cen_x;
	short cen_y_save = cen_y;
	
	cen_x += dx;
	cen_y += dy;
	
	sector_x_overflow = cen_x % map_size;
	if(cen_x < 0) {
		sector_offset_x = -1;
		sector_x_overflow += map_size;
	}
	else if(cen_x >= map_size) {
		sector_offset_x = 1;
	}
	
	sector_y_overflow = cen_y % map_size;
	if(cen_y < 0) {
		sector_offset_y = -1;
		sector_y_overflow += map_size;
	}
	else if(cen_y >= map_size) {
		sector_offset_y = 1;
	}
	
	// limit center position
	cen_x = minmax( 0, map_size - 1, cen_x );
	cen_y = minmax( 0, map_size - 1, cen_y );
	
	if( !editing_town && ((sector_offset_x != 0) || (sector_offset_y != 0)) ) {
		// change outdoor sector
		location aSpot_hit = {cur_out.x + sector_offset_x,cur_out.y + sector_offset_y};
		
		if((aSpot_hit.x < 0) || (aSpot_hit.y < 0)
		   || (aSpot_hit.x >= scenario.out_width)
		   || (aSpot_hit.y >= scenario.out_height))
			return FALSE;
		
		if (change_made_outdoors == TRUE) {
			scroll_dialog_lock = TRUE;
			if ( save_check(990) == FALSE ) {	// canceled
				cen_x = cen_x_save;				// recover center position
				cen_y = cen_y_save;
				scroll_dialog_lock = FALSE;
				return TRUE;
			}
			scroll_dialog_lock = FALSE;
		}
		
		clear_selected_copied_objects();
		//load_outdoors(spot_hit,0);
		augment_terrain(aSpot_hit);
		set_up_terrain_buttons();
		cen_x = (short)sector_x_overflow;
		cen_y = (short)sector_y_overflow;
		//		reset_drawing_mode();
		check_selected_item_number();		// maybe need?
		if (current_drawing_mode == 0)
			set_new_floor(current_floor_drawn);
		else
			set_new_terrain(current_terrain_drawn);
		update_terrain_window_title();
		redraw_screen();
		change_made_outdoors = FALSE;
	}
	return FALSE;
}

//undo system functions

void updateUndoMenu(){
	CFStringRef temp=CFStringCreateWithCString(kCFAllocatorDefault, ("Undo "+undo.currentDescription()).c_str(), kCFStringEncodingASCII);
	SetMenuItemTextWithCFString(GetMenuHandle(570), 1, temp);
	CFRelease(temp);
	temp=CFStringCreateWithCString(kCFAllocatorDefault, ("Redo "+redo.currentDescription()).c_str(), kCFStringEncodingASCII);
	SetMenuItemTextWithCFString(GetMenuHandle(570), 2, temp);
	CFRelease(temp);
}

//Adds an undo step to the history
//s should have been allocated with operator new; 
//the undo system assumes responsibility for deleting it
void pushUndoStep(Undo::UndoStep* s){
	undo.appendChange(s);
	purgeRedo();
	updateUndoMenu();
}

//should be called every time a new zone is loaded
//Otherwise the user could still undo changes made in other zones, but they would be undone 
//in the _current_ zone, which would make a mess and serve no purpose. Therefore existing undo steps
//must be invalidated and removed by calling this function when the zone is switched.
void purgeUndo(){
	undo.clear();
	updateUndoMenu();
}

//This is the actual undo operation that should be called when the user wants to undo editing changes
void performUndo(){
	try{
		if(!undo.applyLast(redo)){
			beep();
			return;
		}
	} catch(std::exception& ex){
		give_error(ex.what(),"It may be a good idea to exit the program immediately.",0);
	}
	updateUndoMenu();
	redraw_screen();
}

//should be called every time a new zone is loaded _and_ every time the user executes an editing operation
//redo steps need to be invalidated for the same reason as undo steps when the zone is switched, 
//but should also be invalidated whenever the user makes a new editing change. For example, suppose
//the user opens a file, places a tree, and then undoes the drawing operation. At this point there 
//will be no undo steps, and one redo step to redraw the tree. Suppose the user then places a wall on the 
//same spot. Then, if the redo steps are not purged, there will be one undo step, to remove the wall again, 
//and the redo step to re-place the tree will still remain. If the user then selects Redo, the wall will be 
//replaced with the tree, which makes no sense. Instead, as soon as the wall is added, the redo steps should
//be purged to eliminate nonsensical redo operations. However, if the user undoes one or more operations 
//without doing anything else, the redo steps must not be purged, in order to allow the user to move freely
//back and forth through the recorded states. 
void purgeRedo(){
	redo.clear();
	updateUndoMenu();
}

//This is the actual redo operation that should be called when the user wants to redo editing changes that were undone
void performRedo(){
	try{
		if(!redo.applyLast(undo)){
			beep();
			return;
		}
	} catch(std::exception& ex){
		give_error(ex.what(),"It may be a good idea to exit the program immediately.",0);
	}
	updateUndoMenu();
	redraw_screen();
}

#endif
