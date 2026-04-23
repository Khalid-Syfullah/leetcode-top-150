#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;

    queue<string> q;
    unordered_set<string> visited;

    q.push(beginWord);
    visited.insert(beginWord);

    int length = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string current = q.front();
            q.pop();
            if (current == endWord) return length;
            for (int j = 0; j < (int)current.size(); j++) {
                char original = current[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    current[j] = ch;
                    if (words.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        q.push(current);
                    }
                    current[j] = original;
                }
            }
        }
        length++;
    }

    return 0;
}

int main() {
    vector<string> wl1 = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", wl1) << "\n";
    vector<string> wl2 = {"hot","dot","dog","lot","log"};
    cout << ladderLength("hit", "cog", wl2) << "\n";
    vector<string> wl3 = {"a","b","c"};
    cout << ladderLength("a", "c", wl3) << "\n";
    return 0;
}
