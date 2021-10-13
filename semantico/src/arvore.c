#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arvore.h"

#define BRED "\e[0;31m"
#define BMAG "\e[1;35m"
#define RESET "\e[0m"
#define BCYAN "\x1b[36m"

// Creates a new node
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

// Free the whole tree recursively
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

// Free current node
void free_node(tree* main_node){
    free_adj_node(main_node);
    if(main_node != NULL){
        free(main_node);
    }
}
// Searches for undeclared IDs
void search_undeclared_node(tree* main_node, symbol* table, pilha* stack){
    if(main_node == NULL){
        return;
    }else{
        int table_size = find_last_symbol(table);
        int stack_size = get_stack_size(stack);
        int found = 0;
        for(int i = 0; i <= table_size; i++){
            if(strcmp(table[i].identifier, main_node->type_name) == 0){
                for(int j = 0; j < stack_size; j++){
                    if(stack->scope_array[j] == main_node->var_scope){
                        found++;
                        break;
                    }
                }
            }
        }
        if(found == 0){
            printf(BRED"(%d:%d) Semantic Error: '%s' undeclared on neither scopes: " RESET, main_node->line, main_node->column, main_node->type_name);
            for(int i = 0; i < stack_size; i++){
                printf(BRED"%d "RESET, stack->scope_array[i]);
            }
            printf("\n");
        }
    }
}   

// Assign types on specific tree nodes - still not working with var_decl
void assign_types(tree* node, symbol* table, pilha* stack){
    int table_size = find_last_symbol(table);
    int stack_size = get_stack_size(stack);
    printf(BCYAN"Current node: %s - %d\n"RESET, node->type_name, node->var_scope);
    int found_scope = 0;
    for(int i = 0; i < stack_size; i++){
        if(node->var_scope == stack->scope_array[i]) found_scope++;
    }
    for(int i = 0; i <= table_size; i++){
        if(strcmp(table[i].identifier, node->type_name) == 0){
            printf("(%d:%d)Current table entry: %s\n",table[i].line, table[i].column, table[i].identifier);
        }
        /* 
        * To enter this condition, either the ID from table has the same scope from the current node
        * or if it's a param, that means the var->scope is 0
        */
        if((strcmp(table[i].identifier, node->type_name) == 0 && (found_scope > 0))
        || node->var_scope == 0){
            for(int j = 0; j < stack_size; j++){
                printf(BMAG"Scope being analyzed inside array: %d\n"RESET, stack->scope_array[j]);
                if(stack->scope_array[j] == node->var_scope){
                    strcpy(node->type, table[i].type);
                    return;
                }
            }
        }
    }
    strcpy(node->type, "undefined");
}

// Print tree based on DFS(Depth first search)
void print_tree(tree* main_node, int depth){
    int node_name;
    node_name = strlen(main_node->type);
    if(main_node == NULL){
        return;
    }else{
        for(int i = 0; i < depth; i++){
            printf(" | ");
        }
        if(node_name > 0){ // Valgrind tá chateando aqui -.- (Conditional jump algo assim, ver dps se sobrar tempo);
            printf(" ├─ %s ", main_node->type_name);
            printf(BMAG"(%s) - %d\n" RESET, main_node->type, main_node->var_scope);
        } else printf(" ├─ %s\n", main_node->type_name);
        // } else printf(" ├─ %s -> %d\n", main_node->type_name, main_node->var_scope);
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