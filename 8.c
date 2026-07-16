#include <stdio.h>

int s[10], x[10], d, n, found = 0;

void sumOfSub(int s_sum, int k, int r) {
    x[k] = 1;
    if (s_sum + s[k] == d) {
        printf("Subset: ");
        for (int i = 1; i <= k; i++) if (x[i]) printf("%d ", s[i]);
        printf("\n");
        found = 1;
    } else if (s_sum + s[k] + s[k + 1] <= d) {
        sumOfSub(s_sum + s[k], k + 1, r - s[k]);
    }
    if ((s_sum + r - s[k] >= d) && (s_sum + s[k + 1] <= d)) {
        x[k] = 0;
        sumOfSub(s_sum, k + 1, r - s[k]);
    }
}

int main() {
    int sum = 0, i;
    printf("Enter n and desired sum d: ");
    scanf("%d %d", &n, &d);
    printf("Enter %d elements in ascending order: ", n);
    for (i = 1; i <= n; i++) { scanf("%d", &s[i]); sum += s[i]; }
    
    if (sum < d || s[1] > d) printf("No subset possible\n");
    else sumOfSub(0, 1, sum);
    
    if (!found) printf("No subset found\n");
    return 0;
}
