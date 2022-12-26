#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int);
int dequeue();
void traverse();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    traverse();

    dequeue();
    dequeue();
    traverse();

    return 0;
}

void enqueue(int data)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    queue[++rear] = data;

    if (front == -1)
        front = 0;
}

int dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    int data = queue[front];
    queue[front] = 0;

    if (front == rear)
        front = rear = -1;
    else
        ++front;

    return data;
}

void traverse()
{
    if (front == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    printf("\nQueue: ");

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}
