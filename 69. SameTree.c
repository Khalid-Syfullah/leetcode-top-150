#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (!p || !q) return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void) {
    struct TreeNode *a = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    struct TreeNode *b = newNode(1);
    b->left = newNode(2);
    b->right = newNode(3);
    puts(isSameTree(a, b) ? "true" : "false");
    return 0;
}
