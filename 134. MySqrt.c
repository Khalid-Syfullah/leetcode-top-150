#include <stdio.h>

int mySqrt(int x) {
    int left = 0, right = x, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    printf("%d\n", mySqrt(8));
    return 0;
}
