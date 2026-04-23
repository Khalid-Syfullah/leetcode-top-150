#include <stdbool.h>
#include <stdio.h>

bool isValidSudoku(char board[9][9]) {
    int rows[9][10] = {0}, cols[9][10] = {0}, box[9][10] = {0};
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') continue;
            int d = board[r][c] - '0';
            int b = (r / 3) * 3 + c / 3;
            if (rows[r][d] || cols[c][d] || box[b][d]) return false;
            rows[r][d] = cols[c][d] = box[b][d] = 1;
        }
    }
    return true;
}

int main(void) {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    puts(isValidSudoku(board) ? "true" : "false");
    return 0;
}
