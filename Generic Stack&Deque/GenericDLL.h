#ifndef GENERIC_DLL_H
#define GENERIC_DLL_H

#include<iomanip>
#include"Node.h"

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
	DNode<E>* header;
	DNode<E>* trailer;
};

template<typename E>
DLinkedList<E>::DLinkedList()
{
	header = new DNode<E>;
	trailer = new DNode<E>;
	header->setNext(trailer);
	trailer->setPrev(header);
}
template<typename E>
DLinkedList<E>::~DLinkedList()
{
	while (!empty())
		removeFront();
	delete header;
	delete trailer;
}
template<typename E>
bool DLinkedList<E>::empty() const
{
	return (header->getNext()==trailer);
}

template<typename E>
const E& DLinkedList<E>::front() const
{
	return((header->getNext())->getElem());
}
template<typename E>
const E& DLinkedList<E>::back() const
{
	return((trailer->getPrev())->getElem());
}
template<typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e)
{
	DNode<E>* u = new DNode<E>;
	u->setElem(e);
	u->setNext(v);
	u->setPrev(v->getPrev());
	(v->getPrev())->setNext(u);
	v->setPrev(u);
}
template<typename E>
void DLinkedList<E>::addFront(const E& e)
{
	add(header->getNext(), e);
}
template<typename E>
void DLinkedList<E>::addBack(const E& e)
{
	add(trailer, e);
}
template<typename E>
void DLinkedList<E>::remove(DNode<E>* v)
{
	DNode<E>* u=v->getPrev();
	DNode<E>* w=v->getNext();
	u->setNext(w);
	w->setPrev(u);
	delete v;
	
}
template<typename E>
void DLinkedList<E>::removeFront()
{
	remove(header->getNext());
}
template<typename E>
void DLinkedList<E>::removeBack()
{
	remove(trailer->getPrev());
}
template<typename E>
void DLinkedList<E>::printDLL()
{
	DNode<E>* u = header->getNext();
	while (u!=trailer)
	{
		cout << setw(3) << u->getElem() << " ";
		u = u->getNext();
	}
	cout << '\n';
}


#endif // !GENERIC_ARRAYQUEUE_H

#pragma once
