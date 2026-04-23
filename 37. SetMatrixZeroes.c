#include <stdbool.h>
#include <stdio.h>

void setZeroes(int matrix[3][3], int rows, int cols) {
    bool firstRow = false, firstCol = false;
    for (int c = 0; c < cols; ++c) if (matrix[0][c] == 0) firstRow = true;
    for (int r = 0; r < rows; ++r) if (matrix[r][0] == 0) firstCol = true;
    for (int r = 1; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
            if (matrix[r][c] == 0) matrix[r][0] = matrix[0][c] = 0;
        }
    }
    for (int r = 1; r < rows; ++r) {
        for (int c = 1; c < cols; ++c) {
            if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
        }
    }
    if (firstRow) for (int c = 0; c < cols; ++c) matrix[0][c] = 0;
    if (firstCol) for (int r = 0; r < rows; ++r) matrix[r][0] = 0;
}

int main(void) {
    int matrix[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix, 3, 3);
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) printf("%d ", matrix[r][c]);
        puts("");
    }
    return 0;
}
