#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(const char *s) {
    char stack[1024];
    int top = 0;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else {
            if (top == 0) return false;
            char t = stack[--top];
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
        }
    }
    return top == 0;
}

int main(void) {
    printf("%s\n", isValid("()") ? "true" : "false");
    printf("%s\n", isValid("()[]{}") ? "true" : "false");
    printf("%s\n", isValid("(]") ? "true" : "false");
    printf("%s\n", isValid("([)]") ? "true" : "false");
    return 0;
}
