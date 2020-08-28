#ifndef GENERIC_TREENODE_H
#define GENERIC_TREENODE_H


template<typename E>
class TreeNode {
public:
	TreeNode():element(),pParent(NULL),pLeft(NULL),pRight(NULL) {}
	TreeNode(E e):element(e), pParent(NULL), pLeft(NULL), pRight(NULL) {}
	E& getElement() { return element; }
	E* getElementAddr() { return &element; }
	void setElement(E e) { element = e; }
	
	TreeNode* getpParent() { return pParent; }
	TreeNode* getpLeft() { return pLeft; }
	TreeNode* getpRight() { return pRight; }

	TreeNode** getppLeft() { return &pLeft; }
	TreeNode** getppRight() { return &pRight; }
	void setpParent(TreeNode* pTN) { pParent = pTN; }
	void setpLeft(TreeNode* pTN) { pLeft = pTN; }
	void setpRight(TreeNode* pTN) { pRight = pTN; }

private:
	E element;
	TreeNode* pParent;
	TreeNode* pLeft;
	TreeNode* pRight;
};



#endif // !GENERIC_TREENODE_H


#pragma once
