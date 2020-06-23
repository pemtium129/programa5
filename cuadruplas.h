#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

/*
 * Fecha: 12/06/2020
 * Autor: VMCR
 * Descripci�n: Estructuras necesarias para la creaci�n de cu�druplas y prototipos de funciones
 * Modificaci�n: 21/06/2020 Se a�adi� un prototipo de funci�n para imprimir el c�digo
 * Modific�: VMCR
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


CUAD *init_quad(); // Reserva memoria para una cu�drupla

void finish_quad(CUAD *c); // Libera la memoria de una cu�drupla

CODE *init_code(); // Reserva memoria para el c�digo

void finish_code(CODE *c); // Libera la memoria de la lista ligada del c�digo

void append_quad(CODE *c, CUAD *cd); // Agrega una cu�drupla al final de la lista

void print_code(CODE *c); // Imprime las cu�druplas contenidas dentro del c�digo c


#endif
