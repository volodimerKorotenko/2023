//
//  tree.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>

static void destroyNode(Node *aNode);
static Node *createNodeWithValue(float value);
static Node *getSuccessor(Tree *tree, Node *toDelete);
static void print_node(Node *node);

Tree *createTree()
{
	Tree *theTree = (Tree *)malloc(sizeof(Tree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyTree(Tree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertValueToTree(Tree *aTree, float value)
{
	if (NULL == aTree)
	{
		return;
	}

	Node *theNode = createNodeWithValue(value);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		Node *theCurrent = aTree->root;
		Node *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (value < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count ++;
	}
}

Node *findNodeWithValue(Tree *aTree, float value)
{
	Node *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root; //<! - start from root
		while (value != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (value < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}

	return theCurrentNode;
}

void deleteNodeWithValue(Tree *aTree, float value) {

	// check input parameters
	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	Node *current = aTree->root;
	Node *parent = aTree->root;

	// find node for delete
	while (value != current->value) {
		parent = current;
		if (value < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		aTree->count --;
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		Node *successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
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


void printTree(Tree *aTree) {
	Node* item = aTree->root;
	print_node(item);
}

void print_node(Node *node) {
	if (node == NULL)
		return;

	printf("Element: %f\n", node->value);
	print_node(node->leftChild);
	print_node(node->rightChild);
}

void printNode(Node *aNode)
{
	if (aNode == NULL)
	 return;

	printf("value(%f)", aNode->value);
}


#pragma mark -
void destroyNode(Node *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

Node *createNodeWithValue(float aValue)
{
	Node *theNode = (Node *)malloc(sizeof(Node));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

Node *getSuccessor(Tree *tree, Node *toDelete) {
	Node *successParent = toDelete;
	Node *successor = toDelete;
	Node *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
//current = NULL;
//successor = 35
	if (successor != toDelete->rightChild) { // 35 != 39
		successParent->leftChild = successor->rightChild; //39 -> NULL
		successor->rightChild = toDelete->rightChild; //35->39
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}


