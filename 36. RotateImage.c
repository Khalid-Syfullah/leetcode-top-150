#include <stdio.h>

/* Rotate n x n matrix 90 degrees clockwise in place:
   1. Transpose
   2. Reverse each row */
void rotate(int *matrix, int n) {
    /* Transpose */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = matrix[i * n + j];
            matrix[i * n + j] = matrix[j * n + i];
            matrix[j * n + i] = tmp;
        }
    }
    /* Reverse each row */
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int tmp = matrix[i * n + left];
            matrix[i * n + left] = matrix[i * n + right];
            matrix[i * n + right] = tmp;
            left++; right--;
        }
    }
}

static void printMatrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            if (j) printf(", ");
            printf("%d", matrix[i * n + j]);
        }
        printf("]\n");
    }
}

int main(void) {
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotate(&m1[0][0], 3);
    printMatrix(&m1[0][0], 3);
    printf("\n");

    int m2[4][4] = {
        { 5,  1,  9, 11},
        { 2,  4,  8, 10},
        {13,  3,  6,  7},
        {15, 14, 12, 16}
    };
    rotate(&m2[0][0], 4);
    printMatrix(&m2[0][0], 4);

    return 0;
}
