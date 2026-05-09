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

static int postIndex;
static int *inorderArray;
static int inorderLen;

static int findInorder(int val) {
    for (int i = 0; i < inorderLen; i++) {
        if (inorderArray[i] == val) return i;
    }
    return -1;
}

static struct TreeNode *build(int *postorder, int left, int right) {
    if (left > right) return NULL;

    int rootVal = postorder[postIndex--];
    struct TreeNode *root = newNode(rootVal);

    int mid = findInorder(rootVal);

    /* Build right first because we consume postorder from the end */
    root->right = build(postorder, mid + 1, right);
    root->left = build(postorder, left, mid - 1);

    return root;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    inorderArray = inorder;
    inorderLen = inorderSize;
    postIndex = postorderSize - 1;
    return build(postorder, 0, inorderSize - 1);
}

static void printInorder(struct TreeNode *root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

static void printPostorder(struct TreeNode *root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main(void) {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};

    struct TreeNode *root = buildTree(inorder, 5, postorder, 5);

    printInorder(root);
    printf("\n");
    printPostorder(root);
    printf("\n");

    return 0;
}
