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

struct TreeNode *build(int *nums, int left, int right) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    return build(nums, 0, numsSize - 1);
}

int main(void) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct TreeNode *root = sortedArrayToBST(nums, 5);
    printf("%d\n", root->val);
    return 0;
}
