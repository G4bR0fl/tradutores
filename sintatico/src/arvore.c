#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arvore.h"

tree* create_node(char* name){
    tree* node = (tree*)malloc(sizeof(tree));
    strcpy(node->rule_name, name);
    node->terminal_node = NULL;
    node->next_node = NULL;
    node->symbol = NULL;
    return node;
}

// To do