#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha;
    cout << isValid("()") << "\n";
    cout << isValid("()[]{}") << "\n";
    cout << isValid("(]") << "\n";
    cout << isValid("([)]") << "\n";
    return 0;
}
