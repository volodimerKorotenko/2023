#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
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
Node* GetLast( Node* Head ) {
	Node *Ptr = Head;
	while( (bool) Ptr->next ) {
		Ptr = Ptr->next;
	}
	return Ptr;
}
Node* Shift( Node* Head, int data ) {
	if( Head == NULL ) {
		Head = (Node*) malloc( sizeof( Node ) );
		if( Head == NULL ) {
			exit( -2 );
		}
		Head->value = data;
		Head->next = 0;
		return Head;
	}
	Node* Temp = (Node*) malloc( sizeof( Node ) );
	if( Temp == NULL ) {
		exit( -2 );
	}
	Temp->value = data;
	Temp->next = 0;
	GetLast( Head )->next = Temp;
	return Head;
}
Node* DataEntry( Node* Head , int Size) {
	for( size_t i = 0; i < Size; i++ ) {
		Head = Shift( Head , GetInt(6, "Entri value: "));
	}
	return Head;
}
Node* BulbSort( Node* Head ) {
	Node* Ptr = Head;
	int Temp = 0;
	while( Ptr->next != 0 ) {
		if( Ptr->value > Ptr->next->value ) {
			Temp = Ptr->value;
			Ptr->value = Ptr->next->value;
			Ptr->next->value = Temp;
			Ptr = Head;
		} else Ptr = Ptr->next;
	}
	return Head;
}
void ListOutput( Node* Head ) {
	Node* Ptr = Head;
	printf("[ %i", Ptr->value);
	while( (bool) Ptr->next ) {
		Ptr = Ptr->next;
		printf( " ,%i", Ptr->value );
	}
	printf( " ]\n" );
	printf( "Max value list: %i\n", Max(Head) );
}
int Max( Node* Head ) {
	Node* Ptr = Head;
	int Temp = Head->value;
	while( (bool) Ptr->next ) {
		if( Temp < Ptr->next->value ) {
			Temp = Ptr->next->value;
		}
		Ptr = Ptr->next;
	}
	return Temp;
}
void FreeList( Node* Head ) {
	Node* Next = Head;
	Node* Current = 0;
	while( (bool)Next->next != 0 ) {
		Current = Next;
		Next = Next->next;
		free( Current );
	}
	free( Next->next );
}