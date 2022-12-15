#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{

    struct node node1;
    struct node *ptr = &node1;

    char arr[2][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}};
    // char *p = arr;

    // printf("%u %c", p, *p);
    // p++;
    // printf("\n%u %c", p, *p);

    char *p = *arr;
    *p = 'x';
    printf("%c", arr[0][0]);

    // ptr->data = 10;
    (*ptr).data = 20;

    printf("\nRoot Node:");
    printf("\nData: %d, %d & %d", node1.data, ptr->data, (*ptr).data);

    return 0;
}