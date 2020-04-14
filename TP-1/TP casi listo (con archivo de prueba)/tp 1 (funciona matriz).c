#include <stdio.h>



void escribirTipo(int filaPalabra, FILE *x)
{
    if (filaPalabra == 5 || filaPalabra == 2)
    {
        fputs("\tEs una constante octal\n\n", x);
    }
    if (filaPalabra == 1)
    {
        fputs("\tEs una constante decimal\n\n", x);
    }
    if (filaPalabra == 4)
    {
        fputs("\tEs una constante hexadecimal\n\n", x);
    }
    if (filaPalabra == 6)
    {
        fputs("\tNo es una constante reconocida\n\n", x);
    }
}
//cambie el estado (1) por el (2) en Octal y (2) por el (1) en el Decimal (asi estaba en el automata)  






int devolverFila(char caracter, int matriz[7][6], int estado, FILE *x)
{

    if (caracter == '0')
    {
        fputc(caracter, x);
        return matriz[estado][0];
    }
    
    if (caracter >= '1' && caracter <= '7')
    {
        fputc(caracter, x);
        return matriz[estado][1];
    }
    
    if (caracter >= '8' && caracter <= '9')
    {
        fputc(caracter, x);
        return matriz[estado][2];
        
    }
    if (caracter == 'x' || caracter == 'X')
    {
        fputc(caracter, x);
        return matriz[estado][3];
    }
    if ((caracter >= 'a' && caracter <= 'f') || (caracter >= 'A' && caracter <= 'F'))
    {
        fputc(caracter, x);
        return matriz[estado][4];
    }
    if (caracter == ',')
    {
        escribirTipo(estado, x);
        return 0;
    }
    else
    {   
        fputc(caracter, x);
        return matriz[estado][5];
    }
}




int main()
{
    
    printf("Reconocimiento de constantes enteras en C \n");
    printf("Reconocimiento exitoso. \n");
    printf("-------------------------------- \n");
    printf("Archivo de salida creado correctamente!");
    FILE *e = fopen("Entrada.txt", "r");
    FILE *s = fopen("Salida.txt", "w");
    //Rellenamos la matriz con los valores de la tabla del automata
    //Mejore un poco las salidas 
    
    int matriz[7][6] = {{2, 1, 1, 6, 6, 6},
                        {1, 1, 1, 6, 6, 6},
                        {5, 5, 6, 3, 6, 6},
                        {4, 4, 4, 6, 4, 6},
                        {4, 4, 4, 6, 4, 6},
                        {5, 5, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6, 6}};
    
    //Ahi arregle la matriz, estaban mal las primeras 3 filas (no se porque antes funcionaba si la matriz del automata es distinta ??¿?¿??)


    int fila = 0;
    char cLeido;

    //usamos un bucle que vaya averiguando en que columna entra el valor analizado, y dependiendo de la ultima fila encontrada se encuentra la
    //proxima fila
    
    
    while (!feof(e))
    {
        cLeido = fgetc(e);
        if (cLeido != -1)
        {
            fila = devolverFila(cLeido, matriz, fila, s);
           
        }
        }
		escribirTipo(fila, s);    
    
    
    fclose(e);
    fclose(s);
    return 0;
}