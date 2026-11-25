#include <stdio.h>

int n, cost[10][10], visited[10];
int min_cost = 9999;

void tsp(int city, int count, int current_cost) {
    if (count == n && cost[city][0] > 0) {
        if (current_cost + cost[city][0] < min_cost) {
            min_cost = current_cost + cost[city][0];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, current_cost + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        visited[i] = 0;
    }

    visited[0] = 1;
    tsp(0, 1, 0);

    printf("Minimum travelling cost = %d\n", min_cost);

    return 0;
}