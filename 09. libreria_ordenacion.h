// Librería con los seis algoritmos de ordenación usados en el blog
// blog.cromat-dragon.net by CromatDragon

void merge_sort(int *listado, int inicio, int final, int SIZE){
	if(inicio<final){ 
		int medio=(inicio+final)/2; // Localizamos el centro del vector
		// Aplicamos la técnica divide y vencerás
		merge_sort(listado, inicio, medio, SIZE);
		merge_sort(listado, medio +1, final, SIZE);
		// Combinamos ambas listas ordenadas

		// Tres contadores, y dos indices
		int iTemp1=medio-inicio+1, iTemp2=final-medio, c1, c2, c3;
		// Dos vectores para usar en la mezcla
		int temp1[SIZE/2], temp2[SIZE/2];
	
		for(c1=0; c1<iTemp1; c1++){
			temp1[c1]=listado[inicio+c1];
		}
		for(c2=0; c2<iTemp2; c2++){
			temp2[c2]=listado[medio+c2+1];
		}
		
		// Añadimos un "marcador" muy alto como último registro
		temp1[c1]=SIZE*SIZE;
		temp2[c2]=SIZE*SIZE;
		
		c1=c2=0;
		
		// Combinamos los dos vectores ordenados
		for(c3=inicio; c3<=final; c3++){
			if(temp1[c1]<=temp2[c2]){
				listado[c3]=temp1[c1++];
			}else{
				listado[c3]=temp2[c2++];
			}
		}
	}
}

// Función que aplica el algoritmo de inserción
void insertion_sort(int *lista, int total){
	int primero,segundo,indice;

	for (primero = 1 ; primero <= total - 1; primero++) {
		segundo = primero;
 
		while ( segundo > 0 && lista[segundo] < lista[segundo-1]) {
			indice = lista[segundo];
			lista[segundo] = lista[segundo-1];
			lista[segundo-1] = indice;
			segundo--;
			}
	}
}

// Función que aplica el algoritmo de selección
void selection_sort(int *lista, int total){
	int primero, segundo, menor, temporal;
	
	for(primero = 0 ; primero < ( total - 1 ) ; primero++){
		menor = primero;
 
		for(segundo = primero + 1 ; segundo < total ; segundo++){
			if(lista[menor] > lista[segundo])
				menor = segundo;
			}
		if(menor != primero){
			temporal = lista[primero];
			lista[primero] = lista[menor];
			lista[menor] = temporal;
			}
		}
}

// Función que aplica el algoritmo shellsort
void shell_sort(int *listado, int total){
    int cont, cont1, cont2, tmp;
    for (cont = total; cont /= 2;) {
        for (cont1 = cont; cont1 < total; cont1++) {
            tmp = listado[cont1];
            for (cont2 = cont1; cont2 >= cont && tmp < listado[cont2 - cont]; cont2 -= cont) {
                listado[cont2] = listado[cont2 - cont];
            }
            listado[cont2] = tmp;
        }
    }
}

// Función que aplica el algoritmo burbuja
void bubble_sort(int *listado, int total){
    int contador, tmp, flag = 1;
    while (flag) {
        flag = 0;
        for (contador = 1; contador < total; contador++) {
            if (listado[contador] < listado[contador-1]) {
                tmp = listado[contador];
                listado[contador] = listado[contador-1];
                listado[contador-1] = tmp;
                flag = 1;
            }
        }
    }
}

// Función que aplica el algoritmo cocktail
void cocktail_sort(int *listado, int total){
	int flag=0, inicio=0, final=total-1,temporal=0,contador=0;
	
	while(flag == 0 && inicio < final){
		flag=1;
		// Ordenamiento de izquierda a derecha
		for(contador=inicio; contador<final; contador++){
			if(listado[contador] > listado[contador+1]){
				temporal=listado[contador];
				listado[contador]=listado[contador+1];
				listado[contador+1]=temporal;
				flag=0;
				}
			}
		}
		
		final=final-1;
		// Ordenamiento de derecha a izquierda
		for(contador=final; contador>inicio; contador--){
			if(listado[contador] < listado[contador-1]){
				temporal=listado[contador];
				listado[contador]=listado[contador-1];
				listado[contador-1]=temporal;
				flag=0;
			}
		}
		inicio=inicio+1;
	}
