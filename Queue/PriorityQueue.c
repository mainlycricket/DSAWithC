// Higher number indicates higher priority

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    int data, priority;
};

struct node queue[MAX];
int size = -1, highestPriority = -1;

void enqueue(int, int);
int dequeue();
void traverse();

int main()
{
    enqueue(70, 6);
    enqueue(30, 2);
    enqueue(60, 5);
    enqueue(20, 1);
    enqueue(50, 4);
    enqueue(10, 0);
    enqueue(40, 3);
    traverse();

    dequeue();
    dequeue();
    traverse();

    return 0;
}

void enqueue(int data, int priority)
{
    if (size == MAX - 1)
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    if (priority < 0)
    {
        printf("\nPriority can't be negative");
        exit(1);
    }

    if (priority >= highestPriority)
    {
        ++size;
        queue[size].data = data;
        queue[size].priority = priority;
        highestPriority = priority;
    }

    else
    {
        int i = 0;
        while (queue[i].priority < priority)
            ++i;
        for (int j = size; j >= i; j--)
        {
            queue[j + 1].data = queue[j].data;
            queue[j + 1].priority = queue[j].priority;
        }
        queue[i].data = data;
        queue[i].priority = priority;
        ++size;
    }
}

int dequeue()
{
    if (size == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    int data = queue[size].data;
    highestPriority = queue[size - 1].priority;
    --size;

    return data;
}

void traverse()
{
    if (size == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }
    printf("\nQueue: ");
    for (int i = size; i >= 0; i--)
        printf("%d ", queue[i].data);
}
