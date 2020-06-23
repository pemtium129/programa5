#ifndef TYPTAB_H
#define TYPTAB_H
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Prototipos de funciones para las tablas y pilas de tipos
 * Modificación: 21/06/2020 Se añadió un prototipo de función para obtener el tamaño de un tipo e ingresar el tipo de una estructura
 * Modificó: VMCR
 */

void append_type(TYPTAB *tablaTipos, TYP *tipo); //Agrega al final de la tabla un nuevo tipo

void clear_type_tab(TYPTAB *tablaTipos); // Deja vacía la tabla

TYPTAB *pop_tt(TSTACK *stack); // Ejecuta un pop sobre la pila de tablas de tipos

void push_tt(TSTACK *stack, TYPTAB *tablaTipos); // Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); // Reserva memoria para la pila

TYPTAB *init_type_tab(); // Reserva memoria para una tabla de tipos e inserta los tipos nativos

TYP *init_type(); // Reserva memoria para un tipo

TYPTAB *get_top_Tstack(TSTACK *stack); // Regresa la tabla de la cima de la pila de tablas de tipos

void finish_type_tab_stack(TSTACK *stack); // Libera la memoria para la pila

void finish_type_tab(TYPTAB *tablaTipos); // Libera memoria para una tabla de tipos

void finish_type(TYP *tipo); // Libera memoria para un tipo

void print_type_tab(TYPTAB *tablaTipos); // Imprime en pantalla la tabla de tipos

int get_size(TYPTAB *tablaTipos, int id); // Obtiene el tamaño de un tipo, es útil para ingresar símbolos en la TS

void set_tb_struct(TYP *tipo, int tb); // Se usa para ingresar el tipo base de una estructura

TYPTAB *get_global_type_tab(TSTACK *stack); // Regresa la tabla del fondo de la pila de tablas de tipos

TYP *get_type(TYPTAB *tablaTipos, int id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

char *get_name_type(TYP *tipo); // Busca el nombre del tipo especificado

TB *get_tb(TYPTAB *tablaTipos, int id); // Busca el tipo base de un tipo


#endif
