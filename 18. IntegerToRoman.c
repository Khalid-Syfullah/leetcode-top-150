#include <stdio.h>

char *intToRoman(int num, char *out) {
    static const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int k = 0;
    for (int i = 0; i < 13; ++i) {
        while (num >= values[i]) {
            const char *s = symbols[i];
            while (*s) out[k++] = *s++;
            num -= values[i];
        }
    }
    out[k] = '\0';
    return out;
}

int main(void) {
    char out[32];
    puts(intToRoman(1994, out));
    return 0;
}
