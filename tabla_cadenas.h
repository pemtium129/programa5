#ifndef STRINGTAB_H
#define STRINGTAB_H
#include "backpatch.h"

/*
 * Fecha: 22/06/2020
 * Autor: VMCR
 * Descripción: Definición de estructuras y prototipos para la tabla de cadenas
 * Modificación:
 * Modificó:
 */

typedef struct string STR;

struct string{
    char *cadena;
    INDEX indice;
    STR *next;
};


typedef struct string_tab STRTAB;

struct string_tab{
    STR *head;
    STR *tail;
    STRTAB *next;
};


void append_string(STRTAB *tablaCadenas, char *cadena); // Agrega al final de la tabla una cadena

int string_exists(STRTAB *tablaCadenas, char *cadena); // Busca una cadena en la tabla de cadenas, regresa 0 si la encuentra, -1 si no

INDEX get_index_string(STRTAB *tablaCadenas, char *cadena); // Devuelve el índice de una cadena dentro de la tabla


#endif
