%option noyywrap
%{
#include<stdio.h> 
#include<math.h> 
#include<stdlib.h>
#include<string.h>
#include "Ejemplo_Calculadora_Notacion_Polaca_Inversa.tab.h"

%}


%%

[0-9]+  {yylval = atoi(yytext); return NUM;}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"^"     {return '^';}
"\n"    {return '\n';}

%%

