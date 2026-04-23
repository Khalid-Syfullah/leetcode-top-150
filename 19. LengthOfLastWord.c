#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char *s) {
    int i = (int)strlen(s) - 1;
    while (i >= 0 && s[i] == ' ') --i;
    int len = 0;
    while (i >= 0 && s[i] != ' ') {
        ++len;
        --i;
    }
    return len;
}

int main(void) {
    printf("%d\n", lengthOfLastWord("Hello World"));
    return 0;
}
