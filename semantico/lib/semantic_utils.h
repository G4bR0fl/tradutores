#ifndef _SEMANTIC_UTILS_ 
#define _SEMANTIC_UTILS_
#include "../lib/arvore.h"
#include "../lib/pilha.h"
#include "../lib/tabela.h"

int function_param_amount(tree* node, symbol* s, int depth, int* pointer);
tree* search_node(tree* node, char* node_name); // Useless
#endif