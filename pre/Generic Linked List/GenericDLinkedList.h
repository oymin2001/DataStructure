#include"Node.h"
#include<iomanip>
template<typename E>
class DLinkedList
{
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const E& front() const;
	const E& back() const;
	void addFront(const E& e);
	void addBack(const E& e);
	void removeFront();
	void removeBack();
	void printDLL();

protected:
	void add(DNode<E>* v, const E& e);
	void remove(DNode<E>* v);

private:
	int num_elements;
	DNode<E>* pFront;
	DNode<E>* pEnd;
};

template<typename E>
DLinkedList<E>::DLinkedList()
{
	pFront = NULL;
	pEnd = NULL;
	num_elements = 0;
}
template<typename E>
DLinkedList<E>::~DLinkedList()
{
	while (!empty())
	{
		removeFront();
		pFront = NULL;
		pEnd = NULL;
	}
}
template<typename E>
bool DLinkedList<E>::empty() const
{
	return (pFront == NULL);
}

template<typename E>
const E& DLinkedList<E>::front() const
{
	return(pFront->getElem);
}
template<typename E>
const E& DLinkedList<E>::back() const
{
	return(pEnd->getElem);
}
template<typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e)
{
	DNode<E>* u = new DNode<E>;
	u->setElem(e);
	u->setNext(v);

	if (v == NULL)
	{
		pFront = pEnd = u;
		u->setPrev(NULL);
	}
	else if (v == pFront)
	{
		u->setPrev(NULL);
		v->setPrev(u);
		pFront = u;
	}
	else
	{
		u->setPrev(v->getPrev());
		(v->getPrev())->setNext(u);
		v->setPrev(u);
	}
	num_elements++;
}
template<typename E>
void DLinkedList<E>::addFront(const E& e)
{
	DNode<E>* u = new DNode<E>;
	u->setElem(e);
	u->setPrev(NULL);
	if (pFront != NULL)
		u->setNext(pFront);
	pFront = u;
	num_elements++;
	if (num_elements == 1)
		pEnd = u;
}
template<typename E>
void DLinkedList<E>::addBack(const E& e)
{
	DNode<E>* u = new DNode<E>;
	u->setElem(e);
	u->setNext(NULL);
	if (pEnd != NULL)
		u->getprev(pEnd);
	pEnd = u;
	num_elements++;
	if (num_elements == 1)
		pFront = u;
}
template<typename E>
void DLinkedList<E>::remove(DNode<E>* v)
{
	DNode<E>* u;
	DNode<E>* w;
	if ((v == NULL) || (num_elements <= 0))
		return;
	if (v == pFront)
	{
		pFront = v->getNext();
		if (pFront != NULL)
			pFront->setPrev(NULL);
	}
	else if(v == pEnd)
	{
		pEnd = v->getPrev();
		if (pEnd != NULL)
			pEnd->setNext(NULL);
	}
	else
	{
		u = v->getPrev();
		w = v->getNext();
		if (u != NULL)
			u->setNext(w);
		if (w != NULL)
			w->setPrev(u);
	}
	delete v;
	num_elements--;
	if (num_elements == 0)
		pFront = pEnd = NULL;
}
template<typename E>
void DLinkedList<E>::removeFront()
{
	remove(pFront);
}
template<typename E>
void DLinkedList<E>::removeBack()
{
	remove(pEnd);
}
template<typename E>
void DLinkedList<E>::printDLL()
{
	DNode<E>* u = pFront;
	int cnt = 0;
	if (num_elements == 0)
	{
		cout << "DLinkedList is Empty!!" << '\n';
		return;
	}
	while (cnt < num_elements)
	{
		cout << setw(3) << u->getElem() << " ";
		u = u->getNext();
		cnt++;
	}
	cout << '\n';
}