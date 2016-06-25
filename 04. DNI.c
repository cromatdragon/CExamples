// Ejercicio: mostrar por pantalla la letra correspondiente a un
// número de DNI dado por teclado.

// Añadimos las librerias que usaremos
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Usaremos cadenas de caracteres
#include <stdio_ext.h> // Usaremos __fpurge()

int main(){
	int ndni=0;
	char dni[10];
	char letras[]="TRWAGMYFPDXBNJZSQVHLCKE";
	
	do{
		system("clear");
		printf("Vamos a calcular la letra de un DNI que me des por teclado.\n");
		printf("¿Que DNI quieres calcular?: ");
		scanf("%s",dni);
		__fpurge(stdin);
	}while(strlen(dni) < 7 || strlen(dni) > 9);
	
	ndni=atoi(dni); // Convertimos a entero el DNI
	ndni=ndni%23; // Calculamos el resto
	
	printf("\nLa letra del DNI %s es %c.",dni,letras[ndni]);
	return 0;
}
