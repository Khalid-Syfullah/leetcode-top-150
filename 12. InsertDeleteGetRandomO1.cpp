#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedSet {
    vector<int> lst;
    unordered_map<int, int> idx;
public:
    RandomizedSet() { srand((unsigned)time(nullptr)); }

    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = lst.size();
        lst.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) return false;
        int i = it->second;
        int last = lst.size() - 1;
        if (i != last) {
            int lv = lst[last];
            lst[i] = lv;
            idx[lv] = i;
        }
        lst.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return lst[rand() % lst.size()];
    }
};

int main() {
    cout << boolalpha;
    RandomizedSet s;
    cout << s.insert(1) << "\n";
    cout << s.remove(2) << "\n";
    cout << s.insert(2) << "\n";
    cout << s.getRandom() << "\n";
    cout << s.remove(1) << "\n";
    cout << s.insert(2) << "\n";
    cout << s.getRandom() << "\n";

    return 0;
}
