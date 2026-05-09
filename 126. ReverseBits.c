#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

int main(void) {
    printf("%u\n", reverseBits(43261596));   /* 964176192 */
    printf("%u\n", reverseBits((uint32_t)-3)); /* example with negative input */
    return 0;
}
