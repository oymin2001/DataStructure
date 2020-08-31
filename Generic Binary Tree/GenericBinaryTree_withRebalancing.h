#include<iostream>
#include<list>
#include"GenericTreeNode.h"
#include<algorithm>

template<typename E>
class BinaryTree
{
private:
	TreeNode<E>* _root;
	int n;

public:
	TreeNode<E>** getRootaddr() { return &_root; }
	TreeNode<E>* insertAndRebalance(TreeNode<E>** ppTN, const E& e)
	{
		TreeNode<E>* pTN;

		if (*ppTN == NULL)
		{
			pTN = new TreeNode<E>(e);
			*ppTN = pTN;
			(*ppTN)->setpLeft(NULL);
			(*ppTN)->setpRight(NULL);
			n++;
		}
		else if (e < (*ppTN)->getElement())
		{
			pTN = insertAndRebalance((*ppTN)->getppLeft(), e);
			(*ppTN)->setpLeft(pTN);
			*ppTN = reBalance(ppTN);
		}
		else
		{
			pTN = insertAndRebalance((*ppTN)->getppRight(), e);
			(*ppTN)->setpRight(pTN);
			*ppTN = reBalance(ppTN);
		}
		return *ppTN;
	}

	class Position {
	private:
		TreeNode<E>* pTN;
	public:
		Position(TreeNode<E>* _v = NULL):pTN(_v){}
		void setpTN(TreeNode<E>* pV) { pTN = pV; }
		TreeNode<E>* getTN() { return pTN; }
		E& operator*() { return pTN->getElement(); }
		Position left() const { return Position(pTN->getpLeft()); }
		Position right() const { return Position(pTN->getpRight()); }
		Position parent() const { return Position(pTN->getpParent()); }
		void setLeft(Position& pos) { pTN->setpLeft(pos.pTN); }
		void setRight(Position& pos) { pTN->setpRight(pos.pTN); }
		void setParent(Position& pos) { pTN->setpParent(pos.pTN); }
		bool isNULL() { return (pTN == NULL); }
		bool isRoot() const { return(pTN->getpParent() == NULL); }
		bool isExternal() const { return ((pTN->getpLeft()) == NULL) && (pTN->getpRight() == NULL); }
	};
	typedef std::list<Position> PositionList;
public:
	BinaryTree():_root(NULL),n(0){}
	int size() const { return n; }
	bool empty() const { return size == 0; }
	Position root() const { return Position(_root); }
	PositionList positions() const
	{
		PositionList pl;
		preorder(_root, pl);
		return PositionList(pl);
	}
	void addRoot() { _root = new TreeNode<E>; n = 1; }
	void expandExternal(Position& pos)
	{
		if (pos.isNULL())
		{
			std::cout << "Error in BinaryTree<E>::expandExternal()!!: given pos is NULL!!" << '\n';
			return;
		}
		if (!pos.isExternal())
		{
			std::cout << "Error in BinaryTree<E>::expandExteranl()!!: given pos is not external!!" << '\n';
			return;
		}
		TreeNode<E>* v = pos.getpTN();
		v->setpLeft(new TreeNode<E>);
		(v->getpLeft())->setpParent(v);
		v->setpRight(new TreeNode<E>);
		(v->getpRight())->setpParent(v);
		n += 2;
	}
	Position removeAboveExternal(Position& p)
	{
		if (!p.isExternal())
		{
			std::cout << "Error in BinaryTree<E>::removeAboveExternal()!!" << '\n';
			return Position(NULL);
		}

		TreeNode<E>* w = p.getpTN();
		TreeNode<E>* v = w->getpParent();
		TreeNode<E>* sib = (w == v->getpLeft() ? v->getpRight() : v->getpLeft());
		if (v == _root)
		{
			_root = sib;
			sib->setpParent(NULL);
		}
		else
		{
			TreeNode<E>* gpar = v->getpParent();
			if (v == gpar->getpLeft())
				gpar->setpLeft(sib);
			else
				gpar->setpRight(sib);
			sib->setpParent(gpar);
		}
		delete w; delete v;
		n -= 2;
		return Position(sib);
	}
	Position& addElementOrder(Position& pos, Position& parenpos, const E& e)
	{
		BinaryTree<E>::Position newPos, childPos, nullPos;
		TreeNode<E>* pTN;

		if (pos.isNULL())
		{
			pTN = new TreeNode<E>(e);
			pos.setpTN(pTN);
			if (parenpos.isNULL())
				_root = pos.getTN();
			pos.setParent(parenpos);

			n++;
			newPos = BinaryTree::Position(pTN);
			return newPos;
		}
		else if (e < *pos)
		{
			childPos = pos.left();
			newPos = addElementOrder(childPos, pos, e);
			if (!newPos.isNULL())
				pos.setLeft(newPos);
			return nullPos;
		}
		else if (e > * pos)
		{
			childPos = pos.right();
			newPos = addElementOrder(childPos, pos, e);
			if (!newPos.isNULL())
				pos.setRight(newPos);
			return nullPos;
		}
		else
			std::cout << "Duplicated element in addElementOrder!!" << '\n';
	}

	void printTreeInOrder(Position pos)
	{
		if (pos.isNULL())
			return;
		printTreeInOrder(pos.left());
		std::cout << *pos << " ";
		printTreeInOrder(pos.right());
	}
	void printTreeByLevel(Position pos, int level)
	{
		TreeNode<E>* pChild = NULL;
		Position childPos;

		if (!pos.isNULL())
		{
			if (level == 0)
				std::cout << "\nRoot (data:";
			std::cout << *pos;
			std::cout << ")" << '\n';

			childPos = pos.left();
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			if (!childPos.isNULL())
			{
				std::cout << "L (data:";
				printTreeByLevel(childPos, level + 1);
			}
			else
				std::cout << "L (NULL)" << '\n';

			childPos = pos.right();
			for (int i = 0; i < level; i++)
				std::cout << "   ";
			if (!childPos.isNULL())
			{
				std::cout << "R (data:";
				printTreeByLevel(childPos, level + 1);
			}
			else
				std::cout << "R (NULL)" << '\n';
		}
	}
protected:
	void preorder(TreeNode<E>* pTN, PositionList& pl) const
	{
		pl.push_back(Position(pTN));
		if (pTN->getpLeft() != NULL)
			preorder(pTN->getpLeft(), pl);
		if (pTN->getpRight() != NULL)
			preorder(pTN->getpRight(), pl);
	}
	TreeNode<E>* rotate_LL(TreeNode<E>* pParent)
	{
		TreeNode<E>* pChild;

		pChild = pParent->getpLeft();
		pParent->setpLeft(pChild->getpRight());
		pChild->setpRight(pParent);
	}
	TreeNode<E>* rotate_RR(TreeNode<E>* pParent)
	{
		TreeNode<E>* pChild;

		pChild = pParent->getpRight();
		pParent->setpRight(pChild->getpLeft());
		pChild->setpLeft(pParent);
	}
	TreeNode<E>* rotate_LR(TreeNode<E>* pParent)
	{
		TreeNode<E>* pChild;

		pChild = pParent->getpRight();
		pParent->setpRight(rotate_LL(pChild));

		return rotate_RR(pParent);
	}
	TreeNode<E>* rotate_RL(TreeNode<E>* pParent)
	{
		TreeNode<E>* pChild;

		pChild = pParent->getpLeft();
		pParent->setpLeft(rotate_RR(pChild));

		return rotate_LL(pParent);
	}
	int getHeight(TreeNode<E>* pTN)
	{
		int height = 0;

		if (pTN != NULL)
			height = 1 + max(getHeight(pTN->getpLeft()),getHeight(pTN->getpRight()));

		return height;
	}
	int getHeightDiff(TreeNode<E>* pTN)
	{
		int heightDiff = 0;

		if (pTN == NULL)
			return 0;
		heightDiff = getHeight(pTN->getpLeft()) - getHeight(pTN->getpRight());

		return heightDiff;
	}
	TreeNode<E>* reBalance(TreeNode<E>** ppTN)
	{
		int heightDiff = 0;

		heightDiff = getHeightDiff(*ppTN);
		if (heightDiff > 1)
		{
			if (getHeightDiff((*ppTN)->getpLeft()) > 0)
				*ppTN = rotate_LL(*ppTN);
			else
				*ppTN = rotate_LR(*ppTN);
		}
		else if(heightDiff<-1)
		{
			if (getHeightDiff((*ppTN)->getpRight()) < 0)
				*ppTN = rotate_RR(*ppTN);
			else
				*ppTN = rotate_RL(*ppTN);
		}

		return *ppTN;
	}

};



#pragma once
