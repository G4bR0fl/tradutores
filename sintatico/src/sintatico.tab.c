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
    tree* root;
    

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  220

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
       0,    97,    97,   105,   110,   116,   117,   118,   119,   123,
     136,   151,   168,   191,   195,   196,   199,   203,   211,   220,
     228,   239,   250,   251,   258,   263,   268,   273,   279,   283,
     287,   292,   293,   294,   300,   306,   310,   311,   312,   313,
     314,   315,   316,   317,   322,   328,   332,   338,   343,   348,
     353,   357,   363,   367,   368,   369,   370,   371,   376,   380,
     385,   393,   401,   410,   416,   417
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

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,   129,    76,     1,   553,   582,   611,   640,   669,   -15,
     130,   -30,   698,   303,   727,     3,   756,     3,   186,    -6,
     211,   237,   244,   266,    -9,    51,    30,   252,   273,   252,
     281,    44,    58,   194,    91,  1014,  1057,  1064,    15,    -3,
      75,    15,    15,  1033,    82,    89,   975,   982,   310,   339,
     368,   397,   426,   455,   484,    77,   513,   101,   155,  1076,
    1082,   542,   571,   114,   154,   785,   811,   116,   985,  1086,
     156,    43,  1091,  1095,   163,   170,   174,  1004,   982,  1004,
      98,   600,   178,   200,   629,    15,  1011,    15,   214,   215,
     243,   258,   274,   289,   305,   318,   324,   329,   658,  1101,
    1106,    53,  1110,   176,   336,   347,   355,  1114,   358,  1004,
     687,   716,   745,   252,   362,   354,   982,   223,   363,   947,
     373,   252,   774,   252,   380,   383,   803,   832,   396,    11,
     113,   162,   250,    83,    83,    83,  1052,   982,   388,     2,
     279,   308,   392,   415,   861,   126,   196,   254,   172,   172,
     172,   755,   982,   283,   312,   172,   332,    -2,   337,   366,
     395,   418,   421,   425,   982,   417,    83,  1030,    83,   439,
     341,   370,   399,   447,   443,   172,   428,   890,     3,   446,
     450,   461,   469,   424,   453,    45,   134,   173,   230,   230,
     230,   141,   982,    -5,   221,   540,   482,    78,   472,   457,
     486,   295,   511,   569,   598,   627,   454,   475,   230,   230,
     515,   420,   476,   656,   685,   714,   252,   743,   477,   919
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -30,   -30,   -30,   523,   489,   -30,   500,   -14,   508,   -30,
     -30,   -30,   -30,   -30,   -29,   -30,    22,   429,    -7,   -13,
       0,   -28,   -30,   -30,    -1,    37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    20,    21,    50,
      51,    52,    53,    30,    31,    54,    55,    56,   138,   139,
     140,   141,    61,    62,   142,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    11,    60,    22,    18,   208,    19,    13,   -54,   -54,
      60,   -54,   166,    60,    60,   167,    23,    58,    60,    35,
      36,    27,    37,    57,   -44,    70,   163,   -54,   -65,    63,
      59,   -45,   -15,    58,     1,   -15,     2,    68,    69,    57,
     -35,    72,    73,    47,   129,    63,    59,   130,   131,    60,
     132,    60,    90,   133,    19,   -55,   -55,    60,   154,   102,
      29,   134,   135,   155,    58,   136,    58,    64,    82,    83,
      57,   137,    57,   101,   -55,    65,    63,    59,    63,    59,
     -44,    60,     9,    64,   115,   100,   153,   130,   131,    66,
     132,    60,   124,    91,   125,   -63,    58,   128,    10,    95,
      96,    97,    57,    71,    84,   157,    58,   -62,    63,    59,
      78,   137,    57,    67,    64,   -65,    64,    79,    63,    59,
     154,   154,   154,   -55,   -55,   -35,   -55,   154,   -31,    -8,
      -8,   114,    -8,   158,   159,   160,   -55,   -55,   118,   195,
     196,   -32,   -55,   144,   -56,   -56,    64,   200,   170,   171,
     172,   -54,   -54,   -55,   193,   176,    64,    14,    15,   165,
     195,   195,   195,   -56,   201,    85,   184,   194,    86,   206,
     -54,    88,   -56,   -56,   174,   -56,   145,   146,    89,   147,
     195,   215,   -45,   -58,   -58,    92,   182,   218,   203,   204,
     205,   -56,    93,   -63,   151,   -43,    94,   -43,   -43,   -43,
     152,   -43,   -58,   -62,   -43,    98,   -56,   -56,   214,   -43,
     -43,   -65,   -43,   -43,   207,   -16,   -43,   -43,   -16,   -43,
     -43,   -35,   -43,   -56,   -18,   -43,   -18,   -18,   -18,    99,
     -18,   -50,   209,   -18,   185,   186,   103,   187,   -18,   -18,
      24,   -18,   -18,    25,   104,   -18,   -18,   119,   -18,   -18,
     -50,   -18,   191,   -27,   -18,   -27,   -27,   -27,   192,   -27,
     -58,   -58,   -27,   -58,   -58,   -58,   -14,   -27,   -27,   -14,
     -27,   -27,   105,    26,   -27,   -27,    25,   -27,   -27,   -58,
     -27,   -58,    33,   -27,    34,    35,    36,   106,    37,   -50,
     168,    38,   -50,   -50,   175,   -17,    39,    40,   -17,    41,
      42,   -33,   -13,    43,    44,   -13,    45,    46,   -50,    47,
     -50,   -24,   -28,   -24,   -24,   -24,   -34,   -24,   -52,   -52,
     -24,   -52,   -52,   -52,   211,   -24,   -24,    25,   -24,   -24,
      16,    17,   -24,   -24,   107,   -24,   -24,   -52,   -24,   -52,
     -25,   -24,   -25,   -25,   -25,   -30,   -25,   -47,   168,   -25,
     -47,   -47,   175,   108,   -25,   -25,   109,   -25,   -25,   177,
     178,   -25,   -25,   110,   -25,   -25,   -47,   -25,   -47,   -37,
     -25,   -37,   -37,   -37,   111,   -37,   -49,   168,   -37,   -49,
     -49,   175,   112,   -37,   -37,   117,   -37,   -37,   113,   116,
     -37,   -37,   120,   -37,   -37,   -49,   -37,   -49,   -38,   -37,
     -38,   -38,   -38,   123,   -38,   -48,   168,   -38,   -48,   -48,
     175,   126,   -38,   -38,   127,   -38,   -38,   -31,   156,   -38,
     -38,   -32,   -38,   -38,   -48,   -38,   -48,   -39,   -38,   -39,
     -39,   -39,   169,   -39,   -53,   -53,   -39,   -53,   -46,   175,
     179,   -39,   -39,   180,   -39,   -39,   183,   181,   -39,   -39,
     216,   -39,   -39,   -53,   -39,   -46,   -40,   -39,   -40,   -40,
     -40,   197,   -40,   -46,   168,   -40,   -46,   -53,   -53,   198,
     -40,   -40,   199,   -40,   -40,   -33,   212,   -40,   -40,   -34,
     -40,   -40,   -46,   -40,   -53,   -36,   -40,   -36,   -36,   -36,
     202,   -36,   -51,   -51,   -36,   -51,   -51,   -51,   -30,   -36,
     -36,   210,   -36,   -36,   213,   217,   -36,   -36,   219,   -36,
     -36,   -51,   -36,   -51,   -26,   -36,   -26,   -26,   -26,    48,
     -26,   -57,   -57,   -26,   -57,   -57,   -57,    12,   -26,   -26,
      49,   -26,   -26,    28,     0,   -26,   -26,     0,   -26,   -26,
     -57,   -26,   -57,   -41,   -26,   -41,   -41,   -41,   122,   -41,
     -52,   -52,   -41,    -2,     1,     0,     2,   -41,   -41,     0,
     -41,   -41,     0,     0,   -41,   -41,     0,   -41,   -41,   -52,
     -41,     0,   -42,   -41,   -42,   -42,   -42,     0,   -42,   -47,
     209,   -42,    -4,    -4,     0,    -4,   -42,   -42,     0,   -42,
     -42,     0,     0,   -42,   -42,     0,   -42,   -42,   -47,   -42,
       0,   -22,   -42,   -22,   -22,   -22,     0,   -22,   -49,   209,
     -22,    -5,    -5,     0,    -5,   -22,   -22,     0,   -22,   -22,
       0,     0,   -22,   -22,     0,   -22,   -22,   -49,   -22,     0,
     -29,   -22,   -29,   -29,   -29,     0,   -29,   -48,   209,   -29,
      -6,    -6,     0,    -6,   -29,   -29,     0,   -29,   -29,     0,
       0,   -29,   -29,     0,   -29,   -29,   -48,   -29,     0,   -23,
     -29,   -23,   -23,   -23,     0,   -23,   -53,   -53,   -23,    -7,
      -7,     0,    -7,   -23,   -23,     0,   -23,   -23,     0,     0,
     -23,   -23,     0,   -23,   -23,   -53,   -23,     0,   -61,   -23,
     -61,   -61,   -61,     0,   -61,   -46,   209,   -61,    -3,    -3,
       0,    -3,   -61,   -61,     0,   -61,   -61,     0,     0,   -61,
     -61,     0,   -61,   -61,   -46,   -61,     0,   -59,   -61,   -59,
     -59,   -59,     0,   -59,   -51,   -51,   -59,    -9,    -9,     0,
      -9,   -59,   -59,     0,   -59,   -59,     0,     0,   -59,   -59,
       0,   -59,   -59,   -51,   -59,     0,   -60,   -59,   -60,   -60,
     -60,     0,   -60,   -57,   -57,   -60,   -11,   -11,     0,   -11,
     -60,   -60,     0,   -60,   -60,   -54,   -54,   -60,   -60,     0,
     -60,   -60,   -57,   -60,     0,   -20,   -60,   -20,   -20,   -20,
       0,   -20,   -54,   173,   -20,   -10,   -10,     0,   -10,   -20,
     -20,     0,   -20,   -20,     0,     0,   -20,   -20,     0,   -20,
     -20,     0,   -20,     0,   -19,   -20,   -19,   -19,   -19,     0,
     -19,   -12,   -12,   -19,   -12,     0,     0,     0,   -19,   -19,
       0,   -19,   -19,     0,     0,   -19,   -19,     0,   -19,   -19,
       0,   -19,     0,   -21,   -19,   -21,   -21,   -21,     0,   -21,
       0,     0,   -21,     0,     0,     0,     0,   -21,   -21,     0,
     -21,   -21,     0,     0,   -21,   -21,     0,   -21,   -21,     0,
     -21,     0,    -9,   -21,    -9,    -9,    -9,     0,    -9,     0,
       0,    -9,     0,     0,     0,     0,    -9,    -9,     0,    -9,
      -9,     0,     0,    -9,    -9,     0,    -9,    -9,     0,    -9,
       0,   -11,    -9,   -11,   -11,   -11,     0,   -11,     0,     0,
     -11,     0,     0,     0,     0,   -11,   -11,     0,   -11,   -11,
       0,     0,   -11,   -11,     0,   -11,   -11,     0,   -11,     0,
     -12,   -11,   -12,   -12,   -12,     0,   -12,     0,     0,   -12,
       0,     0,     0,     0,   -12,   -12,     0,   -12,   -12,     0,
       0,   -12,   -12,     0,   -12,   -12,     0,   -12,    33,     0,
     -12,    35,    36,     0,    37,     0,     0,    38,     0,     0,
       0,     0,    39,    40,     0,    41,    42,     0,     0,    43,
      44,     0,    45,    46,     0,    47,    80,   121,     0,    35,
      36,     0,    37,   129,     0,    38,   130,   131,     0,   132,
       0,     0,   133,    41,    42,   -54,   -54,    43,   -54,     0,
     134,   135,    81,    47,   136,    80,     0,     0,    35,    36,
     137,    37,   -54,    76,    38,   145,   146,     0,   147,     0,
       0,   148,    41,    42,   -55,   -55,    43,   -55,     0,   149,
     150,     0,    47,   151,   185,   186,     0,   187,     0,   152,
     188,   -55,     0,   -54,   -54,     0,   -54,     0,   189,   190,
     -64,     0,   191,    74,    75,     0,     0,     0,   192,     0,
     -54,    76,   -54,   -54,     0,   -54,    77,   -56,   -56,   -64,
     -56,     0,   161,   162,   -58,   -58,     0,   -58,     0,     0,
     163,   -54,     0,     0,   -56,   164,   -50,    87,     0,   -50,
       0,   -58,   -52,   -52,     0,   -52,   -47,    87,     0,   -47,
       0,   -49,    87,   -50,   -49,   -48,    87,     0,   -48,   -52,
       0,   -53,   -53,   -47,   -53,     0,   -46,    87,   -49,   -46,
     -51,   -51,   -48,   -51,   -57,   -57,     0,   -57,   -53,     0,
       0,     0,     0,   -46,     0,     0,     0,   -51,     0,     0,
       0,   -57
};

static const yytype_int16 yycheck[] =
{
      29,     0,    30,    17,     1,    10,     3,    22,    10,    11,
      38,    13,    10,    41,    42,    13,    22,    30,    46,     4,
       5,    30,     7,    30,    29,    28,    28,    29,    17,    30,
      30,    29,    29,    46,     1,    32,     3,    22,    38,    46,
      29,    41,    42,    28,     1,    46,    46,     4,     5,    77,
       7,    79,     9,    10,     3,    10,    11,    85,    86,    87,
      30,    18,    19,    10,    77,    22,    79,    30,    46,    47,
      77,    28,    79,    86,    29,    31,    77,    77,    79,    79,
      27,   109,     6,    46,   113,    85,    86,     4,     5,    31,
       7,   119,   121,    71,   123,    17,   109,     6,    22,    77,
      78,    79,   109,    28,    27,    22,   119,    29,   109,   109,
      28,    28,   119,    22,    77,    17,    79,    28,   119,   119,
     148,   149,   150,    10,    11,    27,    13,   155,    27,     0,
       1,   109,     3,   133,   134,   135,    10,    11,   116,   167,
     168,    27,    29,    27,    10,    11,   109,   175,   148,   149,
     150,    10,    11,    27,   167,   155,   119,    27,    28,   137,
     188,   189,   190,    29,   178,    10,   166,   167,    13,    28,
      29,    17,    10,    11,   152,    13,     4,     5,    22,     7,
     208,   209,    27,    10,    11,    22,   164,   216,   188,   189,
     190,    29,    22,    17,    22,     1,    22,     3,     4,     5,
      28,     7,    29,    27,    10,    27,    10,    11,   208,    15,
      16,    17,    18,    19,   192,    29,    22,    23,    32,    25,
      26,    27,    28,    27,     1,    31,     3,     4,     5,    29,
       7,    10,    11,    10,     4,     5,    22,     7,    15,    16,
      29,    18,    19,    32,    29,    22,    23,    24,    25,    26,
      29,    28,    22,     1,    31,     3,     4,     5,    28,     7,
      10,    11,    10,    13,    10,    11,    29,    15,    16,    32,
      18,    19,    29,    29,    22,    23,    32,    25,    26,    29,
      28,    27,     1,    31,     3,     4,     5,    29,     7,    10,
      11,    10,    13,    10,    11,    29,    15,    16,    32,    18,
      19,    27,    29,    22,    23,    32,    25,    26,    29,    28,
      27,     1,    31,     3,     4,     5,    27,     7,    10,    11,
      10,    13,    10,    11,    29,    15,    16,    32,    18,    19,
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
      26,    29,    28,    27,     1,    31,     3,     4,     5,    30,
       7,    10,    11,    10,    13,    10,    11,     4,    15,    16,
      30,    18,    19,    25,    -1,    22,    23,    -1,    25,    26,
      29,    28,    27,     1,    31,     3,     4,     5,   119,     7,
      10,    11,    10,     0,     1,    -1,     3,    15,    16,    -1,
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
      -1,     7,    27,    28,    10,     0,     1,    -1,     3,    15,
      16,    -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,
      26,    -1,    28,    -1,     1,    31,     3,     4,     5,    -1,
       7,     0,     1,    10,     3,    -1,    -1,    -1,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    -1,    25,    26,
      -1,    28,    -1,     1,    31,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,
      28,    -1,     1,    31,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    26,    -1,    28,
      -1,     1,    31,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    18,    19,
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
      10,    11,    27,    13,    10,    11,    -1,    13,    27,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    35,    36,    37,    38,    39,    40,     6,
      22,     0,    37,    22,    27,    28,    27,    28,     1,     3,
      41,    42,    41,    22,    29,    32,    29,    30,    42,    30,
      47,    48,    48,     1,     3,     4,     5,     7,    10,    15,
      16,    18,    19,    22,    23,    25,    26,    28,    38,    40,
      43,    44,    45,    46,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    31,    31,    22,    22,    54,
      28,    28,    54,    54,    20,    21,    28,    33,    28,    28,
       1,    27,    50,    50,    27,    10,    13,    11,    17,    22,
       9,    50,    22,    22,    22,    50,    50,    50,    27,    29,
      54,    53,    55,    22,    29,    29,    29,    29,    29,    27,
      27,    27,    27,    30,    50,    48,    27,    31,    50,    24,
      29,    30,    51,    30,    48,    48,    31,    31,     6,     1,
       4,     5,     7,    10,    18,    19,    22,    28,    52,    53,
      54,    55,    58,    59,    27,     4,     5,     7,    10,    18,
      19,    22,    28,    54,    55,    10,    22,    22,    54,    54,
      54,    20,    21,    28,    33,    50,    10,    13,    11,    17,
      54,    54,    54,    28,    50,    11,    54,    27,    28,    22,
      22,    22,    50,    29,    54,     4,     5,     7,    10,    18,
      19,    22,    28,    53,    54,    55,    55,    22,    22,    29,
      55,    41,    29,    54,    54,    54,    28,    50,    10,    11,
      29,    29,    22,    29,    54,    55,    30,    29,    48,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    37,    38,
      39,    40,    40,    41,    41,    41,    41,    42,    43,    44,
      44,    45,    46,    46,    47,    47,    47,    47,    48,    49,
      50,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    58,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       8,     4,     9,     3,     1,     0,     1,     2,     7,    11,
       9,    11,     2,     3,     2,     2,     2,     0,     1,     2,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     2,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     4,     1,     5,
       5,     5,     3,     3,     1,     1
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
#line 97 "src/sintatico.y"
                     { 
        (yyval.node) = create_node("program");
        (yyval.node)->node1 = (yyvsp[0].node);
        root = (yyval.node);
    }
#line 1743 "src/sintatico.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 105 "src/sintatico.y"
                                 {
        (yyval.node) = create_node("declaration_list");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 1753 "src/sintatico.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 110 "src/sintatico.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1761 "src/sintatico.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 116 "src/sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1767 "src/sintatico.tab.c"
    break;

  case 6: /* declaration: function_declaration  */
#line 117 "src/sintatico.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 1773 "src/sintatico.tab.c"
    break;

  case 7: /* declaration: list_declaration  */
#line 118 "src/sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1779 "src/sintatico.tab.c"
    break;

  case 8: /* declaration: error  */
#line 119 "src/sintatico.y"
            {yyerrok;}
#line 1785 "src/sintatico.tab.c"
    break;

  case 9: /* var_declaration: SIMPLE_TYPE ID ';'  */
#line 123 "src/sintatico.y"
                       {
        symbol new_symbol = add_symbol((yyvsp[-1].token).line, (yyvsp[-1].token).columns, (yyvsp[-1].token).body, (yyvsp[-2].token).body, 0, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;

        (yyval.node) = create_node("var_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
    }
#line 1800 "src/sintatico.tab.c"
    break;

  case 10: /* function_declaration: SIMPLE_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 136 "src/sintatico.y"
                                                        {
        symbol new_symbol = add_symbol((yyvsp[-6].token).line, (yyvsp[-6].token).columns, (yyvsp[-6].token).body, (yyvsp[-7].token).body, 1, scope);
        symbol_table[table_index] = new_symbol;
        table_index++;
        table_size++;   

        (yyval.node) = create_node("function_declaration");
        (yyval.node)->node1 = create_node((yyvsp[-7].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
    }
#line 1817 "src/sintatico.tab.c"
    break;

  case 11: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID ';'  */
#line 151 "src/sintatico.y"
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

        (yyval.node) = create_node("list_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
    }
#line 1839 "src/sintatico.tab.c"
    break;

  case 12: /* list_declaration: SIMPLE_TYPE LIST_TYPE ID '(' params ')' '{' multiple_stmt '}'  */
#line 168 "src/sintatico.y"
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
        
        (yyval.node) = create_node("list_declaration");
        (yyval.node)->node1 = create_node(list_string);
        (yyval.node)->node2 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node3 = (yyvsp[-4].node);
        (yyval.node)->node4 = (yyvsp[-1].node);
        
    }
#line 1864 "src/sintatico.tab.c"
    break;

  case 13: /* params: params ',' param  */
#line 191 "src/sintatico.y"
                     {
        (yyval.node) = create_node("params");
        (yyval.node)->node1 = (yyvsp[0].node);
    }
#line 1873 "src/sintatico.tab.c"
    break;

  case 14: /* params: param  */
#line 195 "src/sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1879 "src/sintatico.tab.c"
    break;

  case 15: /* params: %empty  */
#line 196 "src/sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 1887 "src/sintatico.tab.c"
    break;

  case 16: /* params: error  */
#line 199 "src/sintatico.y"
            {yyerrok;}
#line 1893 "src/sintatico.tab.c"
    break;

  case 17: /* param: SIMPLE_TYPE ID  */
#line 203 "src/sintatico.y"
                   {
        (yyval.node) = create_node("param");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = create_node((yyvsp[0].token).body);
    }
#line 1903 "src/sintatico.tab.c"
    break;

  case 18: /* if_stmt: IF '(' expression ')' '{' multiple_stmt '}'  */
#line 211 "src/sintatico.y"
                                                {
        (yyval.node) = create_node("if_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-6].token).body);
        (yyval.node)->node2 = (yyvsp[-4].node);
        (yyval.node)->node3 = (yyvsp[-1].node);
    }
#line 1914 "src/sintatico.tab.c"
    break;

  case 19: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE '{' multiple_stmt '}'  */
#line 220 "src/sintatico.y"
                                                                           {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-5].node);
        (yyval.node)->node4 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 1927 "src/sintatico.tab.c"
    break;

  case 20: /* if_else_stmt: IF '(' expression ')' '{' multiple_stmt '}' ELSE stmt  */
#line 228 "src/sintatico.y"
                                                            {
        (yyval.node) = create_node("if_else_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-8].token).body);
        (yyval.node)->node2 = (yyvsp[-6].node);
        (yyval.node)->node3 = (yyvsp[-3].node);
        (yyval.node)->node4 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node5 = (yyvsp[0].node);
    }
#line 1940 "src/sintatico.tab.c"
    break;

  case 21: /* for_stmt: FOR '(' expression ';' expression ';' expression ')' '{' multiple_stmt '}'  */
#line 239 "src/sintatico.y"
                                                                               {
        (yyval.node) = create_node("for_stmt");
        (yyval.node)->node1 = create_node((yyvsp[-10].token).body);
        (yyval.node)->node2 = (yyvsp[-8].node);
        (yyval.node)->node3 = (yyvsp[-6].node);
        (yyval.node)->node4 = (yyvsp[-4].node);
        (yyval.node)->node5 = (yyvsp[-1].node);
    }
#line 1953 "src/sintatico.tab.c"
    break;

  case 22: /* return_stmt: RETURN ';'  */
#line 250 "src/sintatico.y"
               {(yyval.node) = create_node((yyvsp[-1].token).body);}
#line 1959 "src/sintatico.tab.c"
    break;

  case 23: /* return_stmt: RETURN expression ';'  */
#line 251 "src/sintatico.y"
                            {
        (yyval.node) = create_node((yyvsp[-2].token).body);
        (yyval.node)->node1 = (yyvsp[-1].node);
    }
#line 1968 "src/sintatico.tab.c"
    break;

  case 24: /* general_declaration: general_declaration var_declaration  */
#line 258 "src/sintatico.y"
                                        {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 1978 "src/sintatico.tab.c"
    break;

  case 25: /* general_declaration: general_declaration list_declaration  */
#line 263 "src/sintatico.y"
                                           {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 1988 "src/sintatico.tab.c"
    break;

  case 26: /* general_declaration: general_declaration stmt  */
#line 268 "src/sintatico.y"
                               {
        (yyval.node) = create_node("general_declaration");
        (yyval.node)->node1 = (yyvsp[-1].node);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 1998 "src/sintatico.tab.c"
    break;

  case 27: /* general_declaration: %empty  */
#line 273 "src/sintatico.y"
             {
        (yyval.node) = create_node("empty");
    }
#line 2006 "src/sintatico.tab.c"
    break;

  case 28: /* multiple_stmt: general_declaration  */
#line 279 "src/sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2012 "src/sintatico.tab.c"
    break;

  case 29: /* expression_stmt: expression ';'  */
#line 283 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[-1].node);}
#line 2018 "src/sintatico.tab.c"
    break;

  case 30: /* expression: ID '=' expression  */
#line 287 "src/sintatico.y"
                      {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2028 "src/sintatico.tab.c"
    break;

  case 31: /* expression: simple_expression  */
#line 292 "src/sintatico.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2034 "src/sintatico.tab.c"
    break;

  case 32: /* expression: binary_construct  */
#line 293 "src/sintatico.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2040 "src/sintatico.tab.c"
    break;

  case 33: /* expression: ID MAP ID  */
#line 294 "src/sintatico.y"
                {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2051 "src/sintatico.tab.c"
    break;

  case 34: /* expression: ID FILTER ID  */
#line 300 "src/sintatico.y"
                   {
        (yyval.node) = create_node("expression");
        (yyval.node)->node1 = create_node((yyvsp[-2].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2062 "src/sintatico.tab.c"
    break;

  case 35: /* expression: error  */
#line 306 "src/sintatico.y"
            {yyerrok;}
#line 2068 "src/sintatico.tab.c"
    break;

  case 36: /* stmt: expression_stmt  */
#line 310 "src/sintatico.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 2074 "src/sintatico.tab.c"
    break;

  case 37: /* stmt: if_stmt  */
#line 311 "src/sintatico.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 2080 "src/sintatico.tab.c"
    break;

  case 38: /* stmt: if_else_stmt  */
#line 312 "src/sintatico.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2086 "src/sintatico.tab.c"
    break;

  case 39: /* stmt: for_stmt  */
#line 313 "src/sintatico.y"
               {(yyval.node) = (yyvsp[0].node);}
#line 2092 "src/sintatico.tab.c"
    break;

  case 40: /* stmt: return_stmt  */
#line 314 "src/sintatico.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2098 "src/sintatico.tab.c"
    break;

  case 41: /* stmt: print  */
#line 315 "src/sintatico.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 2104 "src/sintatico.tab.c"
    break;

  case 42: /* stmt: scan  */
#line 316 "src/sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2110 "src/sintatico.tab.c"
    break;

  case 43: /* stmt: error  */
#line 317 "src/sintatico.y"
            {yyerrok;}
#line 2116 "src/sintatico.tab.c"
    break;

  case 44: /* simple_expression: arithmetic_expression BINARY_COMP_OP arithmetic_expression  */
#line 322 "src/sintatico.y"
                                                               {
        (yyval.node) = create_node("simple_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
    }
#line 2127 "src/sintatico.tab.c"
    break;

  case 45: /* simple_expression: arithmetic_expression  */
#line 328 "src/sintatico.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2133 "src/sintatico.tab.c"
    break;

  case 46: /* arithmetic_expression: arithmetic_expression BINARY_BASIC_OP1 term  */
#line 332 "src/sintatico.y"
                                                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
    }
#line 2144 "src/sintatico.tab.c"
    break;

  case 47: /* arithmetic_expression: BINARY_BASIC_OP1 term  */
#line 338 "src/sintatico.y"
                            {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2154 "src/sintatico.tab.c"
    break;

  case 48: /* arithmetic_expression: TAIL term  */
#line 343 "src/sintatico.y"
                {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2164 "src/sintatico.tab.c"
    break;

  case 49: /* arithmetic_expression: HEADER term  */
#line 348 "src/sintatico.y"
                  {
        (yyval.node) = create_node("arithmetic_expression");
        (yyval.node)->node1 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node2 = (yyvsp[0].node);
    }
#line 2174 "src/sintatico.tab.c"
    break;

  case 50: /* arithmetic_expression: term  */
#line 353 "src/sintatico.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 2180 "src/sintatico.tab.c"
    break;

  case 51: /* term: term BINARY_BASIC_OP2 factor  */
#line 357 "src/sintatico.y"
                                 {
        (yyval.node) = create_node("term");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = (yyvsp[0].node);
    }
#line 2191 "src/sintatico.tab.c"
    break;

  case 52: /* term: factor  */
#line 363 "src/sintatico.y"
             {(yyval.node) = (yyvsp[0].node);}
#line 2197 "src/sintatico.tab.c"
    break;

  case 53: /* factor: '(' expression ')'  */
#line 367 "src/sintatico.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2203 "src/sintatico.tab.c"
    break;

  case 54: /* factor: ID  */
#line 368 "src/sintatico.y"
         {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2209 "src/sintatico.tab.c"
    break;

  case 55: /* factor: INT  */
#line 369 "src/sintatico.y"
          {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2215 "src/sintatico.tab.c"
    break;

  case 56: /* factor: FLOAT  */
#line 370 "src/sintatico.y"
            {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2221 "src/sintatico.tab.c"
    break;

  case 57: /* factor: ID '(' ID ')'  */
#line 371 "src/sintatico.y"
                    {
        (yyval.node) = create_node("factor");
        (yyval.node)->node1 = create_node((yyvsp[-3].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
    }
#line 2231 "src/sintatico.tab.c"
    break;

  case 58: /* factor: LIST_CONSTANT  */
#line 376 "src/sintatico.y"
                    {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2237 "src/sintatico.tab.c"
    break;

  case 59: /* print: OUTPUT '(' STRING ')' ';'  */
#line 380 "src/sintatico.y"
                              {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2247 "src/sintatico.tab.c"
    break;

  case 60: /* print: OUTPUT '(' expression ')' ';'  */
#line 385 "src/sintatico.y"
                                    {
        (yyval.node) = create_node("print");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = (yyvsp[-2].node);
    }
#line 2257 "src/sintatico.tab.c"
    break;

  case 61: /* scan: INPUT '(' ID ')' ';'  */
#line 393 "src/sintatico.y"
                         {
        (yyval.node) = create_node("scan");
        (yyval.node)->node1 = create_node((yyvsp[-4].token).body);
        (yyval.node)->node2 = create_node((yyvsp[-2].token).body);
    }
#line 2267 "src/sintatico.tab.c"
    break;

  case 62: /* binary_construct: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 401 "src/sintatico.y"
                                                     {
        (yyval.node) = create_node("binary_constructor");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2278 "src/sintatico.tab.c"
    break;

  case 63: /* binary_construct_recursive: binary_construct_recursive BINARY_CONSTRUCTOR ID  */
#line 410 "src/sintatico.y"
                                                     {
        (yyval.node) = create_node("binary_constructor_recursive");
        (yyval.node)->node1 = (yyvsp[-2].node);
        (yyval.node)->node2 = create_node((yyvsp[-1].token).body);
        (yyval.node)->node3 = create_node((yyvsp[0].token).body);
    }
#line 2289 "src/sintatico.tab.c"
    break;

  case 64: /* binary_construct_recursive: ID  */
#line 416 "src/sintatico.y"
         {(yyval.node) = create_node((yyvsp[0].token).body);}
#line 2295 "src/sintatico.tab.c"
    break;

  case 65: /* binary_construct_recursive: error  */
#line 417 "src/sintatico.y"
            {yyerrok;}
#line 2301 "src/sintatico.tab.c"
    break;


#line 2305 "src/sintatico.tab.c"

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

#line 422 "src/sintatico.y"


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
    free_node(root);
    fclose(yyin);    
    yylex_destroy();
    return 0;
}
