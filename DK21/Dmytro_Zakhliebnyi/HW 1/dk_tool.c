    #include "dk_tool.h"

void permuteArray(int arr[], int n)
{
    int i, j, temp;
    for (i = 0, j = n-1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

