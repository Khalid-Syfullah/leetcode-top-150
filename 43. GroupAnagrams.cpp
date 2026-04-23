#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (auto& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        groups[key].push_back(str);
    }
    vector<vector<string>> result;
    for (auto& p : groups) result.push_back(p.second);
    return result;
}

int main() {
    auto print = [](vector<vector<string>> res) {
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ", ";
            cout << "[";
            for (size_t j = 0; j < res[i].size(); j++) { if (j) cout << ", "; cout << res[i][j]; }
            cout << "]";
        }
        cout << "]\n";
    };
    vector<string> w1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> w2 = {""};
    vector<string> w3 = {"a"};
    print(groupAnagrams(w1));
    print(groupAnagrams(w2));
    print(groupAnagrams(w3));
    return 0;
}
