#include<iostream>
#include"LinkedList.cpp"


//pList=  헤드포인트  ,pPrev= 연결리스트에서 새로연결할 노드의 이전노드
ListNode* insert_ListNode(ListNode* pList, ListNode* pPrev, int item) {
	ListNode* pNew = NULL;
	if (!(pNew = (ListNode*)malloc(sizeof(ListNode)))) {
		printf("메모리 동적 할당 오류\n");
		exit(1);
	}

	pNew->data = item;
	if (pPrev == NULL) {//연결리스트 처음에 삽입
		pNew->next = pList;
		pList->next = pNew;
	}
	else {//연결리스트 중간에 삽입
		pNew->next = pPrev->next;
		pPrev->next = pNew;
	}
	return pList;
}
//pCurr=삭제할 노드
ListNode* delete_ListNode(ListNode* pList, ListNode* pPrev, ListNode* pCurr) {
	if (pPrev == NULL)
		pList = pCurr->next;
	else
		pPrev->next = pCurr->next;

	free(pCurr);
	return pList;
}

void print_List(ListNode* pList) {
	ListNode* p;
	int cnt = 0;
	int sum = 0;
	p = pList;
	while (p != NULL) {
		printf("%d", p->data);
		cnt++;
		sum += p->data;
		p = p->next;
	}
	printf("\n");
	printf("Length of List: %d\n", cnt);
	printf("Sum of List: %d\n", sum);
}
