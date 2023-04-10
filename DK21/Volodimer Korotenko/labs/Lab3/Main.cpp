#include "Trees.h"

int main()
{
   Node* BinaryTree = 0;
   int count = 0;
   do {
      count = GetInt( 6, "Count: " );
   } while( count < 0 );
   BinaryTree = TreeEntry( BinaryTree, count );
   PrintTree( BinaryTree );
   DeleteNode( BinaryTree, GetInt( 6, "Delete value: " ));
   PrintTree( BinaryTree );
   FreeTree( BinaryTree );
}
