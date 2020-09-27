%{

#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int yylineno;
//Tareas
/* 
2)probar los ejemplos asi se van familiarizando con lo que tenemos que hacer con bison y flex
comandos para ejecutar a)flex archivo.l 
 b)bison -d archivo.y
 Bison les crea el archivo.tab.c y archivo.tab.h
 Flex les crea lex.yy.c
 c)gcc archivo.tab.c lex.yy.c
 Esto les crea el a.exe 
 d)a.exe
Nota1: No probar TP4.l y TP4.y no esta para compilar 
Nota2: No compila? Puede ser:
 a) por que la carpeta Flex y Bison tiene espacios en el nombre
 Cambiarlo de Flex y Bison -> FlexyBison o Flex_y_Bison (cambiar nombre en el winrar, descomprimirlo y ubicarlo en
 el disco C, no olvidarse cambiarlo en el PATH tambien), despues reiniciar PC o VSCODE(si lo usaste tarda un poco).
 b)si en el error incluye #include <y.tab.h> si tira esto hay que borrar ese include en donde aparezca
 c)agregar el #include "archivo.tab.h" en archivo.l
4)Crear una funcion parecida a la del tp3 que devuelva y presente opciones de lo que pide el tp (que 
no devuelva nada todavia pero que tenga un lugar en donde poner la funcion que va a devolver ) 
en funciones.h (ARREGLAR FUNCION SON 6 OPCIONES (1)(2)(3)(4): lo que pide el tp, (5) reporte completo, 
 la (6) que permita salir del programa) y que si elige un nro cualquiera muestre msj de error 
 y reinicie la seleccion de opciones hasta que lo haga correctamente.
6)Una vez hecho el (2) (3) realizar un chequeo de las reglas y definiciones a detalle del TP4.l y TP4.y
7)Ver todo el video "completo" de bison parte 1,2,de bison debug y demas. Sacar conclusiones de como 
mejorar/facilitar el tp, si es posible anotarlo a detalle.(De la clase de los lunes tambien) 
8)Crear las acciones de expresiones (codigo en funciones.h) 
9)Crear las acciones de declaraciones (codigo en funciones.h)
10)Crear las acciones de sentencias (codigo en funciones.h)
11)
Nota: No correr el programa hasta tener el paso (5 y 6)
 */
%}

option noyywrap

DIRECTIVA            "#"[ ]*"include"[ ]*(\".*".h"\"|"<".*".h>")|"#"[ ]*"define"[ ]+{ID}[ ]*("("[ ]*({ID}[ ]*","[ ]*)*{ID}[ ]*")")?[ ]+([^#\n]+)?

CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             '.'|'\\0'|'\\n'
CONSTANTES          {CEDECIMAL}|{CEOCTAL}|{CEHEXA}|{CREAL}

PR_DATO	             int|char|void|float|bool|double|long|short|unsigned|signed 
PR_CLASE              auto|extern|register|static|typedef
PR_STRUNION         struct|union
PR_CAL              const|volatile
PR                   {PR_DATO}|{PR_CLASE}

LCADENA               \"(\\.|[^\\"])*\"
ID       	         [a-zA-Z_][a-zA-Z0-9_]*
COP                  "++"|"*"|"+"|"&"|"!"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"|"..."|"["|"]"  
COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*

%%

{DIRECTIVA}         {;}

{CEDECIMAL}         {yylval.ival = atoi(yytext); return ENTERO;}

{CEOCTAL}           {yylval.ival = strtol(yytext, NULL, 0); return ENTERO;}

{CEHEXA}            {yylval.ival = strtol(yytext, NULL, 0); return ENTERO;} 

{CREAL}             {yylval.dval = atof(yytext); return NUM;}

{CARACTER}          {yylval.cval = atoi(yytext); return ENTERO;}

{LCADENA}            {strcpy(yylval.ccval,yytext); return LCADENA;}

{ID}                {strcpy(yylval.ccval,yytext); return ID;}

{COM_MULT}          {;} 

{COM_SIMP}          {;} 

\n                  {//nlinea +=1;}    
[\t ]+              {;}

(.)                 {;}

{CONSTANTES}{ID}+   {;}
{PR_DATO}       {strcpy(yylval.ccval,yytext); return TDATO;}
{PR_CLASE}       {strcpy(yylval.ccval,yytext); return TCLASE;}
{PR_CAL}        {strcpy(yylval.ccval,yytext); return CALTIPO;}
{PR_STRUNION}       {strcpy(yylval.ccval,yytext); return STRUNION;}
"*="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"/="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"%="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"+="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"-="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"<<="           {strcpy(yylval.ccval,yytext); return OPASIG;}
">>="           {strcpy(yylval.ccval,yytext); return OPASIG;}
"&="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"^="            {strcpy(yylval.ccval,yytext); return OPASIG;}
"|="            {strcpy(yylval.ccval,yytext); return OPASIG;}

"++"            {strcpy(yylval.ccval,yytext); return OPINCDEC;}
"--"            {strcpy(yylval.ccval,yytext); return OPINCDEC;}

"&&"            {strcpy(yylval.ccval,yytext); return AND;}
"||"            {strcpy(yylval.ccval,yytext); return OR;}
">="            {strcpy(yylval.ccval,yytext); return OPREL;}
"=<"            {strcpy(yylval.ccval,yytext); return OPREL;}
"!="            {strcpy(yylval.ccval,yytext); return OPIGUAL;}
"=="            {strcpy(yylval.ccval,yytext); return OPIGUAL;}
"<<"            {strcpy(yylval.ccval,yytext); return OPCORR;}
">>"            {strcpy(yylval.ccval,yytext); return OPCORR;}
"sizeof"        {strcpy(yylval.ccval,yytext); return SIOF;}
"if"            {strcpy(yylval.ccval,yytext); return IF;}
"else"          {strcpy(yylval.ccval,yytext); return ELSE;}
"switch"          {strcpy(yylval.ccval,yytext); return SWITCH;}
"while"          {strcpy(yylval.ccval,yytext); return WHILE;}
"do"          {strcpy(yylval.ccval,yytext); return DO;}
"for"          {strcpy(yylval.ccval,yytext); return FOR;}
"return"          {strcpy(yylval.ccval,yytext); return RETURN;}
"continue"          {strcpy(yylval.ccval,yytext); return CONTINUE;}
"goto"          {strcpy(yylval.ccval,yytext); return GOTO;}
"break"          {strcpy(yylval.ccval,yytext); return BREAK;}
"case"          {strcpy(yylval.ccval,yytext); return CASE;}
"default"          {strcpy(yylval.ccval,yytext); return DEFAULT;}
"enum"          {strcpy(yylval.ccval,yytext); return ENUM;}
"->"            {strcpy(yylval.ccval,yytext); return FLECHA;}
"="             {return '=';}   
"."             {return '.';}   
"!"             {return '!';}
"<"             {return '<';}
">"             {return '>';}
"+"             {return '+';}
"-"             {return '-';}
"*"             {return '*';}
"/"             {return '/';}
"%"             {return '%';}
"&"             {return '&';}
";"             {return ';';}
","             {return ',';}
"("             {return '(';}
")"             {return ')';}
"{"             {return '{';}
"}"             {return '}';}



%%