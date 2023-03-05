#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtBeg(struct node **, int);
void insertAtEnd(struct node **, int);
void insertAtPos(struct node **, int, int);

void deleteAtBeg(struct node **);
void deleteAtEnd(struct node **);

void traverse(struct node *);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    insertAtBeg(&head, 20); // 20
    deleteAtBeg(&head);     // Empty List

    insertAtBeg(&head, 10); // 10
    insertAtEnd(&head, 30); // 10, 30

    deleteAtEnd(&head);     // 10
    insertAtEnd(&head, 40); // 10, 40

    insertAtPos(&head, 20, 2);
    insertAtPos(&head, 30, 3);

    traverse(head);

    return 0;
}

void insertAtBeg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = *head;

    *head = temp;
}

void insertAtEnd(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        temp->prev = NULL;
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    temp->prev = ptr;
    ptr->next = temp;
}

void insertAtPos(struct node **head, int data, int pos)
{
    if (pos == 1)
    {
        insertAtBeg(&(*head), data);
        return;
    }

    int count = 0;
    struct node *ptr = *head;
    while (count < pos - 2)
    {
        if (ptr == NULL)
        {
            printf("\nNot enough nodes!");
            exit(1);
        }

        ptr = ptr->next;
        ++count;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;

}

void deleteAtEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty!");
        exit(1);
    }

    struct node *ptr = *head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    if (ptr->prev == NULL)
    {
        free(ptr);
        *head = NULL;
        return;
    }

    ptr->prev->next = NULL;
    free(ptr);
    ptr = NULL;
}

void deleteAtBeg(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty!");
        exit(1);
    }

    struct node *ptr = *head;
    *head = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = NULL;

    free(ptr);
    ptr = NULL;
}

void traverse(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty!");
        exit(1);
    }

    printf("\nList: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
