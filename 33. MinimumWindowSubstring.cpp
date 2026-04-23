#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if ((int)s.size() < (int)t.size()) return "";
    int need[128] = {};
    for (char c : t) need[(int)c]++;
    int missing = (int)t.size(), l = 0, start = 0, minLen = INT_MAX;
    for (int r = 0; r < (int)s.size(); r++) {
        if (need[(int)s[r]]-- > 0) missing--;
        while (missing == 0) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            if (need[(int)s[l++]]++ == 0) missing++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
    cout << minWindow("a", "a") << "\n";
    cout << minWindow("a", "aa") << "\n";
}
