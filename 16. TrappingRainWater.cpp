#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& h) {
    int l = 0, r = h.size() - 1, lMax = 0, rMax = 0, water = 0;
    while (l < r) {
        if (h[l] < h[r]) {
            if (h[l] >= lMax) lMax = h[l];
            else water += lMax - h[l];
            l++;
        } else {
            if (h[r] >= rMax) rMax = h[r];
            else water += rMax - h[r];
            r--;
        }
    }
    return water;
}

int main() {
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(a) << "\n";

    vector<int> b = {4, 2, 0, 3, 2, 5};
    cout << trap(b) << "\n";

    return 0;
}
