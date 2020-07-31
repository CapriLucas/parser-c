%option noyywrap
%{

#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<string.h>
#include "funcionesTP3.h"
int acum = 0;
int valor= 0;


//Implementar en C un programa que permita reconocer en un archivo.c de entrada todas las 
//categorías léxicas de C y comentarios. El mismo deberá  dar como salida en pantalla un 
//reporte. Para desarrollar dicho programa deberá utilizar LEX/FLEX para la generación del 
//código C que implemente el analizador léxico.



//Categorías léxicas de C a reconocer:
//      Constantes (Entera decimal, entera octal, entera hexadecimal, real, caracter) x
//      Literal cadena x
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
//Buscar palabras reservadas asegurarse que no se puedan escribir como identificador ya que varias paginas dicen --(Agregue mas palabras reservadas )
//  algo diferente, y agregarlos a la regla, investigar como clasificarlos.
//Buscar caracteres de operacion (COP) y puntuacion (CPU), agregarlos a la regla.
//Luego ordenar la prioridad de reglas
//Probar reglas una vez completadas y armar palabras para reconocer en el txt y luego en el .c
//crear listas para recorrer y cumplir lo pedido:
//Listado de id falta ordenar alfabeticamente, no repetir ids, y contar la cant de veces que aparece
//Listado de lt falta obviar las comillas dado que las comillas las toma como caracteres, por ejemplo,
//  "hola" yyleng retorna 6, en realidad tendria que devolver 4-> hacer una funcion que obvie las comillas
// Listado de pr x 


//poner opciones en el main para mostrar las listas segun la opcion elegida(tipo menu)
//crear la entrada por consola de la opcion elegida y mostrarla 
//Adicional: Probar directiva parece que ya esta, investigar distintas directivas puede que alguna no entre 
//en la que hice



%}
DIRECTIVA "#include"[ ]*(\".*".h"\"|"<".*".h>") 
CEDECIMAL 	[1-9][0-9]* 
CEOCTAL		0[0-7]*
CEHEXA		0[xX][A-Fa-f0-9]+
CREAL	    [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER    "'"."'"

LITERALCADENA  \"(\\.|[^\\"])*\"

PRESERVADA_DATO	 int|char|float|bool|double|long|short|unsigned|signed|typedef
PRESERVADA_CONDIC if|else|switch|case|break|return
PRESERVADA_ITERATIVA while|for|do 


ID       	[a-zA-Z_][a-zA-Z0-9_]*

COP        "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="
CPU        "("|")"|"{"|"}"  

COMENTARIOS "//"(.)*\n|"/*"(.|\n)*"*/"

%%

{DIRECTIVA}   {printf("La cadena %s representa una directiva al compilador\n", yytext);}
{CEDECIMAL}   {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{CEOCTAL}     {printf("La cadena %s representa una constante entera octal\n", yytext);}
{CEHEXA}      {valor=strtol(yytext, NULL, 16);printf("La cadena %s representa una constante entera hexadecimal\n y su valor en decimal es %d", yytext),valor;} 
{CREAL}       {printf("La cadena %s representa una constante real\n", yytext);}
{COMENTARIOS} {printf("La cadena %s representa un comentario\n", yytext);} 
{CARACTER}    {acum= acum+1; printf("La cadena %s representa un caracter\n", yytext);}
{PRESERVADA_DATO}  {printf("La cadena %s representa una palabra reservada para representar un tipo de dato\n", yytext);
                    char *palabra=(char *)malloc(sizeof(char *));
                    strcpy(palabra,yytext);  pr =agregarALista2(pr,palabra);}
{PRESERVADA_CONDIC}  {printf("La cadena %s representa una palabra reservada para representar una sentencia condicional\n", yytext);}
{PRESERVADA_ITERATIVA}  {printf("La cadena %s representa una palabra reservada para representar una sentecia iterativa\n", yytext);}
{COP}         {printf("La cadena %s representa un caracter de operacion\n", yytext);}
{CPU}         {printf("La cadena %s representa un caracter de puntuacion\n", yytext);}
{ID}          {printf("La cadena %s representa un identificador\n", yytext);
               char *palabra=(char *)malloc(sizeof(char *));
               strcpy(palabra,yytext);  id =agregarALista(id,palabra,1);}
{LITERALCADENA} {printf("La cadena %s representa un literal cadena de %d caracteres\n", yytext,yyleng);
                 char *palabra=(char *)malloc(100*sizeof(char));
                 strcpy(palabra,yytext);  lt =agregarALista(lt,palabra,yyleng);}
. {printf("La cadena %s representa un caracter no reconocido\n", yytext);}
       
%%


int main(){
    
    yyin = fopen("entrada.txt","r");
    yylex();
    imprimirOpciones();
    return 0;
}

    //Comentarios y dudas

    //No deberia ser un archivo .c como entrada? 
    //Si solo use el txt para ir probando antes de mandarlo al .c ya que no me andara hinchando con los errores
    //lo vuelvo a poner para hacer una pre prueba en el txt y luego el mismo en .c
    
    //ademas tengo duda con el archivo de salida, no es innecesario? 
    //Es como decis no es necesario, pensaba en usarlo como un reporte final para que quede mas
    //presentable con todos los reportes en la salida.txt si llegamos seria bueno ponerlo a demas de por consola
    // que lo pensaba como un menu de opciones 

    //(Hice una clasificacion pero tal vez puede simplifacarse o reordenarse) sobre palabras reservadas
    //bien, alguien que la revise y vea si puede agregar mas dado que por internet rondaban entre 32 y 40
    //como dije en las cosas por hacer que las revisen si no pueden usarse como identificador entonces esas van


    //Agregue un menu de opciones con la funcion de mostrar todos los casos para probarlo
    //Esta genial el menu :O, le modifique un par de cosas, obvio funciona ahora pero da siempre la lista de id
    // mas adelante hay que modificarlo cuando tengamos las listas, ponele algo de minuscula hay mucha mayuscula jaja
    /* Algo asi solo a los que tienen nro
     1)Listado de identificadores encontrados y su cantidad de veces
    */

    //Agregue las directivas que faltan. Son muchisimas, y creo que el tp pide solo #define y #include
    //Entonces solo esas, faltaria la de define nada mas 

    // si hay que comentarlas usemos  /* */ porque sino linea por linea es un bardo  
    // si lo tendre en cuanta para el prox commit es que usaba teclas de acceso rapido por eso y me comenta
    // todo asi cuando selecciono y le doy con "crtl }" 

    //Lo de hex a dec da mal hay que verlo 
    
    //En la lista de pr se puede simplificar porque las acciones en las reglas de pr son iguales
    //Opciones
    //1) quiza lo ponemos todo en una definicion de pr y luego en la lista o acciones lo clasificamos
    //2) ya que esta clasificado en definiciones quizas lo unificamos en una regla con un "|" 
    // no recuerdo si se puede, y como queda una sola regla no repetimos acciones

    //Dato:
    //%{
    // DEFINICIONES Y DECLARACIONES DE C
    // }%

    // DEFINICIONES (NOMBRE EXR) -> Se definen nombres para las ERX

    // %%

    // REGLAS (ERX - CÓDIGO C) -> Conocido como PATRÓN/ACCIÓN

    // %%

    // CÓDIGO C DE USUARIO -> Código C que ejecuta el analizador léxico
