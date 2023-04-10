#ifndef lab3_h
#define lab3_h

#include <stdio.h>
char input[100];
int a;
typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} intNode;

typedef struct __tagTree
{
	intNode *root;
	int count;
} intTree;
intTree *createintTree();
int whatValue();
void insertIntValueToTree(intTree *aTree, int i);
void printTree(intTree *aTree);
intNode *findNodeWithValue(intTree *aTree, int aValue);
void deleteNodeWithValue(intTree *aTree, int aValue);
#endif