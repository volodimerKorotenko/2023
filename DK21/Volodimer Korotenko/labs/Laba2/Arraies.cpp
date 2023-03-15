#include "Functions.h"
int main()
{
	int Size;
	do {
		Size = GetInt( 6, "Enter dimension value: " );
	} while( Size < 0 );
	int *List = createArray( Size );
	InputArray( List , Size );
	BulbSort( List, Size );
	Display( List, Size );
	DestroyArray( List, Size );
}