#include <iostream>
using namespace std;

int nextNum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = nextNum(n);
    while (fast != 1 && slow != fast) {
        slow = nextNum(slow);
        fast = nextNum(nextNum(fast));
    }
    return fast == 1;
}

int main() {
    cout << boolalpha;
    cout << isHappy(19) << "\n";
    cout << isHappy(2) << "\n";
    cout << isHappy(1) << "\n";
}
