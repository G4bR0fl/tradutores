#ifndef _TABELA_H_
#define _TABELA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "arvore.h"



// typedef struct Scope {
//     int current_scope;
//     int scope_list[1000];
// }s_scopes;

typedef struct FunctionParams {
    char argument_type[100];
}params;

typedef struct Symbol {
    int not_empty;
    int line;
    int column;
    int is_function;
    char type[100];
    char identifier[100];
    int function_params;
    int scope; 
    params* param;
}symbol;

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function, int scope);
symbol find_symbol(symbol* s, char* identifier);
void print_table(int size);
int find_last_symbol(symbol* s);
int is_duplicated(symbol* s, char* identifier, int scope, int line, int column);
int get_table_size(symbol* s);
void main_detection(int size);
char* verify_id_type(char* identifier, int scope, symbol* s);
// char* verify_id_type(tree* node, int scope, symbol* s);


#endif