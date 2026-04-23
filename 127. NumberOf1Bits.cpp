#include <iostream>
using namespace std;

int hammingWeight(unsigned int n) {
    int count = 0;
    while (n != 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main() {
    cout << hammingWeight(11) << "\n";
    cout << hammingWeight(128) << "\n";
    cout << hammingWeight((unsigned int)-3) << "\n";
    return 0;
}
