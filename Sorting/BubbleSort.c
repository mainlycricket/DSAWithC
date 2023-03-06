#include <stdio.h>

void bubbleSort(int[], int);   // ascending
void swap(int *, int *);
void traverse(int[], int);

int main()
{
    int arr[] = {45, 43, 64, 34, 89, 2};
    int size = sizeof(arr) / sizeof(int);

    printf("\nInitial Array: ");
    traverse(arr, size);

    bubbleSort(arr, size);
    
    printf("\nSorted Array: ");
    traverse(arr, size);

    return 0;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void traverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
