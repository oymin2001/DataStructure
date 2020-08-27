#include<string>
#include"GenericDLL.h"
#include"Exceptions.h"
using namespace std;

template<typename Elem>
class LinkedDeque
{
public:
	LinkedDeque();
	int size() const;
	bool empty() const;
	const Elem& front_DeQ() throw(DequeEmpty);
	const Elem& back_DeQ() throw(DequeEmpty);
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void removeFront() throw(DequeEmpty);
	void removeBack() throw(DequeEmpty);
	void printDeQ() throw(DequeEmpty);

private:
	DLinkedList<Elem> D;
	int n;
};

template<typename Elem>
LinkedDeque<Elem>::LinkedDeque()
{
	cout << "LinkedDeque::Constructor()" << '\n';
	n = 0;
}
template<typename Elem>
int LinkedDeque<Elem>::size() const
{
	return n;
}
template<typename Elem>
bool LinkedDeque<Elem>::empty() const
{
	return(n == 0);
}
template<typename Elem>
const Elem& LinkedDeque<Elem>::front_DeQ() throw(DequeEmpty)
{
	Elem e;
	e = D.front();
	return (e);
}
template<typename Elem>
const Elem& LinkedDeque<Elem>::back_DeQ() throw(DequeEmpty)
{
	Elem e;
	e = D.back();
	return (e);
}
template<typename Elem>
void LinkedDeque<Elem>::insertFront(const Elem& e)
{
	D.addFront(e);
	n++;
}
template<typename Elem>
void LinkedDeque<Elem>::insertBack(const Elem& e)
{
	D.addBack(e);
	n++;
}
template<typename Elem>
void LinkedDeque<Elem>::removeFront() throw(DequeEmpty)
{
	if (empty()) throw DequeEmpty("removeFront of empty deque");
	D.removeFront();
	n--;
}
template<typename Elem>
void LinkedDeque<Elem>::removeBack() throw(DequeEmpty)
{
	if (empty()) throw DequeEmpty("removeBack of empty deque");
	D.removeBack();
	n--;
}
template<typename Elem>
void LinkedDeque<Elem>::printDeQ() throw(DequeEmpty)
{
	if (!empty())
		D.printDLL();
}
#pragma once
