#include <stdio.h>

int trap(int *h, int n) {
    int l = 0, r = n - 1, lMax = 0, rMax = 0, water = 0;
    while (l < r) {
        if (h[l] < h[r]) {
            if (h[l] >= lMax) lMax = h[l];
            else water += lMax - h[l];
            l++;
        } else {
            if (h[r] >= rMax) rMax = h[r];
            else water += rMax - h[r];
            r--;
        }
    }
    return water;
}

int main(void) {
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(a, 12)); /* 6 */

    int b[] = {4, 2, 0, 3, 2, 5};
    printf("%d\n", trap(b, 6)); /* 9 */

    return 0;
}
