#include <stdio.h>
#include <string.h>

static void dfs(char grid[][6], int rows, int cols, int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, rows, cols, r + 1, c);
    dfs(grid, rows, cols, r - 1, c);
    dfs(grid, rows, cols, r, c + 1);
    dfs(grid, rows, cols, r, c - 1);
}

int numIslands(char grid[][6], int rows, int cols) {
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
    // Test case 1: expected 1
    char grid1[4][6] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    printf("Test 1 | Expected: 1 | Actual: %d\n", numIslands(grid1, 4, 5));

    // Test case 2: expected 3
    char grid2[4][6] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    printf("Test 2 | Expected: 3 | Actual: %d\n", numIslands(grid2, 4, 5));
    return 0;
}
