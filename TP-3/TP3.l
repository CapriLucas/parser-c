%option noyywrap
%{

#include<stdio.h> 
#include<math.h> 
#include<stdlib.h>
#include<string.h>
#include        "funcionesTP3.h"
int nlinea = 1;


%}

DIRECTIVA            "#"[ ]*"include"[ ]*(\".*".h"\"|"<".*".h>")|"#"[ ]*"define"[ ]+{ID}[ ]*("("[ ]*({ID}[ ]*","[ ]*)*{ID}[ ]*")")?[ ]+([^#\n]+)?

CEDECIMAL 	         [1-9][0-9]* 
CEOCTAL		         0[0-7]*
CEHEXA		         0[xX][A-Fa-f0-9]+
CREAL	             [0-9]*"."[0-9]+([eE]([\+\-]?)[0-9]+)?[FfLl]?|[0-9]+"."([eE][\+\-]?[0-9]+)?[FfLl]?|[0-9]+([eE][\+\-]?[0-9]+)[FfLl]?
CARACTER             '.'|'\\0'|'\\n'
CONSTANTES          {CEDECIMAL}|{CEOCTAL}|{CEHEXA}|{CREAL}

PR_DATO	             int|char|float|bool|double|long|short|unsigned|signed|typedef|const|enum|struct
PR_CONDICIONAL       if|else|switch|case|break|return|default
PR_ITERATIVA         while|for|do 
PR_OTRO              auto|continue|extern|goto|register|static|union|void|volatile
PR                   {PR_DATO}|{PR_CONDICIONAL}|{PR_ITERATIVA}|{PR_OTRO}

LITCAD               \"(\\.|[^\\"])*\"
ID       	         [a-zA-Z_][a-zA-Z0-9_]*
COP                  "++"|"*"|"+"|"&"|"!"|"sizeof"|"/"|"-"|"--"|"<"|">"|"<="|">="|"=="|"!="|"="|"&&"|"?:"|"+="|"~"|"%"|"<<"|">>"|"|"|"^"|"||"
CPU                  "("|")"|"{"|"}"|";"|","|":"|"..."|"["|"]"  
COM_MULT             \/\*(\*+[^\*\/]|[^\*])*\*+\/
COM_SIMP             \/\/.*
%%

{DIRECTIVA}         {dir = verificarCadena2(dir,yytext,nlinea);}

{PR}                {pr = verificarCadena3(pr,yytext);}

{CEDECIMAL}         {cdec = verificarCadena(cdec,yytext);}

{CEOCTAL}           {int oct=(int)strtol(yytext, NULL, 0); coct = verificarCadena2(coct,yytext,oct);}

{CEHEXA}            {int hex=(int)strtol(yytext, NULL, 0); chex = verificarCadena2(chex,yytext,hex);} 

{CREAL}             {cre = verificarCadena4(cre,yytext);}

{CARACTER}          {ccar = verificarCadena3(ccar,yytext);}

{LITCAD}            {char * cad=devolverCadenaSinComillas(yytext); lt =verificarCadena2(lt,cad,strlen(cad));}

{COP}               {cop = verificarCadena(cop,yytext);}

{CPU}               {cpu = verificarCadena(cpu,yytext);}

{ID}                {id =verificarCadena5(id,yytext);}

{COM_MULT}          {comml = verificarCadena3(comml,yytext);} 

{COM_SIMP}          {coml = verificarCadena3(coml,yytext);} 

\n                  {nlinea +=1;}    
[\t ]+              {;}

(.)                 {ccarno = verificarCadena2(ccarno,yytext,nlinea);}

{CONSTANTES}{ID}+   {ccarno = verificarCadena2(ccarno,yytext,nlinea);}

%%

int main(){
    
    yyin = fopen("entrada.c","r");
    yyout = fopen("salida.txt","w");
    yylex();
    imprimirOpcionesReporte();
    return 0;
}
