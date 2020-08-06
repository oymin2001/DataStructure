#ifndef LinkedList_cpp
#define LinkedList_cpp

typedef struct ListNode {
	int data;
	struct ListNode* next;

}ListNode;

ListNode* insert_ListNode(ListNode* pList, ListNode* pPrev, int item);
ListNode* delete_ListNode(ListNode* pList, ListNode* pPrev, ListNode* pCurr);
void print_List(ListNode* pList);

#endif 
