#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int rows = (int)board.size();
    int cols = (int)board[0].size();
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if (board[nr][nc] == 1 || board[nr][nc] == -1) liveNeighbors++;
            }
            if (board[r][c] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) board[r][c] = -1;
            if (board[r][c] == 0 && liveNeighbors == 3) board[r][c] = 2;
        }
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            board[r][c] = board[r][c] > 0 ? 1 : 0;
        }
    }
}

void printBoard(vector<vector<int>>& board) {
    for (auto& row : board) {
        cout << "[";
        for (size_t i = 0; i < row.size(); i++) { if (i) cout << ", "; cout << row[i]; }
        cout << "]\n";
    }
}

int main() {
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(board);
    printBoard(board);
    return 0;
}
