#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Trie {
    struct Trie *child[26];
    bool end;
} Trie;

Trie *trieCreate(void) {
    return calloc(1, sizeof(Trie));
}

void trieInsert(Trie *root, const char *word) {
    for (int i = 0; word[i]; ++i) {
        int idx = word[i] - 'a';
        if (!root->child[idx]) root->child[idx] = trieCreate();
        root = root->child[idx];
    }
    root->end = true;
}

bool trieSearch(Trie *root, const char *word) {
    for (int i = 0; word[i]; ++i) {
        int idx = word[i] - 'a';
        if (!root->child[idx]) return false;
        root = root->child[idx];
    }
    return root->end;
}

bool trieStartsWith(Trie *root, const char *prefix) {
    for (int i = 0; prefix[i]; ++i) {
        int idx = prefix[i] - 'a';
        if (!root->child[idx]) return false;
        root = root->child[idx];
    }
    return true;
}

int main(void) {
    Trie *trie = trieCreate();
    trieInsert(trie, "apple");
    puts(trieSearch(trie, "apple") ? "true" : "false");
    puts(trieSearch(trie, "app") ? "true" : "false");
    puts(trieStartsWith(trie, "app") ? "true" : "false");
    return 0;
}
