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

short current_terrain_type = 0;
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

/// return true if the indicated space is a container, taking into account barrels and crates
static bool is_container(short x, short y){
	return((scen_data.scen_terrains[t_d.terrain[x][y]].special==40) || is_crate(x,y) || is_barrel(x,y));
}

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

// if i_to_make is not null, copies all of the info from this structure
// returns TRUE is tried to place in an impossible spot, or item was placed
// returns false is item not palced because too many
bool create_new_item(short item_to_create,location create_loc,Boolean property,item_type *i_to_make)
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

bool create_new_ter_script(const char *ter_script_name,location create_loc,in_town_on_ter_script_type *script_to_make)
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
	give_error("You can only have 100 active terrain scripts in a zone. No terrain script has been created.","",0);
	return FALSE;
}

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
