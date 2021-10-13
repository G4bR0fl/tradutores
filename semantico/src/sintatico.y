%define lr.type canonical-lr
%define parse.error verbose
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"
    #include "../lib/pilha.h"
    #include "../lib/semantic_utils.h"

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
    extern FILE* yyin;
    extern int scope;
    extern symbol symbol_table[100000];
    extern pilha scope_stack; 
    extern params param[100000];
    extern int auxiliary_list[100000]; // No clue what this is doing atm, but if taken out it breaks the code.

    void yyerror(const char* msg);

    int main_idx = 0; // used on loops inside main(), at the end of the file;
    int tree_pointer = 0;
    int param_counter = 0; // counts specific function argument;
    int table_index = 0; // Indexes symbol_table;
    int table_size = 0; // Adds up by +1 when a new symbol is added on the symbol_table;
    tree* root; // First tree node(only reachable when the tree complete);
    
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
%token <token> '=' '!' '(' ')' '{' '}'

%type <node> program
%type <node> declaration_list
%type <node> declaration
%type <node> var_declaration
%type <node> function_declaration
%type <node> list_declaration
%type <node> scope_declaration
%type <node> params_list
%type <node> params
%type <node> param
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
%type <node> relational_expression
%type <node> list_operation
%type <node> term
%type <node> factor
%type <node> print
%type <node> scan
%type <node> for_variation_null_expressions
%type <node> unary_factor
%type <node> arguments_list
%type <node> arguments


%precedence ')'
%precedence '}'
%precedence ELSE    

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
        int create;
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        $$ = create_node("var_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack); 

        // strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack);
    }
;

function_declaration:
    SIMPLE_TYPE ID '(' params_list ')' '{' multiple_stmt '}' {
        int create;
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 1, get_stack_top(&scope_stack));
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;   
            param_counter = 0;
        }
        $$ = create_node("function_declaration");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = $4;
        $$->node4 = $7;
        $$->is_function = 1;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        // strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack);
    }
    | SIMPLE_TYPE LIST_TYPE ID '(' params_list ')' '{' multiple_stmt '}' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){   
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 1, get_stack_top(&scope_stack));
            new_symbol.function_params = param_counter;
            new_symbol.param = param;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
            param_counter = 0;
        }
        
        $$ = create_node("function_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->node3 = $5;
        $$->node4 = $8;
        $$->is_function = 1;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);

        // strcpy($$->node2->type, list_string);
        assign_types($$->node2, symbol_table, &scope_stack);
    }
;

list_declaration: 
    SIMPLE_TYPE LIST_TYPE ID ';' {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){   
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        $$ = create_node("list_declaration");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        
        strcpy($$->node2->type, list_string);
        assign_types($$->node2, symbol_table ,&scope_stack);
    }   
;

scope_declaration:
    '{' multiple_stmt '}' {
        $$ = create_node("scope_declaration");
        $$->node1 = $2;
        $$->var_scope = get_stack_top(&scope_stack);
    }
;

params_list: 
    params {$$ = $1;}
    | %empty {
        $$ = create_node("empty");
    }
;

params:
    params ',' param {
        $$ = create_node("params");
        $$->node1 = $1;
        $$->node2 = $3;

    } 
    | param {
        $$ = create_node("params");
        $$->node1 = $1;
    }   
    | error {yyerrok;}
;

param:
    SIMPLE_TYPE ID {
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, $2.body, get_stack_top(&scope_stack), $2.line, $2.columns);
        if(create == 0){    
            strcpy(param[param_counter].argument_type, $1.body);
            param_counter++;
            symbol new_symbol = add_symbol($2.line, $2.columns, $2.body, $1.body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        $$ = create_node("param");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->var_scope = get_stack_top(&scope_stack);
        // strcpy($$->node2->type, $1.body);
        assign_types($$->node2, symbol_table, &scope_stack);
        $$->node2->line = $2.line;
        $$->node2->column = $2.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        pop(&scope_stack);
        scope--;
    }
    | SIMPLE_TYPE LIST_TYPE ID {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, $3.body, get_stack_top(&scope_stack), $3.line, $3.columns);
        if(create == 0){
            // Concatenating SIMPLE_TYPE + LIST_TYPE
            strcpy(str_simple_type, $1.body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, $2.body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            // End of concatenation
            strcpy(param[param_counter].argument_type, list_string);
            param_counter++;
            symbol new_symbol = add_symbol($3.line, $3.columns, $3.body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        $$ = create_node("param");
        $$->node1 = create_node(list_string);
        $$->node2 = create_node($3.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        assign_types($$->node2, symbol_table, &scope_stack);
        pop(&scope_stack);
        scope--;
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
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->node4 = create_node($8.body);
        $$->node5 = $9;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt ELSE '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = create_node($6.body);
        $$->node5 = $8;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt ELSE stmt { 
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = create_node($6.body);
        $$->node5 = $7;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' '{' multiple_stmt '}' {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $6;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | IF '(' expression ')' stmt {
        $$ = create_node("if_else_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->line = $1.line;
        $$->column = $1.columns;    
    }
;

for_stmt:
    FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' '{' multiple_stmt '}' {
        $$ = create_node("for_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = $7;
        $$->node5 = $10;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' stmt {
        $$ = create_node("for_stmt");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->node3 = $5;
        $$->node4 = $7;
        $$->node5 = $9;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
;

return_stmt:
    RETURN ';' {$$ = create_node($1.body);}
    | RETURN expression ';' {
        $$ = create_node($1.body);
        $$->node1 = $2;
        $$->line = $1.line;
        $$->column = $1.columns;
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
    | general_declaration scope_declaration{
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

for_variation_null_expressions:
    expression {$$ = $1;}
    | %empty{$$ = create_node("empty");}
;

stmt:
    expression_stmt {$$ = $1;}
    | if_else_stmt {$$ = $1;} 
    | for_stmt {$$ = $1;}
    | return_stmt {$$ = $1;} 
    | print {$$ = $1;}
    | scan {$$ = $1;}
    | error {yyerrok;}
;


print:
    OUTPUT '(' STRING ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | OUTPUT '(' expression ')' ';' {
        $$ = create_node("print");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->line = $1.line;
        $$->column = $1.columns;
        evaluate_read_write($$, $$->node2);
    }
;

scan:
    INPUT '(' ID ')' ';' {
        $$ = create_node("scan");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($3.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node2->line = $3.line;
        $$->node2->column = $3.columns;
        $$->node2->var_scope = get_stack_top(&scope_stack);
        assign_types($$->node2, symbol_table, &scope_stack);
        search_undeclared_node($$->node2, symbol_table, &scope_stack);
        evaluate_read_write($$, $$->node2);
    }
;

expression:
    ID '=' expression {
        $$ = create_node("expression");
        $$->node1 = create_node($1.body);
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node1->line = $1.line;
        $$->node1->column = $1.columns;
        $$->node1->var_scope = get_stack_top(&scope_stack);

        search_undeclared_node($$->node1, symbol_table, &scope_stack);
        assign_types($$->node1, symbol_table, &scope_stack);

    } 
    | simple_expression {$$ = $1;}
    | error {yyerrok;}
;


simple_expression: 
    list_operation {$$ = $1;}
    | simple_expression LOGIC_OP list_operation {
        $$ = create_node("simple_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
    }
;   


list_operation:
    relational_expression MAP list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
    }
    | relational_expression FILTER list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
    }
    | relational_expression BINARY_CONSTRUCTOR list_operation {
        $$ = create_node("list_operation");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
    }
    | relational_expression {$$ = $1;}
;

 
relational_expression:
    relational_expression BINARY_COMP_OP arithmetic_expression {
        $$ = create_node("relational_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;
    }
    | arithmetic_expression {$$ = $1;}
;

arithmetic_expression:
    arithmetic_expression BINARY_BASIC_OP1 term {
        $$ = create_node("arithmetic_expression");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_arithmetic($$->node1, $$, $$->node3);
    } 
    | term {$$ = $1;}
;

term: 
    term BINARY_BASIC_OP2 factor {
        $$ = create_node("term");
        $$->node1 = $1;
        $$->node2 = create_node($2.body);
        $$->node3 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $2.line;
        $$->column = $2.columns;

        evaluate_mult_div($$->node1, $$, $$->node3);
    }
    | factor {$$ = $1;}
;

factor:
    '(' expression ')' {$$ = $2;} 
    | ID {
        $$ = create_node($1.body);
        $$->var_scope = get_stack_top(&scope_stack);
        $$->line = $1.line;
        $$->column = $1.columns;

        search_undeclared_node($$, symbol_table, &scope_stack);
        assign_types($$, symbol_table, &scope_stack);
    }
    | INT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "int"); 
    }
    | FLOAT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "float");
    }
    | ID '(' arguments ')' {
        $$ = create_node("factor_arguments");
        $$->node1 = create_node($1.body);
        $$->node2 = $3;
        $$->var_scope = get_stack_top(&scope_stack);
        $$->node1->line = $1.line;
        $$->node1->column = $1.columns;

        search_undeclared_node($$->node1, symbol_table, &scope_stack);
        assign_types($$->node1, symbol_table, &scope_stack);
    } 
    | LIST_CONSTANT {
        $$ = create_node($1.body);
        $$->line = $1.line;
        $$->column = $1.columns;
        $$->var_scope = get_stack_top(&scope_stack);
        strcpy($$->type, "NIL");
    }
    | unary_factor {$$ = $1;}
;

arguments:
    arguments_list ',' expression {
        $$ = create_node("arguments");
        $$->node1 = $1;
        $$->node2 = $3; 
    } 
    | expression {
        $$ = create_node("arguments");
        $$->node1 = $1;
    }
;

arguments_list: 
    arguments {$$ = $1;}
    | %empty {
        $$ = create_node("empty");
    }
;

unary_factor:
    BINARY_BASIC_OP1 factor {
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->line = $1.line;
        $$->column = $1.columns;
    }
    | TAIL factor{
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->line = $1.line;
        $$->column = $1.columns;
    } 
    | HEADER factor{
        $$ = create_node("unary_factor");
        $$->node1 = create_node($1.body);
        $$->node2 = $2;
        $$->line = $1.line;
        $$->column = $1.columns;
    } 
;

%%

void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Syntax error: ");
    printf("%s\n"RESET, msg);
    errors++;
}

int main(int argc, char ** argv) {
    init_stack(&scope_stack);
    init_aux_list(auxiliary_list);
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

    // search_undeclared_node(root, symbol_table, 0, &scope_stack);
    print_table(table_size);
    if(errors == 0){
        printf(BCYAN"No sintatic errors detected. Printing tree and throwing possible semantic errors.\n" RESET);
        function_param_amount(root, symbol_table, 0, &tree_pointer);
        main_detection(table_size);
        print_tree(root, 0);
        free_node(root);
    }
    fclose(yyin);    
    yylex_destroy();

    return 0;
}