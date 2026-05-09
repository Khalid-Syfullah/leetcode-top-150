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

void inorder(struct TreeNode *root, int *prev, int *best) {
    if (!root) return;
    inorder(root->left, prev, best);
    if (*prev != INT_MIN && root->val - *prev < *best) *best = root->val - *prev;
    *prev = root->val;
    inorder(root->right, prev, best);
}

int getMinimumDifference(struct TreeNode *root) {
    int prev = INT_MIN, best = INT_MAX;
    inorder(root, &prev, &best);
    return best;
}

void freeTree(struct TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root1 = newNode(4);
    root1->left  = newNode(2);
    root1->right = newNode(6);
    root1->left->left  = newNode(1);
    root1->left->right = newNode(3);

    struct TreeNode *root2 = newNode(1);
    root2->right = newNode(3);
    root2->right->left = newNode(2);

    printf("%d\n", getMinimumDifference(root1));
    printf("%d\n", getMinimumDifference(root2));

    freeTree(root1);
    freeTree(root2);
    return 0;
}
