/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 0,
     Identifier = 258,
     StringLiteral = 259,
     FloatingPointLiteral = 260,
     CharLiteral = 261,
     IntegerLiteral = 262,
     DoubleQuote = 263,
     Underscore = 264,
     Letter = 265,
     SingleQuote = 266,
     Error = 267,
     TrueOrFalse = 268,
     Boolean = 269,
     Float = 270,
     Int = 271,
     Char = 272,
     Corchete = 273,
     punto = 274,
     Class = 275,
     Extends = 276,
     OpenLlave = 277,
     CloseLlave = 278,
     Coma = 279,
     PuntoComa = 280,
     variableDeclarator = 281,
     Void = 282,
     OpenParentesis = 283,
     This = 284,
     If = 285,
     Else = 286,
     Switch = 287,
     Case = 288,
     Default = 289,
     DosPtos = 290,
     While = 291,
     Do = 292,
     For = 293,
     Break = 294,
     Continue = 295,
     Return = 296,
     New = 297,
     AddOp = 298,
     Not = 299,
     MultOp = 300,
     And = 301,
     Or = 302,
     Tongo = 303,
     OpenCorchete = 304,
     CloseCorchete = 305,
     super = 306,
     modifier = 307,
     CloseParentesis = 308,
     Equals = 309,
     Relacion = 310,
     Igualdad = 311,
     OrOr = 312,
     AndAnd = 313,
     PlusPlus = 314,
     MinusMinus = 315,
     Prec1 = 316
   };
#endif
/* Tokens.  */
#define END 0
#define Identifier 258
#define StringLiteral 259
#define FloatingPointLiteral 260
#define CharLiteral 261
#define IntegerLiteral 262
#define DoubleQuote 263
#define Underscore 264
#define Letter 265
#define SingleQuote 266
#define Error 267
#define TrueOrFalse 268
#define Boolean 269
#define Float 270
#define Int 271
#define Char 272
#define Corchete 273
#define punto 274
#define Class 275
#define Extends 276
#define OpenLlave 277
#define CloseLlave 278
#define Coma 279
#define PuntoComa 280
#define variableDeclarator 281
#define Void 282
#define OpenParentesis 283
#define This 284
#define If 285
#define Else 286
#define Switch 287
#define Case 288
#define Default 289
#define DosPtos 290
#define While 291
#define Do 292
#define For 293
#define Break 294
#define Continue 295
#define Return 296
#define New 297
#define AddOp 298
#define Not 299
#define MultOp 300
#define And 301
#define Or 302
#define Tongo 303
#define OpenCorchete 304
#define CloseCorchete 305
#define super 306
#define modifier 307
#define CloseParentesis 308
#define Equals 309
#define Relacion 310
#define Igualdad 311
#define OrOr 312
#define AndAnd 313
#define PlusPlus 314
#define MinusMinus 315
#define Prec1 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 178 "bison.y"
{	
	char* str;
	class Node* node;
}
/* Line 1529 of yacc.c.  */
#line 178 "bison.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
