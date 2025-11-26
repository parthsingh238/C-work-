#include <stdio.h>
int main()
{
    int arr[100];
    int size, i, j, temp;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Array sorting code
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nElements of array in sorted ascending order: ");
    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}