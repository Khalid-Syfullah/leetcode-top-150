#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(const char *a, const char *b) {
    int i = (int)strlen(a) - 1, j = (int)strlen(b) - 1, carry = 0, k = 0;
    char *rev = malloc((size_t)(strlen(a) + strlen(b) + 2));
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        rev[k++] = (char)('0' + (sum & 1));
        carry = sum >> 1;
    }
    char *out = malloc((size_t)k + 1);
    for (int x = 0; x < k; ++x) out[x] = rev[k - 1 - x];
    out[k] = '\0';
    free(rev);
    return out;
}

int main(void) {
    char *ans = addBinary("1010", "1011");
    puts(ans);
    free(ans);
    return 0;
}
