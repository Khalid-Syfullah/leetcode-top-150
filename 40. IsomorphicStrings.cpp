#include <iostream>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    int ms[256] = {}, mt[256] = {};
    for (int i = 0; i < (int)s.size(); i++) {
        unsigned char a = s[i], b = t[i];
        if (ms[a] != mt[b]) return false;
        ms[a] = mt[b] = i + 1;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << isIsomorphic("egg", "add") << "\n";
    cout << isIsomorphic("foo", "bar") << "\n";
    cout << isIsomorphic("paper", "title") << "\n";
    return 0;
}
