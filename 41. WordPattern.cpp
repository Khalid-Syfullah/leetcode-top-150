#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> words;
    istringstream iss(s);
    string w;
    while (iss >> w) words.push_back(w);
    if ((int)words.size() != (int)pattern.size()) return false;
    unordered_map<char, string> cToW;
    unordered_map<string, char> wToC;
    for (int i = 0; i < (int)pattern.size(); i++) {
        char c = pattern[i];
        string& word = words[i];
        if (cToW.count(c) && cToW[c] != word) return false;
        if (wToC.count(word) && wToC[word] != c) return false;
        cToW[c] = word;
        wToC[word] = c;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << wordPattern("abba", "dog cat cat dog") << "\n";
    cout << wordPattern("abba", "dog cat cat fish") << "\n";
    cout << wordPattern("aaaa", "dog cat cat dog") << "\n";
}
