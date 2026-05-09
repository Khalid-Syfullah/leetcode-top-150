#include <stdio.h>

/* Generic spiral order print for a rows x cols matrix stored as flat array */
void spiralOrder(int *matrix, int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int first = 1;
    printf("[");
    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; c++) {
            if (!first) printf(", "); else first = 0;
            printf("%d", matrix[top * cols + c]);
        }
        top++;
        for (int r = top; r <= bottom; r++) {
            if (!first) printf(", "); else first = 0;
            printf("%d", matrix[r * cols + right]);
        }
        right--;
        if (top <= bottom) {
            for (int c = right; c >= left; c--) {
                if (!first) printf(", "); else first = 0;
                printf("%d", matrix[bottom * cols + c]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; r--) {
                if (!first) printf(", "); else first = 0;
                printf("%d", matrix[r * cols + left]);
            }
            left++;
        }
    }
    printf("]\n");
}

int main(void) {
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    spiralOrder(&m1[0][0], 3, 3); // [1, 2, 3, 6, 9, 8, 7, 4, 5]

    int m2[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    spiralOrder(&m2[0][0], 3, 4); // [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]

    return 0;
}
