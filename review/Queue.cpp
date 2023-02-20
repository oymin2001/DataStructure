#include <iostream>
#include "LinkdedList.cpp"

typedef struct Queue
{
    Node* front;
    Node* rear;
    int NumOfNode;

}Queue;

void initQueue(Queue* queue)
{
    queue->front = queue->rear = NULL;
    queue->NumOfNode = 0;
}

bool isEmpty(Queue* queue)
{
    return queue->NumOfNode == 0;
}

void enqueue(Queue* queue, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
    }
    else 
    {
        queue->rear->next = newNode; // 기존 맨뒤에 있던 노드 포인터를 newNode로 지정
    }
    queue->rear = newNode;
    queue->NumOfNode++;
}

int dequeue(Queue* queue)
{
    int data;
    Node* ptr;

    if (isEmpty(queue))
    {
        printf("Error: Queue is Empty");
        return 0;
    }

    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->NumOfNode--;

    return data;
    
}
