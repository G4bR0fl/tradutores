#ifndef _TAC_H_
#define _TAC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "pilha.h"
#include "tabela.h"
#include "semantic_utils.h"

// FileWriting
void write_symbol_table(tree* node, FILE *fp);
void write_code(tree* node, FILE *fp);

// Casting
void arithmetic_cast(tree* left_arg, tree* right_arg);


#endif