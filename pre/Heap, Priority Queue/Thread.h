#ifndef THREAD_H
#define THREAD_H
#include<Windows.h>
#include<time.h>
#include"Event.h"
#include"HeapPriorityQueue.h"


enum ROLE { EVENT_GENERATOR,EVENTHANDLER};
enum THREAD_FLAG {INITIALIZE,RUN,TERMINATE};

typedef struct ThreadStatusMonitor
{
	int numEventGenerated;
	int numEventProcessed;
	int totalEventGenerated;
	int totalEventProcessed;
	Event eventProcessed[TOTAL_NUM_EVENTS];
	THREAD_FLAG* pFlagThreadTerminate;
}ThreadStatusMonitor;

typedef struct ThreadParam
{
	CRITICAL_SECTION* pCS_main;
	CRITICAL_SECTION* pCS_thrd_mon;
	HeapPriorityQueue<Event>* pPriQ_Event;
	ROLE role;
	int myAddr;
	int maxRound;
	int targetEventGen;
	ThreadStatusMonitor* pThredMon;
}ThreadParam_Event;

DWORD WINAPI Thread_EventHandler(LPVOID pParam)
{
	ThreadParam Event* pThrdParam;
	HeapPriorityQueue<Event>* pPriQ_Event;
	int myRole;
	THREAD_FLAG* pFlagThreadTerminate;
	int maxRound;
	Event event, *pEvent;
	int event_no = 0;
	int event_priority = 0;
	int event_gen_count = 0;
	int targetEventGen;
	int myAddr = -1;
	int event_handler_addr;
	ThreadStatusMonitor* pThrdMon;
	pThrdParam = (ThreadParam_Event*)pParam;
	myRole = pThrdParam->role;
	myAddr = pThrdParam->myAddr;
	pPriQ_Event = pThrdParam->pPriQ_Evnet;
	pThrdMon = pThrdParam->pThrdMon;
	maxRound = pThrdParam->maxRound;
	targetEventGen = pThrdParam->targetEventGen;

	srand(time(NULL));
	for (int round = 0; round < maxRound; round++)
	{
		if (event_gen_count >= targetEventGen)
		{
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
				break;
			else
			{
				Sleep(500);
				continue;
			}
		}
		event_no = event_gen_count + NUM_EVENTS_PER_GEN * myAddr;
		event_priority = targetEventGen - event_gen_count - 1;
		event.setEventNo(event_no);
		event.setEventPri(event_priority);
		event.setEventGenAddr(myAddr);
		event.setEventHanlerAddr(-1);
		event.setEvenStatus(GENERATED);
		pPriQ_Event->insert(event);

		EnterCriticalSection(pThrdParam->pCS_thrd_mon);
		pThrdMon->numEventGenerated++;
		pThrdMon->totalEventGenerated++;
		LeaveCriticalSection(pThrdParam->pCS_thrd_mon);
		event_gen_count++;
		Sleep(10);
	}
	return 0;
}
DWORD WINAPI Thread_EventGenerator(LPVOID pParam) 
{
	ThreadParam Event* pThrdParam;
	HeapPriorityQueue<Event>* pPriQ_Event;
	int myRole;
	int myAddr;
	THREAD_FLAG* pFlagThreadTerminate;
	int maxRound;
	Event event, * pEvent, * pEventProc;
	int event_no = 0;
	int eventPiority = 0;
	int event_gen_count = 0;
	int num_pkt_processed=0;
	int targetEventGen;
	ThreadStatusMonitor* pThrdMon;
	pThrdParam = (ThreadParam_Event*)pParam;
	myRole = pThrdParam->role;
	myAddr = pThrdParam->myAddr;

	pPriQ_Event = pThrdParam->pPriQ_Evnet;
	pThrdMon = pThrdParam->pThrdMon;
	maxRound = pThrdParam->maxRound;
	targetEventGen = pThrdParam->targetEventGen;

	srand(time(NULL));
	for (int round = 0; round < maxRound; round++)
	{
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)
				break;
		event = pPriQ_Event->removeMin();
		if (event.getEventNo() != -1)
		{
			EnterCriticalSection(pThrdParam->pCS_thrd_mon);
            event.setEventHandlerAddr(myAddr);
			pThrdMon->numEventProcessed[pThrdMon->totalEventProcessed] = event;
			pThrdMon->numEventProcessed++;
			pThrdMon->totalEventProcessed++;
			LeaveCriticalSection(pThrdParam->pCS_thrd_mon);
		}
		Sleep(300 + rand() % 500);
	}
	return 0;
}


#endif // ! THREAD_H


#pragma once
