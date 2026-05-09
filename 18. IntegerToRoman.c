#include <stdio.h>
#include <string.h>

static const int VALS[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
static const char *SYMS[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

void intToRoman(int num, char *out) {
    int k = 0;
    for (int i = 0; i < 13; i++) {
        while (num >= VALS[i]) {
            const char *s = SYMS[i];
            while (*s) out[k++] = *s++;
            num -= VALS[i];
        }
    }
    out[k] = '\0';
}

int main(void) {
    char out[32];

    intToRoman(3, out);
    printf("%s\n", out);    /* III */

    intToRoman(58, out);
    printf("%s\n", out);    /* LVIII */

    intToRoman(1994, out);
    printf("%s\n", out);    /* MCMXCIV */

    return 0;
}
