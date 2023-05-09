#include <stdio.h>
#include "array.h"

int main() {
    Array *arr = create_array(5);

    Ellipse el1 = {{0,0}, 2, 4};
    Ellipse el2 = {{1,1}, 3, 5};
    Ellipse el3 = {{2,2}, 4, 6};
    Ellipse el4 = {{3,3}, 5, 7};

    add_element(arr, &el1);
    add_element(arr, &el2);
    add_element(arr, &el3);

    int index = insert_element(arr, &el4, 1);
    if (index == -1) {
        printf("Insertion failed\n");
    } else {
        printf("Inserted ellipse at index %d\n", index);
    }

    print_array(arr);

    destroy_array(arr);
    return 0;
}
