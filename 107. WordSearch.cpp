#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
    if (index == (int)word.size()) return true;
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return false;
    if (board[r][c] != word[index]) return false;
    char saved = board[r][c];
    board[r][c] = '#';
    bool found = dfs(board, word, r + 1, c, index + 1)
              || dfs(board, word, r - 1, c, index + 1)
              || dfs(board, word, r, c + 1, index + 1)
              || dfs(board, word, r, c - 1, index + 1);
    board[r][c] = saved;
    return found;
}

bool exist(vector<vector<char>> board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dfs(board, word, r, c, 0)) return true;
        }
    }
    return false;
}

int main() {
    cout << boolalpha;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << exist(board, "ABCCED") << "\n";
    cout << exist(board, "SEE") << "\n";
    cout << exist(board, "ABCB") << "\n";
    return 0;
}
