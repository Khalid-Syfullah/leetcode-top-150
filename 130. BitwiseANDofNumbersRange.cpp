#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shifts = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shifts++;
    }
    return left << shifts;
}

int main() {
    cout << rangeBitwiseAnd(5, 7) << "\n";
    cout << rangeBitwiseAnd(0, 0) << "\n";
    cout << rangeBitwiseAnd(1, 2147483647) << "\n";
    cout << rangeBitwiseAnd(12, 15) << "\n";
    return 0;
}
