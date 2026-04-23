#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string MAP[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(const string& digits, int i, string& cur, vector<string>& out) {
    if (i == (int)digits.size()) {
        out.push_back(cur);
        return;
    }
    for (char c : MAP[digits[i] - '0']) {
        cur.push_back(c);
        dfs(digits, i + 1, cur, out);
        cur.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> out;
    if (digits.empty()) return out;
    string cur;
    dfs(digits, 0, cur, out);
    return out;
}

int main() {
    auto print = [](const vector<string>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) {
            if (i) cout << ", ";
            cout << v[i];
        }
        cout << "]\n";
    };
    print(letterCombinations("23"));
    print(letterCombinations(""));
    print(letterCombinations("2"));
    return 0;
}
