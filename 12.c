#include <stdio.h>
#include <math.h>

int board[20], count = 0;

int place(int row, int col) {
    for (int i = 1; i <= row - 1; i++) {
        // Check for same column or same diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n) {
                printf("\nSolution %d:\n", ++count);
                for (int i = 1; i <= n; i++) printf("%d\t", board[i]);
            } else {
                queen(row + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    if(count == 0) printf("No solution.\n");
    return 0;
}
