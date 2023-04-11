#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

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
void destroyNode(FloatNode *Node);
void destroyTree(FloatTree *Tree);

void insertFloatValueToTree(FloatTree *Tree, float Value);
FloatNode *findNodeWithValue(FloatTree *Tree, float Value);
void deleteNodeWithValue(FloatTree *Tree, float Value);

void printTree(FloatTree *Tree);
void printNode(FloatNode *Node);
void print_float_node(FloatNode *Node);
FloatTree *createFloatTreewithValue(float Value);
FloatNode *getSuccessor(FloatTree *tree, FloatNode *toDelete);
FloatNode *createFloatNodeWithValue(float aValue);
#endif // TREE_H_INCLUDED
