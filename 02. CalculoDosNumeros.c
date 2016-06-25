// Ejercicio: Debemos pedir dos números por teclado, realizando la suma,
// resta, multiplicación y división mostrando el resultado por la pantalla.
// No podemos ingresar número negativos.

// Añadimos las librerías que usaremos
#include <stdio.h>
#include <stdlib.h>
 
// Declaramos como float dos variables globales
float n1,n2;
 
int main(){
	printf("Calcular la suma, resta, multiplicación y división");
	printf(" de dos números dados por teclado.");
	getchar();
 
	do{// Validación del primer número
		system("clear");
		printf("Introduce el primer número que no sea negativo: ");
		scanf("%f",&n1);
	}while(n1<0);
 
	do{// Validación del segundo número
		system("clear");
		printf("Introduce el segundo número que no sea negativo: ");
		scanf("%f",&n2);
	}while(n2<0);
 
	// Calculamos la suma
	printf("\nLa suma de %g y %g es %g \n",n1,n2,n1+n2);
	// Calculamos la resta
	printf("La resta de %g y %g es %g \n",n1,n2,n1-n2);
	// Calculamos la multiplicación
	printf("La multiplicación de %g y %g es %g \n",n1,n2,n1*n2);
	// Calculamos la división
	printf("La división de %g y %g es %g \n",n1,n2,n1/n2);
 
	return 0;
}
