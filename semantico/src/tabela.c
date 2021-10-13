#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/tabela.h"
#include "../lib/pilha.h"

#define BRED "\e[0;31m"
#define BMAG "\e[1;35m"
#define RESET "\e[0m"

symbol symbol_table[100000];
params param[100000];
// s_scopes scopes[1000];

// Adds a new entry to the symbol_table
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

// Find a specific entry on symbol_table based on the 'identifier' provided
symbol find_symbol(symbol* s, char* identifier){
    symbol found_symbol;
    int i;
    int last_idx = find_last_symbol(s);
    for(i = 0; i < last_idx; i++){
        if(strcmp(s[i].identifier, identifier) == 0){
            found_symbol = s[i];
            break;
        }
    }
    if(s[i].not_empty == 0){
        found_symbol = s[i];
    }
    return found_symbol;
}

// Find last symbol and returns last index
int find_last_symbol(symbol* s){
    for(int i = 0; i < (int)sizeof(symbol_table)/220; i++){
        if(s[i].not_empty == 0){
            return i;
        }
    }
    return -1;
}

// Check if there's any identifiers identical to the one being called
int is_duplicated(symbol* s, char* identifier, int scope, int line, int column){
    char new_id_string[100];
    int latest_index = find_last_symbol(s);
    strcpy(new_id_string, identifier);
    for(int i = 0; i < latest_index; i++){
        int id_comparation = strcmp(new_id_string, s[i].identifier);
        if(id_comparation == 0 && scope == s[i].scope){
            printf(BRED"(%d:%d) Semantic Error: '%s' - Has already been declared on this scope -> [%d]\n" RESET, line, column, identifier, scope);
            return 1;
        }
    }
    return 0;
}

// Print out the whole symbol_table
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

// Detects if there's a main declaration
void main_detection(int size){
    int detected = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(symbol_table[i].identifier, "main") == 0){
            detected++;
            break;
        }
    }
    if(detected == 0){
        printf(BRED"'Main' function not detected.\n" RESET);
    }
}

char* verify_id_type(char* identifier, int scope, symbol* s){
    int i;
    int size = find_last_symbol(s);
    for(i = 0; i < size; i++){
        if(strcmp(s[i].identifier, identifier) == 0){
            if(s[i].scope == scope){
                // printf("Verificando o tipo de %s no escopo %d\nTipo: %s\n", identifier, scope, s[i].type);
                return s[i].type;
            }
        }
    }
    // printf("Identifier not found: %s -> %d\n", identifier, scope);
    return s[i].type;
}

// char* verify_id_type2(tree* node, int scope, symbol* s){
//     int i;
//     int size = find_last_symbol(s);
//     for(i = 0; i < size; i++){
//         if(strcmp(s[i].identifier, node->type_name) == 0){
//             if(s[i].scope == scope){
//                 // printf("Verificando o tipo de %s no escopo %d\nTipo: %s\n", identifier, scope, s[i].type);
//                 return s[i].type;
//             }
//         }
//     }
//     return s[i].type;
// }