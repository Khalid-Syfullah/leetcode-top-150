#include <stdio.h>

int maxArea(int *height, int n) {
    int left = 0, right = n - 1, best = 0;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int area = h * (right - left);
        if (area > best) best = area;
        if (height[left] < height[right]) ++left;
        else --right;
    }
    return best;
}

int main(void) {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(height, 9));
    return 0;
}
