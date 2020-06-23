# ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Prototipos de funciones para las tablas y pilas de s�mbolos
 * Modificaci�n: 21/06/2020 Se a�adi� el prototipo de la funci�n que permite ingresar argumentos a un s�mbolo
 * Modific�: VMCR
 */

void append_sym(SYMTAB *ts, TYPTAB *tt, SYM *s); //Agrega al final de la tabla un nuevo s�mbolo

void clear_sym_tab (SYMTAB *tablaSim); // Deja vac�a la tabla

SYMTAB *pop_st(SSTACK *stack); // Ejecuta un pop sobre la pila de tablas de s�mbolos

void push_st(SSTACK *stack, SYMTAB *tablaSim); // Ingresa una tabla a la pila de tablas de s�mbolos

SSTACK *init_sym_tab_stack(); // Reserva memoria para la pila

SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de s�mbolos vac�a

SYM *init_sym(); // Reserva memoria para un s�mbolo vac�o

ARGS *init_args(); // Reserva memoria para una lista de argumentos

ARG *init_arg(int arg); // Reserva memoria para un argumento y le asigna su valor

void finish_sym_tab_stack(SSTACK *stackSim); // Libera la memoria para la pila

void finish_sym_tab(SYMTAB *tablaSim); // Libera memoria para una tabla de s�mbolos

void finish_sym(SYM *simbolo); // Libera memoria para un s�mbolo vac�o

void print_sym_tab(SYMTAB *tablaSim); // Imprime en pantalla la tabla de s�mbolos

void *add_args_sym(SYM *simbolo, int arg); // A�ade un argumento al s�mbolo indicado

SYMTAB *get_global_sym_tab(SSTACK *stack); // Regresa la tabla del fondo de la pila de tablas de s�mbolos

SYM *get_sym(SYMTAB *tablaSim, char *id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

int get_dir(SYMTAB *tablaSim, char *id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

int sym_id_exists(SYMTAB *tablaSim, char *id); // Busca un ID entre los s�mbolos, regresa 0 si lo encuentra, -1 si no


#endif
