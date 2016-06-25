// Ejercicio: este ejercicio nos pide que, dados tres número positivos
// por teclado, averigüemos cual es el mayor, el menor y el mediano.

// Añadimos las librerías que usaremos
#include <stdio.h>
#include <stdlib.h>

int main(){

	// Declaramos como float seis variables
	float n1,n2,n3,mayor,mediano,pequeno;

	printf("Dados tres números positivos por teclado, indicar");
	printf("\n cual es el mayor, el menor y el mediano.");
	getchar();
	
	do{// Validación del primer número
		system("clear");
		printf("\nIntroduce el primer número que no sea negativo: ");
		scanf("%f",&n1);
	}while(n1<0);

	do{// Validación del segundo número
		system("clear");
		printf("\nIntroduce el segundo número que no sea negativo: ");
		scanf("%f",&n2);
	}while(n2<0);
	
	do{// Validación del tercer número
		system("clear");
		printf("\nIntroduce el tercer número que no sea negativo: ");
		scanf("%f",&n3);
	}while(n3<0);

	system("clear");

	if(n1>n2 && n1>n3){// Primera comprobación
		mayor=n1;
		if(n2>n3){mediano=n2,pequeno=n3;}
		else{mediano=n3,pequeno=n2;}
	}else{// Segunda comprobación		
		if(n2>n1 && n2>n3){
			mayor=n2;
			if(n1>n3){mediano=n1,pequeno=n3;}
			else{mediano=n3,pequeno=n1;}
		}else{// Tercera comprobación
			mayor=n3;
			if(n1>n2){mediano=n1,pequeno=n2;}
			else{mediano=n2,pequeno=n1;}
			}
	}
	// Mostramos el resultado final
	printf("\nEl mayor es %g, el mediano es %g y el pequeño es %g",mayor,mediano,pequeno);
	return 0;
}
