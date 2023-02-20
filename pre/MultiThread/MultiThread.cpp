#include<iostream>
#include<Windows.h>
#include<ctime>
#include"Queue.cpp"

#define MAX_QUEUE_SIZE 10
#define THREAD_EXECUTION_TIME 10000
enum ROLE { PRODUCER, CONSUMER };

typedef struct ThreadParam {
	Circular_Int_Queue* queue;
	CRITICAL_SECTION* pCS;
	int role;
}ThreadParam;

DWORD WINAPI Thread_producer(LPVOID pParam);
DWORD WINAPI Thread_consumer(LPVOID pParam);

Circular_Int_Queue circular_IntQ(MAX_QUEUE_SIZE);
CRITICAL_SECTION crit;
ThreadParam* pThrParam;
HANDLE hThreadProducer;
HANDLE hThreadConsumer;
DWORD nExitCode = NULL;


int main() {

	Circular_Int_Queue circular_IntQ(MAX_QUEUE_SIZE);
	CRITICAL_SECTION crit;
	ThreadParam* pThrParam;
	HANDLE hThreadProducer=0;
	HANDLE hThreadConsumer=0;
	DWORD nExitCode = NULL;

	Circular_Int_Queue* pQ = &circular_IntQ;
	InitializeCriticalSection(&crit);

	pThrParam = (ThreadParam*)malloc(sizeof(ThreadParam));
	pThrParam->pCS = &crit;
	pThrParam->queue = pQ;
	pThrParam->role = CONSUMER;
	hThreadConsumer = CreateThread(NULL, 0, Thread_consumer, pThrParam, 0, NULL);
	printf("Thread consumer has been created and instantitated ..\n");

	pThrParam = (ThreadParam*)malloc(sizeof(ThreadParam));
	pThrParam->pCS = &crit;
	pThrParam->queue = pQ;
	pThrParam->role = PRODUCER;
	hThreadConsumer = CreateThread(NULL, 0, Thread_producer, pThrParam, 0, NULL);
	printf("Thread producer has been created and instantitated ..\n");

	printf("Waiting for the termination of thread prodecer..\n");
	WaitForSingleObject(hThreadProducer, THREAD_EXECUTION_TIME);
	GetExitCodeThread(hThreadProducer, &nExitCode);
	TerminateThread(hThreadProducer, nExitCode);
	CloseHandle(hThreadProducer);
	printf("Thread producer is now terminated ..\n");

	printf("Waiting for the termination of thread consumer..\n");
	WaitForSingleObject(hThreadConsumer, THREAD_EXECUTION_TIME);
	GetExitCodeThread(hThreadConsumer, &nExitCode);
	TerminateThread(hThreadConsumer, nExitCode);
	CloseHandle(hThreadConsumer);
	printf("Thread consumer is now terminated ..\n");
}

DWORD WINAPI Thread_producer(LPVOID pParam) {
	ThreadParam* pThrParam;
	pThrParam = (ThreadParam*)pParam;
	Circular_Int_Queue* pQ = pThrParam->queue;
	int data = 0;
	int sleep_time_ms = 0;
	int enQ_res;
	srand(time(NULL));
	while (1) {
		data = rand() % 100;
		EnterCriticalSection(pThrParam->pCS);
		printf("Thread_prodecer::enqueue(data ==% 2d) => ", data);
		enQ_res = enQueue(pQ, data);
		LeaveCriticalSection(pThrParam->pCS);
		if (enQ_res != -1) {
			EnterCriticalSection(pThrParam->pCS);
			printQueue(pQ);
			LeaveCriticalSection(pThrParam->pCS);
	}
		else {// isQueueFull
			do {
				Sleep(200);
				EnterCriticalSection(pThrParam->pCS);
				enQ_res = enQueue(pQ, data);
				LeaveCriticalSection(pThrParam->pCS);
			} while (enQ_res == -1);
			EnterCriticalSection(pThrParam->pCS);
			printQueue(pQ);
			LeaveCriticalSection(pThrParam->pCS);
		}
		sleep_time_ms = rand() % 500;
		Sleep(sleep_time_ms);
	}
	return 0;
}

DWORD WINAPI Thread_consumer(LPVOID pParam) {
	ThreadParam* pThrParam;
	pThrParam = (ThreadParam*)pParam;
	Circular_Int_Queue* pQ = pThrParam->queue;
	int sleep_time_ms = 0,dequeue_data=-1;
	srand(time(NULL));
	while (1) {
		EnterCriticalSection(pThrParam->pCS);
		printf("Thread_prodecer::dequeue() => ");
		dequeue_data= deQueue(pQ);
		if (dequeue_data > -1) {
			printf("dequeue data (%2d)", dequeue_data);
			printQueue(pQ);
		}
		LeaveCriticalSection(pThrParam->pCS);
		sleep_time_ms = rand() % 1000;
		Sleep(sleep_time_ms);
	}
	return 0;
}
