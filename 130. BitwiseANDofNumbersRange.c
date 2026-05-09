#include <stdio.h>

int rangeBitwiseAnd(int left, int right) {
    int shifts = 0;

    while (left < right) {
        left >>= 1;
        right >>= 1;
        shifts++;
    }

    return left << shifts;
}

int main(void) {
    printf("%d\n", rangeBitwiseAnd(5, 7));          /* 4 */
    printf("%d\n", rangeBitwiseAnd(0, 0));          /* 0 */
    printf("%d\n", rangeBitwiseAnd(1, 2147483647)); /* 0 */
    printf("%d\n", rangeBitwiseAnd(12, 15));        /* 12 */
    return 0;
}
