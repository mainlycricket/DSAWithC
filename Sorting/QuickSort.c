#include <stdio.h>

void quickSort(int[], int, int);     // ascending
int partition(int[], int, int);
void swap(int *, int *);
void traverse(int[], int);

int main()
{
    int arr[] = {45, 43, 64, 34, 89, 2};
    int size = sizeof(arr) / sizeof(int);

    traverse(arr, size);
    quickSort(arr, 0, size - 1);
    traverse(arr, size);

    return 0;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end) {
        int splitIndex = partition(arr, start, end);
        quickSort(arr, start, splitIndex - 1);
        quickSort(arr, splitIndex + 1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(&arr[i], &arr[pIndex]);
            ++pIndex;
        }
    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void traverse(int arr[], int size)
{
    printf("\nArray: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
