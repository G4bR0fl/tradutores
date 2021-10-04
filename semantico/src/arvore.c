#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arvore.h"

#define BRED "\e[0;31m"
#define BMAG "\e[1;35m"
#define RESET "\e[0m"


tree* create_node(char* type_name){
    tree* main_node = (tree*)malloc(sizeof(tree));
    strcpy(main_node->type_name, type_name);
    main_node->node1 = NULL;
    main_node->node2 = NULL;
    main_node->node3 = NULL;
    main_node->node4 = NULL;
    main_node->node5 = NULL;

    return main_node;
}


void free_adj_node(tree* main_node){
    if(main_node->node1 != NULL){
        free_adj_node(main_node->node1);
        free(main_node->node1);
    }
    if(main_node->node2 != NULL){
        free_adj_node(main_node->node2);
        free(main_node->node2);
    }
    if(main_node->node3 != NULL){
        free_adj_node(main_node->node3);
        free(main_node->node3);
    }
    if(main_node->node4 != NULL){
        free_adj_node(main_node->node4);
        free(main_node->node4);
    }
    if(main_node->node5 != NULL){
        free_adj_node(main_node->node5);
        free(main_node->node5);
    }
}

void free_node(tree* main_node){
    free_adj_node(main_node);
    if(main_node != NULL){
        free(main_node);
    }
}

void search_undeclared_node(tree* main_node, symbol* table, int depth, pilha* stack){
    if(main_node == NULL){
        return;
    }else{
        if(strcmp(main_node->type_name, "expression") == 0){
            int table_size = find_last_symbol(table);
            int found = 0;
            // printf("Printing inside 'search_undeclared_node()\n");
            // print_aux_list(list_range);  
            for(int i = 0; i < table_size - 1; i++){
                if( ( strcmp(table[i].identifier, main_node->node1->type_name) == 0 ) && (table[i].scope == main_node->var_scope) ){
                    found++;
                    break;
                }
            }
            if(found > 0){
                printf("Variavel %s inicializada!\n", main_node->node1->type_name);
            }else{
                printf(BRED"Variavel %s nao declarada!\n" RESET, main_node->node1->type_name);
            }
        }
        else{
            if(main_node->node1 && strcmp(main_node->node1->type_name, "empty") != 0){
                search_undeclared_node(main_node->node1, table, depth+1, stack);
            }
            if(main_node->node2 && strcmp(main_node->node2->type_name, "empty") != 0){
                search_undeclared_node(main_node->node2, table, depth+1, stack);
            }
            if(main_node->node3 && strcmp(main_node->node3->type_name, "empty") != 0){
                search_undeclared_node(main_node->node3, table, depth+1, stack);
            }
            if(main_node->node4 && strcmp(main_node->node4->type_name, "empty") != 0){
                search_undeclared_node(main_node->node4, table, depth+1, stack);
            }
            if(main_node->node5 && strcmp(main_node->node5->type_name, "empty") != 0){
                search_undeclared_node(main_node->node5, table, depth+1, stack);
            }
        }
    }
}   

void print_tree(tree* main_node, int depth){
    if(main_node == NULL){
        return;
    }else{
        for(int i = 0; i < depth; i++){
            printf(" | ");
        }
        printf(" ├─ %s\n", main_node->type_name);
        if(main_node->node1 && strcmp(main_node->node1->type_name, "empty") != 0){
            print_tree(main_node->node1, depth+1);
        }
        if(main_node->node2 && strcmp(main_node->node2->type_name, "empty") != 0){
            print_tree(main_node->node2, depth+1);
        }
        if(main_node->node3 && strcmp(main_node->node3->type_name, "empty") != 0){
            print_tree(main_node->node3, depth+1);
        }
        if(main_node->node4 && strcmp(main_node->node4->type_name, "empty") != 0){
            print_tree(main_node->node4, depth+1);
        }
        if(main_node->node5 && strcmp(main_node->node5->type_name, "empty") != 0){
            print_tree(main_node->node5, depth+1);
        }
    }
}