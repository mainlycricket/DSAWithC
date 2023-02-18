#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *createNode(char);
struct node *insertLeft(struct node **, char);
struct node *insertRight(struct node **, char);

void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
void levelOrder(struct node *);

char queue[10];
int upperBound = -1;

int main()
{
    struct node *m = createNode('M');

    struct node *x = insertLeft(&m, 'X');
    struct node *z = insertRight(&m, 'Z');

    struct node *a = insertLeft(&x, 'A');
    struct node *d = insertRight(&x, 'D');

    struct node *g = insertLeft(&z, 'G');
    struct node *t = insertRight(&z, 'T');

    printf("\nPre-Order Traversal: ");
    preOrder(m);

    printf("\nIn-Order Traversal: ");
    inOrder(m);

    printf("\nPost-Order Traversal: ");
    postOrder(m);

    printf("\nLevel-Order Traversal: ");
    levelOrder(m);

    return 0;
}

struct node *createNode(char data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insertLeft(struct node **root, char data)
{
    struct node *leftNode = createNode(data);
    (*root)->left = leftNode;
    return leftNode;
}

struct node *insertRight(struct node **root, char data)
{
    struct node *rightNode = createNode(data);
    (*root)->right = rightNode;
    return rightNode;
}

void preOrder(struct node *root)
{
    printf("%c ", root->data);

    if (root->left != NULL)
        preOrder(root->left);

    if (root->right != NULL)
        preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root->left != NULL)
        inOrder(root->left);

    printf("%c ", root->data);

    if (root->right != NULL)
        inOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root->left != NULL)
        postOrder(root->left);

    if (root->right != NULL)
        postOrder(root->right);

    printf("%c ", root->data);
}

void levelOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;

    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = ptr;
    ++front;

    while (front <= rear)
    {
        struct node *current = queue[front];
        ++front;

        printf("%c ", current->data);

        if (current->left != NULL)
            queue[++rear] = current->left;

        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}
