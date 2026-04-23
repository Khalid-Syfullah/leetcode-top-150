#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static bool dfs(char **board, int rows, int cols, int r, int c, const char *word, int idx) {
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

bool exist(char **board, int rows, int cols, const char *word) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (dfs(board, rows, cols, r, c, word, 0)) return true;
        }
    }
    return false;
}

int main(void) {
    char r0[] = "ABCE", r1[] = "SFCS", r2[] = "ADEE";
    char *board[] = {r0, r1, r2};
    puts(exist(board, 3, 4, "ABCCED") ? "true" : "false");
    return 0;
}
