#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinSearchTreeNodeType {
	int key;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
}BinSearchTreeNode;

typedef struct BinSearchTreeType {
	BinSearchTreeNode *pRootNode;
}BinSearchTree;

BinSearchTree * createBinSearchTree() {
	BinSearchTree *pReturn = NULL;
	pReturn = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (pReturn != NULL) {
		pReturn -> pRootNode = NULL;
	}
	else {
		printf("¿À·ù, ¸Þ¸ð¸® ÇÒ´ç, createBinSearchTree()\n");
	}
	return pReturn;
}

BinSearchTreeNode * createNewBinSearchTreeNode(int key) {
	BinSearchTreeNode * pNewNode = NULL;

	pNewNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (pNewNode != NULL) {
		pNewNode->key = key;
		pNewNode->pLeftChild = NULL;
		pNewNode->pRightChild = NULL;
	}

	return pNewNode;
}

int getParentNode(BinSearchTreeNode *pCurrentNode, int key, BinSearchTreeNode **ppResult) {
	int ret = 1;
	BinSearchTreeNode *pParentNode = NULL;

	while (pCurrentNode != NULL) {
		if (key == pCurrentNode->key) {
			printf("¿À·ù, Áßº¹µÈ Å°-[%d], getParentNode()\n", key);
			ret = 0;
			return ret;
		}
		else if (key < pCurrentNode->key) {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pLeftChild;
		}
		else {
			pParentNode = pCurrentNode;
			pCurrentNode = pCurrentNode->pRightChild;
		}
	}
	if (1 == ret) {
		*ppResult = pParentNode;
	}

	return ret;
}

void insertNewBinSearchTreeNode(BinSearchTree* pBinSearchTree, BinSearchTreeNode * pParentNode, BinSearchTreeNode* pNewNode) {
	if (pParentNode == NULL) {
		pBinSearchTree->pRootNode = pNewNode;
	}
	else {
		if (pNewNode->key < pParentNode->key) {
			pParentNode->pLeftChild = pNewNode;
		}
		else {
			pParentNode->pRightChild = pNewNode;
		}
	}
}

int insertDataBST(BinSearchTree* pBinSearchTree, int key) {
	int ret = 1;
	BinSearchTreeNode * pParentNode = NULL;
	BinSearchTreeNode * pNewNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = 0;
		return ret;
	}

	ret = getParentNode(pBinSearchTree->pRootNode, key, &pParentNode);
	if (0 == ret) {
		return ret;
	}

	pNewNode = createNewBinSearchTreeNode(key);
	if (NULL == pNewNode) {
		return 0;
	}

	insertNewBinSearchTreeNode(pBinSearchTree, pParentNode, pNewNode);

	return ret;
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
		deleteBinSearchTreeInternal(pTreeNode->pRightChild);
		free(pTreeNode);
	}
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree) {
	if (pBinSearchTree != NULL) {
		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
		free(pBinSearchTree);
	}
}

void *readBinTree(BinSearchTree **pTree1, BinSearchTree **pTree2, int *count1, int *count2) {

	int pData, cData;
	FILE *fs = fopen("hw_input.txt", "r");
	if (fs == NULL) {
		printf("ÆÄÀÏÀÌ ¾ø½À´Ï´Ù.");
		return 0;
	}

	else {
		fscanf(fs, "%d", &*count1);
		*pTree1 = createBinSearchTree();
		if (*pTree1 != NULL) {
			for (int i = 0; i < *count1 - 1; i++) {
				fscanf(fs, "%d %d\n", &pData, &cData);
				if (i == 0) {
					insertDataBST(*pTree1, pData);
				}
				insertDataBST(*pTree1, cData);
			}
		}
		fscanf(fs, "%d", &*count2);
		*pTree2 = createBinSearchTree();
		if (*pTree2 != NULL) {
			for (int i = 0; i < *count2 - 1; i++) {
				fscanf(fs, "%d %d\n", &pData, &cData);
				if (i == 0) {
					insertDataBST(*pTree2, pData);
				}
				insertDataBST(*pTree2, cData);
			}
		}
	}
	return 0;
}

BinSearchTree *mergeNode(BinSearchTree** mergeTree, BinSearchTreeNode* pNode) {
	
	insertDataBST(*mergeTree, pNode->key);
	if (pNode->pLeftChild != NULL) {
			mergeNode(&*mergeTree, pNode->pLeftChild);
		}
	if (pNode->pRightChild != NULL) {
			mergeNode(&*mergeTree, pNode->pRightChild);
		}
	
	return *mergeTree;
}

BinSearchTree *mergeBST(BinSearchTree* rootTree, BinSearchTree* insertTree) {
	
	BinSearchTree *mergeTree = rootTree;
	mergeNode(&mergeTree, insertTree->pRootNode);
	
	return mergeTree;
}

BinSearchTreeNode* searchWithParentNodeBST(BinSearchTree* pBinSearchTree, int key, BinSearchTreeNode ** ppParentNode) {
	BinSearchTreeNode* pReturn = NULL;
	BinSearchTreeNode* pParentNode = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}
	pReturn = pBinSearchTree->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		pParentNode = pReturn;

		if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	if (NULL != ppParentNode) {
		*ppParentNode = pParentNode;
	}
	return pReturn;
}

int newNodeNum(BinSearchTree* mergeTree, BinSearchTreeNode *Node, int pNkey, int *nNum) {
	
	BinSearchTreeNode* pParentNode = NULL;
	searchWithParentNodeBST(mergeTree, Node->key, &pParentNode);
	if (pNkey != pParentNode->key) {
		*nNum += 1;
	}
	if (Node->pLeftChild != NULL) {
		newNodeNum(mergeTree, Node->pLeftChild, Node->key, nNum);
	}
	if (Node->pRightChild != NULL) {
		newNodeNum(mergeTree, Node->pRightChild, Node->key, nNum);
	}
	return *nNum;
}

void writeNode(FILE* fp, BinSearchTreeNode* pNode) {

	if (pNode->pLeftChild != NULL) {
		fprintf(fp, "%d %d\n", pNode->key, pNode->pLeftChild->key);
	}
	if (pNode->pRightChild != NULL) {
		fprintf(fp, "%d %d\n", pNode->key, pNode->pRightChild->key);
	}
	if (pNode->pLeftChild != NULL) {
		writeNode(fp, pNode->pLeftChild);
	}
	if (pNode->pRightChild != NULL) {
		writeNode(fp, pNode->pRightChild);
	}
}

void writeFile(BinSearchTree* mergeTree, int nNum, int dNum) {

	FILE * fp = fopen("hw_output.txt", "w");
	writeNode(fp, mergeTree->pRootNode);
	fprintf(fp, "%d\n", nNum);
	fprintf(fp, "%d", dNum);
	fclose(fp);
}

int main(int argc, char *argv[]) {

	int nNum = 0, dNum, count1, count2;
	BinSearchTree* pTree1 = NULL;
	BinSearchTree* pTree2 = NULL;
	BinSearchTree * mergeTree = NULL;

	readBinTree(&pTree1, &pTree2, &count1, &count2);

	if (count1 >= count2) {
		mergeTree = mergeBST(pTree1, pTree2);
		newNodeNum(mergeTree, pTree2->pRootNode, NULL, &nNum);
	}
	else {
		mergeTree = mergeBST(pTree2, pTree1);
		newNodeNum(mergeTree, pTree1->pRootNode, NULL, &nNum);
	}
	dNum = nNum - 1;
	writeFile(mergeTree, nNum, dNum);

	deleteBinSearchTree(pTree1);
	deleteBinSearchTree(pTree2);
	deleteBinSearchTree(mergeTree);
}
