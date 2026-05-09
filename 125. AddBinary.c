#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *addBinary(const char *a, const char *b) {
    int i = (int)strlen(a) - 1;
    int j = (int)strlen(b) - 1;
    int carry = 0;
    int k = 0;
    char *rev = malloc((size_t)(strlen(a) + strlen(b) + 2));
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        rev[k++] = (char)('0' + sum % 2);
        carry = sum / 2;
    }
    char *out = malloc((size_t)k + 1);
    for (int x = 0; x < k; x++) out[x] = rev[k - 1 - x];
    out[k] = '\0';
    free(rev);
    return out;
}

int main(void) {
    char *ans1 = addBinary("11", "1");
    printf("%s\n", ans1);      /* 100 */
    free(ans1);

    char *ans2 = addBinary("1010", "1011");
    printf("%s\n", ans2);      /* 10101 */
    free(ans2);

    char *ans3 = addBinary("0", "0");
    printf("%s\n", ans3);      /* 0 */
    free(ans3);
    return 0;
}
