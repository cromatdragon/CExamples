// Ejercicio: Crear un programa que pueda leer y escribir contenido en
// un fichero

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> // Usaremos __fpurge(stdin)
#include <string.h> // Usaremos strlen()
 
int main(){
	FILE *puntero; // Declaramos el puntero de referencia al archivo
    int opcion;
    char linea[100];
 
    while(1){ // Bucle infinito
        do{ // Menú de opciones
            system("clear");
			printf("1) - Añadir contenido al fichero\n");
			printf("2) - Leer el contenido del fichero\n");
			printf("0) - Salir del programa\n");
			printf("\n¿Que quieres hacer?\t");
			scanf("%d",&opcion);
			__fpurge(stdin);
			}while(opcion > 2);

		switch(opcion){
			case 0: // Opción para salir del programa
				printf("\n\nSaliendo del programa.");
				exit(0);
				break;
			case 1: // Opción para añadir datos al fichero
				if((puntero=fopen("fichero_test.txt","a+"))==NULL){
					printf("Se ha producido un error al intentar abrir o crear el fichero en modo escritura\n");
					exit(1);
				}else{
					printf("\nEscribe lo que quieras y pulsa la tencla ENTER para añadir al fichero\n");
					scanf("%[^\n]s",linea);
					__fpurge(stdin);
					fputs(linea,puntero);
					fclose(puntero);
				}
				break;
			case 2: // Opción para leer datos del fichero
				if((puntero=fopen("fichero_test.txt","r"))==NULL){
					printf("Se ha producido un error al intentar leer el fichero\n");
					exit(1);
				}else{
					system("clear");
					printf("Esto es lo que continene el archivo:\n\n");
					while(!feof(puntero) || ferror(puntero)){
						fputc(fgetc(puntero), stdout);
						}
					getchar();
					fclose(puntero);
				}
				break;
			default:
				fclose(puntero); // Cerramos el fichero
				printf("\n\nSe ha producido un error en las opciones.");
				exit(1);
				break;
			}
		}
	return 0;
}
