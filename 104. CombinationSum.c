#include <stdio.h>

static void dfs(int *cand, int n, int start, int target, int *path, int depth) {
    if (target == 0) {
        putchar('[');
        for (int i = 0; i < depth; ++i) {
            if (i) printf(", ");
            printf("%d", path[i]);
        }
        puts("]");
        return;
    }
    for (int i = start; i < n; ++i) {
        if (cand[i] > target) continue;
        path[depth] = cand[i];
        dfs(cand, n, i, target - cand[i], path, depth + 1);
    }
}

int main(void) {
    int cand[] = {2, 3, 6, 7}, path[16];
    dfs(cand, 4, 0, 7, path, 0);
    return 0;
}
