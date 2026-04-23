#include <limits.h>
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

void inorder(struct TreeNode *root, int *prev, int *best) {
    if (!root) return;
    inorder(root->left, prev, best);
    if (*prev != INT_MIN && root->val - *prev < *best) *best = root->val - *prev;
    *prev = root->val;
    inorder(root->right, prev, best);
}

int getMinimumDifference(struct TreeNode *root) {
    int prev = INT_MIN, best = INT_MAX;
    inorder(root, &prev, &best);
    return best;
}

int main(void) {
    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    printf("%d\n", getMinimumDifference(root));
    return 0;
}
