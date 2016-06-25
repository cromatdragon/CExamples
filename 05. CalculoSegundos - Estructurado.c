// Ejercicio: En este ejercicio, debemos ingresar un número en segundos, 
// y nos calculará el total de horas, minutos y segundos que lo componen.
// Sabemos que 1 hora son 60 minutos, y cada minuto, 60 segundos.

// Añadimos las librerías que usaremos
#include <stdio.h>
#include <stdlib.h>
 
int main(){
	int segundos; // Declaramos una variable como entero
	
	// Mostramos el enunciado
	printf("Dados los segundos por teclado, calcular cuantas horas segundos y minutos representan");
	getchar();
	
	do{// Nos aseguramos tener el valor correcto
		system("clear");
		printf("\n¿Cuantos segundos quieres calcular?: ");
		scanf("%d",&segundos);
	}while(segundos < 1);
	
	system("clear");
	
	// Calculamos y mostramos el resultado
	printf("%d segundos son:\n\n%d horas\n",segundos,segundos/3600);
	printf("%d minutos\n",(segundos%3600)/60);
	printf("%d segundos",(segundos%3600)%60);
	
	return 0;
}
