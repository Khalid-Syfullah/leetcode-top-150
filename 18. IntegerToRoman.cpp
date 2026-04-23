#include <iostream>
#include <string>
#include <vector>
using namespace std;

string intToRoman(int num) {
    vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> syms = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    for (int i = 0; i < (int)vals.size(); i++) {
        while (num >= vals[i]) {
            result += syms[i];
            num -= vals[i];
        }
    }
    return result;
}

int main() {
    cout << intToRoman(3) << "\n";
    cout << intToRoman(58) << "\n";
    cout << intToRoman(1994) << "\n";

    return 0;
}
