#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/tabela.h"

symbol symbol_table[100000];

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function, int scope){
    symbol new_symbol;
    new_symbol.line = line;
    new_symbol.column = column;
    strcpy(new_symbol.identifier, identifier);
    strcpy(new_symbol.type, type);
    new_symbol.is_function = is_function;
    new_symbol.scope = scope;

    return new_symbol;
}

void print_table(int size){
    int i;
    if(size > 0){
        printf("\n\t\t\t\tTabela de Simbolos\n");
        printf("\t================================================================== \n");
        printf("\tID\t\tLine:Column\tType\tisFunction\tinScope\n");
        printf("\t================================================================== \n");
        for(i = 0; i < size; i++){
            printf("\t%-7.10s \t %d:%d \t %10s \t %5d \t %10d\n", symbol_table[i].identifier, symbol_table[i].line, symbol_table[i].column, symbol_table[i].type, symbol_table[i].is_function, symbol_table[i].scope);
            printf("\t------------------------------------------------------------------\n");
        }
    } else {
        printf("TABELA VAZIA!\n");
    }
}
