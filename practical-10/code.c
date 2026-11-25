#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int v) {
    if (parent[v] != v)
        parent[v] = find(parent, parent[v]);

    return parent[v];
}

int unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU == rootV)
        return 0;

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }

    return 1;
}

int compareEdges(const void *a, const void *b) {
    const struct Edge *e1 = a;
    const struct Edge *e2 = b;

    if (e1->weight < e2->weight)
        return -1;
    if (e1->weight > e2->weight)
        return 1;

    return 0;
}

int main() {
    struct Edge edges[E] = {
        {1, 2, 1},
        {1, 3, 2},
        {2, 4, 3},
        {3, 4, 4},
        {2, 3, 5}
    };

    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int edgeCount = 0;
    int totalWeight = 0;

    printf("Edges in Minimum Spanning Tree:\n");


    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].src - 1;
        int v = edges[i].dest - 1;

        if (unionSets(parent, rank, u, v)) {
            printf("%d -- %d  Weight: %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            totalWeight += edges[i].weight;
            edgeCount++;
        }
    }
    printf("Total Weight of Minimum Spanning Tree: %d\n", totalWeight);
    return 0;
}