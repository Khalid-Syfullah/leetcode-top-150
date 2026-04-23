#include <stdbool.h>
#include <stdio.h>

static void backtrack(int n, int row, bool *cols, bool *diag1, bool *diag2, int *count) {
    if (row == n) {
        ++(*count);
        return;
    }
    for (int col = 0; col < n; ++col) {
        int d1 = row - col + n;
        int d2 = row + col;
        if (cols[col] || diag1[d1] || diag2[d2]) continue;
        cols[col] = diag1[d1] = diag2[d2] = true;
        backtrack(n, row + 1, cols, diag1, diag2, count);
        cols[col] = diag1[d1] = diag2[d2] = false;
    }
}

int totalNQueens(int n) {
    bool cols[16] = {false}, diag1[32] = {false}, diag2[32] = {false};
    int count = 0;
    backtrack(n, 0, cols, diag1, diag2, &count);
    return count;
}

int main(void) {
    printf("%d\n", totalNQueens(4));
    return 0;
}
