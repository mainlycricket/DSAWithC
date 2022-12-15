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
void traverseList(struct node *);

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;

    insertAtEnd(&head, 50);
    insertAtBeginning(&head, 10);

    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 20);

    insertAtPos(&head, 55, 2);
    insertAtPos(&head, 44, 0);

    printf("Travering List: ");
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

void insertAtPos(struct node **head, int data, int pos)
{

    if (*head == NULL || pos == 0)
    {
        insertAtBeginning(&(*head), data);
    }

    else
    {

        struct node *ptr = *head;
        int count = 0;

        while (count < pos - 2)
        {

            if (ptr == NULL)
            {
                printf("\nNot enough nodes!");
                return;
            }

            ptr = ptr->next;
            ++count;
        }

        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void traverseList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}