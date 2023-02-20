#include<iostream>
#include"Queue.cpp"

Circular_Int_Queue::Circular_Int_Queue(int maxQsize) {
	max_Q_size = maxQsize;
	data = (int*)malloc(sizeof(int) * max_Q_size);
	first_index = last_index = 0;
	num_data = 0;
	for (int i = 0; i < max_Q_size; i++)
	{
		data[i] = -1;
	}
}

void freeQueueBuffer(Circular_Int_Queue* pQ) {
	free(pQ->data);
}

void printQueue(Circular_Int_Queue* pQ) {
	int cnt = 0;
	printf("Current queue (num Data:%2d[", pQ->num_data);
	for (int i = 0; i < pQ->num_data; i++)
	{
		printf(" %2d", pQ->data[(pQ->first_index + i) % pQ->max_Q_size]);
		if (i < pQ->num_data - 1)
			printf(", ");
	}
	printf("])\n");
}
int isQueueFull(Circular_Int_Queue* pQ) {
	if (pQ->num_data == pQ->max_Q_size)
		return 1;
	else
		return 0;
}
int isQueueEmpty(Circular_Int_Queue* pQ) {
	if (pQ->num_data == 0)
		return 1;
	else
		return 0;
}
int enQueue(Circular_Int_Queue* pQ, int data) {
	int idx = -1;
	if (isQueueFull(pQ)) {
		printf("Queue is Full!\n");
		return -1;
	}
	else {
		idx = pQ->last_index;
		pQ->data[idx] = data;
		pQ->last_index = (pQ->last_index + 1) % pQ->max_Q_size;
		pQ->num_data++;
		return 0;
	}
}
int deQueue(Circular_Int_Queue* pQ) {
	int data = 0;
	int idx = -1;
	if (isQueueEmpty(pQ)) {
		printf("Queue is Empty!\n");
		return -1;
	}
	else {
		idx = pQ->first_index;
		data = pQ->data[idx];
		pQ->data[idx] = -1;
		pQ->first_index = (pQ->first_index + 1) % pQ->max_Q_size;
		pQ->num_data--;
		return data;
	}
}
