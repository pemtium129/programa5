#ifndef TYPTAB_H
#define TYPTAB_H
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Prototipos de funciones para las tablas y pilas de tipos
 * Modificaci�n: 21/06/2020 Se a�adi� un prototipo de funci�n para obtener el tama�o de un tipo e ingresar el tipo de una estructura
 * Modific�: VMCR
 */

void append_type(TYPTAB *tablaTipos, TYP *tipo); //Agrega al final de la tabla un nuevo tipo

void clear_type_tab(TYPTAB *tablaTipos); // Deja vac�a la tabla

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

int get_size(TYPTAB *tablaTipos, int id); // Obtiene el tama�o de un tipo, es �til para ingresar s�mbolos en la TS

void set_tb_struct(TYP *tipo, int tb); // Se usa para ingresar el tipo base de una estructura

TYPTAB *get_global_type_tab(TSTACK *stack); // Regresa la tabla del fondo de la pila de tablas de tipos

TYP *get_type(TYPTAB *tablaTipos, int id); // Busca un tipo con cierto ID y lo regresa si lo encuentra

char *get_name_type(TYP *tipo); // Busca el nombre del tipo especificado

TB *get_tb(TYPTAB *tablaTipos, int id); // Busca el tipo base de un tipo


#endif
