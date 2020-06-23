#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.c"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Pruebas para TS y pilas de TS
 * Modificación: Este archivo quedó obsoleto. Revisar mainTablas.c para ver cómo trabajan las dos tablas en conjunto
 * Modificó: VMCR
 */

int main(void){
    printf("Pruebas para la tabla de s%cmbolos\n\n",161);
    
	printf("Creando la pila de tablas de s%cmbolos\n\n",161);
    SSTACK *pilaTS = init_sym_tab_stack();
    
	printf("Creando dos tablas de s%cmbolos\n\n",161);
    SYMTAB *prueba1 = init_sym_tab();
    SYMTAB *prueba2 = init_sym_tab();
    
	printf("Creando tres s%cmbolos\n\n",161);
    SYM *sim1 = init_sym();
    SYM *sim2 = init_sym();
    SYM *sim3 = init_sym();
    
	printf("Llenando los s%cmbolos\n\n",161);
    sim1->args = NULL;
	strcpy(sim1->id,"Simbolo 1");
	sim1->tipo = 0;
	sim1->var = 0;
	
	sim2->args = NULL;
	strcpy(sim2->id,"Simbolo 2");
	sim2->tipo = 0;
	sim2->var = 0;
	
	sim3->args = NULL;
	strcpy(sim3->id,"Simbolo 3");
	sim3->tipo = 0;
	sim3->var = 0;
	
    printf("Insertando dos tablas en la pila\n\n");
    push_st(pilaTS, prueba1);
    push_st(pilaTS, prueba2);
    
	printf("Llenando la tabla de la cima con 3 elementos\n\n");
    append_sym(pilaTS->top, sim1);
    append_sym(pilaTS->top, sim2);
    append_sym(pilaTS->top, sim3);
    
    printf("Imprimiendo el n%cmero de elementos de la tabla de la cima: %d\n\n",163,pilaTS->top->num);
    
	printf("Imprimiendo la tabla de la cima\n\n");
    print_tab(pilaTS->top);
    
	printf("Sacando las tablas de la pila\n\n");
	SYMTAB *prueba1pop = init_sym_tab();
    SYMTAB *prueba2pop = init_sym_tab();
    prueba1pop = pop_st(pilaTS);
    prueba2pop = pop_st(pilaTS);
    
    printf("Imprimiendo las tablas que se sacaron de la pila\n\n");
    
    printf("Tabla 1:\n\n");
	print_tab(prueba1pop);
	
	printf("Tabla 2:\n\n");
    print_tab(prueba2pop);
    
    printf("Vaciando la tabla que estaba en la cima\n\n");
    clear_sym_tab(prueba1pop);
    
    printf("Imprimiendo la tabla para comprobar si est%c vac%ca\n\n",160,161);
    print_tab(prueba1pop);
    
    printf("Liberando la memoria de todos los elementos usados\n");
    finish_sym(sim1);
    finish_sym(sim2);
    finish_sym(sim3);
    finish_sym_tab(prueba1pop);
    finish_sym_tab(prueba2pop);
    finish_sym_tab(prueba1);
    finish_sym_tab(prueba2);
    finish_sym_tab_stack(pilaTS);
    
    printf("Proceso finalizado con %cxito\n",130);
    
    return 0;
}
