%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}
extern int yylineno;




// usar yylineno para las lineas en ts
extern FILE* yyin;
extern FILE* yyout;

%}

%union {
char* ccval; // cadenas
double dval; // numeros reales/racionales
int ival; // numeros enteros
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
%token <ccval> OPCORR 
%token <ccval> OPREL 
%token <ccval> OPERADORINC
%token <ccval> OPERADORDEC 
%token <ccval> T_DATO 
%token <ccval> TCLASE 
%token <ccval> FLECHA 
%token <ccval> STRUNION 
%token <ccval> CALTIPO 
%token <ccval> OPDESIGUAL
%token <ccval> OPERADORUNARIO
%token  ENUM
%token  IF 
%token  ELSE 
%token  SIZEOF 
%token  SWITCH
%token  WHILE 
%token  DO 
%token  FOR 
%token  RETURN 
%token  CONTINUE 
%token  GOTO 
%token  BREAK 
%token  CASE 
%token DEFAULT
%token <ccval> DIRECTIVA
%token <ccval> CNORECONOCIDO
%token ERRORLEXICO
%type <ccval> variableSimple


%% 
 
input:  /* vacio */
        | input line
;


line:   '\n'
        | sentencia '\n' 
        | declaracion '\n'
        | defincionDeFuncion '\n' 
;


/* GRAMATICA DE EXPRESIONES */
expresion:    expresionAsignacion
             | expresion ',' expresionAsignacion
;

expresionAsignacion:    expresionCondicional
                        | expresionUnaria operadoresAsignador expresionAsignacion
;

operadoresAsignador: OPASIG
                        | '='
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
            | expresionIgualdad OPDESIGUAL expresionRelacional
;
expresionRelacional: expresionCorrimiento
        | expresionRelacional operadoresRelacionales expresionCorrimiento
;

operadoresRelacionales: '<' | '>' | OPREL
;

expresionCorrimiento: expresionAditiva
        | expresionCorrimiento OPCORR expresionAditiva
;

expresionAditiva: expresionMultiplicativa
        | expresionAditiva '+' expresionMultiplicativa
        | expresionAditiva '-' expresionMultiplicativa
;
expresionMultiplicativa: expresionUnaria
        | expresionMultiplicativa '*' expresionUnaria
        | expresionMultiplicativa '/' expresionUnaria
        | expresionMultiplicativa '%' expresionUnaria
;

;
expresionUnaria: expresionPostFijo
        | OPERADORDEC expresionUnaria
        | OPERADORINC expresionUnaria
        | SIZEOF '(' T_DATO ')'
;


expresionPostFijo:   expresionPrimaria
            | expresionPostFijo '[' expresion ']'
            | expresionPostFijo '(' listaArgumentos ')'
            | expresionPostFijo '.' ID
            | expresionPostFijo FLECHA ID
            | expresionPostFijo OPERADORINC
            | expresionPostFijo OPERADORDEC
;
listaArgumentos:  expresionAsignacion
            | listaArgumentos ',' expresionAsignacion
;
expresionPrimaria:     ID 
            | CENTERO 
            | CREAL 
            | LCADENA 
            | '(' expresion ')'
            ;








/* GRAMATICA DE DECLARACIONES */

declaracion: declaracionDeVariables
             |declaracionDeFunciones
             |defincionDeFuncion    
;

declaracionDeVariables: T_DATO listaVariablesSimples ';' {printf("\nde tipo %s", $<ccval>1);}
;

listaVariablesSimples: variableSimple                     {printf ("\nSe encontro la variable %s", $<ccval>1);}
                        |listaVariablesSimples ',' variableSimple  
;

variableSimple: ID inicializador                           {strcpy($<ccval>$, $<ccval>1);}
;

inicializador: /* vacio */
              |OPASIG   expresionCondicional
;


declaracionDeFunciones: T_DATO ID '(' opcionArgumentos ')' ';'      {printf ("\nSe encontro la funcion %s de tipo %s", $<ccval>2, $<ccval>1);}
;

opcionArgumentos: /*vacio*/
                | T_DATO referencia ID 
                | T_DATO referencia ID ',' opcionArgumentos
;

referencia: /*vacio*/
        | '&'
;

defincionDeFuncion: T_DATO ID '(' opcionArgumentos ')' sentencia {printf ("\nSe encontro la funcion %s de tipo %s ", $<ccval>2, $<ccval>1);}






/*GRAMATICA DE SENTENCIAS*/

sentencia:		
        sentenciaExpresion    
        | sentenciaCompuesta 
        | sentenciaSeleccion 
        | sentenciaIteracion 
        | sentenciaSalto  
        | sentenciaEtiqueta  
;

sentenciaExpresion: ';'
                    |expresion;

sentenciaCompuesta:	'{' listaDeclaracionesOpcional listaSentenciasOpcional '}'      {fprintf(yyout,"Sentencia Compuesta encontrada:\n");}
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





int main (){
//funciones y menu

yyin = fopen("Entrada.txt","r");
yyout = fopen("Salida.txt","w");

    #ifdef BISON_DEBUG
        yydebug = 1;
#endif
yyparse();


}


