#include <stdio.h>

void productExceptSelf(const int *nums, int n, int *out) {
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        out[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        out[i] *= suffix;
        suffix *= nums[i];
    }
}

int main(void) {
    int nums[] = {1, 2, 3, 4}, out[4];
    productExceptSelf(nums, 4, out);
    for (int i = 0; i < 4; ++i) printf("%d ", out[i]);
    puts("");
    return 0;
}
