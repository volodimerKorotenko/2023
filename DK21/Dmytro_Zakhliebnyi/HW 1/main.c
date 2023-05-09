#include <stdio.h>
#include "dk_tool.h"

void inputArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void outputArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    inputArray(arr, n);

    printf("Original array: ");
    outputArray(arr, n);

    permuteArray(arr, n);

    printf("Permuted array: ");
    outputArray(arr, n);

    return 0;
}
