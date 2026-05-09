#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *newNode(int val) {
    struct TreeNode *node = malloc(sizeof(*node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

static struct TreeNode *buildBST(int *nums, int left, int right) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);
    return root;
}

static struct TreeNode *sortedArrayToBST(int *nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}

static void printInOrder(struct TreeNode *root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

static int height(struct TreeNode *root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main(void) {
    int nums[] = {-10, -3, 0, 5, 9};
    struct TreeNode *root = sortedArrayToBST(nums, 5);
    printInOrder(root);
    printf("\n");
    printf("Height: %d\n", height(root));
    printf("Root: %d\n", root->val);
    return 0;
}
