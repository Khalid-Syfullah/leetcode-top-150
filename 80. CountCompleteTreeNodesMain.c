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

static int leftHeight(struct TreeNode *node) {
    int h = 0;
    while (node) { ++h; node = node->left; }
    return h;
}

static int rightHeight(struct TreeNode *node) {
    int h = 0;
    while (node) { ++h; node = node->right; }
    return h;
}

int countNodes(struct TreeNode *root) {
    if (!root) return 0;
    int lh = leftHeight(root), rh = rightHeight(root);
    if (lh == rh) return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(void) {
    // Complete tree: [1,2,3,4,5,6]
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    printf("%d\n", countNodes(root));
    return 0;
}
