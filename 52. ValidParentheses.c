#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(const char *s) {
    char stack[1024];
    int top = 0;
    for (int i = 0; s[i]; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') stack[top++] = c;
        else {
            if (top == 0) return false;
            char open = stack[--top];
            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) return false;
        }
    }
    return top == 0;
}

int main(void) {
    puts(isValid("()[]{}") ? "true" : "false");
    return 0;
}
