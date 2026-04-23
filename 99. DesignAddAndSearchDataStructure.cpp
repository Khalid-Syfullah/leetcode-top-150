#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(const string& word, int pos, TrieNode* node) {
        if (node == nullptr) return false;
        if (pos == (int)word.size()) return node->isEndOfWord;
        char ch = word[pos];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && dfs(word, pos + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }
        return dfs(word, pos + 1, node->children[ch - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        return dfs(word, 0, root);
    }
};

int main() {
    cout << boolalpha;
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad") << "\n";
    cout << wordDictionary.search("bad") << "\n";
    cout << wordDictionary.search(".ad") << "\n";
    cout << wordDictionary.search("b..") << "\n";
    return 0;
}
