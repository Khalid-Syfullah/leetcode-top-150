#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    vector<string> words;
    string w;
    while (iss >> w) words.push_back(w);
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) result += ' ';
    }
    return result;
}

int main() {
    cout << reverseWords("the sky is blue") << "\n";
    cout << reverseWords("  hello world  ") << "\n";
    cout << reverseWords("a good   example") << "\n";

    return 0;
}
