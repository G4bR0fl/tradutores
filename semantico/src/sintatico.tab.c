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

    void yyerror(const char* msg);

    int last_element = 0;
    int table_index = 0;
    int table_size = 0;
    tree* root;
    

#line 105 "sintatico.tab.c"

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
  YYSYMBOL_params = 42,                    /* params  */
  YYSYMBOL_param = 43,                     /* param  */
  YYSYMBOL_if_stmt = 44,                   /* if_stmt  */
  YYSYMBOL_if_else_stmt = 45,              /* if_else_stmt  */
  YYSYMBOL_for_stmt = 46,                  /* for_stmt  */
  YYSYMBOL_return_stmt = 47,               /* return_stmt  */
  YYSYMBOL_general_declaration = 48,       /* general_declaration  */
  YYSYMBOL_multiple_stmt = 49,             /* multiple_stmt  */
  YYSYMBOL_expression_stmt = 50,           /* expression_stmt  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_for_variation_null_expressions = 52, /* for_variation_null_expressions  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_simple_expression = 54,         /* simple_expression  */
  YYSYMBOL_relational_expression = 55,     /* relational_expression  */
  YYSYMBOL_arithmetic_expression = 56,     /* arithmetic_expression  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_factor = 58,                    /* factor  */
  YYSYMBOL_print = 59,                     /* print  */
  YYSYMBOL_scan = 60,                      /* scan  */
  YYSYMBOL_binary_construct = 61,          /* binary_construct  */
  YYSYMBOL_binary_construct_recursive = 62, /* binary_construct_recursive  */
  YYSYMBOL_list_operation = 63,            /* list_operation  */
  YYSYMBOL_recursive_list_operation = 64   /* recursive_list_operation  */
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
#define YYLAST   2181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  363

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
       0,   107,   107,   115,   120,   126,   127,   128,   129,   133,
     150,   167,   194,   220,   224,   225,   228,   232,   249,   278,
     287,   295,   306,   317,   318,   325,   330,   335,   340,   346,
     350,   354,   361,   362,   363,   364,   368,   369,   373,   374,
     375,   376,   377,   378,   379,   380,   385,   386,   396,   403,
     407,   414,   420,   426,   432,   436,   443,   447,   448,   452,
     453,   454,   460,   461,   470,   475,   483,   491,   500,   506,
     507,   511,   517,   526,   532,   538
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
  "function_declaration", "list_declaration", "params", "param", "if_stmt",
  "if_else_stmt", "for_stmt", "return_stmt", "general_declaration",
  "multiple_stmt", "expression_stmt", "expression",
  "for_variation_null_expressions", "stmt", "simple_expression",
  "relational_expression", "arithmetic_expression", "term", "factor",
  "print", "scan", "binary_construct", "binary_construct_recursive",
  "list_operation", "recursive_list_operation", YY_NULLPTR
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

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      34,   649,    43,    46,   679,   709,   739,   769,   799,    30,
     159,   -33,   829,   383,   122,   848,   122,   859,   304,   131,
     453,   499,   529,    48,   545,    42,    85,    60,   559,   551,
     575,   551,   581,    61,    76,   485,   152,   223,   307,   460,
      11,    11,   102,   107,   123,    11,  1456,   121,   138,   332,
    1257,   611,   641,   671,   701,   731,   761,   791,   179,   821,
      94,    84,   331,  1281,  1321,   851,   881,   180,   160,   188,
     139,   878,   889,   202,   216,   158,  1361,  1480,   239,   446,
    1488,  1497,  1277,  1257,  1257,   392,   224,   911,   218,   246,
     941,   293,    11,  1297,    11,  1317,   265,   271,   263,   286,
     291,   299,   329,   302,   337,   339,   342,   971,  1505,    10,
    1514,   176,  1522,   371,   370,   -19,    -9,   356,   368,   389,
    1531,   367,   392,  1001,  1031,  1061,   551,   394,   402,   419,
     521,   373,  1234,   408,   551,  1091,   551,   413,   420,  1121,
    1151,    68,  1729,  1737,  1745,   144,   144,   418,   144,  1686,
    1257,   185,   229,  1692,  1753,  1761,   424,   440,   432,   174,
    1181,  1548,  1556,  1565,   221,   221,   454,   221,  1539,  1257,
    1573,  1582,   105,   130,   227,   348,   348,   459,   348,    15,
    1257,   237,   252,  2001,  2011,  2019,   456,   456,   462,   456,
    1257,   606,  1256,  2027,  2035,  1211,   221,   348,  1257,   461,
    1707,  1769,  1777,  1785,  1793,  1257,  1257,   464,  1337,   144,
    1357,   144,  1377,   474,   477,  1590,  1599,  1607,  1616,  1257,
     476,   221,   425,   502,  1381,  1469,  1257,   479,   348,  1981,
    2043,  2051,  2059,  2067,   486,  1397,   456,  1417,   456,  1624,
    1645,   500,   508,   519,  1801,   269,  1833,  1841,  1427,  1427,
     535,  1427,  1671,  1257,   346,  1849,  1857,  1809,    96,   190,
     398,  1433,  1433,   538,  1433,   278,  1257,    69,  1929,  1931,
    1817,  1715,   305,   365,   532,  1633,  1641,   557,  1654,  1658,
    2075,  2104,  2109,  2114,  1443,  1443,   543,  1443,  1991,  1257,
      -7,  2119,  2124,  2083,   363,   396,   510,  1453,  1453,   546,
    1453,   261,  1257,    21,   531,   561,  2091,  2099,  1825,  1865,
    1873,  1881,  1889,  1257,   560,  1427,  1427,  1939,  1943,  1947,
    1955,  1257,   562,  1433,  1433,  1650,  1662,  2129,  2134,  2139,
    2144,  1257,   565,  1443,  1443,   591,   621,   651,   681,  1257,
     568,  1453,  1453,   587,  1897,  1905,  1913,   590,  1957,  1965,
    1969,   592,  2149,  2154,  2159,   595,   711,   741,   771,  1921,
    1973,  2164,   801
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -33,   -33,   528,   549,   -33,   579,   612,   525,   -33,
     -33,   -33,   -33,   -33,   -24,   -33,    -8,   -26,   503,   -28,
     -13,   -27,   182,   -32,   -33,   -33,    -4,    -2,     2,     7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    20,    21,    53,
      54,    55,    56,    32,    33,    57,    58,   106,    59,   151,
     152,   153,   154,   155,    65,    66,   156,   157,   158,   159
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,   -73,   -73,   333,    60,    62,   -48,    34,    64,    64,
     -48,   -74,   -74,    64,   -71,    37,    38,    64,    39,    61,
     196,    60,    62,   -48,   -72,   -58,   -58,   -48,    67,    44,
      68,   341,   -58,    75,    69,     1,    61,     2,   -47,    70,
      50,    88,    89,   -48,   226,    67,    11,    68,   -58,     9,
      64,    69,    13,    64,    60,    62,    70,    60,    62,   171,
      64,   182,   112,   194,   109,    10,   111,   114,   192,    61,
      28,   101,    61,    29,   102,   103,   104,   105,    67,   323,
      68,    67,   191,    68,    69,   -70,   -47,    69,    19,    70,
      64,    31,    70,    71,    60,    62,   127,    91,   -35,   -47,
      64,   -46,   128,   131,    60,    62,   -59,   -59,    72,    61,
     137,   -69,   138,   -59,   105,   -59,   -59,   -46,    67,    61,
      68,   199,   -59,    18,    69,    19,   -59,   -32,    67,    70,
      68,    78,   171,   171,    69,   171,    79,    23,   -59,    70,
     -60,   -60,   207,   182,   182,    80,   182,   -60,   142,   143,
      84,   144,   -15,    24,   194,   194,   -15,   194,    73,    96,
      97,   220,   147,   -60,   171,   182,   200,    85,   -58,   -58,
     -58,   -58,   227,   150,    74,   -58,   256,    95,   269,   270,
     194,   254,   234,   267,   114,   192,   197,    83,    14,   276,
     241,   -58,    15,   -47,   213,   214,   279,   242,   243,   191,
     -60,   -60,   -69,   292,   194,   305,   306,   -60,   290,   -47,
     303,   274,    90,   -33,    63,   -32,   256,   256,   277,   256,
     -60,   -34,    76,    77,    98,   161,   162,    81,   163,   269,
     269,    63,   269,   -59,   -59,   -59,   -59,   -62,   -62,   166,
     -59,   -70,   208,   168,   -62,   314,   -46,   -54,   228,   160,
     169,   107,   292,   292,   -54,   292,   -59,   -35,   322,   -46,
     -62,    99,   -56,   -56,    63,   305,   305,    63,   305,   -56,
     -54,   -58,   -58,   170,   110,   181,   108,   193,   -58,   -59,
     -59,   332,   -59,   256,   346,   -56,   -59,   115,   -58,   -58,
     339,   269,   350,   116,   340,   -58,   195,   161,   162,   -59,
     163,   292,   354,   164,    63,   343,   165,   321,   -58,   305,
     358,   166,   167,   347,    63,   168,   117,   -60,   -60,   -60,
     -60,   118,   169,   351,   -60,   -73,   -73,   201,   202,   119,
     204,   355,   120,    86,   -16,   -71,    37,    38,   -16,    39,
     -60,    92,    40,    93,   -49,    41,   215,   216,   -49,   218,
      44,    45,   172,   173,    46,   174,   315,   222,   223,   -48,
     225,    50,   -31,   -48,   -49,    87,   177,   121,   230,   231,
     179,   233,   -36,   -59,   -59,   122,   -48,   180,   239,   240,
     -59,   -58,   -58,   -58,   -58,   -74,   -74,   -68,   -58,   123,
     255,   257,   268,    86,   193,   -72,    37,    38,   126,    39,
     198,   124,    40,   133,   -67,    41,   -60,   -60,   -62,   -62,
      44,    45,    16,   -60,    46,   -62,    17,   291,   293,   304,
     141,    50,   125,   142,   143,   -37,   144,   129,   -62,   145,
     309,   310,   146,   312,   130,   -51,   228,   147,   148,   136,
     203,   149,   -51,   317,   318,   139,   320,   141,   150,   -37,
     142,   143,   140,   144,   -33,   100,   145,   212,   -51,   146,
     183,   184,   -34,   185,   147,   148,   327,   328,   149,   330,
     -62,   -62,   -62,   -62,   188,   150,   217,   -62,   229,   335,
     336,   224,   338,    25,   232,   190,   -45,    26,   -45,   -45,
     -45,   -36,   -45,   -62,   244,   -45,   272,   345,   -45,   273,
     -45,   -45,   -70,   -45,   -45,   349,   275,   -45,   -45,   278,
     -45,   -45,   -52,   228,   -45,   353,   280,   -45,   -35,   -52,
     -62,   -62,   -19,   357,   -19,   -19,   -19,   -62,   -19,   -14,
     307,   -19,    12,   -14,   -19,   -52,   -19,   -19,   -31,   -19,
     -19,   -54,   342,   -19,   -19,   132,   -19,   -19,   -54,   308,
     -19,    30,   -28,   -19,   -28,   -28,   -28,   311,   -28,    27,
     319,   -28,   325,    26,   -28,   329,   -28,   -28,   337,   -28,
     -28,   -56,   -56,   -28,   -28,   -17,   -28,   -28,   -56,   -17,
     -28,    51,    35,   -28,    36,    37,    38,   326,    39,   -18,
     344,    40,   348,   -18,    41,   352,    42,    43,   356,    44,
      45,   -51,   342,    46,    47,   -13,    48,    49,   -51,   -13,
      50,    52,   -25,   -29,   -25,   -25,   -25,   359,   -25,   235,
     360,   -25,   361,   -46,   -25,   362,   -25,   -25,    22,   -25,
     -25,   -52,   342,   -25,   -25,   135,   -25,   -25,   -52,     0,
     -25,     0,   -26,   -25,   -26,   -26,   -26,     0,   -26,    -8,
      -8,   -26,    -8,     0,   -26,     0,   -26,   -26,     0,   -26,
     -26,   -63,   -63,   -26,   -26,     0,   -26,   -26,   -63,     0,
     -26,     0,   -39,   -26,   -39,   -39,   -39,     0,   -39,    -2,
       1,   -39,     2,     0,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -53,   342,   -39,   -39,     0,   -39,   -39,   -53,     0,
     -39,     0,   -40,   -39,   -40,   -40,   -40,     0,   -40,    -4,
      -4,   -40,    -4,     0,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -57,   -57,   -40,   -40,     0,   -40,   -40,   -57,     0,
     -40,     0,   -41,   -40,   -41,   -41,   -41,     0,   -41,    -5,
      -5,   -41,    -5,     0,   -41,     0,   -41,   -41,     0,   -41,
     -41,   -50,   342,   -41,   -41,     0,   -41,   -41,   -50,     0,
     -41,     0,   -42,   -41,   -42,   -42,   -42,     0,   -42,    -6,
      -6,   -42,    -6,     0,   -42,     0,   -42,   -42,     0,   -42,
     -42,   -55,   -55,   -42,   -42,     0,   -42,   -42,   -55,     0,
     -42,     0,   -38,   -42,   -38,   -38,   -38,     0,   -38,    -7,
      -7,   -38,    -7,     0,   -38,     0,   -38,   -38,     0,   -38,
     -38,   -61,   -61,   -38,   -38,     0,   -38,   -38,   -61,     0,
     -38,     0,   -27,   -38,   -27,   -27,   -27,     0,   -27,    -3,
      -3,   -27,    -3,     0,   -27,     0,   -27,   -27,     0,   -27,
     -27,     0,     0,   -27,   -27,     0,   -27,   -27,    -9,    -9,
     -27,    -9,   -43,   -27,   -43,   -43,   -43,     0,   -43,   -12,
     -12,   -43,   -12,     0,   -43,     0,   -43,   -43,     0,   -43,
     -43,     0,     0,   -43,   -43,     0,   -43,   -43,   -10,   -10,
     -43,   -10,   -44,   -43,   -44,   -44,   -44,     0,   -44,   -11,
     -11,   -44,   -11,     0,   -44,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,   -44,   -44,     0,   -44,   -44,     0,     0,
     -44,     0,   -23,   -44,   -23,   -23,   -23,     0,   -23,     0,
       0,   -23,     0,     0,   -23,     0,   -23,   -23,     0,   -23,
     -23,     0,     0,   -23,   -23,     0,   -23,   -23,     0,     0,
     -23,     0,   -30,   -23,   -30,   -30,   -30,     0,   -30,     0,
       0,   -30,     0,     0,   -30,     0,   -30,   -30,     0,   -30,
     -30,     0,     0,   -30,   -30,     0,   -30,   -30,     0,     0,
     -30,     0,   -24,   -30,   -24,   -24,   -24,     0,   -24,     0,
       0,   -24,     0,     0,   -24,     0,   -24,   -24,     0,   -24,
     -24,     0,     0,   -24,   -24,     0,   -24,   -24,     0,     0,
     -24,     0,   -66,   -24,   -66,   -66,   -66,     0,   -66,     0,
       0,   -66,     0,     0,   -66,     0,   -66,   -66,     0,   -66,
     -66,     0,     0,   -66,   -66,     0,   -66,   -66,     0,     0,
     -66,     0,   -64,   -66,   -64,   -64,   -64,     0,   -64,     0,
       0,   -64,     0,     0,   -64,     0,   -64,   -64,     0,   -64,
     -64,     0,     0,   -64,   -64,     0,   -64,   -64,     0,     0,
     -64,     0,   -65,   -64,   -65,   -65,   -65,     0,   -65,     0,
       0,   -65,     0,     0,   -65,     0,   -65,   -65,     0,   -65,
     -65,     0,     0,   -65,   -65,     0,   -65,   -65,     0,     0,
     -65,     0,   -21,   -65,   -21,   -21,   -21,     0,   -21,     0,
       0,   -21,     0,     0,   -21,     0,   -21,   -21,     0,   -21,
     -21,     0,     0,   -21,   -21,     0,   -21,   -21,     0,     0,
     -21,     0,   -20,   -21,   -20,   -20,   -20,     0,   -20,     0,
       0,   -20,     0,     0,   -20,     0,   -20,   -20,     0,   -20,
     -20,     0,     0,   -20,   -20,     0,   -20,   -20,     0,     0,
     -20,     0,   -22,   -20,   -22,   -22,   -22,     0,   -22,     0,
       0,   -22,     0,     0,   -22,     0,   -22,   -22,     0,   -22,
     -22,     0,     0,   -22,   -22,     0,   -22,   -22,     0,     0,
     -22,     0,    -9,   -22,    -9,    -9,    -9,     0,    -9,     0,
       0,    -9,     0,     0,    -9,     0,    -9,    -9,     0,    -9,
      -9,     0,     0,    -9,    -9,     0,    -9,    -9,     0,     0,
      -9,     0,   -12,    -9,   -12,   -12,   -12,     0,   -12,     0,
       0,   -12,     0,     0,   -12,     0,   -12,   -12,     0,   -12,
     -12,     0,     0,   -12,   -12,    35,   -12,   -12,    37,    38,
     -12,    39,     0,   -12,    40,     0,     0,    41,     0,    42,
      43,     0,    44,    45,     0,     0,    46,    47,   141,    48,
      49,   142,   143,    50,   144,   134,   236,   145,   237,   -49,
     146,     0,     0,   -49,     0,   147,   148,     0,    86,   149,
       0,    37,    38,     0,    39,     0,   150,    40,     0,     0,
      41,   -54,    94,   -54,   -54,    44,    45,     0,   -54,    46,
       0,   172,   173,     0,   174,     0,    50,   175,     0,     0,
     176,     0,     0,     0,   -54,   177,   178,     0,     0,   179,
       0,   183,   184,     0,   185,     0,   180,   186,     0,     0,
     187,   -56,   -56,   -56,   -56,   188,   189,     0,   -56,   113,
       0,   245,   246,     0,   247,     0,   190,   248,     0,     0,
     249,     0,     0,     0,   -56,   250,   251,     0,     0,   252,
       0,   258,   259,     0,   260,     0,   253,   261,     0,     0,
     262,   -51,    94,   -51,   -51,   263,   264,     0,   -51,   265,
       0,   183,   184,     0,   185,     0,   266,   186,     0,     0,
     187,   -63,   -63,     0,   -51,   188,   189,     0,   -63,   271,
       0,   281,   282,     0,   283,     0,   190,   284,     0,     0,
     285,     0,     0,     0,   -63,   286,   287,     0,     0,   288,
       0,   294,   295,     0,   296,     0,   289,   297,     0,     0,
     298,   245,   246,     0,   247,   299,   300,   258,   259,   301,
     260,     0,     0,     0,     0,   250,   302,   281,   282,   252,
     283,   263,     0,     0,     0,   265,   253,   294,   295,     0,
     296,   286,   266,     0,     0,   288,   -58,   -58,   -58,   -58,
       0,   299,   289,   -58,     0,   301,   -75,   -75,     0,   -53,
     228,     0,   302,    82,     0,    83,   -53,     0,     0,   -58,
     -52,    94,   -52,   -52,     0,     0,     0,   -52,   -63,   -63,
     -63,   -63,   -53,     0,     0,   -63,     0,   -53,    94,   -53,
     -53,     0,     0,   -52,   -53,   -57,   -57,   -57,   -57,     0,
       0,   -63,   -57,     0,   -50,    94,   -50,   -50,     0,     0,
     -53,   -50,   -55,   -55,   -55,   -55,     0,     0,   -57,   -55,
       0,   -61,   -61,   -61,   -61,     0,     0,   -50,   -61,   -58,
     -58,     0,   -58,     0,     0,   -55,   -58,     0,   -59,   -59,
       0,   -59,     0,     0,   -61,   -59,   -60,   -60,   219,   -60,
       0,     0,   -58,   -60,     0,   -62,   -62,     0,   -62,     0,
       0,   -59,   -62,   -54,   221,     0,   -54,     0,     0,   -60,
     -54,     0,   -56,   -56,     0,   -56,     0,     0,   -62,   -56,
     -51,   221,     0,   -51,     0,     0,   -54,   -51,     0,   -52,
     221,     0,   -52,     0,     0,   -56,   -52,   -63,   -63,     0,
     -63,     0,     0,   -51,   -63,     0,   -53,   221,     0,   -53,
       0,     0,   -52,   -53,   -50,   221,     0,   -50,     0,     0,
     -63,   -50,     0,   -57,   -57,     0,   -57,     0,     0,   -53,
     -57,   -55,   -55,     0,   -55,   -50,   228,   -50,   -55,     0,
     -61,   -61,   -50,   -61,   -57,   -57,   -57,   -61,   -55,   -55,
       0,   -57,   -61,   -61,   -55,   -55,     0,     0,   -50,   -61,
       0,   -58,   -58,   -61,   -58,     0,     0,   -57,   -58,     0,
       0,   -55,     0,     0,     0,   -61,   -58,   -58,   -58,   -58,
     313,   -58,   209,   -58,   210,   -49,   -75,   -75,     0,   -49,
       0,     0,     0,   205,     0,   206,   -58,   -58,   -58,   -58,
     -58,     0,   -49,     0,   -58,   -58,   -58,   -58,   -58,     0,
       0,     0,   -58,     0,     0,     0,   206,   -58,     0,   -59,
     -59,   -59,   -59,     0,   198,   -67,   -59,   -60,   -60,   -60,
     -60,     0,     0,     0,   -60,   -62,   -62,   -62,   -62,   -59,
       0,     0,   -62,   -54,   211,   -54,   -54,   -60,     0,     0,
     -54,   -56,   -56,   -56,   -56,   -62,     0,     0,   -56,   -51,
     211,   -51,   -51,   -54,     0,     0,   -51,   -52,   211,   -52,
     -52,   -56,     0,     0,   -52,   -63,   -63,   -63,   -63,   -51,
       0,     0,   -63,   -53,   211,   -53,   -53,   -52,     0,     0,
     -53,   -57,   -57,   -57,   -57,   -63,     0,     0,   -57,   -50,
     211,   -50,   -50,   -53,     0,     0,   -50,   -55,   -55,   -55,
     -55,   -57,     0,     0,   -55,   -61,   -61,   -61,   -61,   -50,
       0,     0,   -61,   -60,   -60,     0,   -60,   -55,     0,     0,
     -60,   -62,   -62,     0,   -62,   -61,     0,     0,   -62,   -54,
     316,     0,   -54,   -60,     0,     0,   -54,   -56,   -56,     0,
     -56,   -62,     0,     0,   -56,   -51,   316,     0,   -51,   -54,
       0,     0,   -51,   -52,   316,     0,   -52,   -56,     0,     0,
     -52,   -63,   -63,     0,   -63,   -51,     0,     0,   -63,   -53,
     316,     0,   -53,   -52,     0,     0,   -53,   -57,   -57,     0,
     -57,   -63,     0,     0,   -57,   -50,   316,     0,   -50,   -53,
       0,     0,   -50,   -55,   -55,     0,   -55,   -57,     0,     0,
     -55,   -61,   -61,     0,   -61,   -50,     0,     0,   -61,   -54,
     324,   -56,   -56,   -55,     0,     0,   -54,     0,   -56,   -51,
     324,   -61,     0,   -52,   324,     0,   -51,   -63,   -63,   -54,
     -52,   -56,     0,     0,   -63,   -53,   324,   -57,   -57,   -51,
       0,     0,   -53,   -52,   -57,   -50,   324,   -63,     0,   -55,
     -55,     0,   -50,   -61,   -61,   -53,   -55,   -57,     0,     0,
     -61,   -58,   -58,   -58,   -58,   -50,     0,     0,   -58,   -55,
       0,   -58,   -58,   -61,   -58,     0,     0,     0,   -58,     0,
     198,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,     0,
     331,   -60,   -60,   -60,   -60,     0,     0,     0,   -60,   -62,
     -62,   -62,   -62,     0,     0,     0,   -62,   -54,   238,   -54,
     -54,     0,     0,     0,   -54,   -56,   -56,   -56,   -56,     0,
       0,     0,   -56,   -51,   238,   -51,   -51,     0,     0,     0,
     -51,   -52,   238,   -52,   -52,     0,     0,     0,   -52,   -63,
     -63,   -63,   -63,     0,     0,     0,   -63,   -53,   238,   -53,
     -53,     0,     0,     0,   -53,   -57,   -57,   -57,   -57,     0,
       0,     0,   -57,   -50,   238,   -50,   -50,     0,     0,     0,
     -50,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,   -61,
     -61,   -61,   -61,     0,   -59,   -59,   -61,   -59,     0,   -60,
     -60,   -59,   -60,     0,   -62,   -62,   -60,   -62,     0,   -54,
     334,   -62,   -54,     0,   -56,   -56,   -54,   -56,     0,   -51,
     334,   -56,   -51,     0,   -52,   334,   -51,   -52,     0,   -63,
     -63,   -52,   -63,     0,   -53,   334,   -63,   -53,     0,   -57,
     -57,   -53,   -57,     0,   -50,   334,   -57,   -50,     0,   -55,
     -55,   -50,   -55,     0,   -61,   -61,   -55,   -61,     0,     0,
       0,   -61
};

static const yytype_int16 yycheck[] =
{
      32,    20,    21,    10,    32,    32,    13,    31,    40,    41,
      17,    20,    21,    45,    33,     4,     5,    49,     7,    32,
      10,    49,    49,    13,    33,    10,    11,    17,    32,    18,
      32,    10,    17,    22,    32,     1,    49,     3,    17,    32,
      29,    49,    50,    33,    29,    49,     0,    49,    33,     6,
      82,    49,    22,    85,    82,    82,    49,    85,    85,    91,
      92,    93,    94,    95,    91,    22,    93,    95,    95,    82,
      22,    79,    85,    31,    82,    83,    84,    85,    82,    10,
      82,    85,    95,    85,    82,    17,    17,    85,     3,    82,
     122,    31,    85,    32,   122,   122,   122,    13,    30,    30,
     132,    17,   126,   129,   132,   132,    10,    11,    32,   122,
     134,    17,   136,    17,   122,    10,    11,    33,   122,   132,
     122,   129,    17,     1,   122,     3,    30,    33,   132,   122,
     132,    29,   164,   165,   132,   167,    29,     6,    33,   132,
      10,    11,   150,   175,   176,    22,   178,    17,     4,     5,
      29,     7,    30,    22,   186,   187,    34,   189,     6,    20,
      21,   169,    18,    33,   196,   197,    22,    29,    10,    11,
      12,    13,   180,    29,    22,    17,   208,    17,   210,   211,
     212,   208,   190,   210,   212,   212,    10,    29,    29,   221,
     198,    33,    33,    17,    20,    21,   228,   205,   206,   212,
      10,    11,    17,   235,   236,   237,   238,    17,   235,    33,
     237,   219,    33,    33,    32,    30,   248,   249,   226,   251,
      30,    33,    40,    41,    22,     4,     5,    45,     7,   261,
     262,    49,   264,    10,    11,    12,    13,    10,    11,    18,
      17,    17,    13,    22,    17,   253,    17,    10,    11,    33,
      29,    33,   284,   285,    17,   287,    33,    33,   266,    30,
      33,    22,    10,    11,    82,   297,   298,    85,   300,    17,
      33,    10,    11,    91,    92,    93,    30,    95,    17,    10,
      11,   289,    13,   315,   316,    33,    17,    22,    10,    11,
      29,   323,   324,    22,   302,    17,    33,     4,     5,    30,
       7,   333,   334,    10,   122,   313,    13,    29,    30,   341,
     342,    18,    19,   321,   132,    22,    30,    10,    11,    12,
      13,    30,    29,   331,    17,    20,    21,   145,   146,    30,
     148,   339,    30,     1,    30,    30,     4,     5,    34,     7,
      33,    10,    10,    12,    13,    13,   164,   165,    17,   167,
      18,    19,     4,     5,    22,     7,    10,   175,   176,    13,
     178,    29,    33,    17,    33,    33,    18,    30,   186,   187,
      22,   189,    33,    10,    11,    33,    30,    29,   196,   197,
      17,    10,    11,    12,    13,    20,    21,    17,    17,    33,
     208,   209,   210,     1,   212,    30,     4,     5,    31,     7,
      29,    33,    10,    30,    33,    13,    10,    11,    10,    11,
      18,    19,    29,    17,    22,    17,    33,   235,   236,   237,
       1,    29,    33,     4,     5,    33,     7,    33,    30,    10,
     248,   249,    13,   251,    32,    10,    11,    18,    19,    31,
      22,    22,    17,   261,   262,    32,   264,     1,    29,    30,
       4,     5,    32,     7,    30,     9,    10,    17,    33,    13,
       4,     5,    30,     7,    18,    19,   284,   285,    22,   287,
      10,    11,    12,    13,    18,    29,    22,    17,    22,   297,
     298,    22,   300,    30,    22,    29,     1,    34,     3,     4,
       5,    30,     7,    33,    30,    10,    22,   315,    13,    22,
      15,    16,    17,    18,    19,   323,    30,    22,    23,    30,
      25,    26,    10,    11,    29,   333,    30,    32,    33,    17,
      10,    11,     1,   341,     3,     4,     5,    17,     7,    30,
      30,    10,     4,    34,    13,    33,    15,    16,    30,    18,
      19,    10,    11,    22,    23,    24,    25,    26,    17,    30,
      29,    26,     1,    32,     3,     4,     5,    22,     7,    30,
      22,    10,    30,    34,    13,    22,    15,    16,    22,    18,
      19,    10,    11,    22,    23,    30,    25,    26,    17,    34,
      29,    32,     1,    32,     3,     4,     5,    30,     7,    30,
      30,    10,    30,    34,    13,    30,    15,    16,    30,    18,
      19,    10,    11,    22,    23,    30,    25,    26,    17,    34,
      29,    32,     1,    32,     3,     4,     5,    30,     7,    13,
      30,    10,    30,    17,    13,    30,    15,    16,    16,    18,
      19,    10,    11,    22,    23,   132,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    17,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,     0,     1,
      29,     3,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,     0,     1,
      29,     3,     1,    32,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      29,    -1,     1,    32,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,     1,    25,    26,     4,     5,
      29,     7,    -1,    32,    10,    -1,    -1,    13,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,     1,    25,
      26,     4,     5,    29,     7,    31,    10,    10,    12,    13,
      13,    -1,    -1,    17,    -1,    18,    19,    -1,     1,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    10,    11,    12,    13,    18,    19,    -1,    17,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    -1,    -1,    -1,    33,    18,    19,    -1,    -1,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    10,    11,    12,    13,    18,    19,    -1,    17,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    -1,    -1,    -1,    33,    18,    19,    -1,    -1,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    10,    11,    12,    13,    18,    19,    -1,    17,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    10,    11,    -1,    33,    18,    19,    -1,    17,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,    -1,    -1,    -1,    33,    18,    19,    -1,    -1,    22,
      -1,     4,     5,    -1,     7,    -1,    29,    10,    -1,    -1,
      13,     4,     5,    -1,     7,    18,    19,     4,     5,    22,
       7,    -1,    -1,    -1,    -1,    18,    29,     4,     5,    22,
       7,    18,    -1,    -1,    -1,    22,    29,     4,     5,    -1,
       7,    18,    29,    -1,    -1,    22,    10,    11,    12,    13,
      -1,    18,    29,    17,    -1,    22,    20,    21,    -1,    10,
      11,    -1,    29,    27,    -1,    29,    17,    -1,    -1,    33,
      10,    11,    12,    13,    -1,    -1,    -1,    17,    10,    11,
      12,    13,    33,    -1,    -1,    17,    -1,    10,    11,    12,
      13,    -1,    -1,    33,    17,    10,    11,    12,    13,    -1,
      -1,    33,    17,    -1,    10,    11,    12,    13,    -1,    -1,
      33,    17,    10,    11,    12,    13,    -1,    -1,    33,    17,
      -1,    10,    11,    12,    13,    -1,    -1,    33,    17,    10,
      11,    -1,    13,    -1,    -1,    33,    17,    -1,    10,    11,
      -1,    13,    -1,    -1,    33,    17,    10,    11,    29,    13,
      -1,    -1,    33,    17,    -1,    10,    11,    -1,    13,    -1,
      -1,    33,    17,    10,    11,    -1,    13,    -1,    -1,    33,
      17,    -1,    10,    11,    -1,    13,    -1,    -1,    33,    17,
      10,    11,    -1,    13,    -1,    -1,    33,    17,    -1,    10,
      11,    -1,    13,    -1,    -1,    33,    17,    10,    11,    -1,
      13,    -1,    -1,    33,    17,    -1,    10,    11,    -1,    13,
      -1,    -1,    33,    17,    10,    11,    -1,    13,    -1,    -1,
      33,    17,    -1,    10,    11,    -1,    13,    -1,    -1,    33,
      17,    10,    11,    -1,    13,    10,    11,    33,    17,    -1,
      10,    11,    17,    13,    10,    11,    33,    17,    10,    11,
      -1,    17,    10,    11,    33,    17,    -1,    -1,    33,    17,
      -1,    10,    11,    33,    13,    -1,    -1,    33,    17,    -1,
      -1,    33,    -1,    -1,    -1,    33,    10,    11,    12,    13,
      29,    30,    10,    17,    12,    13,    20,    21,    -1,    17,
      -1,    -1,    -1,    27,    -1,    29,    30,    10,    11,    12,
      13,    -1,    30,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    29,    30,    -1,    10,
      11,    12,    13,    -1,    29,    30,    17,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    10,    11,    12,    13,    30,
      -1,    -1,    17,    10,    11,    12,    13,    30,    -1,    -1,
      17,    10,    11,    12,    13,    30,    -1,    -1,    17,    10,
      11,    12,    13,    30,    -1,    -1,    17,    10,    11,    12,
      13,    30,    -1,    -1,    17,    10,    11,    12,    13,    30,
      -1,    -1,    17,    10,    11,    12,    13,    30,    -1,    -1,
      17,    10,    11,    12,    13,    30,    -1,    -1,    17,    10,
      11,    12,    13,    30,    -1,    -1,    17,    10,    11,    12,
      13,    30,    -1,    -1,    17,    10,    11,    12,    13,    30,
      -1,    -1,    17,    10,    11,    -1,    13,    30,    -1,    -1,
      17,    10,    11,    -1,    13,    30,    -1,    -1,    17,    10,
      11,    -1,    13,    30,    -1,    -1,    17,    10,    11,    -1,
      13,    30,    -1,    -1,    17,    10,    11,    -1,    13,    30,
      -1,    -1,    17,    10,    11,    -1,    13,    30,    -1,    -1,
      17,    10,    11,    -1,    13,    30,    -1,    -1,    17,    10,
      11,    -1,    13,    30,    -1,    -1,    17,    10,    11,    -1,
      13,    30,    -1,    -1,    17,    10,    11,    -1,    13,    30,
      -1,    -1,    17,    10,    11,    -1,    13,    30,    -1,    -1,
      17,    10,    11,    -1,    13,    30,    -1,    -1,    17,    10,
      11,    10,    11,    30,    -1,    -1,    17,    -1,    17,    10,
      11,    30,    -1,    10,    11,    -1,    17,    10,    11,    30,
      17,    30,    -1,    -1,    17,    10,    11,    10,    11,    30,
      -1,    -1,    17,    30,    17,    10,    11,    30,    -1,    10,
      11,    -1,    17,    10,    11,    30,    17,    30,    -1,    -1,
      17,    10,    11,    12,    13,    30,    -1,    -1,    17,    30,
      -1,    10,    11,    30,    13,    -1,    -1,    -1,    17,    -1,
      29,    10,    11,    12,    13,    -1,    -1,    -1,    17,    -1,
      29,    10,    11,    12,    13,    -1,    -1,    -1,    17,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    10,    11,    12,    13,    -1,    -1,    -1,    17,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    10,    11,    12,    13,    -1,    -1,    -1,    17,    10,
      11,    12,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    10,
      11,    17,    13,    -1,    10,    11,    17,    13,    -1,    -1,
      -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    36,    37,    38,    39,    40,    41,     6,
      22,     0,    38,    22,    29,    33,    29,    33,     1,     3,
      42,    43,    42,     6,    22,    30,    34,    30,    22,    31,
      43,    31,    48,    49,    49,     1,     3,     4,     5,     7,
      10,    13,    15,    16,    18,    19,    22,    23,    25,    26,
      29,    39,    41,    44,    45,    46,    47,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    32,    32,     6,    22,    22,    57,    57,    29,    29,
      22,    57,    27,    29,    29,    29,     1,    33,    51,    51,
      33,    13,    10,    12,    11,    17,    20,    21,    22,    22,
       9,    51,    51,    51,    51,    51,    52,    33,    30,    56,
      57,    56,    58,    22,    54,    22,    22,    30,    30,    30,
      30,    30,    33,    33,    33,    33,    31,    52,    49,    33,
      32,    52,    24,    30,    31,    53,    31,    49,    49,    32,
      32,     1,     4,     5,     7,    10,    13,    18,    19,    22,
      29,    54,    55,    56,    57,    58,    61,    62,    63,    64,
      33,     4,     5,     7,    10,    13,    18,    19,    22,    29,
      57,    58,     4,     5,     7,    10,    13,    18,    19,    22,
      29,    57,    58,     4,     5,     7,    10,    13,    18,    19,
      29,    55,    56,    57,    58,    33,    10,    10,    29,    51,
      22,    57,    57,    22,    57,    27,    29,    51,    13,    10,
      12,    11,    17,    20,    21,    57,    57,    22,    57,    29,
      51,    11,    57,    57,    22,    57,    29,    51,    11,    22,
      57,    57,    22,    57,    51,    13,    10,    12,    11,    57,
      57,    51,    51,    51,    30,     4,     5,     7,    10,    13,
      18,    19,    22,    29,    56,    57,    58,    57,     4,     5,
       7,    10,    13,    18,    19,    22,    29,    56,    57,    58,
      58,    22,    22,    22,    51,    30,    58,    51,    30,    58,
      30,     4,     5,     7,    10,    13,    18,    19,    22,    29,
      56,    57,    58,    57,     4,     5,     7,    10,    13,    18,
      19,    22,    29,    56,    57,    58,    58,    30,    30,    57,
      57,    22,    57,    29,    51,    10,    11,    57,    57,    22,
      57,    29,    51,    10,    11,    30,    30,    57,    57,    22,
      57,    29,    51,    10,    11,    57,    57,    22,    57,    29,
      51,    10,    11,    51,    30,    57,    58,    51,    30,    57,
      58,    51,    30,    57,    58,    51,    30,    57,    58,    30,
      30,    30,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    39,
      40,    40,    41,    42,    42,    42,    42,    43,    43,    44,
      45,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    63,    63,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       8,     9,     4,     3,     1,     0,     1,     2,     3,     7,
      11,     9,    11,     2,     3,     2,     2,     2,     0,     1,
       2,     3,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     2,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     4,     1,     2,     5,     5,     5,     3,     3,     1,
       1,     3,     3,     3,     3,     1
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
#line 107 "sintatico.y"
                     { 
        (yyval.node) = create_node("program");
        (yyval.node)->node1 = (yyvsp[0].node);
        root = (yyval.node);
    }
#line 2010 "sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 115 "sintatico.y"
                                 {
        (yyval.node) = create_node("declaration_list");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2020 "sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 120 "sintatico.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2028 "sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 126 "sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2034 "sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 127 "sintatico.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2040 "sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 128 "sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2046 "sintatico.tab.c"
    break;

  case 8: /* declaration: error  */
#line 129 "sintatico.y"
            {yyerrok;}
#line 2052 "sintatico.tab.c"
    break;

  case 9: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 133 "sintatico.y"
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
#line 2071 "sintatico.tab.c"
    break;

  case 10: /* function_declaration: SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 150 "sintatico.y"
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
#line 2093 "sintatico.tab.c"
    break;

  case 11: /* function_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 167 "sintatico.y"
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
#line 2122 "sintatico.tab.c"
    break;

  case 12: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 194 "sintatico.y"
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
#line 2149 "sintatico.tab.c"
    break;

  case 13: /* params: params ',' param  */
#line 220 "sintatico.y"
                     {
        (yyval.node) = create_node("params");
        (yyval.node)->node1 = (yyvsp[0].node);
    }
#line 2158 "sintatico.tab.c"
    break;

  case 14: /* params: param  */
#line 224 "sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2164 "sintatico.tab.c"
    break;

  case 15: /* params: %empty  */
#line 225 "sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2172 "sintatico.tab.c"
    break;

  case 16: /* params: error  */
#line 228 "sintatico.y"
            {yyerrok;}
#line 2178 "sintatico.tab.c"
    break;

  case 17: /* param: SIMPLE_TYPE ID  */
#line 232 "sintatico.y"
                   {
        int create;
        scope++;
        push(&scope_stack, scope);
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
#line 2200 "sintatico.tab.c"
    break;

  case 18: /* param: SIMPLE_TYPE LIST_TYPE ID  */
#line 249 "sintatico.y"
                               {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        int create;
        scope++;
        push(&scope_stack, scope);
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
#line 2231 "sintatico.tab.c"
    break;

  case 19: /* if_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 278 "sintatico.y"
                                                {
        (yyval.node) = create_node("if_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-1].node);
    }
#line 2242 "sintatico.tab.c"
    break;

  case 20: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 287 "sintatico.y"
                                                                           {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-5].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 2255 "sintatico.tab.c"
    break;

  case 21: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt  */
#line 295 "sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-3].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
    }
#line 2268 "sintatico.tab.c"
    break;

  case 22: /* for_stmt: FOR '(' for_variation_null_expressions ';' for_variation_null_expressions ';' for_variation_null_expressions ')' '{' multiple_stmt '}'  */
#line 306 "sintatico.y"
                                                                                                                                           {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-6].node);
        (yyval.node)->node4 = (yyvsp[-4].node);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 2281 "sintatico.tab.c"
    break;

  case 23: /* return_stmt: RETURN ';'  */
#line 317 "sintatico.y"
               {(yyval.node) = create_node((yyvsp[-1].token).body);}
#line 2287 "sintatico.tab.c"
    break;

  case 24: /* return_stmt: RETURN expression ';'  */
#line 318 "sintatico.y"
                            {
        (yyval.node) = create_node((yyvsp[-2].token).body);
        (yyval.node)->node1 = (yyvsp[-1].node);
    }
#line 2296 "sintatico.tab.c"
    break;

  case 25: /* general_declaration: general_declaration var_declaration  */
#line 325 "sintatico.y"
                                        {
        (yyval.node) = create_node("general_declaration -> var_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2306 "sintatico.tab.c"
    break;

  case 26: /* general_declaration: general_declaration list_declaration  */
#line 330 "sintatico.y"
                                           {
        (yyval.node) = create_node("general_declaration -> list_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2316 "sintatico.tab.c"
    break;

  case 27: /* general_declaration: general_declaration stmt  */
#line 335 "sintatico.y"
                               {
        (yyval.node) = create_node("general_declaration -> stmt");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2326 "sintatico.tab.c"
    break;

  case 28: /* general_declaration: %empty  */
#line 340 "sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2334 "sintatico.tab.c"
    break;

  case 29: /* multiple_stmt: general_declaration  */
#line 346 "sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2340 "sintatico.tab.c"
    break;

  case 30: /* expression_stmt: expression ';'  */
#line 350 "sintatico.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 2346 "sintatico.tab.c"
    break;

  case 31: /* expression: ID '=' expression  */
#line 354 "sintatico.y"
                      {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2358 "sintatico.tab.c"
    break;

  case 32: /* expression: simple_expression  */
#line 361 "sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2364 "sintatico.tab.c"
    break;

  case 33: /* expression: binary_construct  */
#line 362 "sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2370 "sintatico.tab.c"
    break;

  case 34: /* expression: list_operation  */
#line 363 "sintatico.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2376 "sintatico.tab.c"
    break;

  case 35: /* expression: error  */
#line 364 "sintatico.y"
            {yyerrok;}
#line 2382 "sintatico.tab.c"
    break;

  case 36: /* for_variation_null_expressions: expression  */
#line 368 "sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2388 "sintatico.tab.c"
    break;

  case 37: /* for_variation_null_expressions: %empty  */
#line 369 "sintatico.y"
            {(yyval.node) = create_node("empty");}
#line 2394 "sintatico.tab.c"
    break;

  case 38: /* stmt: expression_stmt  */
#line 373 "sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2400 "sintatico.tab.c"
    break;

  case 39: /* stmt: if_stmt  */
#line 374 "sintatico.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2406 "sintatico.tab.c"
    break;

  case 40: /* stmt: if_else_stmt  */
#line 375 "sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2412 "sintatico.tab.c"
    break;

  case 41: /* stmt: for_stmt  */
#line 376 "sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2418 "sintatico.tab.c"
    break;

  case 42: /* stmt: return_stmt  */
#line 377 "sintatico.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2424 "sintatico.tab.c"
    break;

  case 43: /* stmt: print  */
#line 378 "sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2430 "sintatico.tab.c"
    break;

  case 44: /* stmt: scan  */
#line 379 "sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2436 "sintatico.tab.c"
    break;

  case 45: /* stmt: error  */
#line 380 "sintatico.y"
            {yyerrok;}
#line 2442 "sintatico.tab.c"
    break;

  case 46: /* simple_expression: relational_expression  */
#line 385 "sintatico.y"
                          {(yyval.node) = (yyvsp[0].node);}
#line 2448 "sintatico.tab.c"
    break;

  case 47: /* simple_expression: arithmetic_expression LOGIC_OP arithmetic_expression  */
#line 386 "sintatico.y"
                                                           {
        (yyval.node) = create_node("simple_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2460 "sintatico.tab.c"
    break;

  case 48: /* relational_expression: relational_expression BINARY_COMP_OP arithmetic_expression  */
#line 396 "sintatico.y"
                                                               {
        (yyval.node) = create_node("relational_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2472 "sintatico.tab.c"
    break;

  case 49: /* relational_expression: arithmetic_expression  */
#line 403 "sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2478 "sintatico.tab.c"
    break;

  case 50: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 407 "sintatico.y"
                                                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2490 "sintatico.tab.c"
    break;

  case 51: /* arithmetic_expression: BINARY_BASIC_OP1 term  */
#line 414 "sintatico.y"
                            {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2501 "sintatico.tab.c"
    break;

  case 52: /* arithmetic_expression: BINARY_COMP_OP term  */
#line 420 "sintatico.y"
                          {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2512 "sintatico.tab.c"
    break;

  case 53: /* arithmetic_expression: TAIL term  */
#line 426 "sintatico.y"
                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2523 "sintatico.tab.c"
    break;

  case 54: /* arithmetic_expression: term  */
#line 432 "sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2529 "sintatico.tab.c"
    break;

  case 55: /* term: term BINARY_BASIC_OP2 factor  */
#line 436 "sintatico.y"
                                 {
        (yyval.node) = create_node("term");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2541 "sintatico.tab.c"
    break;

  case 56: /* term: factor  */
#line 443 "sintatico.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 2547 "sintatico.tab.c"
    break;

  case 57: /* factor: '(' expression ')'  */
#line 447 "sintatico.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2553 "sintatico.tab.c"
    break;

  case 58: /* factor: ID  */
#line 448 "sintatico.y"
         {
        (yyval.node) = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2562 "sintatico.tab.c"
    break;

  case 59: /* factor: INT  */
#line 452 "sintatico.y"
          {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2568 "sintatico.tab.c"
    break;

  case 60: /* factor: FLOAT  */
#line 453 "sintatico.y"
            {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2574 "sintatico.tab.c"
    break;

  case 61: /* factor: ID '(' expression ')'  */
#line 454 "sintatico.y"
                            {
        (yyval.node) = create_node("factor");
        (yyval.node)->node1 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node2 = (yyvsp[-1].node);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2585 "sintatico.tab.c"
    break;

  case 62: /* factor: LIST_CONSTANT  */
#line 460 "sintatico.y"
                    {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2591 "sintatico.tab.c"
    break;

  case 63: /* factor: HEADER ID  */
#line 461 "sintatico.y"
                {
        (yyval.node) = create_node("factor");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = create_node((yyvsp[0].token).body);
        (yyval.node)->var_scope = get_stack_top(&scope_stack);
    }
#line 2602 "sintatico.tab.c"
    break;

  case 64: /* print: OUTPUT '(' STRING ')' ';'  */
#line 470 "sintatico.y"
                              {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2612 "sintatico.tab.c"
    break;

  case 65: /* print: OUTPUT '(' expression ')' ';'  */
#line 475 "sintatico.y"
                                    {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
    }
#line 2622 "sintatico.tab.c"
    break;

  case 66: /* scan: INPUT '(' ID ')' ';'  */
#line 483 "sintatico.y"
                         {
        (yyval.node) = create_node("scan");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2632 "sintatico.tab.c"
    break;

  case 67: /* binary_construct: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 491 "sintatico.y"
                                                     {
        (yyval.node) = create_node("binary_constructor");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2643 "sintatico.tab.c"
    break;

  case 68: /* binary_construct_recursive: binary_construct_recursive BINARY_CONSTRUCTOR simple_expression  */
#line 500 "sintatico.y"
                                                                    {
        (yyval.node) = create_node("binary_constructor_recursive");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
    }
#line 2654 "sintatico.tab.c"
    break;

  case 69: /* binary_construct_recursive: simple_expression  */
#line 506 "sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2660 "sintatico.tab.c"
    break;

  case 70: /* binary_construct_recursive: error  */
#line 507 "sintatico.y"
            {yyerrok;}
#line 2666 "sintatico.tab.c"
    break;

  case 71: /* list_operation: recursive_list_operation MAP ID  */
#line 511 "sintatico.y"
                                    {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2677 "sintatico.tab.c"
    break;

  case 72: /* list_operation: recursive_list_operation FILTER ID  */
#line 517 "sintatico.y"
                                         {
        (yyval.node) = create_node("list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2688 "sintatico.tab.c"
    break;

  case 73: /* recursive_list_operation: recursive_list_operation MAP ID  */
#line 526 "sintatico.y"
                                    {
        (yyval.node) = create_node("recursive_list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);       
    }
#line 2699 "sintatico.tab.c"
    break;

  case 74: /* recursive_list_operation: recursive_list_operation FILTER ID  */
#line 532 "sintatico.y"
                                         {
        (yyval.node) = create_node("recursive_list_operation");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2710 "sintatico.tab.c"
    break;

  case 75: /* recursive_list_operation: ID  */
#line 538 "sintatico.y"
         {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2716 "sintatico.tab.c"
    break;


#line 2720 "sintatico.tab.c"

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

#line 541 "sintatico.y"


void yyerror(const char* msg){
    printf(BRED"(%d|%d) ", line, columns);
    printf("Syntax error: ");
    printf("%s\n"RESET, msg);
    errors++;
}

int main(int argc, char ** argv) {
    init_stack(&scope_stack); 
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
    if(errors == 0){
        printf(BCYAN"No errors detected\n" RESET);
        print_tree(root, 0);
        search_undeclared_node(root, symbol_table, 0);
        free_node(root);
    }
    fclose(yyin);    
    yylex_destroy();
    return 0;
}
