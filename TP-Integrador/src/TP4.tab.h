
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CENTERO = 258,
     CREAL = 259,
     ID = 260,
     LCADENA = 261,
     CCARACTER = 262,
     OPASIG = 263,
     OR = 264,
     AND = 265,
     OPIGUAL = 266,
     OPCORR = 267,
     OPREL = 268,
     OPERADORINC = 269,
     OPERADORDEC = 270,
     T_DATO = 271,
     TCLASE = 272,
     FLECHA = 273,
     STRUNION = 274,
     CALTIPO = 275,
     OPDESIGUAL = 276,
     OPERADORUNARIO = 277,
     ENUM = 278,
     IF = 279,
     ELSE = 280,
     SIZEOF = 281,
     SWITCH = 282,
     WHILE = 283,
     DO = 284,
     FOR = 285,
     RETURN = 286,
     CONTINUE = 287,
     GOTO = 288,
     BREAK = 289,
     CASE = 290,
     DEFAULT = 291,
     DIRECTIVA = 292,
     CNORECONOCIDO = 293,
     ERRORLEXICO = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 24 "TP4.y"

char* ccval; // cadenas
double dval; // numeros reales/racionales
int ival; // numeros enteros



/* Line 1676 of yacc.c  */
#line 99 "TP4.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


