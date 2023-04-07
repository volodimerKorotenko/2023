#include "Trees.h"
#include <stdlib.h>
#include <stdio.h>
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
Node* AddValue( Node* Nodes, int Data) {
	if( Nodes == 0 ) {
		return CreateNode(Nodes, Data );
	}
	if( Nodes->Value < Data ) {
		Nodes->RightChild = AddValue( Nodes->RightChild, Data );
	} else {
		Nodes->LeftChild = AddValue( Nodes->LeftChild, Data );
	}
	return Nodes;
}
Node* CreateNode( Node* Nodes, int Data ) {
	Nodes = (Node*) malloc( sizeof( Node ) );
	Nodes->Value = Data;
	Nodes->LeftChild = 0;
	Nodes->RightChild = 0;
	return Nodes;
}
Node* FindNode( Node* Nodes, int Data ) {
	if( Nodes != 0 ) {
		if( Nodes->Value < Data ) {
			if( Nodes->RightChild ) {
				return FindNode( Nodes->RightChild,  Data );
			}
		} else {
			if( Nodes->LeftChild ) {
				return FindNode( Nodes->LeftChild, Data );
			}
		}
		return Nodes;
	}
	return 0;
}
Node* TreeEntry( Node* Nodes , int Count) {
	for( size_t i = 0; i < Count; i++ ) {
		Nodes = AddValue( Nodes, GetInt( 6, "Entry value of tree " ) );
	}
	return Nodes;
}
void PrintTree( Node* Tree ) {
	if( Tree != 0 ) {
		if( Tree->LeftChild ) {
			PrintTree( Tree->LeftChild );
		}
		if( Tree->RightChild ) {
			PrintTree( Tree->RightChild );
		}
		printf("%i\n", Tree->Value);
	}
}
void DeleteNode( Node* Tree, int Data ) {
	if( Tree ) {
		if( Tree->Value != Data ) {
			if( Tree->Value < Data ) {
				if( Tree->RightChild ) {
					if( Tree->RightChild->Value == Data ) {
						TreeShiftInLeft( Tree, Tree->RightChild );
					} else {
						DeleteNode( Tree->RightChild, Data );
					}
				}
			} else {
				if( Tree->LeftChild ) {
					if( Tree->LeftChild->Value == Data ) {
						TreeShiftInLeft( Tree, Tree->LeftChild );
					} else {
						DeleteNode( Tree->LeftChild, Data );
					}
				}
			}
		} else {
			TreeShiftInLeft( 0, Tree );
		}
	}
}
void TreeShiftInLeft( Node* Parent, Node* Child ) {
	if( Parent && Child ) {
		while( Child->RightChild ) {
			Parent = Child;
			Child = Child->RightChild;
			Parent->Value = Child->Value;
		}
		Parent->RightChild = Child->LeftChild;
		free( Child );
	} else {
		free( Child );
	}
}
void FreeTree( Node* Nodes ) {
	if( Nodes ) {
		if( Nodes->LeftChild ) {
			FreeTree( Nodes->LeftChild );
		}
		if( Nodes->RightChild ) {
			FreeTree( Nodes->RightChild );
		}
		free( Nodes );
	}
}