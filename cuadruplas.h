#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

/*
 * Fecha: 12/06/2020
 * Autor: VMCR
 * Descripción: Estructuras necesarias para la creación de cuádruplas y prototipos de funciones
 * Modificación: 21/06/2020 Se añadió un prototipo de función para imprimir el código
 * Modificó: VMCR
 */

typedef struct cuad CUAD;

struct cuad{
	char *op;
	char *arg1;
	char *arg2;
	char *res;
	CUAD *next;
};


typedef struct code CODE;

struct code{
	CUAD *head;
	CUAD *tail;
};


CUAD *init_quad(); // Reserva memoria para una cuádrupla

void finish_quad(CUAD *c); // Libera la memoria de una cuádrupla

CODE *init_code(); // Reserva memoria para el código

void finish_code(CODE *c); // Libera la memoria de la lista ligada del código

void append_quad(CODE *c, CUAD *cd); // Agrega una cuádrupla al final de la lista

void print_code(CODE *c); // Imprime las cuádruplas contenidas dentro del código c


#endif
