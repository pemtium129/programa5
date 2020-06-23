#ifndef TIPOS_H
#define TIPOS_H
#include "cuadruplas.h"

/*
 * Fecha: 14/06/2020
 * Autor: VMCR
 * Descripci�n: Prototipos de funciones para implementar operaciones con tipos
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
char *ampliar (char *dir, int t1, int t2, CODE *c);


/*
 * Recibe dos tipos, cada uno es su �ndice hacia la tabla de tipos en la cima de la pila
 * Si el primero es m�s grande que el segundo, genera la cu�drupla
 * para realizar la reducci�n del tipo.
 * Retorna la nueva direcci�n generada por la reducci�n
 * o la direcci�n original en caso de que no se realice
 */
char *reducir();


/*
 * Recibe dos tipos, cada uno es �ndice hacia la tabla de tipos en la cima de la pila
 * retorna el �ndice de mayor dimensi�n
 */
int max(int t1, int t2);


/*
 * Recibe dos tipos, cada uno es �ndice hacia la tabla de tipos en la cima de la pila
 * retorna el �ndice de menor dimensi�n
 */
int min(int t1, int t2);


#endif
