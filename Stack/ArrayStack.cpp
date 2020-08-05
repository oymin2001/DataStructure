#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct {
	int* stack;
	int capacity;
	int top;

}Array_Stack;

Array_Stack* initStack(Array_Stack* pArrayStack, int capacity);
int* expandStack(Array_Stack* arrStack);
void printStack(Array_Stack* arrStack);
bool isStackFull(Array_Stack* arrStack);
bool isStackEmpty(Array_Stack* arrStack);
void push(Array_Stack* arrStack, int data);
int* top(Array_Stack* arrStack);
int* pop(Array_Stack* arrStack);

#endif