#ifndef NODE_H
#define NODE_H

using namespace std;

template<typename E>
class SNode
{
	
public:
	void setElem(E el) { elem = el; }
	void setNext(SNode<E>* pNext) { next = pNext; }
	SNode<E>* getNext() { return next; }
	E getElem() { return elem; }

private:
	E elem;
	SNode<E>* next;
};


template<typename E>
class DNode
{
public:
	DNode();
	~DNode();
	E getElem() { return elem; }
	void setElem(const E& e) { elem = e; }
	DNode* getPrev() { return prev; }
	DNode* getNext() { return next; }
	void setPrev(DNode* p) { prev = p; }
	void setNext(DNode* n) { next = n; }
private:
	E elem;
	DNode* prev;
	DNode* next;
};
template<typename E>
DNode<E>::DNode()
{
	cout << "Consturct of Generic Doubly LinkedList" << '\n';
}
template<typename E>
DNode<E>::~DNode()
{
	cout << "Desturct of Generic Doubly LinkedList" << '\n';
}
#endif 
