#include <stdio.h>
#include <stdlib.h>

int *input()
{
    int data = 20;
    int *ptr = &data;
    return ptr;
}

int main()
{

    int *ptr2 = input();
    printf("%d\n", *ptr2);
    *ptr2 = 30;
    printf("%d", *ptr2);

    return 0;
}
