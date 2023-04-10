#include "Geometrics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
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
Rectangle* CreateRectangle( Rectangle* Figure ) {
	Rectangle* NewFegure = (Rectangle*) malloc( sizeof( Rectangle ) );
	if( NewFegure == 0 ) {
		exit( -2 );
	}
	NewFegure->Coordinates = NULL;
	if( Figure != 0 ) {
		NewFegure->Coordinates = swift( NewFegure->Coordinates, Figure->Coordinates->X, Figure->Coordinates->Y );
		NewFegure->Coordinates = swift( NewFegure->Coordinates, Figure->Coordinates->NextPoint->X, Figure->Coordinates->NextPoint->Y );
		NewFegure->Coordinates = swift( NewFegure->Coordinates, Figure->Coordinates->NextPoint->NextPoint->X, Figure->Coordinates->NextPoint->NextPoint->Y );
		NewFegure->Coordinates = swift( NewFegure->Coordinates, Figure->Coordinates->NextPoint->NextPoint->NextPoint->X, Figure->Coordinates->NextPoint->NextPoint->NextPoint->Y );
	} else {
		return NewFegure;
	}
	return NewFegure;
}
PointList* CreateList( int x, int y ) {
	PointList* Temp = (PointList*) malloc( sizeof( PointList ) );
	if( Temp == 0 ) {
		exit( -2 );
	}
	Temp->X = x;
	Temp->Y = y;
	Temp->NextPoint = NULL;
	return Temp;
}
Rectangle** CreateRectangleArray( int Size ) {
	Rectangle** Temp = (Rectangle**) malloc( sizeof( Rectangle* ) * Size );
	for( size_t i = 0; i < Size; i++ ) {
		Temp[i] = (Rectangle*) malloc( sizeof( Rectangle ) );
		Temp[i] = CreateRectangle();
		//FillRectangle( Temp[i] );
	}
	return Temp;
}
PointList* GetLastNode( PointList* Head ) {
	PointList* Temp = Head;
	if( Temp != 0 ) {
		while( Temp->NextPoint != 0 ) {
			Temp = Temp->NextPoint;
		}
	}
	return Temp;
}
PointList* swift( PointList* Head, int x, int y ) {
	if( Head == 0 ) {
		return CreateList( x, y );
	} else {
		PointList* Temp = (PointList*) malloc( sizeof( PointList ) );
		Temp->X = x;
		Temp->Y = y;
		Temp->NextPoint = NULL;
		GetLastNode( Head )->NextPoint = Temp;
	}
	return Head;
}
Rectangle** AddToEndArray( Rectangle** fegures,Rectangle* fegure, int &Size ) {
	Rectangle** Temp = CreateRectangleArray( Size + 1 );
	for( size_t i = 0; i < Size; i++ ) {
		Temp[i] = fegures[i];
	}
	Temp[Size] = fegure;
	Size++;
	free( fegures );
	return Temp;
}
int AddAfterIndex( Rectangle** fegures, Rectangle* fegure, int Index, int &Size ) {
	if( Index <= Size ) {
		fegures[Index] = CreateRectangle( fegure );
	} else {
		return -1;
	}
	return Index;
}
void FillRectangle( Rectangle* Figure ) {
	int XFirst, YFirst, XSecond, YSecond;
	XFirst = GetInt( 6, "Enter x coordinate(-32767 for 32767)" );
	YFirst = GetInt( 6, "Enter y coordinate(-32767 for 32767)" );
	Figure->Coordinates = swift( Figure->Coordinates, XFirst, YFirst );
	do {
		XSecond = GetInt( 6, "Enter second x coordinate(-32767 for 32767)" );
	} while( XFirst == XSecond );
	do {
		YSecond = GetInt( 6, "Enter second y coordinate(-32767 for 32767)" );
	} while( YFirst == YSecond );
	Figure->Coordinates = swift( Figure->Coordinates, XFirst, YSecond );
	Figure->Coordinates = swift( Figure->Coordinates, XSecond, YSecond );
	Figure->Coordinates = swift( Figure->Coordinates, XSecond, YFirst );
}
float CalcArea( Rectangle* figure ) {
	int A = sqrt( ( figure->Coordinates->NextPoint->Y - figure->Coordinates->Y ) *
					  ( figure->Coordinates->NextPoint->Y - figure->Coordinates->Y )
	);
	int B = sqrt( ( figure->Coordinates->NextPoint->NextPoint->NextPoint->X - figure->Coordinates->X ) *
					  ( figure->Coordinates->NextPoint->NextPoint->NextPoint->X - figure->Coordinates->X )
	);
	return A * B;
}
float CalcAreaArraies( Rectangle** figures, int Size ) {
	int Area = 0;
	for( size_t i = 0; i < Size; i++ ) {
		Area += CalcArea( figures[i] );
	} return Area;
}
void FillRectangleArraies( Rectangle** figures , int Size ) {
	for( size_t i = 0; i < Size; i++ ) {
		FillRectangle( figures [Size - 1]);
	}
}
void PointOutput( Rectangle* figure ) {
	PointList* Points = figure->Coordinates;
	while( Points != NULL ) {
		printf( "(x;y) = (%i;%i)\n", Points->X, Points->Y );
		Points = Points->NextPoint;
	}
}
void FeguresOutput( Rectangle** figures, int Size ) {
	for( size_t i = 0; i < Size; i++ ) {
		PointOutput( figures[i] );
		printf( "\n" );
	}
}
void FreeList( PointList* Head ) {
	PointList* Next = Head;
	PointList* Current = 0;
	while( (bool) Next->NextPoint != 0 ) {
		Current = Next;
		Next = Next->NextPoint;
		free( Current );
	}
	free( Next );
}
void FreeFigure( Rectangle* figure ) {
	FreeList( figure->Coordinates );
	free( figure );
}
void FreeFiguresArray( Rectangle** figures, int Size ) {
	for( size_t i = 0; i < Size; i++ ) {
		FreeFigure( figures[i] );
	}
	free( figures );
}
