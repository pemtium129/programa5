#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.c"
#include "tabla_tipos.c"

/*
 * Fecha: 15/06/2020
 * Autor: VMCR
 * Descripción: Pruebas para TT  y TS en conjunto
 * Modificación: Se modificó el archivo mainSimbolos.c para que la tabla de tipos trabaje en conjunto con la de símbolos
 * Modificó: VMCR
 */

int main(void){
    printf("Pruebas para la tabla de s%cmbolos y de tipos\n\n",161);
    
    printf("Creando una tabla de tipos\n\n");
    TYPTAB *prueba1 = init_type_tab();
    
    printf("Imprimiendo la tabla creada, se pueden ver sus tipos b%csicos\n\n",160);
    print_type_tab(prueba1);
    
    printf("Creando tres tipos\n\n");
    TYP *tipo1 = init_type();
    TYP *tipo2 = init_type();
    TYP *tipo3 = init_type();
    
	printf("Llenando los tipos\n\n");
    tipo1->id = 0;
    strcpy(tipo1->nombre,"arr1");
    tipo1->tb.is_est = 1;
    tipo1->tam = 8;
    
    tipo2->id = 1;
    strcpy(tipo2->nombre,"arr2");
    tipo2->tb.is_est = 1;
    tipo2->tam = 12;
    
    tipo3->id = 2;
    strcpy(tipo3->nombre,"arr3");
    tipo3->tb.is_est = 1;
    tipo3->tam = 16;
    
    printf("Llenando la tabla 1 con 3 elementos y comprobando si se ingresaron\n\n");
    append_type(prueba1, tipo1);
    printf("Prueba 1: %s\n\n",prueba1->head->next->next->next->next->nombre);
    
    append_type(prueba1, tipo2);
    printf("Prueba 2: %s\n\n",prueba1->head->next->next->next->next->next->nombre);
    
    append_type(prueba1, tipo3);
    printf("Prueba 3: %s\n\n",prueba1->head->next->next->next->next->next->next->nombre);
    
    printf("Imprimiendo la tabla de tipos reci%cn modificada\n\n",130);
    print_type_tab(prueba1);
    
	printf("Creando la pila de tablas de s%cmbolos\n\n",161);
    SSTACK *pilaTS = init_sym_tab_stack();
    
	printf("Creando dos tablas de s%cmbolos\n\n",161);
    SYMTAB *prueba1TS = init_sym_tab();
    SYMTAB *prueba2TS = init_sym_tab();
    
	printf("Creando tres s%cmbolos\n\n",161);
    SYM *sim1 = init_sym();
    SYM *sim2 = init_sym();
    SYM *sim3 = init_sym();
    
	printf("Llenando los s%cmbolos\n\n",161);
    sim1->args = NULL;
	strcpy(sim1->id,"Simbolo 1");
	sim1->tipo = 0; // TIPO INT
	sim1->var = 0;
	
	sim2->args = NULL;
	strcpy(sim2->id,"Simbolo 2");
	sim2->tipo = 2; // TIPO DOUBLE
	sim2->var = 0;
	
	sim3->args = NULL;
	strcpy(sim3->id,"Simbolo 3");
	sim3->tipo = 4; // TIPO ARR1
	sim3->var = 0;
	
    printf("Insertando dos tablas en la pila\n\n");
    push_st(pilaTS, prueba1TS);
    push_st(pilaTS, prueba2TS);
    
	printf("Llenando la tabla de la cima con 3 elementos\n\n");
    append_sym(pilaTS->top, prueba1, sim1);
    append_sym(pilaTS->top, prueba1, sim2);
    append_sym(pilaTS->top, prueba1, sim3);
    
    printf("Imprimiendo el n%cmero de elementos de la tabla de la cima: %d\n\n",163,pilaTS->top->num);
    
	printf("Imprimiendo la tabla de la cima\n\n");
    print_sym_tab(pilaTS->top);
    
	printf("Sacando las tablas de la pila\n\n");
	SYMTAB *prueba1pop = init_sym_tab();
    SYMTAB *prueba2pop = init_sym_tab();
    prueba1pop = pop_st(pilaTS);
    prueba2pop = pop_st(pilaTS);
    
    printf("Imprimiendo las tablas que se sacaron de la pila\n\n");
    
    printf("Tabla 1:\n\n");
	print_sym_tab(prueba1pop);
	
	printf("Tabla 2:\n\n");
    print_sym_tab(prueba2pop);
    
    printf("Vaciando la tabla que estaba en la cima\n\n");
    clear_sym_tab(prueba1pop);
    
    printf("Imprimiendo la tabla para comprobar si est%c vac%ca\n\n",160,161);
    print_sym_tab(prueba1pop);
    
    printf("Liberando la memoria de todos los elementos usados\n");
    finish_sym(sim1);
    finish_sym(sim2);
    finish_sym(sim3);
    finish_sym_tab(prueba1pop);
    finish_sym_tab(prueba2pop);
    finish_sym_tab(prueba1TS);
    finish_sym_tab(prueba2TS);
    finish_sym_tab_stack(pilaTS);
    
    finish_type(tipo1);
    finish_type(tipo2);
    finish_type(tipo3);
    finish_type_tab(prueba1);
    
    return 0;
}
