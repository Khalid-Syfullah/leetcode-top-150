#include <stdio.h>

void rotate(int matrix[3][3], int n) {
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer, last = n - 1 - layer;
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}

int main(void) {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix, 3);
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) printf("%d ", matrix[r][c]);
        puts("");
    }
    return 0;
}
