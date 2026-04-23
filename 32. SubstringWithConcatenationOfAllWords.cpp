#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int w = (int)words[0].size(), k = (int)words.size(), total = w * k;
    if ((int)s.size() < total) return res;
    unordered_map<string, int> need;
    for (auto& word : words) need[word]++;
    for (int i = 0; i < w; i++) {
        int l = i, count = 0;
        unordered_map<string, int> seen;
        for (int r = i; r + w <= (int)s.size(); r += w) {
            string word = s.substr(r, w);
            if (!need.count(word)) {
                seen.clear();
                count = 0;
                l = r + w;
                continue;
            }
            seen[word]++;
            count++;
            while (seen[word] > need[word]) {
                string left = s.substr(l, w);
                seen[left]--;
                l += w;
                count--;
            }
            if (count == k) res.push_back(l);
        }
    }
    return res;
}

int main() {
    auto print = [](const vector<int>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << v[i];
        }
        cout << "]\n";
    };

    vector<string> w1 = {"foo", "bar"};
    print(findSubstring("barfoothefoobarman", w1));

    vector<string> w2 = {"word", "good", "best", "word"};
    print(findSubstring("wordgoodgoodgoodbestword", w2));

    vector<string> w3 = {"bar", "foo", "the"};
    print(findSubstring("barfoofoobarthefoobarman", w3));
}
