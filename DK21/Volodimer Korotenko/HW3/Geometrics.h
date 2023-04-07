#pragma once
typedef struct PointList {
	int X;
	int Y;
	PointList* NextPoint;
} PointList;
typedef struct Rectangle {
	PointList* Coordinates;
} Rectangle;
int GetInt( int Max, const char Message[] );
Rectangle* CreateRectangle( Rectangle* Figure = 0 );
PointList* CreateList( int x, int y );
Rectangle** CreateRectangleArray( int Size );
PointList* GetLastNode( PointList* Head );
PointList* swift( PointList* Head, int x, int y );
Rectangle** AddToEndArray( Rectangle** fegures, Rectangle* fegure, int& Size );
int AddAfterIndex( Rectangle** fegures, Rectangle* fegure, int Index, int &Size );
void FillRectangle( Rectangle* Figure );
float CalcArea( Rectangle* figure );
float CalcAreaArraies( Rectangle** figures, int Size );
void FillRectangleArraies( Rectangle** figures, int Size );
void PointOutput( Rectangle* figure );
void FeguresOutput( Rectangle** figures, int Size );
void FreeList( PointList* Head );
void FreeFigure( Rectangle* figure );
void FreeFiguresArray( Rectangle** figures, int Size );