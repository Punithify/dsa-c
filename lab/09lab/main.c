#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_EDGES 20

int adj[MAX_VERTICES][MAX_VERTICES], n, m, q[MAX_VERTICES], visited[MAX_VERTICES], f = -1, r = -1;

struct edge
{
    int s, d;
};

struct edge e[MAX_EDGES];

void createadjmatrix(struct edge e[])
{
    int i, x, j, y;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++)
    {
        x = e[i].s;
        y = e[i].d;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void bfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] != 0 && visited[i] == 0)
        {
            r = r + 1;
            q[r] = i;
            visited[i] = 1;
            printf("%d  ", i);
        }
    }
    f = f + 1;
    if (f <= r)
        bfs(q[f]);
}

void dfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            printf("%d  ", i);
            dfs(i);
        }
    }
}

int main()
{
    int v, i;
    char ch = 'y';
    m = 0;
    printf("Enter no of vertices: ");
    scanf("%d", &n);

    while (ch == 'y' && m < MAX_EDGES)
    {
        printf("Enter source of edge: ");
        scanf("%d", &e[m].s);
        printf("Enter destination of edge: ");
        scanf("%d", &e[m].d);
        m++;
        printf("Do you want to add more edges? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
    }

    createadjmatrix(e);

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &v);
    f = r = 0;
    q[r] = v;
    printf("\nBFS traversal is:\n");
    visited[v] = 1;
    printf("%d   ", v);
    bfs(v);
    if (r != n - 1)
        printf("\nBFS is not possible");

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the starting vertex for DFS: ");
    scanf("%d", &v);
    printf("\nDFS traversal is:\n");
    visited[v] = 1;
    printf("%d   ", v);
    dfs(v);
    return 0;
}