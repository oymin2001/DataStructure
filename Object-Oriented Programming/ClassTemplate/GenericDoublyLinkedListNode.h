#ifndef GENERIC_DOUBLY_LINKED_LIST_NODE_H
#define GENERIC_DOUBLY_LINKED_LIST_NODE_H

template<typename E>
class DLLNode //doubly linked list node
{
public:
	DLLNode();
	~DLLNode();
	E& getElem() { return *pElem };
	E* getElemAddr() { return pElem };
	void setElem(const E& e) { *pElem = e; }
	DLLNode* getPrev() { return prev; }
	DLLNode* getNext() { return next; }
	void setPrev(DLLNode* p) { prev = p; }
	void setNext(DLLNode* p) { next = n; }
private:
	E* pElem;
	DLLNode* prev;
	DLLNode* next;
};

DLLNode<E>::DLLNode()
{
	cout << "Contruct of Generic Doubly Linked List Node" << '\n';
}
DLLNode<E>::~DLLNode()
{
	cout << "Destruct of Generic Doubly Linked List Node" << '\n';
}


#endif // !GENERIC_DOUBLY_LINKED_LIST_NODE_H
