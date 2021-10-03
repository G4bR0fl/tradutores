#include <stdlib.h>

int a;
int b;

// Tipo do retorno nao pode ser utilizado em funções de map e filter
int list retorna_list(int list b) {
    return b;
}

int funcao2(int a) {
    // 6 Tipo do retorno incorreto
    float* pointer;
    return pointer;
}

// Numero de argumento impede a utilização em map e filter, já que map e filter recebem funções unárias
int tipos(float a, int b) {
    return 1;
}

int map(int a) {
    return a + 1;
}

int map_errado(int a, int b) {
    return a + b;
}

int funcao_sem_retorno() {
    // 1 Funcao declara que retorna tipo int mas nao foi encontrada a palavra chave return
}


// 0 - Não ter declaração de main
int main () {
    int arg1;
    float arg2;
    int * pointer;
    int list list;

    // 1 - Variaveis nao declaradas
    nao_declarada = 5;

    // 2 - Chamada de funcao cuja funcao nao foi declarada
    funcao_nao_declarada();

    // 3 - Numero errado de argumentos
    funcao2(a, b);

    // 4 - Erro no tipo do paramentro da funcao
    tipos(arg1, arg2);

    // 5 - Tipos diferetes na atribuicao - Atribuicao int = pointer
    arg1 = pointer;

    // 7 - Operações/atribuições com NIL
    arg1 = NULL;

    // 8 - Operações com list - verificar se o tipo do último ID é do tipo de list, e se os outros IDs são funções
    // list1 = arg1 >> list;
    // list2 = arg2 << list;
    // list3 = list << func;
    // list4 = list >> func;

    // 9 - Checar se o número de argumentos das funções passadas em map (>>) e filter (<<) é igual 1
    // Verificar exemplos map(int) e map_errado(int, int);

    // 10 - Verificar se funções passadas em map e filter recebem um único argumento do tipo int ou float (que são os possíveis elementos de uma lista)
    list1 = retorna_lista >> list;

    // 11 - Header(?) e tail(%) devem ser seguidos de uma ID que represente o tipo lista - NOTA: no caso da (!) que pode ser negação ou tail, isso deve ser verificado em outra etapa 
    ?arg1;
    %arg2;

    // 12 - O construtor de lista (:) deve receber como o último elemento um ID de lista e os outros elementos devem ser expressões aritméticas ou IDs de variáveis do tipo int ou float. Tipos de funcao e lista devem causar erro.
    // list = list:list
    // list = funcao_que_retorna_tipo_list:list

    // 13 Redeclaração de variável ou funcao no mesmo escopo
    int redeclarada;
    int redeclarada;
}