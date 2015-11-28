//
//  dlogtool.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/27/15.
//
//

#ifndef dlogtool_h
#define dlogtool_h

#include <Carbon/Carbon.h>
#include "global.h"

// dlogtool
void cd_init_dialogs();
short cd_create_dialog_parent_num(short dlog_num,short parent);
void cd_set_edit_focus();
short cd_kill_dialog(short dlog_num,short parent_message);
short cd_process_click(WindowPtr window,Point the_point, short mods,short *item);
short cd_process_keystroke(WindowPtr window,char char_hit,short *item);
void cd_init_button(short dlog_num,short item_num, short button_num, short status);
void cd_attach_key(short dlog_num,short item_num,char key);
void cd_set_pict(short dlog_num, short item_num, short pict_num);
void cd_activate_item(short dlog_num, short item_num, short status);
short cd_get_active(short dlog_num, short item_num);
void cd_get_item_text(short dlog_num, short item_num, char *str);
void cd_retrieve_text_edit_str(short dlog_num,short item_num, char *str);
void cd_set_text_edit_str(short dlog_num, short item_num, const char *str);
void cd_set_item_text(short dlog_num, short item_num, const char *str);
void cd_set_item_num(short dlog_num, short item_num, short num);
void cd_set_led(short dlog_num,short item_num,short state);
void cd_set_flag(short dlog_num,short item_num,short flag);
short cd_get_led(short dlog_num,short item_num);
void cd_text_frame(short dlog_num,short item_num,short frame);
void cd_add_label(short dlog_num, short item_num, char *label, short label_flag);
void cd_take_label(short dlog_num, short item_num);
void cd_key_label(short dlog_num, short item_num,short loc);
void cd_draw_item(short dlog_num,short item_num);
void cd_initial_draw(short dlog_num);
void cd_draw(short dlog_num);
void cd_redraw(WindowPtr window);
void cd_erase_rect(short dlog_num,Rect to_fry);
// void cd_press_button(short dlog_num, short item_num);
void center_window(WindowPtr window);
void draw_dialog_graphic(GrafPtr hDlg, Rect rect, short which_g, Boolean do_frame,short win_or_gworld);
Rect calc_rect(short i, short j);
void beep();
void cd_hit_led_range(short dlog_num,short first_led,short last_led,short which_to_set);
short cd_get_led_range(short dlog_num,short first_led,short last_led);
void cd_set_led_range(short dlog_num,short first_led,short last_led,short which_to_set);
void cd_set_text_edit_num(short dlog_num, short item_num, short num);
void cd_flip_led(short dlog_num,short item_num,short item_hit);
short cd_retrieve_text_edit_num(short dlog_num, short item_num);
Rect calc_from_rect(short i, short j);
Rect get_graphic_rect(GWorldPtr graf);

#endif /* dlogtool_h */
