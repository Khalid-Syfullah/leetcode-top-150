#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0, n = words.size();
    while (i < n) {
        int j = i, len = 0;
        while (j < n && len + (int)words[j].size() + (j - i) <= maxWidth) {
            len += words[j++].size();
        }
        string line;
        int gaps = j - i - 1;
        if (j == n || gaps == 0) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) line += ' ';
            }
            while ((int)line.size() < maxWidth) line += ' ';
        } else {
            int spaces = (maxWidth - len) / gaps;
            int extra = (maxWidth - len) % gaps;
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) {
                    for (int s = 0; s < spaces; s++) line += ' ';
                    if (k - i < extra) line += ' ';
                }
            }
        }
        result.push_back(line);
        i = j;
    }
    return result;
}

int main() {
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res1 = fullJustify(words1, 16);
    for (const string& line : res1) cout << line << "\n";

    cout << "\n";

    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> res2 = fullJustify(words2, 16);
    for (const string& line : res2) cout << line << "\n";

    return 0;
}
