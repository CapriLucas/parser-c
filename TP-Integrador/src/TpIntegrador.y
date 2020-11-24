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
struct yylval_Tokens
  {
      int tipo;
      int ival;
      double dval;
  } estructura;
struct yylval_TokenError
  {
      int linea;
      char nomError[20];
  } errorLex;
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
%token <ccval> OPDESIGUAL
%token <ccval> OPERADORUNARIO
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

%token <ccval> CNORECONOCIDO
%token <ccval> errorLexico


%% 

input:  /* vacio */
        | input line
;


line:   declaracion   
        | sentencia 
        | expresion 
        | errorLexico {
                char *cadena = (char *)malloc((strlen($<errorLex>1.nomError) + 1) * sizeof(char *));
                strcpy(cadena,$<errorLex>1.nomError); 
                int linea = $<errorLex>1.linea;
                listaErroresLexicos = agregarErrorLexico(listaErroresLexicos, cadena , linea);

        }

        | error '\n' {listaErroresSintacticos=agregarErrorSintactico(listaErroresSintacticos,yylineno);} //ver como hacer aca con los errores.
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
        | expresionAditiva '+' expresionMultiplicativa {  if($<estructura>1.tipo==$<estructura>3.tipo) { 
                                                        if($<estructura>1.tipo==1){
                                                        $<estructura>$.ival=$<estructura>1.ival+$<estructura>3.ival;
                                                        printf("El resultado es: %d\n",$<estructura>$.ival);
                                                        }else{
                                                        $<estructura>$.dval=$<estructura>1.dval+$<estructura>3.dval;
                                                        printf("El resultado es: %f\n",$<estructura>$.dval);
                                                        }
                                                           } else {
                                                                printf("Error semantico en la linea %d Los operandos son de distinto tipo \n",yylineno);
                                                                printf("Tipo1 = %d. Tipo2 = %d. \n",$<estructura>1.tipo,$<estructura>3.tipo);
                                                                }
                                                        }
        
        | expresionAditiva '-' expresionMultiplicativa
;
expresionMultiplicativa: expresionUnaria {
                    if($<estructura>1.tipo==1){
                    $<estructura>$.tipo=$<estructura>1.tipo;
                    $<estructura>$.ival=$<estructura>1.ival;
                    }else{
                        $<estructura>$.tipo=$<estructura>1.tipo;
                        $<estructura>$.dval=$<estructura>1.dval;
                        }
                                        }
        | expresionMultiplicativa '*' expresionUnaria
        | expresionMultiplicativa '/' expresionUnaria
        | expresionMultiplicativa '%' expresionUnaria
;

;
expresionUnaria: expresionPostFijo {
                    if($<estructura>1.tipo==1){
                    $<estructura>$.tipo=$<estructura>1.tipo;
                    $<estructura>$.ival=$<estructura>1.ival;
                    }else{
                        $<estructura>$.tipo=$<estructura>1.tipo;
                        $<estructura>$.dval=$<estructura>1.dval;
                        }
                                        }
        | OPINCDEC expresionUnaria
        | SIZEOF '(' T_DATO ')'
;


expresionPostFijo:   expresionPrimaria {

                    if($<estructura>1.tipo==1){
                    $<estructura>$.tipo=$<estructura>1.tipo;
                    $<estructura>$.ival=$<estructura>1.ival;
                    }else{
                        $<estructura>$.tipo=$<estructura>1.tipo;
                        $<estructura>$.dval=$<estructura>1.dval;
                        }
                                        }
            | expresionPostFijo '[' expresion ']'
            | ID '(' listaArgumentos ')' {
                    char *id = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                    strcpy(id,$<ccval>1);
                    int linea = yylineno;
                    comprobarInvocacionFuncion(listaFunciones,listaParametrosAux,id,linea);
                    listaParametrosAux = NULL;
                } 
            | expresionPostFijo '.' ID
            | expresionPostFijo FLECHA ID
            | expresionPostFijo OPINCDEC

;
listaArgumentos:  /*vacio*/
            |expresionAsignacionBis 
            | listaArgumentos ',' expresionAsignacionBis
;
expresionAsignacionBis: expresionAsignacion {
                                        char *id = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(id,$<ccval>1);
                                        variableAux = buscarVariable(listaVariables, id);
                                        if(variableAux == NULL){
                                                char *tipo = (char *)malloc((strlen("undefined") + 1) * sizeof(char *));
                                                strcpy(tipo,"undefined");
                                                listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);
                                                variableAux = NULL;
                                        }
                                        else{
                                                char *tipo = (char *)malloc((strlen(variableAux->tipoVar) + 1) * sizeof(char *));
                                                strcpy(tipo,variableAux->tipoVar);
                                                listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);
                                                variableAux = NULL;

                                        }
                                        }
;
expresionPrimaria:     ID  {strcpy($<ccval>$,$<ccval>1);}
            | CENTERO {$<estructura>$.ival=$<estructura>1.ival; $<estructura>$.tipo=$<estructura>1.tipo;}
            | CREAL {$<estructura>$.dval=$<estructura>1.dval; $<estructura>$.tipo=$<estructura>1.tipo;}
            | LCADENA 
            | '(' expresion ')'
;













/* GRAMATICA DE DECLARACIONES */

declaracion: '\n' 
        | declaracionDeVariables 
        |declaracionDeFunciones 
        |definicionDeFuncion 
        
;

declaracionDeVariables: T_DATO declaracionDeVariablesPuntero {
                                        strcat($<ccval>1,$<ccval>2);
                                        int linea = yylineno;
                                        listaVariables = pasarVariablesDeAux(listaVariables,listaVariablesAux, $<ccval>1,linea);
                                        listaVariablesAux = destroyListaVar(listaVariablesAux);
        }
;

declaracionDeVariablesPuntero: listaVariablesSimples ';' {strcpy($<ccval>$, "");}
        | '*' listaVariablesSimples ';' {strcpy($<ccval>$, "*");}
        |  ID listaArreglos ';'  {
                                        strcpy($<ccval>$, " arreglo");
                                        char *cadena = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(cadena,$<ccval>1);
                                        listaVariablesAux = agregarVariable(listaVariablesAux,cadena," ");
        
        }
;
listaArreglos: arreglo 
                | listaArreglos arreglo
;

arreglo: '[' expresion ']'
;

listaVariablesSimples: variableSimple
                        |listaVariablesSimples ',' variableSimple  
;

variableSimple: ID inicializador                           {
                                        char *cadena = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(cadena,$<ccval>1);
                                        listaVariablesAux = agregarVariable(listaVariablesAux,cadena,"not yet");
                                        strcpy($<ccval>$, $<ccval>1);
        }
;

inicializador: /* vacio */
              |OPASIG   expresionCondicional
;


declaracionDeFunciones: T_DATO  ID '(' opcionArgumentos ')' ';'   {
                                        char *id = (char *)malloc((strlen($<ccval>2) + 1) * sizeof(char *));
                                        strcpy(id,$<ccval>2);
                                        char *tipo = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(tipo,$<ccval>1);
                                        int cantidad = contarParametros(listaParametrosAux);
                                        int linea = yylineno;
                                        listaFunciones = validarFuncionYAgregarla(listaFunciones,listaParametrosAux, id,tipo,cantidad,linea);
                                        listaParametrosAux = NULL;
                                        }
        
                        |T_DATO '*' ID '(' opcionArgumentos ')' ';' {
                                        char *id = (char *)malloc((strlen($<ccval>3) + 1) * sizeof(char *));
                                        strcpy(id,$<ccval>3);
                                        strcat($<ccval>1,"*");
                                        char *tipo = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(tipo,$<ccval>1);
                                        int cantidad = contarParametros(listaParametrosAux);
                                        int linea = yylineno;
                                        listaFunciones = validarFuncionYAgregarla(listaFunciones,listaParametrosAux, id,tipo,cantidad,linea);
                                        listaParametrosAux = NULL;
        }
;

opcionArgumentos: /*vacio*/
                | argumentoSimple
                | argumentoSimple ',' opcionArgumentos

;

argumentoSimple: T_DATO referencia ID {
                                        char *id = (char *)malloc((strlen($<ccval>3) + 1) * sizeof(char *));
                                        strcpy(id,$<ccval>3);
                                        char *tipo = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(tipo,$<ccval>1);
                                        listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);
        
}
                |T_DATO '*' referencia ID {
                                        char *id = (char *)malloc((strlen($<ccval>4) + 1) * sizeof(char *));
                                        strcpy(id,$<ccval>4);
                                        strcat($<ccval>1,"*");
                                        char *tipo = (char *)malloc((strlen($<ccval>1) + 1) * sizeof(char *));
                                        strcpy(tipo,$<ccval>1);
                                        listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);

}
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


yyin = fopen("Entrada.c","r");
yyout= fopen("Salida.txt", "w");
yyparse();
mostrarListaErroresLexicos(listaErroresLexicos);
printf("\n\n\n");
mostrarListaErroresSemanticos(listaErroresSemanticos);
printf("\n\n\n");
mostrarListaErroresSintacticos(listaErroresSintacticos);
printf("\n\n\n");
mostrarListaVariables(listaVariables);
mostrarListaFunciones(listaFunciones);




}