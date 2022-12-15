#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// global variables
int stack_arr[MAX];
int top = -1;

void push(int);
int pop();
void traverse();
int isEmpty();
int isFull();
int peek();     // Return TOP of the stack

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // Overflow
    traverse();
    pop();
    pop();
    pop();
    pop();
    pop();
    // pop();   Underflow EXIT;
    traverse();     // Underflow
    return 0;
}

void push(int data)
{
    printf("\nInserting %d...", data);
    if (isFull())
    {
        printf("\nStack is full. OVERFLOW!");
        return;
    }
    top += 1;
    stack_arr[top] = data;
    printf("\nInserted!");
}

int pop()
{
    printf("\nPoping TOP...");
    if (isEmpty())
    {
        printf("\nStack is empty. UNDERFLOW!");
        exit(-1);
    }
    int data = stack_arr[top];
    printf("\nDeleted %d from stack.", data);
    top -= 1;
    return data;
}

void traverse()
{
    printf("\nTraversing Stack: ");
    if (isEmpty())
    {
        printf("\nStack is empty. UNDERFLOW!");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d\t", stack_arr[i]);
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

int peek() {
    if (isEmpty()) {
        printf("\nStack is empty. UNDERFLOW!");
    }
    return stack_arr[top];
}
