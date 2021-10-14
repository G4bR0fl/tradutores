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


void create_cast_node_left(tree* left_arg, tree* father_node, tree* right_arg, char* node_name){
    tree* new_node = create_node(node_name);
    new_node->node1 = left_arg;
    father_node->node1 = new_node; 
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

// Assignment - Nearly Done 
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
            ((strcmp(left_arg->type, "float list") == 0) && (strcmp(right_arg->type, "NIL") == 0)) ||
            ((strcmp(left_arg->type, "NIL") == 0) && (strcmp(right_arg->type, "int list") == 0)) ||
            ((strcmp(left_arg->type, "NIL") == 0) && (strcmp(right_arg->type, "float list") == 0)) ){
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
        // Checar se o argumento da direita eh uma funcao do mesmo tipo do operador da esquerda
    }
}

// Relational expressions - Nearly Done
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
    /* 
    * 'int' com 'int' e 'float' com 'float' e conversao para float caso necessario - OK
    * Para todas relacionais: Nao pode comparar funcao(id sem '()') - X
    * Nao pode comparar funcao(id), function call(factor args) pode. Ex: a (int) < soma(a, b) (int) - X
    * Em caso de NIL
    *   - Comparar com 'float list' ou 'int list' e fazer a conversao - OK
    *   - 'int list' so compara com 'int list', mesma coisa pra 'float list', checar o tipo do NIL - OK
    * No pai precisa ser 'int' - OK
    */

    

// Logical expressions (&& and ||)
    /* 
     * Nao pode ter 'int list', 'float list' ou NIL
     * Tratar apenas 'int' 'float'
     * Nao pode comparar funcao(id), function call pode
     * No pai precisa ser 'int'
    */

// return 
    /* 
     * Igual atribuicao
     */

// Unary operations(?, !, %, +, -)
    /* Nao pode operar em id de funcao e nao pode operar em NIL(regra vale pra todos)
     * Operadores '+' e '-':
     * - So podem operar em tipo primitivo 'int' ou 'float'
     * - Retorno do operador eh o tipo do operando
     * Operador '?':
     * - So pode ser aplicado a tipo list 'int list' ou 'float list'
     * - Tipo do operador retorna 'int' ou 'float' baseado na cabeca da lista
     * Operador '%':
     * - So pode ser aplicado a tipo list 'int list' ou 'float list'
     * - Tipo do operador retorna 'int list' ou 'float list'
     * Operador '!':
     * - Negacao ou cauda da lista
     * - Pode receber os 4 tipos
     * - Em caso de 'float' ou 'int'
     *    - retornar inteiro pois eh boolean
     * - Em caso de 'int list' ou 'float list' 
     *    - retorna o tipo do operando
     * 
     */

// List Operations (map(>>), filter(<<), binary_constructor ':')
    /* 
     * No filter:
     * - Operador da direita pode ser: 'int list', 'float list'
     * - Operador da esquerda tem que ser id de funcao. A funcao necessariamente tem que ser unaria(So pode ter um argumento). So pode retornar 'int' ou 'float'
     * - O retorno da operacao eh o tipo do segundo operando
     * - Possivelmente checar se o retorno da operacao eh um 'int', pois retornar TRUE ou FALSE
     * No map:
     * - Operando da direita necessariamente precisa ser do tipo 'int list' ou 'float list'. Nao pode ser nil
     * - Operador da esquerda tem que ser id de funcao. A funcao necessariamente tem que ser unaria(So pode ter um argumento). So pode retornar 'int' ou 'float'
     * - O retorno da operacao eh baseado no operando esquerdo. Se o operando esquerdo retorna 'int', o no pai vai receber 'int list', mesma coisa pra float
     * Construtor:
     * - Operando da direita pode ser 'int list', 'float list' ou 'NIL'
     * - Operando da esquerda so pode ser 'int' ou 'float'
     * - Nao pode receber funcao
     * - O tipo da operacao sempre eh o do operando mais a direita
     * - 1 : float_list -> converter 1 pra float antes de inserir na lista/1.5 : int_list -> converter 1 pra int antes de inserir na lista
     * - NIL
     *    - 1 : NIL -> Tipar o nil como int list baseado no operador da esquerda, mesma coisa caso seja um float
     *    - Retorno do operador sempre eh o tipo da direita
     */

