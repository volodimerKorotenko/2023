#ifndef TREE_H_
#define TREE_H_

// Code for header body
#include <stdio.h>

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} FloatNode;

typedef struct __tagTree
{
	FloatNode *root;
	int count;
} FloatTree;

FloatTree *createFloatTree();
void destroyNode(FloatNode *aNode);
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, float aValue);
FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);
void deleteNodeWithValue(FloatTree *aTree, float aValue);

void printTree(FloatTree *aTree);
void printNode(FloatNode *aNode);

FloatNode *getNodeSuccessor(FloatTree *tree, FloatNode *toDelete);
FloatNode *createFloatNodeWithValue(float aValue);
void print_float_node(FloatNode *node);

#endif //TREE_H_