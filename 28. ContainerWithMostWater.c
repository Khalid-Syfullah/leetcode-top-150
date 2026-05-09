#include <stdio.h>

int maxArea(int *height, int n) {
    int l = 0, r = n - 1, best = 0;
    while (l < r) {
        int h = height[l] < height[r] ? height[l] : height[r];
        int area = h * (r - l);
        if (area > best) best = area;
        if (height[l] < height[r]) l++; else r--;
    }
    return best;
}

int main(void) {
    int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d\n", maxArea(a, 9)); // 49

    int b[] = {1, 1};
    printf("%d\n", maxArea(b, 2)); // 1

    return 0;
}
