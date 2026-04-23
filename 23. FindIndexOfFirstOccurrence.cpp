#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.length(), m = needle.length();
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
        if (haystack.substr(i, m) == needle) return i;
    }
    return -1;
}

int main() {
    cout << strStr("sadbutsad", "sad") << "\n";
    cout << strStr("leetcode", "leeto") << "\n";
    cout << strStr("hello", "ll") << "\n";

    return 0;
}
