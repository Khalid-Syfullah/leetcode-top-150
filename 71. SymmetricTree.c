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
    node->left = NULL;
    node->right = NULL;
    return node;
}

static bool mirror(struct TreeNode *a, struct TreeNode *b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return a->val == b->val &&
           mirror(a->left, b->right) &&
           mirror(a->right, b->left);
}

bool isSymmetric(struct TreeNode *root) {
    return root == NULL || mirror(root->left, root->right);
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    printf("%s\n", isSymmetric(root) ? "true" : "false"); /* true */

    struct TreeNode *r2 = newNode(1);
    r2->left = newNode(2);
    r2->right = newNode(2);
    r2->left->right = newNode(3);
    r2->right->right = newNode(3);
    printf("%s\n", isSymmetric(r2) ? "true" : "false"); /* false */

    return 0;
}
