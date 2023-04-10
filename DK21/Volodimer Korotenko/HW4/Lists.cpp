#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"
int GetInt( int Max, const char Message[] ) {
	int Result = 0, i = 0;
	char Char = ' ';
	bool Invers = false, error = false;
	do {
		printf( Message );
		error = false;
		while( 1 ) {
			Char = fgetc( stdin );
			if( !Invers && Char == '-' ) {
				Invers = true;
				continue;
			}
			if( Char != '\n' ) {
				if( !error ) {
					if( i < Max ) {
						if( Char >= '0' && Char <= '9' ) {
							Result *= 10;
							Result += ( Char - '0' );
						} else {
							Result = 0;
							error = true;
							printf( "Entered non-numeric value\n" );
							system( "pause" );
							system( "cls" );
						}
					} else {
						Result = 0;
						error = true;
						printf( "The value entered is too large (no more than %i characters)\n", Max );
						system( "pause" );
						system( "cls" );
					}
				}
			} else break;
			i++;
		}
		i = 0;
	} while( error );
	if( !Invers ) {
		return Result;
	} else return -Result;
}
Node* Shift( Node* Head, int data ) {
	if( Head == 0 ) {
		return CreateList( data );
	} else {
		Node* Temp = (Node*) malloc( sizeof( Node ) );
		Temp->value = data;
		Temp->next = NULL;
		GetLastNode( Head )->next = Temp;
	}
	return Head;
}
void Pop( Node* Head ) {
	Node* Next = Head;
	Node* Current = 0;
	if( Head != 0 ) {
		while( (bool) Next->next != 0 ) {
			Current = Next;
			Next = Next->next;
		}
		free( Next );
		Current->next = 0;
	}
}
int AddAfterIndex( Node* Head ,int data, int Index) {
	int Size = SizeList( Head );
	if( Size > Index ) {
		FindBehindIndex( Head, Index )->value = data;
		return Index;
	} else if( Size == Index ) {
		Head = Shift( Head , data);
		return Index;
	}
	return -1;
}
Node* CreateList( int data ) {
	Node* Temp = (Node*) malloc( sizeof( Node ) );
	if( Temp == 0 ) {
		exit( -2 );
	}
	Temp->value = data;
	Temp->next = NULL;
	return Temp;
}
Node* GetLastNode( Node* Head ) {
	Node* Temp = Head;
	if( Temp != 0 ) {
		while( Temp->next != 0 ) {
			Temp = Temp->next;
		}
	}
	return Temp;
}
Node* DataEntry( Node* Head, int Size ) {
	for( size_t i = 0; i < Size; i++ ) {
		Head = Shift( Head, GetInt( 6, "Entri value: " ) );
	}
	return Head;
}
Node* FindBehindIndex( Node* Head, int Index ) {
	Node* Next = Head;
	int i = 0;
	if( Next != 0 ) {
		while( (bool) Next->next != 0 ) {
			if( Index == i ) {
				return Next;
			}
			i++;
			Next = Next->next;
		}
		return Next;
	}
	return 0;
}
unsigned int SizeList( Node* Head ) {
	Node* Next = Head;
	unsigned int Size = 0;
	if( Head != 0 ) {
		Size++;
		while( (bool) Next->next != 0 ) {
			Next = Next->next;
			Size++;
		}
	}
	return Size;
}
void ListOutput( Node* Head ) {
	Node* Ptr = Head;
	printf( "[ %i", Ptr->value );
	while( (bool) Ptr->next ) {
		Ptr = Ptr->next;
		printf( " ,%i", Ptr->value );
	}
	printf( " ]\n" );
}
void FreeList( Node* Head ) {
	Node* Next = Head;
	Node* Current = 0;
	while( (bool) Next->next != 0 ) {
		Current = Next;
		Next = Next->next;
		free( Current );
	}
	free( Next );
}