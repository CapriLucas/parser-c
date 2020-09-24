%{

#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int yylineno;
//Tareas
/* 
1)Crear y copiar un .txt las gramaticas de declaraciones y sentencias (Cada una en un txt aparte)
usar la del libro combinada con la del campus virtual.
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
3)Completar en TP4.l las acciones de las reglas y agregar su return a %token(en TP4.y) segun su 
tipo de dato descripto en %union
4)Crear una funcion parecida a la del tp3 que devuelva y presente opciones de lo que pide el tp (que 
no devuelva nada todavia pero que tenga un lugar en donde poner la funcion que va a devolver ) 
en funciones.h
5)Una vez hecho el (1) realizar sus reglas gramaticales como la que se hizo en expresiones
6)Una vez hecho el (2) (3) realizar un chequeo de las reglas y definiciones a detalle del TP4.l y TP4.y
7)Ver todo el video "completo" de bison parte 1,2,de bison debug y demas. Sacar conclusiones de como 
mejorar/facilitar el tp, si es posible anotarlo a detalle.(De la clase de los lunes tambien) 
8)Crear las acciones de expresiones (codigo en funciones.h)
9)Crear las acciones de declaraciones (codigo en funciones.h)
10)Crear las acciones de sentencias (codigo en funciones.h)

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

PR_DATO	             int|char|float|bool|double|long|short|unsigned|signed|typedef|const|enum|struct
PR_CONDICIONAL       if|else|switch|case|break|return|default
PR_ITERATIVA         while|for|do 
PR_OTRO              auto|continue|extern|goto|register|static|union|void|volatile
PR                   {PR_DATO}|{PR_CONDICIONAL}|{PR_ITERATIVA}|{PR_OTRO}

LCADENA               \"(\\.|[^\\"])*\"
ID       	         [a-zA-Z_][a-zA-Z0-9_]*
COP                  "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"|"..."|"["|"]"  
COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*

%%

{DIRECTIVA}         {;}

{PR}                {;}

{CEDECIMAL}         {yylval.ival = atoi(yytext); return ENTERO;}

{CEOCTAL}           {yylval.ival = strtol(yytext, NULL, 0); return ENTERO;}

{CEHEXA}            {yylval.ival = strtol(yytext, NULL, 0); return ENTERO;} 

{CREAL}             {yylval.dval = atof(yytext); return NUM;}

{CARACTER}          {yylval.cval = atoi(yytext); return ENTERO;}

{LCADENA}            {strcpy(yylval.ccval,yytext); return LCADENA;}

{COP}               {;}

{CPU}               {;}

{ID}                {strcpy(yylval.ccval,yytext); return ID;}

{COM_MULT}          {;} 

{COM_SIMP}          {;} 

\n                  {//nlinea +=1;}    
[\t ]+              {;}

(.)                 {;}

{CONSTANTES}{ID}+   {;}
{PR_DATO}       {strcpy(yylval.ccval,yytext); return TDATO;}
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