%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}

%% /*  reglas gramaticales y las acciones */


%%

int yyerror (char *mensaje)  
{  
    printf ("Error: %s\n", mensaje);
}

int main ()
{
//El mismo deberá tomar un archivo de texto como entrada (archivo fuente) y dar como salida en pantalla
//un reporte de variables declaradas indicando tipo de dato correspondiente, funciones declaradas,
// tipos sentencias encontradas. Deberá indicarse aquellas secuencias que no pertenezcan a ninguna categoría
// léxica o estructuras que no sean válidas sintácticamente. Para desarrollar dicho programa deberá utilizar 
//LEX/FLEX combinado con YACC/BISON para la generación del código C.

// Las gramáticas pueden ser extraídas del volumen 1 del apunte de la cátedra, en varios casos pueden empezar
// implementando las producciones más sencillas y luego ir agregando complejidad. 

  yyin = fopen("entrada.txt","r");
  // yyout = fopen("salida.txt","w"); Para hacer pruebas
  yyparse ();
 	printf("Variables declaradas y su tipo de dato\n");
    // Funcion generica que devuelva lo pedido 
	printf("Funciones declaradas\n");
    // Funcion generica que devuelva lo pedido 
    printf("Tipo de Sentencias Encontradas");
    // Funcion generica que devuelva lo pedido 
    printf("Secuencias que no pertenecen a ninguna categoria lexica o estructuras no validas");
}