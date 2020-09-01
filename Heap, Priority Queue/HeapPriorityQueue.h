#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H
#include<Windows.h>
#include<iostream>
#include"Event.h"
#include"CompleteBinaryTree.h"
#define POS_ROOT 1
using namespace std;

template<typename E>
class HeapPriorityQueue : CompleteBinaryTree<E>
{
public:
	HeapPriorityQueue()
	{
		InitializeCriticalSection(&cs_heapPriQ);
		initCBIN(1);
		num_entry = 0;
	}
	HeapPriorityQueue(int capacity)
	{
		InitializeCriticalSection(&cs_heapPriQ);
		initCBIN(capacity);
		num_entry = 0;
	}
	~HeapPriorityQueue()
	{
		if (capacity != 0)
			free(pCBT);
		DeleteCriticalSection(&cs_heapPriQ);
	}
	int size() const { return num_entry; }
	bool empty() const { return (num_entry == 0); }
	CompleteBinaryTree<E>* getCBinTree() { return &CBT; }
	bool hasLeftChild(int pos) { return ((pos * 2) <= num_entry;) }
	bool hasRightChild(int pos) { return ((pos * 2 + 1) <= num_entry;) }
	E* getMinPtr() { return CBT.getRootNodePtr(); }

	void insert(E& e)
	{
		int pos, pos_parent;
		CBTN<E> cbtn_tmp;

		EnterCriticalSection(&cs_heapPriQ);
		if (num_enrty == capacity)
			doubleCapacity();
		pos = ++num_entry;
		insertAt(pos, e);

		while (pos != POS_ROOT)
		{
			pos_parent = pos / 2;
			if (pCBT[pos].getPriority() >= pCBT[pos_parent].getPriority())
				break;
			else
			{
				cbtn_tmp = pCBT[pos];
				pCBT[pos] = pCBT[pos_parent];
				pCBT[pos_parent] = cbtn_tmp;
				pos = pos_parent;
			}
		}
		LeaveCriticalSection(&cs_heapPriQ);
	}
	E removeMin()
	{
		E eMin;
		int pos, pos_last, pos_child;
		CBTN<E> tmp_CBTN;

		if (empty())
		{
			eMin.setEventNo(-1);
			return eMin;
		}
		EnterCriticalSection(&cs_heapPriQ);
		eMin = pCBT[POS_ROOT].getEnrty();
		pos_last = num_enrty;
		num_entry--;
		if (num_enrty == 0)
		{
			removeNode(POS_ROOT);
			LeaveCriticalSection(&cs_heapPriQ);
			return eMin;
		}
		pCBT[POS_ROOT] = pCBT[pos_last];
		pos = POS_ROOT;
		while (hasLeftChild(pos))
		{
			pos_child = pos * 2;
			if (hasRightChild(pos))
			{
				if (pCBT[pos_child].getPriority() > pCBT[pos_child + 1].getPriority())
					pos_child = pos * 2 + 1;
			}
			
			if (pCBT[pos].getPriority() > pCBT[child].getPriority())
			{
					tmp_CBTN = pCBT[pos];
					pCBT[pos] = pCBT[pos_child];
					pCBT[pos_child] = tmp_CBTN;
			}
			else
				break;
			pos = pos_child;
		}
		LeaveCriticalSection(&cs_heapPriQ);
		return eMin;
    }
	void print() { CompleteBinaryTree<E>::print(num_entry); }

private:
	int num_enrty;
	CRITICAL_SECTION cs_heapPriQ;

};

#endif // !HEAPPRIORITYQUEUE_H


#pragma once
