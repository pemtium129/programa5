#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Funciones para las tablas y pilas de s�mbolos
 * Modificaci�n: 21/06/2020 Correcciones menores, se a�ade la funci�n para ingresar argumentos a un s�mbolo
 * Modific�: VMCR
 */

/*Esta funci�n debe tener la referencia a la tabla de tipos para realizar la asignaci�n de la direcci�n del s�mbolo*/
/*Primero se debe tener la tabla de tipos para que funcione*/
void append_sym(SYMTAB *tablaSim, TYPTAB *tablaTipos, SYM *simbolo){
	if(tablaSim->head == NULL){ // Si la TS est� vac�a
		tablaSim->head = simbolo; // Todav�a no hay tail, el next de head sigue siendo nulo
		tablaSim->head->dir = 0; // Se le asigna la dir 0 a head porque la direcci�n es local para cada tabla de s�mbolos
		tablaSim->num++; // Se aumenta el n�mero de elementos que tiene la tabla
		return;
	}
	else{
		if(tablaSim->num == 1){ // Si hay un elemento en la tabla (Se podr�a usar stdbool.h para simplificar instrucciones como esta)
			tablaSim->tail = simbolo; // El nuevo se convierte en tail
			tablaSim->head->next = tablaSim->tail; // El nuevo elemento es el siguiente del que hab�a
			tablaSim->tail->next = NULL;
			tablaSim->tail->dir = tablaSim->head->dir + get_size(tablaTipos, tablaSim->head->tipo);
			// La siguiente direcci�n asignada ser� la direcci�n de head m�s su tama�o, por eso se busca ese tipo en la TT, para obtener el tama�o
			tablaSim->num++; // Se aumenta el n�mero de elementos que tiene la tabla
			return;
		}
		else{
			SYM *current = tablaSim->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaSim->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next; // Si todav�a no llega a tail, avanza
			}
			SYM *copy = tablaSim->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			tablaSim->tail = simbolo; // Ahora el �ltimo ser� el s�mbolo nuevo
			tablaSim->tail->dir = copy->dir + get_size(tablaTipos, copy->tipo); // Se suma la �ltima direcci�n asignada m�s el tama�o del �ltimo elemento que entr�
			copy->next = tablaSim->tail; // El siguiente del que era tail es el valor nuevo
			tablaSim->num++; // Se aumenta el n�mero de elementos que tiene la tabla
			return;
			/* Creo que podr�a hacerse de otra forma, parar en tail, hacer que su siguiente sea el nuevo
			 * y luego hacer que tail sea el nuevo elemento, pero no lo prob�
			 */
		}
	}
} //Agrega al final de la tabla un nuevo s�mbolo


void clear_sym_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){ // Si head es nulo quiere decir que la tabla est� vac�a
    	printf("La tabla de s%cmbolos no tiene elementos\n\n",161);
    }
    else{				
    	SYM *current = tablaSim->head; //Obtengo a head
    	SYM *aux;
   		while(current != NULL){
        	if(current != tablaSim->head && current != tablaSim->tail){ // No se libera el espacio para head y tail, s�lo se har�n nulos 
        		aux = current->next; // Se determina cu�l es el s�mbolo siguiente del actual
				free(current); // Se libera la memoria del actual
				current = aux; // El actual toma el valor de su s�mbolo siguiente
        	}
			else{ // En caso de que el nodo actual sea head o tail
        		current = current->next; // Ahora el actual se iguala con su siguiente
        	}
   	 	}
   	 	printf("La tabla de s%cmbolos se ha vaciado correctamente\n\n",161);
	}
	tablaSim->head = NULL; // S�lo se liber� el espacio de los nodos intermedios entre head y tail, quedan s�lo estos dos
	tablaSim->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaSim->next = NULL; // No tiene siguiente
	tablaSim->num = 0; // Ya no tiene elementos
	return;
} // Deja vac�a la tabla


SYMTAB *pop_st(SSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		printf("La pila est� vac%ca\n\n",161);
		return stack->tail; // Regresa nulo
	}
	else{
		if(stack->top == stack->tail){ // Si s�lo hay un elemento en la pila, es el fondo y la cima
			SYMTAB *copiaTop = stack->top; //Obtenemos el valor de la cima de la pila actual
			stack->top == NULL;
			stack->tail == NULL;
			return copiaTop;
		}
		else{ // Si hay m�s de un elemento en la pila
			SYMTAB *copiaAux = stack->tail; //Vamos a detenernos en el pen�ltimo elemento hacia arriba
			while(copiaAux->next != stack->top){
				copiaAux = copiaAux->next;
			}
			SYMTAB *copiaTop = stack->top; //Se obtiene el valor de la cima de la pila actual
			copiaAux->next =NULL;
			stack->top = copiaAux;
			return copiaTop; //Se devuelve la copia del valor de la cima
		}
	}
} // Ejecuta un pop sobre la pila de tablas de s�mbolos


void push_st(SSTACK *stack, SYMTAB *tablaSim){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		stack->tail = stack->top = tablaSim; // Como hay un solo elemento, es fondo y cima al mismo tiempo
		return;
	}
	else{ // Si la pila no est� vac�a
		stack->top->next = tablaSim;
    	stack->top = tablaSim;
    	return;
	}
} // Ingresa una tabla a la pila de tablas de s�mbolos


SSTACK *init_sym_tab_stack(){
	SSTACK *pilaTS = (SSTACK*) malloc(sizeof(SSTACK));
	pilaTS->top = NULL;
	pilaTS->tail = NULL;
	return pilaTS;
} // Reserva memoria para la pila


SYMTAB *init_sym_tab(){
	SYMTAB *tablaSim = (SYMTAB*) malloc(sizeof(SYMTAB));
	tablaSim->head = NULL;
	tablaSim->tail = NULL;
	tablaSim->next = NULL;
	tablaSim->num = 0;
	return tablaSim;
} // Reserva memoria para una tabla de s�mbolos vac�a


SYM *init_sym(){
	SYM *simbolo = (SYM*) malloc(sizeof(SYM));
	simbolo->args = init_args();
	simbolo->next = NULL;
	simbolo->dir = 0;
	memset((void*)simbolo->id, '\0', sizeof(simbolo)); // Se inicializa el arreglo de caracteres al s�mbolo nulo
	simbolo->num = 0;
	simbolo->tipo = 0;
	simbolo->var = 0;
	return simbolo;
} // Reserva memoria para un s�mbolo vac�o


ARGS *init_args(){
	ARGS *argumentos = (ARGS*) malloc(sizeof(ARGS));
	argumentos->head = NULL;
	argumentos->tail = NULL;
	argumentos->num = 0;
	return argumentos;
} // Reserva memoria para una lista de argumentos


ARG *init_arg(int arg){
	ARG *argumento = (ARG*) malloc(sizeof(ARG));
	argumento->arg = arg;
	argumento->next = NULL;
	return argumento;
} // Reserva memoria para un argumento y le asigna su valor


/*En las siguientes tres funciones se utiliza free() porque la memoria se reserv�(allocate) con malloc*/
void finish_sym_tab_stack(SSTACK *stackSim){
	free(stackSim);
	return;
} // Libera la memoria para la pila


void finish_sym_tab(SYMTAB *tablaSim){
	free(tablaSim);
	return;
} // Libera memoria para una tabla de s�mbolos


void finish_sym(SYM *simbolo){
	free(simbolo);
	return;
} // Libera memoria para un s�mbolo vac�o


void print_sym_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){
    	printf("La tabla de s%cmbolos no tiene elementos\n\n",161);
    	return;
    }
    else{
    	printf("%10s %10s %10s %10s %10s\n\n","Identificador","Direccion","Tipo","Var","Num Args");
    	SYM *actual = tablaSim->head;
   		while (actual != NULL) {	// Se recorre la tabla hasta que se terminen los s�mbolos
        	printf("%10s %10d %10d %10d %10d\n\n", actual->id,actual->dir,actual->tipo,actual->var,actual->num);
        	actual = actual->next;
   	 	}
   	 	return;
	}
} // Imprime en pantalla la tabla de s�mbolos


void *add_args_sym(SYM *simbolo, int arg){ // Funci�n para a�adir un argumento al s�mbolo especificado
	ARG *argumento = init_arg(arg);
	if(simbolo->args->head == NULL){ // Si no hay argumentos
		simbolo->args->head = argumento; // Todav�a no hay tail, el next de head sigue siendo nulo
		simbolo->args->head->next = NULL;
		simbolo->num++; // Se aumenta el n�mero de argumentos
		simbolo->args->num++;
		return;
	}
	else{
		if(simbolo->num == 1){ // Si hay un argumento
			simbolo->args->tail = argumento; // El nuevo se convierte en tail
			simbolo->args->head->next = simbolo->args->tail; // El nuevo elemento es el siguiente del que hab�a
			simbolo->args->tail->next = NULL;
			simbolo->num++; // Se aumenta el n�mero de argumentos
			simbolo->args->num++;
			return;
		}
		else{
			ARG *current = simbolo->args->head; // Si hay m�s de 1 elemento comienzo a recorrer la lista de argumentos
			while(current->next != simbolo->args->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next; // Si todav�a no llega a tail, avanza
			}
			ARG *copy = simbolo->args->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			simbolo->args->tail = argumento; // Ahora el �ltimo ser� el s�mbolo nuevo
			copy->next = simbolo->args->tail; // El siguiente del que era tail es el valor nuevo
			simbolo->num++; // Se aumenta el n�mero de argumentos
			simbolo->args->num++;
			return;
			/* Creo que podr�a hacerse de otra forma, parar en tail, hacer que su siguiente sea el nuevo
			 * y luego hacer que tail sea el nuevo elemento, pero no lo prob�
			 */
		}
	}
} // A�ade un argumento al s�mbolo indicado


SYMTAB *get_global_sym_tab(SSTACK *stack){
	SYMTAB *global = stack->tail;
	return global;
} // Regresa la tabla del fondo de la pila de tablas de s�mbolos


SYM *get_sym(SYMTAB *tablaSim, char *id){
	SYM *current = tablaSim->head;
	while(current != NULL){
		if(strcmp(current->id, id) == 0){
			return current;
		}
		current = current->next;
	}
	return current; // Si no lo encuentra, regresa nulo
} // Busca un tipo con cierto ID y lo regresa si lo encuentra


int get_dir(SYMTAB *tablaSim, char *id){
	int address;
	SYM *current = tablaSim->head;
	while(current != NULL){
		if(strcmp(current->id, id) == 0){
			address = current->dir;
			return address;
		}
		current = current->next;
	}
	return -1; // Si no lo encuentra, regresa -1
} // Busca un tipo con cierto ID y lo regresa si lo encuentra


int sym_id_exists(SYMTAB *tablaSim, char *id){
	SYM *current = tablaSim->head;
	while(current != NULL){
		if(strcmp(current->id, id) == 0){
			return 0;
		}
		current = current->next;
	}
	return -1; // Si no lo encuentra, regresa -1
} // Busca un ID entre los s�mbolos, regresa 0 si lo encuentra, -1 si no
