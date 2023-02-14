#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

bool ChoiceOperation() {//Функція вибору операції та порядок її виконань
	int W, H, t = 0;
	char strTemp[60] = "", strPhrase[60] = "";
	int** MatrixA;
	int** MatrixB;
	printf( "\nEnter the required operation: " );
	unsigned short NumOperation = GetInt(5);
	system( "cls" );
	switch( NumOperation ) {
		case 1:
			printf( "Enter width of matrix:" );
			do {
				W = GetInt( 6 );
			} while( W < 1 );
			printf( "Enter height of matrix:" );
			do {
				H = GetInt( 6 );
			} while( H < 1 );
			MatrixA = (int**) malloc( H * sizeof( int* ) );
			CreateMatrix( W, H, MatrixA );
			InsertInMatrix( W, H, MatrixA );
			printf( "Enter mul number " );
			MulMatrixByNumber( W, H, MatrixA, GetInt(99) );
			break;
		case 2:
			printf( "Enter size of matrix:" );
			do {
				W = GetInt( 6 );
			} while( W < 1 );
			MatrixA = (int**) malloc( W * sizeof( int* ) );
			MatrixB = (int**) malloc( W * sizeof( int* ) );
			CreateMatrix( W, W, MatrixA );
			CreateMatrix( W, W, MatrixB );
			InsertInMatrix( W, W, MatrixA );
			InsertInMatrix( W, W, MatrixB );
			MulMatrixByMatrix( W, MatrixA, MatrixB );
			break;
		case 3:
			printf( "Enter width " );
			do {
				W = GetInt( 6 );
			} while( W < 1 );
			printf( "Enter height " );
			do {
				H = GetInt( 6 );
			} while( H < 1 );
			MatrixA = (int**) malloc( H * sizeof( int* ) );
			MatrixB = (int**) malloc( H * sizeof( int* ) );
			CreateMatrix( W, H, MatrixA );
			CreateMatrix( W, H, MatrixB );
			InsertInMatrix( W, H, MatrixA );
			InsertInMatrix( W, H, MatrixB );
			AddMatrixByMatrix( W, H, MatrixA, MatrixB );
			break;
		case 4:
			printf( "Enter width " );
			do {
				W = GetInt( 6 );
			} while( W < 1 );
			printf( "Enter height " );
			do {
				H = GetInt( 6 );
			} while( H < 1 );
			MatrixA = (int**) malloc( H * sizeof( int* ) );
			CreateMatrix( W, H, MatrixA );
			InsertInMatrix( W, H, MatrixA );
			MatrixB = (int**) malloc( H * sizeof( int* ) );
			CreateMatrix( W, H, MatrixB );
			InsertInMatrix( W, H, MatrixB );
			SubMatrixByMatrix( W, H, MatrixA, MatrixB );
			break;
		case 5:
			printf( "Enter width " );
			do {
				W = GetInt( 6 );
			} while( W < 1 );
			printf( "Enter height " );
			do {
				H = GetInt( 6 );
			} while( H < 1 );
			MatrixA = (int**) malloc( H * sizeof( int* ) );
			CreateMatrix( W, H, MatrixA );
			InsertInMatrix( W, H, MatrixA );
			TranspositionMatrix( W, H, MatrixA );
			break;
		case 6:
			printf( "Enter words: " );
			GetStr( strTemp, 12 );
			printf( "Enter Phrase: " );
			GetStr( strPhrase, 12 );
			printf( "%i", FindPhrases( strTemp, strPhrase ));
			break;
		case 7:
			printf( "Enter values " );
			GetStr( strTemp, 12 );
			InversArray(strTemp);
			printf( "%s", strTemp );
			break;
		case 8:
			printf( "Enter words " );
			GetStr( strTemp, 12 );
			printf( "%i", WordCount( strTemp ) );
			break;
		case 9:
			printf( "Enter words " );
			GetStr( strTemp, 12 );
			printf( "Enter Phrase " );
			GetStr( strPhrase , 12);
			printf( "%i", PhraseCount( strTemp, strPhrase ) );
			break;
		case 10:
			printf( "Enter numbers " );
			GetStr( strTemp, 4 );
			OctalToDec( strTemp, t );
			printf( "%i\n", t );
			break;
		case 11:
			printf( "Enter numbers " );
			GetStr( strTemp, 4 );
			HexlToDec( strTemp, t );
			printf( "%i\n", t );
			break;
		case 12:
			printf( "Enter numbers " );
			GetStr( strTemp , 8);
			BinarToDec( strTemp, t );
			printf( "%i\n", t );
			break;
		default:
			return false;
	}
}
void InversArray( char Arr[] ) {//Функція перевертання/віддзеркалення масиву
	char t;
	for( size_t i = 0, Size = strlen( Arr ); i < Size/2; i++ ) {
		t = Arr[i];
		Arr[i] = Arr[Size - i - 1];
		Arr[Size - i - 1] = t;
	}
}
void Display() {
	printf( "1.  multiplication of a matrix by a number\n" );
	printf( "2.  multiplication of two matrices\n" );
	printf( "3.  sum of two matrices\n" );
	printf( "4.  subtraction of two matrices\n" );
	printf( "5.  matrix transposition\n" );
	printf( "6.  searches for character set assignments and returns the address of the first occurrence or -1\n" );
	printf( "7.  flip array\n" );
	printf( "8.  number of searched character sets in the sentence\n" );
	printf( "9.  number of words in a sentence\n" );
	printf( "10. lowercase 16th (no more than 4 characters) number in 10\n" );
	printf( "11. lowercase 8th (no more than 4 characters) number in 10\n" );
	printf( "12. lowercase 2nd (no more than 8 characters) number in 10\n" );
}
void Start() {
	do {
		Display();
		ChoiceOperation();
		system( "pause" );
		system( "cls" );
		printf( "want to continue? 1 (y) or 0 (n)" );
		int t = GetInt( 2 );
		if( t == 0 ) break;
	} while( 1 );
}