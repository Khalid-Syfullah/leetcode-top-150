#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> c(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) c[i] = c[i - 1] + 1;
    }
    int total = c[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        total += c[i];
    }
    return total;
}

int main() {
    vector<int> a = {1, 0, 2};
    cout << candy(a) << "\n";

    vector<int> b = {1, 2, 2};
    cout << candy(b) << "\n";

    vector<int> c = {1, 3, 4, 5, 2};
    cout << candy(c) << "\n";

    return 0;
}
