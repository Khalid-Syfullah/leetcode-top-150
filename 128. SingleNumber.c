#include <stdio.h>

int singleNumber(int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main(void) {
    int a[] = {2, 2, 1};
    int b[] = {4, 1, 2, 1, 2};
    int c[] = {1};

    printf("%d\n", singleNumber(a, 3)); /* 1 */
    printf("%d\n", singleNumber(b, 5)); /* 4 */
    printf("%d\n", singleNumber(c, 1)); /* 1 */
    return 0;
}
