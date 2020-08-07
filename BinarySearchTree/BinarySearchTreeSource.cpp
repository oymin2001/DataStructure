#include<iostream>
#include<algorithm>
#include"BinarySearchTree.cpp"

using namespace std;

Star* genStar(int StarID) {
	Star* pNew;
	int name_len;

	pNew = (Star*)malloc(sizeof(Star));
	name_len = rand() % 6 + 5;

	pNew->name[0] = rand() % 26 + 'A';
	for (int i = 1; i < name_len; i++) {
		pNew->name[i] = rand() % 26 + 'a';
	}
	pNew->name[name_len] = '\0';
	pNew->id = StarID;
	pNew->age = rand() % 10000 + 10;

	return pNew;

}

// *ppT의 값이 NULL일 때 새로운 노드를 추가할 것이기에 포인터가 변경되기 때문
void insrertTreeNode(TreeNode** ppT, Star* pS) {


	TreeNode* pN;
	if (*ppT == NULL) {
		pN = (TreeNode*)malloc(sizeof(TreeNode));
		pN->pStar = pS;
		pN->pL = NULL;
		pN->pR = NULL;
		//pN의 주소값을 ppT에 저장
		*ppT = pN;

		printf("InsertTreeNode (Star id: %d", pS->id);
		printf(", name: %s\n", pS->name);
	}
	else if (pS->id < (*ppT)->pStar->id)
		insrertTreeNode(&(*ppT)->pL, pS);
	else
		insrertTreeNode(&(*ppT)->pR, pS);

}

void printStar(Star* pS) {

	if (pS != NULL) {
		printf("Star (ID: %3d", pS->id);
		printf(", Name: %s)\n", pS->name);
	}
}

void printTreeInOrder(TreeNode* pT) {
	if (pT != NULL) {
		printTreeInOrder(pT->pL);
		printStar(pT->pStar);
		printTreeInOrder(pT->pR);
	}
}
void printTreeReverseOrder(TreeNode* pT) {
	if (pT != NULL) {
		printTreeInOrder(pT->pR);
		printStar(pT->pStar);
		printTreeInOrder(pT->pL);
    }
}

Star* searchTree(TreeNode* pT, int nodeID) {
	if (pT == NULL)
		return NULL;
	else if (pT->pStar->id == nodeID)
		return pT->pStar;
	else if (pT->pStar->id < nodeID)
		searchTree(pT->pR, nodeID);
	else
		searchTree(pT->pL, nodeID);
}



int getHeight(BSTN* pBSTN) {
	int height = 0;
	if (pBSTN != NULL) {
		height = 1 + max(getHeight(pBSTN->pLc), getHeight(pBSTN->pRc));
	}
	return height;
}

int getHeightDiff(BSTN* pBSTN) {
	int heightDiff = 0;

	if (pBSTN == NULL)
		return 0;
	
	heightDiff = getHeight(pBSTN->pLc) - getHeight(pBSTN->pRc);
	
	return heightDiff;
}


BSTN* rotate_LL(BSTN* pCurSubRoot) {
	BSTN* pNewSubRoot, * pBR, *pCurParent;

	pCurParent = pCurSubRoot->pPr;
	pNewSubRoot = pCurSubRoot->pLc;
	pBR = pNewSubRoot->pLc;
	pCurSubRoot->pLc = pBR;
	if (pBR != NULL)
		pBR->pPr = pCurSubRoot;
	pNewSubRoot->pRc = pCurSubRoot;
	pNewSubRoot->pPr = pCurParent;
	pCurSubRoot->pPr = pNewSubRoot;

	return pNewSubRoot;
}

BSTN* rotate_RR(BSTN* pCurSubRoot) {
	BSTN* pNewSubRoot, * pBL, * pCurParrent;

	pCurParrent = pCurSubRoot->pPr;
	pNewSubRoot = pCurSubRoot->pRc;
	pBL = pNewSubRoot->pLc;
	pCurSubRoot->pRc = pBL;
	if (pBL != NULL)
		pBL->pPr = pCurSubRoot;
	pNewSubRoot->pLc = pCurSubRoot;
	pNewSubRoot->pPr = pCurParrent;
	pCurSubRoot->pPr = pNewSubRoot;

	return pNewSubRoot;
}

BSTN* rotate_LR(BSTN* pCurSubRoot) {
	BSTN* pSubRoot, * pNewSubRoot, * pCurParent;
	BSTN* pA, *pB, *pC, *pBL, *pBR;

	pC = pCurSubRoot;
	pCurParent = pCurSubRoot->pPr;
	pA = pC->pLc;
	pB = pA->pRc;
	pBL = pB->pLc;
	pBR = pB->pRc;
	pCurSubRoot->pLc=rotate_RR(pA);
	pNewSubRoot = rotate_LL(pC);

	pNewSubRoot->pPr = pCurParent;
	pA->pPr = pNewSubRoot;
	pC->pPr = pNewSubRoot;
	if (pBL != NULL)
		pBL->pPr = pA;
	if (pBR != NULL)
		pBR->pPr = pC;

	return pNewSubRoot;
}

BSTN* rotate_RL(BSTN* pCurSubRoot) {
	BSTN* pSubRoot, * pNewSubRoot, * pCurParrent;
	BSTN* pA, * pB, * pC, * pBL, * pBR;

	pA = pCurSubRoot;
	pCurParrent = pCurSubRoot->pPr;
	pC = pA->pRc;
	pB = pC->pLc;
	pBL = pB->pLc;
	pBR = pB->pRc;
	pCurSubRoot->pRc = rotate_LL(pC);
	pNewSubRoot = rotate_RR(pA);

	pNewSubRoot->pPr = pCurParrent;
	pA->pPr = pNewSubRoot;
	pC->pPr = pNewSubRoot;
	if (pBL != NULL)
		pBL->pPr = pA;
	if (pBR != NULL)
		pBR->pPr = pC;

	return pNewSubRoot;
}

BSTN* reBalance(BSTN** ppTN) {
	int heightDiff = 0;

	heightDiff = getHeightDiff(*ppTN);
	if (heightDiff > 1) //LeftSubTree is higher
	{
		if (getHeightDiff((*ppTN)->pLc) > 0)
			*ppTN = rotate_LL(*ppTN);
		else
			*ppTN = rotate_LR(*ppTN);
	}
	else if (heightDiff < -1) //RightSubTree is higher
	{
		if (getHeightDiff((*ppTN)->pRc) < 0)
			*ppTN = rotate_RR(*ppTN);
		else
			*ppTN = rotate_RL(*ppTN);
	}

	return *ppTN;
}

BSTN* insertBSTN_with_Balancing(BSTN** ppTN, BSTN* pPr, int* pE) {

	BSTN* pTN;

	if (*ppTN == NULL) //새로운 노드를 추가할 위치에 도달
	{
		pTN = (BSTN*)calloc(1, sizeof(BSTN));
		pTN->data = pE;
		*ppTN = pTN;
		if (pPr != NULL)
			pTN->pPr = pPr;
		(*ppTN)->pLc = (NULL);
		(*ppTN)->pRc = (NULL);
	}
	else if (*pE < *(*ppTN)->data) {
		pTN = insertBSTN_with_Balancing(&(*ppTN)->pLc, *ppTN, pE);
		if (ppTN != NULL) {
			(*ppTN)->pLc = (pTN);
			*ppTN = reBalance(ppTN);
		}
	}
	else if (*pE > * (*ppTN)->data) {
		pTN = insertBSTN_with_Balancing(&(*ppTN)->pRc, *ppTN, pE);
		if (ppTN != NULL) {
			(*ppTN)->pRc = (pTN);
			*ppTN = reBalance(ppTN);
		}
	}
	else
		printf("insertBSTN_with_Rebalancing - the giver entry is already existing!!\n");

	return *ppTN;
}