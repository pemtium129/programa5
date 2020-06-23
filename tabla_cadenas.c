#include <string.h>
#include "tabla_cadenas.h"

/*
 * Fecha: 22/06/2020
 * Autor: VMCR
 * Descripción: Definición de funciones para la tabla de cadenas
 * Modificación:
 * Modificó:
 */

void append_string(STRTAB *tablaCadenas, STR *cadena){
	if(tablaCadenas->head == NULL){ // Si la tabla está vacía
		tablaCadenas->head = cadena; // Todavía no hay tail, el next de head sigue siendo nulo
		tablaCadenas->head->next = NULL;
	}
	else{
		if(tablaCadenas->tail == NULL){ // Si hay un elemento en la tabla
			tablaCadenas->tail = cadena; // El nuevo se convierte en tail
			tablaCadenas->head->next = cod->tail; // El nuevo elemento es el siguiente del que había
			tablaCadenas->tail->next = NULL;
		}
		else{
			char *current = tablaCadenas->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaCadenas->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			char *copy = tablaCadenas->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			tablaCadenas->tail = cadena; // Ahora el último será la cadena nueva
			copy->next = tablaCadenas->tail; // El siguiente del que era tail es el valor nuevo
			tablaCadenas->tail->next = NULL;
		}
	}
} // Agrega al final de la tabla una cadena


int string_exists(STRTAB *tablaCadenas, char *str){
	STR *current = tablaCadenas->head;
	while(current != NULL){
		if(strcmp(current->cadena, str) == 0){
			return 0;
		}
		current = current->next;
	}
	return -1; // Si no lo encuentra, regresa -1
} // Busca una cadena en la tabla de cadenas, regresa 0 si la encuentra, -1 si no


INDEX get_index_string(STRTAB *tablaCadenas, char *str){
	STR *current = tablaCadenas->head;
	while(current != NULL){
		if(strcmp(current->cadena, str) == 0){
			return current->indice;
		}
		current = current->next;
	}
	return NULL; // Si no lo encuentra, regresa nulo
} // Devuelve el índice de una cadena dentro de la tabla
