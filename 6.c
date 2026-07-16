#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m, w[20], v[20], K[20][20], i, j;
    printf("Enter number of items and knapsack capacity: ");
    scanf("%d %d", &n, &m);
    printf("Enter weights and values of items:\n");
    for (i = 1; i <= n; i++) scanf("%d %d", &w[i], &v[i]);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) K[i][j] = 0;
            else if (w[i] <= j) K[i][j] = MAX(v[i] + K[i - 1][j - w[i]], K[i - 1][j]);
            else K[i][j] = K[i - 1][j];
        }
    }
    printf("Maximum value: %d\n", K[n][m]);
    return 0;
}
