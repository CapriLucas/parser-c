#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


struct NodoVariables
{
  char *nombreVar;
  char *tipoVar;
  struct NodoVariables *sig;
};

struct NodoFunciones
{
     char *nombreFun;
     char *parametroSalida;
     struct NodoVariables *parametrosEntrada;
     int cantParametros;
     struct NodoFunciones *sig;
};

struct NodoErrorLexico{
char *cadenaError;
int linea;
struct NodoErrorLexico *sig;
};

struct NodoErrorSemantico{
  char *cadenaError;
  int linea;
  struct NodoErrorSemantico *sig;
};
struct NodoErrorSintactico{
  int linea;
  struct NodoErrorSintactico *sig;
};


struct NodoVariables *variableAux = NULL;
struct NodoVariables *listaVariablesAux = NULL;
struct NodoVariables *listaParametrosAux = NULL;
struct NodoVariables *listaVariables = NULL;
struct NodoFunciones *listaFunciones = NULL;
struct NodoFunciones *funcionAux = NULL;
struct NodoErrorLexico *listaErroresLexicos = NULL;
struct NodoErrorSintactico *listaErroresSintacticos =NULL;
struct NodoErrorSemantico *listaErroresSemanticos =NULL;



struct NodoErrorSemantico *agregarErrorDobleDeclaracion(struct NodoErrorSemantico*puntero, char *cadNoReconocida,int linea);
void mostrarListaVariables(struct NodoVariables* puntero);
struct NodoVariables *validarVariableYAgregarla(struct NodoVariables *puntero, char *nombre,char *tipo,int linea);

struct NodoVariables *pasarVariablesDeAux(struct NodoVariables*lista,struct NodoVariables *auxiliar, char *tipo,int linea){
    struct NodoVariables *aux = auxiliar;
    while (aux != NULL)
     {
          lista = validarVariableYAgregarla(lista, aux->nombreVar,tipo,linea);
          aux = aux->sig;
     }
    return lista;

}

//Libera la lista de variables
struct NodoVariables *destroyListaVar(struct NodoVariables *lista)
{
  struct NodoVariables *aux = lista;
  struct NodoVariables *next;

    while (aux != NULL)
    {
       next = aux->sig;
       free(aux);
       aux = next;
    }
    lista = NULL;
    return lista;
}

//Agrega una variable a la TS
struct NodoVariables *agregarVariable(struct NodoVariables*puntero, char *nombre, char *tipo){
  struct NodoVariables*nuevaLista;
  nuevaLista= (struct NodoVariables*)malloc(sizeof(struct NodoVariables));
  nuevaLista->nombreVar = nombre;
  nuevaLista->tipoVar= tipo;
  nuevaLista->sig=NULL;
     if (puntero != NULL)
     {
          struct NodoVariables *aux = puntero;
          while (aux->sig != NULL)
          {
               aux = aux->sig;
          }
          aux->sig = nuevaLista;
     }
     else
     {
          puntero = nuevaLista;
     }
     return puntero;
}

//Busca una variable determinada
struct NodoVariables *buscarVariable(struct NodoVariables *puntero, char *nombre)
{
     struct NodoVariables *aux = puntero;
     while (aux != NULL && strcmp(aux->nombreVar, nombre) != 0)
     {
          aux = aux->sig;
     }
     return aux;
}

//Valida que la variable encontrada no tenga errores semanticos y la agrega a la TS
struct NodoVariables *validarVariableYAgregarla(struct NodoVariables *puntero, char *nombre,char *tipo,int linea)
{
     char *cadena = (char *)malloc((strlen(nombre) + 1) * sizeof(char *));
     char *tipoVar = (char *)malloc((strlen(tipo) + 1) * sizeof(char *));
     strcpy(cadena, nombre);
     strcpy(tipoVar,tipo);
     struct NodoVariables *cadenaABuscar = buscarVariable(puntero, cadena);
     if (cadenaABuscar == NULL)
     {
          puntero = agregarVariable(puntero, cadena,tipoVar);
     }
     else
     {
          listaErroresSemanticos = agregarErrorDobleDeclaracion(listaErroresSemanticos,"'doble declaracion de variable'",linea); //revisar 
     }
     return puntero;
}




//Agrega errores lexicos encontrados
struct NodoErrorLexico *agregarErrorLexico(struct NodoErrorLexico*puntero, char *cadNoReconocida,int linea){
  struct NodoErrorLexico *nuevaLista;
  nuevaLista= (struct NodoErrorLexico*)malloc(sizeof(struct NodoErrorLexico));
  nuevaLista->cadenaError = cadNoReconocida;
  nuevaLista->linea = linea;
    nuevaLista->sig=NULL;
     if (puntero != NULL)
     {
          struct NodoErrorLexico *aux = puntero;
          while (aux->sig != NULL)
          {
               aux = aux->sig;
          }
          aux->sig = nuevaLista;
     }
     else
     {
          puntero = nuevaLista;
     }
     return puntero;
}

//Agrega errores sintacticos encontrados
struct NodoErrorSintactico* agregarErrorSintactico(struct NodoErrorSintactico*puntero ,int linea){
  struct NodoErrorSintactico *nuevaLista;
  nuevaLista= (struct NodoErrorSintactico*)malloc(sizeof(struct NodoErrorSintactico));

  nuevaLista->linea = linea;
    nuevaLista->sig=NULL;
     if (puntero != NULL)
     {
          struct NodoErrorSintactico *aux = puntero;
          while (aux->sig != NULL)
          {
               aux = aux->sig;
          }
          aux->sig = nuevaLista;
     }
     else
     {
          puntero = nuevaLista;
     }
     return puntero;
}

//Agrega errores semanticos encontrados
struct NodoErrorSemantico *agregarErrorDobleDeclaracion(struct NodoErrorSemantico*puntero, char *cadNoReconocida,int linea){
  struct NodoErrorSemantico *nuevaLista;
  nuevaLista= (struct NodoErrorSemantico*)malloc(sizeof(struct NodoErrorSemantico));
  nuevaLista->cadenaError=cadNoReconocida;
  nuevaLista->linea = linea;
  nuevaLista->sig=NULL;
     if (puntero != NULL)
     {
          struct NodoErrorSemantico *aux = puntero;
          while (aux->sig != NULL)
          {
               aux = aux->sig;
          }
          aux->sig = nuevaLista;
     }
     else
     {
          puntero = nuevaLista;
     }
     return puntero;
}


//Agrega una funcion a la TS
struct NodoFunciones *agregarFuncion(struct NodoFunciones*puntero, char *nombre, struct NodoVariables* parametrosEntrada, char* parametroSal, int cantParam){
  struct NodoFunciones*nuevaLista;
  nuevaLista= (struct NodoFunciones*)malloc(sizeof(struct NodoFunciones));
  nuevaLista->nombreFun = nombre;
  nuevaLista->parametroSalida= parametroSal;
  nuevaLista->cantParametros = cantParam;
  nuevaLista->parametrosEntrada = parametrosEntrada;
  nuevaLista->sig=NULL;
     if (puntero != NULL)
     {
          struct NodoFunciones *aux = puntero;
          while (aux->sig != NULL)
          {
               aux = aux->sig;
          }
          aux->sig = nuevaLista;
     }
     else
     {
          puntero = nuevaLista;
     }
     return puntero;
}

//Busca una funcion determinada
struct NodoFunciones *buscarFuncion(struct NodoFunciones *puntero, char *nombre)
{
     struct NodoFunciones *aux = puntero;
     while (aux != NULL && strcmp(aux->nombreFun, nombre) != 0)
     {
          aux = aux->sig;
     }
     return aux;
}

//Valida que la funcion no tenga error semantico y la agrega a la TS
struct NodoFunciones *validarFuncionYAgregarla(struct NodoFunciones *puntero,struct NodoVariables *listaParam, char *nombre,char *tipo,int cantidad,int linea)
{
     char *cadena = (char *)malloc((strlen(nombre) + 1) * sizeof(char *));
     char *tipoVar = (char *)malloc((strlen(tipo) + 1) * sizeof(char *));
     strcpy(cadena, nombre);
     strcpy(tipoVar,tipo);
     struct NodoFunciones *cadenaABuscar = buscarFuncion(puntero, cadena);
     if (cadenaABuscar == NULL)
     {
          puntero = agregarFuncion(puntero,cadena,listaParam,tipoVar,cantidad);
     }
     else
     {
          listaErroresSemanticos = agregarErrorDobleDeclaracion(listaErroresSemanticos,"'doble declaracion de funcion'",linea); 
     }
     return puntero;
}



//Muestra la lista de funciones encontradas
void mostrarListaFunciones(struct NodoFunciones*puntero)
{
     struct NodoFunciones *auxFun = puntero;
     struct NodoVariables *auxParam;
     while (auxFun != NULL)
     {
          printf("\n\nEn la TS se encontro la funcion: '%s', de tipo: %s\n", auxFun->nombreFun, auxFun->parametroSalida);
          auxParam = auxFun->parametrosEntrada;
          printf("\n\tRecibe %d parametros:\n", auxFun->cantParametros);
          while (auxParam != NULL)
          {
          printf("\tParametro: '%s' de tipo %s\n", auxParam->nombreVar, auxParam->tipoVar);
          auxParam = auxParam->sig;
          }
          auxParam = NULL;
          auxFun = auxFun->sig;
     }
}



//Muestra la lista de variables encontradas
void mostrarListaVariables(struct NodoVariables *puntero)
{
     struct NodoVariables *aux = puntero;
     while (aux != NULL)
     {
          printf("En la TS se encontro la variable %s de tipo %s\n", aux->nombreVar, aux->tipoVar);
          aux = aux->sig;
     }
}


//Muestra la lista de errores lexicos encontrados
void mostrarListaErroresLexicos(struct NodoErrorLexico *puntero)
{
     struct NodoErrorLexico *aux = puntero;
     while (aux != NULL)
     {
          printf("Se encontro el error lexico %s en la linea %d \n", aux->cadenaError,aux->linea);
          aux = aux->sig;
     }
}


//Muestra la lista de errores semanticos encontrados
void mostrarListaErroresSemanticos(struct NodoErrorSemantico *puntero)
{
     struct NodoErrorSemantico *aux = puntero;
     while (aux != NULL)
     {
          printf("Se encontro el error semantico %s en la linea %d \n", aux->cadenaError,aux->linea);
          aux = aux->sig;
     }
}

//Muestra la lista de errores sintacticos
void mostrarListaErroresSintacticos(struct NodoErrorSintactico *puntero)
{
     struct NodoErrorSintactico *aux = puntero;
     while (aux != NULL)
     {
          printf("Se encontro el error Sintactico en la linea %d. Imposible emparejar por alguna produccion.\n",aux->linea);
          aux = aux->sig;
     }
}

//Cuenta la cantidad de parametros de las funciones
int contarParametros(struct NodoVariables* funciones ){
       struct NodoVariables *aux = funciones;
       int cont = 0;
     while (aux != NULL)
     {
          aux = aux->sig;
          cont++;
     }
     return cont;
}


//Comprueba parametros de la funcion
int comprobarInvocacionFuncion(struct NodoFunciones *listaFunc,struct NodoVariables *listaParam,char *idFunc,int linea){
     funcionAux = buscarFuncion(listaFunciones, idFunc);
     if(listaFunc->cantParametros == contarParametros(listaParam)){
          struct NodoVariables *aux = funcionAux->parametrosEntrada;
          struct NodoVariables *aux2 = listaParam;
          while(aux!= NULL){
               if(strcmp(aux->tipoVar,aux2->tipoVar) != 0){
                    listaErroresSemanticos = agregarErrorDobleDeclaracion(listaErroresSemanticos,"'error en paso de parametros a invocacion'",linea);
                    funcionAux = NULL;
                    return 0;
               }
               aux = aux->sig;
               aux2 = aux2->sig;
          }
          funcionAux = NULL;

     }

}
