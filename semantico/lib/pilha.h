#ifndef _PILHA_H_
#define _PILHA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha{
    int scope_array[15];
    int last_element;
}pilha;

void init_stack(pilha* p);
void push(pilha* p, int scope_id);
int pop(pilha* p);
void print_stack(pilha* p);
int get_stack_top(pilha* p);


#endif