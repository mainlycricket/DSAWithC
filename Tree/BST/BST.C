#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};

struct tree *createNode(int);
void insert(struct tree **, int);
void preOrder(struct tree *);
void inOrder(struct tree *);
void postOrder(struct tree *);

int main()
{
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root = NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 1);

    printf("\nPre-order: ");
    preOrder(root);

    printf("\nIn-order: ");
    inOrder(root);

    printf("\nPost-order: ");
    postOrder(root);

    return 0;
}

void insert(struct tree **root, int data)
{
    if (*root == NULL)
        *root = createNode(data);

    else if ((*root)->data > data)
        insert(&(*root)->left, data);

    else
        insert(&(*root)->right, data);
}

struct tree *createNode(int data)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void preOrder(struct tree *ptr)
{
    printf("%d ", ptr->data);

    if (ptr->left != NULL)
        preOrder(ptr->left);

    if (ptr->right != NULL)
        preOrder(ptr->right);
}

void inOrder(struct tree *ptr)
{
    if (ptr->left != NULL)
        preOrder(ptr->left);

    printf("%d ", ptr->data);

    if (ptr->right != NULL)
        preOrder(ptr->right);
}

void postOrder(struct tree *ptr)
{
    if (ptr->left != NULL)
        preOrder(ptr->left);

    if (ptr->right != NULL)
        preOrder(ptr->right);

    printf("%d ", ptr->data);
}