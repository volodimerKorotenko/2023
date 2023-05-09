//
//  main.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	Tree *tree = createTree();
	insertValueToTree(tree, 53);
	insertValueToTree(tree, 43);
	insertValueToTree(tree, 39);
	insertValueToTree(tree, 30);
	insertValueToTree(tree, 14);
	insertValueToTree(tree, 9);
	insertValueToTree(tree, 23);

	insertValueToTree(tree, 35);
	insertValueToTree(tree, 73);
	insertValueToTree(tree, 61);
	insertValueToTree(tree, 56);

	printTree(tree);

	Node *node43 = findNodeWithValue(tree, 61);

	if (NULL != node43)
	{
		printNode(node43);
		printf("\n");
	} else {
		printf("The node with request key/value was not found\n");
	}

	deleteNodeWithValue(tree, 30);
	printTree(tree);

	destroyTree(tree);

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
