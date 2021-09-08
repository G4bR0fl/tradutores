#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/tabela.h"

symbol symbol_table[100000];

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function){
    symbol new_symbol;
    strcpy(new_symbol.identifier, identifier);
    new_symbol.column = column;
    new_symbol.line = line;
    strcpy(new_symbol.type, type);
    new_symbol.is_function = is_function;
    return new_symbol;
}


