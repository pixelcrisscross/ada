#include <stdio.h>

int main() {
    int n, m, i, j;
    float w[20], v[20], ratio[20], temp, total_val = 0.0;
    
    printf("Enter items count and capacity: ");
    scanf("%d %d", &n, &m);
    printf("Enter weight and value for each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &w[i], &v[i]);
        ratio[i] = v[i] / w[i];
    }

    // Sort by ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
            }
        }
    }

    int rem = m;
    for (i = 0; i < n; i++) {
        if (w[i] <= rem) { total_val += v[i]; rem -= w[i]; }
        else { total_val += v[i] * ((float)rem / w[i]); break; }
    }
    printf("Maximum profit: %.2f\n", total_val);
    return 0;
}
