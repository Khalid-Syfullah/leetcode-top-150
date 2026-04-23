#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> digits) {
    bool done = false;
    for (int i = (int)digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            done = true;
            break;
        }
        digits[i] = 0;
    }
    if (done) {
        return digits;
    }
    vector<int> result(digits.size() + 1, 0);
    result[0] = 1;
    return result;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 3, 2, 1};
    vector<int> v3 = {9};
    vector<int> v4 = {9, 9, 9};

    auto print = [](const vector<int>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; }
        cout << "]\n";
    };

    print(plusOne(v1));
    print(plusOne(v2));
    print(plusOne(v3));
    print(plusOne(v4));
    return 0;
}
