//Funciones para el tp
// Tener en cuenta que debemos almacenar lo sig:
// .Variables declaradas con tipo de dato (valor?)
// .Funciones declaradas
// .Tipos de sentencias encontradas (sentencia expresión|sentencia compuesta|sentencia de selección|sentencia de iteración|
//        sentencia etiquetada|sentencia de salto)
// .Secuencias que no pertenezcan a ninguna cat Lexica y errores sintacticos
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct NodoVar
{
  char *tipo;
  char *id;
  NodoVar *sig;
};

struct NodoVar *listaVar = NULL;

// Funcion para retornar el puntero a la lista que se va a almacenar en "*listaVar"  (el parametro *punt es el mismo puntero a la lista)
struct NodoVar *agregarVariable(struct NodoVar *punt, char *id, char *tipo)
{
  struct NodoVar *nuevo = (struct NodoVar *)malloc((strlen(tipo) + strlen(id) + 2) * sizeof(struct NodoVar));
  nuevo->id = id;
  nuevo->tipo = tipo;
  nuevo->sig = NULL;
  struct NodoVar *ant = NULL;
  struct NodoVar *aux = punt;
  while (aux != NULL && strcasecmp(aux->id, id) <= 0)
  {
    ant = aux;
    aux = aux->sig;
  }
  if (ant == NULL)
  {
    punt = nuevo;
  }
  else
  {
    ant->sig = nuevo;
  }
  nuevo->sig = aux;
  return punt;
}
