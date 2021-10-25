#include "../lib/arvore.h"
#include "../lib/pilha.h"
#include "../lib/tabela.h"
#include "../lib/semantic_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRED "\e[0;31m"
#define BMAG "\e[1;35m"
#define RESET "\e[0m"

// Get the amount of params called by all functions and throws errors if it's not correct.
void function_param_amount(symbol* s, int args_counted, char* name, int line, int column){
    symbol found_symbol;
    found_symbol = find_symbol(s, name);
    if(found_symbol.not_empty == 1){
        if(found_symbol.function_params != args_counted){
            printf(BRED"(%d:%d) Semantic Error: function '%s' expected %d arguments but received %d.\n" RESET, line, column, found_symbol.identifier, found_symbol.function_params, args_counted);
        }
    }
}

// Checks if both types from an expression are correct
int type_comparer(tree* left_arg, tree* right_arg){
    if(strcmp(left_arg->type, right_arg->type) == 0){
        return SAME_TYPE; 
    } else return DIFF_TYPE;
}

// Checks if read/write statements are correct
int input_output_comparer(tree* arg){
    if(strcmp(arg->type, "int") == 0 || strcmp(arg->type, "float") == 0){
        return SAME_TYPE;
    } else return DIFF_TYPE;
}

// Checks if assignments are correct
int assignment_comparer(tree* left_arg, tree* right_arg){
    if((left_arg->is_function == 0) && (strcmp(left_arg->type, right_arg->type) == 0)){ 
        // checar se right_arg eh chamada de func ou nao -> tem q mexer com tabela de simbolos
        return SAME_TYPE;
    } else return DIFF_TYPE;
}

// Checks Unary operations
int verify_unary_operator(tree* left_arg){
    if((strcmp(left_arg->type_name, "+") == 0) || (strcmp(left_arg->type_name, "-") == 0)){
        return BINARY_OPERAND;
    } else if (strcmp(left_arg->type_name, "?") == 0){
        return HEADER_OPERAND;
    } else if (strcmp(left_arg->type_name, "%") == 0){
        return TAIL_OPERAND;
    } else if(strcmp(left_arg->type_name, "!") == 0){
        return NEGATION_OR_TAIL;
    } 
    return DIFF_TYPE;
}

// Checks lists operations
int list_operation_comparer(tree* operation){

    if(strcmp(operation->type_name, "<<") == 0){
        return FILTER_OPERAND;
    } else if(strcmp(operation->type_name, ">>") == 0){
        return MAP_OPERAND;
    } else if(strcmp(operation->type_name, ":") == 0){
        return CONSTRUCTOR_OPERAND;
    } else return DIFF_TYPE;
}

// Casts NIL type in different contexts
void cast_nil(tree* left_arg, tree* right_arg){
    // NIL a esquerda
    if(strcmp(left_arg->type, "NIL") == 0){
        strcpy(left_arg->type, right_arg->type);
        return;
    }
    // NIL a direita
    if(strcmp(right_arg->type, "NIL") == 0){
        strcpy(right_arg->type, left_arg->type);
        return;
    }
}

void cast_nil_constructor(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = right_arg;
    father_node->node3 = new_node;
    if(strcmp(left_arg->type, "int") == 0){
        strcpy(new_node->type, "int list");
        return;
    } else if(strcmp(left_arg->type, "float") == 0){
        strcpy(new_node->type, "float list");
        return;
    }
}

void cast_return(tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = right_arg;
    father_node->node1 = new_node;
    strcpy(new_node->type, father_node->type);
}

void create_cast_node_left(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = left_arg;
    father_node->node1 = new_node; 
    // List operation casting
    if(strcmp(right_arg->type, "int list") == 0){
        strcpy(new_node->type, "int"); 
        return;
    } else if(strcmp(right_arg->type, "float list") == 0){
        strcpy(new_node->type, "float"); 
        return;
    }
    // Normal Operations casting
    strcpy(new_node->type, right_arg->type); 
}

void cast_node_right(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = right_arg;
    father_node->node3 = new_node;
    strcpy(new_node->type, left_arg->type);
}

// + and - operations - Done
void evaluate_arithmetic(tree* left_arg, tree* father_node, tree* right_arg){
    if(type_comparer(left_arg, right_arg) == SAME_TYPE){
        strcpy(father_node->type, left_arg->type);
    } else {
        // Float a direita
        if((strcmp(left_arg->type, "int") == 0) && strcmp(right_arg->type, "float") == 0){
            create_cast_node_left(left_arg, father_node, right_arg, "int_to_float");
            evaluate_arithmetic(father_node->node1, father_node, father_node->node3);
            return;
        } else { // Float a esquerda
            if((strcmp(left_arg->type, "float") == 0) && strcmp(right_arg->type, "int") == 0){ 
                cast_node_right(left_arg, father_node, right_arg, "int_to_float");
                evaluate_arithmetic(father_node->node1, father_node, father_node->node3);
                return;
            } else { 
                // Comparacao de int e int list
                if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "int list") == 0) || 
                (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int and int list\n" RESET, father_node->line, father_node->column);
                    return;
                } 
                // Comparacao int e float list 
                if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "float list") == 0) || 
                (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int and float list\n" RESET, father_node->line, father_node->column);
                    return;
                }
                // Comparacao float e int list
                if((strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "int list") == 0) || 
                (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Implicit conversion between float and int list\n" RESET, father_node->line, father_node->column);
                    return;
                }
                // Comparacao float e float list
                if((strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "float list") == 0) || 
                (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Implicit conversion between float and float list\n" RESET, father_node->line, father_node->column);
                    return;
                }
                // Comparacao int list e float list
                if((strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float list") == 0) || 
                (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int list") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int list and float list\n" RESET, father_node->line, father_node->column);
                    return;
                }    
                // Comparacao int list + int list ou float list + float list
                if((strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int list") == 0) || 
                (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float list") == 0)){
                    printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
                    return;
                }
                // Comparacao com NIL
                if( (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
                (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "int") == 0) ||
                (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
                (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "float") == 0) ){
                    printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
                    return;
                }
            }
        }
    }
}

// * and / operations - Done
void evaluate_mult_div(tree* left_arg, tree* father_node, tree* right_arg){
    if(type_comparer(left_arg, right_arg) == SAME_TYPE){
        strcpy(father_node->type, left_arg->type);
    } else {
        // Float a direita
        if((strcmp(left_arg->type, "int") == 0) && strcmp(right_arg->type, "float") == 0){
            create_cast_node_left(left_arg, father_node, right_arg, "int_to_float");
            evaluate_mult_div(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Float a esquerda
        if((strcmp(left_arg->type, "float") == 0) && strcmp(right_arg->type, "int") == 0){ 
            cast_node_right(left_arg, father_node, right_arg, "int_to_float");
            evaluate_arithmetic(father_node->node1, father_node, father_node->node3);
            return;
        }
        else{
            // Comparacao int e int list
            if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "int list") == 0) || 
            (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int and int list\n" RESET, father_node->line, father_node->column);
                return;
            } 
            // Comparacao int e float list 
            if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "float list") == 0) || 
            (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int and float list\n" RESET, father_node->line, father_node->column);
                return;
            }
            // Comparacao float e int list
            if((strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "int list") == 0) || 
            (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Implicit conversion between float and int list\n" RESET, father_node->line, father_node->column);
                return;
            }
            // Comparacao float e float list
            if((strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "float list") == 0) || 
            (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Implicit conversion between float and float list\n" RESET, father_node->line, father_node->column);
                return;
            }
            // Comparacao int list e float list
            if((strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float list") == 0) || 
            (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int list") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Implicit conversion between int list and float list\n" RESET, father_node->line, father_node->column);
                return;
            }    
            // Comparacao (int list * int list) ou (float list * float list)
            if((strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int list") == 0) || 
            (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float list") == 0)){
                printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
                return;
            } 
            // Comparacao com NIL
            if( (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
            (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "int") == 0) ||
            (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
            (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "float") == 0) ){
                printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
                return;
            }

        }
        
    }
}

// Read operation - Done
void evaluate_read_write(tree* father_node, tree* arg){
    if(input_output_comparer(arg) == SAME_TYPE){
        strcpy(father_node->type, arg->type);
        return;
    } else {
        // Receiving int list
        if(strcmp(arg->type, "int list") == 0){
            printf(BRED"(%d:%d) Semantic Error: Unsupported identifier type '%s'.\n"RESET, arg->line, arg->column, arg->type);
            return;
        }
        // Receiving float list
        if(strcmp(arg->type, "float list") == 0){
            printf(BRED"(%d:%d) Semantic Error: Unsupported identifier type '%s'.\n"RESET, arg->line, arg->column, arg->type); 
            return;
        }
    }
}

// Assignment - Done
/* 
* 'int' com 'int' e 'float' com 'float' e conversao para float caso necessario - OK
* Em caso de NIL
*   - Comparar com 'float list' ou 'int list' e fazer a conversao - OK
*   - 'int list' so compara com 'int list', mesma coisa pra 'float list', checar o tipo do NIL - OK
* No pai precisa ser 'int' - OK
* Para todas relacionais: Nao pode comparar funcao(id sem '()') - X
* Nao pode comparar funcao(id), function call(factor args) pode. Ex: a (int) < soma(a, b) (int) - X
*/
void evaluate_assignment(tree* left_arg, tree* father_node, tree* right_arg){
    if(assignment_comparer(left_arg, right_arg) == SAME_TYPE){
        strcpy(father_node->type, left_arg->type);
        return;
    } else {
        // Float a direita
        if((strcmp(left_arg->type, "int") == 0) && (strcmp(right_arg->type, "float") == 0)){
            cast_node_right(left_arg, father_node, right_arg, "float_to_int");
            evaluate_assignment(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Int a direita
        if((strcmp(left_arg->type, "float") == 0) && (strcmp(right_arg->type, "int") == 0)){
            cast_node_right(left_arg, father_node, right_arg, "int_to_float");
            evaluate_assignment(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Int recebendo int_list, float_list, NIL
        if(((strcmp(left_arg->type, "int") == 0) && (strcmp(right_arg->type, "int list") == 0)) ||
        ((strcmp(left_arg->type, "int") == 0) && (strcmp(right_arg->type, "float list") == 0)) ||
        ((strcmp(left_arg->type, "int") == 0) && (strcmp(right_arg->type, "NIL") == 0))){
            printf(BRED"(%d:%d) Semantic Error: Invalid assignment between '%s' and '%s'\n" RESET, left_arg->line, left_arg->column, left_arg->type, right_arg->type);
            return;  
        }
        // Float recebendo int_list, float_list, NIL
        if(((strcmp(left_arg->type, "float") == 0) && (strcmp(right_arg->type, "int list") == 0)) ||
        ((strcmp(left_arg->type, "float") == 0) && (strcmp(right_arg->type, "float list") == 0)) ||
        ((strcmp(left_arg->type, "float") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ){
            printf(BRED"(%d:%d) Semantic Error: Invalid assignment between '%s' and '%s'\n" RESET, left_arg->line, left_arg->column, left_arg->type, right_arg->type);
            return;  
        }
        // int list ou float list recebendo NIL e fazer a conversao
        if( ((strcmp(left_arg->type, "int list") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ||
            ((strcmp(left_arg->type, "float list") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ){
                cast_nil(left_arg, right_arg);
                evaluate_assignment(father_node->node1, father_node, father_node->node3);    
        }
        // int list ou float list recebendo int ou float ou tipo de lista distinto
        if( (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0) || 
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0) || 
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0) || 
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float list") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Invalid assignment between '%s' and '%s'\n"RESET, left_arg->line, left_arg->column, left_arg->type, right_arg->type);
        }
        
    }
}

// Relational expressions - Done
/* 
    * 'int' com 'int' e 'float' com 'float' e conversao para float caso necessario - OK
    * Para todas relacionais: Nao pode comparar funcao(id sem '()') - X
    * Nao pode comparar funcao(id), function call(factor args) pode. Ex: a (int) < soma(a, b) (int) - X
    * Em caso de NIL
    *   - Comparar com 'float list' ou 'int list' e fazer a conversao - OK
    *   - 'int list' so compara com 'int list', mesma coisa pra 'float list', checar o tipo do NIL - OK
    * No pai precisa ser 'int' - OK
*/
void evaluate_relational(tree* left_arg, tree* father_node, tree* right_arg){
    if(type_comparer(left_arg, right_arg) == SAME_TYPE){
        strcpy(father_node->type, "int");
        return;
    } else {
        // Float a direita
        if((strcmp(left_arg->type, "int") == 0) && strcmp(right_arg->type, "float") == 0){
            create_cast_node_left(left_arg, father_node, right_arg, "int_to_float");
            evaluate_relational(father_node->node1, father_node, father_node->node3);
            return;
        } 
        // Float a esquerda
        if((strcmp(left_arg->type, "float") == 0) && strcmp(right_arg->type, "int") == 0){ 
            cast_node_right(left_arg, father_node, right_arg, "int_to_float");
            evaluate_relational(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Int e float recebendo tipos de listas
        if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "int list") == 0) || 
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "float list") == 0) ||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "float list") == 0)||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Implicit conversion between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
            return;
        } 
        // Casos com NIL
        if((strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "float list") == 0) || 
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "NIL") == 0)){
            cast_nil(left_arg, right_arg);
            evaluate_relational(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Casos errados com NIL
        if((strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "float") == 0) ||
        (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "NIL") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Implicit conversion between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
            return;
        }

    }  
}   

// Logical expressions - Done
/* 
    * Nao pode ter 'int list', 'float list' ou NIL - OK 
    * Tratar apenas 'int' 'float' - OK
    * No pai precisa ser 'int' - OK
    * Nao pode comparar funcao(id), function call pode - X
    * Para todas relacionais: Nao pode comparar funcao(id sem '()') - X
*/
void evaluate_logical(tree* left_arg, tree* father_node, tree* right_arg){
    if(type_comparer(left_arg, right_arg) == SAME_TYPE){
        strcpy(father_node->type, "int");
        return;
    } else {
        // Float a direita
        if((strcmp(left_arg->type, "int") == 0) && strcmp(right_arg->type, "float") == 0){
            create_cast_node_left(left_arg, father_node, right_arg, "int_to_float");
            evaluate_logical(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Float a esquerda
        if((strcmp(left_arg->type, "float") == 0) && strcmp(right_arg->type, "int") == 0){
            cast_node_right(left_arg, father_node, right_arg, "int_to_float");
            evaluate_logical(father_node->node1, father_node, father_node->node3);
            return;
        }
        // Int e float recebendo tipos de listas ou NIL
        if((strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "int list") == 0) || 
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "float list") == 0) ||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "float list") == 0)||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0) ||
        (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(left_arg->type, "NIL") == 0 && strcmp(right_arg->type, "float") == 0) ||
        (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "NIL") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "int list") == 0 && strcmp(right_arg->type, "float list") == 0) ||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(left_arg->type, "float list") == 0 && strcmp(right_arg->type, "float list") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Implicit conversion between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type, right_arg->type);
            return;
        }
    }
}

// Return statements - Done 
/* 
    * PRIORIDADE: No sintatico quando passa pelo return ainda ta sem tipo!!! - OK
    * 'int' com 'int' e 'float' com 'float' e conversao para float caso necessario - - OK
    * Em caso de NIL
    *   - Comparar com 'float list' ou 'int list' e fazer a conversao -  
    *   - 'int list' so compara com 'int list', mesma coisa pra 'float list', checar o tipo do NIL - 
    * Nao pode comparar funcao(id), function call(factor args) pode. Ex: a (int) < soma(a, b) (int) -
*/
void evaluate_return(tree* father_node, tree* right_arg, char* return_type){
    if((father_node && father_node->node1 == NULL) || (right_arg && right_arg->node1 == NULL)) return;
    if(strcmp(return_type, right_arg->type) == 0){
        strcpy(father_node->type, return_type);
        return;
    } else {
        strcpy(father_node->type, return_type);
        // Cast pra inteiro
        if((strcmp(father_node->type, "int") == 0) && (strcmp(right_arg->type, "float") == 0)){
            cast_return(father_node, right_arg, "float_to_int");
            return;
        }
        // Cast pra float
        if(strcmp(father_node->type, "float") == 0 && strcmp(right_arg->type, "int") == 0){
            cast_return(father_node, right_arg, "int_to_float");
            return;
        }
        // Int recebendo int_list, float_list, NIL
        if((strcmp(father_node->type, "int") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(father_node->type, "int") == 0 && strcmp(right_arg->type, "float list") == 0) ||
        (strcmp(father_node->type, "int") == 0 && strcmp(right_arg->type, "NIL") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Invalid return type '%s'. Expected 'int' or 'float'\n" RESET, father_node->line, father_node->column, right_arg->type);
            return;   
        }
        // Float recebendo int list, float list, NIL
        if((strcmp(father_node->type, "float") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(father_node->type, "float") == 0 && strcmp(right_arg->type, "float list") == 0) ||
        (strcmp(father_node->type, "float") == 0 && strcmp(right_arg->type, "NIL") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Invalid return type '%s'. Expected 'int' or 'float'\n" RESET, father_node->line, father_node->column, right_arg->type);
            return;   
        }
        // int list ou float list recebendo int ou float ou tipo de lista distinto
        if( (strcmp(father_node->type, "int list") == 0 && strcmp(right_arg->type, "int") == 0) ||
        (strcmp(father_node->type, "int list") == 0 && strcmp(right_arg->type, "float") == 0) || 
        (strcmp(father_node->type, "float list") == 0 && strcmp(right_arg->type, "int") == 0) || 
        (strcmp(father_node->type, "float list") == 0 && strcmp(right_arg->type, "float") == 0) || 
        (strcmp(father_node->type, "float list") == 0 && strcmp(right_arg->type, "int list") == 0) ||
        (strcmp(father_node->type, "int list") == 0 && strcmp(right_arg->type, "float list") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Invalid assignment between '%s' and '%s'\n"RESET, father_node->line, father_node->column, father_node->type, right_arg->type);
            return;
        }
        // int list ou float list recebendo NIL e fazendo a conversao
        if( ((strcmp(father_node->type, "int list") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ||
            ((strcmp(father_node->type, "float list") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ){
                cast_nil(father_node, right_arg);
                return;
        }
    }
    return;
}

// DFS search for this lad
void search_return(tree* node, char* node_name, char* type){
    if(node == NULL){
        return;
    }
    if(strcmp(node->type_name, "empty") == 0){
        return;
    }
    if((strcmp(node->type_name, "return") == 0)){
        strcpy(node->type, type);
        evaluate_return(node, node->node1, type);
    }else{
        search_return(node->node1, node_name, type);
        search_return(node->node2, node_name, type);
        search_return(node->node3, node_name, type);
        search_return(node->node4, node_name, type);
        search_return(node->node5, node_name, type);
    }
    return;
}

// Unary operations(?, !, %, +, -)
/*
    * Nao pode operar em id de funcao e nao pode operar em NIL(regra vale pra todos)
    * Operadores '+' e '-':
    * - So podem operar em tipo primitivo 'int' ou 'float' - OK
    * - Retorno do operador eh o tipo do operando - OK
    * Operador '?':
    * - So pode ser aplicado a tipo list 'int list' ou 'float list' - OK
    * - Tipo do operador retorna 'int' ou 'float' baseado na cabeca da lista - OK
    * Operador '%':
    * - So pode ser aplicado a tipo list 'int list' ou 'float list' - OK
    * - Tipo do operador retorna 'int list' ou 'float list' - OK
    * Operador '!':
    * - Negacao ou cauda da lista - OK
    * - Pode receber os 4 tipos 
    * - Em caso de 'float' ou 'int'
    *    - retornar inteiro pois eh boolean - OK
    * - Em caso de 'int list' ou 'float list' 
    *    - retorna o tipo do operando - OK
    * 
*/
void evaluate_unary(tree* left_arg, tree* father_node, tree* right_arg){
    // * Operadores '+' e '-':
    if(verify_unary_operator(left_arg) == BINARY_OPERAND){
        // int ou float a direita
        if(strcmp(right_arg->type, "int") == 0 || strcmp(right_arg->type, "float") == 0){
            strcpy(father_node->type, right_arg->type);
            return;
        }
        // int list ou float list ou NIL a direita
        if((strcmp(right_arg->type, "int list") == 0) || 
        (strcmp(right_arg->type, "float list") == 0) || 
        (strcmp(right_arg->type, "NIL") == 0)){
            printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type_name, right_arg->type);
            return;
        }
    }
    // Operador '?':
    if(verify_unary_operator(left_arg) == HEADER_OPERAND){
        // Recebendo int list
        if(strcmp(right_arg->type, "int list") == 0){
            strcpy(father_node->type, "int");
            return;
        }
        // Recebendo float list
        if(strcmp(right_arg->type, "float list") == 0){
            strcpy(father_node->type, "float");
            return;
        }
        // Recebendo int, float ou NIL
        if(strcmp(right_arg->type, "int") == 0 ||
        strcmp(right_arg->type, "float") == 0 ||
        strcmp(right_arg->type, "NIL") == 0){
            printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type_name, right_arg->type);
            return;
        }
    }
    // Operador '%'
    if(verify_unary_operator(left_arg) == TAIL_OPERAND){
        // Recebebndo int list ou float list
        if(strcmp(right_arg->type, "int list") == 0 || strcmp(right_arg->type, "float list") == 0){
            strcpy(father_node->type, right_arg->type);
            return;
        }
        // Recebendo int, float ou NIL
        if(strcmp(right_arg->type, "int") == 0 ||
        strcmp(right_arg->type, "float") == 0 ||
        strcmp(right_arg->type, "NIL") == 0){
            printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type_name, right_arg->type);
            return; 
        }
    }
    // Operador '!' como negacao
    if(verify_unary_operator(left_arg) == NEGATION_OR_TAIL){
        // Recebendo int ou float
        if(strcmp(right_arg->type, "int") == 0 || strcmp(right_arg->type, "float") == 0){
            strcpy(father_node->type, right_arg->type);
            return;
        }
        // Recebendo int list, float list
        if(strcmp(right_arg->type, "int list") == 0 || strcmp(right_arg->type, "float list") == 0) {
            strcpy(father_node->type, right_arg->type);
            return; 
        }
        // Recebendo NIL
        if(strcmp(right_arg->type, "NIL") == 0) {
            printf(BRED"(%d:%d) Semantic Error: Invalid operation between '%s' and '%s'\n" RESET, father_node->line, father_node->column, left_arg->type_name, right_arg->type);
            return; 
        }
    }
}


// List Operations (map(>>), filter(<<), binary_constructor ':')
/* 
    * No filter:
    * - Operador da direita pode ser: 'int list', 'float list' ou NIL - OK
    * - O retorno da operacao eh o tipo do segundo operando - OK
    * - Operador da esquerda tem que ser id de funcao. A funcao necessariamente tem que ser unaria(So pode ter um argumento).
    * No map:
    * - Operando da direita necessariamente precisa ser do tipo 'int list' ou 'float list'. Nao pode ser nil - OK
    * - Operador da esquerda tem que ser id de funcao. A funcao necessariamente tem que ser unaria(So pode ter um argumento). 
    *   So pode retornar 'int' ou 'float' - OK
    * - O retorno da operacao eh baseado no operando esquerdo. - OK
    * Construtor:
    * - Operando da direita pode ser 'int list', 'float list' ou 'NIL' - OK
    * - Operando da esquerda so pode ser 'int' ou 'float' - OK
    * - Nao pode receber funcao
    * - O tipo da operacao sempre eh o do operando mais a direita
    * - 1 : float_list -> converter 1 pra float antes de inserir na lista/1.5 : int_list -> converter 1 pra int antes de inserir na lista - OK
    * - NIL
    *    - 1 : NIL -> Tipar o nil como int list baseado no operador da esquerda, mesma coisa caso seja um float - OK
    *    - Retorno do operador sempre eh o tipo da direita - OK
*/
void evaluate_list_exp(tree* left_arg, tree* father_node, tree* right_arg, tree* operation){ 
    // Filter '<<'
    if(list_operation_comparer(operation) == FILTER_OPERAND){
        // Operador a direita 'int list' ou 'float list' ou eh 'NIL'
        if( ((strcmp(left_arg->type, "int") || strcmp(left_arg->type, "float")) && (strcmp(right_arg->type, "int list") == 0)) || 
        ((strcmp(left_arg->type, "int") || strcmp(left_arg->type, "float")) && (strcmp(right_arg->type, "float list") == 0)) ||   
        ((strcmp(left_arg->type, "int") || strcmp(left_arg->type, "float")) && strcmp(right_arg->type, "NIL") == 0)){
            strcpy(father_node->type, right_arg->type);
            return;
        }
        // Operador a direita nao eh do tipo list
        if(strcmp(right_arg->type, "int") == 0 || strcmp(right_arg->type, "float") == 0){
            printf(BRED"(%d:%d) Semantic Error: Filter operation doesn't support '%s' on right-side of operation\n" RESET,
            father_node->line, father_node->column, right_arg->type);
            return;
        }
        // Verificando tipos de lista na esquerda
        if(strcmp(left_arg->type, "int list") == 0 || strcmp(left_arg->type, "float list") == 0){
            printf(BRED"(%d:%d) Semantic Error: Filter operation doesn't support '%s' on left-side of operation\n" RESET,
            father_node->line, father_node->column, left_arg->type);
            return;
        }
    }
    // Map '>>'
    if(list_operation_comparer(operation) == MAP_OPERAND){
        // Operador a direita 'int list' ou 'float list' 
        if( (strcmp(left_arg->type, "int") == 0 && ((strcmp(right_arg->type, "int list") == 0) || strcmp(right_arg->type, "float list") == 0)) || 
        (strcmp(left_arg->type, "float") == 0 && ((strcmp(right_arg->type, "int list") == 0) || strcmp(right_arg->type, "float list") == 0)) ){
            strcpy(father_node->type, left_arg->type);
            strcat(father_node->type, "\x20");
            strcat(father_node->type, "list");
            return;
        }
        // Operando a direita recebendo int, float ou NIL
        if(strcmp(right_arg->type, "int") == 0 || strcmp(right_arg->type, "float") == 0 || strcmp(right_arg->type, "NIL") == 0)  {
            printf(BRED"(%d:%d) Semantic Error: Map operation doesn't support '%s' on right-side of operation\n" RESET,
            father_node->line, father_node->column, right_arg->type);
        }
        // Funcao da direita e da esquerda precisam ser equivalentes na parte primitiva
        if( (strcmp(left_arg->type, "int") == 0 && strcmp(right_arg->type, "int list") != 0 ) ||
        (strcmp(left_arg->type, "float") == 0 && strcmp(left_arg->type, "float list") != 0)){
            printf(BRED"(%d:%d) Semantic Error: different return types on map operation '%s' and '%s' \n" RESET,
            father_node->line, father_node->column, left_arg->type, right_arg->type);
            return;
        }
    }
    // Binary constructor ':'
    if(list_operation_comparer(operation) == CONSTRUCTOR_OPERAND){
        // Operando da direita sempre recebendo 'int list' 
        if(strcmp(right_arg->type, "int list") == 0){
            if(strcmp(left_arg->type, "int") != 0){
                create_cast_node_left(left_arg, father_node, right_arg, "float_to_int");
                strcpy(father_node->type, right_arg->type);
                return;
            } else {
                strcpy(father_node->type, right_arg->type);
                return;
            }

        }
        // Operando da direita recebendo'float list'
        if(strcmp(right_arg->type, "float list") == 0){
            if(strcmp(left_arg->type, "float") != 0){
                create_cast_node_left(left_arg, father_node, right_arg, "int_to_float");
                strcpy(father_node->type, right_arg->type);
                return;
            } else {
                strcpy(father_node->type, right_arg->type);
                return;
            }
        }
        // Operando da direita recebendo 'NIL'
        if(strcmp(right_arg->type, "NIL") == 0){
            cast_nil_constructor(left_arg, father_node, right_arg, "nil_to_list");
            strcpy(father_node->type, father_node->node3->type);
            return;
        }
        // Operando da direita recebendo 'int' ou 'float'
        if(strcmp(right_arg->type, "int") == 0 || strcmp(right_arg->type, "float") == 0){
            printf(BRED"(%d:%d) Semantic Error: Right argument on binary constructor cannot receive '%s'\n" RESET, father_node->line, father_node->column, right_arg->type);
            return;
        }
        // Operando da esquerda recebendo int list ou float list ou NIL
        if(strcmp(left_arg->type, "int list") == 0 ||
        strcmp(left_arg->type, "float list") == 0 || 
        strcmp(left_arg->type, "NIL") == 0){
            printf(BRED"(%d:%d) Semantic Error: Left argument on binary constructor cannot receive '%s'\n" RESET, father_node->line, father_node->column, left_arg->type);
            return;
        }
    }
}

