#include <stdio.h>

//esta funcion te devuelve la columna a la que pertenece el caracter analizado, los numeros que se ven son los valores ascii
int devolverColumna(char caracter){
    if (caracter==48){
        return 0;
    }
    else if (caracter >= 49 && caracter <= 55){
        return 1;
    }
    else if (caracter >= 56 && caracter <= 57){
        return 2;
    }
    else if (caracter == 120 || caracter == 88){
        return 3;
    }
    else if ((caracter >= 97 && caracter <= 102) || (caracter >= 65 && caracter <= 70))
    {
        return 4;
    }

}
//modifique la funcion del otro archivo para poder hacerlo facil para esta prueba, dependiendo en que fila (terminal del AFD) este te dice que
//que tipo es
char escribirTipo(int filaPalabra)
{
    if (filaPalabra == 2 || filaPalabra == 5)
    {
        printf( "Es octal");
    }
    else if (filaPalabra == 1)
    {
        printf( "Es decimal");
    }
    else if (filaPalabra == 4)
    {
        printf( "Es hexadecimal");    
    }
    else
    {
        printf( "Escribi bien gil");
    }
    
    
}

int main ()
{    

    //Rellenamos la matriz con los valores de la tabla del automata
    int matriz [7][5] = {   {2,1,1,6,6},
                            {1,1,1,6,6},
                            {5,5,6,3,6},
                            {4,4,4,6,4},
                            {4,4,4,6,4},
                            {5,5,6,6,6},
                            {6,6,6,6,6}               
                        };
    // ingreso por codigo el numero a analizar (no se como usar inputs todavia)
    char prueba [20] = "0x2511";
    int fila = 0, columna;
    int i = 0;
    //usamos un bucle que vaya averiguando en que columna entra el valor analizado, y dependiendo de la ultima fila encontrada se encuentra la
    //proxima fila
    for(i= 0; i<sizeof(prueba);i++)
    {
        columna = devolverColumna(prueba[i]);
        fila = matriz [fila][columna];
    }
    escribirTipo(fila);  
}