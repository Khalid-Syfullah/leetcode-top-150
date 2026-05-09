#include <ctype.h>
#include <stdio.h>

int calculate(const char *s) {
    int result = 0, num = 0, sign = 1;
    int stack[1024];
    int top = 0;

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (isdigit((unsigned char)c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            stack[top++] = result;
            stack[top++] = sign;
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            result *= stack[--top];
            result += stack[--top];
        }
    }
    return result + sign * num;
}

int main(void) {
    printf("%d\n", calculate("1 + 1"));                /* 2 */
    printf("%d\n", calculate(" 2-1 + 2 "));            /* 3 */
    printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)")); /* 23 */
    return 0;
}
