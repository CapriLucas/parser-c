%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}



extern int yylineno;
// usar yylineno para las lineas en ts

FILE* yyin;
FILE* yyout;

%}

%type <ccval> variableSimple    //se agrega el type a la produccion para que pueda abarcar cualquier tipo y no haya conflicto para derivar


%union {
char ccval[20]; // cadenas
double dval; // numeros reales/racionales
int ival; // numeros enteros
int tipo;
}


%token <ival> CENTERO 
%token <dval> CREAL
%token <ccval> ID
%token <ccval> LCADENA
%token <ccval> CCARACTER
%token <ccval> OPASIG 
%token <ccval> OR 
%token <ccval> AND 
%token <ccval> OPIGUAL 
%token <ccval> OPREL 
%token <ccval> OPINCDEC
%token <ccval> T_DATO 
%token <ccval> TCLASE 
%token <ccval> FLECHA 
%token <ccval> STRUNION 
%token <ccval> CALTIPO 
%token <ccval> OPDESIGUAL
%token <ccval> OPERADORUNARIO
%token <ccval> ENUM
%token <ccval> IF 
%token <ccval> ELSE 
%token <ccval> SIZEOF 
%token <ccval> SWITCH
%token <ccval> WHILE 
%token <ccval> DO 
%token <ccval> FOR 
%token <ccval> RETURN 
%token <ccval> CONTINUE 
%token <ccval> GOTO 
%token <ccval> BREAK 
%token <ccval> CASE 
%token <ccval>DEFAULT
%token <ccval> DIRECTIVA
%token <ccval> CNORECONOCIDO
%token <ccval> errorLexico


%% 

input:  /* vacio */
        | input line
;


line:   declaracion  
        | sentencia 
        | expresion
        | errorLexico {printf("Se encontro un error lexico en la linea %d\n ", yylineno);}
        | error {printf("\nSe encontro un error sintactico en la linea %d. Imposible emparejar por alguna produccion\n", yylineno);} //ver como hacer aca con los errores.
;


/* GRAMATICA DE EXPRESIONES */
expresion:    expresionAsignacion
;

expresionAsignacion:    expresionCondicional
                        | expresionUnaria OPASIG expresionAsignacion
;


expresionCondicional:    expresionOr
                        | expresionOr '?' expresion ':' expresionCondicional
;
expresionOr:  expresionAnd
            | expresionOr OR expresionAnd 
;
expresionAnd: expresionIgualdad
            | expresionAnd AND expresionIgualdad
;
expresionIgualdad:   expresionRelacional
            | expresionIgualdad OPIGUAL expresionRelacional
;





expresionRelacional: expresionAditiva
                    |expresionRelacional OPREL expresionAditiva
;









expresionAditiva: expresionMultiplicativa 
        | expresionAditiva '+' expresionMultiplicativa {  if($<tipo>1==$<tipo>3) { 
                                                        if($<tipo>1==1){
                                                        $<ival>$=$<ival>1+$<ival>3;
                                                        printf("El resultado es: %d\n",$<ival>$);
                                                        }
                                                        else{
                                                        $<dval>$=$<dval>1+$<dval>3;
                                                        printf("El resultado es: %f\n",$<dval>$);
                                                        }
                                                           } else {
                                                                printf("Error semantico en la linea %d. Los operandos son de distinto tipo \n", yylineno);
                                                                }
                                                        }
        
        | expresionAditiva '-' expresionMultiplicativa
;
expresionMultiplicativa: expresionUnaria {$<ival>$=$<ival>1;}
        | expresionMultiplicativa '*' expresionUnaria
        | expresionMultiplicativa '/' expresionUnaria
        | expresionMultiplicativa '%' expresionUnaria
;

;
expresionUnaria: expresionPostFijo {$<ival>$=$<ival>1;}
        | OPINCDEC expresionUnaria
        | SIZEOF '(' T_DATO ')'
;


expresionPostFijo:   expresionPrimaria {$<ival>$=$<ival>1;}
            | expresionPostFijo '[' expresion ']'
            | expresionPostFijo '(' listaArgumentos ')'
            | expresionPostFijo '.' ID
            | expresionPostFijo FLECHA ID
            | expresionPostFijo OPINCDEC

;
listaArgumentos:  /*vacio*/
            |expresionAsignacion
            | listaArgumentos ',' expresionAsignacion
;
expresionPrimaria:     ID 
            | CENTERO {$<ival>$=$<ival>1;}
            | CREAL 
            | LCADENA 
            | '(' expresion ')'
;








/* GRAMATICA DE DECLARACIONES */

declaracion: '\n' 
        | declaracionDeVariables 
        |declaracionDeFunciones 
        |definicionDeFuncion    
;

declaracionDeVariables: T_DATO declaracionDeVariablesPuntero {printf(" de tipo %s%s.\n", $<ccval>1,$<ccval>2);}
;
declaracionDeVariablesPuntero: listaVariablesSimples ';' {strcpy($<ccval>$, "");}
        | '*' listaVariablesSimples ';' {strcpy($<ccval>$, "*");}
        |  ID listaArreglos ';'  {strcpy($<ccval>$, "");printf ("\nSe encontro la variable arreglo %s", $<ccval>1);}
;
listaArreglos: arreglo 
                | listaArreglos arreglo
;
arreglo: '[' expresion ']'
;
listaVariablesSimples: variableSimple                     {printf ("\nSe encontro la variable %s", $<ccval>$);}
                        |listaVariablesSimples ',' variableSimple  
;

variableSimple: ID inicializador                           {strcpy($<ccval>$, $<ccval>1);}
;

inicializador: /* vacio */
              |OPASIG   expresionCondicional
;


declaracionDeFunciones: T_DATO  ID '(' opcionArgumentos ')' ';'   {printf ("\nSe encontro la funcion %s de tipo %s\n", $<ccval>2, $<ccval>1);}
                        | T_DATO '*' ID '(' opcionArgumentos ')' ';' {printf ("\nSe encontro la funcion %s de tipo %s*\n", $<ccval>3, $<ccval>1);}
;

opcionArgumentos: /*vacio*/
                | T_DATO referencia ID 
                | T_DATO referencia ID ',' opcionArgumentos
;

referencia: /*vacio*/
        | '&'
;

definicionDeFuncion: T_DATO ID '(' opcionArgumentos ')' sentencia  {printf ("\nSe encontro la funcion %s de tipo %s\n ", $<ccval>2, $<ccval>1);}
;




/*GRAMATICA DE SENTENCIAS*/

sentencia:		
        sentenciaExpresion '\n'
        | sentenciaCompuesta 
        | sentenciaSeleccion 
        | sentenciaIteracion 
        | sentenciaSalto  
        | sentenciaEtiqueta  
;

sentenciaExpresion: ';'
                    | expresion ';' 
;

sentenciaCompuesta:	'{' listaDeclaracionesOpcional '\n' listaSentenciasOpcional '}' '\n'    {printf("Sentencia compuesta encontrada.\n"); }
                        | '{' listaDeclaracionesOpcional  listaSentenciasOpcional '}' '\n'    {printf("Sentencia compuesta encontrada.\n"); }
;


listaDeclaracionesOpcional: /*vacio*/
                        | declaracion 
                        | listaDeclaracionesOpcional declaracion
;

listaSentenciasOpcional: /*vacio*/
                        | sentencia
                        | listaSentencias sentencia 
;

listaSentencias: sentencia 
                | listaSentencias sentencia
;




sentenciaSeleccion:	IF '(' expresion ')' sentencia elseSent                         {printf("Sentencia de seleccion If encontrada.\n"); }
                        | SWITCH '(' expresion ')' sentencia                            {printf("Sentencia de seleccion switch encontrada.\n"); }
;

elseSent: 	/* vacio */
			| ELSE sentencia                                                {printf("Sentencia de seleccion If-Else encontrada.\n"); }
;


sentenciaIteracion:	WHILE '(' expresion ')' sentencia                                               {printf("Sentencia de Iteracion while encontrada.\n"); }
                        | DO sentencia WHILE '(' expresion ')' ';'                                      {printf("Sentencia de Iteracion do while encontrada.\n"); }
                        | FOR '('expresionOpc ';' expresionOpc ';' expresionOpc ')' sentencia           {printf("Sentencia de Iteracion for encontrada.\n"); }
;


sentenciaSalto:  RETURN expresionOpc ';'                                                 {printf("Sentencia de salto return encontrada.\n"); }
                        | CONTINUE ';'                                                   {printf("Sentencia de salto continue encontrada.\n"); }
                        | BREAK ';'                                                      {printf("Sentencia de salto break encontrada.\n"); }
                        | GOTO ID ';'                                                    {printf("Sentencia de salto goto encontrada.\n"); }
;


sentenciaEtiqueta:   CASE expresionCondicional ':' sentencia                             {printf("Sentencia de etiqueta case encontrada.\n"); }
                        | DEFAULT ':' sentencia                                          {printf("Sentencia de etiqueta default encontrada.\n"); }
                        | ID ':' sentencia                                       
;       

expresionOpc: /*vacio*/
                        |expresion

;


%%


int yyerror (char *mensajeError){  //tambien ver como hay que manerjarlo en el archivo de salida o si es necesario (todavia no me fije)
        fprintf(yyout, "Se encontro un error sintatico\n ", mensajeError);
}


//La TS es global no hace falta ingresarla en putVariable

int main (){
//funciones y menu
/*struct TablaSimbolos *TS;
TS = inicializarTS();
if(TS->listaVar == NULL){
        printf("PUTOOO");
}
printf("kasjlkasjdlkas");
TS = putVariable(TS,"hola","int");
printf("kasjlkasjdlkas");
printListVar(TS);
*/

listaVariables=agregarVariable(listaVariables,"Int","askdja");
mostrarListaVariables(listaVariables);
mostrarListaErroresLexicos(listaErroresLexicos);
yyin = fopen("Entrada.c","r");
yyout= fopen("Salida.txt", "w");
yyparse();



//---al final creo que es mas facil hacer cuatro listas. Una para las funciones, otra para las variables y las otras dos de errores. La otra opcion es hacer una sola struct que tenga el tipo variable, tipo, y un campo para parametros, que este ultimo puede ser NULL si es una variable (pero puede ser un quilombo)
//---tambien se me ocurrio como manejar el tema de los errores: los lexicos, agregar la cadena no reconocida a una lista cuando los detecta *lo hice. Probe hacerlo desde el .l pero me rompe con lineas de codigo en la consola que 
//ni idea que son. 
//---Los semanticos, agregarlos tambien a cada lista segun corresponda.
//Los sintactico, mostrar los msjs de errores segun corresponda
//revisar el control de tipos, ahora muestra los printf pero no lo hace correctamente. 



}