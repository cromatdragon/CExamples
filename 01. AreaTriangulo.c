// Ejercicio: Este ejercicio nos pide calcular el área de un triángulo.
// Debemos pedir por pantalla los datos necesarios, aplicar la ecuación
// y mostrar el resultado de la misma por pantalla, sabiendo que la
// ecuación para calcular el área de un triángulo es base * altura / 2

// Añadimos la libreria que usaremos
#include <stdio.h>
 
// Declaramos como float tres variables globales
float altura,base,superficie;
 
int main(){
	printf("Este programa calcula el área de un triángulo\n");
	getchar();
	// Pedimos y almacenamos la base
	printf("\nPorfavor, teclea la base del triángulo: ");
	scanf("%f",&base);
	// Pedimos y almacenamos la altura
	printf("\nPorfavor, ahora teclea la altura del triángulo: ");
	scanf("%f",&altura);
	// Aplicamos la fórmula
	superficie=base*altura/2;
	// Mostramos el resultado por pantalla
	printf("\nEl área del triángulo de base %g y de altura %g es %g",base,altura,superficie);
	return 0;
	}
