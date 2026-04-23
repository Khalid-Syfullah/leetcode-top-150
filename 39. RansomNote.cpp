#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int count[26] = {};
    for (char c : magazine) count[c - 'a']++;
    for (char c : ransomNote) {
        if (--count[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << canConstruct("a", "b") << "\n";
    cout << canConstruct("aa", "ab") << "\n";
    cout << canConstruct("aa", "aab") << "\n";
}
