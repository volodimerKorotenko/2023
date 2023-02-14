#include "Base.h"
#include <string.h>

bool OctalToDec( char strNum[], int &Num ) {//‘ункц≥€ восьмир≥чний строки в дес€тичню число
	for( size_t i = 0, Size = strlen( strNum ), t; i < Size; i++ ) {
		t = strNum[i];
		if( t >= '0' && t < '9' ) {
			Num += ( t - '0' ) * exponentiation(8, Size - i - 1);
		} else {
			Num = 0;
			return false;
		}
	}
	return true;
}
bool HexlToDec( char strNum[], int& Num ) {//‘ункц≥€ ш≥стнадц€тир≥чний строки в дес€тичню число
	for( size_t i = 0, Size = strlen( strNum ), t; i < Size; i++ ) {
		t = strNum[i];
		if( t >= '0' && t <= '9' ) {
			Num += ( t - '0' ) * exponentiation( 16, Size - i );
		} else if( t >= 'a' && t <= 'f' ) {
			Num += ( t - 'a' + 10 ) * exponentiation( 16, Size - i - 1);
		} else if( t >= 'A' && t <= 'F' ) {
			Num += ( t - 'A' + 10 ) * exponentiation( 16, Size - i - 1);
		} else {
			Num = 0;
			return false;
		}
	}
	return true;
}
bool BinarToDec( char strNum[], int& Num) {//‘ункц≥€ восьмир≥чний строки в дес€тичню число
	for( size_t i = 0, Size = strlen( strNum ), t; i < Size; i++ ) {
		t = strNum[i];
		if( t >= '0' && t < '2' ) {
			Num += ( t - '0' ) * exponentiation( 2, Size - i - 1);
		} else {
			Num = 0;
			return false;
		}
	}
	return true;
}