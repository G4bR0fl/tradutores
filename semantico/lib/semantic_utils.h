#ifndef _SEMANTIC_UTILS_ 
#define _SEMANTIC_UTILS_
#include "../lib/arvore.h"
#include "../lib/pilha.h"
#include "../lib/tabela.h"

int function_param_amount(tree* node, symbol* s, int depth, int* pointer);
int type_comparer(tree* left_arg, tree* right_arg);
void create_cast_node_left(tree* left_arg, tree* father_node, tree* right_arg, char* node_name);
void cast_node_right(tree* left_arg, tree* father_node, tree* right_arg, char* node_name);
void evaluate_arithmetic(tree* left_arg, tree* father_node, tree* right_arg);
void evaluate_mult_div(tree* left_arg, tree* father_node, tree* right_arg);

enum CAST{
    DIFF_TYPE,
    SAME_TYPE,
    INT_TO_FLOAT,
    FLOAT_TO_INT,
    ERROR,
};


#endif