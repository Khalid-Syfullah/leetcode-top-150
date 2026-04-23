#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = (int)matrix.size();
    int cols = (int)matrix[0].size();
    bool firstRowZero = false, firstColZero = false;
    for (int c = 0; c < cols; c++) {
        if (matrix[0][c] == 0) { firstRowZero = true; break; }
    }
    for (int r = 0; r < rows; r++) {
        if (matrix[r][0] == 0) { firstColZero = true; break; }
    }
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrix[r][c] == 0) {
                matrix[r][0] = 0;
                matrix[0][c] = 0;
            }
        }
    }
    for (int r = 1; r < rows; r++) {
        if (matrix[r][0] == 0) {
            for (int c = 1; c < cols; c++) matrix[r][c] = 0;
        }
    }
    for (int c = 1; c < cols; c++) {
        if (matrix[0][c] == 0) {
            for (int r = 1; r < rows; r++) matrix[r][c] = 0;
        }
    }
    if (firstRowZero) {
        for (int c = 0; c < cols; c++) matrix[0][c] = 0;
    }
    if (firstColZero) {
        for (int r = 0; r < rows; r++) matrix[r][0] = 0;
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[";
        for (size_t i = 0; i < row.size(); i++) {
            if (i) cout << ", ";
            cout << row[i];
        }
        cout << "]\n";
    }
}

int main() {
    vector<vector<int>> m1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> m2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(m1);
    setZeroes(m2);
    printMatrix(m1);
    cout << "\n";
    printMatrix(m2);
}
