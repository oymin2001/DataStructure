#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP


typedef struct Star {
	char name[16];
	int id;
	double distance;
	int age;
}Star;


typedef struct TreeNode {
	Star* pStar;
	TreeNode* pL;
	TreeNode* pR;
}TreeNode;


//BinaryTreeNode
typedef struct BTN {
	int* data;
	BTN* pLc; //Left child
	BTN* pRc; //Right child
	BTN* pPr; //Parent
}BSTN; //BinarySearchTreeNode



Star* genStar(int StarID);
void insrertTreeNode(TreeNode** ppT, Star* pS);
void printStar(Star* pS);
void printTreeInOrder(TreeNode* pT);
void printTreeReverseOrder(TreeNode* pT);
Star* searchTree(TreeNode* pT, int nodeID);

int getHeight(BSTN* pBSTN);
int getHeightDiff(BSTN* pBSTN);
BSTN* rotate_LL(BSTN* pCurSubRoot);
BSTN* rotate_RR(BSTN* pCurSubRoot);
BSTN* rotate_LR(BSTN* pCurSubRoot);
BSTN* rotate_RL(BSTN* pCurSubRoot);
BSTN* reBalance(BSTN** ppTN);
BSTN* insertBSTN_with_Balancing(BSTN** ppTN, BSTN* Prc, int* pE);

#endif 