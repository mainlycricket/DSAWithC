#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)malloc(5 * sizeof(int));

    printf("\nInitial Data: ");

    for (int i = 0; i < 5; i++)
        printf("%d ", *(ptr + i));

    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter an integer: ");
        scanf("%d", (ptr + i));
    }

    printf("\nYou entered: ");

    for (int i = 0; i < 5; i++)
        printf("%d ", *(ptr + i));

    return 0;
}