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
%token <ccval> ID LCADENA OPASIG OR AND OPIGUAL OPCORR OPREL OPINCDEC TDATO TCLASE FLECHA LCADENA
%token <ccval> STRUNION CALTIPO ENUM
%token <ccval> IF ELSE SIOF SWITCH WHILE DO FOR RETURN CONTINUE GOTO BREAK CASE DEFAULT

%% /*  reglas gramaticales y las acciones */
 
input:  /* vacio */
        | input line
;

line:   '\n'
        | exp '\n' 
;

/* GRAMATICA DE DECLARACIONES */

declaracion:	espDec	listDeclaradoresOp
;
espDec: espClase espDecOP
        | espTipo espDecOP
        | calTIpo espDecOP
        nomTyp
;
espDecOP:   /* vacio*/
                | espDec
;
listDeclaradoresOp: /* vacio*/
                | listDeclaradores
;
listDeclaradores:       declarador
                | listDeclaradores ',' declarador
;
declarador:     decla
                | decla '=' inicializador
;
inicializador:  expAsig
                | '{' listInic '}'
                | '{' listInic ',' '}'
;
listInic:       inicializador
                | listInic ',' inicializador
;

espClase:       TCLASE 
;
espTipo:        TDATO espStrunion espEnum
;
calTipo:        CALTIPO
;
espStrunion:    STRUNION idOp '{' listStruct '}'
                | STRUNION ID
;
idOp: /* vacio*/
        | ID
;
listStruct:     declStruct
                | listStruct declStruct
;
declStruct:     listCal declaradoresStruct ';'
;
listCal:        espTipo listCalOp
                | calTipo listCalOp
;
listCalOp: /*vacio*/
                | listCal
;
declaradoresStruct:     declaStruct
                        | declaradoresStruct ',' declaStruct
;
declaStruct:    decla
                | declaOp ';' expCond
;
decla: puntOp declaDir
;
punt: '*' listaCalTipOp
        | '*' listaCalTipOp punt
;
declaOp: /*vacio*/
        | decla
;
puntOp: /*vacio*/
        | punt
;
listaCalTip:    calTipo
                | listaCalTip calTipo
;
listaCalTipOp:  /*vacio*/
                | listaCalTip
;
declaDir: ID
        | '(' decla ')'
        | declaDir '[' expCondOp ']'
        | declaDir '(' listTipoParam ')'
;
expCondOp: /*vacio*/
                | expCond
;
listTipoParam:  listParam
                | listParam ',' '.' '.' '.'
;
listParam:      declParam
                | listParam ',' declParam
;
declParam:      espDec decla
                | espDec declAbsOp
;
espEnum:        ENUM idOp '{' listEnum '}'
                | ENUM ID
;
listEnum:       enumerador
                | listEnum ',' enumerador
;
enumerador:     constEnum
                | constEnum '=' expCond
;
constEnum:      ID
;
nomTyp: ID
;
nomTipo:        listCal declAbsOp
;
declAbs:        punt
                | puntOp declAbsDir
;
declAbsOp: /*vacio*/
                | declAbs
;
declAbsDir:     '(' declAbs ')'
                | declAbsDirOp '[' expCondOp ']'
                | declAbsDirOp '(' listTipoParamOp ')'
;
declAbsDirOp:   /*vacio*/
                | declAbsDir
;
listTipoParamOp: /*vacio*/
                | listTipoParam
;

/* GRAMATICA DE DEFINICIONES EXTERNAS*/

unidadTrad:     declExt
                | unidadTrad declExt
;
declExt:        defFun
                | declaracion
;
defFun:         espDecOP decla listDeclaracionesOp sentComp
;

/* GRAMATICA DE SENTENCIAS */

sent:		sentExp | sentComp | sentSelecc | sentIterac | sentSalto | sentEtiq
;
sentComp:	'{' listDeclaracionesOp listsentOp '}'
;

listsent:    sent
            | listsent sent
;
listsentOp: /*vacio*/
        | listsent
;
listDeclaraciones:      declaracion
                        | listDeclaraciones declaracion
;
listDeclaracionesOp: /*vacio*/
                        | listDeclaraciones
;
sentExp:        expOp ';'
;
sentSelecc:	IF '(' exp ')' sent elseSent
            | SWITCH '(' exp ')' sent
;
elseSent: 	/* vacio */
				| ELSE sent
;
sentIterac:	WHILE '(' exp ')' sent
            | DO sent WHILE '(' exp ')' ';'
            | FOR '('expOp ';' expOp ';' expOp ')' sent
;
sentSalto:  RETURN expOp ';'
            | CONTINUE ';'
            | BREAK ';'
            | GOTO ID ';'
;
sentEtiq:   CASE expCond ':' sent
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
        | SIOF '(' nomTipo ')'
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