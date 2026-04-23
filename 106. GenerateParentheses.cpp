#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(vector<string>& result, string& current, int open, int close, int n) {
    if ((int)current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        current.push_back('(');
        backtrack(result, current, open + 1, close, n);
        current.pop_back();
    }
    if (close < open) {
        current.push_back(')');
        backtrack(result, current, open, close + 1, n);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    backtrack(result, current, 0, 0, n);
    return result;
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
    print(generateParenthesis(3));
    print(generateParenthesis(1));
    return 0;
}
