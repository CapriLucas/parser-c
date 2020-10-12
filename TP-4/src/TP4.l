%option noyywrap

%{
#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>




%}


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
{DIRECTIVA}         {;}
{CEDECIMAL}         {yylval.ival = atoi(yytext); return CENTERO;}
{CEOCTAL}           {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;}
{CEHEXA}            {yylval.ival = strtol(yytext, NULL, 0); return CENTERO;} 
{CREAL}             {yylval.dval = atof(yytext); return CREAL;}
{CARACTER}          {yylval.ccval = strdup(yytext); return CCARACTER;}
{LCADENA}           {yylval.ccval = strdup(yytext); return LCADENA;}
{COM_MULT}          {;} 
{COM_SIMP}          {;} 
{CONSTANTES}{ID}+   {;}
{PR_DATO}           {return TDATO;}
{PR_CLASE}          {return TCLASE;}
{PR_CAL}            {return CALTIPO;}
{PR_STRUNION}       {return STRUNION;}

"*="                {return OPASIG;}
"/="                {return OPASIG;}
"%="                {return OPASIG;}
"+="                {return OPASIG;}
"-="                {return OPASIG;}
"<<="               {return OPASIG;}
">>="               {return OPASIG;}
"&="                {return OPASIG;}
"|="                {return OPASIG;}
"++"                {return OPINCDEC;}
"--"                {return OPINCDEC;}
"&&"                {return AND;}
"||"                {return OR;}
">="                {return OPREL;}
"=<"                {return OPREL;}
"!="                {return OPIGUAL;}
"=="                {return OPIGUAL;}
"<<"                {return OPCORR;}
">>"                {return OPCORR;}
"sizeof"            {return SIOF;}
"if"                {return IF;}
"else"              {return ELSE;}
"switch"            {return SWITCH;}
"while"             {return WHILE;}
"do"                {return DO;}
"for"               {return FOR;}
"return"            {return RETURN;}
"continue"          {return CONTINUE;}
"goto"              {return GOTO;}
"break"             {return BREAK;}
"case"              {return CASE;}
"default"           {return DEFAULT;}
"enum"              {return ENUM;}
{ID}                {yylval.ccval = strdup(yytext); return ID;}

"->"                {return FLECHA;}
"="                 {return '=';}   
"."                 {return '.';}   
"!"                 {return '!';}
"<"                 {return '<';}
">"                 {return '>';}
"+"                 {return '+';}
"-"                 {return '-';}
"*"                 {return '*';}
"/"                 {return '/';}
"%"                 {return '%';}
"&"                 {return '&';}
";"                 {return ';';}
","                 {return ',';}
"("                 {return '(';}
")"                 {return ')';}
"{"                 {return '{';}
"}"                 {return '}';} 
[\t ]+              {;}
\n                  {;} 
.                   {;}
%%