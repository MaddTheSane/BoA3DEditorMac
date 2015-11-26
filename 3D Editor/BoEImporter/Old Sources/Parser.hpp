//
//  Parser.hpp
//  3D BoA Editor
//
//  Created by C.W. Betts on 11/25/15.
//
//

#ifndef Parser_hpp
#define Parser_hpp

#include "ImporterGlobal.h"

bool load_core_scenario_data();

/// a block of text, loaded in from a file.
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

/// Stores a loaded script, in tokenized form.
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

#endif /* Parser_hpp */
