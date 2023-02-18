/* Calculate height and find leaf nodes in a binary.
Check if a binary tree is a Binary Search Tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

int checkBST(struct node *, int, int);
int findHeight(struct node *);
int countLeafNodes(struct node *);
int findMax(int, int);

struct node *insertLeft(struct node **, int);
struct node *createNode(char);
struct node *insertRight(struct node **, int);

int main()
{
    struct node *root = createNode(10);

    struct node *five = insertLeft(&root, 5);
    struct node *fifteen = insertRight(&root, 15);

    struct node *four = insertLeft(&five, 3);
    struct node *six = insertRight(&five, 7);

    struct node *thirteen = insertLeft(&fifteen, 13);
    struct node *seventeen = insertRight(&fifteen, 17);

    int height = findHeight(root);
    printf("\nHeight of Binary Tree: %d", height);

    int leafNodes = countLeafNodes(root);
    printf("\nCount of leaf nodes in Binary Tree: %d", leafNodes);

    int isBST = checkBST(root, INT_MIN, INT_MAX);
    if (isBST)
        printf("\nGiven Binary Tree is a BST!");
    else
        printf("\nGiven Binary Tree isn't a BST!");

    return 0;
}

int checkBST(struct node *ptr, int lowerLimit, int upperLimit)
{
    int data = ptr->data;
    printf("\nchecking for %d, min: %d & max: %d", data, lowerLimit, upperLimit);
    if (data < lowerLimit || data > upperLimit)
        return 0;

    if (ptr->left == NULL && ptr->right == NULL)
        return 1;

    else
    {
        if (ptr->left != NULL)
            if (!checkBST(ptr->left, lowerLimit, data))
                return 0;

        if (ptr->right != NULL)
            if (!checkBST(ptr->right, data, upperLimit))
                return 0;
        
        return 1;
    }
}

int countLeafNodes(struct node *ptr)
{
    if (ptr->left == NULL && ptr->right == NULL)
    {
        printf("\nLeaf Node: %d", ptr->data);
        return 1;
    }
    else if (ptr->left == NULL)
        return countLeafNodes(ptr->right);
    else if (ptr->right == NULL)
        return countLeafNodes(ptr->left);
    else
        return countLeafNodes(ptr->left) + countLeafNodes(ptr->right);
}

int findHeight(struct node *ptr)
{
    if (ptr == NULL)
        return -1;

    int leftSubTreeHeight = findHeight(ptr->left);
    int rightSubTreeHeight = findHeight(ptr->right);

    return findMax(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

int findMax(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    return num2;
}

struct node *createNode(char data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insertLeft(struct node **root, int data)
{
    struct node *leftNode = createNode(data);
    (*root)->left = leftNode;
    return leftNode;
}

struct node *insertRight(struct node **root, int data)
{
    struct node *rightNode = createNode(data);
    (*root)->right = rightNode;
    return rightNode;
}
