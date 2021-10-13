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
// Useless atm
tree* search_node(tree* node, char* node_name){
    tree* aux_node = NULL;
    if(node == NULL){
        return NULL;
    }
    if(strcmp(node->type_name, "empty") == 0){
        return NULL;
    }
    if((strcmp(node->type_name, "factor_arguments") == 0) && (strcmp(node->node1->type_name, node_name) == 0)){
        return node;
    }else{
        aux_node = search_node(node->node1, node_name);
        if(aux_node == NULL){
            aux_node = search_node(node->node2, node_name);
        }
        if(aux_node == NULL){
            aux_node = search_node(node->node3, node_name);
        }
        if(aux_node == NULL){
            aux_node = search_node(node->node4, node_name);
        }
        if(aux_node == NULL){
            aux_node = search_node(node->node5, node_name);
        }
    }
    return aux_node;
}

// Get the amount of params called by all functions and throws errors if it's not correct.
int function_param_amount(tree* node, symbol* s, int depth, int* pointer){
    symbol found_symbol;
    if(node == NULL){ 
        return 0;
    }
    if(strcmp(node->type_name, "empty") == 0){
        return 0;
    }
    // Compare current node to a function call node "factor_arguments"
    if(strcmp(node->type_name, "factor_arguments") == 0){
        found_symbol = find_symbol(s, node->node1->type_name);
        if(found_symbol.not_empty == 1){
            function_param_amount(node->node2, &found_symbol, depth+1, pointer);
            if(found_symbol.function_params != *pointer){
                printf(BRED"(%d:%d) Semantic Error: '%s' expected %d arguments but received %d.\n" RESET, node->line, node->column, found_symbol.identifier, found_symbol.function_params, *pointer);
            }
            *pointer = 0;
        }
    }else{
        if((strcmp(node->type_name, "arguments") == 0) && (strcmp(node->node1->type_name, "arguments") != 0)){
            return ++*pointer;
        }else{
            function_param_amount(node->node1, s, depth+1, pointer);    
        }
        if((strcmp(node->type_name, "arguments") == 0) && (strcmp(node->node2->type_name, "arguments") != 0)){
            return ++*pointer;
        }else{
            function_param_amount(node->node2, s, depth+1, pointer);
        }
        if((strcmp(node->type_name, "arguments") == 0) && (strcmp(node->node3->type_name, "arguments") != 0)){
            return ++*pointer;
        }else{
            function_param_amount(node->node3, s, depth+1, pointer);
        }
        if((strcmp(node->type_name, "arguments") == 0) && (strcmp(node->node4->type_name, "arguments") != 0)){
            return ++*pointer;
        }else{
            function_param_amount(node->node4, s, depth+1, pointer);
        }
        if((strcmp(node->type_name, "arguments") == 0) && (strcmp(node->node5->type_name, "arguments") != 0)){
            return ++*pointer;
        }else{
            function_param_amount(node->node5, s, depth+1, pointer);
        }
    }

    return *pointer;
}

int type_comparer(tree* left_arg, tree* right_arg){
    if((strcmp(left_arg->type, right_arg->type) == 0) &&
    (strcmp(left_arg->type, "int list") != 0) &&
    (strcmp(right_arg->type, "int list") != 0) &&
    (strcmp(left_arg->type, "float list") != 0) &&
    (strcmp(right_arg->type, "float list") != 0)) {
        return SAME_TYPE; 
    } else return DIFF_TYPE;
}

void create_cast_node_left(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = left_arg;
    father_node->node1 = new_node; 
    strcpy(new_node->type, right_arg->type); 
}

void cast_node_right(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node("int_to_float");
    new_node->node1 = right_arg;
    father_node->node3 = new_node;
    strcpy(new_node->type, left_arg->type);
}

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
            }
        }
    }
}

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

        }
        
    }
}