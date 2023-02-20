#ifndef GALAXY_CPP
#define GALAXY_CPP

typedef struct Star {
	char name[16];
	int id;
	double distance;
	double luminosity;
	double mass;
	double radius;
	int age;
}Star;

typedef struct ListNode {
	Star* pS;
	ListNode* pPrev;
	ListNode* pNext;
}ListNode;

typedef struct Galaxy {
	ListNode* pFirst; //head
	ListNode* pLast;  //tail
	int num_Star;
}Galaxy;

Star* genStar(int starID);
void insertListNodeAtTail(Galaxy* pGlx, Star* pStar);
void insertListNodeInOrder(Galaxy* pGlx, Star* pStar);
Star* removeFromHead(Galaxy* pGlx);
Star* getFromHead(Galaxy* pGlx);
void printGalaxy(Galaxy* pGlx);



#endif 
