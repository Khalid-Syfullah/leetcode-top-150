#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (t == "+") s.push(a + b);
            else if (t == "-") s.push(a - b);
            else if (t == "*") s.push(a * b);
            else s.push(a / b);
        } else {
            s.push(stoi(t));
        }
    }
    return s.top();
}

int main() {
    vector<string> t1 = {"2","1","+","3","*"};
    vector<string> t2 = {"4","13","5","/","+"};
    vector<string> t3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(t1) << "\n";
    cout << evalRPN(t2) << "\n";
    cout << evalRPN(t3) << "\n";
    return 0;
}
