#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
    enqueue(50);
    traverse();     // 10, 20, 30, 40, 50

    dequeue();      // Remove 10
    traverse();     // 20, 30, 40, 50
    enqueue(60);    // Reality: 60, 20, 30, 40, 50
    traverse();     // 20, 30, 40, 50, 60

    dequeue();      // Remove 20
    traverse();     // 30, 40, 50, 60

    return 0;
}

void enqueue(int data)
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    if (rear == MAX - 1)
        rear = 0;
    else
        ++rear;

    queue[rear] = data;

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
        front = -1, rear = -1;
    else if (front == MAX - 1)
        front = 0;
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

    // Normal Queue
    if (front <= rear)
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);

    // Circular Queue
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}
