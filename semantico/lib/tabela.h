#ifndef _TABELA_H_
#define _TABELA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Symbol {
    int not_empty;
    int line;
    int column;
    int is_function;
    char type[100];
    char identifier[100];
    int scope; 
}symbol;

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function, int scope);
void print_table(int size);
int find_last_symbol(symbol* s);
int is_duplicated(symbol* s, char* identifier, int scope, int line, int column);


#endif