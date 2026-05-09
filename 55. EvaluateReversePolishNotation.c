#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char **tokens, int n) {
    int stack[1024];
    int top = 0;
    for (int i = 0; i < n; i++) {
        char *t = tokens[i];
        if (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 || strcmp(t, "/") == 0) {
            int b = stack[--top];
            int a = stack[--top];
            if (t[0] == '+') stack[top++] = a + b;
            else if (t[0] == '-') stack[top++] = a - b;
            else if (t[0] == '*') stack[top++] = a * b;
            else stack[top++] = a / b;
        } else {
            stack[top++] = atoi(t);
        }
    }
    return stack[0];
}

int main(void) {
    char *t1[] = {"2", "1", "+", "3", "*"};
    printf("%d\n", evalRPN(t1, 5)); /* 9 */

    char *t2[] = {"4", "13", "5", "/", "+"};
    printf("%d\n", evalRPN(t2, 5)); /* 6 */

    char *t3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    printf("%d\n", evalRPN(t3, 13)); /* 22 */

    return 0;
}
