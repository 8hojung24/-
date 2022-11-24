///전체영역닫기 : ctrl + K + 0 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

typedef struct BinTreeNodeType {
	int data;

	struct BinTreeNodeType * pLeftChild;
	struct BinTreeNodeType * pRightChild;
} BinTreeNode;

typedef struct BintreeType {
	struct BinTreeNodeType * pRootNode;
}BinTree;

BinTreeNode *makeNewNodeBT(int data)
{
	BinTreeNode *pReturn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (pReturn != NULL)
	{
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

	if (pReturn != NULL)
	{
		pReturn->pRootNode = makeNewNodeBT(rootNodeData);
		if (pReturn->pRootNode == NULL)
		{
			free(pReturn);
			pReturn = NULL;
			printf("오류, 메모리 할당(2), makeBinTree()\n");
		}
	}
	else
	{
		printf("오류, 메모리 할당(1), makeBinTree()\n");
	}
	return pReturn;
}

BinTreeNode *addLeftChildNodeBT(BinTreeNode *pParentNode, int data)
{
	BinTreeNode *pReturn = makeNewNodeBT(data);
	if (pParentNode != NULL)
	{
		if (pParentNode->pLeftChild == NULL)
		{
			pParentNode->pLeftChild = pReturn;
		}
		else
		{
			printf("오류, 이미 노드가 존재합니다. addLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode *addRightChildNodeBT(BinTreeNode *pParentNode, int data)
{
	BinTreeNode *pReturn = makeNewNodeBT(data);
	if (pParentNode != NULL)
	{
		if (pParentNode->pRightChild == NULL)
		{
			pParentNode->pRightChild = pReturn;
		}
		else
		{
			printf("오류, 이미 노드가 존재합니다. addRightChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
	BinTreeNode *pReturn = NULL;

	if (pBinTree != NULL)
	{
		pReturn = pBinTree->pRootNode;
	}
	return pReturn;
}

void deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL)
	{
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}

void deleteBinTree(BinTree *pBinTree)
{
	if (pBinTree != NULL)
	{
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL)
	{
		printf("%d", pNode->data);
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
		printf("%d", pNode->data);
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
		printf("%d", pNode->data);
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
