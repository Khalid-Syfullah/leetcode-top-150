#include <stdio.h>

static void dfs(int n, int open, int close, int idx, char *path) {
    if (idx == 2 * n) {
        path[idx] = '\0';
        puts(path);
        return;
    }
    if (open < n) {
        path[idx] = '(';
        dfs(n, open + 1, close, idx + 1, path);
    }
    if (close < open) {
        path[idx] = ')';
        dfs(n, open, close + 1, idx + 1, path);
    }
}

int main(void) {
    char path[16];
    dfs(3, 0, 0, 0, path);
    return 0;
}
