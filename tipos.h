#ifndef TIPOS_H
#define TIPOS_H
#include "cuadruplas.h"

/*
 * Fecha: 14/06/2020
 * Autor: VMCR
 * Descripción: Prototipos de funciones para implementar operaciones con tipos
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
char *ampliar (char *dir, int t1, int t2, CODE *c);


/*
 * Recibe dos tipos, cada uno es su índice hacia la tabla de tipos en la cima de la pila
 * Si el primero es más grande que el segundo, genera la cuádrupla
 * para realizar la reducción del tipo.
 * Retorna la nueva dirección generada por la reducción
 * o la dirección original en caso de que no se realice
 */
char *reducir();


/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de mayor dimensión
 */
int max(int t1, int t2);


/*
 * Recibe dos tipos, cada uno es índice hacia la tabla de tipos en la cima de la pila
 * retorna el índice de menor dimensión
 */
int min(int t1, int t2);


#endif
