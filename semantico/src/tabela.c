#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/tabela.h"
#include "../lib/pilha.h"

#define BRED "\e[0;31m"
#define BMAG "\e[1;35m"
#define RESET "\e[0m"

symbol symbol_table[100000];

symbol add_symbol(int line, int column, char* identifier, char* type, int is_function, int scope){
    
    symbol new_symbol;
    new_symbol.not_empty = 1;
    new_symbol.line = line;
    new_symbol.column = column;
    strcpy(new_symbol.identifier, identifier);
    strcpy(new_symbol.type, type);
    new_symbol.is_function = is_function;
    new_symbol.scope = scope;

    return new_symbol;
}

int find_last_symbol(symbol* s){
    for(int i = 0; i < (int)sizeof(symbol_table)/220; i++){
        if(s[i].not_empty == 0){
            return i;
        }
    }
    return -1;
}

int is_duplicated(symbol* s, char* identifier, int scope, int line, int column){
    char new_id_string[100];
    int latest_index = find_last_symbol(s);
    strcpy(new_id_string, identifier);
    for(int i = 0; i < latest_index; i++){
        int id_comparation = strcmp(new_id_string, s[i].identifier);
        if(id_comparation == 0 && scope == s[i].scope){
            printf(BRED"(%d:%d) '%s' - Has already been declared on this scope -> [%d]" RESET, line, column, identifier, scope);
            return 1;
        }
    }
    return 0;
}

void print_table(int size){
    int i;
    if(size > 0){
        printf("\t\t\t\tTabela de Simbolos\n");
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
