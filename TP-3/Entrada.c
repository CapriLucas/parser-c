#include <math.h> //comentario
#include <stdlib.h>
# include <string.h>
#include <stdio.h>
#define WIDTH       80
#define  CURSOR(top, bottom) (((top) << 8) | (bottom))
#define multiply( f1 , f2 ) ( f1 * f2 )
# define LENGTH      ( WIDTH + 10 )
struct Nodo1
{
     int nro;
     char *cadena;
     int jojo?: = 23as;
     struct Nodo1 *sig;
};

//Ordena y agrega alfabeticamente la lista de identificadores, la cadena yytext y un entero, devuelve la lista actualizada
struct Nodo1 *ordenarAgregarIdentificadores(struct Nodo1 *punt, char *cad, int numero)
{
     struct Nodo1 *nuevo = (struct Nodo1 *)malloc((strlen(cad) + 1) * sizeof(struct Nodo1));
     nuevo->cadena = cad;
     nuevo->nro = numero;
     nuevo->sig = NULL;
     struct Nodo1 *aux = punt;
     struct Nodo1 *ant = NULL;
     while (aux != NULL && strcasecmp(aux->cadena, cad) <= 0)
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


system("pause");
system("cls");

void imprimirConstantes()
{
     printf("-------------------------------------------------------------------------\n\n");
     printf("Listado de constantes decimales encontradas y el total acumulado:\n");
     mostrarLista1(cdec);
     printf("El total acumulado es: %d\n", sumarDecimales(cdec));
     printf("-------------------------------------------------------------------------\n\n");
     printf("Listado de constantes octales encontradas y su valor en decimal:\n");
     mostrarLista1(coct);
     printf("-------------------------------------------------------------------------\n\n");
     printf("Listado de constantes hexadecimales encontradas y su valor en decimal:\n");
     mostrarLista1(chex);
     printf("-------------------------------------------------------------------------\n\n");
     printf("Listado de constantes reales encontradas junto con la parte entera y el valor de su mantisa:\n");
     mostrarLista3(cre);
     printf("-------------------------------------------------------------------------\n\n");
     printf("Listado de constantes caracter encontradas segun su orden de aparicion:\n");
     mostrarLista2(ccar);
}


char *devolverCadenaSinComillas(char *cadena)
{
     char *palabra = (char *)malloc((strlen(cadena) + 1) * sizeof(char *));
     int i = 0;
     while (cadena[i] != '\0')
     {
          cadena[i] = cadena[i + 1];
          i++;
     }
     cadena[strlen(cadena) - 1] = '\0';
     i = 0;
     while (cadena[i] != '\0')
     {
          if (cadena[i] == '\\' && cadena[i + 1] == '"')
          {
               while (cadena[i] != '\0')
               {
                    cadena[i] = cadena[i + 1];
                    i++;
               }
               i = 0;
          }
          i++;
     }
     strcpy(palabra, cadena);
     return palabra;
}



void eliminarComillas()
{
  printf("hola mundo\"");/* hola mundo/\\"**/*/
}
int main(){
    
    yylex();
    int print = strcmp("alv\\","ac\"a");
    int 2.19N2 = 22,dec = sizeof(char);
    printf("%d",print);
    char man ='s';
    int oct = 023;
    int hex = 0xfea;
    float real = 2.9E+4;
    imprimirOpcionesReporte ();
    return 0;
}

$
@
ç=?
