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
