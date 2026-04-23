#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode *stack[1024];
    int top;
} BSTIterator;

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

static void pushLeft(BSTIterator *it, struct TreeNode *node) {
    while (node) {
        it->stack[it->top++] = node;
        node = node->left;
    }
}

void bSTIteratorInit(BSTIterator *it, struct TreeNode *root) {
    it->top = 0;
    pushLeft(it, root);
}

bool bSTIteratorHasNext(BSTIterator *it) {
    return it->top > 0;
}

int bSTIteratorNext(BSTIterator *it) {
    struct TreeNode *node = it->stack[--it->top];
    pushLeft(it, node->right);
    return node->val;
}

int main(void) {
    struct TreeNode *root = newNode(7);
    root->left = newNode(3);
    root->right = newNode(15);
    root->right->left = newNode(9);
    root->right->right = newNode(20);
    BSTIterator it;
    bSTIteratorInit(&it, root);
    while (bSTIteratorHasNext(&it)) printf("%d ", bSTIteratorNext(&it));
    puts("");
    return 0;
}
