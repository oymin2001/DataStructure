#ifndef SLINKED_LIST_H
#define SLINKED_LIST_H

#include<iostream>
using namespace std;
#include"Node.h";

template<typename E>
class SLinkedList
{
public:
	SLinkedList();
	~SLinkedList();
	bool empty() const;
	const E& front() const;
	void addFront(const E& e);
	void removeFront();
	void printSLinkedList();

private:
	SNode<E>* head;
};

template<typename E>
SLinkedList<E>::SLinkedList()
	:head(NULL)
{ }

template<typename E>
bool SLinkedList<E>::empty() const
{
	return head == NULL;
}

template<typename E>
const E& SLinkedList<E>::front() const { return head->elem };
template<typename E>
SLinkedList<E>::~SLinkedList()
{
	while (!empty())removeFront();
}
template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	SNode<E>* v = new SNode<E>;
	v->setElem(e);
	v->setNext(head);
	head = v;
}
template<typename E>
void SLinkedList<E>::removeFront()
{
	SNode<E>* old = head;
	head = old->getNext();
	delete old;
}
template<typename E>
void SLinkedList<E>::printSLinkedList()
{
	SNode<E>* v;
	v = head;

	while (v != NULL)
	{
		cout << v->getElem() << " ";
		v = v->getNext();
	}
}
#endif // !SLINKED_LIST_H
