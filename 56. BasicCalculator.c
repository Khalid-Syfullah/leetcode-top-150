#include <ctype.h>
#include <stdio.h>

int calculate(const char *s) {
    int ans = 0, num = 0, sign = 1;
    int stack[1024], top = 0;
    for (int i = 0; s[i]; ++i) {
        if (isdigit((unsigned char)s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '+') {
            ans += sign * num;
            num = 0;
            sign = 1;
        } else if (s[i] == '-') {
            ans += sign * num;
            num = 0;
            sign = -1;
        } else if (s[i] == '(') {
            stack[top++] = ans;
            stack[top++] = sign;
            ans = 0;
            sign = 1;
        } else if (s[i] == ')') {
            ans += sign * num;
            num = 0;
            ans *= stack[--top];
            ans += stack[--top];
        }
    }
    return ans + sign * num;
}

int main(void) {
    printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)"));
    return 0;
}
