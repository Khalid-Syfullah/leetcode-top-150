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
    return validate(root->left, low, (long long)root->val) &&
           validate(root->right, (long long)root->val, high);
}

bool isValidBST(struct TreeNode *root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

void freeTree(struct TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *validRoot = newNode(2);
    validRoot->left  = newNode(1);
    validRoot->right = newNode(3);

    struct TreeNode *invalidRoot = newNode(5);
    invalidRoot->left  = newNode(1);
    invalidRoot->right = newNode(4);
    invalidRoot->right->left  = newNode(3);
    invalidRoot->right->right = newNode(6);

    puts(isValidBST(validRoot)   ? "true" : "false");
    puts(isValidBST(invalidRoot) ? "true" : "false");

    freeTree(validRoot);
    freeTree(invalidRoot);
    return 0;
}
