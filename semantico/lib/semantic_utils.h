#ifndef _SEMANTIC_UTILS_ 
#define _SEMANTIC_UTILS_
#include "../lib/arvore.h"
#include "../lib/pilha.h"
#include "../lib/tabela.h"

void search_return(tree* node, char* node_name, char* type);
void function_param_amount(symbol* s, int args_counted, char* name, int line, int column);

// Node Casting
void create_cast_node_left(tree* left_arg, tree* father_node, tree* right_arg, char* node_name);
void cast_node_right(tree* left_arg, tree* father_node, tree* right_arg, char* node_name);
void cast_nil(tree* left_arg, tree* right_arg);
void cast_nil_constructor(tree* left_arg, tree* father_node, tree* right_arg, char* node_name);
void cast_return(tree* father_node, tree* right_arg, char* node_name);

// Conditional functions
int type_comparer(tree* left_arg, tree* right_arg);
int input_output_comparer(tree* arg);
int assignment_comparer(tree* left_arg, tree* right_arg);
int verify_unary_operator(tree* left_arg);
int list_operation_comparer(tree* operation);

// Expression evaluators
void evaluate_arithmetic(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_mult_div(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_read_write(tree* father_node, tree* arg);
void evaluate_assignment(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_relational(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_logical(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_return(tree* father_node, tree* right_arg, char* return_type);
void evaluate_unary(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_list_exp(tree* left_arg, tree* father_node, tree* right_arg, tree* operation);


enum TYPE_VERIFIER{
    DIFF_TYPE,
    SAME_TYPE,
    BINARY_OPERAND,
    HEADER_OPERAND,
    TAIL_OPERAND,
    NEGATION_OR_TAIL,
    MAP_OPERAND,
    FILTER_OPERAND,
    CONSTRUCTOR_OPERAND,
};


#endif