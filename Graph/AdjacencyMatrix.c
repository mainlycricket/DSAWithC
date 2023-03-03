#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct graph
{
    char vertices[MAX];
    int verticesCount;
    int matrix[MAX][MAX];
};

struct graph *createGraph();
void addVertex(struct graph *, char);
void addEdge(struct graph *, char, char);
void printAdjacencyMatrix(struct graph *);

void listConnectedNodes(struct graph *, char);
int areNodesConnected(struct graph *, char, char);

int getVertexIndex(struct graph *, char);
void listVertices(struct graph *);

void DFS(struct graph *, char);
void BFS(struct graph *, char);

int main()
{
    struct graph *graph1 = createGraph();

    addVertex(graph1, 'A');
    addVertex(graph1, 'B');
    addVertex(graph1, 'C');
    addVertex(graph1, 'D');
    addVertex(graph1, 'E');

    addEdge(graph1, 'A', 'B');
    addEdge(graph1, 'A', 'C');
    addEdge(graph1, 'A', 'D');

    addEdge(graph1, 'B', 'C');
    addEdge(graph1, 'B', 'D');

    addEdge(graph1, 'C', 'D');
    addEdge(graph1, 'D', 'E');

    printAdjacencyMatrix(graph1);
    listConnectedNodes(graph1, 'A');

    if (areNodesConnected(graph1, 'B', 'A'))
        printf("\n'B' & 'A' are connected!");
    else
        printf("\n'B' & 'A' aren't connected!");

    DFS(graph1, 'A');
    BFS(graph1, 'A');

    return 0;
}

struct graph *createGraph()
{
    struct graph *newGraph = (struct graph *)malloc(sizeof(struct graph));
    newGraph->verticesCount = 0;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            newGraph->matrix[i][j] = 0;

    return newGraph;
}

void addVertex(struct graph *ptr, char data)
{
    ptr->vertices[ptr->verticesCount] = data;
    ptr->verticesCount++;
}

void addEdge(struct graph *ptr, char source, char destination)
{
    int sourceIndex = getVertexIndex(ptr, source);
    int destinationIndex = getVertexIndex(ptr, destination);

    if (sourceIndex == -1 || destinationIndex == -1)
    {
        printf("\nInvalid vertices!");
        exit(1);
    }

    ptr->matrix[sourceIndex][destinationIndex] = 1;
    ptr->matrix[destinationIndex][sourceIndex] = 1;
}

void printAdjacencyMatrix(struct graph *ptr)
{
    int verticesCount = ptr->verticesCount;

    printf("\nAdjacency Matrix:\n  ");
    listVertices(ptr);

    for (int i = 0; i < verticesCount; i++)
    {
        printf("\n%c ", ptr->vertices[i]);
        for (int j = 0; j < verticesCount; j++)
            printf("%d ", ptr->matrix[i][j]);
    }
}

void listConnectedNodes(struct graph *ptr, char data)
{
    int nodeIndex = getVertexIndex(ptr, data);

    if (nodeIndex == -1)
    {
        printf("\nVertex %c doesn't exist!", data);
        exit(1);
    }

    printf("\nNodes connected with %c: ", data);

    for (int i = 0; i < ptr->verticesCount; i++)
    {
        if (ptr->matrix[nodeIndex][i] == 1)
            printf("%c ", ptr->vertices[i]);
    }
}

int areNodesConnected(struct graph *ptr, char source, char destination)
{
    int sourceIndex = getVertexIndex(ptr, source);
    int destinationIndex = getVertexIndex(ptr, destination);

    if (sourceIndex == -1 || destinationIndex == -1)
    {
        printf("\nInvalid vertices!");
        exit(1);
    }

    if (ptr->matrix[sourceIndex][destinationIndex] == 1)
        return 1;

    return 0;
}

int getVertexIndex(struct graph *ptr, char data)
{
    for (int i = 0; i < ptr->verticesCount; i++)
        if (ptr->vertices[i] == data)
            return i;
    return -1;
}

void listVertices(struct graph *ptr)
{
    for (int i = 0; i < ptr->verticesCount; i++)
        printf("%c ", ptr->vertices[i]);
}

void DFS(struct graph *ptr, char start)
{
    printf("\nDFS: ");

    char visited[ptr->verticesCount], stack[ptr->verticesCount];
    int top = -1, vCount = -1;

    stack[++top] = start;

    while (top != -1)
    {
        char curNode = stack[top];
        int curIndex = getVertexIndex(ptr, curNode);
        top--;
        visited[++vCount] = curNode;
        printf("%c ", curNode);

        for (int i = 0; i < ptr->verticesCount; i++)
            if (ptr->matrix[curIndex][i] == 1 
                && !strpbrk(visited, &ptr->vertices[i])
                && !strpbrk(top, &ptr->vertices[i]))
                stack[++top] = ptr->vertices[i];
    }
}

void BFS(struct graph *ptr, char start)
{
    printf("\nBFS: ");

    char visited[ptr->verticesCount], queue[ptr->verticesCount];
    int front = -1, rear = -1, vCount = -1;

    queue[++rear] = start;
    visited[++vCount] = start;
    ++front;

    while (front <= rear)
    {
        char curNode = queue[front];
        int curIndex = getVertexIndex(ptr, curNode);

        for (int i = 0; i < ptr->verticesCount; i++)
            if (ptr->matrix[curIndex][i] == 1 && !strpbrk(visited, &(ptr->vertices[i])))
            {
                queue[++rear] = ptr->vertices[i];
                visited[++vCount] = ptr->vertices[i];
            }
        ++front;
    }

    for (int i = 0; i <= vCount; i++)
        printf("%c ", visited[i]);
}
