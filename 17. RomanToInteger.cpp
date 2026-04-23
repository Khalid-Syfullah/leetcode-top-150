#include <iostream>
#include <string>
using namespace std;

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int total = 0, prev = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int v = value(s[i]);
        total += v < prev ? -v : v;
        prev = v;
    }
    return total;
}

int main() {
    cout << romanToInt("III") << "\n";
    cout << romanToInt("LVIII") << "\n";
    cout << romanToInt("MCMXCIV") << "\n";

    return 0;
}
