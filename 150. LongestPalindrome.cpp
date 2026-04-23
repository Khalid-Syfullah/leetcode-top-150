#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int expand(const string& s, int left, int right) {
    while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindromeSubstr(string s) {
    if (s.empty()) return "";
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int main() {
    cout << longestPalindromeSubstr("babad") << "\n";
    cout << longestPalindromeSubstr("cbbd") << "\n";
    cout << longestPalindromeSubstr("a") << "\n";
    cout << longestPalindromeSubstr("ac") << "\n";
    cout << longestPalindromeSubstr("forgeeksskeegfor") << "\n";
    return 0;
}
