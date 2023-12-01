#include "vector_enteros.h"
#include <stdlib.h>

struct vector_enteros *vector_enteros_crear()
{	
		struct vector_enteros* vector = malloc(sizeof(struct vector_enteros));
				if (!vector){
						return NULL;
				}

		vector->enteros = malloc(0);
				if (!vector->enteros){
						return NULL;
				}

		vector->cantidad = 0;
		return vector;
}

struct vector_enteros *
vector_enteros_agregar_elemento(struct vector_enteros *vector, int nuevo)
{
		if (!vector){
			return NULL;
		}

		int *nuevo_enteros = realloc(vector->enteros, sizeof(int)*((size_t)vector->cantidad+1));
				if (!nuevo_enteros){
						return NULL;
				}   
	
		vector->enteros = nuevo_enteros;
		vector->enteros[vector->cantidad] = nuevo;
		vector->cantidad++;
		return vector;
}

int vector_enteros_obtener_elemento(struct vector_enteros *vector, int posición)
{
		if (!vector){
			return 0;
		}

		if (posición >= vector->cantidad || posición < 0){
				return 0;
		}

		return vector->enteros[posición];
}

int vector_enteros_modificar_elemento(struct vector_enteros *vector,
				      int posición, int nuevo_valor)
{		
		if (!vector){
			return 0;
		}

		if (posición >= vector->cantidad || posición < 0){
				return 0;
		}

		return vector->enteros[posición] = nuevo_valor;
}

int vector_enteros_tamaño(struct vector_enteros *vector)
{			
		if (!vector){
			return 0;
		}

		return vector->cantidad;
}

void vector_enteros_destruir(struct vector_enteros *vector)
{	
		free(vector->enteros);
		free(vector);
}
