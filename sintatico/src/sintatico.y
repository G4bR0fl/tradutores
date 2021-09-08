%define lr.type canonical-lr
%define parse.error verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"

    #define BRED "\e[0;31m"
    #define BMAG "\e[1;35m"
    #define RESET "\e[0m"

    extern int line;
    extern int columns;
    extern int yylex();
    extern int yylex_destroy();
    extern int yyparse();
    void yyerror(const char* a);
    extern FILE* yyin;

    int table_index = 0;
%}  

%union{
    struct Token {
        int columns;
        int line;
        char body[101];
    } token;
}

%token <token> SIMPLE_TYPE
%token <token> INT
%token <token> FLOAT
%token <token> LIST_TYPE
%token <token> LIST_CONSTANT    
%token <token> DIGIT
%token <token> STRING
%token <token> BINARY_BASIC_OP1
%token <token> BINARY_BASIC_OP2
%token <token> LOGIC_OP
%token <token> BINARY_COMP_OP
%token <token> KEYWORD
%token <token> INPUT
%token <token> OUTPUT
%token <token> BINARY_CONSTRUCTOR
%token <token> HEADER
%token <token> TAIL
%token <token> MAP
%token <token> FILTER
%token <token> ID
%token <token> IF
%token <token> ELSE
%token <token> FOR
%token <token> RETURN


%%
program: 
    declaration_list {printf("program->declaration_list\n");}
;

declaration_list:
    declaration_list declaration {printf("declaration_list -> declaration_list declaration\n");}
    | declaration {printf("declaration_list -> declaration\n");}
;

declaration:
    var_declaration {printf("declaration -> var_declaration\n");}
    | function_declaration {printf("declaration -> function_declaration\n");}
    | list_declaration {printf("declaration -> list_declaration\n");}
;

var_declaration:
    SIMPLE_TYPE ID ';' {
        // printf("var_declaration -> %s %s ';'\n", $1.body, $2.body);
        symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0);

        printf("(%d|%d) - ID: %s TYPE: %s\n", new_symbol.line, new_symbol.column, new_symbol.identifier, new_symbol.type);
        exit(1);
    }
;

function_declaration:
    SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}' {printf("function_declaration -> %s %s '(' params ')' '{' multiple_stmt '}'\n", $1.body, $2.body);}
;

list_declaration: 
    SIMPLE_TYPE LIST_TYPE ID ';' {printf("list_declaration -> %s %s %s ';'\n", $1.body, $2.body, $3.body);}
    | SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}' {printf("list_declaration -> %s %s %s '(' params ')' '{' multiple_stmt '}'\n",
                                                                            $1.body, $2.body, $3.body);}
;

params:
    params ',' param {printf(" params -> params ',' param\n");} 
    | param {printf("params -> param\n");}
    | %empty
;

param:
    SIMPLE_TYPE ID {printf("param -> %s %s\n", $1.body, $2.body);}
;

if_stmt:
    IF '(' expression ')' '{' multiple_stmt '}' {printf("if_stmt -> %s '(' expression_stmt ')' '{' stmt '}'\n", 
                                                    $1.body);}
;

if_else_stmt: 
    IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}' {printf("if_else_stmt -> %s '(' expression_stmt ')' '{' stmt '}' ELSE '{' stmt '}'\n", $1.body);} 
    | IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt
;

for_stmt:
    FOR '(' expression ';' expression ';' expression')' '{' multiple_stmt '}' {printf("for_stmt -> %s '(' expression_stmt ')' '{' stmt '}'\n", $1.body);}
;

return_stmt:
    RETURN ';' {printf("return_stmt -> %s ';'\n", $1.body);}
    | RETURN expression ';' {printf("return_stmt -> %s expression ';'\n", $1.body);}
;

general_declaration:
    general_declaration var_declaration
    | general_declaration list_declaration
    | general_declaration stmt
    | %empty
;

multiple_stmt:
    general_declaration {printf("multiple_stmt -> general_declaration\n");}
;

expression_stmt:
    expression ';' {printf("expression_stmt -> expression ';'\n");}
;

expression:
    ID '=' expression {printf("expression -> %s '=' expression\n", $1.body);}
    | simple_expression {printf("expression -> simple_expression\n");}
    |binary_construct {printf("expression -> binary_construct\n");}
    | ID MAP ID
    | ID FILTER ID
;

stmt:
    expression_stmt {printf("stmt -> expression_stmt\n");}
    | if_stmt {printf("stmt -> if_stmt\n");}
    | if_else_stmt {printf("stmt -> if_else_stmt\n");}
    | for_stmt {printf("stmt -> for_stmt\n");}
    | return_stmt {printf("stmt -> return_stmt\n");}
    | print
    | scan
;


simple_expression:
    arithmetic_expression BINARY_COMP_OP arithmetic_expression {printf("simple_expression -> arithmetic_expression %s arithmetic_expression\n", $2.body);}
    | arithmetic_expression {printf("simple_expression -> arithmetic_expression\n");}
;   

arithmetic_expression:
    arithmetic_expression BINARY_BASIC_OP1 term {printf("arithmetic_expression -> arithmetic_expression %s term\n", $2.body);}
    | BINARY_BASIC_OP1 term {printf("arithmetic_expression -> %s term\n", $1.body);}
    | TAIL term
    | HEADER term
    | term {printf("arithmetic_expression -> term\n");}
;

term: 
    term BINARY_BASIC_OP2 factor {printf("term -> term %s factor\n", $2.body);}
    | factor {printf("term -> factor\n");}
;

factor:
    '(' expression ')' {printf("factor -> '(' expression ')'\n");}
    | ID {printf("factor -> %s\n", $1.body);}
    | INT {printf("factor -> %s\n", $1.body);}
    | FLOAT {printf("factor -> %s\n", $1.body);}
    | ID '(' ID ')' {printf("factor -> %s '(' %s ')'\n", $1.body, $3.body);}
    | LIST_CONSTANT
;

print:
    OUTPUT '(' STRING ')' ';' {printf("print -> %s '(' %s ')' ';'\n", $1.body, $3.body);}
    | OUTPUT '(' expression ')' ';'
;

scan:
    INPUT '(' ID ')' ';' {printf("print -> %s '(' %s ')' ';'\n", $1.body, $3.body);}
;

binary_construct:
    binary_construct_recursive BINARY_CONSTRUCTOR ID {printf("binary_construct -> binary_construct_recursive %s %s\n", $2.body, $3.body);}
;

binary_construct_recursive:
    binary_construct_recursive BINARY_CONSTRUCTOR ID {printf("binary_construct_recursive -> binary_construct_recursive %s %s\n", $2.body, $3.body);}
    | ID {printf("%s\n", $1.body);}
;



%%

void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Erro sintatico: ");
    printf("%s\n"RESET, msg);
}

int main(int argc, char ** argv) {
    FILE *fp = fopen(argv[1], "r");
    if(argc > 1) {
        if(fp) {
            yyin = fp;
            yyparse();
        }
        else {
            printf("File does not exist.\n");
        }
    }
    else {
        printf("No input given.\n");
    }
    fclose(yyin);    
    yylex_destroy();
    return 0;
}