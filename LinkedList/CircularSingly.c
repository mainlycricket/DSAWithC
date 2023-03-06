#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void insertAtBeginning(struct node **, int);
void insertAtEnd(struct node **, int);

void deleteFromBeginning(struct node **);
void deleteFromEnd(struct node **);
void deleteNodeByData(struct node **, int);

int count(struct node *);
void traverse(struct node *);

int main()
{
	struct node *tail = NULL;

	insertAtEnd(&tail, 35);
	deleteFromBeginning(&tail);

	insertAtEnd(&tail, 40);
	insertAtEnd(&tail, 50);

	insertAtBeginning(&tail, 30);
	insertAtBeginning(&tail, 20);
	insertAtBeginning(&tail, 10);

	traverse(tail);

	deleteFromBeginning(&tail);
	deleteFromEnd(&tail);
	deleteNodeByData(&tail, 30);

	traverse(tail);

	return 0;
}

void insertAtBeginning(struct node **tail, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	if (*tail == NULL)
	{
		temp->link = temp;
		*tail = temp;
	}
	else
	{
		temp->link = (*tail)->link;
		(*tail)->link = temp;
	}
}

void insertAtEnd(struct node **tail, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;

	if (*tail == NULL)
	{
		*tail = temp;
		temp->link = temp;
	}

	temp->link = (*tail)->link;
	(*tail)->link = temp;
	*tail = temp;
}

void deleteFromBeginning(struct node **tail)
{
	if (*tail == NULL)
	{
		printf("\nLinked List is empty. UNDERFLOW!");
		exit(1);
	}

	struct node *head = (*tail)->link;

	// if only one node exists
	if (head == *tail)
	{
		free(*tail);
		*tail = NULL;
		return;
	}

	(*tail)->link = head->link;
	free(head);
	head = NULL;
}

void deleteFromEnd(struct node **tail)
{
	if (*tail == NULL)
	{
		printf("\nLinked List is empty. UNDERFLOW!");
		exit(1);
	}

	// if only one node exists
	if (*tail == (*tail)->link)
	{
		free(*tail);
		*tail = NULL;
		return;
	}

	struct node *ptr = (*tail)->link;

	while (ptr->link != *tail)
	{
		ptr = ptr->link;
	}

	ptr->link = (*tail)->link;
	free(*tail);
	*tail = ptr;
}

void deleteNodeByData(struct node **tail, int data)
{
	if (*tail == NULL)
	{
		printf("\nLinked List is empty. UNDERFLOW!");
		exit(1);
	}

	if ((*tail)->data == data)
		deleteFromEnd(&(*tail));

	else if ((*tail)->link->data == data)
		deleteFromBeginning(&(*tail));

	else
	{
		struct node *ptr = (*tail)->link;

		while (ptr->link != *tail && ptr->link->data != data)
			ptr = ptr->link; 

		if (ptr->link->data != data)
		{
			printf("\nNode not found!");
			exit(1);
		}

		struct node *temp = ptr->link;
		ptr->link = temp->link;
		free(temp);
		temp = NULL;
	}
}

void traverse(struct node *ptr)
{
	if (ptr == NULL)
	{
		printf("\nEmpty Linked List! UNDERFLOW!");
		exit(1);
	}

	struct node *head = ptr->link;
	ptr = ptr->link;
	printf("\nLinked List: ");
	do
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	} while (ptr != head);
}

int count(struct node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}

	int count = 0;
	struct node *head = ptr->link;
	ptr = ptr->link;
	do
	{
		++count;
		ptr = ptr->link;
	} while (ptr != head);

	return count;
}
