#include<iostream>
#include"DoublyLinkedList.cpp"
#include<ctime>
#define NUM_STARS 10

int main() {
	Galaxy* pGlx;
	Star* pS;
	int* starID, i;

	pGlx = (Galaxy*)malloc(sizeof(Galaxy));
	pGlx->pFirst =NULL;
	pGlx->pLast = NULL;
	pGlx->num_Star = 0;

	starID = new int[NUM_STARS];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NUM_STARS; i++)
	{
		starID[i] = rand();
	}


	printf("Inserting Stars into Galaxy using insertListNodeInOrder()...\n");
	for (int i = 0; i < NUM_STARS; i++)
	{
		pS = genStar(starID[i]);
		insertListNodeInOrder(pGlx,pS);
		printf("Galaxy after insertListNodeInOrder(%d)\n", pS->id);
		printGalaxy(pGlx);
	}
	printf("\nDeleting Stars from Galaxy using removeFromHead()...\n");
	for (i = 0; i < NUM_STARS; i++)
	{
		pS = removeFromHead(pGlx);
		if (pS != NULL) {
			printf("Galaxy after ListNode (id:%d) remove from head of the linked list:\n", pS->id);
			printGalaxy(pGlx);
			free(pS);
		}
		pS = getFromHead(pGlx);
		if (pS != NULL)
			printf("New head in list of Galaxy:%d\n", pS->id);
	}
	free(pGlx);
	return 0;
}
