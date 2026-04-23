#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int count[26] = {};
    for (int i = 0; i < (int)s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int c : count) if (c != 0) return false;
    return true;
}

int main() {
    cout << boolalpha;
    cout << isAnagram("anagram", "nagaram") << "\n";
    cout << isAnagram("rat", "car") << "\n";
}
