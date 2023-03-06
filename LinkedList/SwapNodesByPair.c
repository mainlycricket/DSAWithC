/*
LeetCode Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairsByLink(struct ListNode *head);
struct ListNode *swapPairsByVal(struct ListNode *head);

void insertAtEnd(struct ListNode **head, int data);
void traverse(struct ListNode *ptr);

int main()
{
    struct ListNode *head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("\nInitial List: ");
    traverse(head);

    head = swapPairsByLink(head);
    printf("\nSwapped by Link: ");
    traverse(head);

    head = swapPairsByVal(head);
    printf("\nRe-swapped by values: ");
    traverse(head);

}

struct ListNode *swapPairsByLink(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *temp = head->next;
    head->next = temp->next;
    temp->next = head;
    head = temp;

    if (head->next->next != NULL)
        head->next->next = swapPairsByLink(head->next->next);

    return head;
}

struct ListNode *swapPairsByVal(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int temp = head->val;
    head->val = head->next->val;
    head->next->val = temp;

    if (head->next->next != NULL)
        swapPairsByVal(head->next->next);

    return head;
}

void insertAtEnd(struct ListNode **head, int data)
{
    struct ListNode *ptr = *head;
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = data;
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

void traverse(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
}
