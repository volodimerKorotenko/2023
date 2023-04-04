#ifndef TREE_H_
#define TREE_H_

// Code for header body
#include <stdio.h>

typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode *root;
	int count;
} IntTree;

IntTree *createIntTree();
void destroyNode(IntNode *aNode);
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);
IntNode *findNodeWithValue(IntTree *aTree, int aValue);
void deleteNodeWithValue(IntTree *aTree, int aValue);

void printTree(IntTree *aTree);
void printNode(IntNode *aNode);

IntNode *getNodeSuccessor(IntNode *toDelete);
IntNode *createIntNodeWithValue(int aValue);
void print_int_node(IntNode *node);

#endif //TREE_H_