#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0, n = words.size();
    while (i < n) {
        int j = i, len = 0;
        while (j < n && len + (int)words[j].length() + (j - i) <= maxWidth) {
            len += words[j++].length();
        }
        string line;
        int gaps = j - i - 1;
        if (j == n || gaps == 0) {
            for (int k = i; k < j; k++) {
                line += words[k];
                if (k < j - 1) line += ' ';
            }
            while ((int)line.length() < maxWidth) line += ' ';
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
    vector<string> w1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> r1 = fullJustify(w1, 16);
    cout << "[";
    for (int i = 0; i < (int)r1.size(); i++) { if (i) cout << ", "; cout << "\"" << r1[i] << "\""; }
    cout << "]\n";

    vector<string> w2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vector<string> r2 = fullJustify(w2, 16);
    cout << "[";
    for (int i = 0; i < (int)r2.size(); i++) { if (i) cout << ", "; cout << "\"" << r2[i] << "\""; }
    cout << "]\n";

    return 0;
}
