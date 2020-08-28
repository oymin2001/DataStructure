#include<iostream>
#include"GenericBinaryTree.h"
#define NUM_DATA 10
using namespace std;


int main()
{
	BinaryTree<int>* pInt_BT;
	int data[NUM_DATA] = { 4,3,7,2,0,9,8,5,1,6 };

	pInt_BT = new BinaryTree<int>;
	cout << '\n';
	BinaryTree<int>::Position intBTpos_root = pInt_BT->root();
	BinaryTree<int>::Position intBTpos_NULL(NULL);
	for (int i = 0; i < 10; i++)
	{
		cout << "Adding " << data[i] << "into BinaryTree" << '\n';
		pInt_BT->addElementOrder(intBTpos_root, intBTpos_NULL, data[i]);
	}
	cout << "\n Elements in BinaryTree in order: " << '\n';
	pInt_BT->printTreeInOrder(intBTpos_root);
	cout << '\n';

	pInt_BT->printTreeByLevel(intBTpos_root, 0);
	cout << '\n';

}