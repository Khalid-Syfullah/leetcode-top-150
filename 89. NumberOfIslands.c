#include <stdio.h>

static void dfs(char **grid, int rows, int cols, int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, rows, cols, r + 1, c);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r, c - 1);
}

int numIslands(char **grid, int rows, int cols) {
    int count = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == '1') {
                ++count;
                dfs(grid, rows, cols, r, c);
            }
        }
    }
    return count;
}

int main(void) {
    char r0[] = "11110";
    char r1[] = "11010";
    char r2[] = "11000";
    char r3[] = "00000";
    char *grid[] = {r0, r1, r2, r3};
    printf("%d\n", numIslands(grid, 4, 5));
    return 0;
}
