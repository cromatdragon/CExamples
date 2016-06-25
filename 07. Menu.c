// Ejemplo de un menú

// Llamada a las librerias que vamos a utilizar
#include <stdio.h>
#include <stdlib.h> 
 
int main(){
	int opcion=0;
	
	while(1){ // Bucle infinito
		do{
			system("clear");
			printf("Elige una opción\n");
			printf("***********************************\n");
			printf(" 1) - Sumar dos números\n");
			printf(" 2) - Restar dos números\n");
			printf(" 3) - Dividir dos números\n");
			printf(" 4) - Multiplicar dos números\n");
			printf(" 0) - Salir del programa\n");
			printf("***********************************\n");
			printf("¿Que opción escoges? ");
			scanf("%d",&opcion);
		}while(opcion > 4);
		
		switch(opcion){
			case 1:
				system("clear");
				printf("Lanzaríamos la llamada a una función que sumara.\n");
				getchar();getchar();
				break;
			case 2:
				system("clear");
				printf("Lanzaríamos la llamada a una función que restara.\n");
				getchar();getchar();
				break;
			case 3:
				system("clear");
				printf("Lanzaríamos la llamada a una función que dividiera.\n");
				getchar();getchar();
				break;
			case 4:
				system("clear");
				printf("Lanzaríamos la llamada a una función que multiplicara.\n");
				getchar();getchar();
				break;
			case 0:
				exit(0);
			default:
				system("clear");
				printf("Ha ocurrido un error en las opciones del menú.\n");
				exit(1);
			}
	}
	return 0;
}
