#include "Geometrics.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int Size = 0, Index = 0;
	do {
		Size = GetInt( 6, "Entri size " );
	} while( Size < 1  );
	Rectangle** RectangleArray = CreateRectangleArray( Size );

	printf( "Create extra rectangle\n" );
	Rectangle* Temp = CreateRectangle();
	FillRectangle( Temp );
	printf( "Index: %i\n", AddToEndArray( RectangleArray, Temp, Size ) );
	FeguresOutput( RectangleArray, Size );
	printf( "%f\n", CalcAreaArraies( RectangleArray , Size ) );

	do {
		Index = GetInt( 6, "Entri index " );
	} while( Index < 0 );
	printf( "Index: %i\n", AddAfterIndex( RectangleArray, Temp, Index, Size ) );
	FeguresOutput( RectangleArray, Size );
	printf( "%f\n", CalcAreaArraies( RectangleArray, Size ) );
	FreeFiguresArray( RectangleArray , Size );

	free( Temp );
}

