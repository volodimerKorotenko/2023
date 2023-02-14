#include <string>
#include <malloc.h>

#define SIZE 6+2

int exponentiation( int Number, int degree ) {//функція зведення у степінь
	if( degree == 0 ) return 1;
	int a = Number;
	for( size_t i = 1; i < degree; i++ ) {
		a *= Number;
	}
	return a;
}
bool StrToInt( char String[], int& Number ) {//Текстове чісло у число
	int Size = strlen( String );
	for( int i = Size; i > 0; i-- ) {
		if( String[i - 1] < '0' || String[i - 1] > '9' ) return false;
		Number += ( String[i - 1] - '0' ) * exponentiation( 10, Size - i );
	}
	return true;
}
int GetInt(int Size) {//Очікує вод користувача і перетворює отриманий строку в число
	Size++;
	char *String = (char*)malloc(sizeof(Size));
	int Number = 0;
	do {
		fgets( String, Size, stdin );
		if( String[strlen( String ) - 1] == '\n' ) {
			String[strlen( String ) - 1] = 0;
			if( StrToInt( String, Number ) ) {
				break;
			}
		}
	} while( 1 );
	return Number;
}
void GetStr( char NewString[], int Size ) {//Функція вода строки користувачем
	Size++;
	char *String = (char* )malloc(99);
	do {
		fgets( String, 99, stdin );
		for( size_t i = 0; i < strlen( String ); i++ ) {

		}
	} while( strlen( String ) > Size );
	String[strlen( String ) - 1] = 0;
	for( size_t i = 0, a = strlen( String ); i < a; i++ ) {
		NewString[i] = String[i];
	}
}