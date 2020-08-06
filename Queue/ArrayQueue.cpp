#ifndef Array_Queue_cpp
#define Array_Queue_cpp


typedef struct {
    int* CirQ;
    int capacity;
    int front;
    int end;
    int num_elements;
}Array_Queue;

Array_Queue* initQueue(Array_Queue* pIntArrayQueue, int capacity);
int* expandQueue(Array_Queue* arrQueue);
void printQueue(Array_Queue* arrQueue);
bool isQueueFull(Array_Queue* arrQueue);
bool isQueueEmpty(Array_Queue* arrQueue);
void enQueue(Array_Queue* arrQueue, int data);
int* deQueue(Array_Queue* arrQueue);

#endif