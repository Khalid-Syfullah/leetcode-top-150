#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}

int main() {
    vector<int> a = {1, 2, 3, 0, 0, 0};
    vector<int> a2 = {2, 5, 6};
    merge(a, 3, a2, 3);
    for (int i = 0; i < (int)a.size(); i++) { if (i) cout << ", "; cout << a[i]; } cout << "\n";

    vector<int> b = {1};
    vector<int> b2 = {};
    merge(b, 1, b2, 0);
    for (int i = 0; i < (int)b.size(); i++) { if (i) cout << ", "; cout << b[i]; } cout << "\n";

    vector<int> c = {0};
    vector<int> c2 = {1};
    merge(c, 0, c2, 1);
    for (int i = 0; i < (int)c.size(); i++) { if (i) cout << ", "; cout << c[i]; } cout << "\n";

    return 0;
}
