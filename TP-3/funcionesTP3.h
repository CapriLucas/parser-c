#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

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


/*
void imprimirOpciones(){
     printf("Eleccion del reporte:\n\n");
     printf("1)Listado de identificadores encontrados y su cantidad de veces");
}
*/


struct Nodo1{
     int nro;          
     char* cadena;        
     struct Nodo1 *sig; // puntero al siguiente nodo
};

struct Nodo1* id=NULL;

struct Nodo1 *agregarALista(struct Nodo1 *puntero, char *cadenaNueva, int numero){
struct Nodo1 *nuevo = (struct Nodo1*)malloc(sizeof(struct Nodo1));  
     strcpy(nuevo->cadena,cadenaNueva);
     nuevo->nro=numero;
     nuevo->sig=NULL;
     if(puntero!=NULL){
         struct Nodo1 *aux = puntero;
         while(aux->sig!=NULL){
           
             aux=aux->sig;
         }
         aux->sig = nuevo;
     }else{
         puntero = nuevo;
     } 
     return puntero;
 }


void mostrarListaID(struct Nodo1* id){
     struct Nodo1 *aux = id;
     while(aux !=NULL){
         printf("%s",id->cadena);
         aux = aux->sig;
     }
 }



void opciones(){
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


void imprimirOpciones(){
struct Nodo1* lista = NULL;
int opcionIngresada;
     printf("-------------------------------------------------------------------------");
     printf("\n\t\t\t\tREPORTE\n");
     printf("-------------------------------------------------------------------------\n\n");
    do
    {
        opciones();  
        scanf("%d", &opcionIngresada);
        switch(opcionIngresada)
        {
          case 1:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 1: GENERAR LISTA DE IDENTIFICADORES.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE IDENTIFICADORES:\n"); 
                 mostrarListaID(lista);
               break;

          case 2:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 2: GENERAR LISTA DE LITERALES CADENA.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE LITERALES CADENA:\n"); 
                 mostrarListaID(lista);
               break;

          case 3:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 3: GENERAR LISTA DE PALABRAS RESERVADAS.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE PALABRAS RESERVADAS:\n");
                 mostrarListaID(lista);
               break;

          case 4:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 4: GENERAR LISTA DE CONSTANTES DECIMALES.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CONSTANTES DECIMALES:\n");
                 mostrarListaID(lista);
               break;

          case 5:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 5: GENERAR LISTA DE CONSTANTES OCTALES.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CONSTANTES OCTALES:\n");
                 mostrarListaID(lista);
               break;

          case 6:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 6: GENERAR LISTA DE CONSTANTES REALES.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CONSTANTES HEXADECIMAL:\n");
                 mostrarListaID(lista);
               break;
 
          case 7:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 7: GENERAR LISTA DE CONSTANTES REALES.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CONSTANTES REALES:\n");
                 mostrarListaID(lista);
               break;
 
          case 8:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 8: GENERAR LISTA DE CONSTANTES CARACTER.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CONSTANTES CARACTER:\n");
                 mostrarListaID(lista);
               break;
 
          case 9:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 9: GENERAR LISTA DE CARACTERES DE PUNTUACION.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CARACTERES DE PUNTUACION:\n");
                 mostrarListaID(lista);
               break;
 

          case 10:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 10: GENERAR LISTA DE CARACTERES DE OPERACION.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CARACTERES DE OPERACION:\n");
                 mostrarListaID(lista);
               break;

          case 11:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 11: GENERAR LISTA DE COMENTARIOS.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE COMENTARIOS:\n");
                 mostrarListaID(lista);
               break;

          case 12:
                 printf("-------------------------------------------------------------------------");
                 printf("\nUSTED INGRESO LA OPCION 12: GENERAR LISTA DE CARACTERES RECONOCIDOS.\n");
                 printf("-------------------------------------------------------------------------\n\n");
                 printf("LISTA DE CARACTERES NO RECONOCIDOS:\n");
                 mostrarListaID(lista);
               break;
                    }
 
        system("pause");  
        system("cls");
 
    }while(opcionIngresada!=13);
                 printf("-------------------------------------------------------------------------");
                 printf("\n\t\t\tREPORTE FINALIZADO\n");
                 printf("-------------------------------------------------------------------------\n\n");
}

