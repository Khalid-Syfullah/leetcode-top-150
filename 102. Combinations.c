#include <stdio.h>

static void dfs(int n, int k, int start, int depth, int *path) {
    if (depth == k) {
        putchar('[');
        for (int i = 0; i < k; ++i) {
            if (i) printf(", ");
            printf("%d", path[i]);
        }
        puts("]");
        return;
    }
    for (int x = start; x <= n; ++x) {
        path[depth] = x;
        dfs(n, k, x + 1, depth + 1, path);
    }
}

int main(void) {
    int path[4];
    dfs(4, 2, 1, 0, path);
    return 0;
}
