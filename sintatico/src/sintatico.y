%define lr.type canonical-lr
%define parse.error verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"


    #define BRED "\e[0;31m"
    #define BMAG "\e[1;35m"
    #define BCYAN "\x1b[36m"
    #define RESET "\e[0m"

    extern int line;
    extern int columns;
    extern int errors;
    extern int yylex();
    extern int yylex_destroy();
    extern int yyparse();
    void yyerror(const char* msg);
    extern FILE* yyin;

    extern int scope;
    extern symbol symbol_table[100000];
    int table_index = 0;
    int table_size = 0;
    tree* root;
    
%}  

%union{
    struct Token {
        int columns;
        int line;
        char body[101];
    } token;
    tree* node;
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

%type <node> program
%type <node> declaration_list
%type <node> declaration
%type <node> var_declaration
%type <node> function_declaration
%type <node> list_declaration
%type <node> params
%type <node> param
%type <node> if_stmt
%type <node> if_else_stmt
%type <node> for_stmt
%type <node> return_stmt
%type <node> general_declaration
%type <node> multiple_stmt
%type <node> expression_stmt
%type <node> expression
%type <node> stmt
%type <node> simple_expression
%type <node> arithmetic_expression
%type <node> term
%type <node> factor
%type <node> binary_construct
%type <node> binary_construct_recursive
%type <node> print
%type <node> scan

%start program

%%
program: 
    declaration_list { 
        $$ = create_node("program");
        $$->node1 = $1;
        root = $$;
    }
;

declaration_list:
    declaration_list declaration {
        $$ = create_node("declaration_list");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | declaration {
        $$ = $1;
    }
;

declaration:
    var_declaration {$$ = $1;}
    | function_declaration {$$ = $1;} 
    | list_declaration {$$ = $1;}  
    | error {yyerrok;}
;

var_declaration:
    SIMPLE_TYPE ID ';' {
        symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;

        $$ = create_node("var_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
    }
;

function_declaration:
    SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}' {
        symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;   

        $$ = create_node("function_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = $4;
        $$->node4 = $7;
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
        
        $$ = create_node("list_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->node3 = $5;
        $$->node4 = $8;
        
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

        $$ = create_node("list_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
    }
    
;

params:
    params ',' param {
        $$ = create_node("params");
        $$->node1 = $3;
    } 
    | param {$$ = $1;}
    | %empty {
        $$ = create_node("empty");
    }
    | error {yyerrok;}
;

param:
    SIMPLE_TYPE ID {
        $$ = create_node("param");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
    }
;

if_stmt:
    IF '(' expression ')' '{' multiple_stmt '}' {
        $$ = create_node("if_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
    }
;

if_else_stmt: 
    IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->node4 = create_node($8.body);
        $$->node5 = $10;
    }
    | IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->node4 = create_node($8.body);
        $$->node5 = $9;
    }
;

for_stmt:
    FOR '(' expression ';' expression ';' expression ')' '{' multiple_stmt '}' {
        $$ = create_node("for_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = $7;
        $$->node5 = $10;
    }
;

return_stmt:
    RETURN ';' {$$ = create_node($1.body);}
    | RETURN expression ';' {
        $$ = create_node($1.body);
        $$->node1 = $2;
    }
;

general_declaration:
    general_declaration var_declaration {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | general_declaration list_declaration {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | general_declaration stmt {
        $$ = create_node("general_declaration");
        $$->node1 = $1;
        $$->node2 = $2;
    }
    | %empty {
        $$ = create_node("empty");
    }
;

multiple_stmt:
    general_declaration {$$ = $1;} 
;

expression_stmt:
    expression ';' {$$ = $1;}
;

expression:
    ID '=' expression {
        $$ = create_node("expression");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
    } 
    | simple_expression {$$ = $1;}
    | binary_construct {$$ = $1;}
    | ID MAP ID {
        $$ = create_node("expression");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = create_node($3.body);
    }
    | ID FILTER ID {
        $$ = create_node("expression");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = create_node($3.body);
    }
    | error {yyerrok;}
;

stmt:
    expression_stmt {$$ = $1;}
    | if_stmt {$$ = $1;} 
    | if_else_stmt {$$ = $1;} 
    | for_stmt {$$ = $1;}
    | return_stmt {$$ = $1;} 
    | print {$$ = $1;}
    | scan {$$ = $1;}
    | error {yyerrok;}
;


simple_expression:
    arithmetic_expression BINARY_COMP_OP arithmetic_expression {
        $$ = create_node("simple_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
    }
    | arithmetic_expression {$$ = $1;}
;   

arithmetic_expression:
    arithmetic_expression BINARY_BASIC_OP1 term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
    } 
    | BINARY_BASIC_OP1 term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
    }
    | TAIL term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
    }
    | HEADER term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
    }
    | term {$$ = $1;}
;

term: 
    term BINARY_BASIC_OP2 factor {
        $$ = create_node("term");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
    }
    | factor {$$ = $1;}
;

factor:
    '(' expression ')' {$$ = $2;} 
    | ID {$$ = create_node($1.body);}
    | INT {$$ = create_node($1.body);}
    | FLOAT {$$ = create_node($1.body);}
    | ID '(' ID ')' {
        $$ = create_node("factor");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
    } 
    | LIST_CONSTANT {$$ = create_node($1.body);}
;

print:
    OUTPUT '(' STRING ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
    }
    | OUTPUT '(' expression ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
    }
;

scan:
    INPUT '(' ID ')' ';' {
        $$ = create_node("scan");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
    }
;

binary_construct:
    binary_construct_recursive BINARY_CONSTRUCTOR ID {
        $$ = create_node("binary_constructor");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = create_node($3.body);
    } 
;

binary_construct_recursive:
    binary_construct_recursive BINARY_CONSTRUCTOR ID {
        $$ = create_node("binary_constructor_recursive");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = create_node($3.body);
    }
    | ID {$$ = create_node($1.body);}
    | error {yyerrok;}
;


%%

void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Syntax error: ");
    printf("%s\n"RESET, msg);
    errors++;
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
    if(errors == 0){
        printf(BCYAN"No errors detected\n" RESET);
    }
    print_table(table_size);
    print_tree(root, 0);
    free_node(root);
    fclose(yyin);    
    yylex_destroy();
    return 0;
}