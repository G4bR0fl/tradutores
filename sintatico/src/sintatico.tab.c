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
#line 3 "src/sintatico.y"

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

#line 92 "src/sintatico.tab.c"

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
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_declaration_list = 36,          /* declaration_list  */
  YYSYMBOL_declaration = 37,               /* declaration  */
  YYSYMBOL_var_declaration = 38,           /* var_declaration  */
  YYSYMBOL_function_declaration = 39,      /* function_declaration  */
  YYSYMBOL_list_declaration = 40,          /* list_declaration  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_if_stmt = 43,                   /* if_stmt  */
  YYSYMBOL_if_else_stmt = 44,              /* if_else_stmt  */
  YYSYMBOL_for_stmt = 45,                  /* for_stmt  */
  YYSYMBOL_return_stmt = 46,               /* return_stmt  */
  YYSYMBOL_general_declaration = 47,       /* general_declaration  */
  YYSYMBOL_multiple_stmt = 48,             /* multiple_stmt  */
  YYSYMBOL_expression_stmt = 49,           /* expression_stmt  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_stmt = 51,                      /* stmt  */
  YYSYMBOL_simple_expression = 52,         /* simple_expression  */
  YYSYMBOL_arithmetic_expression = 53,     /* arithmetic_expression  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_factor = 55,                    /* factor  */
  YYSYMBOL_print = 56,                     /* print  */
  YYSYMBOL_scan = 57,                      /* scan  */
  YYSYMBOL_binary_construct = 58,          /* binary_construct  */
  YYSYMBOL_binary_construct_recursive = 59 /* binary_construct_recursive  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    64,    65,    69,    70,    71,    75,    85,
      89,    90,    95,    96,    97,   101,   105,   110,   111,   115,
     119,   120,   124,   125,   126,   127,   131,   135,   139,   140,
     141,   142,   143,   147,   148,   149,   150,   151,   152,   153,
     158,   159,   163,   164,   165,   166,   167,   171,   172,   176,
     177,   178,   179,   180,   181,   185,   186,   190,   194,   198,
     199
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
  "MAP", "FILTER", "ID", "IF", "ELSE", "FOR", "RETURN", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'='", "$accept", "program",
  "declaration_list", "declaration", "var_declaration",
  "function_declaration", "list_declaration", "params", "param", "if_stmt",
  "if_else_stmt", "for_stmt", "return_stmt", "general_declaration",
  "multiple_stmt", "expression_stmt", "expression", "stmt",
  "simple_expression", "arithmetic_expression", "term", "factor", "print",
  "scan", "binary_construct", "binary_construct_recursive", YY_NULLPTR
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
     275,   276,   277,   278,   279,   280,   281,    59,    40,    41,
     123,   125,    44,    61
};
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,     0,    19,    88,   122,   131,   142,   163,     6,   162,
     -40,   239,   197,   246,    13,   268,    13,    18,   271,   275,
     297,   304,    21,    55,    39,   225,   326,   225,   254,    40,
      49,    59,   101,  1023,  1030,     3,    76,    95,     3,     3,
     999,    99,   121,   128,   951,   283,   312,   341,   370,   399,
     428,   457,   124,   486,   138,   613,  1042,  1048,   515,   544,
     156,   178,   362,   384,   174,   980,  1052,   190,   944,  1057,
    1061,   194,   209,   233,   970,   951,   970,   573,   218,   231,
     602,     3,   977,     3,   262,   249,   260,   284,   270,   291,
     303,   315,   318,   334,   631,  1067,  1072,    -9,  1076,   164,
     344,   349,   363,  1080,   361,   970,   660,   689,   718,   225,
     367,   369,   951,   195,   376,   917,   383,   225,   747,   225,
     389,   392,   776,   805,   407,    65,    73,   193,    16,    16,
      16,  1018,   951,   405,    14,   223,   252,   413,   431,   834,
      50,   227,   256,    42,    42,    42,   165,   951,   285,   314,
      42,   247,   151,   281,   310,   339,   423,   427,   436,   951,
     434,    16,   996,    16,   449,   343,   372,   401,   452,   448,
      42,   430,   863,    13,   458,   463,   470,   471,   368,   397,
      86,   186,   484,   166,   166,   166,     4,   951,     1,   487,
     513,   426,    92,   474,   459,   633,   387,   455,   516,   542,
     545,   456,   477,   166,   166,   641,   422,   478,   571,   574,
     600,   225,   603,   450,   892
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   507,   493,   -40,   500,   -13,   492,   -40,
     -40,   -40,   -40,   -40,   -27,   -40,   -39,   414,    -2,    25,
      24,   -26,   -40,   -40,    11,    67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,     7,    18,    19,    47,
      48,    49,    50,    28,    29,    51,    52,    53,   133,   134,
     135,   136,    58,    59,   137,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   150,    57,    20,    78,    79,     8,    32,    33,    57,
      34,   203,    57,    57,   -50,   -50,    17,    57,   -40,    10,
     125,   126,     9,   127,   161,    65,    54,   162,    12,    87,
     -40,    44,   201,   -50,     1,    91,    92,    93,   152,    60,
      21,    54,   -14,   -41,   132,   -14,   140,   141,    57,   142,
      57,    25,    56,    55,    60,    57,   149,    98,    17,    66,
     -51,   -51,    69,    70,   146,   124,   110,    56,    55,    27,
     147,    62,    54,   114,    54,   -51,   -51,   -51,   -51,    57,
      63,    64,   111,   -52,   -52,    60,   -52,    60,    -2,    57,
     120,     1,   121,   160,   -51,    61,   -51,   -51,    56,    55,
      56,    55,   -52,    54,    67,    96,   148,    97,   169,   -59,
      61,   -51,   -51,    54,   -51,   -51,    60,   149,   149,   149,
     177,   -58,    -4,    68,   149,    -4,    60,    75,   -51,    56,
      55,    -5,    32,    33,    -5,    34,   190,   191,    35,    56,
      55,    61,    -6,    61,   195,    -6,    38,    39,   202,    76,
      40,    80,   153,   154,   155,    77,    44,   190,   190,   190,
     196,   -50,   -50,    -7,   -50,   -29,    -7,   165,   166,   167,
     180,   181,    61,   182,   171,   -50,   -50,   190,   210,   158,
     -50,   -59,    61,   -30,   213,   179,   189,   188,   186,    13,
      14,   -58,   -50,   168,   187,    84,   -52,   -52,   -16,   -16,
     -16,   139,   -16,   -54,   -54,   -16,   -54,   198,   199,   200,
     -16,   -16,    85,   -16,   -16,   -52,    88,   -16,   -16,   115,
     -16,   -16,   -54,   -16,    15,    16,   -16,   209,   -25,   -25,
     -25,    89,   -25,   -46,   163,   -25,   -46,   -52,   -52,    -3,
     -25,   -25,    -3,   -25,   -25,    94,    -8,   -25,   -25,    -8,
     -25,   -25,   -46,   -25,   -52,    90,   -25,    31,    32,    33,
      95,    34,   -48,   -48,    35,   -48,   -54,   -54,   -10,    36,
      37,   -10,    38,    39,   172,   173,    40,    41,   100,    42,
      43,   -48,    44,   -54,    99,   -26,   -22,   -22,   -22,   101,
     -22,   -43,   163,   -22,   -43,   -46,   170,   -31,   -22,   -22,
      22,   -22,   -22,    23,   -13,   -22,   -22,   -13,   -22,   -22,
     -43,   -22,   -46,   102,   -22,   -23,   -23,   -23,   -32,   -23,
     -45,   163,   -23,   -45,   -48,   -48,    24,   -23,   -23,    23,
     -23,   -23,   103,   -15,   -23,   -23,   -15,   -23,   -23,   -45,
     -23,   -48,   -28,   -23,   -34,   -34,   -34,   104,   -34,   -44,
     163,   -34,   -44,   -43,   170,   -12,   -34,   -34,   -12,   -34,
     -34,   105,    -9,   -34,   -34,    -9,   -34,   -34,   -44,   -34,
     -43,   106,   -34,   -35,   -35,   -35,   107,   -35,   -49,   -49,
     -35,   -49,   -45,   170,   -11,   -35,   -35,   -11,   -35,   -35,
     108,   109,   -35,   -35,   112,   -35,   -35,   -49,   -35,   -45,
     113,   -35,   -36,   -36,   -36,   116,   -36,   -42,   163,   -36,
     -42,   -44,   170,   119,   -36,   -36,   206,   -36,   -36,    23,
     122,   -36,   -36,   123,   -36,   -36,   -42,   -36,   -44,   151,
     -36,   -37,   -37,   -37,   -29,   -37,   -47,   -47,   -37,   -47,
     -42,   170,   -30,   -37,   -37,   174,   -37,   -37,   164,   175,
     -37,   -37,   211,   -37,   -37,   -47,   -37,   -42,   176,   -37,
     -33,   -33,   -33,   178,   -33,   -53,   -53,   -33,   -53,   -49,
     -49,   192,   -33,   -33,   193,   -33,   -33,   194,   207,   -33,
     -33,   214,   -33,   -33,   -53,   -33,   -49,   -31,   -33,   -24,
     -24,   -24,   -32,   -24,   -54,   -54,   -24,   -46,   204,   197,
     -28,   -24,   -24,   205,   -24,   -24,   208,   212,   -24,   -24,
      11,   -24,   -24,   -54,   -24,    26,   -46,   -24,   -38,   -38,
     -38,    45,   -38,   -48,   -48,   -38,   -43,   204,    46,   118,
     -38,   -38,     0,   -38,   -38,     0,     0,   -38,   -38,     0,
     -38,   -38,   -48,   -38,     0,   -43,   -38,   -39,   -39,   -39,
       0,   -39,   -45,   204,   -39,   -44,   204,     0,     0,   -39,
     -39,     0,   -39,   -39,     0,     0,   -39,   -39,     0,   -39,
     -39,   -45,   -39,     0,   -44,   -39,   -20,   -20,   -20,     0,
     -20,   -49,   -49,   -20,   -42,   204,     0,     0,   -20,   -20,
       0,   -20,   -20,     0,     0,   -20,   -20,     0,   -20,   -20,
     -49,   -20,     0,   -42,   -20,   -27,   -27,   -27,     0,   -27,
     -47,   -47,   -27,   -53,   -53,     0,     0,   -27,   -27,     0,
     -27,   -27,     0,    81,   -27,   -27,    82,   -27,   -27,   -47,
     -27,     0,   -53,   -27,   -21,   -21,   -21,     0,   -21,     0,
     -41,   -21,     0,   -47,   -47,     0,   -21,   -21,     0,   -21,
     -21,   -53,   -53,   -21,   -21,     0,   -21,   -21,     0,   -21,
     -47,     0,   -21,   -57,   -57,   -57,     0,   -57,   -53,     0,
     -57,     0,     0,     0,     0,   -57,   -57,     0,   -57,   -57,
       0,     0,   -57,   -57,     0,   -57,   -57,     0,   -57,     0,
       0,   -57,   -55,   -55,   -55,     0,   -55,     0,     0,   -55,
       0,     0,     0,     0,   -55,   -55,     0,   -55,   -55,     0,
       0,   -55,   -55,     0,   -55,   -55,     0,   -55,     0,     0,
     -55,   -56,   -56,   -56,     0,   -56,     0,     0,   -56,     0,
       0,     0,     0,   -56,   -56,     0,   -56,   -56,     0,     0,
     -56,   -56,     0,   -56,   -56,     0,   -56,     0,     0,   -56,
     -18,   -18,   -18,     0,   -18,     0,     0,   -18,     0,     0,
       0,     0,   -18,   -18,     0,   -18,   -18,     0,     0,   -18,
     -18,     0,   -18,   -18,     0,   -18,     0,     0,   -18,   -17,
     -17,   -17,     0,   -17,     0,     0,   -17,     0,     0,     0,
       0,   -17,   -17,     0,   -17,   -17,     0,     0,   -17,   -17,
       0,   -17,   -17,     0,   -17,     0,     0,   -17,   -19,   -19,
     -19,     0,   -19,     0,     0,   -19,     0,     0,     0,     0,
     -19,   -19,     0,   -19,   -19,     0,     0,   -19,   -19,     0,
     -19,   -19,     0,   -19,     0,     0,   -19,    -8,    -8,    -8,
       0,    -8,     0,     0,    -8,     0,     0,     0,     0,    -8,
      -8,     0,    -8,    -8,     0,     0,    -8,    -8,     0,    -8,
      -8,     0,    -8,     0,     0,    -8,   -10,   -10,   -10,     0,
     -10,     0,     0,   -10,     0,     0,     0,     0,   -10,   -10,
       0,   -10,   -10,     0,     0,   -10,   -10,     0,   -10,   -10,
       0,   -10,     0,     0,   -10,   -11,   -11,   -11,     0,   -11,
       0,     0,   -11,     0,     0,     0,     0,   -11,   -11,     0,
     -11,   -11,     0,     0,   -11,   -11,     0,   -11,   -11,     0,
     -11,    32,    33,   -11,    34,     0,     0,    35,     0,     0,
       0,     0,    36,    37,     0,    38,    39,     0,     0,    40,
      41,     0,    42,    43,     0,    44,     0,   117,   125,   126,
       0,   127,     0,    86,   128,   125,   126,     0,   127,     0,
       0,   128,   129,   130,     0,     0,   131,     0,     0,   129,
     130,     0,   132,   131,    32,    33,     0,    34,     0,   132,
      35,   140,   141,     0,   142,     0,     0,   143,    38,    39,
     -50,   -50,    40,   -50,     0,   144,   145,     0,    44,   146,
     180,   181,     0,   182,     0,   147,   183,   -50,    73,   -50,
     -50,     0,   -50,     0,   184,   185,   -60,     0,   186,    71,
      72,     0,     0,     0,   187,     0,   -50,    73,   -50,   -50,
       0,   -50,    74,   -52,   -52,   -60,   -52,     0,   156,   157,
     -54,   -54,     0,   -54,     0,     0,   158,   -50,     0,     0,
     -52,   159,   -46,    83,     0,   -46,     0,   -54,   -48,   -48,
       0,   -48,   -43,    83,     0,   -43,     0,   -45,    83,   -46,
     -45,   -44,    83,     0,   -44,   -48,     0,   -49,   -49,   -43,
     -49,     0,   -42,    83,   -45,   -42,   -47,   -47,   -44,   -47,
     -53,   -53,     0,   -53,   -49,     0,     0,     0,     0,   -42,
       0,     0,     0,   -47,     0,     0,     0,   -53
};

static const yytype_int16 yycheck[] =
{
      27,    10,    28,    16,    43,    44,     6,     4,     5,    35,
       7,    10,    38,    39,    10,    11,     3,    43,    27,     0,
       4,     5,    22,     7,    10,    22,    28,    13,    22,    68,
      29,    28,    28,    29,     3,    74,    75,    76,    22,    28,
      22,    43,    29,    29,    28,    32,     4,     5,    74,     7,
      76,    30,    28,    28,    43,    81,    82,    83,     3,    35,
      10,    11,    38,    39,    22,     6,   105,    43,    43,    30,
      28,    31,    74,   112,    76,    10,    11,    27,    13,   105,
      31,    22,   109,    10,    11,    74,    13,    76,     0,   115,
     117,     3,   119,   132,    29,    28,    10,    11,    74,    74,
      76,    76,    29,   105,    28,    81,    82,    82,   147,    17,
      43,    10,    11,   115,    13,    29,   105,   143,   144,   145,
     159,    29,     0,    28,   150,     3,   115,    28,    27,   105,
     105,     0,     4,     5,     3,     7,   162,   163,    10,   115,
     115,    74,     0,    76,   170,     3,    18,    19,   187,    28,
      22,    27,   128,   129,   130,    27,    28,   183,   184,   185,
     173,    10,    11,     0,    13,    27,     3,   143,   144,   145,
       4,     5,   105,     7,   150,    10,    11,   203,   204,    28,
      29,    17,   115,    27,   211,   161,   162,   162,    22,    27,
      28,    27,    27,    28,    28,    17,    10,    11,     3,     4,
       5,    27,     7,    10,    11,    10,    13,   183,   184,   185,
      15,    16,    22,    18,    19,    29,    22,    22,    23,    24,
      25,    26,    29,    28,    27,    28,    31,   203,     3,     4,
       5,    22,     7,    10,    11,    10,    13,    10,    11,     0,
      15,    16,     3,    18,    19,    27,     0,    22,    23,     3,
      25,    26,    29,    28,    27,    22,    31,     3,     4,     5,
      29,     7,    10,    11,    10,    13,    10,    11,     0,    15,
      16,     3,    18,    19,    27,    28,    22,    23,    29,    25,
      26,    29,    28,    27,    22,    31,     3,     4,     5,    29,
       7,    10,    11,    10,    13,    10,    11,    27,    15,    16,
      29,    18,    19,    32,    29,    22,    23,    32,    25,    26,
      29,    28,    27,    29,    31,     3,     4,     5,    27,     7,
      10,    11,    10,    13,    10,    11,    29,    15,    16,    32,
      18,    19,    29,    29,    22,    23,    32,    25,    26,    29,
      28,    27,    27,    31,     3,     4,     5,    29,     7,    10,
      11,    10,    13,    10,    11,    29,    15,    16,    32,    18,
      19,    27,     0,    22,    23,     3,    25,    26,    29,    28,
      27,    27,    31,     3,     4,     5,    27,     7,    10,    11,
      10,    13,    10,    11,     0,    15,    16,     3,    18,    19,
      27,    30,    22,    23,    27,    25,    26,    29,    28,    27,
      31,    31,     3,     4,     5,    29,     7,    10,    11,    10,
      13,    10,    11,    30,    15,    16,    29,    18,    19,    32,
      31,    22,    23,    31,    25,    26,    29,    28,    27,    22,
      31,     3,     4,     5,    29,     7,    10,    11,    10,    13,
      10,    11,    29,    15,    16,    22,    18,    19,    17,    22,
      22,    23,    30,    25,    26,    29,    28,    27,    22,    31,
       3,     4,     5,    29,     7,    10,    11,    10,    13,    10,
      11,    22,    15,    16,    22,    18,    19,    29,    22,    22,
      23,    31,    25,    26,    29,    28,    27,    29,    31,     3,
       4,     5,    29,     7,    10,    11,    10,    10,    11,    29,
      29,    15,    16,    29,    18,    19,    29,    29,    22,    23,
       3,    25,    26,    29,    28,    23,    29,    31,     3,     4,
       5,    28,     7,    10,    11,    10,    10,    11,    28,   115,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      25,    26,    29,    28,    -1,    29,    31,     3,     4,     5,
      -1,     7,    10,    11,    10,    10,    11,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    29,    28,    -1,    29,    31,     3,     4,     5,    -1,
       7,    10,    11,    10,    10,    11,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,    26,
      29,    28,    -1,    29,    31,     3,     4,     5,    -1,     7,
      10,    11,    10,    10,    11,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    10,    22,    23,    13,    25,    26,    29,
      28,    -1,    29,    31,     3,     4,     5,    -1,     7,    -1,
      27,    10,    -1,    10,    11,    -1,    15,    16,    -1,    18,
      19,    10,    11,    22,    23,    -1,    25,    26,    -1,    28,
      27,    -1,    31,     3,     4,     5,    -1,     7,    27,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    31,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,
      31,     3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    31,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    31,     3,
       4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    31,     3,     4,
       5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      15,    16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    31,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    28,    -1,    -1,    31,     3,     4,     5,    -1,
       7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    31,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      28,     4,     5,    31,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    30,     4,     5,
      -1,     7,    -1,     9,    10,     4,     5,    -1,     7,    -1,
      -1,    10,    18,    19,    -1,    -1,    22,    -1,    -1,    18,
      19,    -1,    28,    22,     4,     5,    -1,     7,    -1,    28,
      10,     4,     5,    -1,     7,    -1,    -1,    10,    18,    19,
      10,    11,    22,    13,    -1,    18,    19,    -1,    28,    22,
       4,     5,    -1,     7,    -1,    28,    10,    27,    28,    10,
      11,    -1,    13,    -1,    18,    19,    17,    -1,    22,    20,
      21,    -1,    -1,    -1,    28,    -1,    27,    28,    10,    11,
      -1,    13,    33,    10,    11,    17,    13,    -1,    20,    21,
      10,    11,    -1,    13,    -1,    -1,    28,    29,    -1,    -1,
      27,    33,    10,    11,    -1,    13,    -1,    27,    10,    11,
      -1,    13,    10,    11,    -1,    13,    -1,    10,    11,    27,
      13,    10,    11,    -1,    13,    27,    -1,    10,    11,    27,
      13,    -1,    10,    11,    27,    13,    10,    11,    27,    13,
      10,    11,    -1,    13,    27,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,    36,    37,    38,    39,    40,     6,    22,
       0,    37,    22,    27,    28,    27,    28,     3,    41,    42,
      41,    22,    29,    32,    29,    30,    42,    30,    47,    48,
      48,     3,     4,     5,     7,    10,    15,    16,    18,    19,
      22,    23,    25,    26,    28,    38,    40,    43,    44,    45,
      46,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    31,    31,    22,    22,    54,    28,    28,    54,
      54,    20,    21,    28,    33,    28,    28,    27,    50,    50,
      27,    10,    13,    11,    17,    22,     9,    50,    22,    22,
      22,    50,    50,    50,    27,    29,    54,    53,    55,    22,
      29,    29,    29,    29,    29,    27,    27,    27,    27,    30,
      50,    48,    27,    31,    50,    24,    29,    30,    51,    30,
      48,    48,    31,    31,     6,     4,     5,     7,    10,    18,
      19,    22,    28,    52,    53,    54,    55,    58,    59,    27,
       4,     5,     7,    10,    18,    19,    22,    28,    54,    55,
      10,    22,    22,    54,    54,    54,    20,    21,    28,    33,
      50,    10,    13,    11,    17,    54,    54,    54,    28,    50,
      11,    54,    27,    28,    22,    22,    22,    50,    29,    54,
       4,     5,     7,    10,    18,    19,    22,    28,    53,    54,
      55,    55,    22,    22,    29,    55,    41,    29,    54,    54,
      54,    28,    50,    10,    11,    29,    29,    22,    29,    54,
      55,    30,    29,    48,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    38,    39,
      40,    40,    41,    41,    41,    42,    43,    44,    44,    45,
      46,    46,    47,    47,    47,    47,    48,    49,    50,    50,
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    58,    59,
      59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     8,
       4,     9,     3,     1,     0,     2,     7,    11,     9,    11,
       2,     3,     2,     2,     2,     0,     1,     2,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     4,     1,     5,     5,     5,     3,     3,
       1
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
#line 60 "src/sintatico.y"
                     {printf("program->declaration_list\n");}
#line 1722 "src/sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 64 "src/sintatico.y"
                                 {printf("declaration_list -> declaration_list declaration\n");}
#line 1728 "src/sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 65 "src/sintatico.y"
                  {printf("declaration_list -> declaration\n");}
#line 1734 "src/sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 69 "src/sintatico.y"
                    {printf("declaration -> var_declaration\n");}
#line 1740 "src/sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 70 "src/sintatico.y"
                           {printf("declaration -> function_declaration\n");}
#line 1746 "src/sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 71 "src/sintatico.y"
                       {printf("declaration -> list_declaration\n");}
#line 1752 "src/sintatico.tab.c"
    break;

  case 8: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 75 "src/sintatico.y"
                       {
        // printf("var_declaration -> %s %s ';'\n", $1.body, $2.body);
        symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, (yyvsp[-2].token).body, 0);

        printf("(%d|%d) - ID: %s TYPE: %s\n", new_symbol.line, new_symbol.column, new_symbol.identifier, new_symbol.type);
        exit(1);
    }
#line 1764 "src/sintatico.tab.c"
    break;

  case 9: /* function_declaration: SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 85 "src/sintatico.y"
                                                        {printf("function_declaration -> %s %s '(' params ')' '{' multiple_stmt '}'\n", (yyvsp[-7].token).body, (yyvsp[-6].token).body);}
#line 1770 "src/sintatico.tab.c"
    break;

  case 10: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 89 "src/sintatico.y"
                                 {printf("list_declaration -> %s %s %s ';'\n", (yyvsp[-3].token).body, (yyvsp[-2].token).body, (yyvsp[-1].token).body);}
#line 1776 "src/sintatico.tab.c"
    break;

  case 11: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 90 "src/sintatico.y"
                                                                    {printf("list_declaration -> %s %s %s '(' params ')' '{' multiple_stmt '}'\n",
                                                                            (yyvsp[-8].token).body, (yyvsp[-7].token).body, (yyvsp[-6].token).body);}
#line 1783 "src/sintatico.tab.c"
    break;

  case 12: /* params: params ',' param  */
#line 95 "src/sintatico.y"
                     {printf(" params -> params ',' param\n");}
#line 1789 "src/sintatico.tab.c"
    break;

  case 13: /* params: param  */
#line 96 "src/sintatico.y"
            {printf("params -> param\n");}
#line 1795 "src/sintatico.tab.c"
    break;

  case 15: /* param: SIMPLE_TYPE ID  */
#line 101 "src/sintatico.y"
                   {printf("param -> %s %s\n", (yyvsp[-1].token).body, (yyvsp[0].token).body);}
#line 1801 "src/sintatico.tab.c"
    break;

  case 16: /* if_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 105 "src/sintatico.y"
                                                {printf("if_stmt -> %s '(' expression_stmt ')' '{' stmt '}'\n", 
                                                    (yyvsp[-6].token).body);}
#line 1808 "src/sintatico.tab.c"
    break;

  case 17: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 110 "src/sintatico.y"
                                                                           {printf("if_else_stmt -> %s '(' expression_stmt ')' '{' stmt '}' ELSE '{' stmt '}'\n", (yyvsp[-10].token).body);}
#line 1814 "src/sintatico.tab.c"
    break;

  case 19: /* for_stmt: FOR '(' expression ';' expression ';' expression ')' '{' multiple_stmt '}'  */
#line 115 "src/sintatico.y"
                                                                              {printf("for_stmt -> %s '(' expression_stmt ')' '{' stmt '}'\n", (yyvsp[-10].token).body);}
#line 1820 "src/sintatico.tab.c"
    break;

  case 20: /* return_stmt: RETURN ';'  */
#line 119 "src/sintatico.y"
               {printf("return_stmt -> %s ';'\n", (yyvsp[-1].token).body);}
#line 1826 "src/sintatico.tab.c"
    break;

  case 21: /* return_stmt: RETURN expression ';'  */
#line 120 "src/sintatico.y"
                            {printf("return_stmt -> %s expression ';'\n", (yyvsp[-2].token).body);}
#line 1832 "src/sintatico.tab.c"
    break;

  case 26: /* multiple_stmt: general_declaration  */
#line 131 "src/sintatico.y"
                        {printf("multiple_stmt -> general_declaration\n");}
#line 1838 "src/sintatico.tab.c"
    break;

  case 27: /* expression_stmt: expression ';'  */
#line 135 "src/sintatico.y"
                   {printf("expression_stmt -> expression ';'\n");}
#line 1844 "src/sintatico.tab.c"
    break;

  case 28: /* expression: ID '=' expression  */
#line 139 "src/sintatico.y"
                      {printf("expression -> %s '=' expression\n", (yyvsp[-2].token).body);}
#line 1850 "src/sintatico.tab.c"
    break;

  case 29: /* expression: simple_expression  */
#line 140 "src/sintatico.y"
                        {printf("expression -> simple_expression\n");}
#line 1856 "src/sintatico.tab.c"
    break;

  case 30: /* expression: binary_construct  */
#line 141 "src/sintatico.y"
                      {printf("expression -> binary_construct\n");}
#line 1862 "src/sintatico.tab.c"
    break;

  case 33: /* stmt: expression_stmt  */
#line 147 "src/sintatico.y"
                    {printf("stmt -> expression_stmt\n");}
#line 1868 "src/sintatico.tab.c"
    break;

  case 34: /* stmt: if_stmt  */
#line 148 "src/sintatico.y"
              {printf("stmt -> if_stmt\n");}
#line 1874 "src/sintatico.tab.c"
    break;

  case 35: /* stmt: if_else_stmt  */
#line 149 "src/sintatico.y"
                   {printf("stmt -> if_else_stmt\n");}
#line 1880 "src/sintatico.tab.c"
    break;

  case 36: /* stmt: for_stmt  */
#line 150 "src/sintatico.y"
               {printf("stmt -> for_stmt\n");}
#line 1886 "src/sintatico.tab.c"
    break;

  case 37: /* stmt: return_stmt  */
#line 151 "src/sintatico.y"
                  {printf("stmt -> return_stmt\n");}
#line 1892 "src/sintatico.tab.c"
    break;

  case 40: /* simple_expression: arithmetic_expression BINARY_COMP_OP arithmetic_expression  */
#line 158 "src/sintatico.y"
                                                               {printf("simple_expression -> arithmetic_expression %s arithmetic_expression\n", (yyvsp[-1].token).body);}
#line 1898 "src/sintatico.tab.c"
    break;

  case 41: /* simple_expression: arithmetic_expression  */
#line 159 "src/sintatico.y"
                            {printf("simple_expression -> arithmetic_expression\n");}
#line 1904 "src/sintatico.tab.c"
    break;

  case 42: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 163 "src/sintatico.y"
                                                {printf("arithmetic_expression -> arithmetic_expression %s term\n", (yyvsp[-1].token).body);}
#line 1910 "src/sintatico.tab.c"
    break;

  case 43: /* arithmetic_expression: BINARY_BASIC_OP1 term  */
#line 164 "src/sintatico.y"
                            {printf("arithmetic_expression -> %s term\n", (yyvsp[-1].token).body);}
#line 1916 "src/sintatico.tab.c"
    break;

  case 46: /* arithmetic_expression: term  */
#line 167 "src/sintatico.y"
           {printf("arithmetic_expression -> term\n");}
#line 1922 "src/sintatico.tab.c"
    break;

  case 47: /* term: term BINARY_BASIC_OP2 factor  */
#line 171 "src/sintatico.y"
                                 {printf("term -> term %s factor\n", (yyvsp[-1].token).body);}
#line 1928 "src/sintatico.tab.c"
    break;

  case 48: /* term: factor  */
#line 172 "src/sintatico.y"
             {printf("term -> factor\n");}
#line 1934 "src/sintatico.tab.c"
    break;

  case 49: /* factor: '(' expression ')'  */
#line 176 "src/sintatico.y"
                       {printf("factor -> '(' expression ')'\n");}
#line 1940 "src/sintatico.tab.c"
    break;

  case 50: /* factor: ID  */
#line 177 "src/sintatico.y"
         {printf("factor -> %s\n", (yyvsp[0].token).body);}
#line 1946 "src/sintatico.tab.c"
    break;

  case 51: /* factor: INT  */
#line 178 "src/sintatico.y"
          {printf("factor -> %s\n", (yyvsp[0].token).body);}
#line 1952 "src/sintatico.tab.c"
    break;

  case 52: /* factor: FLOAT  */
#line 179 "src/sintatico.y"
            {printf("factor -> %s\n", (yyvsp[0].token).body);}
#line 1958 "src/sintatico.tab.c"
    break;

  case 53: /* factor: ID '(' ID ')'  */
#line 180 "src/sintatico.y"
                    {printf("factor -> %s '(' %s ')'\n", (yyvsp[-3].token).body, (yyvsp[-1].token).body);}
#line 1964 "src/sintatico.tab.c"
    break;

  case 55: /* print: OUTPUT '(' STRING ')' ';'  */
#line 185 "src/sintatico.y"
                              {printf("print -> %s '(' %s ')' ';'\n", (yyvsp[-4].token).body, (yyvsp[-2].token).body);}
#line 1970 "src/sintatico.tab.c"
    break;

  case 57: /* scan: INPUT '(' ID ')' ';'  */
#line 190 "src/sintatico.y"
                         {printf("print -> %s '(' %s ')' ';'\n", (yyvsp[-4].token).body, (yyvsp[-2].token).body);}
#line 1976 "src/sintatico.tab.c"
    break;

  case 58: /* binary_construct: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 194 "src/sintatico.y"
                                                     {printf("binary_construct -> binary_construct_recursive %s %s\n", (yyvsp[-1].token).body, (yyvsp[0].token).body);}
#line 1982 "src/sintatico.tab.c"
    break;

  case 59: /* binary_construct_recursive: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 198 "src/sintatico.y"
                                                     {printf("binary_construct_recursive -> binary_construct_recursive %s %s\n", (yyvsp[-1].token).body, (yyvsp[0].token).body);}
#line 1988 "src/sintatico.tab.c"
    break;

  case 60: /* binary_construct_recursive: ID  */
#line 199 "src/sintatico.y"
         {printf("%s\n", (yyvsp[0].token).body);}
#line 1994 "src/sintatico.tab.c"
    break;


#line 1998 "src/sintatico.tab.c"

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

#line 204 "src/sintatico.y"


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
