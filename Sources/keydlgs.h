//
//  keydlgs.h
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/28/15.
//
//

#ifndef keydlgs_h
#define keydlgs_h

#include <Carbon/Carbon.h>
#include "global.h"

void fancy_choice_dialog_event_filter (short item_hit);
short fancy_choice_dialog(short which_dlog,short parent);
Boolean cre(short val,short min,short max, const char *text1, const char *text2,short parent_num) ;
void give_error(const char *text1, const char *text2,short parent_num);
void display_strings_event_filter (short item_hit);
void display_strings(const char *text1,const char *text2,const char *title,short sound_num,short graphic_num,short parent_num);
void choose_text_res_event_filter (short item_hit);
void put_text_res();
short choose_text_res(short res_list,short first_t,short last_t,short cur_choice,short parent_num,const char *title);
void edit_special_num_event_filter (short item_hit);
short edit_special_num(short mode,short what_start);
void how_many_dlog_event_filter (short item_hit);
short how_many_dlog(short what_start,short minimum,short maximum,const char *what_text);
void get_str_dlog_event_filter (short item_hit);
void get_str_dlog(char *start_str,const char *header_str,char *response,Boolean string_string = FALSE);
void make_cursor_sword() ;
void set_cursor(short which_c) ;
void restore_cursor();
short choice_dialog(short pic,short num);
Boolean string_not_clean(char *str,short max_length,short strict_file_naming,const char *beginning_of_error,short parent_num);

#endif /* keydlgs_h */
