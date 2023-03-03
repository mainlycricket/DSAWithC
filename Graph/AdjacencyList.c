#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct node
{
    char vertex;
    struct node *next;
};

struct graph
{
    struct node *vertices[MAX];
    int verticesCount;
};

struct graph *createGraph();
void addVertex(struct graph *, char);
void addEdge(struct graph *, char, char);
void listVertices(struct graph *);
void listEdges(struct graph *, char);
struct node *locateNode(struct graph *, char);

void DFS(struct graph *, char);
int findChar (char [], int, char);

int main()
{
    struct graph *graph1 = createGraph();

    addVertex(graph1, 'A');
    addVertex(graph1, 'B');
    addVertex(graph1, 'C');
    addVertex(graph1, 'D');

    listVertices(graph1);
    addEdge(graph1, 'A', 'B');
    addEdge(graph1, 'A', 'C');
    addEdge(graph1, 'B', 'C');
    addEdge(graph1, 'B', 'D');
    addEdge(graph1, 'C', 'D');

    listEdges(graph1, 'A');
    listEdges(graph1, 'B');
    listEdges(graph1, 'C');

    DFS(graph1, 'A');
    return 0;
}

void addVertex(struct graph *ptr, char vertex)
{
    ptr->vertices[ptr->verticesCount] = (struct node *)malloc(sizeof(struct node));
    ptr->vertices[ptr->verticesCount]->vertex = vertex;
    ptr->vertices[ptr->verticesCount]->next = NULL;
    ptr->verticesCount++;
}

void addEdge(struct graph *ptr, char source, char destination)
{
    struct node *sourcePtr = locateNode(ptr, source);
    struct node *destinationPtr = locateNode(ptr, destination);

    if (sourcePtr == NULL || destinationPtr == NULL)
    {
        printf("\nInvalid vertices!");
        exit(1);
    }

    while (sourcePtr->next != NULL)
        sourcePtr = sourcePtr->next;

    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    tempNode->vertex = destination;
    tempNode->next = NULL;
    sourcePtr->next = tempNode;

    while (destinationPtr->next != NULL)
        destinationPtr = destinationPtr->next;

    struct node *tempNode2 = (struct node *)malloc(sizeof(struct node));
    tempNode2->vertex = source;
    tempNode2->next = NULL;
    destinationPtr->next = tempNode2;
}

void listVertices(struct graph *ptr)
{
    printf("\nVertices: ");
    for (int i = 0; i < ptr->verticesCount; i++)
        printf("%c ", ptr->vertices[i]->vertex);
}

void listEdges(struct graph *ptr, char vertex)
{
    struct node *vertexPtr = locateNode(ptr, vertex);
    vertexPtr = vertexPtr->next;

    printf("\nConnected Vertices of %c: ", vertex);

    while (vertexPtr != NULL)
    {
        printf("%c ", vertexPtr->vertex);
        vertexPtr = vertexPtr->next;
    }
}

struct graph *createGraph()
{
    struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
    newGraph->verticesCount = 0;
    return newGraph;
}

struct node *locateNode(struct graph *ptr, char vertex)
{
    for (int i = 0; i < ptr->verticesCount; i++)
    {
        if (ptr->vertices[i]->vertex == vertex)
            return ptr->vertices[i];
    }
    return NULL;
}

void DFS(struct graph *ptr, char start) {

    char stack[MAX]; char visited[ptr->verticesCount];
    int top = -1, vCount = -1;

    stack[++top] = start;

    printf("\nDFS: ");
    while (top != -1) {
        char curNode = stack[top];
        top--;
        printf("%c ", curNode);
        visited[++vCount] = curNode;
        struct node *nodePtr = locateNode(ptr, curNode);
        nodePtr = nodePtr->next;
        while (nodePtr != NULL) {
            if (!findChar(visited, vCount - 1, nodePtr->vertex) && !findChar(stack, top, nodePtr->vertex)) {
                stack[++top] = nodePtr->vertex;
            }    
            nodePtr = nodePtr->next;    
        }        
    }

}

int findChar (char arr[], int vCount, char x) {
    for (int i = 0 ; i <= vCount; i++) {
        if (arr[i] == x) return 1;
    }
    return 0;
}
