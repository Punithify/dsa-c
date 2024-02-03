#include <stdio.h>
#include <stdlib.h>

struct Graph
{
    int V;
    int E;
    int **Adj;
};

int n, v;
int f = -1;
int r = -1;
int visited[20];
int q[20];
struct Graph *adjMatrixGraph()
{
    int u, v, i;
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    if (!G)
    {
        printf("memory error\n");
        return;
    }
    printf("No of nodes and edges\n");
    scanf("%d %d", &G->V, &G->E);
    n = G->V;
    G->Adj = malloc(sizeof(int) * (G->V * G->V));
    for (u = 0; u < G->V; u++)
    {
        G->Adj[u] = (int *)malloc(sizeof(int) * G->V);
        for (v = 0; v < G->V; v++)
        {
            G->Adj[u][v] = 0;
        }
    }
    printf("Enter numbers in a pair that connects a Graph");

    for (i = 0; i < G->E; i++)
    {
        scanf("%d %d", &u, &v);
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    return G;
}

// void display(struct Graph *G)
// {
//     for (int i = 0; i < G->V; i++)
//     {
//         for (int j = 0; j < G->V; j++)
//         {
//             printf("%d", G->Adj[i][j]);
//         }
//         printf("\n");
//     }
// }

void BFS(struct Graph *G, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (G->Adj[v][i] != 0 && visited[i] == 0)
        {
            r = r + 1;
            q[r] = i;
            visited[i] = 1;
            printf("%d\t", i);
        }
    }
    f = f + 1;
    if (f <= r)
        BFS(G, q[f]);
}

void DFS(struct Graph *G, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (G->Adj[v][i] != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            printf("%d\t", i);
            DFS(G, i);
        }
    }
}

int main()
{
    struct Graph *G = adjMatrixGraph();
    // display(G);
    for (int i = 0; i < n; i++) // mark all the vertices as not visited
    {
        visited[i] = 0;
    }
    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    f = r = 0;
    q[r] = v;
    printf("\n BFS traversal is:\n");
    visited[v] = 1; // mark the starting vertex as visited
    printf("%d", v);

    BFS(G, v);
    if (r != n - 1)
        printf("\n BFS is not possible");
    for (int i = 0; i < n; i++) // mark all the vertices as not visited
    {
        visited[i] = 0;
    }
    printf("\n Enter the starting vertex for DFS:");
    scanf("%d", &v);
    visited[v] = 1;
    printf("%d", v);

    DFS(G, v);
    // display(G);
    return 0;
}