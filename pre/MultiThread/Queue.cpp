#ifndef CIRCULAR_INT_Q_CPP
#define CIRCULAR_INT_Q_CPP

typedef struct Circular_Int_Queue{
    int* data;
    int max_Q_size;
    int first_index;
    int last_index;
    int num_data;
    Circular_Int_Queue(int maxQsize);
}Circular_Int_Queue;

void printQueue(Circular_Int_Queue* pQ);
int isQueueFull(Circular_Int_Queue* pQ);
int isQueueEmpty(Circular_Int_Queue* pQ);
int enQueue(Circular_Int_Queue* pQ, int data);
int deQueue(Circular_Int_Queue* pQ);
void freeQueueBuffer(Circular_Int_Queue* pQ);

#endif
