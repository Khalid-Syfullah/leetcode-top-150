#include <stdio.h>

int trap(int *height, int n) {
    int left = 0, right = n - 1, leftMax = 0, rightMax = 0, ans = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) leftMax = height[left];
            else ans += leftMax - height[left];
            ++left;
        } else {
            if (height[right] >= rightMax) rightMax = height[right];
            else ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}

int main(void) {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(height, 12));
    return 0;
}
