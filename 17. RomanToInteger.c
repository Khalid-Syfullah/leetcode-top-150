#include <stdio.h>

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

int romanToInt(const char *s) {
    int total = 0;
    for (int i = 0; s[i]; ++i) {
        int curr = value(s[i]);
        int next = value(s[i + 1]);
        total += (curr < next) ? -curr : curr;
    }
    return total;
}

int main(void) {
    printf("%d\n", romanToInt("MCMXCIV"));
    return 0;
}
