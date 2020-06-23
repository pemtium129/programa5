#include "tipos.h"
#include "tabla_tipos.c"

/*
 * Fecha: 14/06/2020
 * Autor: VMCR
 * Descripción: Declaración de funciones para implementar operaciones con tipos
 * Modificación:
 * Modificó:
 */


/*
 * Recibe dos tipos, cada uno es su índice hacia la tabla de tipos en la cima de la pila
 * Si el primero es más chico que el segundo, genera la cuádrupla
 * para realizar la ampliación del tipo.
 * Retorna la nueva dirección generada por la ampliación
 * o la dirección original en caso de que no se realice
 */
char *ampliar (char *dir, int t1, int t2, CODE *c, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, función declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t1
	TYP *busq2 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t2
	int tam1; // Tendrá el tamaño de t1
	int tam2; // Tendrá el tamaño de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tamaño
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tamaño
			}
		busq2 = busq2->next;
	}
	
	if(tam1 < tam2){ // Si el primero es más chico que el segundo se genera la cuádrupla para realizar la ampliación del tipo
		CUAD *quad_nueva = init_quad();
		char *nuevaDir = dir + tam1;
		return nuevaDir;
	}
	else{ // No hubo ampliación
		return dir; // Se retorna la dirección original
	}
}


/*Creo la tupla y la añado al código pero la regreso vacía*/


/*
 *Recibe dos tipos, cada uno es su índice hacia la tabla de tipos en la cima de la pila
 * Si el primero es más grande que el segundo, genera la cuádrupla
 * para realizar la reducción del tipo.
 * Retorna la nueva dirección generada por la reducción
 * o la dirección original en caso de que no se realice
 */
char *reducir(){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, función declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t1
	TYP *busq2 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t2
	int tam1; // Tendrá el tamaño de t1
	int tam2; // Tendrá el tamaño de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tamaño
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tamaño
			}
		busq2 = busq2->next;
	}
	
	if(tam1 > tam2){ // Si el primero es más grande que el segundo se genera la cuádrupla para realizar la reducción del tipo
		CUAD *quad_nueva = init_quad();
		char *nuevaDir = dir + tam1;
	}
	else{ // No hubo reducción
		return dir; // Se regresa la dirección original
	}
}


/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de mayor dimensión
 */
int max(int t1, int t2, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, función declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t1
	TYP *busq2 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t2
	int tam1; // Tendrá el tamaño de t1
	int tam2; // Tendrá el tamaño de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tamaño
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tamaño
			}
		busq2 = busq2->next;
	}
	
	if(tam1 > tam2){ // Se comparan los valores para saber cuál devolver
		return t1; // Se devuelve t1 porque resultó ser de mayor tamaño
	}
	else{ // t2 fue de mayor tamaño
		return t2;
	}
}


/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de menor dimensión
 */
int min(int t1, int t2, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, función declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t1
	TYP *busq2 = cima->head; // Se recorrerán los tipos hasta encontrar el que tenga el índice t2
	int tam1; // Tendrá el tamaño de t1
	int tam2; // Tendrá el tamaño de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tamaño
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tamaño
			}
		busq2 = busq2->next;
	}
	
	if(tam1 < tam2){ // Se comparan los valores para saber cuál devolver
		return t1; // Se devuelve t1 porque resultó ser de menor tamaño
	}
	else{ // t2 fue de menor tamaño
		return t2;
	}
}
