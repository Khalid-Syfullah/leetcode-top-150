#include <limits.h>
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

bool validate(struct TreeNode *root, long long low, long long high) {
    if (!root) return true;
    if (root->val <= low || root->val >= high) return false;
    return validate(root->left, low, root->val) && validate(root->right, root->val, high);
}

bool isValidBST(struct TreeNode *root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main(void) {
    struct TreeNode *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    puts(isValidBST(root) ? "true" : "false");
    return 0;
}
