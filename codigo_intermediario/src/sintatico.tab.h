/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SRC_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SIMPLE_TYPE = 258,             /* SIMPLE_TYPE  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    LIST_TYPE = 261,               /* LIST_TYPE  */
    LIST_CONSTANT = 262,           /* LIST_CONSTANT  */
    DIGIT = 263,                   /* DIGIT  */
    STRING = 264,                  /* STRING  */
    BINARY_BASIC_OP1 = 265,        /* BINARY_BASIC_OP1  */
    BINARY_BASIC_OP2 = 266,        /* BINARY_BASIC_OP2  */
    LOGIC_OP = 267,                /* LOGIC_OP  */
    BINARY_COMP_OP = 268,          /* BINARY_COMP_OP  */
    KEYWORD = 269,                 /* KEYWORD  */
    INPUT = 270,                   /* INPUT  */
    OUTPUT = 271,                  /* OUTPUT  */
    BINARY_CONSTRUCTOR = 272,      /* BINARY_CONSTRUCTOR  */
    HEADER = 273,                  /* HEADER  */
    TAIL = 274,                    /* TAIL  */
    MAP = 275,                     /* MAP  */
    FILTER = 276,                  /* FILTER  */
    ID = 277,                      /* ID  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    RETURN = 281                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "src/sintatico.y"

    struct Token {
        int columns;
        int line;
        char body[101];
    } token;
    tree* node;

#line 99 "src/sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_SINTATICO_TAB_H_INCLUDED  */
