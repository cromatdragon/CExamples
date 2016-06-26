// Ejercicio: aplicar la librería creada en pasos anteriores para hacer
// la llamada a las distintas funciones

#include <stdio.h>
#include <stdlib.h>
#include "libreria_ordenacion.h"

int lista[100];

/// Declaramos los prototipos de las funciones que usaré
// Función para mostrar el resultado de la ordenación
void resultado();
// Función para recoger los datos por teclado
int recoger_datos(int contador);

int main(){
	int opcion=0, total, contador=0;
	
	while(1){ // Bucle infinito
		do{
			system("clear");
			printf("\nElige un método de ordenación\n");
			printf("***********************************\n");
			printf(" 1) - Método de selección\n");
			printf(" 2) - Método de inserción\n");
			printf(" 3) - Método de mezcla\n");
			printf(" 4) - Método cocktail\n");
			printf(" 5) - Método Shell\n");
			printf(" 6) - Método burbuja\n");
			printf(" 0) - Salir del programa\n");
			printf("***********************************\n");
			printf("¿Que opción escoges? ");
			scanf("%d",&opcion);
		}while(opcion > 6);
		
		if (opcion != 0) {
			total=recoger_datos(contador);

			// Mostramos la lista original
			printf("La lista desordenada es:\t");
			for(contador=0; contador<total; contador++){
				printf("%d\t",lista[contador]);
			}
		}
	
		getchar();
		
		switch(opcion){
			case 1:
				selection_sort(lista,total);
				break;
			case 2:
				insertion_sort(lista,total);
				break;
			case 3:
				merge_sort(lista,0,total-1, 100);
				break;
			case 4:
				cocktail_sort(lista,total);
				break;
			case 5:
				shell_sort(lista,total);
				break;
			case 6:
				bubble_sort(lista,total);
				break;
			case 0:
				exit(0);
			}
		resultado(total);
		}
	return 0;
}

// Función para mostrar el resultado de la ordenación
void resultado(int total){
	int contador;
	
	system("clear");
	
	// Mostramos el resultado de la ordenación
	printf("\nLa lista ordenada es:\t");
	for(contador=0; contador<total; contador++){
		printf("%d\t",lista[contador]);
	}

	getchar();
}

// Función para recoger los datos por teclado
int recoger_datos(int contador){
	
	int total;
	
	printf("\n¿Cuantos elementos quieres añadir? ");
	scanf("%d", &total);
	
	// Según la respuesta anterior, pediremos TOTAL números
	printf("Introduce los elementos del vector.\n");
	for(contador=0; contador<total; contador++){
		scanf("%d",&lista[contador]);
	}
	
	return total;
}
