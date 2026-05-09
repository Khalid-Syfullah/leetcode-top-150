#include <stdio.h>
#include <string.h>

static int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

/* Matches Java: iterate right-to-left, subtract when v < prev */
int romanToInt(const char *s) {
    int total = 0, prev = 0;
    int len = (int)strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        int v = value(s[i]);
        total += v < prev ? -v : v;
        prev = v;
    }
    return total;
}

int main(void) {
    printf("%d\n", romanToInt("III"));     /* 3 */
    printf("%d\n", romanToInt("LVIII"));   /* 58 */
    printf("%d\n", romanToInt("MCMXCIV")); /* 1994 */

    return 0;
}
