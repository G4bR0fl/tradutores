#ifndef ARVORE
#define ARVORE

typedef struct Tree {
    struct Tree* adj_node;
    struct Tree* next_node;
    int id_or_cte;
    Symbol* symbol; 
} tree;

#endif