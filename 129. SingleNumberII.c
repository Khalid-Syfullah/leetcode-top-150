#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < numsSize; i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}

int main(void) {
    int a[] = {2, 2, 3, 2};
    int b[] = {0, 1, 0, 1, 0, 1, 99};
    int c[] = {-2, -2, -2, -7};

    printf("%d\n", singleNumber(a, 4)); /* 3 */
    printf("%d\n", singleNumber(b, 7)); /* 99 */
    printf("%d\n", singleNumber(c, 4)); /* -7 */
    return 0;
}
