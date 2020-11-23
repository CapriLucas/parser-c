/* GRAMATICA DE EXPRESIONES    LISTO*/
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



/* GRAMATICA DE DECLARACIONES  listo*/

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

%%