#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
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
void traverse(struct node *);

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    insertAtBeginning(&head, 20); // 20
    deleteAtBeginning(&head);     // Empty List

    insertAtBeginning(&head, 10); // 10
    insertAtEnd(&head, 30);       // 10, 30

    deleteAtEnd(&head);     // 10
    insertAtEnd(&head, 40); // 10, 40

    insertAtPos(&head, 20, 2); // 10, 20, 40
    insertAtPos(&head, 30, 3); // 10, 20, 30, 40

    deleteNodeByData(&head, 30); // 10, 20, 40

    printf("\nList: ");
    traverse(head);

    reverseList(&head);
    printf("\nReversed List: ");
    traverse(head);

    return 0;
}

void insertAtBeginning(struct node **head, int data)
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
        insertAtBeginning(&(*head), data);
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

void deleteAtBeginning(struct node **head)
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

    while (ptr->next->data != data)
    {
        if (ptr->next == NULL)
        {
            printf("\nNo node found with value %d", data);
            exit(1);
        }

        ptr = ptr->next;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = ptr;
    }
    free(temp);
    temp = NULL;
}

void reverseList(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    *head = prev;
    (*head)->prev = NULL;

}

void traverse(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty!");
        exit(1);
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
