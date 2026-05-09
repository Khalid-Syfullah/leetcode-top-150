#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *simplifyPath(const char *path) {
    static char out[2048];
    char buf[2048];
    strncpy(buf, path, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *parts[512];
    int top = 0;

    for (char *tok = strtok(buf, "/"); tok; tok = strtok(NULL, "/")) {
        if (strcmp(tok, ".") == 0 || tok[0] == '\0') continue;
        if (strcmp(tok, "..") == 0) {
            if (top > 0) top--;
        } else {
            parts[top++] = tok;
        }
    }

    if (top == 0) {
        strcpy(out, "/");
        return out;
    }

    int k = 0;
    for (int i = 0; i < top; i++) {
        out[k++] = '/';
        strcpy(out + k, parts[i]);
        k += (int)strlen(parts[i]);
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    printf("%s\n", simplifyPath("/home/"));
    printf("%s\n", simplifyPath("/../"));
    printf("%s\n", simplifyPath("/home//foo/"));
    printf("%s\n", simplifyPath("/a/./b/../../c/"));
    return 0;
}
