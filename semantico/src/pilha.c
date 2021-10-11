#include "../lib/pilha.h"

pilha scope_stack;

void init_stack(pilha* p){
    p->scope_array[0] = 0;
    for(int i = 1; i < 1000; i++){
        p->scope_array[i] = -1;
    }
}

void push(pilha* p, int scope_id, int* list){
    p->last_element++;
    p->scope_array[p->last_element] = scope_id;
    p->nested_scopes = list;
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

int* init_aux_list(int* list){
    list[0] = 0;
    for(int i = 1; i < 1000; i++){
        list[i] = -1;
    }
    return list;
}

void empty_aux_list(int* list){
    for(int i = 1; i < 1000; i++){
        list[i] = -1;
    }
}

int* push_auxiliary_scope_list(int scope, int* list){
    int i;
    int list_size = 0;
    for(i = 0; i < 1000; i++){
        if(list[i] == -1){
            list_size = i;    
            break;
        }
    }
    list[list_size] = scope;
    return list;
}

void print_aux_list(int* list){
    printf("Beginning list\n");
    for(int i = 0; i < 1000; i++){
        if(list[i] != -1){
            printf("%d ", list[i]);
        }else{
            break;
        }
    }
    printf("\n");
}
