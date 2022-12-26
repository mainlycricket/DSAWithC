#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueueFront(int);
void enqueueRear(int);
int dequeueFront();
int dequeueRear();
int isFull();
int isEmpty();
void traverse();

int main()
{
    enqueueFront(20); // 20
    enqueueRear(30);  // 20, 30
    enqueueRear(40);  // 20, 30, 40
    enqueueFront(10); // 10, 20, 30, 40
    enqueueFront(5);  // 5, 10, 20, 30, 40
    traverse();

    dequeueFront(); // 10, 20, 30, 40
    dequeueRear();  // 10, 20, 30
    traverse();

    return 0;
}

void enqueueFront(int data)
{
    if (isFull())
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    for (int i = rear; i >= front; i--)
        queue[i + 1] = queue[i];

    if (front == -1)
        front = 0;

    queue[front] = data;
    ++rear;
}

void enqueueRear(int data)
{
    if (isFull())
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    queue[++rear] = data;

    if (front == -1)
        front = 0;
}

int dequeueFront()
{
    if (isEmpty())
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    int data = queue[front];
    queue[front] = 0;
    ++front;

    return data;
}

int dequeueRear()
{
    if (isEmpty())
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    int data = queue[rear];
    queue[rear] = 0;
    --rear;

    return data;
}

void traverse()
{
    if (isEmpty())
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    printf("\nQueue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
