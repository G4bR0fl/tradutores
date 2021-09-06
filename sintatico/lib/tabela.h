#ifndef TABELA
#define TABELA

typedef struct Symbol {
    int line;
    int columns;
    char type[100];
    int func_type; 
    int scope;
    int id_or_cte;
    char body[100];

}symbol;

typedef struct List{
    list* list;
    int amount;
}list;

#endif