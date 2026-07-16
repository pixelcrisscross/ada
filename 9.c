#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, min_idx, temp;
    clock_t start, end;
    
    printf("Enter n (e.g., 5000, 10000): ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) arr[i] = rand() % 10000;

    start = clock();
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
    end = clock();

    printf("Time taken to sort %d elements: %f seconds\n", n, (double)(end - start) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}
