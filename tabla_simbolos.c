#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Funciones para las tablas y pilas de símbolos
 * Modificación: 21/06/2020 Correcciones menores, se añade la función para ingresar argumentos a un símbolo
 * Modificó: VMCR
 */

/*Esta función debe tener la referencia a la tabla de tipos para realizar la asignación de la dirección del símbolo*/
/*Primero se debe tener la tabla de tipos para que funcione*/
void append_sym(SYMTAB *tablaSim, TYPTAB *tablaTipos, SYM *simbolo){
	if(tablaSim->head == NULL){ // Si la TS está vacía
		tablaSim->head = simbolo; // Todavía no hay tail, el next de head sigue siendo nulo
		tablaSim->head->dir = 0; // Se le asigna la dir 0 a head porque la dirección es local para cada tabla de símbolos
		tablaSim->num++; // Se aumenta el número de elementos que tiene la tabla
		return;
	}
	else{
		if(tablaSim->num == 1){ // Si hay un elemento en la tabla (Se podría usar stdbool.h para simplificar instrucciones como esta)
			tablaSim->tail = simbolo; // El nuevo se convierte en tail
			tablaSim->head->next = tablaSim->tail; // El nuevo elemento es el siguiente del que había
			tablaSim->tail->next = NULL;
			tablaSim->tail->dir = tablaSim->head->dir + get_size(tablaTipos, tablaSim->head->tipo);
			// La siguiente dirección asignada será la dirección de head más su tamaño, por eso se busca ese tipo en la TT, para obtener el tamaño
			tablaSim->num++; // Se aumenta el número de elementos que tiene la tabla
			return;
		}
		else{
			SYM *current = tablaSim->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaSim->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next; // Si todavía no llega a tail, avanza
			}
			SYM *copy = tablaSim->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			tablaSim->tail = simbolo; // Ahora el último será el símbolo nuevo
			tablaSim->tail->dir = copy->dir + get_size(tablaTipos, copy->tipo); // Se suma la última dirección asignada más el tamaño del último elemento que entró
			copy->next = tablaSim->tail; // El siguiente del que era tail es el valor nuevo
			tablaSim->num++; // Se aumenta el número de elementos que tiene la tabla
			return;
			/* Creo que podría hacerse de otra forma, parar en tail, hacer que su siguiente sea el nuevo
			 * y luego hacer que tail sea el nuevo elemento, pero no lo probé
			 */
		}
	}
} //Agrega al final de la tabla un nuevo símbolo


void clear_sym_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){ // Si head es nulo quiere decir que la tabla está vacía
    	printf("La tabla de s%cmbolos no tiene elementos\n\n",161);
    }
    else{				
    	SYM *current = tablaSim->head; //Obtengo a head
    	SYM *aux;
   		while(current != NULL){
        	if(current != tablaSim->head && current != tablaSim->tail){ // No se libera el espacio para head y tail, sólo se harán nulos 
        		aux = current->next; // Se determina cuál es el símbolo siguiente del actual
				free(current); // Se libera la memoria del actual
				current = aux; // El actual toma el valor de su símbolo siguiente
        	}
			else{ // En caso de que el nodo actual sea head o tail
        		current = current->next; // Ahora el actual se iguala con su siguiente
        	}
   	 	}
   	 	printf("La tabla de s%cmbolos se ha vaciado correctamente\n\n",161);
	}
	tablaSim->head = NULL; // Sólo se liberó el espacio de los nodos intermedios entre head y tail, quedan sólo estos dos
	tablaSim->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaSim->next = NULL; // No tiene siguiente
	tablaSim->num = 0; // Ya no tiene elementos
	return;
} // Deja vacía la tabla


SYMTAB *pop_st(SSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que está vacía
		printf("La pila está vac%ca\n\n",161);
		return stack->tail; // Regresa nulo
	}
	else{
		if(stack->top == stack->tail){ // Si sólo hay un elemento en la pila, es el fondo y la cima
			SYMTAB *copiaTop = stack->top; //Obtenemos el valor de la cima de la pila actual
			stack->top == NULL;
			stack->tail == NULL;
			return copiaTop;
		}
		else{ // Si hay más de un elemento en la pila
			SYMTAB *copiaAux = stack->tail; //Vamos a detenernos en el penúltimo elemento hacia arriba
			while(copiaAux->next != stack->top){
				copiaAux = copiaAux->next;
			}
			SYMTAB *copiaTop = stack->top; //Se obtiene el valor de la cima de la pila actual
			copiaAux->next =NULL;
			stack->top = copiaAux;
			return copiaTop; //Se devuelve la copia del valor de la cima
		}
	}
} // Ejecuta un pop sobre la pila de tablas de símbolos


void push_st(SSTACK *stack, SYMTAB *tablaSim){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que está vacía
		stack->tail = stack->top = tablaSim; // Como hay un solo elemento, es fondo y cima al mismo tiempo
		return;
	}
	else{ // Si la pila no está vacía
		stack->top->next = tablaSim;
    	stack->top = tablaSim;
    	return;
	}
} // Ingresa una tabla a la pila de tablas de símbolos


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
} // Reserva memoria para una tabla de símbolos vacía


SYM *init_sym(){
	SYM *simbolo = (SYM*) malloc(sizeof(SYM));
	simbolo->args = init_args();
	simbolo->next = NULL;
	simbolo->dir = 0;
	memset((void*)simbolo->id, '\0', sizeof(simbolo)); // Se inicializa el arreglo de caracteres al símbolo nulo
	simbolo->num = 0;
	simbolo->tipo = 0;
	simbolo->var = 0;
	return simbolo;
} // Reserva memoria para un símbolo vacío


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


/*En las siguientes tres funciones se utiliza free() porque la memoria se reservó(allocate) con malloc*/
void finish_sym_tab_stack(SSTACK *stackSim){
	free(stackSim);
	return;
} // Libera la memoria para la pila


void finish_sym_tab(SYMTAB *tablaSim){
	free(tablaSim);
	return;
} // Libera memoria para una tabla de símbolos


void finish_sym(SYM *simbolo){
	free(simbolo);
	return;
} // Libera memoria para un símbolo vacío


void print_sym_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){
    	printf("La tabla de s%cmbolos no tiene elementos\n\n",161);
    	return;
    }
    else{
    	printf("%10s %10s %10s %10s %10s\n\n","Identificador","Direccion","Tipo","Var","Num Args");
    	SYM *actual = tablaSim->head;
   		while (actual != NULL) {	// Se recorre la tabla hasta que se terminen los símbolos
        	printf("%10s %10d %10d %10d %10d\n\n", actual->id,actual->dir,actual->tipo,actual->var,actual->num);
        	actual = actual->next;
   	 	}
   	 	return;
	}
} // Imprime en pantalla la tabla de símbolos


void *add_args_sym(SYM *simbolo, int arg){ // Función para añadir un argumento al símbolo especificado
	ARG *argumento = init_arg(arg);
	if(simbolo->args->head == NULL){ // Si no hay argumentos
		simbolo->args->head = argumento; // Todavía no hay tail, el next de head sigue siendo nulo
		simbolo->args->head->next = NULL;
		simbolo->num++; // Se aumenta el número de argumentos
		simbolo->args->num++;
		return;
	}
	else{
		if(simbolo->num == 1){ // Si hay un argumento
			simbolo->args->tail = argumento; // El nuevo se convierte en tail
			simbolo->args->head->next = simbolo->args->tail; // El nuevo elemento es el siguiente del que había
			simbolo->args->tail->next = NULL;
			simbolo->num++; // Se aumenta el número de argumentos
			simbolo->args->num++;
			return;
		}
		else{
			ARG *current = simbolo->args->head; // Si hay más de 1 elemento comienzo a recorrer la lista de argumentos
			while(current->next != simbolo->args->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next; // Si todavía no llega a tail, avanza
			}
			ARG *copy = simbolo->args->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			simbolo->args->tail = argumento; // Ahora el último será el símbolo nuevo
			copy->next = simbolo->args->tail; // El siguiente del que era tail es el valor nuevo
			simbolo->num++; // Se aumenta el número de argumentos
			simbolo->args->num++;
			return;
			/* Creo que podría hacerse de otra forma, parar en tail, hacer que su siguiente sea el nuevo
			 * y luego hacer que tail sea el nuevo elemento, pero no lo probé
			 */
		}
	}
} // Añade un argumento al símbolo indicado


SYMTAB *get_global_sym_tab(SSTACK *stack){
	SYMTAB *global = stack->tail;
	return global;
} // Regresa la tabla del fondo de la pila de tablas de símbolos


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
} // Busca un ID entre los símbolos, regresa 0 si lo encuentra, -1 si no
