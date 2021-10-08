/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "sintatico.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "../lib/tabela.h"
    #include "../lib/arvore.h"
    #include "../lib/pilha.h"


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
    extern int auxiliary_list[100000];

    void yyerror(const char* msg);

    int last_element = 0;
    int table_index = 0;
    int table_size = 0;
    tree* root;
    

#line 106 "sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SIMPLE_TYPE = 3,                /* SIMPLE_TYPE  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_LIST_TYPE = 6,                  /* LIST_TYPE  */
  YYSYMBOL_LIST_CONSTANT = 7,              /* LIST_CONSTANT  */
  YYSYMBOL_DIGIT = 8,                      /* DIGIT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_BINARY_BASIC_OP1 = 10,          /* BINARY_BASIC_OP1  */
  YYSYMBOL_BINARY_BASIC_OP2 = 11,          /* BINARY_BASIC_OP2  */
  YYSYMBOL_LOGIC_OP = 12,                  /* LOGIC_OP  */
  YYSYMBOL_BINARY_COMP_OP = 13,            /* BINARY_COMP_OP  */
  YYSYMBOL_KEYWORD = 14,                   /* KEYWORD  */
  YYSYMBOL_INPUT = 15,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 16,                    /* OUTPUT  */
  YYSYMBOL_BINARY_CONSTRUCTOR = 17,        /* BINARY_CONSTRUCTOR  */
  YYSYMBOL_HEADER = 18,                    /* HEADER  */
  YYSYMBOL_TAIL = 19,                      /* TAIL  */
  YYSYMBOL_MAP = 20,                       /* MAP  */
  YYSYMBOL_FILTER = 21,                    /* FILTER  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_declaration_list = 37,          /* declaration_list  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_var_declaration = 39,           /* var_declaration  */
  YYSYMBOL_function_declaration = 40,      /* function_declaration  */
  YYSYMBOL_list_declaration = 41,          /* list_declaration  */
  YYSYMBOL_params_list = 42,               /* params_list  */
  YYSYMBOL_params = 43,                    /* params  */
  YYSYMBOL_param = 44,                     /* param  */
  YYSYMBOL_if_else_stmt = 45,              /* if_else_stmt  */
  YYSYMBOL_for_stmt = 46,                  /* for_stmt  */
  YYSYMBOL_return_stmt = 47,               /* return_stmt  */
  YYSYMBOL_general_declaration = 48,       /* general_declaration  */
  YYSYMBOL_multiple_stmt = 49,             /* multiple_stmt  */
  YYSYMBOL_expression_stmt = 50,           /* expression_stmt  */
  YYSYMBOL_for_variation_null_expressions = 51, /* for_variation_null_expressions  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_print = 53,                     /* print  */
  YYSYMBOL_scan = 54,                      /* scan  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_simple_expression = 56,         /* simple_expression  */
  YYSYMBOL_list_operation = 57,            /* list_operation  */
  YYSYMBOL_relational_expression = 58,     /* relational_expression  */
  YYSYMBOL_arithmetic_expression = 59,     /* arithmetic_expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_arguments = 62,                 /* arguments  */
  YYSYMBOL_arguments_list = 63,            /* arguments_list  */
  YYSYMBOL_unary_factor = 64               /* unary_factor  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3021

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  288

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,     2,     2,     2,
      29,    30,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   120,   125,   131,   132,   133,   134,   138,
     155,   172,   199,   225,   226,   232,   238,   239,   243,   260,
     289,   297,   305,   313,   321,   327,   336,   344,   355,   356,
     363,   368,   373,   378,   384,   388,   392,   393,   397,   398,
     399,   400,   401,   402,   403,   408,   413,   421,   429,   436,
     437,   442,   443,   454,   461,   468,   475,   480,   487,   491,
     498,   502,   509,   513,   514,   518,   519,   520,   526,   527,
     531,   536,   540,   541,   547,   552,   557
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SIMPLE_TYPE", "INT",
  "FLOAT", "LIST_TYPE", "LIST_CONSTANT", "DIGIT", "STRING",
  "BINARY_BASIC_OP1", "BINARY_BASIC_OP2", "LOGIC_OP", "BINARY_COMP_OP",
  "KEYWORD", "INPUT", "OUTPUT", "BINARY_CONSTRUCTOR", "HEADER", "TAIL",
  "MAP", "FILTER", "ID", "IF", "ELSE", "FOR", "RETURN", "'='", "'!'",
  "'('", "')'", "'{'", "'}'", "';'", "','", "$accept", "program",
  "declaration_list", "declaration", "var_declaration",
  "function_declaration", "list_declaration", "params_list", "params",
  "param", "if_else_stmt", "for_stmt", "return_stmt",
  "general_declaration", "multiple_stmt", "expression_stmt",
  "for_variation_null_expressions", "stmt", "print", "scan", "expression",
  "simple_expression", "list_operation", "relational_expression",
  "arithmetic_expression", "term", "factor", "arguments", "arguments_list",
  "unary_factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    33,    40,
      41,   123,   125,    59,    44
};
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     101,   285,   141,    10,   349,   369,   377,   411,   428,   -17,
     -21,  -117,   449,   164,     1,   482,     1,   502,   182,   143,
     -15,   183,   190,   -12,    26,   191,    11,    71,    44,   202,
    1387,   208,  1387,  1417,    50,    79,   694,   179,   406,   515,
    2627,   248,    95,   112,   248,   248,  2589,   114,   117,    62,
    2323,  1447,  1477,  1507,  1537,  1567,  1597,  1627,  1657,  1687,
     128,   -11,     8,   154,  2781,  2641,  2655,  2669,   537,   552,
     146,   137,  2613,  2683,   166,   357,  2697,  2711,  2339,    42,
    2323,   204,   162,  1717,   167,   177,  1747,   248,   248,   248,
     248,   248,   248,   248,   186,   180,   188,   221,   223,   209,
     227,   142,   224,   254,   266,  1777,  2725,    12,  2795,    18,
      61,    66,  2739,  2753,   276,   280,   281,  2767,  2355,   567,
     204,  1807,  1837,  1867,   229,  1387,   727,   284,   230,  2130,
    2291,   757,  1387,  1897,   244,  2153,   279,  2176,  1387,  1927,
    1957,  1387,  1987,   291,   296,  2017,  2047,   302,  2823,  2835,
    2847,   300,   300,   300,   169,  2323,     5,    25,  2386,  2979,
    2859,  2871,  2883,  2077,   238,   457,  2400,  2412,  2371,  2371,
    2371,   314,  2323,    -5,    20,  2615,  2562,  2427,  2439,  2454,
    2107,   661,   242,   301,   310,   313,   491,   787,   817,   847,
     877,   907,   937,   312,   316,  2809,  2895,  2907,  2919,  2323,
      42,   321,   300,   300,   300,   300,   300,   300,   300,  2375,
    2466,  2481,  2493,  2355,    42,   326,  2371,  2371,  2371,  2371,
    2371,  2371,  2371,   193,  2307,  2323,   204,   967,   327,   997,
     333,   239,  2931,    32,  2991,    73,    93,   122,  2943,  2955,
     272,   278,  2508,    53,  2574,    56,    58,    67,  2520,  2535,
     335,   338,   343,   344,   348,  1027,  2967,  2547,   350,   361,
     364,  2199,   204,  1057,  1087,  1117,  1387,  1147,   367,   376,
    2222,  2291,  1177,  1387,  1207,   352,  2245,   383,  2268,  1387,
    1237,  1267,  1387,  1297,   389,   390,  1327,  1357
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,   426,   400,  -117,   404,   422,  -117,   415,
     -19,   -10,    -7,  -117,   -32,     0,  -114,  -116,     3,     7,
     -22,   -41,   345,   436,   401,   241,    76,   -61,  -117,   185
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    20,    21,    22,
     187,   188,   189,    33,    34,   190,   103,    57,   191,   192,
     193,    61,    62,    63,    64,    65,    66,   100,   101,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    87,    18,   126,    19,    13,   127,   216,    14,   156,
      11,    60,    15,   133,    53,    26,   134,   202,    28,   139,
     -51,   142,   -49,    54,   -52,   -49,    55,    84,    85,   -49,
     -55,   -14,   -51,    56,   156,   -49,    58,   -51,   173,   156,
      59,   -51,    30,   164,   -52,   -52,   165,   166,    29,   167,
     -51,   -55,   168,    97,   -51,   -51,    98,    99,   102,   104,
     169,   170,   -52,    82,   171,   -52,    38,    39,   -55,    40,
     -53,   172,    41,   -53,    19,    32,   -73,   173,   -54,   -54,
      44,    45,    68,   -52,    46,   -55,   -55,   -52,   -53,   156,
     -55,    50,   -53,   128,   -53,    83,   124,   -54,   104,   -54,
     136,   -54,     1,   -55,     2,   -53,   143,    60,   194,   144,
      53,    69,   254,    60,   156,    60,    53,    73,    53,    54,
      76,    77,    55,   -53,    74,    54,   161,    54,    55,    56,
      55,   156,    58,   201,   -54,    56,    59,    56,    58,   231,
      58,    75,    59,    80,    59,   267,    81,     9,   268,    24,
     215,   161,   -54,   241,   274,   178,   161,   275,   156,   173,
     280,    86,   283,    10,   228,    25,   -56,    88,    94,   113,
     163,    89,   173,   173,    90,    91,   118,   230,    99,   -64,
     -64,   -64,   -64,   156,   156,    70,   -64,   -56,    95,   -64,
     -64,   240,    99,    16,   178,   -50,   199,    17,   200,   -64,
     105,    71,   252,   253,   104,    82,   161,   106,    38,    39,
     114,    40,   -17,   -13,    41,   250,   -17,    27,   115,   180,
     -16,   -18,    44,    45,   -16,   -18,    46,   196,   197,   198,
     156,   161,   -19,    50,   269,   162,   -19,   -37,   -15,   -71,
     104,   277,   -15,   -71,   210,   211,   212,   284,   161,   194,
     285,   116,    38,    39,   119,    40,   -48,   117,    41,   -70,
     162,   -72,   131,   -70,   179,   162,    44,    45,   -50,   256,
      72,   223,   -50,   -72,   137,   161,   178,    50,   161,   161,
     161,   161,   161,   161,   239,    -8,    -8,   120,    -8,   178,
     178,   160,   178,   178,   178,   178,   178,   178,   249,   -36,
     161,   161,   -48,   179,   148,   149,   -48,   150,   257,   121,
     151,   140,   -72,   122,   123,   162,   160,   130,   152,   153,
     177,   160,   195,   145,   -64,   -64,   -64,   -64,   146,   155,
     224,   -64,   -50,   112,   -64,   -64,   162,   162,   162,   225,
     162,   213,   226,   214,   -64,   229,   -36,   161,   -64,    -2,
       1,   232,     2,   179,   179,   179,   242,   162,   147,   177,
     255,   148,   149,   -48,   150,   258,    96,   151,   259,    -4,
      -4,   160,    -4,   260,   261,   152,   153,    -5,    -5,   154,
      -5,   262,   278,   263,   162,   179,   155,   162,   162,   162,
     162,   162,   162,   162,   264,   157,   160,   265,   179,   179,
     271,   179,   179,   179,   179,   179,   179,   179,   272,   162,
     162,    -6,    -6,   160,    -6,   281,   -65,   -65,   -65,   -65,
     157,   286,   287,   -65,   174,   157,   -65,   -65,    -7,    -7,
      12,    -7,   107,    51,   109,   110,   111,    52,    23,   -65,
     160,   177,    31,   160,   160,   160,   160,   160,   238,    -3,
      -3,   159,    -3,     0,   177,   177,   162,   177,   177,   177,
     177,   177,   248,   174,     0,   160,   160,   -65,   -65,   -65,
     -65,     0,     0,     0,   -65,   157,   159,   -65,   -65,     0,
     176,   159,    -9,    -9,     0,    -9,   158,   -65,     0,   108,
       0,   -65,    82,     0,     0,    38,    39,     0,    40,     0,
     157,    41,   -12,   -12,     0,   -12,     0,     0,     0,    44,
      45,   158,   160,    46,     0,   175,   158,   157,     0,   176,
      50,     0,     0,     0,   227,   -66,   -66,   -66,   -66,     0,
       0,   159,   -66,     0,     0,   -66,   -66,   -10,   -10,     0,
     -10,     0,     0,     0,   157,   174,     0,   233,   -66,   235,
     236,   237,   -11,   -11,   175,   -11,   159,     0,   174,   174,
       0,   243,     0,   245,   246,   247,   158,     0,   181,   157,
     157,    38,    39,   159,    40,     0,     0,    41,     0,     0,
       0,     0,   182,   183,     0,    44,    45,     0,     0,    46,
     184,   158,   185,   186,     0,     0,    50,     0,   125,     0,
     159,   176,     0,   159,   234,   159,   159,   159,   158,     0,
       0,     0,     0,     0,   176,   176,   157,   176,   244,   176,
     176,   176,     0,     0,     0,   159,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   175,     0,   158,     0,
     158,   158,   158,     0,     0,     0,     0,     0,     0,   175,
     175,     0,   175,     0,   175,   175,   175,     0,     0,     0,
     158,   158,   -44,     0,   -44,   -44,   -44,     0,   -44,     0,
       0,   -44,   159,     0,     0,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,   -44,   -44,   -44,   -44,   -44,     0,     0,
     -44,     0,     0,   -44,   -50,   -44,     0,   -44,   -44,   -44,
       0,   -44,     0,     0,   -44,     0,     0,   158,     0,   -44,
     -44,     0,   -44,   -44,     0,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,   -44,     0,     0,   -44,   -50,   -25,     0,
     -25,   -25,   -25,     0,   -25,     0,     0,   -25,     0,     0,
       0,     0,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,
     -25,   129,   -25,   -25,     0,     0,   -25,     0,   -24,   -25,
     -24,   -24,   -24,     0,   -24,     0,     0,   -24,     0,     0,
       0,     0,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,
     -24,   135,   -24,   -24,     0,     0,   -24,     0,   -39,   -24,
     -39,   -39,   -39,     0,   -39,     0,     0,   -39,     0,     0,
       0,     0,   -39,   -39,     0,   -39,   -39,     0,     0,   -39,
     -39,   -39,   -39,   -39,     0,     0,   -39,     0,   -40,   -39,
     -40,   -40,   -40,     0,   -40,     0,     0,   -40,     0,     0,
       0,     0,   -40,   -40,     0,   -40,   -40,     0,     0,   -40,
     -40,   -40,   -40,   -40,     0,     0,   -40,     0,   -41,   -40,
     -41,   -41,   -41,     0,   -41,     0,     0,   -41,     0,     0,
       0,     0,   -41,   -41,     0,   -41,   -41,     0,     0,   -41,
     -41,   -41,   -41,   -41,     0,     0,   -41,     0,   -38,   -41,
     -38,   -38,   -38,     0,   -38,     0,     0,   -38,     0,     0,
       0,     0,   -38,   -38,     0,   -38,   -38,     0,     0,   -38,
     -38,   -38,   -38,   -38,     0,     0,   -38,     0,   -42,   -38,
     -42,   -42,   -42,     0,   -42,     0,     0,   -42,     0,     0,
       0,     0,   -42,   -42,     0,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,     0,     0,   -42,     0,   -43,   -42,
     -43,   -43,   -43,     0,   -43,     0,     0,   -43,     0,     0,
       0,     0,   -43,   -43,     0,   -43,   -43,     0,     0,   -43,
     -43,   -43,   -43,   -43,     0,     0,   -43,     0,   -28,   -43,
     -28,   -28,   -28,     0,   -28,     0,     0,   -28,     0,     0,
       0,     0,   -28,   -28,     0,   -28,   -28,     0,     0,   -28,
     -28,   -28,   -28,   -28,     0,     0,   -28,     0,   -35,   -28,
     -35,   -35,   -35,     0,   -35,     0,     0,   -35,     0,     0,
       0,     0,   -35,   -35,     0,   -35,   -35,     0,     0,   -35,
     -35,   -35,   -35,   -35,     0,     0,   -35,     0,   -29,   -35,
     -29,   -29,   -29,     0,   -29,     0,     0,   -29,     0,     0,
       0,     0,   -29,   -29,     0,   -29,   -29,     0,     0,   -29,
     -29,   -29,   -29,   -29,     0,     0,   -29,     0,   -47,   -29,
     -47,   -47,   -47,     0,   -47,     0,     0,   -47,     0,     0,
       0,     0,   -47,   -47,     0,   -47,   -47,     0,     0,   -47,
     -47,   -47,   -47,   -47,     0,     0,   -47,     0,   -45,   -47,
     -45,   -45,   -45,     0,   -45,     0,     0,   -45,     0,     0,
       0,     0,   -45,   -45,     0,   -45,   -45,     0,     0,   -45,
     -45,   -45,   -45,   -45,     0,     0,   -45,     0,   -46,   -45,
     -46,   -46,   -46,     0,   -46,     0,     0,   -46,     0,     0,
       0,     0,   -46,   -46,     0,   -46,   -46,     0,     0,   -46,
     -46,   -46,   -46,   -46,     0,     0,   -46,     0,   -25,   -46,
     -25,   -25,   -25,     0,   -25,     0,     0,   -25,     0,     0,
       0,     0,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,
     -25,   270,   -25,   -25,     0,     0,   -25,     0,   -24,   -25,
     -24,   -24,   -24,     0,   -24,     0,     0,   -24,     0,     0,
       0,     0,   -24,   -24,     0,   -24,   -24,     0,     0,   -24,
     -24,   276,   -24,   -24,     0,     0,   -24,     0,   -23,   -24,
     -23,   -23,   -23,     0,   -23,     0,     0,   -23,     0,     0,
       0,     0,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,
     -23,   -23,   -23,   -23,     0,     0,   -23,     0,   -21,   -23,
     -21,   -21,   -21,     0,   -21,     0,     0,   -21,     0,     0,
       0,     0,   -21,   -21,     0,   -21,   -21,     0,     0,   -21,
     -21,   -21,   -21,   -21,     0,     0,   -21,     0,   -22,   -21,
     -22,   -22,   -22,     0,   -22,     0,     0,   -22,     0,     0,
       0,     0,   -22,   -22,     0,   -22,   -22,     0,     0,   -22,
     -22,   -22,   -22,   -22,     0,     0,   -22,     0,   -27,   -22,
     -27,   -27,   -27,     0,   -27,     0,     0,   -27,     0,     0,
       0,     0,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
     -27,   -27,   -27,   -27,     0,     0,   -27,     0,   -20,   -27,
     -20,   -20,   -20,     0,   -20,     0,     0,   -20,     0,     0,
       0,     0,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,
     -20,   -20,   -20,   -20,     0,     0,   -20,     0,   -26,   -20,
     -26,   -26,   -26,     0,   -26,     0,     0,   -26,     0,     0,
       0,     0,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,
     -26,   -26,   -26,   -26,     0,     0,   -26,     0,   -33,   -26,
     -33,   -33,   -33,     0,   -33,     0,     0,   -33,     0,     0,
       0,     0,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,
     -33,     0,   -33,   -33,     0,     0,   -33,     0,    36,   -33,
      37,    38,    39,     0,    40,     0,     0,    41,     0,     0,
       0,     0,    42,    43,     0,    44,    45,     0,     0,    46,
      47,     0,    48,    49,     0,     0,    50,     0,   -30,   -34,
     -30,   -30,   -30,     0,   -30,     0,     0,   -30,     0,     0,
       0,     0,   -30,   -30,     0,   -30,   -30,     0,     0,   -30,
     -30,     0,   -30,   -30,     0,     0,   -30,     0,   -31,   -30,
     -31,   -31,   -31,     0,   -31,     0,     0,   -31,     0,     0,
       0,     0,   -31,   -31,     0,   -31,   -31,     0,     0,   -31,
     -31,     0,   -31,   -31,     0,     0,   -31,     0,   -39,   -31,
     -39,   -39,   -39,     0,   -39,     0,     0,   -39,     0,     0,
       0,     0,   -39,   -39,     0,   -39,   -39,     0,     0,   -39,
     -39,     0,   -39,   -39,     0,     0,   -39,     0,   -40,   -39,
     -40,   -40,   -40,     0,   -40,     0,     0,   -40,     0,     0,
       0,     0,   -40,   -40,     0,   -40,   -40,     0,     0,   -40,
     -40,     0,   -40,   -40,     0,     0,   -40,     0,   -41,   -40,
     -41,   -41,   -41,     0,   -41,     0,     0,   -41,     0,     0,
       0,     0,   -41,   -41,     0,   -41,   -41,     0,     0,   -41,
     -41,     0,   -41,   -41,     0,     0,   -41,     0,   -38,   -41,
     -38,   -38,   -38,     0,   -38,     0,     0,   -38,     0,     0,
       0,     0,   -38,   -38,     0,   -38,   -38,     0,     0,   -38,
     -38,     0,   -38,   -38,     0,     0,   -38,     0,   -32,   -38,
     -32,   -32,   -32,     0,   -32,     0,     0,   -32,     0,     0,
       0,     0,   -32,   -32,     0,   -32,   -32,     0,     0,   -32,
     -32,     0,   -32,   -32,     0,     0,   -32,     0,   -42,   -32,
     -42,   -42,   -42,     0,   -42,     0,     0,   -42,     0,     0,
       0,     0,   -42,   -42,     0,   -42,   -42,     0,     0,   -42,
     -42,     0,   -42,   -42,     0,     0,   -42,     0,   -43,   -42,
     -43,   -43,   -43,     0,   -43,     0,     0,   -43,     0,     0,
       0,     0,   -43,   -43,     0,   -43,   -43,     0,     0,   -43,
     -43,     0,   -43,   -43,     0,     0,   -43,     0,   -28,   -43,
     -28,   -28,   -28,     0,   -28,     0,     0,   -28,     0,     0,
       0,     0,   -28,   -28,     0,   -28,   -28,     0,     0,   -28,
     -28,     0,   -28,   -28,     0,     0,   -28,     0,   -35,   -28,
     -35,   -35,   -35,     0,   -35,     0,     0,   -35,     0,     0,
       0,     0,   -35,   -35,     0,   -35,   -35,     0,     0,   -35,
     -35,     0,   -35,   -35,     0,     0,   -35,     0,   -29,   -35,
     -29,   -29,   -29,     0,   -29,     0,     0,   -29,     0,     0,
       0,     0,   -29,   -29,     0,   -29,   -29,     0,     0,   -29,
     -29,     0,   -29,   -29,     0,     0,   -29,     0,   -47,   -29,
     -47,   -47,   -47,     0,   -47,     0,     0,   -47,     0,     0,
       0,     0,   -47,   -47,     0,   -47,   -47,     0,     0,   -47,
     -47,     0,   -47,   -47,     0,     0,   -47,     0,   -45,   -47,
     -45,   -45,   -45,     0,   -45,     0,     0,   -45,     0,     0,
       0,     0,   -45,   -45,     0,   -45,   -45,     0,     0,   -45,
     -45,     0,   -45,   -45,     0,     0,   -45,     0,   -46,   -45,
     -46,   -46,   -46,     0,   -46,     0,     0,   -46,     0,     0,
       0,     0,   -46,   -46,     0,   -46,   -46,     0,     0,   -46,
     -46,     0,   -46,   -46,     0,     0,   -46,     0,   -23,   -46,
     -23,   -23,   -23,     0,   -23,     0,     0,   -23,     0,     0,
       0,     0,   -23,   -23,     0,   -23,   -23,     0,     0,   -23,
     -23,     0,   -23,   -23,     0,     0,   -23,     0,   -21,   -23,
     -21,   -21,   -21,     0,   -21,     0,     0,   -21,     0,     0,
       0,     0,   -21,   -21,     0,   -21,   -21,     0,     0,   -21,
     -21,     0,   -21,   -21,     0,     0,   -21,     0,   -22,   -21,
     -22,   -22,   -22,     0,   -22,     0,     0,   -22,     0,     0,
       0,     0,   -22,   -22,     0,   -22,   -22,     0,     0,   -22,
     -22,     0,   -22,   -22,     0,     0,   -22,     0,   -27,   -22,
     -27,   -27,   -27,     0,   -27,     0,     0,   -27,     0,     0,
       0,     0,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
     -27,     0,   -27,   -27,     0,     0,   -27,     0,   -20,   -27,
     -20,   -20,   -20,     0,   -20,     0,     0,   -20,     0,     0,
       0,     0,   -20,   -20,     0,   -20,   -20,     0,     0,   -20,
     -20,     0,   -20,   -20,     0,     0,   -20,     0,   -26,   -20,
     -26,   -26,   -26,     0,   -26,     0,     0,   -26,     0,     0,
       0,     0,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,
     -26,     0,   -26,   -26,     0,     0,   -26,     0,    -9,   -26,
      -9,    -9,    -9,     0,    -9,     0,     0,    -9,     0,     0,
       0,     0,    -9,    -9,     0,    -9,    -9,     0,     0,    -9,
      -9,     0,    -9,    -9,     0,     0,    -9,     0,   -12,    -9,
     -12,   -12,   -12,     0,   -12,     0,     0,   -12,     0,     0,
       0,     0,   -12,   -12,     0,   -12,   -12,     0,     0,   -12,
     -12,    36,   -12,   -12,    38,    39,   -12,    40,     0,   -12,
      41,     0,     0,     0,     0,    42,    43,     0,    44,    45,
       0,     0,    46,    47,    36,    48,    49,    38,    39,    50,
      40,   132,     0,    41,     0,     0,     0,     0,    42,    43,
       0,    44,    45,     0,     0,    46,    47,    36,    48,    49,
      38,    39,    50,    40,   138,     0,    41,     0,     0,     0,
       0,    42,    43,     0,    44,    45,     0,     0,    46,    47,
     181,    48,    49,    38,    39,    50,    40,   141,     0,    41,
       0,     0,     0,     0,   182,   183,     0,    44,    45,     0,
       0,    46,   184,   181,   185,   186,    38,    39,    50,    40,
     266,     0,    41,     0,     0,     0,     0,   182,   183,     0,
      44,    45,     0,     0,    46,   184,   181,   185,   186,    38,
      39,    50,    40,   273,     0,    41,     0,     0,     0,     0,
     182,   183,     0,    44,    45,     0,     0,    46,   184,   181,
     185,   186,    38,    39,    50,    40,   279,     0,    41,     0,
       0,     0,     0,   182,   183,     0,    44,    45,     0,     0,
      46,   184,   147,   185,   186,   148,   149,    50,   150,   282,
       0,   151,     0,     0,     0,     0,     0,     0,   147,   152,
     153,   148,   149,   154,   150,     0,   251,   151,     0,     0,
     155,   -37,     0,     0,   147,   152,   153,   148,   149,   154,
     150,     0,     0,   151,     0,     0,   155,     0,     0,     0,
      82,   152,   153,    38,    39,   154,    40,     0,     0,    41,
       0,     0,   155,     0,     0,     0,   164,    44,    45,   165,
     166,    46,   167,     0,     0,   168,     0,     0,    50,     0,
       0,     0,     0,   169,   170,   165,   166,   171,   167,     0,
       0,   168,     0,     0,   172,   -64,   -64,   -64,   -64,   169,
     170,     0,   -64,   209,     0,   -64,   -64,     0,   -56,   203,
     172,     0,     0,   204,   214,   -64,   205,   206,     0,   -64,
     -66,   -66,   -66,   -66,     0,     0,   -56,   -66,     0,     0,
     -66,   -66,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,
     -66,     0,   -68,   -68,   -66,     0,     0,   -60,   222,   -60,
     -60,     0,   -68,     0,   -60,     0,   -68,   -60,   -60,   -62,
     -62,   -62,   -62,     0,     0,     0,   -62,   -60,     0,   -62,
     -62,   -60,     0,     0,   -69,   -69,   -69,   -69,     0,   -62,
       0,   -69,     0,   -62,   -69,   -69,   -74,   -74,   -74,   -74,
       0,     0,     0,   -74,   -69,     0,   -74,   -74,   -69,     0,
       0,   -76,   -76,   -76,   -76,     0,   -74,     0,   -76,     0,
     -74,   -76,   -76,   -75,   -75,   -75,   -75,     0,     0,     0,
     -75,   -76,     0,   -75,   -75,   -76,     0,     0,   -63,   -63,
     -63,   -63,     0,   -75,     0,   -63,     0,   -75,   -63,   -63,
     -59,   222,   -59,   -59,     0,     0,     0,   -59,   -63,     0,
     -59,   -59,   -63,     0,     0,   -61,   -61,   -61,   -61,     0,
     -59,     0,   -61,     0,   -59,   -61,   -61,   -67,   -67,   -67,
     -67,     0,     0,     0,   -67,   -61,     0,   -67,   -67,   -61,
       0,     0,   221,     0,   -58,   -58,     0,   -67,     0,   -58,
       0,   -67,   -58,   -58,   221,     0,   -57,   -57,     0,     0,
       0,   -57,   -58,     0,   -57,   -57,   -58,     0,     0,   -64,
     -64,   -64,   -64,     0,   -57,     0,   -64,     0,   -57,   -64,
     -64,     0,     0,     0,     0,     0,    78,     0,    79,     0,
       0,     0,   -64,   -64,   -64,   -64,   -64,   -56,   217,     0,
     -64,     0,   218,   -64,   -64,   219,   220,   -68,   -68,   -68,
     -68,     0,    79,     0,   -68,   -56,   -64,   -68,   -68,   -56,
       0,   -60,    93,   -60,   -60,     0,     0,     0,   -60,     0,
     -68,   -60,   -60,     0,     0,   -62,   -62,   -62,   -62,     0,
       0,     0,   -62,     0,   -60,   -62,   -62,     0,     0,   -69,
     -69,   -69,   -69,     0,     0,     0,   -69,     0,   -62,   -69,
     -69,     0,     0,   -74,   -74,   -74,   -74,     0,     0,     0,
     -74,     0,   -69,   -74,   -74,     0,     0,   -76,   -76,   -76,
     -76,     0,     0,     0,   -76,     0,   -74,   -76,   -76,     0,
       0,   -75,   -75,   -75,   -75,     0,     0,     0,   -75,     0,
     -76,   -75,   -75,     0,     0,   -63,   -63,   -63,   -63,     0,
       0,     0,   -63,     0,   -75,   -63,   -63,     0,     0,   -59,
      93,   -59,   -59,     0,     0,     0,   -59,     0,   -63,   -59,
     -59,     0,     0,   -61,   -61,   -61,   -61,     0,     0,     0,
     -61,     0,   -59,   -61,   -61,     0,     0,   -67,   -67,   -67,
     -67,     0,     0,     0,   -67,     0,   -61,   -67,   -67,     0,
       0,    92,     0,   -58,   -58,     0,     0,     0,   -58,     0,
     -67,   -58,   -58,     0,     0,    92,     0,   -57,   -57,     0,
       0,     0,   -57,     0,   -58,   -57,   -57,     0,     0,   -64,
     -64,   -64,   -64,     0,     0,     0,   -64,     0,   -57,   -64,
     -64,     0,     0,   -65,   -65,   -65,   -65,     0,   200,   -64,
     -65,     0,     0,   -65,   -65,   -66,   -66,   -66,   -66,     0,
       0,     0,   -66,   -65,     0,   -66,   -66,   -68,   -68,   -68,
     -68,     0,     0,     0,   -68,   -66,     0,   -68,   -68,   -60,
     208,   -60,   -60,     0,     0,     0,   -60,   -68,     0,   -60,
     -60,   -62,   -62,   -62,   -62,     0,     0,     0,   -62,   -60,
       0,   -62,   -62,   -69,   -69,   -69,   -69,     0,     0,     0,
     -69,   -62,     0,   -69,   -69,   -74,   -74,   -74,   -74,     0,
       0,     0,   -74,   -69,     0,   -74,   -74,   -76,   -76,   -76,
     -76,     0,     0,     0,   -76,   -74,     0,   -76,   -76,   -75,
     -75,   -75,   -75,     0,     0,     0,   -75,   -76,     0,   -75,
     -75,   -63,   -63,   -63,   -63,     0,     0,     0,   -63,   -75,
       0,   -63,   -63,   -59,   208,   -59,   -59,     0,     0,     0,
     -59,   -63,     0,   -59,   -59,   -61,   -61,   -61,   -61,     0,
       0,     0,   -61,   -59,     0,   -61,   -61,   -67,   -67,   -67,
     -67,     0,     0,     0,   -67,   -61,     0,   -67,   -67,   207,
       0,   -58,   -58,     0,     0,     0,   -58,   -67,     0,   -58,
     -58,   207,     0,   -57,   -57,     0,     0,     0,   -57,   -58,
       0,   -57,   -57,     0,     0,     0,     0,     0,     0,     0,
       0,   -57
};

static const yytype_int16 yycheck[] =
{
      32,    12,     1,   119,     3,    22,   120,    12,    29,    50,
       0,    33,    33,   129,    33,    30,   130,    12,    30,   135,
      12,   137,    33,    33,    12,    30,    33,    49,    50,    34,
      12,    30,    12,    33,    75,    30,    33,    12,    79,    80,
      33,    33,    31,     1,    12,    33,     4,     5,    22,     7,
      30,    33,    10,    75,    34,    30,    78,    79,    80,    81,
      18,    19,    30,     1,    22,    12,     4,     5,    12,     7,
      12,    29,    10,    12,     3,    31,    34,   118,    12,    12,
      18,    19,    32,    30,    22,    12,    30,    34,    30,   130,
      34,    29,    34,   125,    33,    33,   118,    30,   120,    33,
     132,    34,     1,    30,     3,    12,   138,   129,   130,   141,
     129,    32,   226,   135,   155,   137,   135,    41,   137,   129,
      44,    45,   129,    30,    29,   135,    50,   137,   135,   129,
     137,   172,   129,   155,    12,   135,   129,   137,   135,   200,
     137,    29,   135,    29,   137,   261,    29,     6,   262,     6,
     172,    75,    30,   214,   270,    79,    80,   271,   199,   200,
     276,    33,   278,    22,   186,    22,    12,    13,    22,    93,
      33,    17,   213,   214,    20,    21,    34,   199,   200,    10,
      11,    12,    13,   224,   225,     6,    17,    33,    22,    20,
      21,   213,   214,    29,   118,    33,    27,    33,    29,    30,
      33,    22,   224,   225,   226,     1,   130,    30,     4,     5,
      30,     7,    30,    30,    10,    22,    34,    34,    30,    33,
      30,    30,    18,    19,    34,    34,    22,   151,   152,   153,
     271,   155,    30,    29,   266,    50,    34,    33,    30,    30,
     262,   273,    34,    34,   168,   169,   170,   279,   172,   271,
     282,    30,     4,     5,    30,     7,    33,    30,    10,    30,
      75,    34,    32,    34,    79,    80,    18,    19,    30,    30,
      22,    29,    34,    34,    30,   199,   200,    29,   202,   203,
     204,   205,   206,   207,   208,     0,     1,    33,     3,   213,
     214,    50,   216,   217,   218,   219,   220,   221,   222,    33,
     224,   225,    30,   118,     4,     5,    34,     7,    30,    33,
      10,    32,    34,    33,    33,   130,    75,    33,    18,    19,
      79,    80,    22,    32,    10,    11,    12,    13,    32,    29,
      29,    17,    30,    92,    20,    21,   151,   152,   153,    29,
     155,    27,    29,    29,    30,    33,    30,   271,    34,     0,
       1,    30,     3,   168,   169,   170,    30,   172,     1,   118,
      33,     4,     5,    30,     7,    30,     9,    10,    30,     0,
       1,   130,     3,    30,    30,    18,    19,     0,     1,    22,
       3,    33,    30,    33,   199,   200,    29,   202,   203,   204,
     205,   206,   207,   208,    33,    50,   155,    33,   213,   214,
      33,   216,   217,   218,   219,   220,   221,   222,    32,   224,
     225,     0,     1,   172,     3,    32,    10,    11,    12,    13,
      75,    32,    32,    17,    79,    80,    20,    21,     0,     1,
       4,     3,    87,    33,    89,    90,    91,    33,    16,    33,
     199,   200,    27,   202,   203,   204,   205,   206,   207,     0,
       1,    50,     3,    -1,   213,   214,   271,   216,   217,   218,
     219,   220,   221,   118,    -1,   224,   225,    10,    11,    12,
      13,    -1,    -1,    -1,    17,   130,    75,    20,    21,    -1,
      79,    80,     0,     1,    -1,     3,    50,    30,    -1,    88,
      -1,    34,     1,    -1,    -1,     4,     5,    -1,     7,    -1,
     155,    10,     0,     1,    -1,     3,    -1,    -1,    -1,    18,
      19,    75,   271,    22,    -1,    79,    80,   172,    -1,   118,
      29,    -1,    -1,    -1,    33,    10,    11,    12,    13,    -1,
      -1,   130,    17,    -1,    -1,    20,    21,     0,     1,    -1,
       3,    -1,    -1,    -1,   199,   200,    -1,   202,    33,   204,
     205,   206,     0,     1,   118,     3,   155,    -1,   213,   214,
      -1,   216,    -1,   218,   219,   220,   130,    -1,     1,   224,
     225,     4,     5,   172,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,   155,    25,    26,    -1,    -1,    29,    -1,    31,    -1,
     199,   200,    -1,   202,   203,   204,   205,   206,   172,    -1,
      -1,    -1,    -1,    -1,   213,   214,   271,   216,   217,   218,
     219,   220,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   200,    -1,   202,    -1,
     204,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,    -1,   216,    -1,   218,   219,   220,    -1,    -1,    -1,
     224,   225,     1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    10,   271,    -1,    -1,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    32,    33,     1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,   271,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    -1,     1,    32,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,     1,    25,    26,     4,     5,    29,     7,    -1,    32,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,     1,    25,    26,     4,     5,    29,
       7,    31,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,     1,    25,    26,
       4,     5,    29,     7,    31,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
       1,    25,    26,     4,     5,    29,     7,    31,    -1,    10,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,     1,    25,    26,     4,     5,    29,     7,
      31,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,     1,    25,    26,     4,
       5,    29,     7,    31,    -1,    10,    -1,    -1,    -1,    -1,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,     1,
      25,    26,     4,     5,    29,     7,    31,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,     1,    25,    26,     4,     5,    29,     7,    31,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,     1,    18,
      19,     4,     5,    22,     7,    -1,     9,    10,    -1,    -1,
      29,    30,    -1,    -1,     1,    18,    19,     4,     5,    22,
       7,    -1,    -1,    10,    -1,    -1,    29,    -1,    -1,    -1,
       1,    18,    19,     4,     5,    22,     7,    -1,    -1,    10,
      -1,    -1,    29,    -1,    -1,    -1,     1,    18,    19,     4,
       5,    22,     7,    -1,    -1,    10,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    18,    19,     4,     5,    22,     7,    -1,
      -1,    10,    -1,    -1,    29,    10,    11,    12,    13,    18,
      19,    -1,    17,    22,    -1,    20,    21,    -1,    12,    13,
      29,    -1,    -1,    17,    29,    30,    20,    21,    -1,    34,
      10,    11,    12,    13,    -1,    -1,    30,    17,    -1,    -1,
      20,    21,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      30,    -1,    20,    21,    34,    -1,    -1,    10,    11,    12,
      13,    -1,    30,    -1,    17,    -1,    34,    20,    21,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,
      21,    34,    -1,    -1,    10,    11,    12,    13,    -1,    30,
      -1,    17,    -1,    34,    20,    21,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    30,    -1,    20,    21,    34,    -1,
      -1,    10,    11,    12,    13,    -1,    30,    -1,    17,    -1,
      34,    20,    21,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    30,    -1,    20,    21,    34,    -1,    -1,    10,    11,
      12,    13,    -1,    30,    -1,    17,    -1,    34,    20,    21,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,
      20,    21,    34,    -1,    -1,    10,    11,    12,    13,    -1,
      30,    -1,    17,    -1,    34,    20,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,    34,
      -1,    -1,    10,    -1,    12,    13,    -1,    30,    -1,    17,
      -1,    34,    20,    21,    10,    -1,    12,    13,    -1,    -1,
      -1,    17,    30,    -1,    20,    21,    34,    -1,    -1,    10,
      11,    12,    13,    -1,    30,    -1,    17,    -1,    34,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    -1,    29,    -1,
      -1,    -1,    33,    10,    11,    12,    13,    12,    13,    -1,
      17,    -1,    17,    20,    21,    20,    21,    10,    11,    12,
      13,    -1,    29,    -1,    17,    30,    33,    20,    21,    34,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,
      33,    20,    21,    -1,    -1,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,
      21,    -1,    -1,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    33,    20,    21,    -1,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    33,    20,    21,    -1,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,
      33,    20,    21,    -1,    -1,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,
      21,    -1,    -1,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    33,    20,    21,    -1,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    33,    20,    21,    -1,
      -1,    10,    -1,    12,    13,    -1,    -1,    -1,    17,    -1,
      33,    20,    21,    -1,    -1,    10,    -1,    12,    13,    -1,
      -1,    -1,    17,    -1,    33,    20,    21,    -1,    -1,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    -1,    33,    20,
      21,    -1,    -1,    10,    11,    12,    13,    -1,    29,    30,
      17,    -1,    -1,    20,    21,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    30,    -1,    20,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,
      21,    10,    11,    12,    13,    -1,    -1,    -1,    17,    30,
      -1,    20,    21,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    30,    -1,    20,    21,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    30,    -1,    20,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,
      21,    10,    11,    12,    13,    -1,    -1,    -1,    17,    30,
      -1,    20,    21,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    30,    -1,    20,    21,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    30,    -1,    20,    21,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    30,    -1,    20,    21,    10,
      -1,    12,    13,    -1,    -1,    -1,    17,    30,    -1,    20,
      21,    10,    -1,    12,    13,    -1,    -1,    -1,    17,    30,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    36,    37,    38,    39,    40,    41,     6,
      22,     0,    38,    22,    29,    33,    29,    33,     1,     3,
      42,    43,    44,    42,     6,    22,    30,    34,    30,    22,
      31,    44,    31,    48,    49,    49,     1,     3,     4,     5,
       7,    10,    15,    16,    18,    19,    22,    23,    25,    26,
      29,    39,    41,    45,    46,    47,    50,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    64,    32,    32,
       6,    22,    22,    61,    29,    29,    61,    61,    27,    29,
      29,    29,     1,    33,    55,    55,    33,    12,    13,    17,
      20,    21,    10,    11,    22,    22,     9,    55,    55,    55,
      62,    63,    55,    51,    55,    33,    30,    57,    59,    57,
      57,    57,    60,    61,    30,    30,    30,    30,    34,    30,
      33,    33,    33,    33,    55,    31,    52,    51,    49,    24,
      33,    32,    31,    52,    51,    24,    49,    30,    31,    52,
      32,    31,    52,    49,    49,    32,    32,     1,     4,     5,
       7,    10,    18,    19,    22,    29,    56,    57,    58,    59,
      60,    61,    64,    33,     1,     4,     5,     7,    10,    18,
      19,    22,    29,    56,    57,    58,    59,    60,    61,    64,
      33,     1,    15,    16,    23,    25,    26,    45,    46,    47,
      50,    53,    54,    55,    55,    22,    61,    61,    61,    27,
      29,    55,    12,    13,    17,    20,    21,    10,    11,    22,
      61,    61,    61,    27,    29,    55,    12,    13,    17,    20,
      21,    10,    11,    29,    29,    29,    29,    33,    55,    33,
      55,    62,    30,    57,    59,    57,    57,    57,    60,    61,
      55,    62,    30,    57,    59,    57,    57,    57,    60,    61,
      22,     9,    55,    55,    51,    33,    30,    30,    30,    30,
      30,    30,    33,    33,    33,    33,    31,    52,    51,    49,
      24,    33,    32,    31,    52,    51,    24,    49,    30,    31,
      52,    32,    31,    52,    49,    49,    32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    39,
      40,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    55,    55,
      55,    56,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       8,     9,     4,     1,     0,     3,     1,     1,     2,     3,
      11,     9,     9,     7,     7,     5,    11,     9,     2,     3,
       2,     2,     2,     0,     1,     2,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     3,     1,
       1,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     4,     1,     1,
       3,     1,     1,     0,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 112 "sintatico.y"
                     { 
        (yyval.node) = create_node("program");
        (yyval.node)->node1 = (yyvsp[0].node);
        root = (yyval.node);
    }
#line 2155 "sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 120 "sintatico.y"
                                 {
        (yyval.node) = create_node("declaration_list");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2165 "sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 125 "sintatico.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2173 "sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 131 "sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2179 "sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 132 "sintatico.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2185 "sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 133 "sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2191 "sintatico.tab.c"
    break;

  case 8: /* declaration: error  */
#line 134 "sintatico.y"
            {yyerrok;}
#line 2197 "sintatico.tab.c"
    break;

  case 9: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 138 "sintatico.y"
                       {
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-1].token).body, get_stack_top(&scope_stack), (yyvsp[-1].token).line, (yyvsp[-1].token).columns);
        if(create == 0){
            symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, (yyvsp[-2].token).body, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        (yyval.node) = create_node("var_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2216 "sintatico.tab.c"
    break;

  case 10: /* function_declaration: SIMPLE_TYPE ID '(' params_list ')' '{' multiple_stmt '}'  */
#line 155 "sintatico.y"
                                                             {
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-6].token).body, get_stack_top(&scope_stack), (yyvsp[-6].token).line, (yyvsp[-6].token).columns);
        if(create == 0){
            symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, (yyvsp[-7].token).body, 1, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;   
        }

        (yyval.node) = create_node("function_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-7].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2238 "sintatico.tab.c"
    break;

  case 11: /* function_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params_list ')' '{' multiple_stmt '}'  */
#line 172 "sintatico.y"
                                                                         {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-6].token).body, get_stack_top(&scope_stack), (yyvsp[-6].token).line, (yyvsp[-6].token).columns);
        if(create == 0){   
            strcpy(str_simple_type, (yyvsp[-8].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-7].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, list_string, 1, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        
        (yyval.node) = create_node("function_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2267 "sintatico.tab.c"
    break;

  case 12: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 199 "sintatico.y"
                                 {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        create = is_duplicated(symbol_table, (yyvsp[-1].token).body, get_stack_top(&scope_stack), (yyvsp[-1].token).line, (yyvsp[-1].token).columns);
        if(create == 0){   
            strcpy(str_simple_type, (yyvsp[-3].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-2].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, list_string, 0, get_stack_top(&scope_stack));
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        (yyval.node) = create_node("list_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2294 "sintatico.tab.c"
    break;

  case 13: /* params_list: params  */
#line 225 "sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2300 "sintatico.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 226 "sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2308 "sintatico.tab.c"
    break;

  case 15: /* params: params ',' param  */
#line 232 "sintatico.y"
                     {
        (yyval.node) = create_node("params");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = (yyvsp[0].node);

    }
#line 2319 "sintatico.tab.c"
    break;

  case 16: /* params: param  */
#line 238 "sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2325 "sintatico.tab.c"
    break;

  case 17: /* params: error  */
#line 239 "sintatico.y"
            {yyerrok;}
#line 2331 "sintatico.tab.c"
    break;

  case 18: /* param: SIMPLE_TYPE ID  */
#line 243 "sintatico.y"
                   {
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, (yyvsp[0].token).body, get_stack_top(&scope_stack), (yyvsp[0].token).line, (yyvsp[0].token).columns);
        if(create == 0){    
            symbol new_symbol = add_symbol((yyvsp[0].token).line, (yyvsp[0].token).columns, (yyvsp[0].token).body, (yyvsp[-1].token).body, 0, get_stack_top(&scope_stack));
            pop(&scope_stack);
            scope--;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }
        (yyval.node) = create_node("param");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = create_node((yyvsp[0].token).body);
    }
#line 2353 "sintatico.tab.c"
    break;

  case 19: /* param: SIMPLE_TYPE LIST_TYPE ID  */
#line 260 "sintatico.y"
                               {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        scope++;
        push(&scope_stack, scope, auxiliary_list);
        create = is_duplicated(symbol_table, (yyvsp[0].token).body, get_stack_top(&scope_stack), (yyvsp[0].token).line, (yyvsp[0].token).columns);
        if(create == 0){
            strcpy(str_simple_type, (yyvsp[-2].token).body);
            strcat(str_simple_type, "\x20");
            strcpy(str_list_type, (yyvsp[-1].token).body);
            strcpy(list_string, strcat(str_simple_type, str_list_type));
            symbol new_symbol = add_symbol((yyvsp[0].token).line, (yyvsp[0].token).columns, (yyvsp[0].token).body, list_string, 0, get_stack_top(&scope_stack));
            pop(&scope_stack);
            scope--;
            symbol_table[table_index] = new_symbol;
            table_index++;
            table_size++;
        }

        (yyval.node) = create_node("param");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2384 "sintatico.tab.c"
    break;

  case 20: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 289 "sintatico.y"
                                                                           {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-5].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 2397 "sintatico.tab.c"
    break;

  case 21: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt  */
#line 297 "sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-3].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
    }
#line 2410 "sintatico.tab.c"
    break;

  case 22: /* if_else_stmt: IF '(' expression ')' stmt ELSE '{' multiple_stmt '}'  */
#line 305 "sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 2423 "sintatico.tab.c"
    break;

  case 23: /* if_else_stmt: IF '(' expression ')' stmt ELSE stmt  */
#line 313 "sintatico.y"
                                           { 
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-2].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
    }
#line 2436 "sintatico.tab.c"
    break;

  case 24: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 321 "sintatico.y"
                                                  {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-1].node);
    }
#line 2447 "sintatico.tab.c"
    break;

  case 25: /* if_else_stmt: IF '(' expression ')' stmt  */
#line 327 "sintatico.y"
                                 {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
        (yyval.node)->node3 = (yyvsp[0].node);    
    }
#line 2458 "sintatico.tab.c"
    break;

  case 26: /* for_stmt: FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' '{' multiple_stmt '}'  */
#line 336 "sintatico.y"
                                                                                                                                           {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-6].node);
        (yyval.node)->node4 = (yyvsp[-4].node);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 2471 "sintatico.tab.c"
    break;

  case 27: /* for_stmt: FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' stmt  */
#line 344 "sintatico.y"
                                                                                                                            {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-2].node);
        (yyval.node)->node5 = (yyvsp[0].node);
    }
#line 2484 "sintatico.tab.c"
    break;

  case 28: /* return_stmt: RETURN ';'  */
#line 355 "sintatico.y"
               {(yyval.node) = create_node((yyvsp[-1].token).body);}
#line 2490 "sintatico.tab.c"
    break;

  case 29: /* return_stmt: RETURN expression ';'  */
#line 356 "sintatico.y"
                            {
        (yyval.node) = create_node((yyvsp[-2].token).body);
        (yyval.node)->node1 = (yyvsp[-1].node);
    }
#line 2499 "sintatico.tab.c"
    break;

  case 30: /* general_declaration: general_declaration var_declaration  */
#line 363 "sintatico.y"
                                        {
        (yyval.node) = create_node("general_declaration -> var_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2509 "sintatico.tab.c"
    break;

  case 31: /* general_declaration: general_declaration list_declaration  */
#line 368 "sintatico.y"
                                           {
        (yyval.node) = create_node("general_declaration -> list_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2519 "sintatico.tab.c"
    break;

  case 32: /* general_declaration: general_declaration stmt  */
#line 373 "sintatico.y"
                               {
        (yyval.node) = create_node("general_declaration -> stmt");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2529 "sintatico.tab.c"
    break;

  case 33: /* general_declaration: %empty  */
#line 378 "sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2537 "sintatico.tab.c"
    break;

  case 34: /* multiple_stmt: general_declaration  */
#line 384 "sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2543 "sintatico.tab.c"
    break;

  case 35: /* expression_stmt: expression ';'  */
#line 388 "sintatico.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 2549 "sintatico.tab.c"
    break;

  case 36: /* for_variation_null_expressions: expression  */
#line 392 "sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2555 "sintatico.tab.c"
    break;

  case 37: /* for_variation_null_expressions: %empty  */
#line 393 "sintatico.y"
            {(yyval.node) = create_node("empty");}
#line 2561 "sintatico.tab.c"
    break;

  case 38: /* stmt: expression_stmt  */
#line 397 "sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2567 "sintatico.tab.c"
    break;

  case 39: /* stmt: if_else_stmt  */
#line 398 "sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2573 "sintatico.tab.c"
    break;

  case 40: /* stmt: for_stmt  */
#line 399 "sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2579 "sintatico.tab.c"
    break;

  case 41: /* stmt: return_stmt  */
#line 400 "sintatico.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2585 "sintatico.tab.c"
    break;

  case 42: /* stmt: print  */
#line 401 "sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2591 "sintatico.tab.c"
    break;

  case 43: /* stmt: scan  */
#line 402 "sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2597 "sintatico.tab.c"
    break;

  case 44: /* stmt: error  */
#line 403 "sintatico.y"
            {yyerrok;}
#line 2603 "sintatico.tab.c"
    break;

  case 45: /* print: OUTPUT '(' STRING ')' ';'  */
#line 408 "sintatico.y"
                              {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2613 "sintatico.tab.c"
    break;

  case 46: /* print: OUTPUT '(' expression ')' ';'  */
#line 413 "sintatico.y"
                                    {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
    }
#line 2623 "sintatico.tab.c"
    break;

  case 47: /* scan: INPUT '(' ID ')' ';'  */
#line 421 "sintatico.y"
                         {
        (yyval.node) = create_node("scan");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2633 "sintatico.tab.c"
    break;

  case 48: /* expression: ID '=' expression  */
#line 429 "sintatico.y"
                      {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2645 "sintatico.tab.c"
    break;

  case 49: /* expression: simple_expression  */
#line 436 "sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2651 "sintatico.tab.c"
    break;

  case 50: /* expression: error  */
#line 437 "sintatico.y"
            {yyerrok;}
#line 2657 "sintatico.tab.c"
    break;

  case 51: /* simple_expression: list_operation  */
#line 442 "sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2663 "sintatico.tab.c"
    break;

  case 52: /* simple_expression: simple_expression LOGIC_OP list_operation  */
#line 443 "sintatico.y"
                                                {
        (yyval.node) = create_node("simple_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2675 "sintatico.tab.c"
    break;

  case 53: /* list_operation: relational_expression MAP list_operation  */
#line 454 "sintatico.y"
                                             {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);     
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2687 "sintatico.tab.c"
    break;

  case 54: /* list_operation: relational_expression FILTER list_operation  */
#line 461 "sintatico.y"
                                                  {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2699 "sintatico.tab.c"
    break;

  case 55: /* list_operation: relational_expression BINARY_CONSTRUCTOR list_operation  */
#line 468 "sintatico.y"
                                                              {
        (yyval.node) = create_node("binary_constructor_recursive");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2711 "sintatico.tab.c"
    break;

  case 56: /* list_operation: relational_expression  */
#line 475 "sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2717 "sintatico.tab.c"
    break;

  case 57: /* relational_expression: relational_expression BINARY_COMP_OP arithmetic_expression  */
#line 480 "sintatico.y"
                                                               {
        (yyval.node) = create_node("relational_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2729 "sintatico.tab.c"
    break;

  case 58: /* relational_expression: arithmetic_expression  */
#line 487 "sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2735 "sintatico.tab.c"
    break;

  case 59: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 491 "sintatico.y"
                                                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2747 "sintatico.tab.c"
    break;

  case 60: /* arithmetic_expression: term  */
#line 498 "sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2753 "sintatico.tab.c"
    break;

  case 61: /* term: term BINARY_BASIC_OP2 factor  */
#line 502 "sintatico.y"
                                 {
        (yyval.node) = create_node("term");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2765 "sintatico.tab.c"
    break;

  case 62: /* term: factor  */
#line 509 "sintatico.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 2771 "sintatico.tab.c"
    break;

  case 63: /* factor: '(' expression ')'  */
#line 513 "sintatico.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2777 "sintatico.tab.c"
    break;

  case 64: /* factor: ID  */
#line 514 "sintatico.y"
         {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2786 "sintatico.tab.c"
    break;

  case 65: /* factor: INT  */
#line 518 "sintatico.y"
          {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2792 "sintatico.tab.c"
    break;

  case 66: /* factor: FLOAT  */
#line 519 "sintatico.y"
            {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2798 "sintatico.tab.c"
    break;

  case 67: /* factor: ID '(' arguments ')'  */
#line 520 "sintatico.y"
                           {
        (yyval.node) = create_node("factor");
        (yyval.node)->node1 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node2 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2809 "sintatico.tab.c"
    break;

  case 68: /* factor: LIST_CONSTANT  */
#line 526 "sintatico.y"
                    {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2815 "sintatico.tab.c"
    break;

  case 69: /* factor: unary_factor  */
#line 527 "sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2821 "sintatico.tab.c"
    break;

  case 70: /* arguments: arguments_list ',' expression  */
#line 531 "sintatico.y"
                                  {
        (yyval.node) = create_node("arguments");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2831 "sintatico.tab.c"
    break;

  case 71: /* arguments: expression  */
#line 536 "sintatico.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2837 "sintatico.tab.c"
    break;

  case 72: /* arguments_list: arguments  */
#line 540 "sintatico.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2843 "sintatico.tab.c"
    break;

  case 73: /* arguments_list: %empty  */
#line 541 "sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2851 "sintatico.tab.c"
    break;

  case 74: /* unary_factor: BINARY_BASIC_OP1 factor  */
#line 547 "sintatico.y"
                            {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2861 "sintatico.tab.c"
    break;

  case 75: /* unary_factor: TAIL factor  */
#line 552 "sintatico.y"
                 {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2871 "sintatico.tab.c"
    break;

  case 76: /* unary_factor: HEADER factor  */
#line 557 "sintatico.y"
                   {
        (yyval.node) = create_node("unary_factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2881 "sintatico.tab.c"
    break;


#line 2885 "sintatico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 564 "sintatico.y"


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
    main_detection(table_size);
    print_table(table_size);
    if(errors == 0){
        // printf(BCYAN"No errors detected\n" RESET);
        print_tree(root, 0);
        // search_undeclared_node(root, symbol_table, 0, &scope_stack);
        free_node(root);
    }
    fclose(yyin);    
    yylex_destroy();
    return 0;
}
