#include <stdio.h>

int main() {
    int n, cost[10][10], visited[10] = {0}, i, j, a, b, min, mincost = 0, ne = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            scanf("%d", &cost[i][j]);

    visited[1] = 1;
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) { min = cost[i][j]; a = i; b = j; }
                }
            }
        }
        printf("Edge %d: (%d, %d) cost: %d\n", ne++, a, b, min);
        mincost += min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost: %d\n", mincost);
    return 0;
}
