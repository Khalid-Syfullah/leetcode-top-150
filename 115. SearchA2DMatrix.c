#include <stdbool.h>
#include <stdio.h>

bool searchMatrix(int matrix[3][4], int rows, int cols, int target) {
    int left = 0, right = rows * cols - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int val = matrix[mid / cols][mid % cols];
        if (val == target) return true;
        if (val < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(void) {
    int matrix[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    puts(searchMatrix(matrix, 3, 4, 3) ? "true" : "false");
    return 0;
}
