#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//funcion que "propias de c" que podramos usar expliquen para que sirve

//Encontre una funcion: strtol(const char *str, char **endptr, int base) , que lo que hace es convertir el valor hexa a decimal
//aunque no entiendo por que no me covierte la cadena hexa que encontro a decimal ¿??
// En si en la funcion "str" es la cadena principal
// "endptr" seria la parte de caracteres luego del ultimo caracter numerico
//lo que hace la funcion es retornar un long int que es la parte numerica de la cadena principal "str"
// EJEMPLO  hexaEnDec= (int)strtol("0X2 asdk", luegoDePrtNum, 16);
//Creas una variable hexaEnDec por asi decir y lo que retorna la funcion lo convertis en int con casteo (int)
//,y una variable luegoDePrtNum que no te sirve para nada pero no podes dejarlo vacio y base 16
// tambien podes buscar una funcion hecha en c que quizas haya en internet sino funciona con strtol

struct Nodo1
{
     int nro;
     char *cadena;
     struct Nodo1 *sig;
};
struct Nodo2
{
     char *cadena;
     struct Nodo2 *sig;
};
struct Nodo1* id=NULL;
struct Nodo1* lt=NULL;
struct Nodo2* pr=NULL;
struct Nodo1 *agregarALista(struct Nodo1 *puntero, char *cadenaNueva, int numero)
{
     struct Nodo1 *nuevo = (struct Nodo1 *)malloc(sizeof(struct Nodo1));
     nuevo->cadena = cadenaNueva;
     nuevo->nro = numero;
     nuevo->sig = NULL;
     if (puntero != NULL)
     {

          struct Nodo1 *aux = puntero;
          while (aux->sig != NULL)
          {

               aux = aux->sig;
          }
          aux->sig = nuevo;
     }
     else
     {
          puntero = nuevo;
     }
     return puntero;
}
struct Nodo2 *agregarALista2(struct Nodo2 *puntero, char *cadenaNueva)
{
     struct Nodo2 *nuevo = (struct Nodo2 *)malloc(sizeof(struct Nodo2));
     nuevo->cadena = cadenaNueva;
     nuevo->sig = NULL;
     if (puntero != NULL)
     {

          struct Nodo2 *aux = puntero;
          while (aux->sig != NULL)
          {

               aux = aux->sig;
          }
          aux->sig = nuevo;
     }
     else
     {
          puntero = nuevo;
     }
     return puntero;
}
void mostrarLista1(struct Nodo1 *ident)
{
     struct Nodo1 *aux = ident;
     while (aux != NULL)
     {
          printf("%s -- %d\n", aux->cadena, aux->nro);
          aux = aux->sig;
     }
}
void mostrarLista2(struct Nodo2 *ident)
{
     struct Nodo2 *aux = ident;
     while (aux != NULL)
     {
          printf("%s\n", aux->cadena);
          aux = aux->sig;
     }
}
void opciones()
{
     printf("\nINGRESE LA OPCION DE LO QUE DESEA HACER:\n\n");
     printf("1)  GENERAR LISTA DE IDENTIFICADORES\n");
     printf("2)  GENERAR LISTA DE LITERALES CADENA\n");
     printf("3)  GENERAR LISTA DE PALABRAS RESERVADAS\n");
     printf("4)  GENERAR LISTA DE CONSTANTES DECIMALES\n");
     printf("5)  GENERAR LISTA DE CONSTANTES OCTALES\n");
     printf("6)  GENERAR LISTA DE CONSTANTES HEXADECIMALES\n");
     printf("7)  GENERAR LISTA DE CONSTANTES REALES\n");
     printf("8)  GENERAR LISTA DE CONSTANTES CARACTER\n");
     printf("9)  GENERAR LISTA DE CARACTERES DE PUNTUACION\n");
     printf("10) GENERAR LISTA DE CARACTERES DE OPERACION\n");
     printf("11) GENERAR LISTA DE CARACTERES DE COMENTARIOS\n");
     printf("12) GENERAR LISTA DE CARACTERES DE CARACTERES NO RECONOCIDOS\n");
     printf("13) SALIR DEL REPORTE\n");
}

void imprimirOpciones()
{

     int opcionIngresada;
     printf("-------------------------------------------------------------------------");
     printf("\n\t\t\t\tREPORTE\n");
     printf("-------------------------------------------------------------------------\n\n");
     do
     {
          opciones();
          scanf("%d", &opcionIngresada);
          switch (opcionIngresada)
          {
          case 1:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 1: GENERAR LISTA DE IDENTIFICADORES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE IDENTIFICADORES:\n");
               mostrarLista1(id);
               break;

          case 2:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 2: GENERAR LISTA DE LITERALES CADENA.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE LITERALES CADENA:\n");
               mostrarLista1(id);
               break;

          case 3:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 3: GENERAR LISTA DE PALABRAS RESERVADAS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE PALABRAS RESERVADAS:\n");
               mostrarLista1(id);
               break;

          case 4:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 4: GENERAR LISTA DE CONSTANTES DECIMALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CONSTANTES DECIMALES:\n");
               mostrarLista1(id);
               break;

          case 5:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 5: GENERAR LISTA DE CONSTANTES OCTALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CONSTANTES OCTALES:\n");
               mostrarLista1(id);
               break;

          case 6:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 6: GENERAR LISTA DE CONSTANTES REALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CONSTANTES HEXADECIMAL:\n");
               mostrarLista1(id);
               break;

          case 7:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 7: GENERAR LISTA DE CONSTANTES REALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CONSTANTES REALES:\n");
               mostrarLista1(id);
               break;

          case 8:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 8: GENERAR LISTA DE CONSTANTES CARACTER.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CONSTANTES CARACTER:\n");
               mostrarLista1(id);
               break;

          case 9:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 9: GENERAR LISTA DE CARACTERES DE PUNTUACION.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CARACTERES DE PUNTUACION:\n");
               mostrarLista1(id);
               break;

          case 10:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 10: GENERAR LISTA DE CARACTERES DE OPERACION.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CARACTERES DE OPERACION:\n");
               mostrarLista1(id);
               break;

          case 11:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 11: GENERAR LISTA DE COMENTARIOS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE COMENTARIOS:\n");
               mostrarLista1(id);
               break;

          case 12:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 12: GENERAR LISTA DE CARACTERES RECONOCIDOS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("LISTA DE CARACTERES NO RECONOCIDOS:\n");
               mostrarLista1(id);
               break;
          }

          system("pause");
          system("cls");

     } while (opcionIngresada != 13);
     printf("-------------------------------------------------------------------------");
     printf("\n\t\t\tREPORTE FINALIZADO\n");
     printf("-------------------------------------------------------------------------\n\n");
}
