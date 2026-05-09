#include <stdbool.h>
#include <stdio.h>

static bool searchMatrix(int matrix[][4], int rows, int cols, int target) {
    int left = 0;
    int right = rows * cols - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int r = mid / cols;
        int c = mid % cols;
        int value = matrix[r][c];
        if (value == target) return true;
        else if (value < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(void) {
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    printf("%s\n", searchMatrix(matrix, 3, 4, 3) ? "true" : "false");
    printf("%s\n", searchMatrix(matrix, 3, 4, 13) ? "true" : "false");
    return 0;
}
