#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (k < 2 || nums[i] != nums[k - 2]) nums[k++] = nums[i];
    }
    return k;
}

int main(void) {
    int a[] = {1, 1, 1, 2, 2, 3};
    printf("%d\n", removeDuplicates(a, 6)); // 5

    int b[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    printf("%d\n", removeDuplicates(b, 9)); // 7

    int c[] = {1};
    printf("%d\n", removeDuplicates(c, 1)); // 1

    return 0;
}
