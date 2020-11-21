%option noyywrap

%{
#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>




%}

%option yylineno 

DIRECTIVA            "#"[ ]*"include"[ ]*(\".*".h"\"|"<".*".h>")|"#"[ ]*"define"[ ]+{ID}[ ]*("("[ ]*({ID}[ ]*","[ ]*)*{ID}[ ]*")")?[ ]+([^#\n]+)?
CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             '.'|'\\0'|'\\n'
CONSTANTES           {CEDECIMAL}|{CEOCTAL}|{CEHEXA}|{CREAL}

PR_DATO	             int|char|void|float|bool|double|long|short|unsigned|signed 
PR_CLASE             auto|extern|register|static|typedef
PR_STRUNION          struct|union
PR_CAL               const|volatile
PR                   {PR_DATO}|{PR_CLASE}

LCADENA              \"(\\.|[^\\"])*\"
ID       	         [a-zA-Z_][a-zA-Z0-9_]*
COP                  "++"|"*"|"+"|"&"|"!"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"|"..."|"["|"]"  
COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*

%%

{DIRECTIVA}         {strcpy(yylval.ccval, yytext); return DIRECTIVA;}

{CEDECIMAL}         {yylval.ival = atoi(yytext); return CENTERO;}
{CEOCTAL}           {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;}
{CEHEXA}            {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;} 

{CREAL}             {yylval.dval = atof(yytext); return CREAL;}
{LCADENA}           {strcpy(yylval.ccval,yytext); return LCADENA;}
{CONSTANTES}{ID}+   {strcpy(yylval.ccval, yytext); return CNORECONOCIDO;}
{PR_DATO}           {strcpy(yylval.ccval, yytext); return T_DATO;}
{PR_CLASE}          {strcpy(yylval.ccval, yytext);return TCLASE;}
{PR_CAL}            {strcpy(yylval.ccval, yytext);return CALTIPO;}
{PR_STRUNION}       {strcpy(yylval.ccval, yytext);return STRUNION;}


sizeof            {return SIZEOF;}
if                {return IF;}
else              {return ELSE;}
switch            {return SWITCH;}
while             {return WHILE;}
do                {return DO;}
for               {return FOR;}
return            {return RETURN;}
continue          {return CONTINUE;}
goto              {return GOTO;}
break             {return BREAK;}
case              {return CASE;}
default           {return DEFAULT;}
enum              {return ENUM;}

{ID}              {strcpy(yylval.ccval,yytext); return ID;}
{CARACTER}        {strcpy(yylval.ccval,yytext); return CCARACTER;}

{COM_MULT}          {} //vale la pena guardarlo?
{COM_SIMP}          {} //lo mismo


"*="                {return OPASIG;}
"/="                {return OPASIG;}
"%="                {return OPASIG;}
"+="                {return OPASIG;}
"-="                {return OPASIG;}
"<<="               {return OPASIG;}
">>="               {return OPASIG;}
"&="                {return OPASIG;}
"|="                {return OPASIG;}
"++"                {return OPERADORINC;}
"--"                {return OPERADORDEC;}
"&&"                {return AND;}
"||"                {return OR;}
">="                {return OPREL;}
"=<"                {return OPREL;}
"!="                {return OPDESIGUAL;}
"=="                {return OPIGUAL;}
"<<"                {return OPCORR;}
">>"                {return OPCORR;}
"->"                {return FLECHA;}
"="                 {return '=';}   
"."                 {return '.';}   
"!"                 {return OPERADORUNARIO;}
"<"                 {return '<';}
">"                 {return '>';}
"+"                 {return OPERADORUNARIO;}
"-"                 {return OPERADORUNARIO;}
"*"                 {return OPERADORUNARIO;}
"/"                 {return '/';}
"%"                 {return '%';}
"&"                 {return OPERADORUNARIO;}
";"                 {return ';';}
","                 {return ',';}
")"                 {return ')';}
"("                 {return '(';}
"{"                 {return '{';}
"}"                 {return '}';} 
.                {printf("Caracter o cadena %s no emparejable. Se encontro un error lexico en la linea %d", yytext, yylineno); return ERRORLEXICO;}

%%


