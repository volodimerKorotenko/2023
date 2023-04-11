#include "tree.h"
#include <stdlib.h>


FloatTree *createFloatTree()
{
	FloatTree *NewTree = (FloatTree *)malloc(sizeof(FloatTree));

	if (NULL != NewTree)
	{
		NewTree->root = NULL;
		NewTree->count = 0;
	}

	return NewTree;
}
void destroyNode(FloatNode *Node)
{
	if (NULL != Node)
	{
		destroyNode(Node->leftChild);
		destroyNode(Node->rightChild);

		free(Node);
	}
}

void destroyTree(FloatTree *Tree)
{
	if (NULL != Tree)
	{
		destroyNode(Tree->root);
		free(Tree);
	}
}

void insertFloatValueToTree(FloatTree *Tree, float Value)
{
	if (NULL == Tree)
	{
		return;
	}

	FloatNode *Node = createFloatNodeWithValue(Value);
	if (NULL == Node)
	{
		return;
	}

	if (NULL == Tree->root)
	{
		Tree->root = Node;
		Tree->count ++;
	}
	else
	{
		FloatNode *Current = Tree->root;
		FloatNode *Parent = NULL;

		while (1)
		{
			Parent = Current;

			if (Value < Current->value)
			{
				Current = Current->leftChild;
				if (NULL == Current)
				{
					Parent->leftChild = Node;
					break;
				}
			}
			else
			{
				Current = Current->rightChild;
				if (NULL == Current)
				{
					Parent->rightChild = Node;
					break;
				}
			}
		}

		Tree->count ++;
	}
}

FloatNode *findNodeWithValue(FloatTree *Tree, float Value)
{
	FloatNode *CurrentNode = NULL;

	if (NULL != Tree && NULL != Tree->root)
	{
		CurrentNode = Tree->root;
		while (Value != CurrentNode->value)
		{
			CurrentNode = (Value < CurrentNode->value)
						? CurrentNode->leftChild
						: CurrentNode->rightChild;

			if (NULL == CurrentNode)
			{
				break;
			}
		}
	}

	return CurrentNode;
}

void deleteNodeWithValue(FloatTree *Tree, float Value) {

	if (NULL == Tree || NULL == Tree->root) {
		return ;
	}

	FloatNode *current = Tree->root;
	FloatNode *parent = Tree->root;

	while (Value != current->value) {
		parent = current;
		if (Value < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (Tree->root == current) {
			Tree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		Tree->count --;
	} else if (NULL == current->rightChild) {
		if (Tree->root == current) {
			Tree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (Tree->root == current) {
			Tree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		FloatNode *successor = getSuccessor(Tree, current);
		if (Tree->root == successor) {
			Tree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

void printTree(FloatTree *Tree) {
	print_float_node(Tree->root);
}

void print_float_node(FloatNode *node) {
	if (node == NULL)
		return;
	print_float_node(node->leftChild);
	printf("Ёлемент: %.2f\n", node->value);
	print_float_node(node->rightChild);
}

void printNode(FloatNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("«найдений елемент: %.2f\n", aNode->value);
}



FloatNode *createFloatNodeWithValue(float aValue)
{
	FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

FloatNode *getSuccessor(FloatTree *tree, FloatNode *toDelete) {
	FloatNode *successParent = toDelete;
	FloatNode *successor = toDelete;
	FloatNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
	if (successor != toDelete->rightChild) {
		successParent->leftChild = successor->rightChild;
		successor->rightChild = toDelete->rightChild;
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}
