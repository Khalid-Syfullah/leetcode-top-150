#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) return result;
    int top = 0, bottom = (int)matrix.size() - 1;
    int left = 0, right = (int)matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) result.push_back(matrix[top][col]);
        top++;
        for (int row = top; row <= bottom; row++) result.push_back(matrix[row][right]);
        right--;
        if (top <= bottom) {
            for (int col = right; col >= left; col--) result.push_back(matrix[bottom][col]);
            bottom--;
        }
        if (left <= right) {
            for (int row = bottom; row >= top; row--) result.push_back(matrix[row][left]);
            left++;
        }
    }
    return result;
}

int main() {
    auto print = [](const vector<int>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << v[i];
        }
        cout << "]\n";
    };

    vector<vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(spiralOrder(m1));

    vector<vector<int>> m2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print(spiralOrder(m2));
}
