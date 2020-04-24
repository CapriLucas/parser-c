#include <stdio.h>

// Clasifica la constante entera segun su ultimo tipo
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
    // switch (filaPalabra)
    // {
    // case 1:
    //     fputs("\tEs una constante decimal\n\n", x);
    //     break;
    // case 2:
    // case 5:
    //     fputs("\tEs una constante octal\n\n", x);
    //     break;
    // case 4:
    //     fputs("\tEs una constante hexadecimal\n\n", x);
    //     break;
    // default:
    //     fputs("\tNo es una constante reconocida\n\n", x);
    //     break;
    // }
}

//Devuelve fila/Estado siguiente luego de ser analizado segun su valor en las columnas/Valores
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
    // switch (caracter)
    // {
    // case '0':
    //     fputc(caracter, x);
    //     return matriz[estado][0];
    //     break;
    // case '1':
    // case '2':
    // case '3':
    // case '4':
    // case '5':
    // case '6':
    // case '7':
    //     fputc(caracter, x);
    //     return matriz[estado][1];
    //     break;
    // case '8':
    // case '9':
    //     fputc(caracter, x);
    //     return matriz[estado][2];
    //     break;
    // case 'x':
    // case 'X':
    //     fputc(caracter, x);
    //     return matriz[estado][3];
    //     break;
    // case 'a':
    // case 'b':
    // case 'c':
    // case 'd':
    // case 'e':
    // case 'f':
    // case 'A':
    // case 'B':
    // case 'C':
    // case 'D':
    // case 'E':
    // case 'F':
    //     fputc(caracter, x);
    //     return matriz[estado][4];
    //     break;
    // case ',':
    //     escribirTipo(estado, x);
    //     return 0;
    //     break;
    // default:
    //     fputc(caracter, x);
    //     return matriz[estado][5];
    //     break;
    // }
}

int main()
{

    printf("Reconocimiento de constantes enteras en C \n");
    printf("Reconocimiento exitoso. \n");
    printf("-------------------------------- \n");
    printf("Archivo de salida creado correctamente!");
    FILE *e = fopen("entrada.txt", "r");
    FILE *s = fopen("salida.txt", "w");
    //Rellenamos la matriz con los valores de la tabla del automata
    //       0   [1-7] [8-9]  [xX] [a-fA-F] Otro caso

    //q0|    q2    q1    q1    q6     q6     q6

    //q1|    q1    q1    q1    q6     q6     q6

    //q2|    q5    q5    q6    q3     q6     q6

    //q3|    q4    q4    q4    q6     q4     q6

    //q4|    q4    q4    q4    q6     q4     q6

    //q5|    q5    q5    q6    q6     q6     q6

    //q6|    q6    q6    q6    q6     q6     q6

    int matriz[7][6] = {{2, 1, 1, 6, 6, 6},
                        {1, 1, 1, 6, 6, 6},
                        {5, 5, 6, 3, 6, 6},
                        {4, 4, 4, 6, 4, 6},
                        {4, 4, 4, 6, 4, 6},
                        {5, 5, 6, 6, 6, 6},
                        {6, 6, 6, 6, 6, 6}};

    int fila = 0;
    char cLeido;

    //usamos un bucle que vaya averiguando en que columna entra el valor analizado,
    //dependiendo de la ultima fila encontrada se encuentra la proxima fila
    
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
