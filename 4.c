#include <stdio.h>

int main() {
    int n, cost[10][10], dist[10], visited[10] = {0}, i, j, count, min, u, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            scanf("%d", &cost[i][j]);
            
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 1; i <= n; i++) dist[i] = cost[start][i];
    visited[start] = 1; dist[start] = 0;

    for (count = 1; count < n; count++) {
        min = 999;
        for (i = 1; i <= n; i++)
            if (!visited[i] && dist[i] < min) { min = dist[i]; u = i; }
            
        visited[u] = 1;
        for (i = 1; i <= n; i++)
            if (!visited[i] && dist[u] + cost[u][i] < dist[i])
                dist[i] = dist[u] + cost[u][i];
    }

    for (i = 1; i <= n; i++) if (i != start) printf("Distance to %d is %d\n", i, dist[i]);
    return 0;
}
