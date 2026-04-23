#include <stdio.h>

double myPow(double x, int n) {
    long long exp = n;
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }
    double ans = 1.0;
    while (exp) {
        if (exp & 1LL) ans *= x;
        x *= x;
        exp >>= 1;
    }
    return ans;
}

int main(void) {
    printf("%.5f\n", myPow(2.0, 10));
    return 0;
}
