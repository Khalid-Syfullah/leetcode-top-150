#include <stdio.h>

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++shift;
    }
    return left << shift;
}

int main(void) {
    printf("%d\n", rangeBitwiseAnd(5, 7));
    return 0;
}
