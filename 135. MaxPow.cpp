#include <iostream>
using namespace std;

double myPow(double x, int n) {
    long N = n;
    double result = 1.0;
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }
    while (N > 0) {
        if ((N & 1) == 1) {
            result *= x;
        }
        x *= x;
        N >>= 1;
    }
    return result;
}

int main() {
    cout << myPow(2.00000, 10) << "\n";
    cout << myPow(2.10000, 3) << "\n";
    cout << myPow(2.00000, -2) << "\n";
    cout << myPow(0.00001, 2147483647) << "\n";
    cout << myPow(1.00000, -2147483648) << "\n";
    return 0;
}
