#include <iostream>
using namespace std;

int next(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = next(n);
    while (fast != 1 && slow != fast) {
        slow = next(slow);
        fast = next(next(fast));
    }
    return fast == 1;
}

int main() {
    cout << boolalpha;
    cout << isHappy(19) << "\n";
    cout << isHappy(2) << "\n";
    cout << isHappy(1) << "\n";
    return 0;
}
