#include <stdio.h>

int climbStairs(int n) {
    int a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(void) {
    printf("%d\n", climbStairs(5));
    return 0;
}
