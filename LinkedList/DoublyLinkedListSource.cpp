#include<iostream>
#include"DoublyLinkedList.cpp"
#define NUM_STARS 10

Star* genStar(int starID) {
	Star* pNew;
	int name_len;

	pNew = (Star*)malloc(sizeof(Star));
	name_len = rand() % 6 + 5;

	pNew->name[0] = rand() % 26 + 'A';
	for (int i = 1; i < name_len; i++) {
		pNew->name[i] = rand() % 26 + 'a';
	}
	pNew->name[name_len] = '\0';
	pNew->id = starID;
	pNew->distance = (double)(rand() % 10000 + 10.0);
	pNew->luminosity = (double)(rand() % 10000 + 10.0);
	pNew->mass = (double)(rand() % 10000 + 10.0);
	pNew->radius = (double)(rand() % 10000 + 10.0);
	pNew->age = rand() % 10000 + 10;

	return pNew;
}


void insertListNodeAtTail(Galaxy* pGlx, Star* pStar) {
	ListNode* pNew;

	pNew = (ListNode*)malloc(sizeof(ListNode));
	pNew->pNext = NULL;
	pNew->pPrev = NULL;
	pNew->pS = pStar;
	if (pGlx->num_Star == 0) {
		pGlx->pFirst = pGlx->pLast = pNew;
		pGlx->num_Star++;
	}
	else if (pGlx->num_Star < NUM_STARS) {
		pNew->pPrev = pGlx->pLast;
		pGlx->pLast->pNext = pNew;
		pNew->pNext = NULL;
		pGlx->num_Star++;
	}
	else {
		printf("Error in excessive number of Stars(NUM_STARS:%d)\n", NUM_STARS);
	}
}

void insertListNodeInOrder(Galaxy* pGlx, Star* pStar) {
	ListNode* pNew, * pLN; //pLN=현재 방문위치

	pNew = (ListNode*)malloc(sizeof(ListNode));
	pNew->pNext = NULL;
	pNew->pPrev = NULL;
	pNew->pS = pStar;

	if (pGlx->num_Star == 0) {
		pGlx->pFirst = pGlx->pLast = pNew;
		pNew->pNext = NULL;
		pNew->pPrev = NULL;
		pGlx->num_Star++;
	}
	else if (pGlx->num_Star < NUM_STARS) {
		for (pLN = pGlx->pFirst; pLN != NULL;)
		{//id 기준 정렬
			if (pNew->pS->id < pLN->pS->id) {
				pNew->pNext = pLN;
				pNew->pPrev = pLN->pPrev;
				if (pLN != pGlx->pFirst) {
					if (pLN->pPrev != NULL)
						pLN->pPrev->pNext = pNew;
					pLN->pPrev = pNew;
				}
				else {
					pGlx->pFirst = pNew;
					pNew->pPrev = NULL;
					pLN->pPrev = pNew;
				}
				pGlx->num_Star++;
				break;
			}
			else if ((pLN == pGlx->pLast) && (pNew->pS->id >= pLN->pS->id)) {
				pNew->pPrev = pLN;
				pLN->pNext = pNew;
				pGlx->pLast = pNew;
				pNew->pNext = NULL;
				pGlx->num_Star++;
				break;
			}
			else {
				if (pLN != pGlx->pLast)
					pLN = pLN->pNext;
				else break;
			}
		}
	}
	else
		printf("Error in excessive number of Stars(NUM_STARS: %d)\n", NUM_STARS);
}

Star* removeFromHead(Galaxy* pGlx) {
	ListNode* pLN;
	Star* pS;

	if (pGlx->num_Star > 0) {
		pLN = pGlx->pFirst;
		pS = pLN->pS;
		pGlx->pFirst = pGlx->pFirst->pNext;
		if (pGlx->pFirst != NULL)
			pGlx->pFirst->pPrev = NULL;
		pGlx->num_Star--;
		free(pLN);
		return pS;
	}
	else {
		printf("Error in removeFromHead: Linked List is empty\n");
		return NULL;
	}
}

Star* getFromHead(Galaxy* pGlx) {
	if (pGlx->num_Star > 0)
		return pGlx->pFirst->pS;
	else
		return NULL;
}

void printGalaxy(Galaxy* pGlx) {
	ListNode* pLN;
	int cnt = 0;

	printf("Number pf stars: %d\n", pGlx->num_Star);

	pLN = pGlx->pFirst;
	cnt = 0;
	while ((pLN != NULL) && (cnt < NUM_STARS)) {
		printf(" Star_ID (%3d), Name (%s)\n", pLN->pS->id, pLN->pS->name);
		pLN = pLN->pNext;
		cnt++;
	}
}