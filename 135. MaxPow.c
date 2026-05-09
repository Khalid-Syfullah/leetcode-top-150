#include <stdio.h>

double myPow(double x, int n) {
    long long N = n; /* use long long to handle INT_MIN */
    double result = 1.0;
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }

    while (N > 0) {
        if ((N & 1) == 1) {
            result *= x; /* multiply when the current bit is 1 */
        }
        x *= x;  /* square the base */
        N >>= 1; /* shift right (divide exponent by 2) */
    }

    return result;
}

int main(void) {
    printf("%.1f\n",   myPow(2.00000, 10));           /* 1024.0 */
    printf("%.5f\n",   myPow(2.10000, 3));            /* ~9.261 */
    printf("%.2f\n",   myPow(2.00000, -2));           /* 0.25 */
    printf("%.10f\n",  myPow(0.00001, 2147483647));   /* small number */
    printf("%.1f\n",   myPow(1.00000, -2147483648));  /* 1.0 edge case */
    return 0;
}
