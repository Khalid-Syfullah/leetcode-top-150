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

int inorder(struct TreeNode *root, int *k) {
    if (!root) return -1;
    int left = inorder(root->left, k);
    if (*k == 0) return left;
    if (--(*k) == 0) return root->val;
    return inorder(root->right, k);
}

int kthSmallest(struct TreeNode *root, int k) {
    return inorder(root, &k);
}

int main(void) {
    struct TreeNode *root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->right = newNode(2);
    printf("%d\n", kthSmallest(root, 1));
    return 0;
}
