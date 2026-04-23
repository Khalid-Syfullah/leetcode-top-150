#include <stdio.h>

void spiralOrder(int matrix[3][4], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; ++c) printf("%d ", matrix[top][c]);
        ++top;
        for (int r = top; r <= bottom; ++r) printf("%d ", matrix[r][right]);
        --right;
        if (top <= bottom) {
            for (int c = right; c >= left; --c) printf("%d ", matrix[bottom][c]);
            --bottom;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; --r) printf("%d ", matrix[r][left]);
            ++left;
        }
    }
    puts("");
}

int main(void) {
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    spiralOrder(matrix, 3, 4);
    return 0;
}
