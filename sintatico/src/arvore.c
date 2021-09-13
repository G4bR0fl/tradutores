#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arvore.h"

tree* create_node(){
    tree* node = (tree*)malloc(sizeof(tree));
    node->children = (element*)malloc(sizeof(element));
    node->symbol = NULL;
    node->children->node1 = NULL;
    node->children->node2 = NULL;
    node->children->node3 = NULL;
    node->children->node4 = NULL;
    node->children->node5 = NULL;
    
    return node;
}

// To do