#include<iostream>
#include "ArrayQueue.cpp"


Array_Queue* initQueue(Array_Queue* pIntArrayQueue, int capacity) {
	int* CirQ;

	CirQ = (int*)calloc(sizeof(int), capacity);
	if (CirQ == NULL) {
		printf("Error in memory allocation for integer array of size(%d)\n", capacity);
		exit;
	}

	pIntArrayQueue->CirQ = CirQ;
	pIntArrayQueue->capacity = capacity;
	pIntArrayQueue->front = pIntArrayQueue->end = 0;
	pIntArrayQueue->num_elements = 0;
	
	return pIntArrayQueue;
}
int* expandQueue(Array_Queue* arrQueue) {
	int* newCirQ, * oldCirQ;
	int oldCapacity, newCapacity;
	int oldIndex, newIndex;

	oldCapacity = arrQueue->capacity;
	newCapacity = 2 * arrQueue->capacity;
	printf("ExpandingArrayStack (CurrentCapacity(%d) -> NewCapacity(%d)\n",
		arrQueue->capacity, newCapacity);
	oldCirQ = arrQueue->CirQ;
	newCirQ = (int*)calloc(sizeof(int), newCapacity);
	if (newCirQ == NULL) {
		printf("Error in memory allocation for integer array of size (%d)\n", newCapacity);
		exit;
	}
	arrQueue->CirQ = newCirQ;

	// capacity를 2배 늘려도 순환순서가 바뀌지 않도록 index를 이용하여 전달
	for (int i = 0; i < arrQueue->num_elements; i++)
	{
		oldIndex = arrQueue->front + i;
		if (oldIndex >= arrQueue->capacity)
			oldIndex = oldIndex % arrQueue->capacity;
		newIndex = arrQueue->front + i;
		if (newIndex >= newCapacity)
			newIndex = newIndex % newCapacity;
		newCirQ[newIndex] = oldCirQ[oldIndex];
	}
	arrQueue->capacity = newCapacity;
	free(oldCirQ);
	return newCirQ;
	}


void printQueue(Array_Queue* arrQueue) {
	int data;

	if ((arrQueue == NULL) || (arrQueue->CirQ == NULL)) {
		printf("Error in printArrayQueue");
		exit;
	}
	printf("Elements in Queue: ");
	if (isQueueEmpty(arrQueue))
		printf("Queue is Empty");
	else {
		for (int i = arrQueue->front; i <= arrQueue->end; i++)
		{
			data = arrQueue->CirQ[i];
			printf("%3d", data);
		}
	}
	printf("\n");
}
bool isQueueFull(Array_Queue* arrQueue) {
	if (arrQueue->num_elements == arrQueue->capacity)
		return true;
	else
		return false;
}
bool isQueueEmpty(Array_Queue* arrQueue) {
	if (arrQueue->num_elements == 0)
		return true;
	else
		return false;
}
void enQueue(Array_Queue* arrQueue, int data) {
	if (isQueueFull(arrQueue))
		expandQueue(arrQueue);

	arrQueue->end++;
	//순환
	if (arrQueue->end >= arrQueue->capacity)
		arrQueue->end = arrQueue->end % arrQueue->capacity;
     
	arrQueue->CirQ[arrQueue->end] = data;
	arrQueue->num_elements++;
}
int* deQueue(Array_Queue* arrQueue) {
	if (isQueueEmpty(arrQueue))
		return NULL;

	int* pData = &(arrQueue->CirQ[arrQueue->front]);
	arrQueue->front++;
	if (arrQueue->front >= arrQueue->capacity)
		arrQueue->front = arrQueue->front % arrQueue->capacity;
	arrQueue->num_elements--;
	return pData;
}
