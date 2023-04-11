#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	DoubleTree *tree = createDoubleTree();
	AddElement(tree, 15.2);
	AddElement(tree, 3.4);
	AddElement(tree, 4.7);
	AddElement(tree, 16.1);
	AddElement(tree, 1.9);
	AddElement(tree, 91);
	AddElement(tree, 2);
	AddElement(tree, 14.5);
	AddElement(tree, 7);
	AddElement(tree, 6);
	AddElement(tree, 5);

	printTree(tree);

	DoubleNode *Find_Node = findNodeWithValue(tree, 1);

	if (NULL != Find_Node)
	{
		printNode(Find_Node);
		printf("\n");
	} else {
		printf("The node with request value was not found\n");
	}

	deleteNodeWithValue(tree, 15);
	printTree(tree);

	destroyDoubleTree(tree);
	return 0;
}
