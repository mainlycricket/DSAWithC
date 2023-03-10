#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **, int);
void insertAtEnd(struct node **, int);
void insertAtPos(struct node **, int, int);

void deleteAtBeginning(struct node **);
void deleteAtEnd(struct node **);
void deleteNodeByData(struct node **, int);

void reverseList(struct node **);
void reversePrint(struct node *);
void traverseList(struct node *);

int main()
{
    struct node *head = NULL;

    insertAtEnd(&head, 50);       // 50
    insertAtBeginning(&head, 10); // 10, 50

    insertAtEnd(&head, 30);       // 10, 50, 30
    insertAtBeginning(&head, 20); // 20, 10, 50, 30

    insertAtPos(&head, 55, 2); // 20, 55, 10, 50, 30
    insertAtPos(&head, 44, 1); // 44, 20, 55, 10, 50, 30

    printf("\nTravering List: ");
    traverseList(head);

    printf("\nReverse Travering List: ");
    reversePrint(head);

    deleteAtBeginning(&head); // 20, 10, 55, 50, 30
    printf("\nList after deleting first node: ");
    traverseList(head);

    deleteAtEnd(&head); // 20, 10, 55, 50
    printf("\nList after deleting last node: ");
    traverseList(head);

    deleteNodeByData(&head, 55); // 20, 10, 50
    printf("\nList after deleting node with value 55: ");
    traverseList(head);

    reverseList(&head);
    printf("\nReversed List: ");
    traverseList(head);

    return 0;
}

void insertAtBeginning(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertAtEnd(struct node **head, int data)
{
    struct node *ptr = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
}

void insertAtPos(struct node **head, int data, int pos)
{
    if (pos <= 0)
    {
        printf("\nInvalid position!");
        exit(1);
    }

    if (pos == 1)
    {
        insertAtBeginning(&(*head), data);
        return;
    }

    struct node *ptr = *head;
    int count = 0;

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
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteAtBeginning(struct node **head)
{
    if (*head == NULL)
        printf("\nNo node to delete. UNDERFLOW!");

    else
    {
        struct node *ptr = *head;
        *head = ptr->next;
        free(ptr);
        ptr = NULL;
    }
}

void deleteAtEnd(struct node **head)
{
    if (*head == NULL) // no node
        printf("\nNo node to delete. UNDERFLOW!");

    else if ((*head)->next == NULL) // just one node
    {
        free(*head);
        *head = NULL;
    }

    else
    {
        struct node *ptr = *head;

        while (ptr->next->next != NULL)
            ptr = ptr->next;

        free(ptr->next);
        ptr->next = NULL;
    }
}

void deleteNodeByData(struct node **head, int data)
{
    if (*head == NULL)
    {
        printf("\nList is empty. UNDERFLOW!");
        exit(1);
    }

    if ((*head)->data == data)
    {
        deleteAtBeginning(&(*head));
        return;
    }

    struct node *ptr = *head;

    while (ptr->next != NULL && ptr->next->data != data)
        ptr = ptr->next;

    if (ptr->next == NULL)
    {
        printf("\nNo node found with %d value", data);
        exit(1);
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    temp = NULL;
}

void reverseList(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void reversePrint(struct node *ptr)
{
    if (ptr == NULL)
        return;
    reversePrint(ptr->next);
    printf("%d ", ptr->data);
}

void traverseList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}