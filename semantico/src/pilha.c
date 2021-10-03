#include "../lib/pilha.h"

pilha scope_stack;

void init_stack(pilha* p){
    p->scope_array[0] = 0;
    for(int i = 1; i < 1000; i++){
        p->scope_array[i] = -1;
    }
}

void push(pilha* p, int scope_id){
    p->last_element++;
    p->scope_array[p->last_element] = scope_id;
    return;
}

int pop(pilha* p){
    int element;
    element = p->scope_array[p->last_element]; 
    p->scope_array[p->last_element] = -1;
    if(p->last_element > 0){
        p->last_element--;
    }
    return element;
}

int get_stack_top(pilha* p){
    int element;
    element = p->scope_array[p->last_element]; 
    return element;
}

void print_stack(pilha* p){
    for(int i = 0; i < 1000; i++){
        printf("%d ", p->scope_array[i]);
    }
    printf("\n");
}