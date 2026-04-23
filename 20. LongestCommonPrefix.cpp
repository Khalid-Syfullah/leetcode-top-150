#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix = strs[0];
    for (int i = 1; i < (int)strs.size(); i++) {
        while (strs[i].substr(0, prefix.size()) != prefix) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    vector<string> a = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(a) << "\n";

    vector<string> b = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(b) << "\n";

    vector<string> c = {"a"};
    cout << longestCommonPrefix(c) << "\n";

    return 0;
}
