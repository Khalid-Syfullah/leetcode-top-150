#include <stdio.h>

int trailingZeroes(int n) {
    int ans = 0;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    return ans;
}

int main(void) {
    printf("%d\n", trailingZeroes(25));
    return 0;
}
