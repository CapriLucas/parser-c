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
//Luego ordenar la prioridad de reglas
//Probar reglas una vez completadas y armar palabras para reconocer en el txt y luego en el .c
//crear listas para recorrer y cumplir lo pedido:
/*  Listado de id falta ordenar alfabeticamente
    Listado de lt falta obviar las comillas dado que las comillas las toma como caracteres, por ejemplo,
      "hola" yyleng retorna 6, en realidad tendria que devolver 4-> hacer una funcion que obvie las comillas
    Listado de pr falta decidir cosas
    Listado de constantes:
                     dec falta una funcion que sume todos los valores de la lista (REVISAR)
                     real faltaria una funcion o dos que devuelvan la parte mantisa y entera de un creal
    Listado de car no reconocidos falta lo de ver en que linea fueron encontrados, que alguien vea los videos
      habia hecho algo el profe
*/
//Revisar el #define

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------


%}

DIRECTIVA            "#include"[ ]*(\".*".h"\"|"<".*".h>")|"#define"[ ]*{ID}*[ ]*({CEDECIMAL}|{CEHEXA}|{CEOCTAL}|{CREAL})
CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             "'"."'"
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



%%

{DIRECTIVA}             {printf("La cadena %s representa una directiva al compilador\n", yytext);}

{CEDECIMAL}             {acum = acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);
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
                        }

{CARACTER}              {acum= acum+1; printf("La cadena %s representa un caracter\n", yytext);
                        ccar = verificarCadena3(ccar,yytext);}

{COMENTARIOS_MULTIPLES} {printf("La cadena %s representa un comentario de multiples lineas\n", yytext);} 

{COMENTARIOS_SIMPLES}   {printf("La cadena %s representa un comentario simple\n", yytext);} 

{PALABRA_RESERVADA}     {printf("La cadena %s representa una palabra reservada para representar un tipo de dato\n", yytext);
                        pr = verificarCadena3(pr,yytext);}

{COP}                   {printf("La cadena %s representa un caracter de operacion\n", yytext);
                          cop = verificarCadena(cop,yytext);}

{CPU}                   {printf("La cadena %s representa un caracter de puntuacion\n", yytext);
                          cpu = verificarCadena(cpu,yytext);}

{ID}                    {printf("La cadena %s representa un identificador\n", yytext);
                          id =verificarCadena(id,yytext);}
              
{LITERALCADENA}         {printf("La cadena %s representa un literal cadena de %d caracteres\n", yytext,yyleng);
                          lt =verificarCadena2(lt,yytext,yyleng);}

[ \t\n]+          
. {printf("La cadena %s representa un caracter no reconocido\n", yytext);}
       
%%


int main(){
    
    yyin = fopen("entrada.txt","r");
    yylex();
    //int x = 0xf;
    //printf("%d",x);
    imprimirOpciones();
    return 0;
}












    //COMENTARIOS, DUDAS Y CAMBIOS

    //Cambie la regla de comentarios: "//"(.)*\n|"/*"(.|\n)*"*/" por dos distintas para identificar entre comentarios simples y multiples
    //agrego funcion para pasar de hexa a decimal 
    //agrego funcion para pasar de octal a decimal 
    //agrego funcion para sumar los elementos de la lista (esta está polemica ajajs revisenla y fijense)
    //Agregue todas las palabras reservadas que faltaban, y las reagrupe en una sola regla para que quede un poco mas simple
    //Agregue una definicion para #define, pero me parece que queda otra mas, la de los ejemplos que estan en el archivo de entrada funcionan bien
    //Agregue un par de caracteres de puntuacion y operacion que faltaban (Puede que falte alguno todavia, revisar lo del sizeof)
    //Modifique un poco el menu para que no parezca que te esta gritando con las mayusculas jajaj
    /*Pense en modificar la defincion de constantes reales, pero tendria que hacer como definciones que "abarquen" pocos caracteres y no se que tan expresivo queda
    pero en si la definicion esta bien asi */
    //Acomode un poco los archivos para que no quede todo tan mezclado
    //No se que tanto mas se pueden "delegar" las definiciones usando reglas que ya estan, habria que cambiar casi TODAS y no se si queda tan expresivo en definitiva


    //Simplifique lo de pasar a decimal, ojala espero que hayas copiado las funciones si no me vas a querer matar xD
    

    

    //ESTRUCTURA DEL ARCHIVO.L:

    //%{
    // DEFINICIONES Y DECLARACIONES DE C
    // }%

    // DEFINICIONES (NOMBRE EXR) -> Se definen nombres para las ERX

    // %%

    // REGLAS (ERX - CÓDIGO C) -> Conocido como PATRÓN/ACCIÓN

    // %%

    // CÓDIGO C DE USUARIO -> Código C que ejecuta el analizador léxico
 






 // COSAS CORREGIDAS Y LISTAS (Borrar despues)

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

// si hay que comentarlas usemos  /* */ porque sino linea por linea es un bardo  
// si lo tendre en cuanta para el prox commit es que usaba teclas de acceso rapido por eso y me comenta
// todo asi cuando selecciono y le doy con "crtl }" 

//funcion que "propias de c" que podramos usar expliquen para que sirve

//Encontre una funcion: strtol(const char *str, char **endptr, int base) , que lo que hace es convertir el valor hexa a decimal
//aunque no entiendo por que no me covierte la cadena hexa que encontro a decimal ¿??
// En si en la funcion "str" es la cadena principal
// "endptr" seria la parte de caracteres luego del ultimo caracter numerico
//lo que hace la funcion es retornar un long int que es la parte numerica de la cadena principal "str"
// EJEMPLO  hexaEnDec= (int)strtol("0X2 asdk", luegoDePrtNum, 16);
//Creas una variable hexaEnDec por asi decir y lo que retorna la funcion lo convertis en int con casteo (int)
//,y una variable luegoDePrtNum que no te sirve para nada pero no podes dejarlo vacio y base 16
// tambien podes buscar una funcion hecha en c que quizas haya en internet sino funciona con strtol


//Agregue las directivas que faltan. Son muchisimas, y creo que el tp pide solo #define y #include
    //Entonces solo esas, faltaria la de define nada mas 


/* En la lista de pr se puede simplificar porque las acciones en las reglas de pr son iguales
Opciones
1) quiza lo ponemos todo en una definicion de pr y luego en la lista o acciones lo clasificamos
2) ya que esta clasificado en definiciones quizas lo unificamos en una regla con un "|" 
no recuerdo si se puede, y como queda una sola regla no repetimos acciones */

//Lo de hex a dec da mal hay que verlo 





