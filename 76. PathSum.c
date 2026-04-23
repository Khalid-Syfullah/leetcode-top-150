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

bool hasPathSum(struct TreeNode *root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main(void) {
    struct TreeNode *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->right = newNode(1);
    puts(hasPathSum(root, 22) ? "true" : "false");
    return 0;
}
