#include <stdio.h>

int parent[10];
int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}
int uni(int i, int j) {
    if (i != j) { parent[j] = i; return 1; }
    return 0;
}

int main() {
    int n, cost[10][10], mincost = 0, i, j, a, b, u, v, ne = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            scanf("%d", &cost[i][j]);

    while (ne < n) {
        int min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) { min = cost[i][j]; a = u = i; b = v = j; }
            }
        }
        u = find(u); v = find(v);
        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) cost: %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost: %d\n", mincost);
    return 0;
}
