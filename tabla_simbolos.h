# ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Prototipos de funciones para las tablas y pilas de símbolos
 * Modificación: 21/06/2020 Se añadió el prototipo de la función que permite ingresar argumentos a un símbolo
 * Modificó: VMCR
 */

void append_sym(SYMTAB *ts, TYPTAB *tt, SYM *s); //Agrega al final de la tabla un nuevo símbolo

void clear_sym_tab (SYMTAB *tablaSim); // Deja vacía la tabla

SYMTAB *pop_st(SSTACK *stack); // Ejecuta un pop sobre la pila de tablas de símbolos

void push_st(SSTACK *stack, SYMTAB *tablaSim); // Ingresa una tabla a la pila de tablas de símbolos

SSTACK *init_sym_tab_stack(); // Reserva memoria para la pila

SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de símbolos vacía

SYM *init_sym(); // Reserva memoria para un símbolo vacío

ARGS *init_args(); // Reserva memoria para una lista de argumentos

ARG *init_arg(int arg); // Reserva memoria para un argumento y le asigna su valor

void finish_sym_tab_stack(SSTACK *stackSim); // Libera la memoria para la pila

void finish_sym_tab(SYMTAB *tablaSim); // Libera memoria para una tabla de símbolos

void finish_sym(SYM *simbolo); // Libera memoria para un símbolo vacío

void print_sym_tab(SYMTAB *tablaSim); // Imprime en pantalla la tabla de símbolos

void *add_args_sym(SYM *simbolo, int arg); // Añade un argumento al símbolo indicado

SYMTAB *get_global_sym_tab(SSTACK *stack); // Regresa la tabla del fondo de la pila de tablas de símbolos

SYM *get_sym(SYMTAB *tablaSim, char *id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

int get_dir(SYMTAB *tablaSim, char *id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

int sym_id_exists(SYMTAB *tablaSim, char *id); // Busca un ID entre los símbolos, regresa 0 si lo encuentra, -1 si no


#endif
