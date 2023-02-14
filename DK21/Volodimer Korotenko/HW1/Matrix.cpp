#include "Matrix.h"
#include "Base.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


void InsertInMatrix( int Width, int Height, int** Matrix ) {//функція введення чисел у матрицю
	printf( "Enter matrix values ​​(left to right): " );
	for( size_t i = 0; i < Height; i++ ) {
		for( size_t j = 0; j < Width; j++ ) {
			Render( Width, Height, Matrix );
			printf( "Enter matrix value: " );
			Matrix[i][j] = GetInt(99);
			system( "cls" );
		}
	}
	Render( Width, Height, Matrix );
	system( "pause" );
	system( "cls" );
}
void CreateMatrix( int Width, int Height, int** Matrix ) {//функція ініціалізування масива
	for( int i = 0; i < Height; i++ ) {
		Matrix[i] = (int*) malloc( Width * sizeof( int ) );
		for( size_t j = 0; j < Width; j++ ) {
			Matrix[i][j] = 0;
		}
	}
}
void Render( int Width, int Height, int** Matrix ) {// Функція виведення матриці у консоль
	printf( "\n" );
	for( size_t i = 0; i < Height; i++ ) {
		printf( "| " );
		for( size_t j = 0; j < Width; j++ ) {
			printf("%i ", Matrix[i][j]);
		}
		printf( "|\n" );
	}
}
void MulMatrixByNumber( int Width, int Height, int** Matrix, int Number ) {//Функція множення кожний комірки матріці на цисло
	printf( "Multiply matrix: " );
	Render( Width , Height , Matrix );
	printf( "per number %i\n", Number );
	system( "pause" );
	system( "cls" );
	for( size_t i = 0; i < Height; i++ ) {
		for( size_t j = 0; j < Width; j++ ) {
			Matrix[i][j] *= Number;
		}
	}
	printf( "The result of multiplying by %i\n", Number );
	Render( Width, Height, Matrix );
	system( "pause" );
	system( "cls" );
}
void MulMatrixByMatrix( int Size, int** MatrixA, int** MatrixB ) {//Функція множення кожний комірки матриці на такуж комірку матриці
	int** MatrixC = (int**) malloc( Size * sizeof( int* ) );
	CreateMatrix( Size, Size, MatrixC );
	int Temp = 0;
	for( size_t i = 0; i < Size; i++ ) {
		for( size_t j = 0; j < Size; j++ ) {
			for( size_t k = 0; k < Size; k++ ) {
				Temp += MatrixA[i][k] * MatrixB[k][j];
			}
			MatrixC[i][j] = Temp;
			Temp = 0;
		}
	}
	Render( Size, Size, MatrixC );
	for( size_t i = 0; i < Size; i++ ) {
		free( MatrixC[i] );
	}
	free( MatrixC );
}
void AddMatrixByMatrix( int Width, int Height, int** MatrixA, int** MatrixB ) {//Функція додавання матриць
	int** MatrixC = (int**) malloc( Height * sizeof( int* ) );
	CreateMatrix( Width, Height, MatrixC );
	for( size_t i = 0; i < Height; i++ ) {
		for( size_t j = 0; j < Width; j++ ) {
			MatrixC[i][j] = MatrixA[i][j] + MatrixB[i][j];
		}
	}
	Render( Width, Height, MatrixC );
	for( size_t i = 0; i < Height; i++ ) {
		free( MatrixC[i] );
	}
	free( MatrixC );
}
void SubMatrixByMatrix( int Width, int Height, int** MatrixA, int** MatrixB ) {//Функція відміння матриць
	int** MatrixC = (int**) malloc( Height * sizeof( int* ) );
	CreateMatrix( Width, Height, MatrixC );
	for( size_t i = 0; i < Height; i++ ) {
		for( size_t j = 0; j < Width; j++ ) {
			MatrixC[i][j] = MatrixA[i][j] - MatrixB[i][j];
		}
	}
	Render( Width, Height, MatrixC );
	for( size_t i = 0; i < Height; i++ ) {
		free( MatrixC[i]);
	}
	free( MatrixC );
}
void TranspositionMatrix( int Width, int Height, int** Matrix ) {//Функція транспозиції матриці
	int Temp;
	for( size_t i = 0; i < Height; i++) {
		for( size_t j = 0; j + i  < Width; j++ ) {
			Temp = Matrix[i][j + i];
			Matrix[i][j + i] = Matrix[j + i][i];
			Matrix[j+ i][i] = Temp;
		}
	}
	Render( Width, Height, Matrix );
}