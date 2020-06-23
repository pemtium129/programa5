#include <stdlib.h>
#include "cuadruplas.h"

/*
 * Fecha: 12/06/2020
 * Autor: VMCR
 * Descripción: Declaración de funciones para el uso de cuádruplas
 * Modificación: 21/06/2020 Correciones menores, se añadió una función para imprimir el código
 * Modificó: VMCR
 */

CUAD *init_quad(){
	CUAD *quad = (CUAD*) malloc(sizeof(CUAD));
	quad->arg1 = NULL;
	quad->op = NULL;
	quad->arg1 = NULL;
	quad->arg2 = NULL;
	quad->res = NULL;
	quad->next = NULL;
	return quad;
} // Reserva memoria para una cuádrupla


CODE *init_code(){
	CODE *cod = (CODE*) malloc(sizeof(CODE));
	cod->head = NULL;
	cod->tail = NULL;
	return cod;
} // Reserva memoria para el código


void finish_quad(CUAD *cuad){
	free(cuad);
} // Libera la memoria de una cuádrupla


void finish_code(CODE *cod){
	free(cod);
} // Libera la memoria de la lista ligada del código


void append_quad(CODE* cod, CUAD *quad){
	if(cod->head == NULL){ // Si cod está vacía
		cod->head = quad; // Todavía no hay tail, el next de head sigue siendo nulo
		cod->head->next = NULL;
	}
	else{
		if(cod->tail == NULL){ // Si hay un elemento en el código
			cod->tail = quad; // El nuevo se convierte en tail
			cod->head->next = cod->tail; // El nuevo elemento es el siguiente del que había
			cod->tail->next = NULL;
		}
		else{
			CUAD *current = cod->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != cod->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			CUAD *copy = cod->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			cod->tail = quad; // Ahora el último será el símbolo nuevo
			copy->next = cod->tail; // El siguiente del que era tail es el valor nuevo
			cod->tail->next = NULL;
		}
	}
} // Agrega una cuádrupla al final de la lista


void print_code(CODE *c){
	if(c->head == NULL){ // Si la lista está vacía
    	printf("No se generaron elementos de c%cdigo\n\n",162);
    	return;
    }
    else{
    	printf("%8s %8s %8s %8s\n\n","Operador","Arg 1","Arg 2","Resultado");
    	CUAD *actual = code->head;
   		while (actual != NULL) {	// Se recorre la tabla hasta que se terminen las cuádruplas
        	printf("%10c %10c %10c %10c %10c\n\n", actual->op,actual->arg1,actual->arg2,actual->res);
        	actual = actual->next;
   	 	}
   	 	return;
	}
} // Imprime las cuádruplas contenidas dentro del código c
