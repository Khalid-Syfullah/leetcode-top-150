#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool dfs(char board[][4], int rows, int cols, int r, int c, const char *word, int idx) {
    if (!word[idx]) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[idx]) return false;
    char saved = board[r][c];
    board[r][c] = '#';
    bool ok = dfs(board, rows, cols, r + 1, c, word, idx + 1) ||
              dfs(board, rows, cols, r - 1, c, word, idx + 1) ||
              dfs(board, rows, cols, r, c + 1, word, idx + 1) ||
              dfs(board, rows, cols, r, c - 1, word, idx + 1);
    board[r][c] = saved;
    return ok;
}

static bool exist(char board[][4], int rows, int cols, const char *word) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (dfs(board, rows, cols, r, c, word, 0)) return true;
        }
    }
    return false;
}

int main(void) {
    char board[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    printf("%s\n", exist(board, 3, 4, "ABCCED") ? "true" : "false");
    printf("%s\n", exist(board, 3, 4, "SEE") ? "true" : "false");
    printf("%s\n", exist(board, 3, 4, "ABCB") ? "true" : "false");
    return 0;
}
