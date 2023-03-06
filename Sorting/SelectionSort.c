#include <stdio.h>

void selectionSort(int[], int); // ascending
void swap(int *, int *);
void traverse(int[], int);

int main()
{
    int arr[] = {45, 43, 64, 34, 89, 2};
    int size = sizeof(arr) / sizeof(int);

    printf("\nInitial Array: ");
    traverse(arr, size);

    selectionSort(arr, size);

    printf("\nSorted Array: ");
    traverse(arr, size);

    return 0;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
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