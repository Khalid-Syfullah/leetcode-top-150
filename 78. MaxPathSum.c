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

int gain(struct TreeNode *root, int *best) {
    if (!root) return 0;
    int left = gain(root->left, best);
    int right = gain(root->right, best);
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    int through = root->val + left + right;
    if (through > *best) *best = through;
    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode *root) {
    int best = INT_MIN;
    gain(root, &best);
    return best;
}

void freeTree(struct TreeNode *root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    // Test 1: [-10, 9, 20, null, null, 15, 7] => expected 42
    struct TreeNode *root1 = newNode(-10);
    root1->left  = newNode(9);
    root1->right = newNode(20);
    root1->right->left  = newNode(15);
    root1->right->right = newNode(7);
    printf("Test 1: %d\n", maxPathSum(root1)); // 42
    freeTree(root1);

    // Test 2: [1, 2, 3] => expected 6
    struct TreeNode *root2 = newNode(1);
    root2->left  = newNode(2);
    root2->right = newNode(3);
    printf("Test 2: %d\n", maxPathSum(root2)); // 6
    freeTree(root2);

    // Test 3: [-3] => expected -3
    struct TreeNode *root3 = newNode(-3);
    printf("Test 3: %d\n", maxPathSum(root3)); // -3
    freeTree(root3);

    return 0;
}
