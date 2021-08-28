%option noinput nounput
%option noyywrap 

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define BRED "\e[0;31m"
    #define BMAG "\e[1;35m"
    #define RESET "\e[0m"

    int line = 1;
    int columns = 1;
    int errors = 0;

%}

SIMPLE_TYPE         int|float

LIST_TYPE           list

LIST_CONSTANT       NIL              

DIGIT               [0-9]

STRING              (\"([^(\"\')])*\")

ID                  [a-zA-Z_][a-z0-9A-Z_]*

BINARY_BASIC_OP     [+*/-]

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
    printf("(%d:%d) Simple type: "BMAG "%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{LIST_TYPE} {
    printf("(%d:%d) List type: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{LIST_CONSTANT} {
    printf("(%d:%d) Constant NIL: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{DIGIT}+ {
    printf("(%d:%d) Integer: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{DIGIT}+"."{DIGIT}+ {
    printf("(%d:%d) Float: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{STRING} {
    printf("(%d:%d) String: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{BINARY_BASIC_OP} {
    printf("(%d:%d) Binary basic operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{LOGIC_OP} {
    printf("(%d:%d) Logical operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{BINARY_COMP_OP} {
    printf("(%d:%d) Binary comparative operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{KEYWORD} {
    printf("(%d:%d) Keyword: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{INPUT} {
    printf("(%d:%d) Input: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{OUTPUT} {
    printf("(%d:%d) Output: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{BINARY_CONSTRUCTOR} {
    printf("(%d:%d) Binary Constructor: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{HEADER} {
    printf("(%d:%d) List Header operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{TAIL} {
    printf("(%d:%d) List Tail operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{MAP} {
    printf("(%d:%d) Map operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{FILTER} {
    printf("(%d:%d) Filter Operator: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

{ID} {
    printf("(%d:%d) Identifier: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}


";" {
    printf("(%d:%d) Semi Colon: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

"," {
    printf("(%d:%d) Colon: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

"=" {
    printf("(%d:%d) Assignment: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

"{"|"}" {
    printf("(%d:%d) Curly Brackets: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

"("|")" {
    printf("(%d:%d) Parenthesis: "BMAG"%s\n"RESET, line, columns, yytext);
    columns += yyleng;
}

[ \t]+ {
    columns += yyleng;
}

\n {
    line++;
    columns = 1;
}

. {
    errors++;
    printf(BRED"(%d:%d)Unidentified character: '%s'\n" RESET, line, columns, yytext);
    columns += yyleng;
}

%%

int main(int argc, char ** argv) {
    FILE *fp = fopen(argv[1], "r");
    if(argc > 1) {
        if(fp) {
            yyin = fp;
            yylex();
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