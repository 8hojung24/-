#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinTreeNodeType 
{
	int data;
	struct BinTreeNodeType * pLeftChild;
	struct BinTreeNodeType * pRightChild;
} BinTreeNode;

typedef struct BintreeType 
{
	struct BinTreeNodeType * pRootNode;
}BinTree;

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
		printf("오류, 메모리 할당, createBinSearchTree()\n");
	}
	return pReturn;
}

BinSearchTreeNode * searchBST(BinSearchTree* pBinSearchTree, int key) {
	BinSearchTreeNode * pReturn = NULL;

	if (pBinSearchTree == NULL) {
		return NULL;
	}
	pReturn = pBinSearchTree->pRootNode;
	while (pReturn != NULL) {
		if (key == pReturn->key) {
			break;
		}
		else if (key < pReturn->key) {
			pReturn = pReturn->pLeftChild;
		}
		else {
			pReturn = pReturn->pRightChild;
		}
	}

	return pReturn;
}

int getParentNode(BinSearchTreeNode *pCurrentNode, int key, BinSearchTreeNode **ppResult) {
	int ret = 1;
	BinSearchTreeNode *pParentNode = NULL;

	while (pCurrentNode != NULL) {
		if (key == pCurrentNode->key) {
			printf("오류, 중복된 키-[%d], getParentNode()\n", key);
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

BinTreeNode *makeNewNodeBT(int data)
{
	BinTreeNode *pReturn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (pReturn != NULL){
		pReturn->data = data;
		pReturn->pLeftChild = NULL;
		pReturn->pRightChild = NULL;
	}
	return pReturn;
}

BinTree *makeBinTree(int rootNodeData)
{
	BinTree *pReturn = NULL;
	pReturn = (BinTree *)malloc(sizeof(BinTree));
	if (pReturn != NULL){
		pReturn->pRootNode = makeNewNodeBT(rootNodeData);
		if (pReturn->pRootNode == NULL){
			free(pReturn);
			pReturn = NULL;
			printf("오류, 메모리 할당(2), makeBinTree()\n");
		}
	}
	else{
		printf("오류, 메모리 할당(1), makeBinTree()\n");
	}
	return pReturn;
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

void deleteNodeNoChild(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode * pDelNode)
{
	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = NULL;
		}
		else {
			pParentNode->pRightChild = NULL;
		}
	}
	else {
		pBinSearchTree->pRootNode = NULL;
	}
}

void deleteNodeOneChild(BinSearchTree* pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pDelNode) {
	BinSearchTreeNode* pChildNode = NULL;

	if (pDelNode->pLeftChild == NULL) {
		pChildNode = pDelNode->pLeftChild;
	}
	else {
		pChildNode = pDelNode->pRightChild;
	}

	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = pChildNode;
		}
		else {
			pParentNode->pRightChild = pChildNode;
		}
	}
	else {
		pBinSearchTree->pRootNode = pChildNode;
	}
}

void deleteNodeTwoChildren(BinSearchTree*  pBinSearchTree, BinSearchTreeNode* pParentNode, BinSearchTreeNode* pDelNode) {
	BinSearchTreeNode * pPredecessor = NULL, *pSuccessor = NULL;

	pPredecessor = pDelNode;
	pSuccessor = pDelNode->pLeftChild;

	while (pSuccessor->pRightChild != NULL) {
		pPredecessor = pSuccessor;
		pSuccessor = pSuccessor->pRightChild;
	}

	pPredecessor->pRightChild = pSuccessor->pLeftChild;
	pSuccessor->pLeftChild = pDelNode->pLeftChild;
	pSuccessor->pRightChild = pDelNode->pRightChild;

	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == pDelNode) {
			pParentNode->pLeftChild = pSuccessor;
		}
		else {
			pParentNode->pRightChild = pSuccessor;
		}
	}
	else {
		pBinSearchTree->pRootNode = pSuccessor;
	}
}

BinTreeNode *addLeftChildNodeBT(BinTreeNode* pParentNode, int data)
{
	BinTreeNode *pReturn = makeNewNodeBT(data);
	if (pParentNode != NULL){
		if (pParentNode->pLeftChild == NULL){
			pParentNode->pLeftChild = pReturn;
		}
		else{
			printf("오류, 이미 노드가 존재합니다. addLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode *addRightChildNodeBT(BinTreeNode *pParentNode, int data)
{
	BinTreeNode *pReturn = makeNewNodeBT(data);
	if (pParentNode != NULL){
		if (pParentNode->pRightChild == NULL){
			pParentNode->pRightChild = pReturn;
		}
		else{
			printf("오류, 이미 노드가 존재합니다. addRightChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
	BinTreeNode* pReturn = NULL;

	if (pBinTree != NULL){
		pReturn = pBinTree->pRootNode;
	}
	
	return pReturn;
}

void deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL){
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}

void deleteBinTree(BinTree *pBinTree)
{
	if (pBinTree != NULL){
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL)
	{
		printf("%d ", pNode->data);
		preorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		preorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}

void preorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
	if (pBinTree != NULL)
	{
		preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
		printf("\n");
	}
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL)
	{
		inorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		printf("%d ", pNode->data);
		inorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
	if (pBinTree != NULL)
	{
		inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
		printf("\n");
	}
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL)
	{
		postorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		postorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
		printf("%d ", pNode->data);
	}
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
	if (pBinTree != NULL)
	{
		postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
		printf("\n");
	}
}

int binarySearchRecursive(int values[], int start, int end, int key) {
	int ret = -1;
	int middle = 0;

	if (start <= end) {
		middle = (start + end) / 2;
		if (key == values[middle]) {
			ret = middle;
		}
		else if (key < values[middle]) {
			ret = binarySearchRecursive(values, start, middle - 1, key);
		}
		else {
			ret = binarySearchRecursive(values, middle + 1, end, key);
		}
	}
	return ret;
}

int insertDataBST(BinSearchTree* pBinSearchTree, int key) {
	int ret = 1;
	BinSearchTreeNode * pParentNode = NULL;
	BinSearchTreeNode * pNewNode = NULL;s

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

int deleteDataBST(BinSearchTree* pBinSearchTree, int key) {
	int ret = 1;
	BinSearchTreeNode * pDelNode = NULL, *pParentNode = NULL;

	if (pBinSearchTree == NULL) {
		ret = 0;
		return ret;
	}
	pDelNode = searchWithParentNodeBST(pBinSearchTree, key, &pParentNode);
	if (pDelNode == NULL) {
		printf("오류, 존재하지 않는 키-[%d], deleteDataBST()\n", key);
		ret = 0;
		return ret;
	}

	if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
		deleteNodeNoChild(pBinSearchTree, pParentNode, pDelNode);
	}
	else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
		deleteNodeTwoChildren(pBinSearchTree, pParentNode, pDelNode);
	}
	else {
		deleteNodeOneChild(pBinSearchTree, pParentNode, pDelNode);
	}

	free(pDelNode);
	return ret;
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode) {
	if (pTreeNode != NULL) {
		if (pTreeNode->pLeftChild != NULL) {
			deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
		}
		if (pTreeNode->pRightChild != NULL) {
			deleteBinSearchTreeInternal(pTreeNode->pRightChild);
		}
			free(pTreeNode);
	}
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree) {
	if (pBinSearchTree != NULL) {
		deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
		free(pBinSearchTree);
	}
}

void displayBinSearchTree(BinSearchTreeNode *pTreeNode, int level, char type) {
	
	int i = 0;
	if (pTreeNode != NULL) {
		for (i = 0; i < level; i++) {
			printf("	");
		}
		printf("-(%c)-key: %i\n", type, pTreeNode->key);

		displayBinSearchTree(pTreeNode->pLeftChild, level + 1, 'L');
		displayBinSearchTree(pTreeNode->pRightChild, level + 1, 'R');
	}
}

void *readBinTree(BinSearchTree **pTree1, BinSearchTree **pTree2) {

	int count1, count2, pData, cData;
	FILE *fs = fopen("hw_input.txt", "r");
	if (fs == NULL) {
		printf("파일이 없습니다.");
		return 0;
	}

	else {
		fscanf(fs, "%d", &count1);
		*pTree1 = createBinSearchTree();
		if (*pTree1 != NULL) {
			for (int i = 0; i < count1 - 1; i++) {
				fscanf(fs, "%d %d\n", &pData, &cData);
				if (i == 0) {
					insertDataBST(*pTree1, pData);
				}
				insertDataBST(*pTree1, cData);
			}
		}
		fscanf(fs, "%d", &count2);
		*pTree2 = createBinSearchTree();
		if(*pTree2 != NULL){
			for (int i = 0; i < count2 - 1; i++) {
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

BinSearchTree *mergeBST(BinSearchTree* pTree1, BinSearchTree* pTree2) {
	
	BinSearchTree *mergeTree = pTree1;
	mergeNode(&mergeTree, pTree2->pRootNode);
	
	return mergeTree;
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

void writeFile(BinSearchTree* mergeTree) {
	
	FILE * fp = fopen("hw_output.txt", "w");
	writeNode(fp, mergeTree->pRootNode);
	fclose(fp);
}

int main(int argc, char *argv[]) {

	BinSearchTree* pTree1 = NULL;
	BinSearchTree* pTree2 = NULL;
	int pNum=0, mNum=0;

	readBinTree(&pTree1, &pTree2);
	BinSearchTree * mergeTree = mergeBST(pTree1, pTree2);
	displayBinSearchTree(mergeTree->pRootNode, 0, '-');

	writeFile(mergeTree);

	deleteBinSearchTree(pTree1);
	deleteBinSearchTree(pTree2);
	deleteBinSearchTree(mergeTree);
}

//[Ctrl + L ], [ Ctrl + M ]