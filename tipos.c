#include "tipos.h"
#include "tabla_tipos.c"

/*
 * Fecha: 14/06/2020
 * Autor: VMCR
 * Descripci�n: Declaraci�n de funciones para implementar operaciones con tipos
 * Modificaci�n:
 * Modific�:
 */


/*
 * Recibe dos tipos, cada uno es su �ndice hacia la tabla de tipos en la cima de la pila
 * Si el primero es m�s chico que el segundo, genera la cu�drupla
 * para realizar la ampliaci�n del tipo.
 * Retorna la nueva direcci�n generada por la ampliaci�n
 * o la direcci�n original en caso de que no se realice
 */
char *ampliar (char *dir, int t1, int t2, CODE *c, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, funci�n declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t1
	TYP *busq2 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t2
	int tam1; // Tendr� el tama�o de t1
	int tam2; // Tendr� el tama�o de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tama�o
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tama�o
			}
		busq2 = busq2->next;
	}
	
	if(tam1 < tam2){ // Si el primero es m�s chico que el segundo se genera la cu�drupla para realizar la ampliaci�n del tipo
		CUAD *quad_nueva = init_quad();
		char *nuevaDir = dir + tam1;
		return nuevaDir;
	}
	else{ // No hubo ampliaci�n
		return dir; // Se retorna la direcci�n original
	}
}


/*Creo la tupla y la a�ado al c�digo pero la regreso vac�a*/


/*
 *Recibe dos tipos, cada uno es su �ndice hacia la tabla de tipos en la cima de la pila
 * Si el primero es m�s grande que el segundo, genera la cu�drupla
 * para realizar la reducci�n del tipo.
 * Retorna la nueva direcci�n generada por la reducci�n
 * o la direcci�n original en caso de que no se realice
 */
char *reducir(){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, funci�n declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t1
	TYP *busq2 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t2
	int tam1; // Tendr� el tama�o de t1
	int tam2; // Tendr� el tama�o de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tama�o
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tama�o
			}
		busq2 = busq2->next;
	}
	
	if(tam1 > tam2){ // Si el primero es m�s grande que el segundo se genera la cu�drupla para realizar la reducci�n del tipo
		CUAD *quad_nueva = init_quad();
		char *nuevaDir = dir + tam1;
	}
	else{ // No hubo reducci�n
		return dir; // Se regresa la direcci�n original
	}
}


/*
 * Recibe dos tipos, cada uno es �ndice hacia la tabla de tipos en la cima de la pila
 * retorna el �ndice de mayor dimensi�n
 */
int max(int t1, int t2, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, funci�n declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t1
	TYP *busq2 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t2
	int tam1; // Tendr� el tama�o de t1
	int tam2; // Tendr� el tama�o de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tama�o
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tama�o
			}
		busq2 = busq2->next;
	}
	
	if(tam1 > tam2){ // Se comparan los valores para saber cu�l devolver
		return t1; // Se devuelve t1 porque result� ser de mayor tama�o
	}
	else{ // t2 fue de mayor tama�o
		return t2;
	}
}


/*
 * Recibe dos tipos, cada uno es �ndice hacia la tabla de tipos en la cima de la pila
 * retorna el �ndice de menor dimensi�n
 */
int min(int t1, int t2, TSTACK *stack){
	TYPTAB *cima = get_top_Tstack(stack); // Se obtiene la tabla de la cima de la pila, funci�n declarada en tabla_tipos.c
	TYP *busq1 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t1
	TYP *busq2 = cima->head; // Se recorrer�n los tipos hasta encontrar el que tenga el �ndice t2
	int tam1; // Tendr� el tama�o de t1
	int tam2; // Tendr� el tama�o de t2
	
	while(busq1 != NULL){ // Primero se busca para t1
		if(busq1->id == t1){ // Si coinciden
                tam1 = busq1->tam; // Se obtiene el tama�o
			}
		busq1 = busq1->next;
	}
	
	while(busq2 != NULL){ // Luego se busca para t2
		if(busq2->id == t2){ // Si coinciden
                tam2 = busq2->tam; // Obtenemos el tama�o
			}
		busq2 = busq2->next;
	}
	
	if(tam1 < tam2){ // Se comparan los valores para saber cu�l devolver
		return t1; // Se devuelve t1 porque result� ser de menor tama�o
	}
	else{ // t2 fue de menor tama�o
		return t2;
	}
}
