#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    stringstream ss(path);
    string part;
    while (getline(ss, part, '/')) {
        if (part.empty() || part == ".") continue;
        if (part == "..") {
            if (!stack.empty()) stack.pop_back();
        } else {
            stack.push_back(part);
        }
    }
    string result;
    for (const string& p : stack) result += '/' + p;
    return result.empty() ? "/" : result;
}

int main() {
    cout << simplifyPath("/home/") << "\n";
    cout << simplifyPath("/../") << "\n";
    cout << simplifyPath("/home//foo/") << "\n";
    cout << simplifyPath("/a/./b/../../c/") << "\n";
    return 0;
}
