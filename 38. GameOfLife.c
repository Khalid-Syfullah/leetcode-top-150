#include <stdio.h>

/* In-place using encoding:
   -1 = was alive, will die
    2 = was dead, will become alive */
void gameOfLife(int *board, int rows, int cols) {
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int live = 0;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                int val = board[nr * cols + nc];
                if (val == 1 || val == -1) live++;
            }
            if (board[r * cols + c] == 1 && (live < 2 || live > 3))
                board[r * cols + c] = -1;
            if (board[r * cols + c] == 0 && live == 3)
                board[r * cols + c] = 2;
        }
    }

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            board[r * cols + c] = board[r * cols + c] > 0 ? 1 : 0;
}

static void printBoard(int *board, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        printf("[");
        for (int c = 0; c < cols; c++) {
            if (c) printf(", ");
            printf("%d", board[r * cols + c]);
        }
        printf("]\n");
    }
}

int main(void) {
    int board[4][3] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    gameOfLife(&board[0][0], 4, 3);
    printBoard(&board[0][0], 4, 3);
    return 0;
}
