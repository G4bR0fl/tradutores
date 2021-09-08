#ifndef _TABELA_H_
#define _TABELA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Symbol {
    int line;
    int column;
    int is_function;
    char type[100];
    char identifier[100];
    int scope; 
}symbol;

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function);

#endif