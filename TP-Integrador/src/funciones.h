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
struct NodoErrorLexico *sig;
};

struct NodoErrorSemantico{
  char *cadenaError;
  struct NodoErrorSemantico *sig;
};

struct NodoVariables *listaVariablesAux = NULL;
struct NodoVariables *listaParametrosAux = NULL;
struct NodoVariables *listaVariables = NULL;
struct NodoFunciones *listaFunciones = NULL;
struct NodoErrorLexico *listaErroresLexicos = NULL;
struct NodoErrorSintactico *listaErroresSintacticos =NULL;
struct NodoErrorSemantico *listaErroresSemanticos =NULL;




void mostrarListaVariables(struct NodoVariables *puntero);
// VARIABLES
struct NodoVariables *validarVariableYAgregarla(struct NodoVariables *puntero, struct NodoErrorSemantico *punteroSemantico, char *nombre,char *tipo);
struct NodoVariables *pasarVariablesDeAux(struct NodoVariables*lista,struct NodoErrorSemantico *punteroSemantico,struct NodoVariables *auxiliar, char *tipo){
    struct NodoVariables *aux = auxiliar;
    while (aux != NULL)
     {
          lista = validarVariableYAgregarla(lista, punteroSemantico, aux->nombreVar,tipo);
          aux = aux->sig;
     }
    return lista;

}

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


struct NodoVariables *buscarVariable(struct NodoVariables *puntero, char *nombre)
{
     struct NodoVariables *aux = puntero;
     while (aux != NULL && strcmp(aux->nombreVar, nombre) != 0)
     {
          aux = aux->sig;
     }
     return aux;
}


struct NodoVariables *validarVariableYAgregarla(struct NodoVariables *puntero, struct NodoErrorSemantico *punteroSemantico, char *nombre,char *tipo)
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
          printf("Error semantico. Variable %s declarada previamente.", cadena);
          //agregarErrorDobleDeclaracion(punteroSemantico,cadenaABuscar); //revisar 
     }
     return puntero;
}




//esto habria que implemetarlas en la ultima regla del .l (dice *Error léxicos encontrados (si los hay) - (Implementar en Flex, archivo.L)* en el tp)
struct NodoErrorLexico *agregarErrorLexico(struct NodoErrorLexico*puntero, char *cadNoReconocida){
  struct NodoErrorLexico *nuevaLista;
  nuevaLista= (struct NodoErrorLexico*)malloc(sizeof(struct NodoErrorLexico));
  nuevaLista->cadenaError = cadNoReconocida;
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


struct NodoErrorSemantico *agregarErrorDobleDeclaracion(struct NodoErrorSemantico*puntero, char *cadNoReconocida){
  struct NodoErrorSemantico *nuevaLista;
  nuevaLista= (struct NodoErrorSemantico*)malloc(sizeof(struct NodoErrorSemantico));
  nuevaLista->cadenaError = cadNoReconocida;
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


struct NodoFunciones *agregarFuncion(struct NodoFunciones*puntero, char *nombre, struct NodoVariables* parametrosEntrada, char* parametroSal, int cantParam){
  struct NodoFunciones*nuevaLista;
//   struct NodoVariables*listaArgumentos;
//   listaArgumentos= (struct NodoVariables*)malloc(sizeof(struct NodoVariables));
  nuevaLista= (struct NodoFunciones*)malloc(sizeof(struct NodoFunciones));
  nuevaLista->nombreFun = nombre;
  nuevaLista->parametroSalida= parametroSal;
  nuevaLista->cantParametros = cantParam;
  nuevaLista->parametrosEntrada = parametrosEntrada;
  nuevaLista->sig=NULL;
  mostrarListaVariables(nuevaLista->parametrosEntrada);
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



//Muestra la lista de funciones encontradas
void mostrarListaFunciones(struct NodoFunciones*puntero)
{
     struct NodoFunciones *auxFun = puntero;
     struct NodoVariables *auxParam;
     while (auxFun != NULL)
     {
          printf("\n\tSe encontro la funcion:%s , de tipo:%s\n", auxFun->nombreFun, auxFun->parametroSalida);
          auxParam = auxFun->parametrosEntrada;
          while (auxParam != NULL)
          {
          printf("Recibe parametro: %s de tipo %s\n", auxParam->nombreVar, auxParam->tipoVar);
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
          printf("Se encontro el error lexico %s en la TS", aux->cadenaError);
          aux = aux->sig;
     }
}


//Muestra la lista de errores semanticos encontrados
void mostrarListaErroresSemanticos(struct NodoErrorSemantico *puntero)
{
     struct NodoErrorSemantico *aux = puntero;
     while (aux != NULL)
     {
          printf("Se encontro el error semantico %s en la TS", aux->cadenaError);
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



















//int sumar(int a , int b);
//Nodo funciones parametrosalida nombreFun  

// struct NodoParametros
// {
//   char *tipoDato;
//   char *nombre;
//   char *referenciaValor;
//   struct NodoParametros *sig;
// };






//a partir de aca esta lo de ayer:



/*
struct TablaSimbolos
{
  struct NodoVar *listaVar;
  struct NodoFunc *listaFunc;
};

struct NodoVar
{
  char *nombreVar;
  char *tipoVar;
  struct NodoVar *sig;
};
struct NodoFunc
{
  char *nombreFun;
  struct NodoParam *parametrosEntrada;
  char *parametroSalida;
  struct NodoFunc *sig;
};

struct NodoParam
{
  char *tipoDato;
  char *nombre;
  char *referenciaValor;
  int cantParametros;
  struct NodoParam *sig;
};

struct TablaSimbolos *inicializarTS()
{
  struct TablaSimbolos ts;
  ts.listaVar = NULL;
  ts.listaFunc = NULL;
  struct TablaSimbolos *punt = &ts;
  return punt;
}

//agrega una variable con su tipo
struct TablaSimbolos *putVariable(struct TablaSimbolos *punt, char *nombreVar, char *tipoVar)
{
  struct NodoVar *nuevoNodo = (struct NodoVar *)malloc((strlen(nombreVar) + strlen(tipoVar) + 1) * sizeof(struct NodoVar));
  nuevoNodo->nombreVar = nombreVar;
  nuevoNodo->tipoVar = tipoVar;
  nuevoNodo->sig = NULL;
  if (punt->listaVar != NULL)
  {
    printf("NO APAREZCAS");
    struct NodoVar *aux = punt->listaVar;
    while (aux->sig != NULL)
    {

      aux = aux->sig;
    }
    aux->sig = nuevoNodo;
  }
  else
  {
    printf("nuevo NODO como raiz");
    punt->listaVar = nuevoNodo;
  }
  return punt;
}

// // agregar funcion a la tabla de simbolos
// void putFuncion(struct NodoFunc *funcion)
// {
//   if (TS->listaFunc != NULL)
//   {
//     struct NodoFunc *aux = TS->listaFunc;
//     while (aux->sig != NULL)
//     {

//       aux = aux->sig;
//     }
//     aux->sig = funcion;
//   }
//   else
//   {
//     TS->listaFunc = funcion;
//   }
// }

// struct NodoVar *getVariable(char *nombre)
// {
//   struct NodoVar *aux = TS->listaVar;
//   while (aux != NULL && strcmp(aux->nombreVar, nombre) != 0)
//   {
//     aux = aux->sig;
//   }
//   return aux;
// }
// struct NodoFunc *getFuncion(char *nombre)
// {
//   struct NodoFunc *aux = TS->listaFunc;
//   while (aux != NULL && strcmp(aux->nombreFun, nombre) != 0)
//   {
//     aux = aux->sig;
//   }
//   return aux;
// }

void printListVar(struct TablaSimbolos *punt)
{
  int contador = 0;
  if (punt->listaVar != NULL)
  {
    struct NodoVar *aux = punt->listaVar;
    while (aux->sig != NULL && contador < 4)
    {
      printf("\nID: %s\nTIPO: %s", aux->nombreVar, aux->tipoVar);
      aux = aux->sig;
      contador++;
    }
  }
  else
  {
    printf("LISTA VACIA");
  }
}

// void reloadTipos(char *tipoVar)
// {
//   if (TS->listaVar != NULL)
//   {
//     struct NodoVar *aux = TS->listaVar;
//     while (aux->sig != NULL)
//     {
//       if (aux->tipoVar == NULL)
//       {
//         aux->tipoVar = tipoVar;
//       }
//       aux = aux->sig;
//     }
//   }
// }

*/