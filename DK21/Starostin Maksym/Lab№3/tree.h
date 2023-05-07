//
//  tree.h
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} Node;

typedef struct __tagTree
{
	Node *root;
	int count;
} Tree;

// interface
Tree *createTree();
void destroyTree(Tree *aTree);

void insertValueToTree(Tree *aTree, float value);
Node *findNodeWithValue(Tree *aTree, float value);
void deleteNodeWithValue(Tree *aTree, float value);

void printTree(Tree *aTree);
void printNode(Node *aNode);

#endif /* tree_h */
