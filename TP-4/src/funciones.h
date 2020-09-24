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

struct NodoDecl
{
  char *tipo;
  char *id;
  NodoDecl *parametros; // Puntero al primer nodo de una lista con los parametros de las funciones
  NodoDecl *sig;
};

struct NodoDecl *listaVar = NULL;
struct NodoFunc *listaFunc = NULL;

// Funcion para retornar el puntero a la lista que se va a almacenar en "*listaVar"  (el parametro *punt es el mismo puntero a la lista)
struct NodoDecl *agregarAListaVar(struct NodoDecl *punt, char *id, char *tipo)
{
  struct NodoDecl *nuevo = (struct NodoDecl *)malloc((strlen(tipo) + strlen(id) + 2) * sizeof(struct NodoDecl));
  nuevo->id = id;
  nuevo->tipo = tipo;
  nuevo->parametros = NULL;
  nuevo->sig = NULL;
  struct NodoDecl *ant = NULL;
  struct NodoDecl *aux = punt;
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
// Todavia no la defino, primero habria que hacer la gramatica de las declaraciones y definiciones
// Idea de la funcion: Agregar un nodo a una lista de todas las funciones declaradas en el input
// y en parametros se abre una sublista con la cantidad de parametros que posea la funcion en el archivo c
struct NodoDecl *agregarAListaFunc(struct NodoDecl *punt, char *id, char *tipo)
{
}
// Esta funcion verifica que no sea haya declarado dos veces ni una variable ni una funcion
// Devuelve 1 si se encuentra ya declarada
// devuelve 0 caso contrario
int busquedaDecl(struct NodoDecl *punt, char *idABuscar)
{
  struct NodoDecl *aux = punt;
  while (aux != NULL && aux->id != idABuscar)
  {
    aux = aux->sig;
  }
  if (aux == NULL)
    return 0;
  else
    return 1;
}
