#ifndef ARVORE
#define ARVORE

#include "tabela.h"
#include "pilha.h"

typedef struct Tree tree;

struct Tree {
    char type_name[1000];
    struct Tree* node1;
    struct Tree* node2;
    struct Tree* node3;
    struct Tree* node4;
    struct Tree* node5;
    int var_scope;
    int column;
    int line;
};

tree* create_node(char* type_name);
void free_node(tree* main_node);
void free_adj_node(tree* main_node);
void print_tree(tree* main_node, int depth);
void search_undeclared_node(tree* main_node, symbol* table, int depth, pilha* stack);

#endif