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

struct TreeNode *invertTree(struct TreeNode *root) {
    if (!root) return NULL;
    struct TreeNode *tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}

int main(void) {
    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    root = invertTree(root);
    printf("%d %d\n", root->left->val, root->right->val);
    return 0;
}
