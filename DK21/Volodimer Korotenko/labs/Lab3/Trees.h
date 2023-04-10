#pragma once
typedef struct Node {
	double Value;
	Node* LeftChild;
	Node* RightChild;
} Node;
Node* AddValue( Node* Tree, int Data );
Node* CreateNode( Node* Tree, int Data );
Node* FindNode( Node* Nodes, int Data );
void PrintTree( Node* Tree );
void DeleteNode(  Node* Nodes, int Data );
void FreeTree( Node* Tree );
void TreeShiftInLeft( Node* Nodes, Node* );
Node* TreeEntry( Node* Nodes, int Count );
int GetInt( int Max, const char Message[] );