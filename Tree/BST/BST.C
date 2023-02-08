#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int);
void insert(struct node **, int);
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
struct node *deleteNode(struct node **, int);
struct node *findMin(struct node *);

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 1);

    deleteNode(&root, 10);

    printf("\nPre-order: ");
    preOrder(root);

    printf("\nIn-order: ");
    inOrder(root);

    printf("\nPost-order: ");
    postOrder(root);

    return 0;
}

void insert(struct node **root, int data)
{
    if (*root == NULL)
        *root = createNode(data);

    else if ((*root)->data > data)
        insert(&(*root)->left, data);

    else if ((*root)->data < data)
        insert(&(*root)->right, data);
}

struct node *deleteNode(struct node **root, int data)
{
    if (*root == NULL)
        return *root;

    if ((*root)->data < data)
        (*root)->right = deleteNode(&(*root)->right, data);

    else if ((*root)->data > data)
        (*root)->left = deleteNode(&(*root)->left, data);

    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }

        else if ((*root)->left == NULL)
        {
            struct node *temp = *root;
            *root = temp->right;
            free(temp);
            temp = NULL;
        }

        else if ((*root)->right == NULL)
        {
            struct node *temp = *root;
            *root = temp->left;
            free(temp);
            temp = NULL;
        }

        else
        {
            struct node *temp = findMin((*root)->right);
            (*root)->data = temp->data;
            (*root)->right = deleteNode(&(*root)->right, temp->data);
        }
    }

    return *root;
}

struct node *findMin(struct node *ptr)
{
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void preOrder(struct node *ptr)
{
    printf("%d ", ptr->data);

    if (ptr->left != NULL)
        preOrder(ptr->left);

    if (ptr->right != NULL)
        preOrder(ptr->right);
}

void inOrder(struct node *ptr)
{
    if (ptr->left != NULL)
        inOrder(ptr->left);

    printf("%d ", ptr->data);

    if (ptr->right != NULL)
        inOrder(ptr->right);
}

void postOrder(struct node *ptr)
{
    if (ptr->left != NULL)
        postOrder(ptr->left);

    if (ptr->right != NULL)
        postOrder(ptr->right);

    printf("%d ", ptr->data);
}