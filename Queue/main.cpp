#include<iostream>
#include"ArrayQueue.cpp"
#define INIT_QUEUE_CAPACITY 1

int main() {
	Array_Queue* pIntArrayQueue;
	int* pD;

	pIntArrayQueue = (Array_Queue*)malloc(sizeof(Array_Queue));
	printf("Intializing integer queue of capacity (%d)\n", INIT_QUEUE_CAPACITY);
	pIntArrayQueue = initQueue(pIntArrayQueue, INIT_QUEUE_CAPACITY);
	printQueue(pIntArrayQueue);
	printf("\nEnqueuing data into integer quene \n");
	for (int i = 0; i < 10; i++)
	{
		printf("Enqueue data (%2d),", i);
		enQueue(pIntArrayQueue, i);
		printQueue(pIntArrayQueue);
	}
	printf("\nDequeuing data from integer queue\n");
	for (int i = 0; i < 10; i++)
	{
		pD = deQueue(pIntArrayQueue);
		if (pD != NULL)
		{
			printf("Dequed data = %2d,", *pD);
			printQueue(pIntArrayQueue);
		}

	}
	return 0;
}


