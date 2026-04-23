#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
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

int main() {
    cout << boolalpha;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    cout << searchMatrix(matrix, 3) << "\n";
    cout << searchMatrix(matrix, 13) << "\n";
    return 0;
}
