#include <stdlib.h>
#include <string.h>
#include "tabla_tipos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Declaraci�n de funciones para las tablas y pilas de tipos
 * Modificaci�n: 21/06/2020 Se a�adi� una funci�n para obtener el tama�o de un tipo e ingresar el tipo de una estructura
 * Modific�: VMCR
 */

void append_type(TYPTAB *tablaTipos, TYP *tipo){
	if(tablaTipos->head == NULL){ // Si la TT est� vac�a
		tablaTipos->head = tipo; // Todav�a no hay tail, el next de head sigue siendo nulo
		tablaTipos->head->next = NULL; // Como s�lo hay head, no tiene siguiente
		tablaTipos->num++; // Se tiene un elemento
		tablaTipos->head->id = 0; // Se asigna el primer identificador
		return;
	}
	else{
		if(tablaTipos->num == 1){ // Si hay un elemento en la tabla (Se podr�a usar stdbool.h para simplificar instrucciones como esta)
			tablaTipos->tail = tipo; // El nuevo se convierte en tail
			tablaTipos->head->next = tablaTipos->tail; // El nuevo elemento es el siguiente del que hab�a
			tablaTipos->tail->next = NULL; // No hay siguiente de tail
			tablaTipos->num++; // Se aumenta el n�mero de elementos en la tabla
			tablaTipos->tail->id = 1; // Se asigna el identificador 1 a tail
			return;
		}
		else{
			TYP *current = tablaTipos->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaTipos->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			TYP *copy = tablaTipos->tail; // Copio a tail
			int id_copia = tablaTipos->tail->id; //Copio el �ltimo ID asignado
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			tablaTipos->tail = tipo; // Ahora el �ltimo ser� el s�mbolo nuevo
			copy->next = tablaTipos->tail; // El siguiente del que era tail es el valor nuevo
			tablaTipos->tail->id = id_copia + 1; // Se asigna un nuevo ID al elemento que acaba de entrar
			tablaTipos->tail->next = NULL;
			tablaTipos->num++; // Se aumenta el n�mero de elementos en la tabla
			return;
			/* Creo que podr�a hacerse de otra forma, parar en tail, hacer que su siguiente sea el nuevo
			 * y luego hacer que tail sea el nuevo elemento, pero no lo prob�
			 */
		}
	}
} //Agrega al final de la tabla un nuevo tipo


void clear_type_tab(TYPTAB *tablaTipos){
	if(tablaTipos->head == NULL){ // Si head es nulo quiere decir que la tabla est� vac�a
    	printf("La tabla de tipos no tiene elementos\n\n");
    }
    else{				
    	TYP *current = tablaTipos->head; //Obtengo a head
    	TYP *aux;
   		while(current != NULL){
        	if(current != tablaTipos->head && current != tablaTipos->tail){ // No se libera el espacio para head y tail, s�lo se har�n nulos 
        		aux = current->next; // Se determina cu�l es el tipo siguiente del actual
				free(current); // Se libera la memoria del actual
				current = aux; // El actual toma el valor de su tipo siguiente
        	}
			else{ // En caso de que el nodo actual sea head o tail
        		current = current->next; // Ahora el actual se iguala con su siguiente
        	}
   	 	}
   	 	printf("La tabla de tipos se ha vaciado correctamente\n\n");
	}
	tablaTipos->head = NULL; // S�lo se liber� el espacio de los nodos intermedios entre head y tail, quedan s�lo estos dos
	tablaTipos->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaTipos->next = NULL; // No tiene siguiente
	tablaTipos->num = 0; // Ya no tiene elementos
	return;
} // Deja vac�a la tabla


TYPTAB *pop_tt(TSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		printf("La pila est� vac%ca\n\n",161);
		return stack->tail; // Regresa nulo
	}
	else{
		if(stack->top == stack->tail){ // Si s�lo hay un elemento en la pila, es el fondo y la cima
			TYPTAB *copiaTop = stack->top; //Obtenemos el valor de la cima de la pila actual
			stack->top == NULL;
			stack->tail == NULL; // Se sac� el �nico elemento que hab�a, por eso top y tail se vuelven nulos
			return copiaTop;
		}
		else{ // Si hay m�s de un elemento en la pila
			TYPTAB *copiaAux = stack->tail; // Se detiene en el pen�ltimo elemento hacia arriba
			while(copiaAux->next != stack->top){
				copiaAux = copiaAux->next;
			}
			TYPTAB *copiaTop = stack->top; //Se obtiene el valor de la cima de la pila actual
			copiaAux->next =NULL;
			stack->top = copiaAux;
			return copiaTop; //Se devuelve la copia del valor de la cima
		}
	}
} // Ejecuta un pop sobre la pila de tablas de tipos


void push_tt(TSTACK *stack, TYPTAB *tablaTipos){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		stack->tail = stack->top = tablaTipos; // Como hay un solo elemento, es fondo y cima al mismo tiempo
		return;
	}
	else{ // Si la pila no est� vac�a
		stack->top->next = tablaTipos;
    	stack->top = tablaTipos;
    	return;
    	/*Se podr�a usar este mismo razonamiento para los append, pero no lo prob�*/
	}
} // Ingresa una tabla a la pila de tablas de tipos


TSTACK *init_type_tab_stack(){
	TSTACK *pilaTT = (TSTACK*) malloc(sizeof(TSTACK));
	pilaTT->top = NULL;
	pilaTT->tail = NULL;
	return pilaTT;
} // Reserva memoria para la pila


TYPTAB *init_type_tab(){
	TYPTAB *tablaTipos = (TYPTAB*) malloc(sizeof(TYPTAB));
	tablaTipos->head = NULL;
	tablaTipos->tail = NULL;
	tablaTipos->next = NULL;
	tablaTipos->num = 0;
	TYP *entero = init_type();
	TYP *real = init_type();
	TYP *doble_real = init_type();
	TYP *caracter = init_type();
	
	// Llenando los tipos b�sicos
	entero->id = 0;
	strcpy(entero->nombre,"int");
	entero->tb.is_est = -1;
	entero->tam = 4;
	
	real->id = 1;
	strcpy(real->nombre,"float");
	real->tb.is_est = -1;
	real->tam = 4;
	
	doble_real->id = 2;
	strcpy(doble_real->nombre,"double");
	doble_real->tb.is_est = -1;
	doble_real->tam = 8;
	
	caracter->id = 3;
	strcpy(caracter->nombre,"char");
	caracter->tb.is_est = -1;
	caracter->tam = 1;
	
	caracter->id = 4;
	strcpy(caracter->nombre,"sin");
	caracter->tb.is_est = -1;
	caracter->tam = 1;
	
	append_type(tablaTipos, entero);
	append_type(tablaTipos, real);
	append_type(tablaTipos, doble_real);
	append_type(tablaTipos, caracter);
	
	return tablaTipos;
} // Reserva memoria para una tabla de tipos e inserta los tipos nativos


TYP *init_type(){
	TYP *tipo = (TYP*) malloc(sizeof(TYP));
	tipo->id = 0;
	memset((void*)tipo->nombre, '\0', sizeof(tipo)); // Se inicializa el arreglo de caracteres al s�mbolo nulo
	tipo->tb.is_est = 0;
	tipo->tb.tipo.est = NULL;
	tipo->tam = 0;
	tipo->next = NULL;
	return tipo;
} // Reserva memoria para un tipo


TYPTAB *get_top_Tstack(TSTACK *stack){
	TYPTAB *copia = stack->top;
	return copia;
} // Regresa la tabla de la cima de la pila de TT sin hacer pop


/*En las siguientes tres funciones se utiliza free() porque la memoria se reserv�(allocate) con malloc*/
void finish_type_tab_stack(TSTACK *stackTyp){
	free(stackTyp);
	return;
} // Libera la memoria para la pila


void finish_type_tab(TYPTAB *tablaTipos){
	free(tablaTipos);
	return;
} // Libera memoria para una tabla de tipos


void finish_type(TYP *tipo){
	free(tipo);
	return;
} // Libera memoria para un tipo


void print_type_tab(TYPTAB *tablaTipos){
	if(tablaTipos->head == NULL){
    	printf("La tabla de tipos no tiene elementos\n\n");
    	return;
    }
    else{
    	printf("%10s %10s %10s %10s\n\n","Identificador","Nombre","Tamano","Tipo Base");
    	TYP *actual = tablaTipos->head;
   		while (actual != NULL) {	// Se recorre la tabla hasta que se terminen los tipos
        	printf("%10d %10s %10d %10d\n\n", actual->id,actual->nombre,actual->tam,actual->tb.is_est);
        	actual = actual->next;                       
   	 	}
   	 	return;
	}
} // Imprime en pantalla la tabla de tipos


int get_size(TYPTAB *tablaTipos, int id){
	int size;
	TYP *tipo = tablaTipos->head;
	while(tipo != NULL){ // Se recorre la tabla de tipos
		if(tipo->id == id){ // Se busca que el tipo enviado desde la TS coincida con alguno
			size = tipo->tam; // Cuando se encuentra, se obtiene su tama�o
			return size; // Termina la ejecuci�n de la funci�n
		}
		tipo = tipo->next; // Si no se encuentra, busca en el siguiente elemento de la tabla
	}
	return -1; // Cuando no se encontr� el tipo
} // Obtiene el tama�o de un tipo


void set_tb_struct(TYP *tipo, int tb){
	tipo->tb.is_est = 1;
	tipo->tb.tipo.tipo = tb;
	return;
} // Se usa para ingresar el tipo base de una estructura


TYPTAB *get_global_type_tab(TSTACK *stack){
	TYPTAB *global = stack->tail;
	return global;
} // Regresa la tabla del fondo de la pila de tablas de tipos


TYP *get_type(TYPTAB *tablaTipos, int id){
	TYP *current = tablaTipos->head;
	while(current != NULL){
		if(current->id == id){
			return current;
		}
		current = current->next;
	}
	return current; // Si no lo encuentra, regresa nulo
} // Busca un tipo con cierto ID y lo regresa si lo encuentra


char *get_name_type(TYP *tipo){
	char *nombre = tipo->nombre;
	return nombre;
} // Busca el nombre del tipo especificado


TB *get_tb(TYPTAB *tablaTipos, int id){
	TYP *current = tablaTipos->head;
	TB *tipoBase = NULL;
	while(current != NULL){
		if(current->id == id){
			*tipoBase = current->tb;
			return tipoBase;
		}
		current = current->next;
	}
	return tipoBase; // Si no lo encuentra, regresa nulo
} // Busca el tipo base de un tipo
