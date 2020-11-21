%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}



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
%token <ccval> OPASIG OR AND OPIGUAL OPCORR OPREL OPINCDEC TDATO TCLASE FLECHA 
%token <ccval> STRUNION CALTIPO ENUM
%token <ccval> IF ELSE SIOF SWITCH WHILE DO FOR RETURN CONTINUE GOTO BREAK CASE DEFAULT


%% /*  reglas gramaticales y las acciones */
 
input:  /* vacio */
        | input line
;

line:   '\n'
        | expresion '\n' 
        | sentencia 'n'
        | declaracion 'n'
;




/* GRAMATICA DE DECLARACIONES */

declaracion:	espDec	listDeclaradoresOp
;

espDec: espClase espDecOP
        | espTipo espDecOP
        | calTipo espDecOP
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
declaStruct:    declaOp
                | declaOp ';' expCond
;

decla: puntOp declaDir
;

declaOp: /*vacio*/
        |decla
;

punt: '*' listaCalTipOp
        | '*' listaCalTipOp punt
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


/* GRAMATICA DE SENTENCIAS */

sentencia:		
        sentExp    
        | sentComp 
        | sentSelecc 
        | sentIterac 
        | sentSalto  
;

sentExp:        expOp ';'
;

sentComp:	'{' listDeclaracionesOp listsentOp '}'                      {fprintf(yyout,"Sentencia Compuesta encontrada:\n");}
;

listsentOp: /*vacio*/
        | listsent
;

listDeclaracionesOp: /*vacio*/
                        | listDeclaraciones
;

listDeclaraciones:      declaracion
                        | listDeclaraciones declaracion
;

listsent:    sentencia
            | listsent sentencia
;

sentSelecc:	IF '(' expresion ')' sentencia elseSent                    {printf("Sentencia de seleccion If encontrada.\n"); }
                | SWITCH '(' expresion ')' sentencia                       {printf("Sentencia de seleccion switch encontrada.\n"); }
;

elseSent: 	/* vacio */
				| ELSE sentencia                           {printf("Sentencia de seleccion If-Else encontrada.\n"); }
;


sentIterac:	WHILE '(' expresion ')' sentencia                          {printf("Sentencia de Iteracion while encontrada.\n"); }
                | DO sentencia WHILE '(' expresion ')' ';'                 {printf("Sentencia de Iteracion do while encontrada.\n"); }
                | FOR '('expOp ';' expOp ';' expOp ')' sentencia           {printf("Sentencia de Iteracion for encontrada.\n"); }
;


sentSalto:  RETURN expOp ';'                                               {printf("Sentencia de salto return encontrada.\n"); }
            | CONTINUE ';'                                                 {printf("Sentencia de salto continue encontrada.\n"); }
            | BREAK ';'                                                    {printf("Sentencia de salto break encontrada.\n"); }
            | GOTO ID ';'                                                  {printf("Sentencia de salto goto encontrada.\n"); }
;








/* GRAMATICA DE EXPRESIONES */
expresion:    expAsig
             | expresion ',' expAsig
;
expOp: /* vacio */
        | expresion
;  
expAsig:    expCond
            | expUna operAsig expAsig
;
operAsig:   OPASIG
;
expCond:    expOr
            | expOr '?' expresion ':' expCond
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
            | expPFijo '[' expresion ']'
            | expPFijo '(' listaArg ')'
            | expPFijo '.' ID
            | expPFijo FLECHA ID
            | expPFijo OPINCDEC
;
listaArg:   expAsig
            | listaArg ',' expAsig
;
expPri:     ID | CENTERO | CREAL | LCADENA | '(' expresion ')'
;

%%


//Si el analizador no empareja con ninguna produccion se muestra un msj de error con su linea 

int yyerror (char* mensaje)  
{  
    printf ("Error: %s\n", mensaje);
}


int main (){
yyin = fopen("Entrada.txt","r");
yyout = fopen("Salida.txt","w");
yyparse();

}


