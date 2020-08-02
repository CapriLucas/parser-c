%option noyywrap
%{

#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<string.h>
#include"funcionesTP3.h"
int nlinea = 1;


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
//  El listado debe estar ordenado alfabéticamente.
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

//-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

//   COSAS PARA ARREGLAR - AGREGAR

//Faltan algunos COP y CPU
//ordenar la prioridad de reglas esto para el archivo.c ----->"vean la bnf"<--------
//Probar reglas una vez completadas en el .c pongan codigo bien escrito de alguna pagina o trabajos 
//anteriores que hayan hecho
//crear listas para recorrer y cumplir lo pedido:
/*  Listado de id falta ordenar alfabeticamente
    Listado de pr falta decidir cosas
*/

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------


%}

DIRECTIVA            "#include"[ ]*(\".*".h"\"|"<".*".h>")|"#define"[ ]+{ID}[ ]+({CEDECIMAL}|{CEHEXA}|{CEOCTAL}|{CREAL})
CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             '.'|'\\0'|'\\n'
PRESERVADA_DATO	     int|char|float|bool|double|long|short|unsigned|signed|typedef|const|enum|struct
PRESERVADA_CONDIC    if|else|switch|case|break|return|default
PRESERVADA_ITERATIVA while|for|do 
PRESERVADA_OTRO      auto|continue|extern|goto|register|static|union|void|volatile

LITERALCADENA        \"(\\.|[^\\"])*\"

PALABRA_RESERVADA    {PRESERVADA_DATO}|{PRESERVADA_CONDIC}|{PRESERVADA_ITERATIVA}|{PRESERVADA_OTRO}

ID       	         [a-zA-Z_][a-zA-Z0-9_]*

COP                  "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="
CPU                  "("|")"|"{"|"}"|";"|","|":"  

COMENTARIOS_MULTIPLES \/\*(\*+[^\*\/]|[^\*])*\*+\/
COMENTARIOS_SIMPLES   \/\/.*
CARACTER_NO_RECONOCIDO (.)


%%

{DIRECTIVA}             {printf("La cadena %s representa una directiva al compilador\n", yytext);
                        dir = verificarCadena2(dir,yytext,nlinea);}

{CEDECIMAL}             {printf("La cadena %s representa una constante entera decimal\n", yytext);
                        cdec = verificarCadena(cdec,yytext);}

{CEOCTAL}               {printf("La cadena %s representa una constante entera octal\n", yytext);
                        int oct=(int)strtol(yytext, NULL, 0);
                        //int oct =OctalADecimal(atoi(yytext));
                        coct = verificarCadena2(coct,yytext,oct);
                        }

{CEHEXA}                {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);
                        int hex=(int)strtol(yytext, NULL, 0);
                        chex = verificarCadena2(chex,yytext,hex);
} 

{CREAL}                 {printf("La cadena %s representa una constante real\n", yytext);
                        cre = verificarCadena4(cre,yytext);}

{CARACTER}              {printf("La cadena %s representa un caracter\n", yytext);
                        ccar = verificarCadena3(ccar,yytext);}

{COMENTARIOS_MULTIPLES} {printf("La cadena %s representa un comentario de multiples lineas\n", yytext);
                        comml = verificarCadena3(comml,yytext);} 

{COMENTARIOS_SIMPLES}   {printf("La cadena %s representa un comentario simple\n", yytext);
                        coml = verificarCadena3(coml,yytext);} 

{PALABRA_RESERVADA}     {printf("La cadena %s representa una palabra reservada para representar un tipo de dato\n", yytext);
                        pr = verificarCadena3(pr,yytext);}

{COP}                   {printf("La cadena %s representa un caracter de operacion\n", yytext);
                          cop = verificarCadena(cop,yytext);}

{CPU}                   {printf("La cadena %s representa un caracter de puntuacion\n", yytext);
                          cpu = verificarCadena(cpu,yytext);}

{ID}                    {printf("La cadena %s representa un identificador\n", yytext);
                          id =verificarCadena(id,yytext);}
              
{LITERALCADENA}         {printf("La cadena %s representa un literal cadena de %d caracteres\n", yytext,yyleng);
                          char * cad=eliminarComillas(yytext);
                          lt =verificarCadena2(lt,cad,strlen(cad));}

\n  {nlinea +=1;}         
{CARACTER_NO_RECONOCIDO} {printf("La cadena %s representa un caracter no reconocido\n", yytext);
        ccarno = verificarCadena2(ccarno,yytext,nlinea);}
       
%%


int main(){
    
    yyin = fopen("entrada.txt","r");
    yylex();
    //printf("%d",printf);
    imprimirOpciones();
    return 0;
}












    //COMENTARIOS, DUDAS Y CAMBIOS

    //Agregue una definicion para #define, pero me parece que queda otra mas, la de los ejemplos que estan en el archivo de entrada funcionan bien
    //Agregue un par de caracteres de puntuacion y operacion que faltaban (Puede que falte alguno todavia, revisar lo del sizeof)
    
    //Agregue una funcion eliminarcomillas
    //Estan todas las listas agregue directivas a las opciones 
    //Agregue un entrada.c con una funcion simple 
    //Agregue la parte que devuelve parte mantisa y entera en verificar4 ya que solo lo usamos en una regla
    


 // COSAS CORREGIDAS Y LISTAS (Borrar despues)

//No deberia ser un archivo .c como entrada? 
//Si solo use el txt para ir probando antes de mandarlo al .c ya que no me andara hinchando con los errores
//lo vuelvo a poner para hacer una pre prueba en el txt y luego el mismo en .c



