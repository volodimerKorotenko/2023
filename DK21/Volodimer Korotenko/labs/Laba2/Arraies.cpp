#include "Functions.h"
int main()
{
	int Size = 0;
	do {
		Size = GetInt( 6, "Entri size" );
	} while( Size < 0 );
	Node *List = 0;
	List = DataEntry( List, Size );
	List = BulbSort( List );
	ListOutput( List );
	FreeList( List );
}