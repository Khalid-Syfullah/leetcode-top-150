#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    int divisor = 5;
    while (divisor <= n) {
        count += n / divisor;
        divisor *= 5;
    }
    return count;
}

int main() {
    cout << trailingZeroes(3) << "\n";
    cout << trailingZeroes(5) << "\n";
    cout << trailingZeroes(10) << "\n";
    cout << trailingZeroes(25) << "\n";
    cout << trailingZeroes(100) << "\n";
    return 0;
}
