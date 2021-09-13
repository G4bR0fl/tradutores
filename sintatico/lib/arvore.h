#ifndef ARVORE
#define ARVORE

#include "tabela.h"

typedef struct Tree tree;

struct Tree {
    symbol* symbol;
    char rule_name[100];
    struct Tree* terminal_node;
    struct Tree* next_node;
};

tree* create_node();
tree* create_leaf();

#endif