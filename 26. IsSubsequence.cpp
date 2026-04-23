#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0;
    for (int j = 0; j < (int)t.size() && i < (int)s.size(); j++) {
        if (s[i] == t[j]) i++;
    }
    return i == (int)s.size();
}

int main() {
    cout << boolalpha;
    cout << isSubsequence("abc", "ahbgdc") << "\n";
    cout << isSubsequence("axc", "ahbgdc") << "\n";
    cout << isSubsequence("", "abc") << "\n";
}
