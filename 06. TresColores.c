// Ejercicio: Implementar un programa para jugar al rojo, amarillo y verde.
// El programa genera tres dígitos aleatorios entre el 0 y el 9. A estos
// dígitos se le asignan las posiciones 1, 2 y 3. El objetivo del juego
// es adivinar los dígitos así como su posición en un número de intentos
// máximo. Para cada intento, el jugador proporciona 3 números para las
// posiciones 1, 2 y 3. El programa responde con una pista que será rojo,
// amarillo o verde. Si un número está en la posición correcta, responde
// con el color verde, si el número es correcto, pero no lo es la posición,
// el color será amarillo, si no coincide, será rojo.

// Añadimos la librería que usaremos
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Usaremos isdigit()
#include <stdio_ext.h> // Usaremos __fpurge(stdin)
#include <string.h> // Usaremos cadenas de caracteres
#include <time.h> // Usaremos time()

// Prototipos de funciones
int validar(int contador);
int calcular_numero();
void mostrar_resultado(int opcion, int a1, int a2, int a3);

int main(){// Función principal
	int n1,n2,n3; // Declaramos variables para recoger por teclado
	int a1,a2,a3; // Declaramos variables para almacenar aleatorios
	int contador,opcion;
	srand((unsigned)time(0)); // Usamos como semilla la hora del sistema

	for(contador=0;contador<3;contador++){
		switch(contador){
			case 0: 
			a1=calcular_numero();
			break;
			case 1: 
			a2=calcular_numero();
			break;
			case 2: 
			a3=calcular_numero();
			break;
			default:break;
		}
	}

	system("clear");

	printf("Comienza el juego. Adivina tres números, del 0 al 9 y la posición de los mismos.");
	getchar();
	__fpurge(stdin); // Limpiamos el buffer de entrada
	contador=0;

	do{
		printf("\n\nSi el número es el correcto, y está en la posición correcta, se mostrará en verde; si el número es el correcto, pero no la posición, será amarillo y si no existe el número, rojo.\n\n");
		n1=validar(0),n2=validar(1),n3=validar(2);
		system("clear");

		if(n1==a1){// Comparamos el primer número
			printf("%c[%d;%d;%dmVerde%c[%dm(%d) - ",27,1,32,40,27,0,n1);
		}else{
			if(n1==a2 || n1==a3){
				printf("%c[%d;%d;%dmAmarillo%c[%dm(%d) - ",27,1,33,40,27,0,n1);
			}else{
				printf("%c[%d;%d;%dmRojo%c[%dm(%d) - ",27,1,31,40,27,0,n1);
			}
		}

		if(n2==a2){// Comparamos el segundo número
			printf("%c[%d;%d;%dmVerde%c[%dm(%d) - ",27,1,32,40,27,0,n2);
		}else{
			if(n2==a1 || n2==a3){
				printf("%c[%d;%d;%dmAmarillo%c[%dm(%d) - ",27,1,33,40,27,0,n2);
			}else{
				printf("%c[%d;%d;%dmRojo%c[%dm(%d) - ",27,1,31,40,27,0,n2);
			}
		}

		if(n3==a3){// Comparamos el tercer número
			printf("%c[%d;%d;%dmVerde%c[%dm(%d) - ",27,1,32,40,27,0,n3);
		}else{
			if(n3==a2 || n3==a1){
				printf("%c[%d;%d;%dmAmarillo%c[%dm(%d) - ",27,1,33,40,27,0,n3);
			}else{
				printf("%c[%d;%d;%dmRojo%c[%dm(%d) - ",27,1,31,40,27,0,n3);
			}
		}

		if(n1==a1){// Para averiguar si hemos acertado
			if(n2==a2 && n3==a3){
				contador=4;
				opcion=1;
			}
		}
		contador++;
	}while(contador!=5);
	mostrar_resultado(opcion,a1,a2,a3);
	return 0;
}

void mostrar_resultado(int opcion, int a1, int a2, int a3){
	system("clear");
	if(opcion==1){
		printf("%c[%d;%d;%dm¡¡Acertaste!!%c[%dm los números eran %d, %d y %d."
		,27,5,34,40,27,0,a1,a2,a3);
	}else{
		printf("Has fallado los cinco intentos.\nLos números eran %d, %d y %d.",a1,a2,a3);
	 }
 }

int calcular_numero(){ // Función que generá los números
	 int numero=0;
	 numero=rand()%9;// Generamos un número del 0 al 9
	 return numero;
 }

int validar(int contador){
	char posicion[3][8]={"primer","segundo","tercero"};
	char temporal[2];
	int flag, cesta=0;

	do{
		flag=0;
		__fpurge(stdin);
		printf("Introduce el %s número: ",posicion[contador]);
		scanf("%s",temporal);
		system("clear");
		__fpurge(stdin);

		if(strlen(temporal)!=1){
			flag=1;
			printf("%c[%d;%dm¡Error!%c[%dm Solo un número."
			,27,5,31,27,0);
			getchar();
		}else{
			if(isdigit(temporal[0])==0){// Preguntamos si es un digito
				flag=1;
				printf("%c[%d;%dm¡Error!%c[%dm Solo números del 0 al 9."
				,27,5,31,27,0);
				getchar();
			}else{cesta=atoi(temporal);}
		}
	}while(flag==1);

	return cesta;
}
