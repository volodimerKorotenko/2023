#include "Lists.h"
#include <stdio.h>
int main()
{
		int Size = 0, Value, Index;
		do {
			Size = GetInt( 6, "Entri size" );
		} while( Size < 1 );
		Node* List = 0;
		List = DataEntry( List, Size );
		ListOutput( List );
		printf( "Size of list: %i\n", SizeList( List ) );

		printf( "\n" );
		Pop( List );
		printf( "After pop\n" );
		ListOutput( List );
		printf( "Size of list: %i\n", SizeList( List ) );

		printf( "\n" );
		do {
			Value = GetInt( 6, "Entri value" );
		} while( Size < 1 );
		do {
			Index = GetInt( 6, "Entri index" );
		} while( Size < 1 );
		AddAfterIndex( List, Value, Index );
		ListOutput( List );
		printf( "Size of list: %i\n", SizeList( List ) );

		FreeList( List );
}
