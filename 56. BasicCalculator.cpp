#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0, num = 0, sign = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            result += sign * num;
            num = 0;
            sign = c == '+' ? 1 : -1;
        } else if (c == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            result *= st.top(); st.pop();
            result += st.top(); st.pop();
        }
    }
    return result + sign * num;
}

int main() {
    cout << calculate("1 + 1") << "\n";
    cout << calculate(" 2-1 + 2 ") << "\n";
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << "\n";
    return 0;
}
