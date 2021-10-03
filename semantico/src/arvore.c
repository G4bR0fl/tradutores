#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arvore.h"

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

void search_node(tree* main_node, int depth){

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