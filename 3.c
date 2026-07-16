//3A
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, dist[10][10], i, j, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weight matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            scanf("%d", &dist[i][j]);

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);

    printf("Shortest path distance matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) printf("%d\t", dist[i][j]);
        printf("\n");
    }
    return 0;
}

// 3B
#include <stdio.h>

int main() {
    int n, tc[10][10], i, j, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) 
            scanf("%d", &tc[i][j]);

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);

    printf("Transitive Closure matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) printf("%d\t", tc[i][j]);
        printf("\n");
    }
    return 0;
}
