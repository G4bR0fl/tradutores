#ifndef ARVORE
#define ARVORE

#include "tabela.h"

typedef struct Tree tree;


struct Tree {
    symbol* symbol;
    struct List* children;
};

typedef struct List {
    struct Tree* node1;
    struct Tree* node2;
    struct Tree* node3;
    struct Tree* node4;
    struct Tree* node5;
}element;


tree* create_node();
tree* create_leaf();

#endif