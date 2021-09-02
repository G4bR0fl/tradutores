#ifndef TABELA
#define TABELA

typedef struct Symbol {
    int line;
    int columns;
    char type[100];
    tipo_func, variavel, escopo, identificador
    int id_or_cte;
    char body[100];

}symbol;

typedef struct {
    
    int amount;
}list;

#endif