#ifndef ARVORE
#define ARVORE

#include "tabela.h"

typedef struct Tree tree;

struct Tree {
    symbol* symbol;
    char type_name[100000];
    struct Tree* node1;
    struct Tree* node2;
    struct Tree* node3;
    struct Tree* node4;
    struct Tree* node5;
};

tree* create_node(char* type_name);
void free_node(tree* main_node);
void free_adj_node(tree* main_node);
void print_tree(tree* main_node);
#endif