#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void deleteBeginning(struct node **);
void deleteEnd(struct node **);
void deleteAtPos(struct node **, int);

void insertAtEnd(struct node **, int);
void traverseList(struct node *);

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("List before deletion: ");
    traverseList(head);

    deleteBeginning(&head);
    printf("\nList after deleting first node: ");
    traverseList(head);

    deleteEnd(&head);
    printf("\nList after deleting last node: ");
    traverseList(head);

    return 0;
}

void deleteBeginning(struct node **head)
{

    if (*head == NULL)
    {
        printf("\nNo node to delete. UNDERFLOW!");
    }

    else
    {
        struct node *ptr = *head;
        *head = ptr->next;
        free(ptr);
        ptr = NULL;
    }
}

void deleteEnd(struct node **head)
{

    // no node
    if (*head == NULL)
    {
        printf("\nNo node to delete. UNDERFLOW!");
    }

    // just one node
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }

    else
    {
        struct node *ptr = *head;

        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }

        free(ptr->next);
        ptr->next = NULL;
    }
}

void deleteAtPos(struct node **head, int pos) {

    if (*head == NULL) {
        printf("\nNo Node to delete. UNDERFLOW");
    }

    else if ((*head)->next == NULL && pos == 1) {
        free(*head);
        *head = NULL;
    }

    else {

        struct node *ptr = *head;
        int count = 0;

        // remaining

    }

}

void traverseList(struct node *ptr)
{

    if (ptr == NULL)
    {
        printf("Empty list");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
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
    }

    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
