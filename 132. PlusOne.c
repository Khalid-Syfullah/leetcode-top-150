#include <stdio.h>

int plusOne(int *digits, int n, int *out) {
    for (int i = 0; i < n; ++i) out[i + 1] = digits[i];
    int carry = 1;
    for (int i = n; i >= 1 && carry; --i) {
        int sum = out[i] + carry;
        out[i] = sum % 10;
        carry = sum / 10;
    }
    out[0] = carry;
    return carry ? n + 1 : n;
}

int main(void) {
    int digits[] = {9, 9, 9}, out[4];
    int n = plusOne(digits, 3, out);
    int start = n == 4 ? 0 : 1;
    for (int i = start; i < 4; ++i) printf("%d ", out[i]);
    puts("");
    return 0;
}
