#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack.h>
#include <graph.h>
#include <defines.h>

STACK *create_stack(){
	return (STACK *) calloc(1, sizeof(STACK));
}

int push_stack_elem(STACK *stack, int indice){
	if(!stack) return INVALID_STACK;
	STACK_ELEMENT *e = (STACK_ELEMENT *) malloc(sizeof(STACK_ELEMENT));
	e->elem = indice;
	e->next = stack->top;
	stack->top = e;
	stack->counter++;
	return SUCCESS;
}

int pop_stack_elem(STACK *stack){
	if(!stack)return INVALID_STACK;
	if(!stack->counter) return INVALID_STACK;
	int indice;
	STACK_ELEMENT *e = stack->top;
	stack->top = e->next;
	indice = e->elem; 
	free(e);
	e = NULL;
	stack->counter--;
	return indice;

}

int show_stack_top(STACK *stack){
	if(!stack)return INVALID_STACK;
	if(!stack->counter) return INVALID_STACK;
	return stack->top->elem;

}
