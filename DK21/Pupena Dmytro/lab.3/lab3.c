#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include "lab3.h"
static void destroyNode(intNode *aNode);
static intNode *createintNodeWithValue(int aValue);
static intNode *getSuccessor(intTree *tree, intNode *toDelete);
static void print_int_node(intNode *node);
intNode *createintNodeWithValue(int aValue)
{
	intNode *theNode = (intNode *)malloc(sizeof(intNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

intTree *createintTree()
{
	intTree *theTree = (intTree *)malloc(sizeof(intTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}
void destroyNode(intNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}
void destroyintTree(intTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}
int howMuchTimes()
{
    int result;
    do
    {
    
   printf("Введіть натуральне число: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) 
        {
            printf("Введене значення не є натуральним числом\n");
            break;
        }
        i++;
        
    }
    
       result = atoi(input);
    
    }
    while (result<0 );
    printf("Введене число: %d\n", result);
    return result;
}
int whatValue()
{
    int f,result,c;
     do
    {
     f = 1;
     c = 0 ;
   printf("Введіть ціле число: ");
    scanf("%s", input);
    while (input[c] != '\0')
     {
        if (input[c]=='-')
        {
             
        }
        else
        {
        if (!isdigit(input[c])) 
        {
            printf("Введене значення не є цілим числом\n");
             f = 0;
             break;
        }
        }
        c++;
    }
    if (f=1)
    {
     result = atoi(input);
    }
    }
    while (f==0 );
    printf("Введене число: %d\n", result);
    return result;
}
void insertIntValueToTree(intTree *aTree, int aValue)

{
	if (NULL == aTree)
	{
		return;
	}

	intNode *theNode = createintNodeWithValue(aValue);
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
		intNode *theCurrent = aTree->root;
		intNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (aValue < theCurrent->value)
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
void printTree(intTree *aTree) {
	intNode* item = aTree->root;
	print_int_node(item);
}
void print_int_node(intNode *node) {
	if (node == NULL)
		return;
     printf("Элемент: %d\n", node->value);
	print_int_node(node->leftChild);
	print_int_node(node->rightChild);
}
intNode *findNodeWithValue(intTree *aTree, int aValue)
{
	intNode *theCurrentNode = NULL;
	
	if (NULL != aTree && NULL != aTree->root)
	{
		intNode *theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
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
void deleteNodeWithValue(intTree *aTree, int aValue) {


	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	intNode *current = aTree->root;
	intNode *parent = aTree->root;

	while (aValue != current->value) {
		parent = current;
		if (aValue < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

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
		intNode *successor = getSuccessor(aTree, current);
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
intNode *getSuccessor(intTree *tree, intNode *toDelete) {
	intNode *successParent = toDelete;
	intNode *successor = toDelete;
	intNode *current = toDelete->rightChild;

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