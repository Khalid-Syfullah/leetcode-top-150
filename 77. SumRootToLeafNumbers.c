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
    /* Tree:
     *       4
     *      / \
     *     9   0
     *    / \
     *   5   1
     * Paths: 495 + 491 + 40 = 1026
     */
    struct TreeNode *root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(0);
    root->left->left = newNode(5);
    root->left->right = newNode(1);

    printf("Sum: %d\n", sumNumbers(root));
    return 0;
}
