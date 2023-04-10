#include <stdio.h>
#include "list.h"

//5 двозв'язний список + int
int main () {
    IntList *lst = createIntList();

    addIntValueToIntList(lst, 1);
    addIntValueToIntList(lst, 5);
    addIntValueToIntList(lst, 13);
    addIntValueToIntList(lst, 13);
    addIntValueToIntList(lst, 28);
    addIntValueToIntList(lst, 0);

    printIntList(lst);
    printf("Inserting element on index 3...\n");
    insertIntElementToIntListAtIndex(lst, 3, -3);
    printIntList(lst);
    printf("List size: %ld\n", countOfIntList(lst));
    printf("Result of deleting elment on index 22: %d\n", removeIntElementFromIntListAtIndex(lst, 22));
    printf("Result of deleting elment on index 2: %d\n", removeIntElementFromIntListAtIndex(lst, 2));
    printIntList(lst);

    deleteIntList(lst);
    return 0;
}