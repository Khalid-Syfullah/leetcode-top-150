#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int n) {
    int stack[1024], top = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            int b = stack[--top], a = stack[--top];
            if (tokens[i][0] == '+') stack[top++] = a + b;
            else if (tokens[i][0] == '-') stack[top++] = a - b;
            else if (tokens[i][0] == '*') stack[top++] = a * b;
            else stack[top++] = a / b;
        } else {
            stack[top++] = atoi(tokens[i]);
        }
    }
    return stack[0];
}

int main(void) {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    printf("%d\n", evalRPN(tokens, 5));
    return 0;
}
