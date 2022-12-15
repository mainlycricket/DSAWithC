#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter an integer: ");
        scanf("%d", (ptr + i));
    }

    // reallocating

    ptr = (int *)realloc(ptr, 5);

    printf("\nRellocated, array: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", *(ptr + i));

    for (int i = 3; i < 5; i++)
    {
        printf("\nEnter an integer: ");
        scanf("%d", (ptr + i));
    }

    printf("\nYou entered: ");

    for (int i = 0; i < 5; i++)
        printf("%d ", *(ptr + i));

    return 0;
}