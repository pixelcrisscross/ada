#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = (low - 1), j;
        for (j = low; j < high; j++) {
            if (arr[j] < pivot) { i++; swap(&arr[i], &arr[j]); }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    clock_t start, end;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) arr[i] = rand() % 10000;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}
