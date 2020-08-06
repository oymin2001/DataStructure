#include<iostream>
#include"LinkedList.cpp"


//pList=  �������Ʈ  ,pPrev= ���Ḯ��Ʈ���� ���ο����� ����� �������
ListNode* insert_ListNode(ListNode* pList, ListNode* pPrev, int item) {
	ListNode* pNew = NULL;
	if (!(pNew = (ListNode*)malloc(sizeof(ListNode)))) {
		printf("�޸� ���� �Ҵ� ����\n");
		exit(1);
	}

	pNew->data = item;
	if (pPrev == NULL) {//���Ḯ��Ʈ ó���� ����
		pNew->next = pList;
		pList->next = pNew;
	}
	else {//���Ḯ��Ʈ �߰��� ����
		pNew->next = pPrev->next;
		pPrev->next = pNew;
	}
	return pList;
}
//pCurr=������ ���
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
