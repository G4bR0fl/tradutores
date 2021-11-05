#include "../lib/tac.h"

// Uses DFS to check tree and write on the output file
void write_symbol_table(tree* node, FILE *fp){
    if(!node) return;
    if(node->is_symbol== 1){
        fprintf(fp, "%s\n", node->tac_symbol);
    }
    write_symbol_table(node->node1, fp);
    write_symbol_table(node->node2, fp);
    write_symbol_table(node->node3, fp);
    write_symbol_table(node->node4, fp);
    write_symbol_table(node->node5, fp);
}

// Write the effective code on '.code' section on the output file
void write_code(tree* node, FILE *fp){
    if(!node) return;
    // Label part


    // Code part
    write_code(node->node1, fp);
    write_code(node->node2, fp);
    write_code(node->node3, fp);
    write_code(node->node4, fp);
    write_code(node->node5, fp);
    if(strcmp(node->tac_code, "") != 0){
        fprintf(fp, "%s\n", node->tac_code);
    }
}

void write_string(FILE *fp){
    
}
// void arithmetic_cast(tree* left_arg, tree* right_arg){
//     if(!left_arg || !right_arg) return;
//     if((strcmp(left_arg->type, "float") == 0 && strcmp(right_arg->type, "float") != 0)){

//     }
//     if((strcmp(left_arg->type, "float") != 0 && strcmp(right_arg->type, "float") == 0))
// }