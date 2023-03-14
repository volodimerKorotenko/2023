#include "Functions.h"
int main()
{
	int Size = GetInt( 6, "Enter dimension value: " );
	int *List = createArray( Size );
	InputArray( List , Size );
	BulbSort( List, Size );
	Display( List, Size );
	DestroyArray( List, Size );
}