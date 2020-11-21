
%{
#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>




%}
option noyywrap      

%%
"("|")"|"["|"]"|","|"?"|":"|";"|"{"|"}"|"&"|"!"|"+"|"-"|"*"|"/"|"%"       {return yytext[0];}
"int" | "char" | "void" | "float" |"bool"|"double"|"long"|"short"|"unsigned"|"signed"     {return T_DATO;}
"auto"|"extern"|"register"|"static"|"typedef"                                           {return TCLASE;}
"\n" {return '\n';}
"const"|"volatile"           {return CALTIPO;}
"struct"|"union"       {return STRUNION;}
"sizeof"            {return SIZEOF ;}
"if"                {return IF ;}
"else"              {return ELSE ;}
"switch"            {return SWITCH ;}
"while"             {return WHILE ;}
"do"                {return DO;}
"for"               {return FOR;}
"return"            {return RETURN;}
"continue"          {return CONTINUE;}
"goto"              {return GOTO;}
"break"             {return BREAK;}
"enum"              {return ENUM;}
"&&"                {return AND;}
"||"                {return OR;}
"*=" | "/=" | "+=" | "-=" | "="                 {return OPASIG;}
"++" | "--"                                     {return OPINCDEC;}
">"|"<"|"<="|">=" {return OPREL;}
"!=" | "=="                                     {return OPIGUAL;}
[1-9][0-9]*                             {yylval.ival = atoi(yytext); return CENTERO;}
0[0-7]*                                 {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;}
0[xX][A-Fa-f0-9]+                       {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;} 
[0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?          {yylval.dval = atof(yytext); return CREAL;}
'.'|'\\0'       {strcpy(yytext,yylval.ccval); return CCARACTER;}
\"(\\.|[^\\"])*\"            {strcpy(yytext,yylval.ccval); return LCADENA;}
[a-zA-Z_][a-zA-Z0-9_]*                          {strcpy(yytext,yylval.ccval); return ID;}
[\t ]+              {;}
(.)                   {printf("Caracter o cadena %s no emparejable. Se encontro un error lexico en la linea %d", yytext, yylineno); return ERRORLEXICO;}
%%