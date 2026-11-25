

#include <stdio.h>
int main() {
    int n, i, j, u, v, min;
    int cost[20][20], visited[20] = {0};
    int edges = 0, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    visited[0] = 1;

    printf("\nMST Edges:\n");
    while (edges < n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visited[j] == 0 && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);
        mincost = mincost + min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}