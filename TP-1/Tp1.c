#include <stdio.h>
#include <string.h>

//Escribe en el archivo el tipo de palabra
void escribirTipo(char tipoPalabra, FILE *X)
{
    if (tipoPalabra == 'N')
    {
        fputs("No Reconocida", X);
    }
    if (tipoPalabra == 'O')
    {
        fputs("Octal", X);
    }
    if (tipoPalabra == 'D')
    {
        fputs("Decimal", X);
    }
    if (tipoPalabra == 'H')
    {
        fputs("Hexadecimal", X);
    }
}
//Entrada.txt : archivo que contiene las palabras a clasificar |Llenar el archivo con palabras separar por ','|
//Salida.txt : archivo que contendra las palabras clasificadas |Ejemplo: 01 -- Octal, 142 -- Decimal, etc.|
//cLeido: caracter leido del archivo Entrada.txt
//tipo: caracter que clasificara la palabra |Este caracter puede tomar estos valores|
//N : No Reconocida
//O : Octal
//D : Decimal
//H : Hexadecimal


int main()
{
    printf("Inicio de programa \n");
    FILE *e = fopen("Entrada.txt", "r");
    FILE *s = fopen("Salida.txt", "w");
    char cLeido;
    char tipo = 'O';
    escribirTipo(tipo, s);
    fclose(e);
    fclose(s);
    return 0;
}