%option noyywrap
%{

#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> /* */
#include<string.h>
#include        "funcionesTP3.h"
 # define sa(as,asa) laslal?&
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
//  1 Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. 
//   El listado debe estar ordenado alfabéticamente.
//  2 Listado de literales cadena encontrados indicando la longitud de los mismos.
//  3 Listado de palabras reservadas en el orden en el que han aparecido.
//  4 Listado de constantes indicando según su tipo:
//          Para las constantes octales indicar su valor entero decimal.
//          Para las constante hexadecimales indicar su valor entero decimal.
//          Para las constantes decimales indicar el valor de cada una y el total acumulado de sumar todas ellas.
//          Para las constantes reales indicar el valor de su mantisa y parte entera.
//          Para las constantes caracter, enumerarlas según orden de aparición. 
//  5 Listado de operadores/caracteres de puntuación indicando cantidad de veces que aparecen.
//  6 Listado de comentarios encontrados distinguiendo si se trata de comentarios de una línea o múltiples líneas.
//  7 Listado de cadenas y/o caracteres no reconocidos indicando el número de línea.

// 8 Desafío opcional
//  Adicionar al analizador léxico el reconocimiento de las directivas del precompilador #Include #Define.

//-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

//   COSAS PARA ARREGLAR - AGREGAR

//Corregi los cop y cpu pero igual hay dudas con algunos que representan ambos (ejemplo los () y la ,)
//En esos casos podriamos ponerlos en ambas y hacer unas erx en esos casos, sino ponerlo en cualquiera de los 2  
//Probar reglas una vez completadas en el .c pongan codigo bien escrito de alguna pagina o trabajos 
//anteriores que hayan hecho
//si aparece \n \t %d %f etc en una cadena tambien se imprime "hola%d\n" hay que corregir eso o dejarlo asi nomas 
//Reporte completo listo
//Corregi lo del #define hay que probar

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------


%}

DIRECTIVA            [ ]*"#"[ ]*"include"[ ]*(\".*".h"\"|"<".*".h>")|[ ]*"#"[ ]*"define"[ ]+{ID}[ ]*("("[ ]*({ID}[ ]*","[ ]*)*{ID}[ ]*")")?[ ]+([^#\n]+)?
CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             '.'|'\\0'|'\\n'
PR_DATO	             int|char|float|bool|double|long|short|unsigned|signed|typedef|const|enum|struct
PR_CONDICIONAL       if|else|switch|case|break|return|default
PR_ITERATIVA         while|for|do 
PR_OTRO              auto|continue|extern|goto|register|static|union|void|volatile

LITCAD               \"(\\.|[^\\"])*\"

PR                   {PR_DATO}|{PR_CONDICIONAL}|{PR_ITERATIVA}|{PR_OTRO}

ID       	         [a-zA-Z_][a-zA-Z0-9_]*

COP                  "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"  

COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*

/*  /[ |\n|COMENTARIOS_MULTIPLES|COMENTARIOS_SIMPLES]      Esto sirve puede usarse despues de {DIRECTIVA}*/  
%%

{DIRECTIVA}     {printf("La cadena %s representa una directiva al compilador\n", yytext);
                        dir = verificarCadena2(dir,yytext,nlinea);}

{PR}                {printf("La cadena %s representa una palabra reservada para representar un tipo de dato\n", yytext);
                        pr = verificarCadena3(pr,yytext);}

{ID}                {printf("La cadena %s representa un identificador\n", yytext);
                        id =verificarCadena5(id,yytext);}

{CEDECIMAL}         {printf("La cadena %s representa una constante entera decimal\n", yytext);
                        cdec = verificarCadena(cdec,yytext);}

{CEOCTAL}           {printf("La cadena %s representa una constante entera octal\n", yytext);
                        int oct=(int)strtol(yytext, NULL, 0);
                        coct = verificarCadena2(coct,yytext,oct);}

{CEHEXA}            {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);
                        int hex=(int)strtol(yytext, NULL, 0);
                        chex = verificarCadena2(chex,yytext,hex);} 

{CREAL}             {printf("La cadena %s representa una constante real\n", yytext);
                        cre = verificarCadena4(cre,yytext);}

{CARACTER}          {printf("La cadena %s representa un caracter\n", yytext);
                        ccar = verificarCadena3(ccar,yytext);}

{LITCAD}            {printf("La cadena %s representa un literal cadena de %d caracteres\n", yytext,yyleng);
                          char * cad=devolverCadena(yytext);
                          lt =verificarCadena2(lt,cad,strlen(cad));}

{COP}               {printf("La cadena %s representa un caracter de operacion\n", yytext);
                          cop = verificarCadena(cop,yytext);}

{CPU}               {printf("La cadena %s representa un caracter de puntuacion\n", yytext);
                          cpu = verificarCadena(cpu,yytext);}

{COM_MULT}          {printf("La cadena %s representa un comentario de multiples lineas\n", yytext);
                        comml = verificarCadena3(comml,yytext);} 

{COM_SIMP}          {printf("La cadena %s representa un comentario simple\n", yytext);
                        coml = verificarCadena3(coml,yytext);} 


\n  {nlinea +=1;}    
[\t ]+

(.)                 {printf("La cadena %s representa un caracter no reconocido\n", yytext);
                        ccarno = verificarCadena2(ccarno,yytext,nlinea);}

%%
/* NOTA: para la ultima erx de cadena no reconocida ya se probo:
     (.)(.)+/[ ]
     [^ ]+/[ ]
     (.)* /[]
     (.)+/[]  
     {REGLAS}{REGLAS}+/[ ]
     {REGLAS}(REGLAS|[^ ])+
     Descubri que el espacio se puede obviar en algunos casos del codigo asi que es opcional
 */

int main(){
    
    yyin = fopen("entrada.c","r");
    yylex();
    int print = strcmp("alv","aca");
    printf("%d",print);
    
    imprimirOpciones();
    return 0;
}



    //COMENTARIOS, DUDAS Y CAMBIOS

        
    /* Los comentarios yo los dejaria asi, osea que aparezca "La cadena //ejemplo representa un comentario" y lo mismo con /* en los de multiple linea,
    si los sacamos parece que son identificadores, el hecho de que tengan //  creo que hace que parezcan mas comentario que otra cosa             */
    /* "falta una regla para cadena no reconocida" --- te referis a la regla (.)? porque probe y al parecer funciona bien, sino habria que en una regla
    poner todas las cobinaciones de simbolos y cosas que no estan en las otras */
        //De eso hablo estaba intentando por dias algo asi tipo{REGLAS}{REGLAS}+ pero si tocaba idid == id o cdeccdec == cdec
        // esos casos presentan problema quiza alguno mas no he probado todas las posibilidades
        //EN REGLAS habia puesto todas las que hicimos, obvio que tambien estan [%&$#!] que no los puse
        // La idea es que si viene tipo 123abc o ABC123 lo tome como cadena no reconocida



 // COSAS CORREGIDAS Y LISTAS (Borrar despues)


   //agregue mas caracteres de puntuacion y operacion(ver lo que puse arriba)
    //revisar en la libreria, empece una funcion para imprimir la lista de cada cosa pedida en un archivo txt nuevo de salida, pero me imprime 
    //CUALQUIER cosa ?¿??
        //no hace falta ninguna func estaba pensando que seria mas facil poner todo lo de las opciones
        // en la op9 e imprimir todo lo que tengamos osea los mostrar lista todo seguidos y separarlos con printf
        
