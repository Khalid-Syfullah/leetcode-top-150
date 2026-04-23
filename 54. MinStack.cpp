#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<pair<int,int>> s;
public:
    void push(int val) {
        int mn = s.empty() ? val : min(val, s.top().second);
        s.push({val, mn});
    }
    void pop() { s.pop(); }
    int top() { return s.top().first; }
    int getMin() { return s.top().second; }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.top() << "\n";
    cout << ms.getMin() << "\n";
    return 0;
}
