#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {
    cout << reverseBits(43261596) << "\n";
    cout << reverseBits((unsigned int)-3) << "\n";
    return 0;
}
