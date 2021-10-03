%option noinput nounput
%option noyywrap 

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"
    #include "../lib/pilha.h"
    #include "sintatico.tab.h"

    #define BRED "\e[0;31m"
    #define BMAG "\e[1;35m"
    #define RESET "\e[0m"

    int line = 1;
    int columns = 1;
    int errors = 0;
    int scope = 0;

    extern pilha scope_stack;
%}

SIMPLE_TYPE         int|float

LIST_TYPE           list

LIST_CONSTANT       NIL              

DIGIT               [0-9]

STRING              (\"([^(\"\')])*\")

ID                  [a-zA-Z_][a-z0-9A-Z_]*

BINARY_BASIC_OP1    [+-]

BINARY_BASIC_OP2    [*/]

LOGIC_OP            "||"|"&&"

BINARY_COMP_OP      "<"|"<="|">"|">="|"!="|"=="

KEYWORD             if|else|for|return

INPUT               read

OUTPUT              write|writeln

BINARY_CONSTRUCTOR  ":"

HEADER              "?"

TAIL                "!"|"%"

MAP                 ">>"

FILTER              "<<"

%%

{SIMPLE_TYPE} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return SIMPLE_TYPE;
}

{LIST_TYPE} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return LIST_TYPE;
}

{LIST_CONSTANT} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return LIST_CONSTANT;
}

{DIGIT}+ {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return INT;
}

{DIGIT}+"."{DIGIT}+ {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return FLOAT;
}

{STRING} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return STRING;
}

{BINARY_BASIC_OP1} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return BINARY_BASIC_OP1;
}

{BINARY_BASIC_OP2} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return BINARY_BASIC_OP2;
}

{LOGIC_OP} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return LOGIC_OP;
}

{BINARY_COMP_OP} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return BINARY_COMP_OP;
}

{KEYWORD} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    if(strcmp(yytext, "if") == 0) {return IF;}
    if(strcmp(yytext, "else") == 0) {return ELSE;}
    if(strcmp(yytext, "for") == 0) {return FOR;}
    if(strcmp(yytext, "return") == 0) {return RETURN;}
}

{INPUT} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return INPUT;
}

{OUTPUT} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return OUTPUT;
}

{BINARY_CONSTRUCTOR} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return BINARY_CONSTRUCTOR;
}

{HEADER} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return HEADER;
}

{TAIL} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return TAIL;
}

{MAP} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return MAP;
}

{FILTER} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return FILTER;
}

{ID} {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return ID;
}


";" {
    columns += yyleng;
    return ';';
}

"," {
    columns += yyleng;
    return ',';
}

"=" {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    return '=';
}

"{" {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    scope++;
    push(&scope_stack, scope);
    // printf("\nPUSH\n");
    // for(int i = 0; i < 15; i++){
    //     printf("%d -> ", scope_stack.scope_array[i]);
    // }
    printf("\n");
    return '{';
}

"}" {
    strcpy(yylval.token.body, yytext);
    yylval.token.columns = columns;
    yylval.token.line = line;
    columns += yyleng;
    pop(&scope_stack);
    // printf("\nPOP\n");
    // for(int i = 0; i < 15; i++){
    //     printf("%d -> ", scope_stack.scope_array[i]);
    // }
    return '}';
}

"(" {    
    columns += yyleng;
    return '(';
}

")" {
    columns += yyleng;
    return ')';
}


[ \t]+ {
    columns += yyleng;
}

\n {
    line++;
    columns = 1;
}

. {
    printf(BRED"(%d:%d)Unidentified character: '%s'\n" RESET, line, columns, yytext);
    errors++;
    columns += yyleng;
}

%%