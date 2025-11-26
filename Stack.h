#pragma once
#define STACK_SIZE 50


typedef struct Stack {
	int B[STACK_SIZE];
	int top;
	int size;
}Stack;

Stack* init_stack();

int stack_full(Stack* S);

int stack_empty(Stack* S);

void stack_push(Stack* S, int e);

int stack_pop(Stack* S);

int stack_top(Stack* S);

