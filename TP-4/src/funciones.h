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
#include <ctype.h>

struct NodoDecl
{

  char *tipo;
  char *id;
  NodoDecl *parametros; // Puntero al primer nodo de una lista con los parametros de las funciones
  NodoDecl *sig;
};

struct NodoDecl *listaVar = NULL;
struct NodoFunc *listaFunc = NULL;
// Funcion para retornar el puntero a la lista que se va a almacenar en la lista de variables o la de funciones
// el parametro *punt es el mismo puntero a la lista
struct NodoDecl *agregarAListaDecl(struct NodoDecl *punt, char *id, char *tipo)
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
// Funcion para agregar un parametro a un nodo de una Funcion, la lista de parametros es una sub-lista de la de funciones
// Para cada parametro de una funcion registrada, se corre esta funcion agregando el param a la sublista
// En caso de no encontrar el id de dicha funcion ... (COMPLETAR). Por ultimo retorna el puntero a la lista de funciones
struct NodoDecl *agregarParamAFunc(struct NodoDecl *puntListFunc, char *idFunc, char *tipoParam, char *idParam)
{
  struct NodoDecl *aux = puntListFunc;
  while (aux != NULL && aux->id != idFunc)
  {
    aux = aux->sig;
  }
  if (aux == NULL)
  {
    // EN ESTE CASO NO SE PUEDE AGREGAR NINGUN PARAMETRO YA QUE LA FUNCION BUSCADA NO EXISTE
  }
  else
  {
    struct NodoDecl *param = aux->parametros;
    param = agregarAListaDecl(param, idParam, tipoParam);
  }
  return puntListFunc;
}

// Esta funcion verifica que no se re-declare ni una variable ni una funcion
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

void opciones()
{
  printf("\nINGRESE LA OPCION DE LO QUE DESEA HACER:\n\n");
  printf("1)  Generar listado de variables declaradas\n");
  printf("2)  Generar listado de funciones declaradas\n");
  printf("3)  Generar listado de sentencias\n");
  printf("4) Salir del reporte\n");
}

void imprimirOpcionesReporte()
{

  int opcionIngresada;
  printf("-------------------------------------------------------------------------");
  printf("\n\t\t\tOPCIONES DISPONIBLES:\n");
  printf("-------------------------------------------------------------------------\n\n");
  do
  {
    opciones();
    scanf("%d", &opcionIngresada);
    switch (opcionIngresada)
    {
    case 1:
      printf("-------------------------------------------------------------------------");
      printf("\nUSTED INGRESO LA OPCION 1: GENERAR LISTA DE VARIABLES DECLARADAS.\n");
      printf("-------------------------------------------------------------------------\n\n");
      break;

    case 2:
      printf("-------------------------------------------------------------------------");
      printf("\nUSTED INGRESO LA OPCION 2: GENERAR LISTA DE FUNCIONES DECLARADAS.\n");
      printf("-------------------------------------------------------------------------\n\n");

      break;

    case 3:
      printf("-------------------------------------------------------------------------");
      printf("\nUSTED INGRESO LA OPCION 3: GENERAR LISTA DE SENTENCIAS ENCONTRADAS.\n");
      printf("-------------------------------------------------------------------------\n\n");
      break;

      system("pause");
      system("cls");
    }
  } while (opcionIngresada != 4);
  printf("-------------------------------------------------------------------------");
  printf("\n\t\t\tREPORTE FINALIZADO\n\n");
  printf("-------------------------------------------------------------------------\n\n");
}
