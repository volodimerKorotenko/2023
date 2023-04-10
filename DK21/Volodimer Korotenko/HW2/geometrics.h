#pragma once
typedef struct Point{
	int X;
	int Y;
	Point* NextPoint;
} Point;
typedef struct Figure {
	Point *Coordinates;
} Figure;
int GetInt( int Max, const char Message[] );
Figure* CreateFigure();
Point* CreateList( int x, int y );
Point* GetLastNode( Point* Head );
Point* swift( Point* Head, int x, int y );
void CreateSquare( Figure* Figure );
float CalcArea( Figure* figure );
void FreeList( Point* Head );
void FreeFigure( Figure* figure );
void PointOutput( Figure* figure );