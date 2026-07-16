#include <stdio.h>

int main() {
    int n, adj[10][10], indegree[10] = {0}, visited[10] = {0}, i, j, count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j]) indegree[j]++;
        }
    }

    printf("Topological Sort: ");
    while (count < n) {
        for (i = 1; i <= n; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                for (j = 1; j <= n; j++) if (adj[i][j]) indegree[j]--;
                count++;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
