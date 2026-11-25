// Implementation of Depth First Search (DFS)

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        // Undirected graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}