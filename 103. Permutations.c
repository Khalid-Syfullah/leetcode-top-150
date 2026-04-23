#include <stdbool.h>
#include <stdio.h>

static void dfs(int *nums, int n, bool *used, int *path, int depth) {
    if (depth == n) {
        putchar('[');
        for (int i = 0; i < n; ++i) {
            if (i) printf(", ");
            printf("%d", path[i]);
        }
        puts("]");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        path[depth] = nums[i];
        dfs(nums, n, used, path, depth + 1);
        used[i] = false;
    }
}

int main(void) {
    int nums[] = {1, 2, 3}, path[3];
    bool used[3] = {false};
    dfs(nums, 3, used, path, 0);
    return 0;
}
