#include <stdio.h>

void insertionSort(int[], int);     // ascending
void traverse(int[], int);

int main()
{
    int arr[] = {45, 43, 64, 34, 89, 2};
    int size = sizeof(arr) / sizeof(int);

    traverse(arr, size);
    insertionSort(arr, size);
    traverse(arr, size);

    return 0;
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int hole = i, temp = arr[i];
        while (hole > 0 && arr[hole - 1] > temp)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = temp;
    }
}

void traverse(int arr[], int size)
{
    printf("\nArray: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
