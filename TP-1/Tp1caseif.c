#include <stdio.h>
#include <string.h>

//Escribe en el archivo el tipo de palabra
void escribirTipo(char tipoPalabra, FILE *X)
{
    if (tipoPalabra == 'N')
    {
        fputs("\tNo Reconocida\n", X);
    }
    if (tipoPalabra == 'O'|| tipoPalabra == 'L' )
    {
        fputs("\tOctal\n", X);
    }
    if (tipoPalabra == 'D')
    {
        fputs("\tDecimal\n", X);
    }
    if (tipoPalabra == 'H')
    {
        fputs("\tHexadecimal\n", X);
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
//L : Octal o Hexadecimal

//              
//           _____ [0-9]    
//           \   /        _____ [0-7]
//          (q2+)         \   /
//         /              (q5+)
//  [1-9] /      [0-7]  /
//       /             /
//  ->(q0-)------>(q1+)
//                    \  [x,X]                  _____ [0-9 a-f A-F]
//                     \        [0-9 a-f A-F]   \   /
//                       (q3)------------------>(q4)
//

// Esta funcion clasifica si la secuencia de caracteres es 'N','D','O','H','L'

//en q0 solo puede tomar 2 caminos seria el caso pos = 0
// si el 1° caracter es un 0 ,tipo pasa a 'L' (este valor puede ser 'H'u'O' se evalua en pos=1)
//si esta entre [1-9], tipo pasa a 'D'
//(cualquier otro caracter) tipo pasa a 'N'

//ahora para el 2° caracter se pasaria a pos = 1 
//segun el tipo del 1° caracter 
//si es 'L' se verifica para que tipo pase a 'H' que el 2° caracter sea [x o X] 
//                                         a 'O' que el 2° caracter este entre [0-7]
// si no verifica 'H' ni 'O' (cualquier otro caracter) tipo pasa a 'N' 

//por ultimo cualquiera sea la posicion de caracter pos = 2 pos= 3.... pos=5 ... etc
//solo quedaria verificar si el tipo es 'D' que los siguientes caracteres esten entre [0-9]
//                                      'O' que los siguientes caracteres esten entre [0-7]
//                                      'H' que los siguientes caracteres esten entre [0-9 a-f A-F]
//                                      'L' este caso solo ocurrira si la cadena solo es "0" por ende
//                                       tipo pasa a 'O'
//Cualquier otro caso pasara a 'N'
char clasificar(char c, int pos, char tipo)
{
    switch (pos)
    {
    case 0:
        switch (c)
        {
        case '0':
            tipo = 'L';
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            tipo = 'D';
            break;
        default:
            tipo = 'N';
            break;
        }
        break;
    case 1:
        if (tipo == 'L')
        {
            switch (c)
            {
            case 'x':
            case 'X':
                tipo = 'H';
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                tipo = 'O';
                break;
            default:
                tipo = 'L';
                break;
            }
        }
        else
        {
            if (tipo == 'D')
            {
                switch (c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    tipo = 'D';
                    break;
                default:
                    tipo = 'N';
                    break;
                }
            }
        }
        break;
    default:
        switch (tipo)
        {
        case 'D':
            if (c >= '0' && c <= '9')
            {
                tipo = 'D';
            }
            else
            {
                tipo = 'N';
            }
            break;
        case 'O':
            if (c >= '0' && c <= '7')
            {
                tipo = 'O';
            }
            else
            {
                tipo = 'N';
            }
            break;
        case 'H':
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
            {
                tipo = 'H';
            }
            else
            {
                tipo = 'N';
            }
            break;
        default:
            tipo = 'N';
            break;
        }

        break;
    }
    return tipo;
}

int main()
{
    printf("Inicio de programa \n");
    FILE *e = fopen("Entrada.txt", "r");
    FILE *s = fopen("Salida.txt", "w");
    char cLeido;
    char tipo = 'N';
    int pos = 0;
    cLeido = getc(e);
    while (!feof(e))
    {
        while (cLeido != ',' && cLeido!= EOF)
        {
            //clasifica el tipo de constante entera de la cadena leida caracter a caracter se va clasificando
            tipo = clasificar(cLeido, pos, tipo);
            //graba el caracter en el archivo de salida "s"
            fputc(cLeido,s);
            cLeido = getc(e);
            pos++;
        }
        //graba el tipo de constante Entera que clasifico la funcion clasificar
        escribirTipo(tipo, s);

 
        pos = 0;
        tipo = 'N';
        cLeido = getc(e);
    }

    fclose(e);
    fclose(s);
    return 0;
}