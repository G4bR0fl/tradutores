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
    tree* main_node;
    

#line 101 "src/sintatico.tab.c"

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
  YYSYMBOL_38_1 = 38,                      /* $@1  */
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
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_simple_expression = 53,         /* simple_expression  */
  YYSYMBOL_arithmetic_expression = 54,     /* arithmetic_expression  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_print = 57,                     /* print  */
  YYSYMBOL_scan = 58,                      /* scan  */
  YYSYMBOL_binary_construct = 59,          /* binary_construct  */
  YYSYMBOL_binary_construct_recursive = 60 /* binary_construct_recursive  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  221

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
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   105,   108,   112,   113,   114,   115,   115,
     119,   128,   137,   151,   168,   169,   170,   171,   175,   179,
     183,   184,   188,   192,   193,   197,   198,   199,   200,   204,
     208,   212,   213,   214,   215,   216,   217,   221,   222,   223,
     224,   225,   226,   227,   228,   233,   234,   238,   239,   240,
     241,   242,   246,   247,   251,   252,   253,   254,   255,   256,
     260,   261,   265,   269,   273,   274,   275
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
  "declaration_list", "declaration", "$@1", "var_declaration",
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

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   129,    76,     9,   582,   611,   640,   669,   698,   727,
     -21,   130,   -31,   756,   303,   814,     3,   840,     3,   164,
      -6,   186,   211,   237,   244,    -9,    24,    10,   252,   266,
     252,   281,    23,    29,   194,    91,   158,  1014,  1057,    15,
      52,    61,    15,    15,  1033,    75,    82,   975,   982,   310,
     339,   368,   397,   426,   455,   484,    77,   513,    90,   785,
    1064,  1076,   542,   571,   101,   148,   869,   898,   116,   985,
    1082,   156,    43,  1086,  1091,   181,   183,   207,  1004,   982,
    1004,    98,   600,   209,   215,   629,    15,  1011,    15,   265,
     243,   272,   287,   297,   300,   305,   318,   324,   329,   658,
    1095,  1101,     1,  1106,   165,   336,   347,   355,  1110,   358,
    1004,   687,   716,   745,   252,   362,   354,   982,   223,   363,
     947,   373,   252,   774,   252,   380,   383,   803,   832,   396,
      46,   162,   250,   279,    83,    83,    83,  1052,   982,   388,
       2,   308,   337,   392,   415,   861,   126,   196,   254,   172,
     172,   172,   755,   982,   283,   312,   172,   332,   113,   366,
     395,   424,   418,   421,   425,   982,   417,    83,  1030,    83,
     439,   341,   370,   399,   447,   443,   172,   428,   890,     3,
     446,   450,   461,   469,   453,   482,    45,   134,   141,   230,
     230,   230,    -3,   982,    -5,   173,   221,   511,    78,   472,
     457,   486,   273,   540,   569,   598,   627,   454,   475,   230,
     230,   515,   420,   476,   656,   685,   714,   252,   743,   477,
     919
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -31,   -31,   -31,   523,   -31,   488,   -31,   499,   -15,   507,
     -31,   -31,   -31,   -31,   -31,   -30,   -31,    21,   414,    -8,
     -14,    -1,   -29,   -31,   -31,    -2,    36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     9,     6,     7,     8,    21,    22,
      51,    52,    53,    54,    31,    32,    55,    56,    57,   139,
     140,   141,   142,    62,    63,   143,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    14,    61,    23,    19,   209,    20,   -55,   -55,    12,
      61,   156,   167,    61,    61,   168,    24,    59,    61,    36,
      37,    28,    38,    58,   -45,   207,   -55,    20,   -45,    64,
      60,   -46,   -16,    59,     1,   -16,     2,    69,    70,    58,
      30,    73,    74,    48,   130,    64,    60,   131,   132,    61,
     133,    61,    91,   134,    66,   -56,   -56,    61,   155,   103,
      67,   135,   136,   -66,    59,   137,    59,    65,    83,    84,
      58,   138,    58,   102,   -56,   -36,    64,    60,    64,    60,
      71,    61,    10,    65,   116,   101,   154,   131,   132,    72,
     133,    61,   125,    92,   126,   -64,    59,   129,    11,    96,
      97,    98,    58,    79,    85,   158,    59,   -63,    64,    60,
      80,   138,    58,    68,    65,   -66,    65,   -32,    64,    60,
     155,   155,   155,   -55,   -55,   -36,   -55,   155,   -33,    -8,
      -8,   115,    -8,   159,   160,   161,   -56,   -56,   119,   196,
     197,   164,   -55,   145,   -57,   -57,    65,   201,   171,   172,
     173,   -59,   -59,   -56,   194,   177,    65,    15,    16,   166,
     196,   196,   196,   -57,   202,    89,   185,   195,   -56,   -56,
     -59,   -56,   -56,   -56,   175,   -56,   146,   147,    90,   148,
     196,   216,   -64,   -51,   210,   -56,   183,   219,   204,   205,
     206,   -56,   -63,   -17,   152,   -44,   -17,   -44,   -44,   -44,
     153,   -44,   -51,    93,   -44,    94,   -57,   -57,   215,   -44,
     -44,   -66,   -44,   -44,   208,    25,   -44,   -44,    26,   -44,
     -44,   -36,   -44,   -57,   -19,   -44,   -19,   -19,   -19,    95,
     -19,   -53,   -53,   -19,   186,   187,    99,   188,   -19,   -19,
     -15,   -19,   -19,   -15,   100,   -19,   -19,   120,   -19,   -19,
     -53,   -19,   192,   -28,   -19,   -28,   -28,   -28,   193,   -28,
     -57,   -57,   -28,   -57,   -59,   -59,    27,   -28,   -28,    26,
     -28,   -28,   105,   -18,   -28,   -28,   -18,   -28,   -28,   -57,
     -28,   -59,    34,   -28,    35,    36,    37,   104,    38,   -59,
     -59,    39,   -59,   -51,   176,   -14,    40,    41,   -14,    42,
      43,   106,   212,    44,    45,    26,    46,    47,   -59,    48,
     -51,   -25,   -29,   -25,   -25,   -25,   107,   -25,   -51,   169,
     -25,   -51,   -53,   -53,   -34,   -25,   -25,   -35,   -25,   -25,
      17,    18,   -25,   -25,   108,   -25,   -25,   -51,   -25,   -53,
     -26,   -25,   -26,   -26,   -26,   -31,   -26,   -53,   -53,   -26,
     -53,   -48,   176,   109,   -26,   -26,   110,   -26,   -26,   178,
     179,   -26,   -26,   111,   -26,   -26,   -53,   -26,   -48,   -38,
     -26,   -38,   -38,   -38,   112,   -38,   -48,   169,   -38,   -48,
     -50,   176,   113,   -38,   -38,   118,   -38,   -38,   114,   117,
     -38,   -38,   121,   -38,   -38,   -48,   -38,   -50,   -39,   -38,
     -39,   -39,   -39,   124,   -39,   -50,   169,   -39,   -50,   -49,
     176,   127,   -39,   -39,   128,   -39,   -39,   -32,   157,   -39,
     -39,   -33,   -39,   -39,   -50,   -39,   -49,   -40,   -39,   -40,
     -40,   -40,   170,   -40,   -49,   169,   -40,   -49,   -47,   176,
     180,   -40,   -40,   181,   -40,   -40,   184,   182,   -40,   -40,
     217,   -40,   -40,   -49,   -40,   -47,   -41,   -40,   -41,   -41,
     -41,   198,   -41,   -54,   -54,   -41,   -54,   -54,   -54,   199,
     -41,   -41,   200,   -41,   -41,   -34,   213,   -41,   -41,   -35,
     -41,   -41,   -54,   -41,   -54,   -37,   -41,   -37,   -37,   -37,
     203,   -37,   -47,   169,   -37,   -47,   -52,   -52,   -31,   -37,
     -37,   211,   -37,   -37,   214,   218,   -37,   -37,   220,   -37,
     -37,   -47,   -37,   -52,   -27,   -37,   -27,   -27,   -27,    49,
     -27,   -52,   -52,   -27,   -52,   -58,   -58,    13,   -27,   -27,
      50,   -27,   -27,    29,   123,   -27,   -27,     0,   -27,   -27,
     -52,   -27,   -58,   -42,   -27,   -42,   -42,   -42,     0,   -42,
     -58,   -58,   -42,   -58,     0,     0,     0,   -42,   -42,     0,
     -42,   -42,     0,     0,   -42,   -42,     0,   -42,   -42,   -58,
     -42,     0,   -43,   -42,   -43,   -43,   -43,     0,   -43,   -48,
     210,   -43,    -2,     1,     0,     2,   -43,   -43,     0,   -43,
     -43,     0,     0,   -43,   -43,     0,   -43,   -43,   -48,   -43,
       0,   -23,   -43,   -23,   -23,   -23,     0,   -23,   -50,   210,
     -23,    -4,    -4,     0,    -4,   -23,   -23,     0,   -23,   -23,
       0,     0,   -23,   -23,     0,   -23,   -23,   -50,   -23,     0,
     -30,   -23,   -30,   -30,   -30,     0,   -30,   -49,   210,   -30,
      -5,    -5,     0,    -5,   -30,   -30,     0,   -30,   -30,     0,
       0,   -30,   -30,     0,   -30,   -30,   -49,   -30,     0,   -24,
     -30,   -24,   -24,   -24,     0,   -24,   -54,   -54,   -24,    -6,
      -6,     0,    -6,   -24,   -24,     0,   -24,   -24,     0,     0,
     -24,   -24,     0,   -24,   -24,   -54,   -24,     0,   -62,   -24,
     -62,   -62,   -62,     0,   -62,   -47,   210,   -62,    -7,    -7,
       0,    -7,   -62,   -62,     0,   -62,   -62,     0,     0,   -62,
     -62,     0,   -62,   -62,   -47,   -62,     0,   -60,   -62,   -60,
     -60,   -60,     0,   -60,   -52,   -52,   -60,    -9,    -9,     0,
      -9,   -60,   -60,     0,   -60,   -60,     0,     0,   -60,   -60,
       0,   -60,   -60,   -52,   -60,     0,   -61,   -60,   -61,   -61,
     -61,     0,   -61,   -58,   -58,   -61,    -3,    -3,     0,    -3,
     -61,   -61,     0,   -61,   -61,   -55,   -55,   -61,   -61,     0,
     -61,   -61,   -58,   -61,     0,   -21,   -61,   -21,   -21,   -21,
       0,   -21,   -55,   174,   -21,     0,     0,     0,     0,   -21,
     -21,     0,   -21,   -21,     0,    86,   -21,   -21,    87,   -21,
     -21,     0,   -21,     0,   -20,   -21,   -20,   -20,   -20,     0,
     -20,     0,   -46,   -20,   -10,   -10,     0,   -10,   -20,   -20,
       0,   -20,   -20,     0,     0,   -20,   -20,     0,   -20,   -20,
       0,   -20,     0,   -22,   -20,   -22,   -22,   -22,     0,   -22,
     -12,   -12,   -22,   -12,     0,     0,     0,   -22,   -22,     0,
     -22,   -22,     0,     0,   -22,   -22,     0,   -22,   -22,     0,
     -22,     0,   -10,   -22,   -10,   -10,   -10,     0,   -10,   -11,
     -11,   -10,   -11,     0,     0,     0,   -10,   -10,     0,   -10,
     -10,     0,     0,   -10,   -10,     0,   -10,   -10,     0,   -10,
       0,   -12,   -10,   -12,   -12,   -12,     0,   -12,   -13,   -13,
     -12,   -13,     0,     0,     0,   -12,   -12,     0,   -12,   -12,
       0,     0,   -12,   -12,     0,   -12,   -12,     0,   -12,     0,
     -13,   -12,   -13,   -13,   -13,     0,   -13,     0,     0,   -13,
       0,     0,     0,     0,   -13,   -13,     0,   -13,   -13,     0,
       0,   -13,   -13,     0,   -13,   -13,     0,   -13,    34,     0,
     -13,    36,    37,     0,    38,     0,     0,    39,     0,     0,
       0,     0,    40,    41,     0,    42,    43,     0,     0,    44,
      45,     0,    46,    47,     0,    48,    81,   122,     0,    36,
      37,     0,    38,   130,     0,    39,   131,   132,     0,   133,
       0,     0,   134,    42,    43,   -55,   -55,    44,   -55,     0,
     135,   136,    82,    48,   137,    81,     0,     0,    36,    37,
     138,    38,   -55,    77,    39,   146,   147,     0,   148,     0,
       0,   149,    42,    43,   -57,   -57,    44,   -57,     0,   150,
     151,     0,    48,   152,   186,   187,     0,   188,     0,   153,
     189,   -57,     0,   -55,   -55,     0,   -55,     0,   190,   191,
     -65,     0,   192,    75,    76,     0,     0,     0,   193,     0,
     -55,    77,   -55,   -55,     0,   -55,    78,   -59,   -59,   -65,
     -59,     0,   162,   163,   -51,    88,     0,   -51,     0,     0,
     164,   -55,     0,     0,   -59,   165,   -53,   -53,     0,   -53,
       0,   -51,   -48,    88,     0,   -48,   -50,    88,     0,   -50,
       0,   -49,    88,   -53,   -49,   -54,   -54,     0,   -54,   -48,
       0,   -47,    88,   -50,   -47,     0,   -52,   -52,   -49,   -52,
     -58,   -58,   -54,   -58,     0,     0,     0,     0,   -47,     0,
       0,     0,     0,   -52,     0,     0,     0,   -58
};

static const yytype_int16 yycheck[] =
{
      30,    22,    31,    18,     1,    10,     3,    10,    11,     0,
      39,    10,    10,    42,    43,    13,    22,    31,    47,     4,
       5,    30,     7,    31,    29,    28,    29,     3,    27,    31,
      31,    29,    29,    47,     1,    32,     3,    22,    39,    47,
      30,    42,    43,    28,     1,    47,    47,     4,     5,    78,
       7,    80,     9,    10,    31,    10,    11,    86,    87,    88,
      31,    18,    19,    17,    78,    22,    80,    31,    47,    48,
      78,    28,    80,    87,    29,    29,    78,    78,    80,    80,
      28,   110,     6,    47,   114,    86,    87,     4,     5,    28,
       7,   120,   122,    72,   124,    17,   110,     6,    22,    78,
      79,    80,   110,    28,    27,    22,   120,    29,   110,   110,
      28,    28,   120,    22,    78,    17,    80,    27,   120,   120,
     149,   150,   151,    10,    11,    27,    13,   156,    27,     0,
       1,   110,     3,   134,   135,   136,    10,    11,   117,   168,
     169,    28,    29,    27,    10,    11,   110,   176,   149,   150,
     151,    10,    11,    27,   168,   156,   120,    27,    28,   138,
     189,   190,   191,    29,   179,    17,   167,   168,    10,    11,
      29,    13,    10,    11,   153,    13,     4,     5,    22,     7,
     209,   210,    17,    10,    11,    27,   165,   217,   189,   190,
     191,    29,    27,    29,    22,     1,    32,     3,     4,     5,
      28,     7,    29,    22,    10,    22,    10,    11,   209,    15,
      16,    17,    18,    19,   193,    29,    22,    23,    32,    25,
      26,    27,    28,    27,     1,    31,     3,     4,     5,    22,
       7,    10,    11,    10,     4,     5,    27,     7,    15,    16,
      29,    18,    19,    32,    29,    22,    23,    24,    25,    26,
      29,    28,    22,     1,    31,     3,     4,     5,    28,     7,
      10,    11,    10,    13,    10,    11,    29,    15,    16,    32,
      18,    19,    29,    29,    22,    23,    32,    25,    26,    29,
      28,    27,     1,    31,     3,     4,     5,    22,     7,    10,
      11,    10,    13,    10,    11,    29,    15,    16,    32,    18,
      19,    29,    29,    22,    23,    32,    25,    26,    29,    28,
      27,     1,    31,     3,     4,     5,    29,     7,    10,    11,
      10,    13,    10,    11,    27,    15,    16,    27,    18,    19,
      27,    28,    22,    23,    29,    25,    26,    29,    28,    27,
       1,    31,     3,     4,     5,    27,     7,    10,    11,    10,
      13,    10,    11,    29,    15,    16,    27,    18,    19,    27,
      28,    22,    23,    27,    25,    26,    29,    28,    27,     1,
      31,     3,     4,     5,    27,     7,    10,    11,    10,    13,
      10,    11,    27,    15,    16,    31,    18,    19,    30,    27,
      22,    23,    29,    25,    26,    29,    28,    27,     1,    31,
       3,     4,     5,    30,     7,    10,    11,    10,    13,    10,
      11,    31,    15,    16,    31,    18,    19,    29,    22,    22,
      23,    29,    25,    26,    29,    28,    27,     1,    31,     3,
       4,     5,    17,     7,    10,    11,    10,    13,    10,    11,
      22,    15,    16,    22,    18,    19,    29,    22,    22,    23,
      30,    25,    26,    29,    28,    27,     1,    31,     3,     4,
       5,    22,     7,    10,    11,    10,    13,    10,    11,    22,
      15,    16,    29,    18,    19,    29,    22,    22,    23,    29,
      25,    26,    29,    28,    27,     1,    31,     3,     4,     5,
      29,     7,    10,    11,    10,    13,    10,    11,    29,    15,
      16,    29,    18,    19,    29,    29,    22,    23,    31,    25,
      26,    29,    28,    27,     1,    31,     3,     4,     5,    31,
       7,    10,    11,    10,    13,    10,    11,     4,    15,    16,
      31,    18,    19,    26,   120,    22,    23,    -1,    25,    26,
      29,    28,    27,     1,    31,     3,     4,     5,    -1,     7,
      10,    11,    10,    13,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    29,
      28,    -1,     1,    31,     3,     4,     5,    -1,     7,    10,
      11,    10,     0,     1,    -1,     3,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    29,    28,
      -1,     1,    31,     3,     4,     5,    -1,     7,    10,    11,
      10,     0,     1,    -1,     3,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    29,    28,    -1,
       1,    31,     3,     4,     5,    -1,     7,    10,    11,    10,
       0,     1,    -1,     3,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    25,    26,    29,    28,    -1,     1,
      31,     3,     4,     5,    -1,     7,    10,    11,    10,     0,
       1,    -1,     3,    15,    16,    -1,    18,    19,    -1,    -1,
      22,    23,    -1,    25,    26,    29,    28,    -1,     1,    31,
       3,     4,     5,    -1,     7,    10,    11,    10,     0,     1,
      -1,     3,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    29,    28,    -1,     1,    31,     3,
       4,     5,    -1,     7,    10,    11,    10,     0,     1,    -1,
       3,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    29,    28,    -1,     1,    31,     3,     4,
       5,    -1,     7,    10,    11,    10,     0,     1,    -1,     3,
      15,    16,    -1,    18,    19,    10,    11,    22,    23,    -1,
      25,    26,    29,    28,    -1,     1,    31,     3,     4,     5,
      -1,     7,    27,    28,    10,    -1,    -1,    -1,    -1,    15,
      16,    -1,    18,    19,    -1,    10,    22,    23,    13,    25,
      26,    -1,    28,    -1,     1,    31,     3,     4,     5,    -1,
       7,    -1,    27,    10,     0,     1,    -1,     3,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,    26,
      -1,    28,    -1,     1,    31,     3,     4,     5,    -1,     7,
       0,     1,    10,     3,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      28,    -1,     1,    31,     3,     4,     5,    -1,     7,     0,
       1,    10,     3,    -1,    -1,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    28,
      -1,     1,    31,     3,     4,     5,    -1,     7,     0,     1,
      10,     3,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    28,    -1,
       1,    31,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    -1,    25,    26,    -1,    28,     1,    -1,
      31,     4,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    22,
      23,    -1,    25,    26,    -1,    28,     1,    30,    -1,     4,
       5,    -1,     7,     1,    -1,    10,     4,     5,    -1,     7,
      -1,    -1,    10,    18,    19,    10,    11,    22,    13,    -1,
      18,    19,    27,    28,    22,     1,    -1,    -1,     4,     5,
      28,     7,    27,    28,    10,     4,     5,    -1,     7,    -1,
      -1,    10,    18,    19,    10,    11,    22,    13,    -1,    18,
      19,    -1,    28,    22,     4,     5,    -1,     7,    -1,    28,
      10,    27,    -1,    10,    11,    -1,    13,    -1,    18,    19,
      17,    -1,    22,    20,    21,    -1,    -1,    -1,    28,    -1,
      27,    28,    10,    11,    -1,    13,    33,    10,    11,    17,
      13,    -1,    20,    21,    10,    11,    -1,    13,    -1,    -1,
      28,    29,    -1,    -1,    27,    33,    10,    11,    -1,    13,
      -1,    27,    10,    11,    -1,    13,    10,    11,    -1,    13,
      -1,    10,    11,    27,    13,    10,    11,    -1,    13,    27,
      -1,    10,    11,    27,    13,    -1,    10,    11,    27,    13,
      10,    11,    27,    13,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    35,    36,    37,    39,    40,    41,    38,
       6,    22,     0,    37,    22,    27,    28,    27,    28,     1,
       3,    42,    43,    42,    22,    29,    32,    29,    30,    43,
      30,    48,    49,    49,     1,     3,     4,     5,     7,    10,
      15,    16,    18,    19,    22,    23,    25,    26,    28,    39,
      41,    44,    45,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    31,    31,    22,    22,
      55,    28,    28,    55,    55,    20,    21,    28,    33,    28,
      28,     1,    27,    51,    51,    27,    10,    13,    11,    17,
      22,     9,    51,    22,    22,    22,    51,    51,    51,    27,
      29,    55,    54,    56,    22,    29,    29,    29,    29,    29,
      27,    27,    27,    27,    30,    51,    49,    27,    31,    51,
      24,    29,    30,    52,    30,    49,    49,    31,    31,     6,
       1,     4,     5,     7,    10,    18,    19,    22,    28,    53,
      54,    55,    56,    59,    60,    27,     4,     5,     7,    10,
      18,    19,    22,    28,    55,    56,    10,    22,    22,    55,
      55,    55,    20,    21,    28,    33,    51,    10,    13,    11,
      17,    55,    55,    55,    28,    51,    11,    55,    27,    28,
      22,    22,    22,    51,    29,    55,     4,     5,     7,    10,
      18,    19,    22,    28,    54,    55,    56,    56,    22,    22,
      29,    56,    42,    29,    55,    55,    55,    28,    51,    10,
      11,    29,    29,    22,    29,    55,    56,    30,    29,    49,
      31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    38,    37,
      39,    40,    41,    41,    42,    42,    42,    42,    43,    44,
      45,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    59,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     2,
       3,     8,     4,     9,     3,     1,     0,     1,     2,     7,
      11,     9,    11,     2,     3,     2,     2,     2,     0,     1,
       2,     3,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     2,     2,
       2,     1,     3,     1,     3,     1,     1,     1,     4,     1,
       5,     5,     5,     3,     3,     1,     1
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
#line 95 "src/sintatico.y"
                     { 
        (yyval.node) = create_node();
        printf("\n");
        // $$->next_node = $1;
        // main_node = $$;
        // printf("%s\n", main_node->rule_name);
    }
#line 1747 "src/sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 105 "src/sintatico.y"
                                 {
        
    }
#line 1755 "src/sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 108 "src/sintatico.y"
                  {}
#line 1761 "src/sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 112 "src/sintatico.y"
                    {}
#line 1767 "src/sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 113 "src/sintatico.y"
                           {}
#line 1773 "src/sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 114 "src/sintatico.y"
                       {}
#line 1779 "src/sintatico.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 115 "src/sintatico.y"
            {yyerrok;}
#line 1785 "src/sintatico.tab.c"
    break;

  case 9: /* declaration: error $@1  */
#line 115 "src/sintatico.y"
                       {}
#line 1791 "src/sintatico.tab.c"
    break;

  case 10: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 119 "src/sintatico.y"
                       {
        symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, (yyvsp[-2].token).body, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
    }
#line 1802 "src/sintatico.tab.c"
    break;

  case 11: /* function_declaration: SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 128 "src/sintatico.y"
                                                        {
        symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, (yyvsp[-7].token).body, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;   
    }
#line 1813 "src/sintatico.tab.c"
    break;

  case 12: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 137 "src/sintatico.y"
                                 {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        strcpy(str_simple_type, (yyvsp[-3].token).body);
        strcat(str_simple_type, "\x20");
        strcpy(str_list_type, (yyvsp[-2].token).body);
        strcpy(list_string, strcat(str_simple_type, str_list_type));
        symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, list_string, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
       
    }
#line 1832 "src/sintatico.tab.c"
    break;

  case 13: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 151 "src/sintatico.y"
                                                                    {
        char str_simple_type[50];
        char str_list_type[50];
        char list_string[101];
        strcpy(str_simple_type, (yyvsp[-8].token).body);
        strcat(str_simple_type, "\x20");
        strcpy(str_list_type, (yyvsp[-7].token).body);
        strcpy(list_string, strcat(str_simple_type, str_list_type));
        symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, list_string, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;
        
    }
#line 1851 "src/sintatico.tab.c"
    break;

  case 14: /* params: params ',' param  */
#line 168 "src/sintatico.y"
                     {}
#line 1857 "src/sintatico.tab.c"
    break;

  case 15: /* params: param  */
#line 169 "src/sintatico.y"
            {}
#line 1863 "src/sintatico.tab.c"
    break;

  case 16: /* params: %empty  */
#line 170 "src/sintatico.y"
             {}
#line 1869 "src/sintatico.tab.c"
    break;

  case 17: /* params: error  */
#line 171 "src/sintatico.y"
            {yyerrok;}
#line 1875 "src/sintatico.tab.c"
    break;

  case 18: /* param: SIMPLE_TYPE ID  */
#line 175 "src/sintatico.y"
                   {}
#line 1881 "src/sintatico.tab.c"
    break;

  case 19: /* if_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 179 "src/sintatico.y"
                                                {}
#line 1887 "src/sintatico.tab.c"
    break;

  case 20: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 183 "src/sintatico.y"
                                                                           {}
#line 1893 "src/sintatico.tab.c"
    break;

  case 21: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt  */
#line 184 "src/sintatico.y"
                                                            {}
#line 1899 "src/sintatico.tab.c"
    break;

  case 22: /* for_stmt: FOR '(' expression ';' expression ';' expression ')' '{' multiple_stmt '}'  */
#line 188 "src/sintatico.y"
                                                                              {}
#line 1905 "src/sintatico.tab.c"
    break;

  case 23: /* return_stmt: RETURN ';'  */
#line 192 "src/sintatico.y"
               {}
#line 1911 "src/sintatico.tab.c"
    break;

  case 24: /* return_stmt: RETURN expression ';'  */
#line 193 "src/sintatico.y"
                            {}
#line 1917 "src/sintatico.tab.c"
    break;

  case 25: /* general_declaration: general_declaration var_declaration  */
#line 197 "src/sintatico.y"
                                        {}
#line 1923 "src/sintatico.tab.c"
    break;

  case 26: /* general_declaration: general_declaration list_declaration  */
#line 198 "src/sintatico.y"
                                           {}
#line 1929 "src/sintatico.tab.c"
    break;

  case 27: /* general_declaration: general_declaration stmt  */
#line 199 "src/sintatico.y"
                               {}
#line 1935 "src/sintatico.tab.c"
    break;

  case 28: /* general_declaration: %empty  */
#line 200 "src/sintatico.y"
             {}
#line 1941 "src/sintatico.tab.c"
    break;

  case 29: /* multiple_stmt: general_declaration  */
#line 204 "src/sintatico.y"
                        {}
#line 1947 "src/sintatico.tab.c"
    break;

  case 30: /* expression_stmt: expression ';'  */
#line 208 "src/sintatico.y"
                   {}
#line 1953 "src/sintatico.tab.c"
    break;

  case 31: /* expression: ID '=' expression  */
#line 212 "src/sintatico.y"
                      {}
#line 1959 "src/sintatico.tab.c"
    break;

  case 32: /* expression: simple_expression  */
#line 213 "src/sintatico.y"
                        {}
#line 1965 "src/sintatico.tab.c"
    break;

  case 33: /* expression: binary_construct  */
#line 214 "src/sintatico.y"
                      {}
#line 1971 "src/sintatico.tab.c"
    break;

  case 34: /* expression: ID MAP ID  */
#line 215 "src/sintatico.y"
                {}
#line 1977 "src/sintatico.tab.c"
    break;

  case 35: /* expression: ID FILTER ID  */
#line 216 "src/sintatico.y"
                   {}
#line 1983 "src/sintatico.tab.c"
    break;

  case 36: /* expression: error  */
#line 217 "src/sintatico.y"
            {yyerrok;}
#line 1989 "src/sintatico.tab.c"
    break;

  case 37: /* stmt: expression_stmt  */
#line 221 "src/sintatico.y"
                    {}
#line 1995 "src/sintatico.tab.c"
    break;

  case 38: /* stmt: if_stmt  */
#line 222 "src/sintatico.y"
              {}
#line 2001 "src/sintatico.tab.c"
    break;

  case 39: /* stmt: if_else_stmt  */
#line 223 "src/sintatico.y"
                   {}
#line 2007 "src/sintatico.tab.c"
    break;

  case 40: /* stmt: for_stmt  */
#line 224 "src/sintatico.y"
               {}
#line 2013 "src/sintatico.tab.c"
    break;

  case 41: /* stmt: return_stmt  */
#line 225 "src/sintatico.y"
                  {}
#line 2019 "src/sintatico.tab.c"
    break;

  case 42: /* stmt: print  */
#line 226 "src/sintatico.y"
            {}
#line 2025 "src/sintatico.tab.c"
    break;

  case 43: /* stmt: scan  */
#line 227 "src/sintatico.y"
           {}
#line 2031 "src/sintatico.tab.c"
    break;

  case 44: /* stmt: error  */
#line 228 "src/sintatico.y"
            {yyerrok;}
#line 2037 "src/sintatico.tab.c"
    break;

  case 45: /* simple_expression: arithmetic_expression BINARY_COMP_OP arithmetic_expression  */
#line 233 "src/sintatico.y"
                                                               {}
#line 2043 "src/sintatico.tab.c"
    break;

  case 46: /* simple_expression: arithmetic_expression  */
#line 234 "src/sintatico.y"
                            {}
#line 2049 "src/sintatico.tab.c"
    break;

  case 47: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 238 "src/sintatico.y"
                                                {}
#line 2055 "src/sintatico.tab.c"
    break;

  case 48: /* arithmetic_expression: BINARY_BASIC_OP1 term  */
#line 239 "src/sintatico.y"
                            {}
#line 2061 "src/sintatico.tab.c"
    break;

  case 49: /* arithmetic_expression: TAIL term  */
#line 240 "src/sintatico.y"
                {}
#line 2067 "src/sintatico.tab.c"
    break;

  case 50: /* arithmetic_expression: HEADER term  */
#line 241 "src/sintatico.y"
                  {}
#line 2073 "src/sintatico.tab.c"
    break;

  case 51: /* arithmetic_expression: term  */
#line 242 "src/sintatico.y"
           {}
#line 2079 "src/sintatico.tab.c"
    break;

  case 52: /* term: term BINARY_BASIC_OP2 factor  */
#line 246 "src/sintatico.y"
                                 {}
#line 2085 "src/sintatico.tab.c"
    break;

  case 53: /* term: factor  */
#line 247 "src/sintatico.y"
             {}
#line 2091 "src/sintatico.tab.c"
    break;

  case 54: /* factor: '(' expression ')'  */
#line 251 "src/sintatico.y"
                       {}
#line 2097 "src/sintatico.tab.c"
    break;

  case 55: /* factor: ID  */
#line 252 "src/sintatico.y"
         {}
#line 2103 "src/sintatico.tab.c"
    break;

  case 56: /* factor: INT  */
#line 253 "src/sintatico.y"
          {}
#line 2109 "src/sintatico.tab.c"
    break;

  case 57: /* factor: FLOAT  */
#line 254 "src/sintatico.y"
            {}
#line 2115 "src/sintatico.tab.c"
    break;

  case 58: /* factor: ID '(' ID ')'  */
#line 255 "src/sintatico.y"
                    {}
#line 2121 "src/sintatico.tab.c"
    break;

  case 59: /* factor: LIST_CONSTANT  */
#line 256 "src/sintatico.y"
                    {}
#line 2127 "src/sintatico.tab.c"
    break;

  case 60: /* print: OUTPUT '(' STRING ')' ';'  */
#line 260 "src/sintatico.y"
                              {}
#line 2133 "src/sintatico.tab.c"
    break;

  case 61: /* print: OUTPUT '(' expression ')' ';'  */
#line 261 "src/sintatico.y"
                                    {}
#line 2139 "src/sintatico.tab.c"
    break;

  case 62: /* scan: INPUT '(' ID ')' ';'  */
#line 265 "src/sintatico.y"
                         {}
#line 2145 "src/sintatico.tab.c"
    break;

  case 63: /* binary_construct: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 269 "src/sintatico.y"
                                                     {}
#line 2151 "src/sintatico.tab.c"
    break;

  case 64: /* binary_construct_recursive: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 273 "src/sintatico.y"
                                                     {}
#line 2157 "src/sintatico.tab.c"
    break;

  case 65: /* binary_construct_recursive: ID  */
#line 274 "src/sintatico.y"
         {}
#line 2163 "src/sintatico.tab.c"
    break;

  case 66: /* binary_construct_recursive: error  */
#line 275 "src/sintatico.y"
            {yyerrok;}
#line 2169 "src/sintatico.tab.c"
    break;


#line 2173 "src/sintatico.tab.c"

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

#line 280 "src/sintatico.y"


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
    fclose(yyin);    
    yylex_destroy();
    return 0;
}
