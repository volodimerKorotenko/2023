#include "list.h"
#include <string.h>

int main(void)
{
    List *list = CreateList();

    if (!AddValueToList(list, 9) ||
        !AddValueToList(list, 5) ||
        !AddValueToList(list, 3) ||
        !AddValueToList(list, 8) ||
        !AddValueToList(list, 4) ||
        !AddValueToList(list, 2) ||
        !AddValueToList(list, 10) ||
        !AddValueToList(list, 12) ||
        !AddValueToList(list, 45) ||
        !AddValueToList(list, 11)) {
        fprintf(stderr, "Failed to add element to the list.\n");
        DeleteList(list);
        return 1;
    }

    printf("Unsorted list: ");
    PrintList(list);

    SortBeforeMax(list);

    printf("\nSorted list: ");
    PrintList(list);
    printf("\n");

    DeleteList(list);
    return 0;
}

