#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> bankSet(bank.begin(), bank.end());
    if (!bankSet.count(endGene)) return -1;

    vector<char> choices = {'A', 'C', 'G', 'T'};
    queue<string> q;
    unordered_set<string> visited;

    q.push(startGene);
    visited.insert(startGene);

    int mutations = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string current = q.front();
            q.pop();
            if (current == endGene) return mutations;
            for (int j = 0; j < (int)current.size(); j++) {
                char original = current[j];
                for (char choice : choices) {
                    if (choice == original) continue;
                    current[j] = choice;
                    if (bankSet.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        q.push(current);
                    }
                    current[j] = original;
                }
            }
        }
        mutations++;
    }

    return -1;
}

int main() {
    vector<string> bank1 = {"AACCGGTA"};
    cout << minMutation("AACCGGTT", "AACCGGTA", bank1) << "\n";
    vector<string> bank2 = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << minMutation("AACCGGTT", "AAACGGTA", bank2) << "\n";
    vector<string> bank3 = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    cout << minMutation("AAAAACCC", "AACCCCCC", bank3) << "\n";
    vector<string> bank4 = {};
    cout << minMutation("AACCGGTT", "AACCGGTA", bank4) << "\n";
    return 0;
}
