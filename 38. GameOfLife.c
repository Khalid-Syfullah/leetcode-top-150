#include <stdio.h>

void gameOfLife(int board[4][3], int rows, int cols) {
    int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int live = 0;
            for (int d = 0; d < 8; ++d) {
                int nr = r + dirs[d][0], nc = c + dirs[d][1];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && (board[nr][nc] & 1)) ++live;
            }
            if ((board[r][c] & 1) && (live == 2 || live == 3)) board[r][c] |= 2;
            if (!(board[r][c] & 1) && live == 3) board[r][c] |= 2;
        }
    }
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) board[r][c] >>= 1;
    }
}

int main(void) {
    int board[4][3] = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(board, 4, 3);
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 3; ++c) printf("%d ", board[r][c]);
        puts("");
    }
    return 0;
}
