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


%}

%union {
char* ccval; // cadenas
double dval; // numeros reales/racionales
int ival; // numeros enteros
}
%token <ival> CENTERO 
%token <dval> CREAL
%token <ccval> ID LCADENA OPASIG OR AND OPIGUAL OPCORR OPREL OPINCDEC TDATO FLECHA LCADENA
%token <ccval> IF ELSE SIOF SWITCH WHILE DO FOR RETURN CONTINUE GOTO BREAK CASE DEFAULT

%% /*  reglas gramaticales y las acciones */
 
input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n' 
;

/* GRAMATICA DE DECLARACIONES */

decl:		
;
listDecl:   /* vacio */
         	|decl
            |listDecl decl
;
/* GRAMATICA DE DEFINICIONES */


/* GRAMATICA DE SENTENCIAS */
sent:		sentExp | sentComp | sentSelecc | sentIterac | sentSalto | sentEtiq
;
sentComp:	'{' listDecl listsent '}'
;

listsent:   /* vacio */
            |sent
            | listsent sent
;

sentExp:		expOp ';'
;
sentSelecc:	IF '(' exp ')' sent elseSent
            | SWITCH '(' exp ')' sent
;
elseSent: 	/* vacio */
				| ELSE sent
;
sentIterac:	WHILE '(' exp ')' sent
            | DO sent WHILE '(' exp ')'
            | FOR '('expOp ';' expOp ';' expOp ')' sent
;
sentSalto:  RETURN expOp ';'
            | CONTINUE ';'
            | BREAK ';'
            | GOTO ID ';'
;
sentEtiq:   CASE exp ':' sent
            | DEFAULT ':' sent
            | ID ':' sent
;

/* GRAMATICA DE EXPRESIONES */
exp:    expAsig
        | exp ',' expAsig
;
expOp: /* vacio */
        | exp
;  
expAsig:    expCond
            | expUna operAsig expAsig
;
operAsig:   OPASIG
;
expCond:    expOr
            | expOr '?' exp ':' expCond
;
expOr:  expAnd
        | expOr OR expAnd 
;
expAnd: expIgual
        | expAnd AND expIgual
;
expIgual:   expRel
            | expIgual OPIGUAL expRel
;
expRel: expCorr
        | expRel opRela expCorr
;
opRela: '<' | '>' | OPREL
;
expCorr: expAdi
        | expCorr OPCORR expAdi
;

expAdi: expMul
        | expAdi '+' expMul
        | expAdi '-' expMul
;
expMul: expUna
        | expMul '*' expConv
        | expMul '/' expConv
        | expMul '%' expConv
;
expConv: expUna
         | TDATO expConv
;
expUna: expPFijo
        | OPINCDEC expUna
        | opUna expConv
        | SIOF expUna
        | SIOF '(' TDATO ')'
;
opUna: '&' | '*' | '+' | '-'| '~'| '!'
;
expPFijo:   expPri
            | expPFijo '[' exp ']'
            | expPFijo '(' listaArg ')'
            | expPFijo '.' ID
            | expPFijo FLECHA ID
            | expPFijo OPINCDEC
;
listaArg:   expAsig
            | listaArg ',' expAsig
;
expPri:     ID | CENTERO | CREAL | LCADENA | '(' exp ')'
;

     


%%


//Si el analizador no empareja con ninguna produccion se muestra un msj de error con su linea 

void yyerror (char *mensaje)  
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

  yyin = fopen("Entrada.txt","r");
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