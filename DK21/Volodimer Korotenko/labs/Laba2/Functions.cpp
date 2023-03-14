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
int* createArray( int Size ) {
	int* Array = (int*) malloc( sizeof( int ) * Size );
	if( Array == NULL ) {
		printf("Memory allocation error");
		exit(-2);
	}
	return Array;
}
void InputArray( int* Array, int Size ) {
	printf( "Enter an integer value up to 6 characters\n" );
	for( size_t i = 0; i < Size; i++ ) {
		Array[i] = GetInt( 6, "Entering a value: " );
		system( "cls" );
	}
}
void BulbSort( int* Array, int Size ) {
	int temp;
	for( size_t i = 0; i < Size - 1; i++ ) {
		if( Array[i] > Array[i + 1] ) {
			temp = Array[i + 1];
			Array[i + 1] = Array[i];
			Array[i] = temp;
			i = -1;
			continue;
		}
	}
}
void Display( int* Array, int Size ) {
	printf( "[ " );
	for( size_t i = 0; i < Size; i++ ) {
		printf( "%i", Array[i] );
		if( i + 1 < Size ) {
			printf( ", " );
		}
	}
	printf( "] MAX = %i\n", Array[Size - 1] );
}
void DestroyArray( int* Array, int Size ) {
	free( Array );
}