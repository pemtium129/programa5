#include <stdlib.h>
#include "backpatch.h"
#include "cuadruplas.h"

/*
 * Fecha: 13/06/2020
 * Autor: VMCR
 * Descripción: Declaración de funciones para generar el backpatch
 * Modificación:
 * Modificó:
 */

INDEX *init_index(){
	INDEX *indice = (INDEX*) malloc(sizeof(INDEX));
	indice->indice = '\0';
	indice->next = NULL;
	return indice;
} // Reserva memoria para un nodo de índice


void finish_index(INDEX *i){
	free(i);
} // Libera la memoria de un nodo índice


LINDEX *init_list_index(INDEX *i){
	LINDEX *lista_indices = (LINDEX*) malloc(sizeof(LINDEX));
	lista_indices->head = NULL;
	lista_indices->tail = NULL;
	append_index(lista_indices, i);
	return lista_indices;
} // Reserva memoria para la lista de índices e inserta el primero


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
	if(l->head == NULL){ // Si cod está vacía
		l->head = i; // Todavía no hay tail, el next de head sigue siendo nulo
		l->head->next = NULL;
	}
	else{
		if(l->tail == NULL){ // Si hay un elemento en la tabla
			l->tail = i; // El nuevo se convierte en tail
			l->head->next = l->tail; // El nuevo elemento es el siguiente del que había
			l->tail->next = NULL;
		}
		else{
			INDEX *current = l->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != l->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			INDEX *copy = l->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			l->tail = i; // Ahora el último será el símbolo nuevo
			copy->next = l->tail; // El siguiente del que era tail es el valor nuevo
			l->tail->next = NULL;
		}
	}
} // Agrega un nodo índice al final de la lista


LINDEX *combinar(LINDEX l1, LINDEX l2){
	LINDEX *merge = (LINDEX*) malloc(sizeof(LINDEX)); // Se crea una lista de índices vacía
	merge->head = NULL;
	merge->tail = NULL;
	
	INDEX actual = l1->head; // Primero se recorre la primera lista
	while(actual != NULL){ // Se recorre hasta llegar a un nodo nulo
		append_index(merge, actual); // Se añade el nodo actual a la lista merge
		actual = actual->next; // Se avanza al siguiente nodo
	}
	
	INDEX actual = l2->head; // Ahora se recorre la segunda lista
	while(actual->next != NULL){ // Se recorre hasta llegar a un nodo nulo
		append_index(merge, actual); // Se añade el nodo a la lista merge
		actual = actual->next; // Se avanza al siguiente nodo
	}
} // Retorna una lista ligada de la concatenación de l1 con l2


// Comparamos code->elemento->res con el atributo char llamado índice de cada elemento de la lista de índices
// Si son iguales, sustituimos en code->elemento->res por el label
void backpatch(CODE *cod, LINDEX l, char *label){
	CUAD *quad_actual = cod->head; // Tomamos la primer cuádrupla de code
	INDEX *index_actual; // Creamos un índice
	
	while(quad_actual != NULL){ // Recorremos todas las cuádruplas
		index_actual = l->head; // Por cada cuádrupla volvemos a comparar desde el head de la lista de índices
		
		while(index_actual != NULL){ // Cada cuádrupla se compara con todos los índices de la lista
			
			if(strcmp(quad_actual->res, index_actual->indice) == 0){ // Si res es igual al índice
                strcpy(quad_actual->res, label); // Sustituye res por label
			}
			
			index_actual = index_actual->next; // Avanzamos al siguiente índice para comparar con la misma cuádrupla
		}
		
		quad_actual = quad_actual->next; // Avanzamos a la siguiente cuádrupla
	}
} // Reemplaza label en cada aparición de un índice en las cuádruplas del código c
