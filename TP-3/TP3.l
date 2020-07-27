%option noyywrap
%{

#include <stdio.h>
#include "funcionesTP3.h"
int acum = 0;

//Categorías léxicas de C a reconocer:
//      Constantes (Entera decimal, entera octal, entera hexadecimal, real, caracter) x
//      Literal cadena 
//      Palabras reservadas (distinguir entre tipo de dato, estructuras de control y otros) 
//      Identificadores x
//      Caracteres de puntuación y operadores de C.

//Comentarios (es realidad son reconocidos por el PRECOMPILADOR)
//      Comentarios de una línea x
//      Comentarios de múltiples líneas x

//Reporte
//  Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. 
//El listado debe estar ordenado alfabéticamente.
//  Listado de literales cadena encontrados indicando la longitud de los mismos.
//  Listado de palabras reservadas en el orden en el que han aparecido.
//  Listado de constantes indicando según su tipo:
//          Para las constantes octales indicar su valor entero decimal.
//          Para las constante hexadecimales indicar su valor entero decimal.
//          Para las constantes decimales indicar el valor de cada una y el total acumulado de sumar todas ellas.
//          Para las constantes reales indicar el valor de su mantisa y parte entera.
//          Para las constantes caracter, enumerarlas según orden de aparición. 
//  Listado de operadores/caracteres de puntuación indicando cantidad de veces que aparecen.
//  Listado de comentarios encontrados distinguiendo si se trata de comentarios de una línea o múltiples líneas.
//  Listado de cadenas y/o caracteres no reconocidos indicando el número de línea.

//Desafío opcional
//  Adicionar al analizador léxico el reconocimiento de las directivas del precompilador #Include #Define.

//Cosas para hacer:
//Puede simplificarse la CREAL ? queda muy largo si no se puede, esta bien
//Buscar palabras reservadas asegurarse que no se puedan escribir como identificador ya que varias paginas dicen
//  algo diferente, y agregarlos a la regla.
//Buscar caracteres de operacion (COP) y puntuacion (CPU), agregarlos a la regla.
//Crear la regla de LITERALCADENA
//Luego ordenar la prioridad de reglas

%}

CEDECIMAL 	[1-9][0-9]* 
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER    '.'
ID       	[a-zA-Z_][a-zA-Z0-9_]*
PRESERVADA	while|do|if|else|for|int|char|return|case|switch
COMENTARIOS "//"(.)*\n|"/*"(.|\n)*"*/"
COP        \+\+|\*|\+|&|!|sizeof|\/
CPU        \(|\)|\{|\}

%%

{CEDECIMAL}   {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{CEOCTAL}     {printf("La cadena %s representa una constante entera octal\n", yytext);}
{CEHEXA}      {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{CREAL}       {printf("La cadena %s representa una constante real\n", yytext);}
{COMENTARIOS} {printf("La cadena %s representa un comentario\n", yytext);} 
{CARACTER}    {acum= acum+1; printf("La cadena %s representa un caracter\n", yytext);}
{PRESERVADA}  {printf("La cadena %s representa una palabra reservada\n", yytext);}
{COP}         {printf("La cadena %s representa un caracter de operacion\n", yytext);}
{CPU}         {printf("La cadena %s representa un caracter de puntuacion\n", yytext);}
{ID}          {printf("La cadena %s representa un identificador\n", yytext);}


%%


int main(){
    
    yyin = fopen("entrada.txt","r");
    yyout = fopen("salida.txt","w");
    yylex();
    return 0;
    }