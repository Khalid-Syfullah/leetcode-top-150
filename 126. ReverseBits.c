#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; ++i) {
        ans = (ans << 1) | (n & 1u);
        n >>= 1;
    }
    return ans;
}

int main(void) {
    printf("%u\n", reverseBits(43261596u));
    return 0;
}
