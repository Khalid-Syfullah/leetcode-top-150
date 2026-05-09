#include <stdbool.h>
#include <stdio.h>

void setZeroes(int *matrix, int rows, int cols) {
    bool firstRowZero = false, firstColZero = false;

    for (int c = 0; c < cols; c++)
        if (matrix[c] == 0) { firstRowZero = true; break; }

    for (int r = 0; r < rows; r++)
        if (matrix[r * cols] == 0) { firstColZero = true; break; }

    for (int r = 1; r < rows; r++)
        for (int c = 1; c < cols; c++)
            if (matrix[r * cols + c] == 0) {
                matrix[r * cols] = 0;
                matrix[c] = 0;
            }

    for (int r = 1; r < rows; r++)
        if (matrix[r * cols] == 0)
            for (int c = 1; c < cols; c++) matrix[r * cols + c] = 0;

    for (int c = 1; c < cols; c++)
        if (matrix[c] == 0)
            for (int r = 1; r < rows; r++) matrix[r * cols + c] = 0;

    if (firstRowZero)
        for (int c = 0; c < cols; c++) matrix[c] = 0;

    if (firstColZero)
        for (int r = 0; r < rows; r++) matrix[r * cols] = 0;
}

static void printMatrix(int *matrix, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        printf("[");
        for (int c = 0; c < cols; c++) {
            if (c) printf(", ");
            printf("%d", matrix[r * cols + c]);
        }
        printf("]\n");
    }
}

int main(void) {
    int m1[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    setZeroes(&m1[0][0], 3, 3);
    printMatrix(&m1[0][0], 3, 3);
    printf("\n");

    int m2[3][4] = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    setZeroes(&m2[0][0], 3, 4);
    printMatrix(&m2[0][0], 3, 4);

    return 0;
}
