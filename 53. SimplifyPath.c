#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *simplifyPath(char *path) {
    static char out[2048];
    char *parts[512];
    int top = 0;
    for (char *tok = strtok(path, "/"); tok; tok = strtok(NULL, "/")) {
        if (strcmp(tok, ".") == 0) continue;
        if (strcmp(tok, "..") == 0) {
            if (top > 0) --top;
        } else {
            parts[top++] = tok;
        }
    }
    int k = 0;
    if (top == 0) {
        strcpy(out, "/");
        return out;
    }
    for (int i = 0; i < top; ++i) {
        out[k++] = '/';
        strcpy(out + k, parts[i]);
        k += (int)strlen(parts[i]);
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    char path[] = "/home//foo/";
    puts(simplifyPath(path));
    return 0;
}
