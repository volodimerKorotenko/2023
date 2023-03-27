#pragma once
typedef struct Node {
	int value;
	struct Node* next;
} Node;
int GetInt( int Max, const char Message[] );
Node* Shift( Node *head, int data );
Node* DataEntry( Node* Head, int Size );
Node* BulbSort( Node* Head );
void ListOutput( Node* Head );
int Max( Node* Head );
void FreeList( Node* Head );