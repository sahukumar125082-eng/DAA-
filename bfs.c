// BFS CODE

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start)
{
    int queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];

        printf("%d ", vertex);

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
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
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d",start);
    printf("BFS traversal starting from vertex %d: ", start);
}