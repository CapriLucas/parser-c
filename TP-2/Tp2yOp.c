#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Nodo
{
    char elementoPila;
    struct Nodo *sig;
};
struct elemento
{
    int estado;
    char elementoPila[3];
};
struct detector
{
    int posError;
    int elemPila;
    int estado;
};
struct Nodo *pila = NULL;
struct elemento tabla[4][6][2];
struct detector errorEn;

//Retorna el caracter que esta en la cima de la pila
char pop();
//Mete un caracter que se posiciona en la cima de la pila
void push(char c);
//Retorna en un struct elemento los datos que se insertan a la tabla de transicion se le pasan
// | ta = tabla[][][] | est = estado | elem = "cimaPila"
struct elemento insertarDatosTT(struct elemento ta, int est, char *elem);
//Inicia la tabla de transicion llenandola con estado de rechazo en toda posicion se le asigna el simbolo de rechazo
// tabla[][][].estado = 3 | tabla[][][].elementoPila =  "rechazo"
void iniciarTabla(char *rechazo);
//Se llena la tabla de transicion con los datos para el analizador sintactico
void llenarTabla();
//Se imprime en pantalla la tabla de transicion
void imprimirTablaTransicion();
//Elimina los espacios que tiene la cadena de caracteres
void eliminarEspacios(char s[]);
//Retorna la cantidad de caracteres que tiene la cadena que se le pasa
int length(char c[]);
//Retorna true o false segun detecte si struct elemento act tiene estado de rechazo se le pasa un bool que al
// iniciar el analizador comienza en false
bool detectarError(struct elemento act, bool primerError);
//Retorna lo que se espera que deberia ir en el errorEncontrado segun el tipo de pos = nro de columna
char *deberiaIr(int pos);
//Retorna un struct elemento con el sig estado y cimaPila a analizar segun:
// caracter = caracter que se encuentra analizando | estado = estado actual | posElemento = cimaPila $:0 R:1
struct elemento devolverElementos(char caracter, int estado, int posElemento);
//Hace el push en la pila segun el tipo de caracter estado y (posElemento:cimaPila) en que se encuentra
void pushearSegunEstadocimaPila(char caracter, int estado, int posElemento);
//Retorna un struct elemento con el sig estado y cimaPila a analizar y pushea la cimaPila del struct retornado
struct elemento pushearDevolverElementos(char caracter, int estado, int posElemento);
//Imprime segun el error encontrado al analizar lo que se espera que deberia ir
void imprimirLoQueDeberiaIr();
//Imprime el resultado de analizar la expresion se le pasa un | bool esExpresion que al iniciar el analizador es
//false y cambia segun sea o no una expresion | exp = cadena que se analizo | lugar = toma los valores de en y despues
//sirven para expresar si el error esta en dicha posicion o despues de dicha posicion
void resultadoDeExpresion(bool esExpresion, char exp[], char lugar[]);
//Analiza si la expresion ingresada es sintacticamente correcta o no,determina donde encontro el error
// y que es lo que deberia ir
void analizadorSintactico(char expresion[]);

int main(void)
{

    char cadena[100];
    char continuar[100];
    iniciarTabla("$");
    llenarTabla();
    imprimirTablaTransicion();
    do
    {
        printf("Escriba la expresion a analizar: \n");
        gets(cadena);
        eliminarEspacios(cadena);
        analizadorSintactico(cadena);
        printf("(Para continuar pulse: c | Para finalizar pulse cualquier tecla)\n");
        gets(cadena);
    } while (cadena[0] != 'c');

    return 0;
}

void push(char c)
{
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->sig = NULL;
    nuevo->elementoPila = c;
    if (pila == NULL)
    {
        pila = nuevo;
    }
    else
    {
        struct Nodo *aux = pila;
        pila = nuevo;
        pila->sig = aux;
    }
}
char pop()
{
    char x = pila->elementoPila;
    struct Nodo *aux = pila->sig;
    free(pila);
    pila = aux;
    return x;
}

void eliminarEspacios(char s[])
{
    //4 37  8
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            while (s[i] != '\0')
            {
                s[i] = s[i + 1];
                i++;
            }
            i = 0;
        }
        i++;
    }
}
int length(char c[])
{
    int i = 0;
    while (c[i] != '\0')
    {
        i++;
    }
    return i;
}

struct elemento insertarDatosTT(struct elemento ta, int est, char *elem)
{
    strcpy(ta.elementoPila, elem);
    ta.estado = est;
    return ta;
}

void iniciarTabla(char *rechazo)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                tabla[i][j][k] = insertarDatosTT(tabla[i][j][k], 3, rechazo);
            }
        }
    }
}

void llenarTabla()
{
    tabla[0][1][0] = insertarDatosTT(tabla[0][1][0], 1, "$");
    tabla[0][3][0] = insertarDatosTT(tabla[0][3][0], 0, "R$");
    tabla[1][0][0] = insertarDatosTT(tabla[1][0][0], 1, "$");
    tabla[1][1][0] = insertarDatosTT(tabla[1][1][0], 1, "$");
    tabla[1][2][0] = insertarDatosTT(tabla[1][2][0], 0, "$");
    tabla[0][1][1] = insertarDatosTT(tabla[0][1][1], 1, "R");
    tabla[0][3][1] = insertarDatosTT(tabla[0][3][1], 0, "RR");
    tabla[1][0][1] = insertarDatosTT(tabla[1][0][1], 1, "R");
    tabla[1][1][1] = insertarDatosTT(tabla[1][1][1], 1, "R");
    tabla[1][2][1] = insertarDatosTT(tabla[1][2][1], 0, "R");
    tabla[1][4][1] = insertarDatosTT(tabla[1][4][1], 2, "e");
    tabla[2][2][1] = insertarDatosTT(tabla[2][2][1], 0, "R");
    tabla[2][4][1] = insertarDatosTT(tabla[2][4][1], 2, "e");
    tabla[2][2][0] = insertarDatosTT(tabla[2][2][0], 0, "$");
}

void imprimirTablaTransicion()
{

    printf("Tabla de transicion\n\n");
    printf("(Estado /|                    Caracter                               |\n");
    printf("CimaPila)|    0    |  [1-9]  |{+,-,*,/}|    (    |    )    |Otro Caso|\n");

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (k == 0)
            {
                printf(" (Q%d,$)  |", i);
            }
            else
            {
                printf(" (Q%d,R)  |", i);
            }
            for (int j = 0; j < 6; j++)
            {
                if (j == 3 && i == 0)
                {
                    printf(" (Q%d,%s) |", tabla[i][j][k].estado, tabla[i][j][k].elementoPila);
                }
                else
                {
                    printf(" (Q%d,%s)  |", tabla[i][j][k].estado, tabla[i][j][k].elementoPila);
                }
            }
            printf("\n");
        }
    }
    for (int i = 2; i < 4; i++)
    {
        for (int k = 1; k >= 0; k--)
        {
            if (k == 0)
            {
                printf(" (Q%d,$)  |", i);
            }
            else
            {
                printf(" (Q%d,R)  |", i);
            }
            for (int j = 0; j < 6; j++)
            {
                printf(" (Q%d,%s)  |", tabla[i][j][k].estado, tabla[i][j][k].elementoPila);
            }
            printf("\n");
        }
    }
}
bool detectarError(struct elemento act, bool primerError)
{
    if (!primerError)
    {
        return act.estado == 3 ? true : primerError;
    }
    return primerError;
}
char *deberiaIr(int pos)
{
    switch (pos)
    {
    case 0:
        return " 0";
        break;
    case 1:
        return " [1-9]";
        break;
    case 2:
        return " [+,-,/,*]";
        break;
    case 3:
        return " (";
        break;
    case 4:
        return " )";
        break;
    default:
        return "";
        break;
    }
}
struct elemento devolverElementos(char caracter, int estado, int posElemento)
{
    int i = 0;
    struct elemento aux;
    switch (caracter)
    {
    case '0':
        aux = tabla[estado][0][posElemento];
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
        aux = tabla[estado][1][posElemento];
        break;
    case '+':
    case '-':
    case '/':
    case '*':
        aux = tabla[estado][2][posElemento];
        break;
    case '(':
        aux = tabla[estado][3][posElemento];
        break;
    case ')':

        aux = tabla[estado][4][posElemento];
        break;
    default:

        aux = tabla[estado][5][posElemento];
        break;
    }
    return aux;
}
void pushearSegunEstadocimaPila(char caracter, int estado, int posElemento)
{
    int i = 0;
    switch (caracter)
    {
    case '0':
        push(tabla[estado][0][posElemento].elementoPila[i]);
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
        push(tabla[estado][1][posElemento].elementoPila[i]);
        break;
    case '+':
    case '-':
    case '/':
    case '*':
        push(tabla[estado][2][posElemento].elementoPila[i]);
        break;
    case '(':
        for (int j = length(tabla[estado][3][posElemento].elementoPila) - 1; j >= 0; j--)
        {
            push(tabla[estado][3][posElemento].elementoPila[j]);
        }
        break;
    case ')':
        if ((estado != 1 || estado != 2) && posElemento != 1)
        {
            push(tabla[estado][4][posElemento].elementoPila[i]);
        }
        break;
    default:
        push(tabla[estado][5][posElemento].elementoPila[i]);
        break;
    }
}
struct elemento pushearDevolverElementos(char caracter, int estado, int posElemento)
{
    pushearSegunEstadocimaPila(caracter, estado, posElemento);
    return devolverElementos(caracter, estado, posElemento);
}
void imprimirLoQueDeberiaIr()
{
    char c[6] = "01+()s";
    struct elemento aux;
    for (int i = 0; i < 6; i++)
    {
        aux = devolverElementos(c[i], errorEn.estado, errorEn.elemPila);
        if (aux.estado != 3)
        {
            printf("%s ", deberiaIr(i));
        }
    }
}
void resultadoDeExpresion(bool esExpresion, char exp[], char lugar[])
{
    if (esExpresion)
    {
        printf("La expresion %s es sintacticamente correcta\n", exp);
    }
    else
    {
        printf("Se detecto un error en la expresion %s", exp);
        printf(" %s la posicion %d [%c] se esperaba : \n", lugar, errorEn.posError, exp[errorEn.posError]);
        imprimirLoQueDeberiaIr();
        printf("\n");
    }
}

void analizadorSintactico(char expresion[])
{
    bool esReconocida = false;
    char enDonde[50] = "despues de";
    int i = 0;
    int elePila = 0;
    char salidaPila = '$';
    int error;
    error = i;
    bool primerError = false;
    errorEn.elemPila = elePila;
    errorEn.estado = 0;
    errorEn.posError = error;
    struct elemento analizador = pushearDevolverElementos(expresion[i], 0, elePila);
    i++;

    while (expresion[i] != '\0')
    {
        primerError = detectarError(analizador, primerError);
        if (!primerError)
        {
            errorEn.elemPila = elePila;
            errorEn.estado = analizador.estado;
            errorEn.posError = error;
        }
        error = i;
        salidaPila = pop();
        if (salidaPila == '$')
        {
            elePila = 0;
        }
        else
        {
            elePila = 1;
        }
        analizador = pushearDevolverElementos(expresion[i], analizador.estado, elePila);
        i++;
    }
    if (analizador.elementoPila[0] == 'e' && analizador.estado == 2)
    {
        salidaPila = pop();
    }
    if (salidaPila == '$' && (analizador.estado == 1 || analizador.estado == 2))
    {
        esReconocida = true;
    }
    else
    {
        if (analizador.estado != 3)
        {
            errorEn.elemPila = (int)(salidaPila == '$' ? 0 : 1);
            errorEn.estado = analizador.estado;
            errorEn.posError++;
        }
        else
        {
            if (errorEn.estado == 2 && (errorEn.elemPila == 1 || errorEn.elemPila == 0))
            {
                salidaPila = pop();
                errorEn.elemPila = (int)(salidaPila == '$' ? 0 : 1);
                errorEn.posError++;
                strcpy(enDonde, "");
                strcpy(enDonde, "en");
            }
             if (errorEn.elemPila == 0 && errorEn.estado == 0 && errorEn.posError==0)
            {
                strcpy(enDonde, "");
                strcpy(enDonde, "en");
            }
        }
    }
    resultadoDeExpresion(esReconocida, expresion, enDonde);
}
