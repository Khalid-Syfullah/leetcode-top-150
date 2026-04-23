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

int gain(struct TreeNode *root, int *best) {
    if (!root) return 0;
    int left = gain(root->left, best);
    int right = gain(root->right, best);
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    int through = root->val + left + right;
    if (through > *best) *best = through;
    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode *root) {
    int best = INT_MIN;
    gain(root, &best);
    return best;
}

int main(void) {
    struct TreeNode *root = newNode(-10);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    printf("%d\n", maxPathSum(root));
    return 0;
}
