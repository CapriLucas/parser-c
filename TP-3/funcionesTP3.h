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

void imprimirOpciones(){
     printf("Eleccion del reporte:\n\n");
     printf("1)Listado de identificadores encontrados y su cantidad de veces");
}



// struct Nodo1
// {
//     int nro;          
//     char* cadena;        
//     struct Nodo1 *sig; // puntero al siguiente nodo
// };
// struct Nodo1* id=NULL;
// struct Nodo1 *agregarALista(struct Nodo1 *puntero, char *cadenaNueva, int numero){
//     struct Nodo1 *nuevo = (struct Nodo1*)malloc(sizeof(struct Nodo1));
    
//     strcpy(nuevo->cadena,cadenaNueva);
//     nuevo->nro=numero;
//     nuevo->sig=NULL;
//     if(puntero!=NULL){
//         struct Nodo1 *aux = puntero;
//         while(aux->sig!=NULL){
           
//             aux=aux->sig;
//         }
//         aux->sig = nuevo;
//     }else{
//         puntero = nuevo;
//     }
   
//     return puntero;
// }
// void mostrarListaID(struct Nodo1* id){
//     struct Nodo1 *aux = id;
//     while(aux !=NULL){
//         printf("%s",id->cadena);
//         aux = aux->sig;
//     }
// }