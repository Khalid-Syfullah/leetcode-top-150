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

class Trie {
    TrieNode* root;

    TrieNode* traverse(const string& text) {
        TrieNode* node = root;
        for (char ch : text) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) return nullptr;
            node = node->children[index];
        }
        return node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
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
        TrieNode* node = traverse(word);
        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        return traverse(prefix) != nullptr;
    }
};

int main() {
    cout << boolalpha;
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << "\n";
    cout << trie.search("app") << "\n";
    cout << trie.startsWith("app") << "\n";
    trie.insert("app");
    cout << trie.search("app") << "\n";
    return 0;
}
