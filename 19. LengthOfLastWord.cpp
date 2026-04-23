#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int i = s.length() - 1, len = 0;
    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i] != ' ') { len++; i--; }
    return len;
}

int main() {
    cout << lengthOfLastWord("Hello World") << "\n";
    cout << lengthOfLastWord("   fly me   to   the moon ") << "\n";
    cout << lengthOfLastWord("luffy is still joyboy") << "\n";

    return 0;
}
