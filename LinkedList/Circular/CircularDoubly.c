#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtEnd(struct node **, int);
void traverse(struct node *);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    traverse(head);

    return 0;
}

void insertAtEnd(struct node **head, int data)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        temp->prev = NULL;
        return;
    }

    struct node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}

void traverse(struct node *ptr)
{

    if (ptr == NULL)
    {
        printf("\nLinked List is empty. UNDERFLOW!");
        exit(1);
    }

    printf("\nCircular Linked List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
