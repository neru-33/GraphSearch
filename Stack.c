#include "Stack.h"
#include "stdlib.h"

Stack* init_stack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->size = STACK_SIZE;
	S->top = -1;
	return S;
}

int stack_full(Stack* S) {
	return S->top >= S->size - 1;
}

int stack_empty(Stack* S) {
	return S->top <= -1;
}

void stack_push(Stack* S, int e) {
	if (!stack_full(S)) {
		S->B[++S->top] = e;
	}
}

int stack_pop(Stack* S) {
	if (!stack_empty(S)) {
		return S->B[S->top--];
	}
}

int stack_top(Stack* S) {
	if (!stack_empty(S)) {
		return S->B[S->top];
	}
}
