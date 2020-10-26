%option noyywrap

%{

#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()

#include "takeo.tab.h"

char *subString(const char *input, int offset, int len, char *dest)
{
    int input_len = strlen(input);

    if (offset + len > input_len)
    {
        return NULL;
    }

    strncpy(dest, input + offset, len);
    return dest;
}


%}

DIGITO   [0-9]
ID       [a-z]*[a-zA-Z0-9]
LITERAL  \"(\\.|[^"])*\"

%%
{DIGITO}+\.{DIGITO}+ 	{yylval.fval = atof(yytext); return T_REAL;}
{DIGITO}+    			{yylval.ival = atoi(yytext); return T_INT;}
"main"                  {return T_MAIN;}
"=="					{return T_EQQ;}
"="					    {return T_EQUAL;}
"{"					    {return T_CHA_LEFT;}
"}"					    {return T_CHA_RIGHT;}
"("					    {return T_PAR_LEFT;}
")"					    {return T_PAR_RIGHT;}
"["					    {return T_COL_LEFT;}
"]"					    {return T_COL_RIGHT;}
"+"					    {return T_PLUS;}
"-"					    {return T_MINUS;}
"*"					    {return T_MULTIPLY;}
"/"					    {return T_DIVIDE;}
"int"					{return T_INT_TIPO;}
"float"				    {return T_REAL_TIPO;}
"bool"					{return T_BOOL_TIPO;}
"<"					    {return T_LESS;}
">"					    {return T_MORE;}
";"					    {return T_END_LINE;}
":"					    {return T_DOIS_PONTOS;}
","                     {return T_VIRGULA;}
"or"                    {return T_OR;}
"and"                   {return T_AND;}
"if"					{return T_IF;}
"else"					{return T_ELSE;}
"while"				    {return T_WHILE;}
"for"					{return T_FOR;}
"print"				    {return T_PRINT;}
"read"					{return T_READ;}
"string"				{return T_STRING_TIPO;}
"append"				{return T_APPEND;}
"return"                {return T_RETURN;}
"TRUE"                  {yylval.ival = 1;return T_TRUE;}
"FALSE"                 {yylval.ival = 0;return T_FALSE;}
{ID}+                   {yylval.str = malloc(sizeof(char)*strlen(yytext)); memcpy(yylval.str,yytext,sizeof(char)*strlen(yytext));yylval.str[strlen(yytext)] = '\0';return T_IDENT;}
[ \t\n]+                
{LITERAL}({LITERAL}|{ID})*  {yylval.str = malloc(sizeof(char)*(strlen(yytext)));subString(yytext, 1, strlen(yytext)-2, yylval.str);return T_LITERAL;}     
.
%%