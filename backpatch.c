#include <stdlib.h>
#include "backpatch.h"
#include "cuadruplas.h"

/*
 * Fecha: 13/06/2020
 * Autor: VMCR
 * Descripci�n: Declaraci�n de funciones para generar el backpatch
 * Modificaci�n:
 * Modific�:
 */

INDEX *init_index(){
	INDEX *indice = (INDEX*) malloc(sizeof(INDEX));
	indice->indice = '\0';
	indice->next = NULL;
	return indice;
} // Reserva memoria para un nodo de �ndice


void finish_index(INDEX *i){
	free(i);
} // Libera la memoria de un nodo �ndice


LINDEX *init_list_index(INDEX *i){
	LINDEX *lista_indices = (LINDEX*) malloc(sizeof(LINDEX));
	lista_indices->head = NULL;
	lista_indices->tail = NULL;
	append_index(lista_indices, i);
	return lista_indices;
} // Reserva memoria para la lista de �ndices e inserta el primero


void finish_list_index(LINDEX *l){
	INDEX actual = l->head;
	INDEX actual_next;
	while(actual != NULL){
		actual_next = actual->next;
		free(actual);
		actual = actual_next;
	}
	free(actual);
	free(actual_next);
	free(l);
} // Libera la memoria de la lista y de todos los nodos dentro


void append_index(LINDEX *l, INDEX *i){
	if(l->head == NULL){ // Si cod est� vac�a
		l->head = i; // Todav�a no hay tail, el next de head sigue siendo nulo
		l->head->next = NULL;
	}
	else{
		if(l->tail == NULL){ // Si hay un elemento en la tabla
			l->tail = i; // El nuevo se convierte en tail
			l->head->next = l->tail; // El nuevo elemento es el siguiente del que hab�a
			l->tail->next = NULL;
		}
		else{
			INDEX *current = l->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != l->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			INDEX *copy = l->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			l->tail = i; // Ahora el �ltimo ser� el s�mbolo nuevo
			copy->next = l->tail; // El siguiente del que era tail es el valor nuevo
			l->tail->next = NULL;
		}
	}
} // Agrega un nodo �ndice al final de la lista


LINDEX *combinar(LINDEX l1, LINDEX l2){
	LINDEX *merge = (LINDEX*) malloc(sizeof(LINDEX)); // Se crea una lista de �ndices vac�a
	merge->head = NULL;
	merge->tail = NULL;
	
	INDEX actual = l1->head; // Primero se recorre la primera lista
	while(actual != NULL){ // Se recorre hasta llegar a un nodo nulo
		append_index(merge, actual); // Se a�ade el nodo actual a la lista merge
		actual = actual->next; // Se avanza al siguiente nodo
	}
	
	INDEX actual = l2->head; // Ahora se recorre la segunda lista
	while(actual->next != NULL){ // Se recorre hasta llegar a un nodo nulo
		append_index(merge, actual); // Se a�ade el nodo a la lista merge
		actual = actual->next; // Se avanza al siguiente nodo
	}
} // Retorna una lista ligada de la concatenaci�n de l1 con l2


// Comparamos code->elemento->res con el atributo char llamado �ndice de cada elemento de la lista de �ndices
// Si son iguales, sustituimos en code->elemento->res por el label
void backpatch(CODE *cod, LINDEX l, char *label){
	CUAD *quad_actual = cod->head; // Tomamos la primer cu�drupla de code
	INDEX *index_actual; // Creamos un �ndice
	
	while(quad_actual != NULL){ // Recorremos todas las cu�druplas
		index_actual = l->head; // Por cada cu�drupla volvemos a comparar desde el head de la lista de �ndices
		
		while(index_actual != NULL){ // Cada cu�drupla se compara con todos los �ndices de la lista
			
			if(strcmp(quad_actual->res, index_actual->indice) == 0){ // Si res es igual al �ndice
                strcpy(quad_actual->res, label); // Sustituye res por label
			}
			
			index_actual = index_actual->next; // Avanzamos al siguiente �ndice para comparar con la misma cu�drupla
		}
		
		quad_actual = quad_actual->next; // Avanzamos a la siguiente cu�drupla
	}
} // Reemplaza label en cada aparici�n de un �ndice en las cu�druplas del c�digo c
