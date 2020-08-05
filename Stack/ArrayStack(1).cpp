#include<iostream>
#include"ArrayStack.cpp"

Array_Stack* initStack(Array_Stack* pArrayStack, int capacity) {
	int* array;
	array = (int*)calloc(sizeof(int), capacity);
	if (array == NULL) {
		printf("Error in memory allocation for integer array of size(%d)\n", capacity);
		exit;
	}
	pArrayStack->stack = array;
	pArrayStack->capacity = capacity;
	pArrayStack->top = -1;

	return pArrayStack;
};

int* expandStack(Array_Stack* arrStack) {

	int* newArray, * oldArray;
	int newCapacity, oldCapacity;

	oldCapacity = arrStack->capacity;
	newCapacity = 2 * arrStack->capacity;
	printf("Expanding Array Stack (Current capacity(%d)->New capacity(%d)\n",
		arrStack->capacity, newCapacity);
	oldArray = arrStack->stack;
	newArray = (int*)calloc(sizeof(int), newCapacity);
	if (newArray == NULL) {
		printf("Error in memory allocation for integer array of size(%d)\n", newCapacity);
		exit;
	}
	arrStack->stack = newArray;
	for (int i = 0; i < oldCapacity; i++)
	{
		newArray[i] = oldArray[i];
	}
	arrStack->capacity = newCapacity;
	free(oldArray);
	return newArray;
}

void printStack(Array_Stack* arrStack) {
	int data;

	if ((arrStack == NULL) || (arrStack->stack == NULL)) {
		printf("Error in printArrayStack: arrStack is NULL or arrStack->stack is NULL");
		exit;
	}
	printf("Elements in stack: ");
	if (isStackEmpty(arrStack)) {
		printf("Stack is Empty");
	}
	else {
		for (int i = arrStack->top; i >= 0; i--) {

			data = arrStack->stack[i];
			printf("%3d", data);
	    }
	}
	printf("\n");
}

bool isStackFull(Array_Stack* arrStack) {

	if (arrStack->top == (arrStack->capacity - 1))
		return true;
	else
		return false;
}

bool isStackEmpty(Array_Stack* arrStack) {
	if (arrStack->top == -1)
		return true;
	else
		return false;

}

void push(Array_Stack* arrStack, int data) {
	if (isStackFull(arrStack))
		expandStack(arrStack);

	arrStack->top++;
	arrStack->stack[arrStack->top] = data;
}

int* top(Array_Stack* arrStack) {
	if (isStackEmpty(arrStack))
		return NULL;

	int* pData = &(arrStack->stack[arrStack->top]);
	return pData;
}

int* pop(Array_Stack* arrStack) {
	if (isStackEmpty(arrStack))
		return NULL;

	int* pData = &(arrStack->stack[arrStack->top]);
	arrStack->top--;
	return pData;
}