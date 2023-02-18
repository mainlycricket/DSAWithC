#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    struct graph *graph1 = createGraph();

    addVertex(graph1, 'A');
    addVertex(graph1, 'B');
    addVertex(graph1, 'C');
    addVertex(graph1, 'D');

    addEdge(graph1, 'A', 'B');
    addEdge(graph1, 'A', 'C');
    addEdge(graph1, 'A', 'D');

    addEdge(graph1, 'B', 'C');
    addEdge(graph1, 'B', 'D');

    addEdge(graph1, 'C', 'D');

    printAdjacencyMatrix(graph1);
    listConnectedNodes(graph1, 'A');

    if (areNodesConnected(graph1, 'B', 'A'))
        printf("\n'B' & 'A' are connected!");
    else
        printf("\n'B' & 'A' aren't connected!");

    return 0;
}

struct graph *createGraph()
{
    struct graph *newGraph = (struct graph *)malloc(sizeof(graph));
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
