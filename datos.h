#ifndef DATOS_H
#define DATOS_H

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Estructuras para las tablas y pilas de s�mbolos, y tablas y pilas de tipos
 * Modificaci�n:
 * Modific�:
 */

typedef struct arg ARG;

struct arg{
    int arg;
    ARG *next;
};


typedef struct args ARGS;

struct args{
    ARG *head;
    ARG *tail;
    int num; // N�mero de elementos en la lista
};


typedef struct sym SYM;

struct sym{
    int dir; // Direcci�n para la variable
    int tipo; // Tipo como �ndice a la tabla de tipos
    char id[33]; // Identificador
    ARGS *args ; // Lista de argumentos
    int num; // N�mero de argumentos
    int var; // Tipo de variable
    SYM *next; // Apuntador al siguiente s�mbolo
};


typedef struct sym_tab SYMTAB;

struct sym_tab{
    SYM *head;
    SYM *tail;
    int num; //N�mero de elementos en la tabla
    SYMTAB *next; //Apuntador a la tabla siguiente
};


typedef struct sym_stack SSTACK;

struct sym_stack{
    SYMTAB *top;
    SYMTAB *tail;
};


typedef struct tipobase TB;

struct tipobase{
    int is_est; // 1:si es estructura  0:si es tipo simple  -1:si no tiene tipo base
    union{
    SYMTAB *est;
    int tipo;
    } tipo;
};


typedef struct type TYP;

struct type{
    int id;
    char nombre [12];
    TB tb;
    int tam;
    TYP *next; //Apuntador al siguiente tipo en la tabla de tipos
};


typedef struct type_tab TYPTAB;

struct type_tab{
    TYP *head;
    TYP *tail;
    int num; //Contador de elementos en la tabla
    TYPTAB *next; //Apuntador a la tabla siguiente
};


typedef struct typ_stack TSTACK;

struct typ_stack{
    TYPTAB *top;
    TYPTAB *tail;
};


#endif
