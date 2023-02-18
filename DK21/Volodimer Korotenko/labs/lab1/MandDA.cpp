#include "MandDA.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int Factorial( int Number) {// Функція факторіалу
	int Factorial = 1;
	for( int i = 1; i < Number; i++ ) {
		Factorial += Factorial * i;
	}
	return Factorial;
}
int Sum(int ( *Formula )( int, int ), int NumberOfTimes, int A, int n) {// Функція суми значень
	int Result = 0, Temp = 0;
	for( ; n < NumberOfTimes; n++ ) {
		Result += Formula(n, A);
	}
	return Result;
}
int exponentiation(int RaisedToPower,int degree) {// Функція зведення у степінь
	if( degree == 0) {
		return 1;
	}
	int Resultat = RaisedToPower;
	for( size_t i = 1; i < degree; i++ ) {
		Resultat *= RaisedToPower;
	}
	return Resultat;
}
int ABS(int Number) {// Функція модулю числа
	if( Number < 0) return -Number;
	else return Number;
}
int GetInt(int Max,const char Message[]) {// Функція отримання цілого числа
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
void ChoiceOfOption(int option ) {// Функція обчислення вибраної операції
	int A, B, C, Q;
	A = GetInt( 6 , "enter the value of variable A: ");
	B = GetInt( 6 , "enter the value of variable B: ");
	C = GetInt( 6 , "enter the value of variable C: ");
	Q = NULL;
	switch( option ) {
		case 1:
			Q = ( A * B ) / ( B + exponentiation( C, 2 ) ) + Sum( Formula_1, B );
			break;
		case 2:
			Q = (ABS( A * C - B ))/( exponentiation(C, 3) ) + Sum(Formula_2, A);
			break;
		case 3:
			Q = A * (sqrt( B + C ) / B) + Sum( Formula_3, C, A );
			break;
		case 4:
			Q = ( A + B + C ) / ( 100 - B - C ) + Sum( Formula_4, C, A );
			break;
		case 5:
			Q = ( exponentiation( A, 2 ) + exponentiation( B, 2 ) ) / ( B + exponentiation( 5, C ) ) + Factorial( B );
			break;
		case 6:
			Q = Factorial( A ) /  ABS( 2 * A + B );
			break;
		default:
			break;
	}
	printf( "calculation result = %i\n", Q );
	system( "pause" );
}
void Menu(char Menu[][103], int Heaght) {// Функція вибору операції
	int Chose = 0;
	char Arrow[] = "-->";
	char Temp[255];
	char Char;
	do {
		do {
			for( size_t i = 0; i < Heaght; i++ ) {
				if( i != Chose ) {
					snprintf( Temp, sizeof Temp, "%s%s", "   ", Menu[i] );
				} else {
					snprintf( Temp, sizeof Temp, "%s%s", Arrow, Menu[i] );
				}
				printf( Temp );
			}
			Char = _getch();
			if( Char == 'w' && Chose != 0 ) {
				Chose--;
			} else if( Char == 's' && Chose != 5 ) {
				Chose++;
			}
			system( "cls" );
		} while( Char != 13 );
		ChoiceOfOption( Chose + 1 );
		system( "cls" );
		printf("Press ENTER if you want to continue or any other character to end\n");
		Char = _getch();
		if( Char != 13 ) break;
	} while( true );
}
void CallMenu() {
	char option[][103] =  {
		"( A * B ) / ( B + exponentiation( C, 2 ) ) + Sum( Formula_1, B )\n",
		"(ABS( A * C - B ))/( exponentiation(C, 3) ) + Sum(Formula_2, A)\n",
		"A * ( sqrt( B + C ) ) / B + Sum( Formula_3, C )\n",
		"( A + B + C ) / ( 100 - B - C ) + Sum( Formula_4, C, A )\n",
		"( exponentiation( A, 2 ) + exponentiation( B, 2 ) ) / ( B + exponentiation( 5, C ) ) + Factorial( B )\n",
		"Factorial( A ) /  ABS( 2 * A + B )"
	};
	Menu( option , 6);
}
int Formula_1( int Counter, int Buff ) {
	return Factorial( Counter );
}
int Formula_2( int Counter, int Buff ) {
	return exponentiation( 2, Counter );
}
int Formula_3( int Counter, int A ) {
	return Factorial( Counter + A );
}
int Formula_4( int Counter, int A ) {
	return exponentiation( 2, Counter + A );
}