#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last;
    int l = 0, best = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        char c = s[r];
        if (last.count(c) && last[c] >= l) l = last[c] + 1;
        last[c] = r;
        best = max(best, r - l + 1);
    }
    return best;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("bbbbb") << "\n";
    cout << lengthOfLongestSubstring("pwwkew") << "\n";
    cout << lengthOfLongestSubstring("") << "\n";
}
