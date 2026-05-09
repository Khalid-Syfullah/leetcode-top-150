#include <stdio.h>

int trailingZeroes(int n) {
    int count = 0;
    int divisor = 5;

    while (divisor <= n) {
        count += n / divisor;
        divisor *= 5;
    }

    return count;
}

int main(void) {
    printf("%d\n", trailingZeroes(3));   /* 0 */
    printf("%d\n", trailingZeroes(5));   /* 1 */
    printf("%d\n", trailingZeroes(10));  /* 2 */
    printf("%d\n", trailingZeroes(25));  /* 6 */
    printf("%d\n", trailingZeroes(100)); /* 24 */
    return 0;
}
