#pragma once
typedef struct Node {
	int value;
	struct Node* next;
} Node;
int GetInt( int Max, const char Message[] );
Node* Shift( Node* head, int data );
Node* CreateList( int data );
int AddAfterIndex( Node* Head, int data, int Index );
Node* FindBehindIndex( Node* Head, int Index );
void Pop( Node* Head );
Node* DataEntry( Node* Head, int Size );
Node* GetLastNode( Node* Head );
void ListOutput( Node* Head );
unsigned int SizeList( Node* Head );
void FreeList( Node* Head );