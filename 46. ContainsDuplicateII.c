#include <stdbool.h>
#include <stdio.h>

bool containsNearbyDuplicate(int *nums, int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && j <= i + k; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

int main(void) {
    int nums[] = {1, 2, 3, 1};
    puts(containsNearbyDuplicate(nums, 4, 3) ? "true" : "false");
    return 0;
}
