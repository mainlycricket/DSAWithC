// Beginning of the linked list is considered as the TOP of the stack.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL; // Global TOP pointer

void push(int);
int pop();
void traverse();
int peek();

int main()
{
    int data;

    push(10);
    push(20);
    push(30);

    traverse();

    data = pop();
    printf("\nPopped Item: %d", data);

    data = pop();
    printf("\nPopped Item: %d", data);

    traverse();

    return 0;
}

void push(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nStack OVERFLOW!");
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    int data;
    struct node *temp = top;

    if (top == NULL)
    {
        printf("\nStack UNDERFLOW!");
        exit(1);
    }

    data = top->data;
    top = top->next;

    free(temp);
    temp = NULL;
    return data;
}

void traverse()
{
    struct node *temp = top;
    printf("\nTraversing stack:");
    if (temp == NULL)
    {
        printf("\nStack UNDERFLOW!");
        return;
    }

    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}

int peek()
{
    if (top == NULL)
    {
        printf("\nStack UNDERFLOW!");
        exit(1);
    }
    return top->data;
}
