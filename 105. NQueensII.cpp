#include <iostream>
#include <vector>
using namespace std;

int backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) return 1;
    int count = 0;
    for (int col = 0; col < n; col++) {
        int d1 = row - col + (n - 1);
        int d2 = row + col;
        if (cols[col] || diag1[d1] || diag2[d2]) continue;
        cols[col] = true;
        diag1[d1] = true;
        diag2[d2] = true;
        count += backtrack(row + 1, n, cols, diag1, diag2);
        cols[col] = false;
        diag1[d1] = false;
        diag2[d2] = false;
    }
    return count;
}

int totalNQueens(int n) {
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    return backtrack(0, n, cols, diag1, diag2);
}

int main() {
    cout << totalNQueens(1) << "\n";
    cout << totalNQueens(4) << "\n";
    cout << totalNQueens(8) << "\n";
    return 0;
}
