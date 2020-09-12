%{

#include"TP4.tab.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int yylineno;
//Tareas
/* 
1-------Crear y copiar en un .txt todas las gramaticas que vamos a necesitar
2-------probar los ejemplos asi se van familiarizando con lo que tenemos que hacer con bison y flex
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
3-------Crear una funcion parecida a la del tp3 que devuelva lo que pide el tp  
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

LITCAD               \"(\\.|[^\\"])*\"
ID       	         [a-zA-Z_][a-zA-Z0-9_]*
COP                  "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"|"..."|"["|"]"  
COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*

%%

{DIRECTIVA}         {;}

{PR}                {;}

{CEDECIMAL}         {;}

{CEOCTAL}           {;}

{CEHEXA}            {;} 

{CREAL}             {;}

{CARACTER}          {;}

{LITCAD}            {;}

{COP}               {;}

{CPU}               {;}

{ID}                {;}

{COM_MULT}          {;} 

{COM_SIMP}          {;} 

\n                  {nlinea +=1;}    
[\t ]+              {;}

(.)                 {;}

{CONSTANTES}{ID}+   {;}

%%