#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}

int main(void) {
    int a[] = {3, 2, 2, 3};
    printf("%d\n", removeElement(a, 4, 3)); // 2

    int b[] = {0, 1, 2, 2, 3, 0, 4, 2};
    printf("%d\n", removeElement(b, 8, 2)); // 5

    int c[] = {0}; /* placeholder, size=0 */
    printf("%d\n", removeElement(c, 0, 1)); // 0

    return 0;
}
