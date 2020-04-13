#include <stdio.h>

//esta funcion te devuelve la columna a la que pertenece el caracter analizado, los numeros que se ven son los valores ascii

void escribirTipo(int filaPalabra, FILE *x)
{
    if (filaPalabra == 5 || filaPalabra == 1)
    {
        fputs("\tEs octal\n", x);
    }
    if (filaPalabra == 2)
    {
        fputs("\tEs decimal\n", x);
    }
    if (filaPalabra == 4)
    {
        fputs("\tEs hexadecimal\n", x);
    }
    if (filaPalabra == 6)
    {
        fputs("\tNo es Reconocida\n", x);
    }
}

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
//modifique la funcion del otro archivo para poder hacerlo facil para esta prueba, dependiendo en que fila (terminal del AFD) este te dice que
//que tipo es

int main()
{
    printf("Inicio de programa \n");
    FILE *e = fopen("Entrada.txt", "r");
    FILE *s = fopen("Salida.txt", "w");
    //Rellenamos la matriz con los valores de la tabla del automata
    int matriz[7][6] = {{1, 2, 2, 6, 6, 6},
                        {5, 5, 6, 3, 6, 6},
                        {2, 2, 2, 6, 6, 6},
                        {4, 4, 4, 6, 4, 6},
                        {4, 4, 4, 6, 4, 6},
                        {5, 5, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6, 6}};
    //algo esta mal en la tabla

    // ingreso por codigo el numero a analizar (no se como usar inputs todavia)

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