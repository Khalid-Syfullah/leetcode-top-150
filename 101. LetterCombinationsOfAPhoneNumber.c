#include <stdio.h>
#include <string.h>

static const char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

static void dfs(const char *digits, int idx, char *path) {
    if (!digits[idx]) {
        puts(path);
        return;
    }
    const char *letters = map[digits[idx] - '0'];
    for (int i = 0; letters[i]; ++i) {
        path[idx] = letters[i];
        path[idx + 1] = '\0';
        dfs(digits, idx + 1, path);
    }
}

int main(void) {
    char path[16] = {0};
    dfs("23", 0, path);
    return 0;
}
