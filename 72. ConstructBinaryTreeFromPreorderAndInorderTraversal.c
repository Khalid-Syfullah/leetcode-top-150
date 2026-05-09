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

static int preorderIndex;
static int *inorderArray;
static int inorderLen;

/* Find position of val in inorder array */
static int findInorder(int val) {
    for (int i = 0; i < inorderLen; i++) {
        if (inorderArray[i] == val) return i;
    }
    return -1;
}

static struct TreeNode *build(int *preorder, int left, int right) {
    if (left > right) return NULL;

    int rootVal = preorder[preorderIndex++];
    struct TreeNode *root = newNode(rootVal);

    int mid = findInorder(rootVal);
    root->left = build(preorder, left, mid - 1);
    root->right = build(preorder, mid + 1, right);

    return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    preorderIndex = 0;
    inorderArray = inorder;
    inorderLen = inorderSize;
    return build(preorder, 0, inorderSize - 1);
}

static void printInorder(struct TreeNode *root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

static void printPreorder(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(void) {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    struct TreeNode *root = buildTree(preorder, 5, inorder, 5);

    printPreorder(root);
    printf("\n");
    printInorder(root);
    printf("\n");

    return 0;
}
