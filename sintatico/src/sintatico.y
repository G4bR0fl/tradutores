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

    extern int scope;
    extern symbol symbol_table[100000];
    int table_index = 0;
    int table_size = 0;
    
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
    declaration_list
;

declaration_list:
    declaration_list declaration 
    | declaration
;

declaration:
    var_declaration 
    | function_declaration 
    | list_declaration 
;

var_declaration:
    SIMPLE_TYPE ID ';' {
        // printf("var_declaration -> %s %s ';'\n", $1.body, $2.body);
        symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
        
    }
;

function_declaration:
    SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}' {
        symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
        
    }
;

list_declaration: 
    SIMPLE_TYPE LIST_TYPE ID ';' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        strcpy(str_simple_type, $1.body);
        strcat(str_simple_type, "\x20");
        strcpy(str_list_type, $2.body);
        strcpy(list_string, strcat(str_simple_type, str_list_type));
        symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
       
    }
    | SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        strcpy(str_simple_type, $1.body);
        strcat(str_simple_type, "\x20");
        strcpy(str_list_type, $2.body);
        strcpy(list_string, strcat(str_simple_type, str_list_type));
        symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
        
    }
;

params:
    params ',' param
    | param
    | %empty
;

param:
    SIMPLE_TYPE ID 
;

if_stmt:
    IF '(' expression ')' '{' multiple_stmt '}' 
;

if_else_stmt: 
    IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}' 
    | IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt
;

for_stmt:
    FOR '(' expression ';' expression ';' expression')' '{' multiple_stmt '}'
;

return_stmt:
    RETURN ';' 
    | RETURN expression ';'
;

general_declaration:
    general_declaration var_declaration
    | general_declaration list_declaration
    | general_declaration stmt
    | %empty
;

multiple_stmt:
    general_declaration 
;

expression_stmt:
    expression ';' 
;

expression:
    ID '=' expression 
    | simple_expression 
    |binary_construct
    | ID MAP ID
    | ID FILTER ID
;

stmt:
    expression_stmt
    | if_stmt 
    | if_else_stmt 
    | for_stmt
    | return_stmt 
    | print
    | scan
;


simple_expression:
    arithmetic_expression BINARY_COMP_OP arithmetic_expression 
    | arithmetic_expression
;   

arithmetic_expression:
    arithmetic_expression BINARY_BASIC_OP1 term 
    | BINARY_BASIC_OP1 term 
    | TAIL term
    | HEADER term
    | term 
;

term: 
    term BINARY_BASIC_OP2 factor
    | factor
;

factor:
    '(' expression ')' 
    | ID 
    | INT 
    | FLOAT 
    | ID '(' ID ')' 
    | LIST_CONSTANT
;

print:
    OUTPUT '(' STRING ')' ';' 
    | OUTPUT '(' expression ')' ';'
;

scan:
    INPUT '(' ID ')' ';' 
;

binary_construct:
    binary_construct_recursive BINARY_CONSTRUCTOR ID 
;

binary_construct_recursive:
    binary_construct_recursive BINARY_CONSTRUCTOR ID 
    | ID 
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
    print_table(table_size);
    fclose(yyin);    
    yylex_destroy();
    return 0;
}