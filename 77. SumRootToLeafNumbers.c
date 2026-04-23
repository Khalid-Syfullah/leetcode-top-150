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

int dfs(struct TreeNode *root, int curr) {
    if (!root) return 0;
    curr = curr * 10 + root->val;
    if (!root->left && !root->right) return curr;
    return dfs(root->left, curr) + dfs(root->right, curr);
}

int sumNumbers(struct TreeNode *root) {
    return dfs(root, 0);
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    printf("%d\n", sumNumbers(root));
    return 0;
}
