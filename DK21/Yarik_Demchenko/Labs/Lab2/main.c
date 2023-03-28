#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main () {
    printf("Note, that every value must be integer value!\n");
    int size = 0;
    printf("Enter size of your list: ");
    scanf("%d", &size);

    IntSingleList *list = createIntSingleList();

    int temp = 0;
    for(int i = 0; i < size; i++) {
        printf("Enter %d value: ", i);
        scanf("%d", &temp);
        addIntValueToIntSingleList(list, temp);
    }

    printf("Your list:\n");
    printIntSingleList(list);
    
    float average = findAverageFromIntSingleList(list);
    printf("Average value: %f\n", average);

    int i = 0;
    for (SingleListIntElement *element = list->head; element != NULL; element = element->next, i++) {
		if (element->value < average) {
            printf("Element to delete: %d at index %d\n", element->value, i);
			removeIntElementFromIntSingleListAtIndex(list, i);
            break;
		}
	}

    printf("Your list:\n");
    printIntSingleList(list);

    deleteIntSingleList(list);
}