#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *child[26];
    bool end;
} Node;

Node *newTrieNode(void) {
    return calloc(1, sizeof(Node));
}

void addWord(Node *root, const char *word) {
    for (int i = 0; word[i]; ++i) {
        int idx = word[i] - 'a';
        if (!root->child[idx]) root->child[idx] = newTrieNode();
        root = root->child[idx];
    }
    root->end = true;
}

bool searchNode(Node *root, const char *word);

bool searchNode(Node *root, const char *word) {
    if (!root) return false;
    if (!*word) return root->end;
    if (*word == '.') {
        for (int i = 0; i < 26; ++i) {
            if (searchNode(root->child[i], word + 1)) return true;
        }
        return false;
    }
    return searchNode(root->child[*word - 'a'], word + 1);
}

int main(void) {
    Node *dict = newTrieNode();
    addWord(dict, "bad");
    addWord(dict, "dad");
    addWord(dict, "mad");

    puts(searchNode(dict, "pad") ? "true" : "false");  // false
    puts(searchNode(dict, "bad") ? "true" : "false");  // true
    puts(searchNode(dict, ".ad") ? "true" : "false");  // true
    puts(searchNode(dict, "b..") ? "true" : "false");  // true
    return 0;
}
