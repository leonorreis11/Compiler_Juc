/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "jucompiler.y"

/* Ricardo Santiago 2020219352
   Leonor Reis 2019210146
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "syntax_tree.h"


ast_tree* root;
ast_tree* temp;
ast_tree* temp2;
ast_tree* temp3;


int yylex(void);
extern void yyerror(const char*);
extern int num_line;
extern int num_column;

  

#line 98 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    ID = 258,                      /* ID  */
    INTLIT = 259,                  /* INTLIT  */
    REALLIT = 260,                 /* REALLIT  */
    BOOLLIT = 261,                 /* BOOLLIT  */
    STRLIT = 262,                  /* STRLIT  */
    AND = 263,                     /* AND  */
    ASSIGN = 264,                  /* ASSIGN  */
    STAR = 265,                    /* STAR  */
    DIV = 266,                     /* DIV  */
    EQ = 267,                      /* EQ  */
    GE = 268,                      /* GE  */
    GT = 269,                      /* GT  */
    LE = 270,                      /* LE  */
    LT = 271,                      /* LT  */
    MINUS = 272,                   /* MINUS  */
    MOD = 273,                     /* MOD  */
    NE = 274,                      /* NE  */
    NOT = 275,                     /* NOT  */
    OR = 276,                      /* OR  */
    PLUS = 277,                    /* PLUS  */
    LSHIFT = 278,                  /* LSHIFT  */
    RSHIFT = 279,                  /* RSHIFT  */
    DOTLENGTH = 280,               /* DOTLENGTH  */
    PRINT = 281,                   /* PRINT  */
    PARSEINT = 282,                /* PARSEINT  */
    RETURN = 283,                  /* RETURN  */
    XOR = 284,                     /* XOR  */
    COMMA = 285,                   /* COMMA  */
    PUBLIC = 286,                  /* PUBLIC  */
    BOOL = 287,                    /* BOOL  */
    RESERVED = 288,                /* RESERVED  */
    INT = 289,                     /* INT  */
    DOUBLE = 290,                  /* DOUBLE  */
    STATIC = 291,                  /* STATIC  */
    STRING = 292,                  /* STRING  */
    VOID = 293,                    /* VOID  */
    WHILE = 294,                   /* WHILE  */
    LBRACE = 295,                  /* LBRACE  */
    LPAR = 296,                    /* LPAR  */
    LSQ = 297,                     /* LSQ  */
    RBRACE = 298,                  /* RBRACE  */
    RPAR = 299,                    /* RPAR  */
    RSQ = 300,                     /* RSQ  */
    SEMICOLON = 301,               /* SEMICOLON  */
    ARROW = 302,                   /* ARROW  */
    CLASS = 303,                   /* CLASS  */
    ELSE = 304,                    /* ELSE  */
    IF = 305                       /* IF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INTLIT 259
#define REALLIT 260
#define BOOLLIT 261
#define STRLIT 262
#define AND 263
#define ASSIGN 264
#define STAR 265
#define DIV 266
#define EQ 267
#define GE 268
#define GT 269
#define LE 270
#define LT 271
#define MINUS 272
#define MOD 273
#define NE 274
#define NOT 275
#define OR 276
#define PLUS 277
#define LSHIFT 278
#define RSHIFT 279
#define DOTLENGTH 280
#define PRINT 281
#define PARSEINT 282
#define RETURN 283
#define XOR 284
#define COMMA 285
#define PUBLIC 286
#define BOOL 287
#define RESERVED 288
#define INT 289
#define DOUBLE 290
#define STATIC 291
#define STRING 292
#define VOID 293
#define WHILE 294
#define LBRACE 295
#define LPAR 296
#define LSQ 297
#define RBRACE 298
#define RPAR 299
#define RSQ 300
#define SEMICOLON 301
#define ARROW 302
#define CLASS 303
#define ELSE 304
#define IF 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "jucompiler.y"

    struct token *token;
    struct node* node;

#line 256 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTLIT = 4,                     /* INTLIT  */
  YYSYMBOL_REALLIT = 5,                    /* REALLIT  */
  YYSYMBOL_BOOLLIT = 6,                    /* BOOLLIT  */
  YYSYMBOL_STRLIT = 7,                     /* STRLIT  */
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_STAR = 10,                      /* STAR  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_MOD = 18,                       /* MOD  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_LSHIFT = 23,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 24,                    /* RSHIFT  */
  YYSYMBOL_DOTLENGTH = 25,                 /* DOTLENGTH  */
  YYSYMBOL_PRINT = 26,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 27,                  /* PARSEINT  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_XOR = 29,                       /* XOR  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_PUBLIC = 31,                    /* PUBLIC  */
  YYSYMBOL_BOOL = 32,                      /* BOOL  */
  YYSYMBOL_RESERVED = 33,                  /* RESERVED  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_DOUBLE = 35,                    /* DOUBLE  */
  YYSYMBOL_STATIC = 36,                    /* STATIC  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_VOID = 38,                      /* VOID  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_LPAR = 41,                      /* LPAR  */
  YYSYMBOL_LSQ = 42,                       /* LSQ  */
  YYSYMBOL_RBRACE = 43,                    /* RBRACE  */
  YYSYMBOL_RPAR = 44,                      /* RPAR  */
  YYSYMBOL_RSQ = 45,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 47,                     /* ARROW  */
  YYSYMBOL_CLASS = 48,                     /* CLASS  */
  YYSYMBOL_ELSE = 49,                      /* ELSE  */
  YYSYMBOL_IF = 50,                        /* IF  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_Program1 = 53,                  /* Program1  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FieldDeclRep = 56,              /* FieldDeclRep  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_FormalParams1 = 60,             /* FormalParams1  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_MethodBody1 = 62,               /* MethodBody1  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_VarDeclRep = 64,                /* VarDeclRep  */
  YYSYMBOL_Statement = 65,                 /* Statement  */
  YYSYMBOL_Statement1 = 66,                /* Statement1  */
  YYSYMBOL_MethodInvocation = 67,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocation1 = 68,         /* MethodInvocation1  */
  YYSYMBOL_Assignment = 69,                /* Assignment  */
  YYSYMBOL_ParseArgs = 70,                 /* ParseArgs  */
  YYSYMBOL_Expr = 71,                      /* Expr  */
  YYSYMBOL_Expr1 = 72                      /* Expr1  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    78,    79,    86,    87,    89,    96,   114,
     117,   120,   123,   124,   125,   128,   137,   146,   153,   162,
     167,   174,   180,   183,   189,   197,   198,   201,   219,   223,
     226,   237,   264,   279,   294,   295,   297,   298,   299,   300,
     301,   304,   309,   313,   322,   326,   331,   337,   341,   348,
     352,   359,   364,   367,   368,   371,   375,   379,   383,   387,
     391,   396,   400,   404,   408,   412,   416,   420,   424,   428,
     431,   435,   438,   441,   444,   445,   446,   447,   448,   451,
     452,   453,   454
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTLIT",
  "REALLIT", "BOOLLIT", "STRLIT", "AND", "ASSIGN", "STAR", "DIV", "EQ",
  "GE", "GT", "LE", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "LSHIFT", "RSHIFT", "DOTLENGTH", "PRINT", "PARSEINT", "RETURN", "XOR",
  "COMMA", "PUBLIC", "BOOL", "RESERVED", "INT", "DOUBLE", "STATIC",
  "STRING", "VOID", "WHILE", "LBRACE", "LPAR", "LSQ", "RBRACE", "RPAR",
  "RSQ", "SEMICOLON", "ARROW", "CLASS", "ELSE", "IF", "$accept", "Program",
  "Program1", "MethodDecl", "FieldDecl", "FieldDeclRep", "Type",
  "MethodHeader", "FormalParams", "FormalParams1", "MethodBody",
  "MethodBody1", "VarDecl", "VarDeclRep", "Statement", "Statement1",
  "MethodInvocation", "MethodInvocation1", "Assignment", "ParseArgs",
  "Expr", "Expr1", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,     8,    36,     1,   -44,     2,     0,   -21,     2,     6,
       2,     2,   -44,   -25,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,    40,    56,    25,    29,    12,    65,   -44,    23,    85,
     232,    48,    49,    -3,    57,    60,   182,    62,   115,   -44,
      68,    93,    63,    65,    65,    71,    73,    76,    72,   -44,
     120,    80,    96,   -44,    83,   -44,   -44,   233,   174,   227,
      31,    15,   -44,   -44,   -44,   253,   253,   253,   202,   -44,
     -44,   -44,   -44,    82,   274,   233,   115,    86,   233,   100,
     -44,   -44,   -44,   -44,   -44,   -44,    94,   108,   -44,   -44,
     -44,   -44,   101,   -44,   110,   103,   105,   107,   111,   -44,
      10,   -44,   -44,   -44,   116,   118,   -44,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   122,   -44,   -44,   123,   156,   126,   170,
      55,   -44,   -44,   233,   130,   135,   138,   -44,   233,   -44,
     -44,   314,   -44,   -44,   349,   203,   203,   203,   203,    51,
     -44,   349,   294,    51,   146,   146,   334,   143,   143,   100,
     -44,   -44,   173,   110,   -44,   -44,   -44,   145,   -44,   148,
     -44,   108,   -44,   151,   143,   -44,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     5,     2,     3,     4,    12,    13,
      14,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    11,    17,     0,     8,    42,     0,     0,     0,
       0,    77,    79,    80,    81,     0,     0,     0,     0,    34,
      75,    53,    76,     0,    54,     0,     0,     0,     0,    29,
      23,    25,    24,    36,    37,    38,     0,    22,    16,    10,
      15,    50,     0,    45,    49,     0,     0,     0,     0,    78,
      77,    71,    72,    73,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    30,     0,     0,     0,     0,
       0,    19,    47,     0,     0,     0,     0,    52,     0,    82,
      74,    60,    57,    58,    65,    66,    67,    68,    69,    56,
      59,    70,    61,    55,    63,    64,    62,     0,     0,    29,
      27,    20,     0,    49,    46,    41,    40,     0,    33,    32,
      28,    22,    48,     0,     0,    21,    51,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   102,   -44,   -44,   140,    -5,   -44,   168,    39,
     -44,    20,   -44,    41,   -37,   136,   -26,    53,   -24,   -22,
     -31,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    51,   131,
      27,    42,    43,   128,    44,    77,    70,   134,    71,    72,
      73,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    76,    46,     6,    47,     1,    57,    18,    22,    19,
      20,     3,    45,    21,    46,    13,    47,    45,    45,    46,
      46,    47,    47,    50,    57,    50,    91,    94,    96,   101,
     102,   103,    97,     7,    98,    99,     4,   105,    58,    76,
      99,     5,    29,    24,   123,    -6,    12,   126,     8,    15,
      45,    58,    46,    30,    47,    18,    58,    19,    20,    25,
      48,   108,   109,    81,    82,    26,    32,    49,    33,   116,
      28,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    18,    52,    19,
      20,    34,    35,    36,    55,    56,    79,    18,    59,    19,
      20,    60,   163,    75,    37,    38,    80,   167,   -26,    78,
      14,    39,    16,    17,    86,    40,    32,    83,    33,    84,
     168,   169,    85,    87,    88,   162,    29,    90,   106,   125,
     127,    45,    45,    46,    46,    47,    47,   177,   130,   129,
     133,    34,    35,    36,    32,   132,    33,   135,    45,   136,
      46,   137,    47,   138,    37,    38,   108,   109,   -44,   159,
     139,    39,   140,   115,   116,    40,   157,   158,   119,    34,
      35,    36,   160,   161,   164,    92,   171,    61,    62,    63,
      64,   165,    37,    38,   166,    61,    62,    63,    64,    39,
     173,    65,    89,    40,    66,   176,    67,   174,    54,    65,
     170,    35,    66,   104,    67,    61,    62,    63,    64,    35,
     175,     0,   124,   108,   109,    68,   172,     0,    93,    65,
     115,   116,    66,    68,    67,   119,   120,   121,    69,    35,
      61,    62,    63,    64,    95,     0,    61,    62,    63,    64,
       0,     0,     0,    68,    65,     0,     0,    66,     0,    67,
      65,     0,     0,    66,    35,    67,   100,    62,    63,    64,
      35,     0,     0,     0,    18,     0,    19,    20,    68,    48,
      65,     0,     0,    66,    68,    67,    53,     0,     0,     0,
      35,     0,   107,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    68,   118,   119,   120,   121,     0,
       0,     0,   107,   122,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,   119,   120,   121,     0,
       0,     0,     0,   122,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,   119,   120,   121,     0,
       0,     0,     0,   122,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,   119,   120,   121,   108,
     109,     0,   111,   112,   113,   114,   115,   116,     0,     0,
       0,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
      26,    38,    26,     1,    26,    48,     9,    32,    13,    34,
      35,     3,    38,    38,    38,    36,    38,    43,    44,    43,
      44,    43,    44,    28,     9,    30,    57,    58,    59,    65,
      66,    67,     1,    31,     3,    25,     0,    68,    41,    76,
      25,    40,    30,     3,    75,    43,    46,    78,    46,    43,
      76,    41,    76,    41,    76,    32,    41,    34,    35,     3,
      37,    10,    11,    43,    44,    40,     1,    44,     3,    18,
      41,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    32,     3,    34,
      35,    26,    27,    28,    46,    46,     3,    32,    41,    34,
      35,    41,   133,    41,    39,    40,    43,   138,    43,    41,
       8,    46,    10,    11,    42,    50,     1,    46,     3,    46,
     157,   158,    46,     3,    44,   130,    30,    44,    46,    43,
      30,   157,   158,   157,   158,   157,   158,   174,    30,    45,
      30,    26,    27,    28,     1,    44,     3,    44,   174,    44,
     174,    44,   174,    42,    39,    40,    10,    11,    43,     3,
      44,    46,    44,    17,    18,    50,    44,    44,    22,    26,
      27,    28,    46,     3,    44,     1,     3,     3,     4,     5,
       6,    46,    39,    40,    46,     3,     4,     5,     6,    46,
      45,    17,    52,    50,    20,    44,    22,    49,    30,    17,
     159,    27,    20,     1,    22,     3,     4,     5,     6,    27,
     171,    -1,    76,    10,    11,    41,   163,    -1,    44,    17,
      17,    18,    20,    41,    22,    22,    23,    24,    46,    27,
       3,     4,     5,     6,     7,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    41,    17,    -1,    -1,    20,    -1,    22,
      17,    -1,    -1,    20,    27,    22,     3,     4,     5,     6,
      27,    -1,    -1,    -1,    32,    -1,    34,    35,    41,    37,
      17,    -1,    -1,    20,    41,    22,    44,    -1,    -1,    -1,
      27,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    41,    21,    22,    23,    24,    -1,
      -1,    -1,     8,    29,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    52,     3,     0,    40,     1,    31,    46,    53,
      54,    55,    46,    36,    53,    43,    53,    53,    32,    34,
      35,    38,    57,    58,     3,     3,    40,    61,    41,    30,
      41,    56,     1,     3,    26,    27,    28,    39,    40,    46,
      50,    57,    62,    63,    65,    67,    69,    70,    37,    44,
      57,    59,     3,    44,    59,    46,    46,     9,    41,    41,
      41,     3,     4,     5,     6,    17,    20,    22,    41,    46,
      67,    69,    70,    71,    72,    41,    65,    66,    41,     3,
      43,    62,    62,    46,    46,    46,    42,     3,    44,    56,
      44,    71,     1,    44,    71,     7,    71,     1,     3,    25,
       3,    72,    72,    72,     1,    71,    46,     8,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    21,    22,
      23,    24,    29,    71,    66,    43,    71,    30,    64,    45,
      30,    60,    44,    30,    68,    44,    44,    44,    42,    44,
      44,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    44,    44,     3,
      46,     3,    57,    71,    44,    46,    46,    71,    65,    65,
      64,     3,    68,    45,    49,    60,    44,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     4,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     7,     5,     5,     2,     3,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     3,     5,     4,     3,     0,
       3,     7,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1,     1,     2,     1,
       1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* Program: CLASS ID LBRACE Program1 RBRACE  */
#line 69 "jucompiler.y"
                                                    { (yyval.node)=root= create_node("Program",gen_token("",num_line,num_column));
                                                        temp =create_node("Id",(yyvsp[-3].token));
                                                        adicionar_filho(root,temp);
                                                        adicionar_filho(root,(yyvsp[-1].node));
                                                        }
#line 1465 "y.tab.c"
    break;

  case 3: /* Program1: MethodDecl Program1  */
#line 78 "jucompiler.y"
                                                    {(yyval.node) = (yyvsp[-1].node); adicionar_irmao((yyval.node),(yyvsp[0].node)); }
#line 1471 "y.tab.c"
    break;

  case 4: /* Program1: FieldDecl Program1  */
#line 79 "jucompiler.y"
                                                     {if((yyvsp[-1].node) != NULL){
                                                        (yyval.node) = (yyvsp[-1].node); 
                                                        adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                       }else{
                                                        (yyval.node) =(yyvsp[0].node);
                                                        }
                                                    }
#line 1483 "y.tab.c"
    break;

  case 5: /* Program1: SEMICOLON Program1  */
#line 86 "jucompiler.y"
                                                       {(yyval.node) = (yyvsp[0].node);}
#line 1489 "y.tab.c"
    break;

  case 6: /* Program1: %empty  */
#line 87 "jucompiler.y"
                                                    {(yyval.node) = NULL;}
#line 1495 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 89 "jucompiler.y"
                                                    {(yyval.node) = create_node("MethodDecl",gen_token("",num_line,num_column));
                                                     adicionar_filho((yyval.node),(yyvsp[-1].node));
                                                        adicionar_filho((yyval.node),(yyvsp[0].node));
                                                        
                                                       }
#line 1505 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID FieldDeclRep SEMICOLON  */
#line 96 "jucompiler.y"
                                                          {(yyval.node) = create_node("FieldDecl",gen_token("",num_line,num_column));
                                                                adicionar_filho((yyval.node),(yyvsp[-3].node));
                                                                adicionar_filho((yyval.node),create_node("Id",(yyvsp[-2].token)));
                                                                if((yyvsp[-1].node) != NULL){
                                                                    temp = (yyvsp[-1].node);   
                                                                        while(temp!=NULL){
                                                                            
                                                                            temp2= create_node("FieldDecl",gen_token("",num_line,num_column));
                                                                             temp3=create_node((yyvsp[-3].node)->type,(yyvsp[-3].node)->token);
                                                                              adicionar_filho(temp2,temp3);
                                                                              adicionar_filho(temp2,create_node("Id",temp->token));
                                                                              adicionar_irmao((yyval.node),temp2);

                                                                             temp=temp->irmao;
                                                                       }
                                                                }
                                                           
                                                            }
#line 1528 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 114 "jucompiler.y"
                                                        {(yyval.node) = NULL; }
#line 1534 "y.tab.c"
    break;

  case 10: /* FieldDeclRep: COMMA ID FieldDeclRep  */
#line 117 "jucompiler.y"
                                                            {(yyval.node) =temp=create_node("Id",(yyvsp[-1].token));
                                                    adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                   }
#line 1542 "y.tab.c"
    break;

  case 11: /* FieldDeclRep: %empty  */
#line 120 "jucompiler.y"
                                                        {(yyval.node)= NULL;}
#line 1548 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 123 "jucompiler.y"
                                                        {(yyval.node) = create_node("Bool",gen_token("",num_line,num_column));}
#line 1554 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 124 "jucompiler.y"
                                                         {(yyval.node) =create_node("Int",gen_token("",num_line,num_column));}
#line 1560 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 125 "jucompiler.y"
                                                        {(yyval.node) =create_node("Double",gen_token("",num_line,num_column));}
#line 1566 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 128 "jucompiler.y"
                                                        {(yyval.node) = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                          adicionar_filho((yyval.node),(yyvsp[-4].node));
                                                          temp =create_node("Id",(yyvsp[-3].token));
                                                          adicionar_filho((yyval.node),temp);
                                                            temp2= create_node("MethodParams",gen_token("",num_line,num_column));
                                                            adicionar_filho((yyval.node),temp2);
                                                             adicionar_filho(temp2,(yyvsp[-1].node));
                                                           
                                                            }
#line 1580 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 137 "jucompiler.y"
                                                        {(yyval.node) = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                        temp=create_node("Void",gen_token("",num_line,num_column));
                                                        adicionar_filho((yyval.node),temp);
                                                        adicionar_filho((yyval.node),create_node("Id",(yyvsp[-3].token)));
                                                        temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho((yyval.node),temp2);
                                                        adicionar_filho(temp2,(yyvsp[-1].node));
                                                        
                                                        }
#line 1594 "y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 146 "jucompiler.y"
                                                        {(yyval.node) = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                         adicionar_filho((yyval.node),(yyvsp[-3].node));
                                                         adicionar_filho((yyval.node),create_node("Id",(yyvsp[-2].token)));
                                                         temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho((yyval.node),temp2);
                                                         
                                                         }
#line 1606 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 153 "jucompiler.y"
                                                        {(yyval.node) = create_node("MethodHeader",gen_token("",num_line,num_column));
                                                            temp=create_node("Void",gen_token("",num_line,num_column));
                                                            adicionar_filho((yyval.node),temp);
                                                            adicionar_filho((yyval.node),create_node("Id",(yyvsp[-2].token)));
                                                            temp2 = create_node("MethodParams",gen_token("",num_line,num_column));
                                                        adicionar_filho((yyval.node),temp2);
                                                            }
#line 1618 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID FormalParams1  */
#line 162 "jucompiler.y"
                                                        {(yyval.node)= create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                            adicionar_filho((yyval.node),create_node("Id",(yyvsp[-1].token)));
                                                            adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                             }
#line 1628 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 167 "jucompiler.y"
                                                         {(yyval.node) = create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            temp=create_node("StringArray",gen_token("",num_line,num_column));
                                                            adicionar_filho((yyval.node),temp);
                                                             adicionar_filho((yyval.node),create_node("Id",(yyvsp[0].token)));
                                                             }
#line 1638 "y.tab.c"
    break;

  case 21: /* FormalParams1: COMMA Type ID FormalParams1  */
#line 174 "jucompiler.y"
                                                        {(yyval.node) = create_node("ParamDecl",gen_token("",num_line,num_column));
                                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                            adicionar_filho((yyval.node),create_node("Id",(yyvsp[-1].token)));
                                                            adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                           
                                                            }
#line 1649 "y.tab.c"
    break;

  case 22: /* FormalParams1: %empty  */
#line 180 "jucompiler.y"
                                                        {(yyval.node)= NULL;}
#line 1655 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE MethodBody1 RBRACE  */
#line 183 "jucompiler.y"
                                                    {(yyval.node) = create_node("MethodBody",gen_token("",num_line,num_column));
                                                    adicionar_filho((yyval.node),(yyvsp[-1].node));
                                                  
                                                    }
#line 1664 "y.tab.c"
    break;

  case 24: /* MethodBody1: Statement MethodBody1  */
#line 189 "jucompiler.y"
                                                    { 
                                                    if((yyvsp[-1].node) != NULL){
                                                    (yyval.node)=(yyvsp[-1].node);
                                                    adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                    }else{
                                                    (yyval.node)=(yyvsp[0].node);
                                                    }     
                                                    }
#line 1677 "y.tab.c"
    break;

  case 25: /* MethodBody1: VarDecl MethodBody1  */
#line 197 "jucompiler.y"
                                                    {(yyval.node)=(yyvsp[-1].node);adicionar_irmao((yyval.node),(yyvsp[0].node));}
#line 1683 "y.tab.c"
    break;

  case 26: /* MethodBody1: %empty  */
#line 198 "jucompiler.y"
                                                    {(yyval.node) = NULL;}
#line 1689 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID VarDeclRep SEMICOLON  */
#line 201 "jucompiler.y"
                                                    {(yyval.node) = create_node("VarDecl",gen_token("",num_line,num_column));
                                                        adicionar_filho((yyval.node),(yyvsp[-3].node));
                                                        adicionar_filho((yyval.node),create_node("Id",(yyvsp[-2].token)));
                                                       
                                                        if((yyvsp[-1].node) != NULL){
                                                            temp=(yyvsp[-1].node);
                                                            while(temp!=NULL){
                                                                temp2= create_node("VarDecl",gen_token("",num_line,num_column));
                                                                temp3=create_node((yyvsp[-3].node)->type,(yyvsp[-3].node)->token);
                                                                adicionar_filho(temp2,temp3);
                                                                adicionar_filho(temp2,create_node("Id",temp->token));
                                                                adicionar_irmao((yyval.node),temp2);
                                                                temp=temp->irmao;
                                                            }
                                                        }
                                                        }
#line 1710 "y.tab.c"
    break;

  case 28: /* VarDeclRep: COMMA ID VarDeclRep  */
#line 219 "jucompiler.y"
                                                        {(yyval.node) = temp = create_node("Id",(yyvsp[-1].token));
                                                                adicionar_irmao((yyval.node),(yyvsp[0].node));
                                                              
                                                                }
#line 1719 "y.tab.c"
    break;

  case 29: /* VarDeclRep: %empty  */
#line 223 "jucompiler.y"
                                                        {(yyval.node)= NULL;}
#line 1725 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE Statement1 RBRACE  */
#line 226 "jucompiler.y"
                                                   {   
                                                        if ( block_count((yyvsp[-1].node)) > 1 ) {
														temp = create_node( "Block",gen_token("",num_line,num_column));
														(yyval.node) = temp;
														adicionar_filho(temp, (yyvsp[-1].node));
														}
														else {
														(yyval.node) = (yyvsp[-1].node);
															}
                                                           
                                                            }
#line 1741 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 237 "jucompiler.y"
                                             {
                                                    (yyval.node) = create_node("If",gen_token("",num_line,num_column));
												adicionar_filho((yyval.node),(yyvsp[-4].node));
												temp = create_node( "Block",gen_token("",num_line,num_column));
												if (block_count((yyvsp[-2].node)) == 1 && (yyvsp[-2].node) != NULL) {
													adicionar_filho((yyval.node), (yyvsp[-2].node));
													if (block_count((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
														adicionar_filho((yyval.node), (yyvsp[0].node));
													}
													else {
														adicionar_filho((yyval.node), temp);
														adicionar_filho(temp, (yyvsp[0].node));
													}
												}
												else {
														adicionar_filho((yyval.node), temp);
														adicionar_filho(temp, (yyvsp[-2].node));
														if (block_count((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
															adicionar_filho((yyval.node), (yyvsp[0].node));
															}
														else {
														    temp2 = create_node("Block",gen_token("",num_line,num_column));
															adicionar_filho((yyval.node), temp2);
															adicionar_filho(temp2, (yyvsp[0].node));
															}
													}
                                                  }
#line 1773 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement  */
#line 264 "jucompiler.y"
                                              { 
                                                (yyval.node)=create_node("If",gen_token("",num_line,num_column));
                                                adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                temp = create_node("Block",gen_token("",num_line,num_column));
                                                if((yyvsp[0].node) != NULL && block_count((yyvsp[0].node)) == 1 ){
                                                adicionar_filho((yyval.node),(yyvsp[0].node)); 
                                                adicionar_filho((yyval.node), temp);
                                                }
                                                else{
                                                adicionar_filho((yyval.node),temp);
                                                adicionar_filho(temp,(yyvsp[0].node));
                                                adicionar_filho((yyval.node),create_node("Block",gen_token("",num_line,num_column)));
                                                }
                                              
                                              }
#line 1793 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 279 "jucompiler.y"
                                             { 
                                                (yyval.node) = create_node( "While",gen_token("",num_line,num_column));
												adicionar_filho((yyval.node), (yyvsp[-2].node));
												if (block_count((yyvsp[0].node)) < 2 && (yyvsp[0].node) != NULL) {
													adicionar_filho((yyval.node), (yyvsp[0].node));
												}
												else {
													temp = create_node( "Block",gen_token("",num_line,num_column));
													adicionar_filho((yyval.node), temp);
													adicionar_filho(temp, (yyvsp[0].node));
												}
                                                
                                                }
#line 1811 "y.tab.c"
    break;

  case 34: /* Statement: RETURN SEMICOLON  */
#line 294 "jucompiler.y"
                        {(yyval.node)= create_node("Return",(yyvsp[-1].token));}
#line 1817 "y.tab.c"
    break;

  case 35: /* Statement: RETURN Expr SEMICOLON  */
#line 295 "jucompiler.y"
                             {(yyval.node)= create_node("Return",(yyvsp[-2].token));
                                adicionar_filho((yyval.node),(yyvsp[-1].node));}
#line 1824 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 297 "jucompiler.y"
                                 {(yyval.node)=(yyvsp[-1].node);}
#line 1830 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 298 "jucompiler.y"
                         {(yyval.node)=(yyvsp[-1].node);}
#line 1836 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 299 "jucompiler.y"
                        {(yyval.node)=(yyvsp[-1].node);}
#line 1842 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 300 "jucompiler.y"
            {(yyval.node)=NULL;}
#line 1848 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 301 "jucompiler.y"
                                     {(yyval.node)=create_node("Print",(yyvsp[-4].token));
                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                          }
#line 1856 "y.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 304 "jucompiler.y"
                                    {(yyval.node) = create_node("Print",(yyvsp[-4].token));
                                        temp = create_node("StrLit",(yyvsp[-2].token));
                                        adicionar_filho((yyval.node),temp);
                                                                  
                                        }
#line 1866 "y.tab.c"
    break;

  case 42: /* Statement: error SEMICOLON  */
#line 309 "jucompiler.y"
                        {(yyval.node) = NULL;}
#line 1872 "y.tab.c"
    break;

  case 43: /* Statement1: Statement Statement1  */
#line 313 "jucompiler.y"
                                           {   
                                        if ((yyvsp[-1].node) != NULL) {
										(yyval.node) = (yyvsp[-1].node);
									    adicionar_irmao((yyval.node), (yyvsp[0].node));
									    }
										else {
										(yyval.node) = (yyvsp[0].node);
										}
                                      }
#line 1886 "y.tab.c"
    break;

  case 44: /* Statement1: %empty  */
#line 322 "jucompiler.y"
                                 {(yyval.node) = NULL;}
#line 1892 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR RPAR  */
#line 326 "jucompiler.y"
                                                 {(yyval.node)=create_node("Call",gen_token("",num_line,num_column));
                                                    temp=create_node("Id",(yyvsp[-2].token));
                                                     adicionar_filho((yyval.node),temp); 
                                                     }
#line 1901 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR Expr MethodInvocation1 RPAR  */
#line 331 "jucompiler.y"
                                                      {(yyval.node)=create_node("Call",gen_token("",num_line,num_column));
                                                    temp=create_node("Id",(yyvsp[-4].token));
                                                     adicionar_filho((yyval.node),temp);
                                                     adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                    adicionar_filho((yyval.node),(yyvsp[-1].node));
                                                     }
#line 1912 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR error RPAR  */
#line 337 "jucompiler.y"
                                        {(yyval.node)=NULL;}
#line 1918 "y.tab.c"
    break;

  case 48: /* MethodInvocation1: COMMA Expr MethodInvocation1  */
#line 341 "jucompiler.y"
                                                {if((yyvsp[-1].node)!=NULL){
                                            (yyval.node)=(yyvsp[-1].node);
                                            adicionar_irmao((yyval.node),(yyvsp[0].node));
                                            }else{
                                                (yyval.node)=(yyvsp[-1].node);
                                            }
                                           }
#line 1930 "y.tab.c"
    break;

  case 49: /* MethodInvocation1: %empty  */
#line 348 "jucompiler.y"
                                      {(yyval.node)=NULL;}
#line 1936 "y.tab.c"
    break;

  case 50: /* Assignment: ID ASSIGN Expr  */
#line 352 "jucompiler.y"
                                                          {(yyval.node) = create_node("Assign",(yyvsp[-1].token));
                                                                temp=create_node("Id",(yyvsp[-2].token));
                                                                adicionar_filho((yyval.node),temp);
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                                              }
#line 1946 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 359 "jucompiler.y"
                                                            {(yyval.node) = create_node("ParseArgs",(yyvsp[-6].token));
                                                                temp=create_node("Id",(yyvsp[-4].token));
                                                                adicionar_filho((yyval.node),temp);
                                                                adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                }
#line 1956 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 364 "jucompiler.y"
                                                            {(yyval.node) = NULL;}
#line 1962 "y.tab.c"
    break;

  case 53: /* Expr: Assignment  */
#line 367 "jucompiler.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 1968 "y.tab.c"
    break;

  case 54: /* Expr: Expr1  */
#line 368 "jucompiler.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 1974 "y.tab.c"
    break;

  case 55: /* Expr1: Expr1 PLUS Expr1  */
#line 371 "jucompiler.y"
                                       {(yyval.node) = create_node("Add",(yyvsp[-1].token));
                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                        adicionar_filho((yyval.node),(yyvsp[0].node));
                                      }
#line 1983 "y.tab.c"
    break;

  case 56: /* Expr1: Expr1 MINUS Expr1  */
#line 375 "jucompiler.y"
                                       {(yyval.node) = create_node("Sub",(yyvsp[-1].token));
                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                        adicionar_filho((yyval.node),(yyvsp[0].node));
                                     }
#line 1992 "y.tab.c"
    break;

  case 57: /* Expr1: Expr1 STAR Expr1  */
#line 379 "jucompiler.y"
                                        {(yyval.node) = create_node("Mul",(yyvsp[-1].token));
                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                            adicionar_filho((yyval.node),(yyvsp[0].node));
                                        ;}
#line 2001 "y.tab.c"
    break;

  case 58: /* Expr1: Expr1 DIV Expr1  */
#line 383 "jucompiler.y"
                                           {(yyval.node) = create_node("Div",(yyvsp[-1].token));
                                                    adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                           }
#line 2010 "y.tab.c"
    break;

  case 59: /* Expr1: Expr1 MOD Expr1  */
#line 387 "jucompiler.y"
                                               {(yyval.node) = create_node("Mod",(yyvsp[-1].token));
                                                adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                            }
#line 2019 "y.tab.c"
    break;

  case 60: /* Expr1: Expr1 AND Expr1  */
#line 391 "jucompiler.y"
                                                   {(yyval.node) = create_node("And",(yyvsp[-1].token));
                                                    adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                    adicionar_filho((yyval.node),(yyvsp[0].node));}
#line 2027 "y.tab.c"
    break;

  case 61: /* Expr1: Expr1 OR Expr1  */
#line 396 "jucompiler.y"
                                                       {(yyval.node) = create_node("Or",(yyvsp[-1].token));
                                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                        adicionar_filho((yyval.node),(yyvsp[0].node));
                                                  }
#line 2036 "y.tab.c"
    break;

  case 62: /* Expr1: Expr1 XOR Expr1  */
#line 400 "jucompiler.y"
                                                        {(yyval.node) = create_node("Xor",(yyvsp[-1].token));
                                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                            adicionar_filho((yyval.node),(yyvsp[0].node));
                                                        }
#line 2045 "y.tab.c"
    break;

  case 63: /* Expr1: Expr1 LSHIFT Expr1  */
#line 404 "jucompiler.y"
                                                           {(yyval.node) = create_node("Lshift",(yyvsp[-1].token));
                                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                                            }
#line 2054 "y.tab.c"
    break;

  case 64: /* Expr1: Expr1 RSHIFT Expr1  */
#line 408 "jucompiler.y"
                                                              {(yyval.node) = create_node("Rshift",(yyvsp[-1].token));
                                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                                             }
#line 2063 "y.tab.c"
    break;

  case 65: /* Expr1: Expr1 EQ Expr1  */
#line 412 "jucompiler.y"
                                                                {(yyval.node) = create_node("Eq",(yyvsp[-1].token));
                                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                    adicionar_filho((yyval.node),(yyvsp[0].node));
                                                  }
#line 2072 "y.tab.c"
    break;

  case 66: /* Expr1: Expr1 GE Expr1  */
#line 416 "jucompiler.y"
                                                                  {(yyval.node) = create_node("Ge",(yyvsp[-1].token));
                                                                adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                            adicionar_filho((yyval.node),(yyvsp[0].node));
                                                           }
#line 2081 "y.tab.c"
    break;

  case 67: /* Expr1: Expr1 GT Expr1  */
#line 420 "jucompiler.y"
                                                              {(yyval.node) = create_node("Gt",(yyvsp[-1].token));
                                                             adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                            adicionar_filho((yyval.node),(yyvsp[0].node));
                                                          }
#line 2090 "y.tab.c"
    break;

  case 68: /* Expr1: Expr1 LE Expr1  */
#line 424 "jucompiler.y"
                                                              {(yyval.node) = create_node("Le",(yyvsp[-1].token));
                                                                        adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                        adicionar_filho((yyval.node),(yyvsp[0].node));
                                                                   }
#line 2099 "y.tab.c"
    break;

  case 69: /* Expr1: Expr1 LT Expr1  */
#line 428 "jucompiler.y"
                                                                  {(yyval.node) = create_node("Lt",(yyvsp[-1].token));
                                                                adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));}
#line 2107 "y.tab.c"
    break;

  case 70: /* Expr1: Expr1 NE Expr1  */
#line 431 "jucompiler.y"
                                                                  {(yyval.node) = create_node("Ne",(yyvsp[-1].token));
                                                            adicionar_filho((yyval.node),(yyvsp[-2].node));
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                                                }
#line 2116 "y.tab.c"
    break;

  case 71: /* Expr1: MINUS Expr1  */
#line 435 "jucompiler.y"
                                                             {(yyval.node) = create_node("Minus",(yyvsp[-1].token));
                                                                adicionar_filho((yyval.node),(yyvsp[0].node));
                                                               }
#line 2124 "y.tab.c"
    break;

  case 72: /* Expr1: NOT Expr1  */
#line 438 "jucompiler.y"
                                                       {(yyval.node) = create_node("Not",(yyvsp[-1].token));
                                                                    adicionar_filho((yyval.node),(yyvsp[0].node));
                                                                    }
#line 2132 "y.tab.c"
    break;

  case 73: /* Expr1: PLUS Expr1  */
#line 441 "jucompiler.y"
                                                                    {(yyval.node) = create_node("Plus",(yyvsp[-1].token));
                                                                            adicionar_filho((yyval.node),(yyvsp[0].node));
                                                                            }
#line 2140 "y.tab.c"
    break;

  case 74: /* Expr1: LPAR Expr RPAR  */
#line 444 "jucompiler.y"
                                                                    {(yyval.node)=(yyvsp[-1].node);}
#line 2146 "y.tab.c"
    break;

  case 75: /* Expr1: MethodInvocation  */
#line 445 "jucompiler.y"
                                                                    {(yyval.node)=(yyvsp[0].node);}
#line 2152 "y.tab.c"
    break;

  case 76: /* Expr1: ParseArgs  */
#line 446 "jucompiler.y"
                                                                       {(yyval.node)=(yyvsp[0].node);}
#line 2158 "y.tab.c"
    break;

  case 77: /* Expr1: ID  */
#line 447 "jucompiler.y"
                                                                          {(yyval.node) = create_node("Id",(yyvsp[0].token));}
#line 2164 "y.tab.c"
    break;

  case 78: /* Expr1: ID DOTLENGTH  */
#line 448 "jucompiler.y"
                                                                            {(yyval.node) = create_node("Length",(yyvsp[0].token));
                                                                                adicionar_filho((yyval.node),create_node("Id",(yyvsp[-1].token)));
                                                                                }
#line 2172 "y.tab.c"
    break;

  case 79: /* Expr1: INTLIT  */
#line 451 "jucompiler.y"
                                                                           {(yyval.node) = create_node("DecLit",(yyvsp[0].token));}
#line 2178 "y.tab.c"
    break;

  case 80: /* Expr1: REALLIT  */
#line 452 "jucompiler.y"
                                                                            {(yyval.node) = create_node("RealLit",(yyvsp[0].token));}
#line 2184 "y.tab.c"
    break;

  case 81: /* Expr1: BOOLLIT  */
#line 453 "jucompiler.y"
                                                                               {(yyval.node) = create_node("BoolLit",(yyvsp[0].token));}
#line 2190 "y.tab.c"
    break;

  case 82: /* Expr1: LPAR error RPAR  */
#line 454 "jucompiler.y"
                                        {(yyval.node) = NULL;}
#line 2196 "y.tab.c"
    break;


#line 2200 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 458 "jucompiler.y"
