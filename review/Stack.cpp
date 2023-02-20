#include <iostream>
#include "LinkdedList.cpp"


typedef struct {
	Node* top;
}Stack;

void initStack(Stack* stack)
{
	stack->top = NULL;
}

bool isStackEmpty(Stack* stack) {
	return (stack == NULL);
}

void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack* stack)
{
	if (isStackEmpty(stack)) {
		std::cout << "Stack is empty!!" << '\n';
		return 0;
	}

	Node* ptr = stack->top;
	int data = ptr->data;
	stack->top = stack->top->next;
	free(ptr);
	return data;
}