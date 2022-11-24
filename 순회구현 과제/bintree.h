#ifndef _BINTREE_
#define _BINTREE_

typedef struct BinTreeNodeType{
    int data;

    struct BinTreeNodeType * pLeftChild;
    struct BinTreeNodeType * pRightChild;
} BinTreeNode;

typedef struct BintreeType{
    struct BinTreeNodeType * pRootNode;
}BinTree;

BinTreeNode* makeNewNodeBT (int data);
BinTree * makeBinTree(int rootNodeData);
BinTreeNode * addLeftChildNodeBT(BinTreeNode & pParentNode, int data);
BinTreeNode * addRightChildNodeBT(BinTreeNode & pParentNode, int data);
BinTreeNode * getRootNodeBT(BinTree * pBinTree);
void deleteBinTreeNode (BinTreeNode* pNode);
void deleteBinTree(BinTree * pBinTree);

void preorderTraversalRecursiveBinTreeNode(BinTree *pNode);
void preorderTraversalRecursiveBinTree(BinTree *pBinTree);
void inorderTraversalRecursiveBinTreeNode(BinTree *pNode);
void inorderTraversalRecursiveBinTree(BinTree *pBinTree);
void postorderTraversalRecursiveBinTreeNode(BinTree *pNode);
void postorderTraversalRecursiveBinTree(BinTree *pBinTree);

#endif