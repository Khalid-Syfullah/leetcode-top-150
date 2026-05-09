#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main(void) {
    int a[] = {1, 1, 2};
    int ka = removeDuplicates(a, 3);
    printf("Expected: 2, Got: %d\n", ka); // [1,2]

    int b[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int kb = removeDuplicates(b, 10);
    printf("Expected: 5, Got: %d\n", kb); // [0,1,2,3,4]

    return 0;
}
