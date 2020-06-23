#include <stdio.h>
#include <string.h>
#include "tabla_tipos.c"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Pruebas para TT y pilas de TT
 * Modificación: Correcciones menores
 * Modificó: VMCR
 */

int main(void){
    printf("Pruebas para tablas de tipos\n\n");
    
	printf("Creando la pila de tablas de tipos\n\n");
    TSTACK *pilaTT = init_type_tab_stack();
    
	printf("Creando dos tablas de tipos\n\n");
    TYPTAB *prueba1 = init_type_tab();
    TYPTAB *prueba2 = init_type_tab();
    
    printf("Tabla 1:\n\n");
    print_type_tab(prueba1);
    
	printf("Tabla 2:\n\n");
    print_type_tab(prueba2);
    
    printf("Creando una tabla de tipos y dej%cndola vac%ca\n\n",160,161);
    TYPTAB *prueba3 = init_type_tab();
    clear_type_tab(prueba3);
    
    printf("Imprimiendo la tabla de tipos para comprobar si est%c vac%ca\n\n",160,161);
    print_type_tab(prueba3);
    
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
	
    printf("Insertando dos tablas en la pila\n\n");
    push_tt(pilaTT, prueba1);
    
    push_tt(pilaTT, prueba2);
    
	printf("Llenando la tabla de la cima con 3 elementos y comprobando si se ingresaron\n\n");
    append_type(pilaTT->top, tipo1);
    printf("Prueba 1: %s\n\n",pilaTT->top->head->next->next->next->next->nombre);
    
    append_type(pilaTT->top, tipo2);
    printf("Prueba 2: %s\n\n",pilaTT->top->head->next->next->next->next->next->nombre);
    
    append_type(pilaTT->top, tipo3);
    printf("Prueba 3: %s\n\n",pilaTT->top->head->next->next->next->next->next->next->nombre);

	printf("Imprimiendo la tabla de la cima\n\n");
    print_type_tab(pilaTT->top);
    
	printf("Sacando las tablas de la pila\n\n");
	TYPTAB *prueba1pop = pop_tt(pilaTT);
    TYPTAB *prueba2pop = pop_tt(pilaTT);
    
    printf("Imprimiendo las tablas que se sacaron de la pila\n\n");
    
	printf("Tabla 1:\n\n");
	print_type_tab(prueba1pop);
	
	printf("Tabla 2:\n\n");
    print_type_tab(prueba2pop);
    
    printf("Vaciando la tabla 1\n\n");
    clear_type_tab(prueba1pop);
    
    printf("Imprimiendo la tabla de tipos para comprobar si est%c vac%ca\n\n",160,161);
    print_type_tab(prueba1pop);
    
    printf("Liberando la memoria de todos los elementos usados\n\n");
    finish_type(tipo1);
    finish_type(tipo2);
    finish_type(tipo3);
    finish_type_tab(prueba1pop);
    finish_type_tab(prueba2pop);
    finish_type_tab(prueba1);
    finish_type_tab(prueba2);
    finish_type_tab(prueba3);
    finish_type_tab_stack(pilaTT);
    
    printf("Proceso finalizado con %cxito\n",130);
    
    return 0;
}
