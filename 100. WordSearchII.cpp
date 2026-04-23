#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    string word;
    TrieNode() : word("") {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

TrieNode* buildTrie(const vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string& word : words) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word;
    }
    return root;
}

void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
    char ch = board[r][c];
    if (ch == '#') return;
    TrieNode* next = node->children[ch - 'a'];
    if (next == nullptr) return;
    if (!next->word.empty()) {
        result.push_back(next->word);
        next->word = "";
    }
    board[r][c] = '#';
    dfs(board, r + 1, c, next, result);
    dfs(board, r - 1, c, next, result);
    dfs(board, r, c + 1, next, result);
    dfs(board, r, c - 1, next, result);
    board[r][c] = ch;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = buildTrie(words);
    vector<string> result;
    int rows = board.size();
    int cols = board[0].size();
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dfs(board, r, c, root, result);
        }
    }
    return result;
}

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = findWords(board, words);
    cout << "[";
    for (size_t i = 0; i < res.size(); i++) { if (i) cout << ", "; cout << res[i]; }
    cout << "]\n";
    return 0;
}
