#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha{
    int scope_array[1000];
    int last_element;
    int* nested_scopes;
}pilha;

void init_stack(pilha* p);
void push(pilha* p, int scope_id, int* list);
int pop(pilha* p);
void print_stack(pilha* p);
int get_stack_top(pilha* p);
int get_stack_size(pilha* p);


int* push_auxiliary_scope_list(int scope, int* list);
int* init_aux_list(int* list);
void empty_aux_list(int* list);
void print_aux_list(int* list);

#endif