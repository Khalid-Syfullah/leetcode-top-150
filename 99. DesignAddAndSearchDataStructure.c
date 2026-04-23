#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *child[26];
    bool end;
} Node;

Node *newNode(void) {
    return calloc(1, sizeof(Node));
}

void addWord(Node *root, const char *word) {
    for (int i = 0; word[i]; ++i) {
        int idx = word[i] - 'a';
        if (!root->child[idx]) root->child[idx] = newNode();
        root = root->child[idx];
    }
    root->end = true;
}

bool search(Node *root, const char *word) {
    if (!root) return false;
    if (!*word) return root->end;
    if (*word == '.') {
        for (int i = 0; i < 26; ++i) {
            if (search(root->child[i], word + 1)) return true;
        }
        return false;
    }
    return search(root->child[*word - 'a'], word + 1);
}

int main(void) {
    Node *dict = newNode();
    addWord(dict, "bad");
    addWord(dict, "dad");
    addWord(dict, "mad");
    puts(search(dict, ".ad") ? "true" : "false");
    puts(search(dict, "b..") ? "true" : "false");
    return 0;
}
