#include <stdio.h>
#include <windows.h>
#include <conio.h>

struct Est{                                                         //estructura utilizada para el array
	
	int estado_Sig;
	char cadPush[3];
};

struct Nodo{
	
	char info;
	struct Nodo* sig;
};


struct Nodo* push(struct Nodo *pila, char caracter){                //funcion push para pila
	
	struct Nodo* nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
	nuevo->info = caracter;
	nuevo->sig = pila;
	return nuevo;
}

struct Nodo* pop(struct Nodo *pila){                                //funcion pop para pila
	
	struct Nodo* aux = pila;
	pila = aux->sig;
	return pila;
}


void tablaDeTransicionDeAutomata(struct Est TT[4][2][6]){	        //casos posibles de la tabla de transicion del automata de pila


	TT[0][0][1].estado_Sig=1;
	strcpy(TT[0][0][1].cadPush,"$");       //si entra un 0 --- esta en estado (q0,$)
	
	TT[0][0][3].estado_Sig=0;
	strcpy(TT[0][0][3].cadPush,"R$");      //si entra un ( --- esta en estado (q0,$)
	
	TT[1][0][0].estado_Sig=1;
	strcpy(TT[1][0][0].cadPush,"$");       //si entra un 0 --- esta en estado (q1,$)
	
	TT[1][0][1].estado_Sig=1; 
	strcpy(TT[1][0][1].cadPush,"$");       //si entra un caracter entre el 1 y el 9 --- esta en estado (q1,$)
	
	TT[1][0][2].estado_Sig=0;
	strcpy(TT[1][0][2].cadPush,"$");       //si entra un operador (*,/,+,-) --- esta en estado (q1,$) 
			
	TT[0][1][1].estado_Sig=1;
	strcpy(TT[0][1][1].cadPush,"R");       //si entra un caracter entre el 1 y 9 --- esta en estado (q0,R)
	
	TT[0][1][3].estado_Sig=0;
	strcpy(TT[0][1][3].cadPush,"RR");      //si entra un ( --- esta en estado (q0,R)
	
	TT[1][1][0].estado_Sig=1;
	strcpy(TT[1][1][0].cadPush,"R");       //si entra un 0 --- esta en estado (q1,R) 
	
	TT[1][1][1].estado_Sig=1;
	strcpy(TT[1][1][1].cadPush,"R");       //si entra un caracter entre el 1 y 9 --- esta en estado (q1,R)
	
	TT[1][1][2].estado_Sig=0;
	strcpy(TT[1][1][2].cadPush,"R");       //si entra un operador (*,+,/,-) --- esta en estado (q1,R)
	
	TT[1][1][4].estado_Sig=2;
	strcpy(TT[1][1][4].cadPush,"");        //si entra un ) --- esta en estado (q1,R)   || "" refiere al caracter nulo o epsilon *
	
	TT[2][1][2].estado_Sig=0;
	strcpy(TT[2][1][2].cadPush,"R");       //si entra un operador (*,/,+,-) --- esta en estado (q2,R)
	
	TT[2][1][4].estado_Sig=2;
	strcpy(TT[2][1][4].cadPush,"");        //si entra un ) --- esta en estado (q2,R)  || "" refiere al caracter nulo o epsilon *
	
	TT[2][0][2].estado_Sig=0;
	strcpy(TT[2][0][2].cadPush,"$");       //si entra un operador (*,+,/,-) --- esta en estado (q2,$)
	
}
 
 

void analizar (struct Est TT[4][2][6]) {


	struct Nodo* pila = (struct Nodo*)malloc(sizeof(struct Nodo));  
	
	pila = push(pila, '$');  
	
	printf("Expresion que desea evaluar: ");
	
	int cimaDePila,columna;
	int estado;
	estado=0; 
	int error;
	error=0;

	char caracterLeido;
	caracterLeido = getche();  // lee el caracter, sabiendo que la pila comienza vacia
	
	while(caracterLeido!=13) {  //chequea que el usuario este ingresando una cadena hasta que presione enter, (en ASCII es 13) 
	

	    char cima;
		cima = pila->info;     //cima apunta al ultimo ingreso en la pila 
		
		
		if(cima == '$'){		//revisa si es $, entonces la pila esta vacia
		
			cimaDePila = 0; 
}

		else{
		
			cimaDePila = 1; 
}
		pila = pop(pila);

										//a partir de aca hace el recorrido por la expresion 
			if(caracterLeido == 0){
		
			columna = 0;
		}
		else if(caracterLeido>= '1' && caracterLeido <= '9'){
		
			columna = 1;
		}
		else if(caracterLeido == '-' || caracterLeido == '+' || caracterLeido == '/' || caracterLeido == '*'){
		
			columna = 2;
		}
		else if(caracterLeido == '('){
		
			columna = 3;
		}
		else if(caracterLeido == ')'){
		
			columna = 4;
		}
		else{
		
			columna = 5;
	}
			
    int i=1; 

	while(i>=0)
		{
			if(TT[estado][cimaDePila][columna].cadPush[i] == '$' || TT[estado][cimaDePila][columna].cadPush[i] == 'R')
				pila = push(pila,TT[estado][cimaDePila][columna].cadPush[i]);
			i--;
		}
		
		estado=TT[estado][cimaDePila][columna].estado_Sig;
		
		if(estado==3){
			error = 1;
		}
			else{
				caracterLeido = getche();
		}
	}
	if(pila->info != '$'){            //si no se vacia la pila, va al estado 3 (rechazo)
		estado = 3; 
}


	if(estado == 3) 
	{
		printf("Error. La expresion no es sintacticamente correcta.\n");
		printf("Por favor revise su entrada y vuelva a intentarlo\n");
	}
	else
		printf("No se detectaron errores en su entrada.");
}
	


int main()
{
	struct Est TT[4][2][6]; // declaramos la tabla
	
	tablaDeTransicionDeAutomata(TT); 

	printf("Reconocimiento de expresiones \n");
	printf("----------------------------- \n");
	
	int opcion;
	char temp[10]; //cadena temporal para que despues se vacie el buffer
	do	{
			printf("\nPresione 1 para ingresar una expresion \n");
			printf("Presione 2 para finalizar el programa\n");

			fgets(temp,10,stdin); //se lee la cadena y se guarda en la variable temporal desde stdin || Puede hacerse tambien con scanf
			opcion  = atoi(temp); //pasamos el buffer a tipo numero
			switch(opcion)	{
				case 1:
					 analizar(TT);
				break;
				case 2: printf("Gracias por utilizar el software!");
				break;
				default:
					printf("Opcion incorrecta\n");
				break;
			}
	} while(opcion != 2);
	return 0;
}