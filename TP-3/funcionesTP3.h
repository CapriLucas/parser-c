#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
struct Nodo3
{
     double mantisa;
     int entera;
     char *cadena;
     struct Nodo3 *sig;
};
struct Nodo1 *id = NULL;
struct Nodo1 *lt = NULL;
struct Nodo2 *pr = NULL;
struct Nodo1 *coct = NULL;
struct Nodo1 *chex = NULL;
struct Nodo1 *cdec = NULL;
struct Nodo3 *cre = NULL;
struct Nodo2 *ccar = NULL;
struct Nodo1 *cop = NULL;
struct Nodo1 *cpu = NULL;
struct Nodo2 *coml = NULL;
struct Nodo2 *comml = NULL;
struct Nodo1 *ccarno = NULL;

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

struct Nodo3 *agregarALista3(struct Nodo3 *puntero, char *cadenaNueva, int ent, double mant)
{
     struct Nodo3 *nuevo = (struct Nodo3 *)malloc(sizeof(struct Nodo3));
     nuevo->mantisa = mant;
     nuevo->entera = ent;
     nuevo->cadena = cadenaNueva;
     nuevo->sig = NULL;
     if (puntero != NULL)
     {
          struct Nodo3 *aux = puntero;
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

struct Nodo1 *buscarCadena(struct Nodo1 *puntero, char *cad)
{
     struct Nodo1 *aux = puntero;
     while (aux != NULL && strcmp(aux->cadena, cad) != 0)
     {
          aux = aux->sig;
     }
     return aux;
}
struct Nodo2 *buscarCadena2(struct Nodo2 *puntero, char *cad)
{
     struct Nodo2 *aux = puntero;
     while (aux != NULL && strcmp(aux->cadena, cad) != 0)
     {
          aux = aux->sig;
     }
     return aux;
}

int sumarDecimales(struct Nodo1 *dec)
{
     struct Nodo1 *aux = dec;
     int total = 0;
     while (aux != NULL)
     {
          total = total + atoi(aux->cadena);
          aux = aux->sig;
     }
     return total;
}
struct Nodo1 *verificarCadena(struct Nodo1 *punt, char *cadena)
{
     char *palabra = (char *)malloc(100 * sizeof(char *));
     strcpy(palabra, cadena);
     struct Nodo1 *cadbus = buscarCadena(punt, palabra);
     if (cadbus == NULL)
     {
          punt = agregarALista(punt, palabra, 1);
     }
     else
     {
          cadbus->nro++;
     }
     return punt;
}
struct Nodo1 *verificarCadena2(struct Nodo1 *punt, char *cadena, int cant)
{
     char *palabra = (char *)malloc(100 * sizeof(char *));
     strcpy(palabra, cadena);
     struct Nodo1 *cadbus = buscarCadena(punt, palabra);
     if (cadbus == NULL)
     {
          punt = agregarALista(punt, palabra, cant);
     }
     return punt;
}
struct Nodo2 *verificarCadena3(struct Nodo2 *punt, char *cadena)
{
     char *palabra = (char *)malloc(100 * sizeof(char *));
     strcpy(palabra, cadena);
     struct Nodo2 *cadbus = buscarCadena2(punt, palabra);
     if (cadbus == NULL)
     {
          punt = agregarALista2(punt, palabra);
     }
     return punt;
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
     int i = 1;
     while (aux != NULL)
     {
          printf("%d --- %s\n", i, aux->cadena);
          aux = aux->sig;
          i++;
     }
}
void mostrarLista3(struct Nodo3 *ident)
{
     struct Nodo3 *aux = ident;
     while (aux != NULL)
     {
          printf("%s %d %f\n", aux->cadena, aux->entera, aux->mantisa);
          aux = aux->sig;
     }
}

int sumarElementosLista(struct Nodo1 *cdec)
{
     int suma = 0;
     while (cdec != NULL)
     {
          suma = suma + cdec->nro;
          cdec = cdec->sig;
     }
     return suma;
}

long long HexadecimalADecimal(char hexadecimal[40])
{
     long long numeroDecimal, pos;
     int i = 0, val, len;

     numeroDecimal = 0;
     pos = 1;

     len = strlen(hexadecimal);
     len--;

     for (i = 0; hexadecimal[i] != '\0'; i++)
     {

          if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
          {
               val = hexadecimal[i] - 48;
          }
          else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
          {
               val = hexadecimal[i] - 97 + 10;
          }
          else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
          {
               val = hexadecimal[i] - 65 + 10;
          }

          numeroDecimal += val * pow(16, len);
          len--;
     }

     return numeroDecimal;
}

int OctalADecimal(int numeroOctal)
{
     int numeroDecimal = 0, i = 0;
       printf("%d\n",numeroOctal);
     while (numeroOctal != 0)
     {
          numeroDecimal += (numeroOctal%10) * (int)pow(8, i);
        
          i++;
          numeroOctal /= 10;
     }
     return numeroDecimal;
}

void opciones()
{
     printf("\nINGRESE LA OPCION DE LO QUE DESEA HACER:\n\n");
     printf("1)  Generar lista de identificadores\n");
     printf("2)  Generar lista de literales cadenas\n");
     printf("3)  Generar lista de palabras reservadas\n");
     printf("4)  Generar listado de constantes decimales\n");
     printf("5)  Generar listado de constantes octales\n");
     printf("6)  Generar listado de constantes hexadecimales\n");
     printf("7)  Generar listado de constantes reales\n");
     printf("8)  Generar listado de constantes caracter\n");
     printf("9)  Generar listado de caracteres de puntuacion\n");
     printf("10) Generar listado de caracteres de operacion\n");
     printf("11) Generar listado de comentarios \n");
     printf("12) Generar listado de caracteres no reconocidos\n");
     printf("13) Salir del reporte\n");
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
               printf("Listado de identificadores encontrados y su cantidad de veces: \n");
               mostrarLista1(id);
               break;

          case 2:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 2: GENERAR LISTA DE LITERALES CADENA.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de literales cadena encontrados y la longitud de los mismos:\n");
               mostrarLista1(lt);
               break;

          case 3:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 3: GENERAR LISTA DE PALABRAS RESERVADAS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de palabras reservadas encontradas en el orden en el que se encontraron:\n");
               mostrarLista2(pr);
               break;

          case 4:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 4: GENERAR LISTA DE CONSTANTES DECIMALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de constantes decimales encontradas y el total acumulado:\n");
               mostrarLista1(cdec);
               printf("El total acumulado es: %d\n", sumarDecimales(cdec));
               break;

          case 5:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 5: GENERAR LISTA DE CONSTANTES OCTALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de constantes octales encontradas y su valor en decimal:\n");
               mostrarLista1(coct); /*Modificar*/
               break;

          case 6:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 6: GENERAR LISTA DE CONSTANTES HEXADECIMALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de constantes hexadecimales encontradas y su valor en decimal:\n");
               mostrarLista1(chex); /*Modificar*/
               break;

          case 7:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 7: GENERAR LISTA DE CONSTANTES REALES.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de constantes reales encontradas junto con el valor de su mantisa y parte entera:\n");
               mostrarLista3(cre);
               break;

          case 8:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 8: GENERAR LISTA DE CONSTANTES CARACTER.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de constantes caracter encontradas segun su orden de aparicion:\n");
            mostrarLista2(ccar);
               break;

          case 9:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 9: GENERAR LISTA DE CARACTERES DE PUNTUACION.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de caracteres de puntuacion encontrados y la cantidad de veces que aparecen:\n");
               mostrarLista1(cop);
               break;

          case 10:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 10: GENERAR LISTA DE CARACTERES DE OPERACION.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de caracteres de operacion encontrados y la cantidad de veces que aparecen::\n");
               mostrarLista1(cpu);
               break;

          case 11:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 11: GENERAR LISTA DE COMENTARIOS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de comentarios encontrados clasificados en multilinea/simples:\n");
               mostrarLista1(id); /*Modificar*/
               break;

          case 12:
               printf("-------------------------------------------------------------------------");
               printf("\nUSTED INGRESO LA OPCION 12: GENERAR LISTA DE CARACTERES NO RECONOCIDOS.\n");
               printf("-------------------------------------------------------------------------\n\n");
               printf("Listado de cadenas y caracteres no reconocidos con su numero de linea:\n");
               mostrarLista1(id); /*Modificar*/
               break;
          }

          system("pause");
          system("cls");

     } while (opcionIngresada != 13);
     printf("-------------------------------------------------------------------------");
     printf("\n\t\t\tREPORTE FINALIZADO\n\n");
     printf("-------------------------------------------------------------------------\n\n");
}
