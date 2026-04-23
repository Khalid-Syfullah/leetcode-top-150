#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= (int)s.length()) return s;
    vector<string> rows(numRows);
    int cur = 0, dir = -1;
    for (char c : s) {
        rows[cur] += c;
        if (cur == 0 || cur == numRows - 1) dir = -dir;
        cur += dir;
    }
    string out;
    for (string& r : rows) out += r;
    return out;
}

int main() {
    cout << convert("PAYPALISHIRING", 3) << "\n";
    cout << convert("PAYPALISHIRING", 4) << "\n";
    cout << convert("A", 1) << "\n";

    return 0;
}
