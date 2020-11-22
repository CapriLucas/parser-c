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
struct yylval_struct{
int ival;// numeros enteros
double dval;// numeros reales/racionales
char ccval[20]; // cadenas
int tipo;
} estructura;
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


line:   '\n'
        | declaracion  '\n' 
        | sentencia '\n'
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

expresionAditiva: expresionMultiplicativa        {$<estructura>$ = $<estructura>1;}

        | expresionAditiva '+' expresionMultiplicativa {  if($<estructura>1.tipo==$<estructura>3.tipo) { 
                                                        if($<estructura>1.tipo==1){
                                                        $<estructura>$.ival=$<estructura>1.ival+$<estructura>3.ival;
                                                        }
                                                        else{
                                                        $<estructura>$.dval=$<estructura>1.dval+$<estructura>3.dval;
                                                        }
                                                           } else {
                                                                printf("Error semantico en la linea %d. Los operandos son de distinto tipo \n");
                                                                }
                                                        }
        
        | expresionAditiva '-' expresionMultiplicativa 
;

expresionMultiplicativa: expresionUnaria              {$<estructura>$ = $<estructura>1;}
        | expresionMultiplicativa '*' expresionUnaria
        | expresionMultiplicativa '/' expresionUnaria
        | expresionMultiplicativa '%' expresionUnaria
;

;
expresionUnaria: expresionPostFijo         {$<estructura>$ = $<estructura>1;}
        | OPINCDEC expresionUnaria
        | SIZEOF '(' T_DATO ')'
;


expresionPostFijo:   expresionPrimaria            {$<estructura>$ = $<estructura>1;}
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
            | CENTERO           {$<estructura>$.tipo=$<estructura>1.tipo;$<estructura>$.ival=$<estructura>1.ival;}
            | CREAL             {$<estructura>$.tipo=$<estructura>1.tipo;$<estructura>$.dval=$<estructura>1.dval;}
            | LCADENA 
            | '(' expresion ')'
            ;





/* GRAMATICA DE DECLARACIONES */

declaracion: declaracionDeVariables
             |declaracionDeFunciones
             |defincionDeFuncion    
;


declaracionDeVariables: T_DATO listaVariablesSimples ';'                 {printf(" de tipo %s.\n", $<estructura>1.ccval);}
;

listaVariablesSimples: variableSimple                                    {printf ("\nSe encontro la variable %s", $<estructura>$.ccval);}
                        |listaVariablesSimples ',' variableSimple  
;

variableSimple: ID inicializador                                         {strcpy($<estructura>$.ccval, $<estructura>1.ccval);}
;

inicializador: /* vacio */
              |OPASIG   expresionCondicional
;


declaracionDeFunciones: T_DATO ID '(' opcionArgumentos ')' ';'            {printf ("\nSe encontro la funcion %s de tipo %s\n", $<estructura>2.ccval, $<estructura>1.ccval);}
;

opcionArgumentos: /*vacio*/
                | T_DATO referencia ID 
                | T_DATO referencia ID ',' opcionArgumentos
;

referencia: /*vacio*/
        | '&'
;

defincionDeFuncion: T_DATO ID '(' opcionArgumentos ')' sentencia           {printf ("\nSe encontro la funcion %s de tipo %s\n ", $<estructura>2.ccval, $<estructura>1.ccval);}





/*GRAMATICA DE SENTENCIAS*/

sentencia: sentenciaExpresion    
        | sentenciaCompuesta 
        | sentenciaSeleccion 
        | sentenciaIteracion 
        | sentenciaSalto  
        | sentenciaEtiqueta  
;

sentenciaExpresion: ';'
                    |expresion;

sentenciaCompuesta:	'{' listaDeclaracionesOpcional listaSentenciasOpcional '}'      {printf("Sentencia compuesta encontrada.\n"); }
;


listaDeclaracionesOpcional: /*vacio*/
                        |declaracion
                        | listaDeclaracionesOpcional declaracion
;

listaSentenciasOpcional: /*vacio*/
                        | sentencia
                        |listaSentencias sentencia 
;

listaSentencias: sentencia 
                |listaSentencias sentencia
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




int main (){
//funciones y menu

yyin = fopen("Entrada.c","r");
yyout= fopen("Salida.txt", "w");
yyparse();


}