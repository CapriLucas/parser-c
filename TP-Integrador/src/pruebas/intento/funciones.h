
/* flex TpIntegrador.l, bison TpIntegrador.y -d, gcc TpIntegrador.tab.c lex.yy.c -L “C:\MinGW\lib” -lfl -ly */

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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

struct TablaSimbolos *TS = NULL;

void putVariable(char *nombreVar, char *tipoVar)
{
  struct NodoVar *nuevoNodo = (struct NodoVar *)malloc((strlen(nombreVar) + strlen(tipoVar) + 2) * sizeof(struct NodoVar));
  nuevoNodo->nombreVar = nombreVar;
  nuevoNodo->tipoVar = tipoVar;
  nuevoNodo->sig = NULL;
  if (TS->listaVar != NULL)
  {
    struct NodoVar *aux = TS->listaVar;
    while (aux->sig != NULL)
    {

      aux = aux->sig;
    }
    aux->sig = nuevoNodo;
  }
  else
  {
    TS->listaVar = nuevoNodo;
  }
}

void reloadTipos(char *tipoVar)
{
  if (TS->listaVar != NULL)
  {
    struct NodoVar *aux = TS->listaVar;
    while (aux->sig != NULL)
    {
      if (aux->tipoVar == NULL)
      {
        aux->tipoVar = tipoVar;
      }
      aux = aux->sig;
    }
  }
}
void putFuncion(struct NodoFunc *funcion)
{
  if (TS->listaFunc != NULL)
  {
    struct NodoFunc *aux = TS->listaFunc;
    while (aux->sig != NULL)
    {

      aux = aux->sig;
    }
    aux->sig = funcion;
  }
  else
  {
    TS->listaFunc = funcion;
  }
}

struct NodoVar *getVariable(char *nombre)
{
  struct NodoVar *aux = TS->listaVar;
  while (aux != NULL && strcmp(aux->nombreVar, nombre) != 0)
  {
    aux = aux->sig;
  }
  return aux;
}
struct NodoFunc *getFuncion(char *nombre)
{
  struct NodoFunc *aux = TS->listaFunc;
  while (aux != NULL && strcmp(aux->nombreFun, nombre) != 0)
  {
    aux = aux->sig;
  }
  return aux;
}

void printListVar()
{
  if (TS->listaVar != NULL)
  {
    struct NodoVar *aux = TS->listaVar;
    while (aux->sig != NULL)
    {
      printf("\nID: %s\nTIPO: %s", aux->nombreVar, aux->tipoVar);
      aux = aux->sig;
    }
  }
  else
  {
    printf("LISTA VACIA");
  }
}