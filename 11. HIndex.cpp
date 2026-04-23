#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i = 0; i < n; i++) {
        int h = n - i;
        if (citations[i] >= h) return h;
    }
    return 0;
}

int main() {
    vector<int> a = {3, 0, 6, 1, 5};
    cout << hIndex(a) << "\n";

    vector<int> b = {1, 3, 1};
    cout << hIndex(b) << "\n";

    vector<int> c = {0};
    cout << hIndex(c) << "\n";

    return 0;
}
