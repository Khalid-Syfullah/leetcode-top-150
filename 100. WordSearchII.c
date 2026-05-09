#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 12

typedef struct TrieNode {
    struct TrieNode *children[26];
    char word[MAX_WORD_LEN + 1];  /* non-empty string = end of that word */
} TrieNode;

static TrieNode *newTrieNode(void) {
    return (TrieNode *)calloc(1, sizeof(TrieNode));
}

static TrieNode *buildTrie(const char words[][MAX_WORD_LEN + 1], int numWords) {
    TrieNode *root = newTrieNode();
    for (int i = 0; i < numWords; i++) {
        TrieNode *node = root;
        for (int j = 0; words[i][j]; j++) {
            int idx = words[i][j] - 'a';
            if (!node->children[idx]) node->children[idx] = newTrieNode();
            node = node->children[idx];
        }
        strncpy(node->word, words[i], MAX_WORD_LEN);
    }
    return root;
}

/* Results stored as copies so clearing node->word doesn't lose the string */
static char results[MAX_WORDS][MAX_WORD_LEN + 1];
static int  resultCount;

static void dfs(char board[][4], int rows, int cols, int r, int c, TrieNode *node) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    char ch = board[r][c];
    if (ch == '#') return;

    int idx = ch - 'a';
    TrieNode *next = node->children[idx];
    if (!next) return;

    if (next->word[0] != '\0') {
        strncpy(results[resultCount++], next->word, MAX_WORD_LEN);
        next->word[0] = '\0';  /* mark as found to avoid duplicates */
    }

    board[r][c] = '#';
    dfs(board, rows, cols, r + 1, c, next);
    dfs(board, rows, cols, r - 1, c, next);
    dfs(board, rows, cols, r, c + 1, next);
    dfs(board, rows, cols, r, c - 1, next);
    board[r][c] = ch;
}

void findWords(char board[][4], int rows, int cols,
               const char words[][MAX_WORD_LEN + 1], int numWords) {
    TrieNode *root = buildTrie(words, numWords);
    resultCount = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dfs(board, rows, cols, r, c, root);
        }
    }
}

int main(void) {
    char board[4][4] = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    const char words[][MAX_WORD_LEN + 1] = {"oath", "pea", "eat", "rain"};
    findWords(board, 4, 4, words, 4);

    putchar('[');
    for (int i = 0; i < resultCount; i++) {
        if (i) printf(", ");
        printf("%s", results[i]);
    }
    puts("]");
    return 0;
}
