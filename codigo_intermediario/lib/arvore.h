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
    int is_function;
    char type[100];
    // Tac functionalities
    int is_symbol; // Checks if is a symbol or not
    char tac_symbol[10000]; // writes symbol table entries
    int is_const; // checks if something is an ID
    char tac_const[1000]; // writes ID
    char tac_code[10000]; // writes TAC code
    int tac_reg; // Receives the counter from bison
    int is_expression; // Checks if something is a complex expression
    
};

tree* create_node(char* type_name);
void free_node(tree* main_node);
void free_adj_node(tree* main_node);
void print_tree(tree* main_node, int depth);
void search_undeclared_node(tree* main_node, symbol* table, pilha* stack);
void assign_types(tree* node, symbol* table, pilha* stack);
void assign_return(tree* node);

#endif