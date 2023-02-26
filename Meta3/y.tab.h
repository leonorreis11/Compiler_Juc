/* A Bison parser, made by GNU Bison 3.8.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
