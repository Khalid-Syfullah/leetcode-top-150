#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool isWordBreak(string s, vector<string>& wordDict) {
    int n = (int)s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    cout << boolalpha;
    vector<string> d1 = {"leet", "code"};
    vector<string> d2 = {"apple", "pen"};
    vector<string> d3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> d4 = {"a"};
    vector<string> d5 = {};
    cout << isWordBreak("leetcode", d1) << "\n";
    cout << isWordBreak("applepenapple", d2) << "\n";
    cout << isWordBreak("catsandog", d3) << "\n";
    cout << isWordBreak("", d4) << "\n";
    cout << isWordBreak("a", d5) << "\n";
    return 0;
}
