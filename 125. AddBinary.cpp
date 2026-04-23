#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) { sum += a[i] - '0'; i--; }
        if (j >= 0) { sum += b[j] - '0'; j--; }
        result.push_back('0' + sum % 2);
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << addBinary("11", "1") << "\n";
    cout << addBinary("1010", "1011") << "\n";
    cout << addBinary("0", "0") << "\n";
    return 0;
}
