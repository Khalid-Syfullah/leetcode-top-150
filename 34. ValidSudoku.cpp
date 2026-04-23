#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char value = board[r][c];
            if (value == '.') continue;
            string rowKey = string(1, value) + " in row " + to_string(r);
            string colKey = string(1, value) + " in col " + to_string(c);
            string boxKey = string(1, value) + " in box " + to_string(r / 3) + "-" + to_string(c / 3);
            if (!seen.insert(rowKey).second || !seen.insert(colKey).second || !seen.insert(boxKey).second) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << boolalpha;
    vector<vector<char>> validBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    vector<vector<char>> invalidBoard = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << isValidSudoku(validBoard) << "\n";
    cout << isValidSudoku(invalidBoard) << "\n";
}
