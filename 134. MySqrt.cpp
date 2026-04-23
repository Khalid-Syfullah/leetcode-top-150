#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x < 2) return x;
    long r = x;
    while (r * r > x) {
        r = (r + x / r) / 2;
    }
    return (int)r;
}

int main() {
    cout << mySqrt(4) << "\n";
    cout << mySqrt(8) << "\n";
    cout << mySqrt(0) << "\n";
    cout << mySqrt(1) << "\n";
    cout << mySqrt(2147395600) << "\n";
    return 0;
}
