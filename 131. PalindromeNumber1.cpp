#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x;
    int reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    cout << boolalpha;
    cout << isPalindrome(121) << "\n";
    cout << isPalindrome(-121) << "\n";
    cout << isPalindrome(10) << "\n";
    cout << isPalindrome(0) << "\n";
    return 0;
}
