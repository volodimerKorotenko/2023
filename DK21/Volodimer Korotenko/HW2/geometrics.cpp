#include "geometrics.h"
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
Figure* CreateFigure( ) {
	Figure* NewFegure = (Figure*)malloc(sizeof( Figure ));
	if( NewFegure == 0 ) {
		exit( -2 );
	}
	NewFegure->Coordinates = NULL;
	return NewFegure;
}
Point* CreateList(int x, int y) {
	Point* Temp = (Point*) malloc( sizeof( Point ) );
	if( Temp == 0 ) {
		exit( -2 );
	}
	Temp->X = x;
	Temp->Y = y;
	Temp->NextPoint = NULL;
	return Temp;
}
Point* GetLastNode(Point *Head) {
	Point* Temp=Head;
	if( Temp != 0 ) {
		while( Temp->NextPoint != 0 ) {
			Temp = Temp->NextPoint;
		}
	}
	return Temp;
}
Point* swift( Point* Head, int x, int y ) {
	if( Head == 0 ) {
		return CreateList( x, y );
	} else {
		Point* Temp = (Point*) malloc( sizeof( Point ) );
		Temp->X = x;
		Temp->Y = y;
		Temp->NextPoint = NULL;
		GetLastNode( Head )->NextPoint = Temp;
	}
	return Head;
}
void CreateSquare( Figure* Figure ) {
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
float CalcArea( Figure* figure ) {
	int A = sqrt((figure->Coordinates->NextPoint->Y - figure->Coordinates->Y) *
					  ( figure->Coordinates->NextPoint->Y - figure->Coordinates->Y )
	            );
	int B = sqrt(( figure->Coordinates->NextPoint->NextPoint->NextPoint->X - figure->Coordinates->X ) * 
					  ( figure->Coordinates->NextPoint->NextPoint->NextPoint->X - figure->Coordinates->X )
	             );
	return A * B;
}
void FreeList( Point* Head ) {
	Point* Next = Head;
	Point* Current = 0;
	while( (bool) Next->NextPoint != 0 ) {
		Current = Next;
		Next = Next->NextPoint;
		free( Current );
	}
	free( Next );
}
void FreeFigure( Figure* figure ) {
	FreeList( figure->Coordinates );
	free( figure );
}
void PointOutput( Figure* figure ) {
	Point *Points = figure->Coordinates;
	while( Points != NULL ) {
		printf("(x;y) = (%i;%i)\n", Points->X,Points->Y);
		Points = Points->NextPoint;
	}
}