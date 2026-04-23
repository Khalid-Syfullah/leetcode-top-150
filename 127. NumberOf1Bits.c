#include <stdint.h>
#include <stdio.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

int main(void) {
    printf("%d\n", hammingWeight(11u));
    return 0;
}
