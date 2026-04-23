#include <stdio.h>

void twoSum(int *nums, int n, int target, int *a, int *b) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                *a = i;
                *b = j;
                return;
            }
        }
    }
    *a = *b = -1;
}

int main(void) {
    int nums[] = {2, 7, 11, 15}, i, j;
    twoSum(nums, 4, 9, &i, &j);
    printf("[%d, %d]\n", i, j);
    return 0;
}
