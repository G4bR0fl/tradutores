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

int function_param_amount(tree* node, symbol* s, int depth, int* pointer){
    // char called_function[100];
    // int args_count = 0;
    // int aux_arg_count = 0;
    symbol found_symbol;
    if(node == NULL){
        return 0;
    }
    if(strcmp(node->type_name, "empty") == 0){
        return 0;
    }
    if(strcmp(node->type_name, "factor_arguments") == 0){
        found_symbol = find_symbol(s, node->node1->type_name);
        if(found_symbol.not_empty == 1){
            // function_param_amount(node->node1, s, depth+1);
            function_param_amount(node->node2, &found_symbol, depth+1, pointer);
            if(found_symbol.function_params != *pointer){
                printf(BRED"(%d:%d) Semantic error: %s expected %d arguments but received %d.\n" RESET, node->line, node->column, found_symbol.identifier, found_symbol.function_params, *pointer);
            } // Botar linha e coluna nesse erro e na árvore.
            *pointer = 0;
            // function_param_amount(node->node3, s, depth+1);
            // function_param_amount(node->node4, s, depth+1);
            // function_param_amount(node->node5, s, depth+1);
        } else printf("Symbol not found!");
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

