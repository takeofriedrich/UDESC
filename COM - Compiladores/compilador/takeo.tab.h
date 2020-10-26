/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_TAKEO_TAB_H_INCLUDED
# define YY_YY_TAKEO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_REAL = 259,
    T_BOOL = 260,
    T_IDENT = 261,
    T_LITERAL = 262,
    T_STR = 263,
    T_TRUE = 264,
    T_FALSE = 265,
    T_END_LINE = 266,
    T_DOIS_PONTOS = 267,
    T_VIRGULA = 268,
    T_STRING_TIPO = 269,
    T_BOOL_TIPO = 270,
    T_INT_TIPO = 271,
    T_REAL_TIPO = 272,
    T_MAIN = 273,
    T_RETURN = 274,
    T_IF = 275,
    T_WHILE = 276,
    T_FOR = 277,
    T_PRINT = 278,
    T_READ = 279,
    T_PLUS = 280,
    T_MINUS = 281,
    T_MULTIPLY = 282,
    T_DIVIDE = 283,
    T_APPEND = 284,
    T_PAR_LEFT = 285,
    T_CHA_LEFT = 286,
    T_PAR_RIGHT = 287,
    T_COL_RIGHT = 288,
    T_CHA_RIGHT = 289,
    T_EQQ = 290,
    T_LESS = 291,
    T_MORE = 292,
    T_EQUAL = 293,
    T_OR = 294,
    T_AND = 295,
    T_COL_LEFT = 296,
    T_THEN1 = 297,
    T_THEN2 = 298,
    T_ELSE = 299,
    T_PREC_STR = 300,
    T_RET = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "takeo.y"

	int ival;
	float fval;
	char *str;

#line 110 "takeo.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAKEO_TAB_H_INCLUDED  */
