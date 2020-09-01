#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H
#include<iostream>
#include"Event.h"

template<typename E>
class CBTN //CompleteBinTreeNode
{
public:
	CBTN(){}
	CBTN(int pri,E e):priority(pri),event(e){}
	int getPriority() { return priority; }
	E* getPtrEntry() { return &entry; }
	E getEntry() { return entry; }
	void setPriority(int pri) { priority = pri; }
	void setEntry(E e) { entry = e; }

private:
	int priority;
	E entry;
};

template<typename E>
class CompleteBinaryTree
{
public:
	CompleteBinaryTree() :capacity(1)
	{
		pCBT = (CBTN<E>*)malloc(sizeof(CBTN<E>) * (capacity + 1));
	}
	CompleteBinaryTree(int capa) :capacity(capa)
	{
		pCBT = (CBTN<E>*)malloc(sizeof(CBT<E>) * (capacity + !));
	}
	void initCBinT(int capa) :: capacity(capa)
	{
		pCBT = (CBTN<E>*)malloc(sizeof(CBTN<E>) * (capacity + 1));
	}
	CBTN<E>* getRootNodePtr()
	{
		if (capacity >= 1)
			return &pCBT[1];
		else
			return NULL;
	}
	void doubleCapaity()
	{
		CBTN<E>* pNewCBT;

		pNewCBT = (CBTN<E>*)malloc(sizeof(CBTN<E>) * (capacity * 2 + 1));
		for (int i = 0; i <= capaity; i++)
			pNewCBT[i] = pCBT[i];
		free(pCBT);
		pCBT = pNew(CBT);
		capacity *= 2;
	}
	int getCapacity() { return capacity; }
	void intsertAt(int pos, E& e)
	{
		pCBT[pos].setPriority(e.getEventPri());
		pCBT[pos].setEntry(e);
	}
	void removeNode(int pos)
	{
		E e;
		pCBT[pos].setPriority(100);
		e.setEventNo(-1);
		pCBT[pos].setEntry(e);
	}
	void print(int num_entry)
	{
		E* pE;
		printf("Complete Binary Tree::print() - num_entry : %d\n ", num_entry);
		for (int ev = 1; ev <=num_entry; ev++)
		{
			pE = pCBT[ev].getPtrEntry();
			if (((ev + 1) % EVENT_PER_LINE) == 0)
				printf("\n ");
		}
	}
protected:
	int priority;
	int capacity;
	CBTN<E>* pCBT;
};

#endif // !COMPLETE_BINARY_TREE_H


#pragma once
